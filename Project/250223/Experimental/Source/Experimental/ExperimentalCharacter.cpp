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
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	inventoryLimit = 2;
	reach = 500.f;
	suspicionPercentage = 0.f;
	bDeniedText = false;
	bIsGamePaused = false;

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
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("You can't carry any more items!"));
			if (bDeniedText == false)
			{
				bDeniedText = true;
				FTimerHandle TimerHandle;
				GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AExperimentalCharacter::RemoveDeniedText, 3.0f, false);
				return false;
			}
			return false;
		}
	}
	else return false;
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
		inventory[slot]->Use_Implementation();
		inventory[slot] = NULL; /*Deletes the item from inventory once used*/
	}
}

void AExperimentalCharacter::ToggleInventory()
{
	APlayerController* MyController = GetWorld()->GetFirstPlayerController(); /* Controller REF*/
	ACharacter* Character = UGameplayStatics::GetPlayerCharacter(this, 0); /* Character REF*/

	/*Check players hud state, if inventory is open, then close it, otherwise open inventory*/
	AExperimentalGameMode* GM = Cast<AExperimentalGameMode>(GetWorld()->GetAuthGameMode());

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

void AExperimentalCharacter::TestArea()
{
	FTransform TestAreaT;

	FVector TestAreaLocation = FVector(1470.000000, 2380.000000, 210.000000);
	FRotator NoRotation = FRotator(0.f, 0.f, 0.f);
	FVector NormalScale = FVector(1.f, 1.f, 1.f);

	TestAreaT.SetLocation(TestAreaLocation);
	TestAreaT.SetRotation(NoRotation.Quaternion());
	TestAreaT.SetScale3D(NormalScale);

	SetActorTransform(TestAreaT);
	Controller->SetControlRotation(NoRotation);
}

void AExperimentalCharacter::MapArea()
{
	FTransform MapAreaT;
	
	FVector MapAreaLocation = FVector(1370.f, 8720.f, 210.f);
	FRotator MapAreaRotation = FRotator(0.f, -90.f, 0.f);
	FVector NormalScale = FVector(1.f, 1.f, 1.f);

	MapAreaT.SetLocation(MapAreaLocation);
	MapAreaT.SetRotation(MapAreaRotation.Quaternion());
	MapAreaT.SetScale3D(NormalScale);

	SetActorTransform(MapAreaT);
	Controller->SetControlRotation(MapAreaRotation);
}

void AExperimentalCharacter::DecreaseSuspicion()
{
	suspicionPercentage = suspicionPercentage - 25.f;
}

void AExperimentalCharacter::IncreaseSuspicion()
{
	suspicionPercentage = suspicionPercentage + 25.f;
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
		
		//Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
		
		/*Interacting*/
		EnhancedInputComponent->BindAction(ToggleInventoryAction, ETriggerEvent::Completed, this, &AExperimentalCharacter::ToggleInventory);
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Completed, this, &AExperimentalCharacter::Interact);

		//Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AExperimentalCharacter::Move);

		//Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AExperimentalCharacter::Look);

		/* Testing only, REMOVE BEFORE DEADLINE*/
		EnhancedInputComponent->BindAction(TestAreaAction, ETriggerEvent::Triggered, this, &AExperimentalCharacter::TestArea);
		EnhancedInputComponent->BindAction(MapAreaAction, ETriggerEvent::Triggered, this, &AExperimentalCharacter::MapArea);
		EnhancedInputComponent->BindAction(DecreaseSuspicionAction, ETriggerEvent::Completed, this, &AExperimentalCharacter::DecreaseSuspicion);
		EnhancedInputComponent->BindAction(IncreaseSuspicionAction, ETriggerEvent::Completed, this, &AExperimentalCharacter::IncreaseSuspicion);

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

void AExperimentalCharacter::RemoveDeniedText()
{
	bDeniedText = false;
}
