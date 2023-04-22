// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Sound/SoundCue.h"
#include "Kismet/GameplayStatics.h"
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
		HS_Pause, /*2*/
		HS_GameOver, /*3*/
		HS_RepairWin, /*4*/
		HS_DestroyWin /*5*/
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

	UFUNCTION(BlueprintCallable, Category = "Functions")
	void AddStable();

	void DecreaseStable();
	void RepairCheck();

	/*Timer functions*/
	UFUNCTION(BlueprintCallable, Category = "Timer Functions")
	void EngineTimer_0();
	UFUNCTION(BlueprintCallable, Category = "Timer Functions")
	void EngineTimer_1();
	UFUNCTION(BlueprintCallable, Category = "Timer Functions")
	void SteeringTimer();
	UFUNCTION(BlueprintCallable, Category = "Timer Functions")
	void O2RefreshTimer();
	UFUNCTION(BlueprintCallable, Category = "Timer Functions")
	void O2H2OStorageTimer();
	UFUNCTION(BlueprintCallable, Category = "Timer Functions")
	void FuelStorageTimer();
	UFUNCTION(BlueprintCallable, Category = "Timer Functions")
	void BridgeTimer();
	UFUNCTION(BlueprintCallable, Category = "Timer Functions")
	void StaffMainTimer();
	UFUNCTION(BlueprintCallable, Category = "Timer Functions")
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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Broken")
	bool bEngineBroken_0; // Room 8
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Broken")
	bool bEngineBroken_1; // Room 9
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Broken")
	bool bSteeringBroken; //Room 4
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Broken")
	bool bO2RefreshBroken; //?
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Broken")
	bool bO2H2OStorageBroken; // Room 10
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Broken")
	bool bFuelStorageBroken; //?
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Broken")
	bool bBridgeBroken; //?
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Broken")
	bool bStaffMainBroken; // Room 11
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Broken")
	bool bDOSSBroken; //Room 1
	/*bool bChargingBroken; //Room 7*/
	/*----------------------------------------------------*/

	/*Broken charging ports*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Charge")
	bool bAPSRDChargeBroken;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Charge")
	bool bC2M2ChargeBroken;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Charge")
	bool bCarGOChargeBroken;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Charge")
	bool bCaptainChargeBroken;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Charge")
	bool bMIMAChargeBroken;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Charge")
	bool bSOSChargeBroken;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Charge")
	bool bSSRChargeBroken;
	/*----------------------------------------------------*/
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	int stableNum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	int maxStableNum;

	int repairInt;
	int repairGoal;

	UPROPERTY(EditAnywhere, Category = "SFX")
	USoundCue* WarningSFX;

	//TUTORIALS
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tutorial")
	bool bTutorial;
	
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

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HUDwidgets", Meta = (BlueprintProtected = "true"))
	TSubclassOf<class UUserWidget> GameOverHUDClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HUDwidgets", Meta = (BlueprintProtected = "true"))
	TSubclassOf<class UUserWidget> RepairWinHUDClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HUDwidgets", Meta = (BlueprintProtected = "true"))
	TSubclassOf<class UUserWidget> DestroyWinHUDClass;

	UPROPERTY()
	class UUserWidget* CurrentWidget;
};



