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
	bSteeringBroken = false;
	bO2RefreshBroken = false;
	bO2H2OStorageBroken = false;
	bFuelStorageBroken = false;
	bBridgeBroken = false;
	bStaffMainBroken = false;
	bDOSSBroken = false;

	bAPSRDChargeBroken = false;
	bC2M2ChargeBroken = false;
	bCarGOChargeBroken = false;
	bCaptainChargeBroken = false;
	bMIMAChargeBroken = false;
	bSOSChargeBroken = false;
	bSSRChargeBroken = false;

	stableNum = 100;
	maxStableNum = 100;
	chanceNum = 1;

	bTutorial = false;
	bOpenTutorialDoor2 = false;
	bOpenTutorialDoor3 = false;
}

void AExperimentalGameMode::BeginPlay()
{
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));

	if (MyCharacter != nullptr)
	{
		ApplyHUDChanges();
		
		if (bTutorial == false)
		{
			if (bEngineBroken_0 == false)
			{
				EngineTimer_0();

			}

			else
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Engine 1 is broken"));
				DecreaseStable();
			}

			if (bEngineBroken_1 == false)
			{
				EngineTimer_1();
			}

			else
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Engine 2 is broken"));
				DecreaseStable();
			}

			if (bSteeringBroken == false)
			{
				SteeringTimer();
			}

			else
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Steering is broken"));
				DecreaseStable();
			}

			if (bO2RefreshBroken == false)
			{
				O2RefreshTimer();
			}

			else
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Oxygen refresher is broken"));
				DecreaseStable();
			}

			if (bO2H2OStorageBroken == false)
			{
				O2H2OStorageTimer();
			}

			else
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Oxygen/Water storage is broken"));
				DecreaseStable();
			}

			if (bFuelStorageBroken == false)
			{
				FuelStorageTimer();
			}

			else
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Fuel storage is broken"));
				DecreaseStable();
			}

			if (bBridgeBroken == false)
			{
				BridgeTimer();
			}

			else
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Bridge is broken"));
				DecreaseStable();
			}

			if (bStaffMainBroken == false)
			{
				StaffMainTimer();
			}

			else
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Staff maintenance is broken"));
				DecreaseStable();
			}

			if (bDOSSBroken == false)
			{
				DOSSTimer();
			}

			else
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("DOSS is broken"));
				DecreaseStable();
			}
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

void AExperimentalGameMode::AddStable()
{
	stableNum = stableNum + 10;
}

void AExperimentalGameMode::DecreaseStable()
{
	stableNum = stableNum - 10;
	UGameplayStatics::PlaySound2D(this, WarningSFX);
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

void AExperimentalGameMode::SteeringTimer()
{
	FTimerHandle delayHandle;
	GetWorldTimerManager().SetTimer(delayHandle, this, &AExperimentalGameMode::SteeringChance, 30.f, false);
}

void AExperimentalGameMode::O2RefreshTimer()
{
	FTimerHandle delayHandle;
	GetWorldTimerManager().SetTimer(delayHandle, this, &AExperimentalGameMode::O2RefreshChance, 30.f, false);
}

void AExperimentalGameMode::O2H2OStorageTimer()
{
	FTimerHandle delayHandle;
	GetWorldTimerManager().SetTimer(delayHandle, this, &AExperimentalGameMode::O2H2OStorageChance, 30.f, false);
}

void AExperimentalGameMode::FuelStorageTimer()
{
	FTimerHandle delayHandle;
	GetWorldTimerManager().SetTimer(delayHandle, this, &AExperimentalGameMode::FuelStorageChance, 30.f, false);
}

void AExperimentalGameMode::BridgeTimer()
{
	FTimerHandle delayHandle;
	GetWorldTimerManager().SetTimer(delayHandle, this, &AExperimentalGameMode::BridgeChance, 30.f, false);
}

void AExperimentalGameMode::StaffMainTimer()
{
	FTimerHandle delayHandle;
	GetWorldTimerManager().SetTimer(delayHandle, this, &AExperimentalGameMode::StaffMainChance, 30.f, false);
}

void AExperimentalGameMode::DOSSTimer()
{
	FTimerHandle delayHandle;
	GetWorldTimerManager().SetTimer(delayHandle, this, &AExperimentalGameMode::DOSSChance, 30.f, false);
}

void AExperimentalGameMode::EngineChance_0()
{
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	stateEngine_0 = FMath::RandRange(0, 20);
	FTimerHandle TimerHandle;

	if (stateEngine_0 < chanceNum)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Engine 1 is broken"));
		bEngineBroken_0 = true;
		DecreaseStable();
		return;
	}

	else
	{
		EngineTimer_0();
		return;
	}
}

