// Copyright Epic Games, Inc. All Rights Reserved.

#include "ExperimentalGameMode.h"
#include "ExperimentalCharacter.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h" 
#include "UObject/ConstructorHelpers.h"

AExperimentalGameMode::AExperimentalGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	/*Sets default HUD state to ingame*/
	HUDState = EHUDState::HS_Ingame;

	bEngineBroken_0 = false;
	bEngineBroken_1 = false;
	stableNum = 100;
	maxStableNum = 100;
}

void AExperimentalGameMode::BeginPlay()
{
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));

	if (MyCharacter != nullptr)
	{
		ApplyHUDChanges();
		
		if (bEngineBroken_0 == false)
		{
			EngineTimer_0();
		}

		if (bEngineBroken_1 == false)
		{
			EngineTimer_1();
		}
	}
}

void AExperimentalGameMode::ApplyHUDChanges()
{
	/*Remove the previous hud, since we're applying a new one*/
	if (CurrentWidget != nullptr)
	{
		CurrentWidget->RemoveFromParent();
	}

	switch (HUDState)
	{
		case EHUDState::HS_Ingame:
		{
			ApplyHUD(IngameHUDClass, false, false);
			break;
		}
		case EHUDState::HS_Inventory:
		{
			ApplyHUD(InventoryHUDClass, true, true);
			break;
		}
		case EHUDState::HS_Pause:
		{
			ApplyHUD(PauseHUDClass, true, true);
			break;
		}
		default:
		{
			ApplyHUD(IngameHUDClass, false, false);
			break;
		}
	}
}

uint8 AExperimentalGameMode::GetHUDState()
{
	return HUDState;
}

void AExperimentalGameMode::ChangeHUDState(uint8 NewState)
{
	HUDState = NewState;
	ApplyHUDChanges();
}

bool AExperimentalGameMode::ApplyHUD(TSubclassOf<class UUserWidget> WidgetToApply, bool bShowMouseCursor, bool EnableClickEvents)
{
	/* Get a reference to the player and the controller*/
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	APlayerController* MyController = GetWorld()->GetFirstPlayerController();

	/* Nullcheck whatever widget we're trying to apply*/
	if (WidgetToApply != nullptr)
	{
		/*Set mouse visibilty and click events according to params*/
		MyController->bShowMouseCursor = bShowMouseCursor;
		MyController->bEnableClickEvents = EnableClickEvents;

		/*Create the widget*/
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), WidgetToApply);

		if (CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
			return true;
		}
		else return false;
	}
	else return false;
}

void AExperimentalGameMode::EngineTimer_0()
{
	FTimerHandle delayHandle;
	GetWorldTimerManager().SetTimer(delayHandle, this, &AExperimentalGameMode::EngineChance_0, 30.f, false);
}

void AExperimentalGameMode::EngineTimer_1()
{
	FTimerHandle delayHandle;
	GetWorldTimerManager().SetTimer(delayHandle, this, &AExperimentalGameMode::EngineChance_1, 30.f, false);
}

void AExperimentalGameMode::EngineChance_0()
{
	stateEngine_0 = FMath::RandRange(0, 9);

	if (stateEngine_0 == 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Engine 1 is broken"));
		bEngineBroken_0 = true;
		stableNum = stableNum - 20;
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Engine 1 remains"));
		EngineTimer_0();
	}
}

void AExperimentalGameMode::EngineChance_1()
{
	stateEngine_1 = FMath::RandRange(0, 9);

	if (stateEngine_1 == 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Engine 2 is broken"));
		bEngineBroken_1 = true;
		stableNum = stableNum - 20;
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Engine 2 remains"));
		EngineTimer_1();
	}
}