// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ExperimentalGameMode.generated.h"

UCLASS(minimalapi)
class AExperimentalGameMode : public AGameModeBase
{
	GENERATED_BODY()

		virtual void BeginPlay() override;

public:
	AExperimentalGameMode();

	/*Unsigned integer of 8 bits in size, gives each state a ordered value starting from 0*/
	enum EHUDState : uint8
	{
		HS_Ingame, /*0*/
		HS_Inventory, /*1*/
		HS_Pause /*2*/
	};

	/*Checks the hud state, and tgeb calls applyHUD accordingly to apply whatever hud we want*/
	void ApplyHUDChanges();

	/*Getter function for hudstate*/
	uint8 GetHUDState();

	/*Setter function for the hudstate, applies the new state and then calls ApplyHUDChanges*/
	UFUNCTION(BlueprintCallable, Category = "HUD Functions")
	void ChangeHUDState(uint8 NewState);

	/*Applies a hud to the screen, returns true if successful, false otherwise*/
	bool ApplyHUD(TSubclassOf<class UUserWidget> WidgetToApply, bool bShowMouseCursor, bool EnableClickEvents);

	void EngineTimer_0();
	void EngineTimer_1();
	void SteeringTimer();
	void EngineChance_0();
	void EngineChance_1();
	void SteeringChance();

	int stateEngine_0;
	int stateEngine_1;
	int stateSteering;
	
	UPROPERTY(EditAnywhere, Category = "Variables")
	bool bEngineBroken_0;

	UPROPERTY(EditAnywhere, Category = "Variables")
	bool bEngineBroken_1;

	UPROPERTY(EditAnywhere, Category = "Variables")
	bool bSteeringBroken;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	int stableNum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	int maxStableNum;

	bool bToolboxEquipped;

protected:
	/*Actual HUD State, can only be used within this class, and not outside*/
	uint8 HUDState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HUDwidgets", Meta = (BlueprintProtected = "true"))
	TSubclassOf<class UUserWidget> IngameHUDClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HUDwidgets", Meta = (BlueprintProtected = "true"))
	TSubclassOf<class UUserWidget> InventoryHUDClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HUDwidgets", Meta = (BlueprintProtected = "true"))
	TSubclassOf<class UUserWidget> PauseHUDClass;

	UPROPERTY()
	class UUserWidget* CurrentWidget;
};