void AExperimentalGameMode::EngineChance_1()
{
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	stateEngine_1 = FMath::RandRange(0, 20);
	FTimerHandle TimerHandle;

	if (stateEngine_1 < chanceNum)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Engine 2 is broken"));
		bEngineBroken_1 = true;
		DecreaseStable();
		return;
	}

	else
	{
		EngineTimer_1();
		return;
	}
}

void AExperimentalGameMode::SteeringChance()
{
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	stateSteering = FMath::RandRange(0, 20);
	FTimerHandle TimerHandle;

	if (stateSteering < chanceNum)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Steering is broken"));
		bSteeringBroken = true;
		DecreaseStable();
		return;
	}

	else
	{
		SteeringTimer();
		return;
	}
}

void AExperimentalGameMode::O2RefreshChance()
{
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	stateO2Refresh = FMath::RandRange(0, 20);
	FTimerHandle TimerHandle;

	if (stateO2Refresh < chanceNum)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Oxygen refresher is broken"));
		bO2RefreshBroken = true;
		DecreaseStable();
		return;
	}

	else
	{
		O2RefreshTimer();
		return;
	}
}

void AExperimentalGameMode::O2H2OStorageChance()
{
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	stateO2H2OStorage = FMath::RandRange(0, 20);
	FTimerHandle TimerHandle;

	if (stateO2H2OStorage < chanceNum)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Oxygen/Water Storage is broken"));
		bO2H2OStorageBroken = true;
		DecreaseStable();
		return;
	}

	else
	{
		O2H2OStorageTimer();
		return;
	}
}

void AExperimentalGameMode::FuelStorageChance()
{
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	stateFuelStorage = FMath::RandRange(0, 20);
	FTimerHandle TimerHandle;

	if (stateFuelStorage < chanceNum)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Fuel storage is broken"));
		bFuelStorageBroken = true;
		DecreaseStable();
		return;
	}

	else
	{
		FuelStorageTimer();
		return;
	}
}

void AExperimentalGameMode::BridgeChance()
{
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	stateBridge = FMath::RandRange(0, 20);
	FTimerHandle TimerHandle;

	if (stateBridge < chanceNum)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Bridge is broken"));
		bBridgeBroken = true;
		DecreaseStable();
		return;
	}

	else
	{
		BridgeTimer();
		return;
	}
}

void AExperimentalGameMode::StaffMainChance()
{
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	stateStaffMain = FMath::RandRange(0, 20);
	FTimerHandle TimerHandle;

	if (stateStaffMain < chanceNum)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Staff maintenance is broken"));
		bStaffMainBroken = true;
		DecreaseStable();
		return;
	}

	else
	{
		StaffMainTimer();
		return;
	}
}

void AExperimentalGameMode::DOSSChance()
{
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	stateDOSS = FMath::RandRange(0, 20);
	FTimerHandle TimerHandle;

	if (stateDOSS < chanceNum)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("DOSS is broken"));
		bDOSSBroken = true;
		DecreaseStable();
		return;
	}

	else
	{
		DOSSTimer();
		return;
	}
}