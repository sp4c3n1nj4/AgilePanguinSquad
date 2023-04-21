// Copyright Epic Games, Inc. All Rights Reserved.

#include "ExperimentalCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "ExperimentalGameMode.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "EnhancedInputSubsystems.h"


//////////////////////////////////////////////////////////////////////////
// AExperimentalCharacter

AExperimentalCharacter::AExperimentalCharacter()
{	
	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.f;
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 0.0f, 100.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	inventoryLimit = 2;
	reach = 500.f;
	suspicionPercentage = 0.f;
	bIsGamePaused = false;
	
	// general overlaps
	bEngineOverlap_0 = false;
	bEngineOverlap_1 = false;
	bFuelStorageOverlap = false;
	bO2RefresherOverlap = false;
	bSteeringOverlap = false;
	bBridgeOverlap = false;
	bO2H2OStorageOverlap = false;
	bDOSSOverlap = false;

	// charging overlaps
	bAPSRDChargeOverlap = false;
	bC2M2ChargeOverlap = false;
	bCaptainChargeOverlap = false;
	bCarGOChargeOverlap = false;
	bMIMAChargeOverlap = false;
	bSOSChargeOverlap = false;
	bSSRChargeOverlap = false;
	
	// tutorial overlaps
	bTutorial2Overlap = false;
	bTutorial3Overlap = false;

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)
}

bool AExperimentalCharacter::AddItemToInventory(APickup* Item)
{
	if (Item != NULL)
	{
		const int32 AvaliableSlot = inventory.Find(nullptr); /*Find first slot with a nullptr in it*/

		if (AvaliableSlot != INDEX_NONE)
		{
			inventory[AvaliableSlot] = Item;
			return true;
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("You can't carry any more items"));
			return false;
		}
	}

	return false;
}

UTexture2D* AExperimentalCharacter::GetThumbnailAtInventorySlot(int32 slot)
{
	if (inventory[slot] != NULL)
	{
		return inventory[slot]->pickupThumbnail;
	}
	else return nullptr;
}

FString AExperimentalCharacter::GetItemNameAtInventorySlot(int32 slot)
{
	if (inventory[slot] != NULL)
	{
		return inventory[slot]->itemName;
	}
	return FString("None"); /*Item will be named none if inventory slot is empty*/
}

FString AExperimentalCharacter::GetItemDescriptionAtInventorySlot(int32 slot)
{
	if (inventory[slot] != NULL)
	{
		return inventory[slot]->itemDescription;
	}
	return FString(""); /*Item will have a empty description if ibventory slot is empty*/
}

void AExperimentalCharacter::UseItemAtInventorySlot(int32 slot)
{
	if (inventory[slot] != NULL)
	{
		if (inventory[slot]->uses != NULL)
		{
			inventory[slot]->Use_Implementation();
			
			if (inventory[slot]->bUsable == true)
			{
				inventory[slot]->uses--;
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("uses = %d"), inventory[slot]->uses));
			}
			
			if (inventory[slot]->uses <= 0)
			{
				inventory[slot]->Discard_Implementation();
				inventory[slot]->Reset_Uses();
				inventory[slot] = NULL;
				return;
			}
		}
		else
		{
			inventory[slot]->Use_Implementation();
			return;
		}
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Use what exactly?"));
	}
}

void AExperimentalCharacter::DeleteItemAtInventorySlot(int32 slot)
{
	inventory[slot]->Discard_Implementation();
	if (inventory[slot] != NULL)
	{
		inventory[slot] = NULL;
	}
	
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Discard what exactly?"));
	}
}

void AExperimentalCharacter::ToggleInventory()
{
	APlayerController* MyController = GetWorld()->GetFirstPlayerController(); /* Controller REF*/
	ACharacter* Character = UGameplayStatics::GetPlayerCharacter(this, 0); /* Character REF*/
	AExperimentalGameMode* GM = Cast<AExperimentalGameMode>(GetWorld()->GetAuthGameMode());

	/*Check players hud state, if inventory is open, then close it, otherwise open inventory*/
	if (GM->GetHUDState() == GM->HS_Ingame)
	{
		GM->ChangeHUDState(GM->HS_Inventory);
		Character->GetCharacterMovement()->SetMovementMode(MOVE_None);
		MyController->SetInputMode(FInputModeGameAndUI());
	}
	else
	{
		GM->ChangeHUDState(GM->HS_Ingame);
		Character->GetCharacterMovement()->SetMovementMode(MOVE_Walking);
		MyController->SetInputMode(FInputModeGameOnly());
	}
}

