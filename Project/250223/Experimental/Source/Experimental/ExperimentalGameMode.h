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

	void AddStable();
	void DecreaseStable();

	void EngineTimer_0();
	void EngineTimer_1();
	void SteeringTimer();
	void O2RefreshTimer();
	void O2H2OStorageTimer();
	void FuelStorageTimer();
	void BridgeTimer();
	void StaffMainTimer();
	void DOSSTimer();

	void EngineChance_0();
	void EngineChance_1();
	void SteeringChance();
	void O2RefreshChance();
	void O2H2OStorageChance();
	void FuelStorageChance();
	void BridgeChance();
	void StaffMainChance();
	void DOSSChance();

	int chanceNum; /*For the toolbox*/
	
	/*Room states, this will determine the broken booleans*/
	int stateEngine_0;
	int stateEngine_1;
	int stateSteering;
	int stateO2Refresh;
	int stateO2H2OStorage;
	int stateFuelStorage;
	int stateBridge;
	int stateStaffMain;
	int stateDOSS;
	/*int stateCharging; //Need to split this up*/
	/*----------------------------------------*/
	
	/*Broken rooms, cargo hold (Room 2) cannot be broken*/
	bool bEngineBroken_0; // Room 8
	bool bEngineBroken_1; // Room 9
	bool bSteeringBroken; //Room 4
	bool bO2RefreshBroken; //?
	bool bO2H2OStorageBroken; // Room 10
	bool bFuelStorageBroken; //?
	bool bBridgeBroken; //?
	bool bStaffMainBroken; // Room 11
	bool bDOSSBroken; //Room 1
	/*bool bChargingBroken; //Room 7*/
	/*----------------------------------------------------*/
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	int stableNum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	int maxStableNum;

	//TUTORIALS
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tutorial")
	bool bOpenTutorialDoor2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tutorial")
	bool bOpenTutorialDoor3;

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



