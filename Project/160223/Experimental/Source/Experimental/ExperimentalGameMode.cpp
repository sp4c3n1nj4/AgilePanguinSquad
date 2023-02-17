// Copyright Epic Games, Inc. All Rights Reserved.

#include "ExperimentalGameMode.h"
#include "ExperimentalCharacter.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

void AExperimentalGameMode::BeginPlay()
{
	/*As soon as the player enters the game, apply hud to the screen*/
	ApplyHUDChanges();
}

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