void AExperimentalCharacter::Interact()
{
	if (currentInteractable != nullptr)
	{
		currentInteractable->Interact_Implementation();
	}
}

void AExperimentalCharacter::CheckForInteractables()
{
	FVector startTrace = FollowCamera->GetComponentLocation();
	FVector endTrace = startTrace + FollowCamera->GetForwardVector() * reach;

	FHitResult hitResult;
	FCollisionQueryParams CQP;
	CQP.AddIgnoredActor(this);

	GetWorld()->LineTraceSingleByChannel(hitResult, startTrace, endTrace, ECC_WorldDynamic, CQP);

	AInteractable* potentialInteractable = Cast<AInteractable>(hitResult.GetActor());

	if (potentialInteractable == NULL)
	{
		helpText = FString("");
		currentInteractable = nullptr;
		return;
	}
	else
	{
		currentInteractable = potentialInteractable;
		helpText = potentialInteractable->interactableHelpText;
	}
}

void AExperimentalCharacter::PauseGame()
{
	APlayerController* MyController = GetWorld()->GetFirstPlayerController(); /* Controller REF*/
	AExperimentalGameMode* GM = Cast<AExperimentalGameMode>(GetWorld()->GetAuthGameMode());
	
	/*If the game is unpaused, pause it*/
	if (bIsGamePaused == false)
	{
		if (GM->GetHUDState() == GM->HS_Ingame)
		{
			UGameplayStatics::SetGamePaused(GetWorld(), true);
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Game Paused"));
			bIsGamePaused = true;
			GM->ChangeHUDState(GM->HS_Pause);
			MyController->SetInputMode(FInputModeGameAndUI());
			return;
		}
		else
		{
			return;
		}
	}
	/*If the game is paused, unpause it*/
	if (bIsGamePaused == true)
	{
		UGameplayStatics::SetGamePaused(GetWorld(), false);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Game Resumed"));
		bIsGamePaused = false;
		GM->ChangeHUDState(GM->HS_Ingame);
		MyController->SetInputMode(FInputModeGameOnly());
	}
}

void AExperimentalCharacter::OpenOptions()
{
	/*Open options widget here*/
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Options menu widget will open, pause widget will close"));
}

void AExperimentalCharacter::CloseOptions()
{
	/*Close options widget here*/
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Options menu widget will close, pause menu widget will open"));
}

void AExperimentalCharacter::QuitToMenu()
{
	/*Open main menu level here*/
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Level will close and menu will open"));
}

void AExperimentalCharacter::AddSus()
{
	if (suspicionPercentage > 80.f)
	{
		suspicionPercentage = 100.f;
	}
	else
	{
		suspicionPercentage += 20.f;
	}
}

void AExperimentalCharacter::DecreaseSus()
{
	if (suspicionPercentage < 20.f)
	{
		suspicionPercentage = 0.f;
	}
	else
	{
		suspicionPercentage -= 20.f;
	}
}

void AExperimentalCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	APlayerController* MyController = GetWorld()->GetFirstPlayerController();
	
	inventory.SetNum(inventoryLimit);

	currentInteractable = nullptr;

	MyController->SetInputMode(FInputModeGameOnly());
	
	//Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

void AExperimentalCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CheckForInteractables();
}

//////////////////////////////////////////////////////////////////////////
// Input

void AExperimentalCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) {
		
		/*Interacting*/
		EnhancedInputComponent->BindAction(ToggleInventoryAction, ETriggerEvent::Completed, this, &AExperimentalCharacter::ToggleInventory);
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Completed, this, &AExperimentalCharacter::Interact);

		//Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AExperimentalCharacter::Move);

		//Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AExperimentalCharacter::Look);

		/*Pause*/
		EnhancedInputComponent->BindAction(PauseAction, ETriggerEvent::Started, this, &AExperimentalCharacter::PauseGame);
	}
}

void AExperimentalCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AExperimentalCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}
