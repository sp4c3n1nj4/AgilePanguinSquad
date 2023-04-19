// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interactable.h"
#include "Pickup.h"
#include "InputActionValue.h"
#include "ExperimentalCharacter.generated.h"


UCLASS(config=Game)
class AExperimentalCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

	/*Toggle inventory input action*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* ToggleInventoryAction;

	/*Interact input action*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* InteractAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* PauseAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MapAreaAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* TestAreaAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* DecreaseSuspicionAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* IncreaseSuspicionAction;

public:
	AExperimentalCharacter();

	/*The players help text*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
	FString helpText;

	/*How close the player needs to be to the pickup*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory Functions")
	float reach;

	/*How close the player needs to be to the pickup*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory Functions")
	float suspicionPercentage;

	/*Variable which represents the player not being able to pick up a third object*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory Functions")
	bool bAlertText;

	bool bIsGamePaused;


	
	/*Overlap Checks*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Overlaps")
	bool bEngineOverlap_0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Overlaps")
	bool bEngineOverlap_1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Overlaps")
	bool bSteeringOverlap;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Overlaps")
	bool bO2RefresherOverlap;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Overlaps")
	bool bFuelStorageOverlap;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Overlaps")
	bool bBridgeOverlap;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Overlaps")
	bool bO2H2OStorageOverlap;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Overlaps")
	bool bStaffMainOverlap;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Overlaps")
	bool bDOSSOverlap;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Overlaps")
	bool bAPSRDChargeOverlap;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Overlaps")
	bool bC2M2ChargeOverlap;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Overlaps")
	bool bCaptainChargeOverlap;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Overlaps")
	bool bCarGOChargeOverlap;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Overlaps")
	bool bMIMAChargeOverlap;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Overlaps")
	bool bSOSChargeOverlap;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Overlaps")
	bool bSSRChargeOverlap;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Overlaps")
	bool bTutorial2Overlap;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Overlaps")
	bool bTutorial3Overlap;

	/*Adds an item to the inventory*/
	UFUNCTION(BlueprintPure, Category = "Inventory Functions")
	bool AddItemToInventory(APickup* Item);

	/*Gets the thumbnail for a given inventory slot*/
	UFUNCTION(BlueprintPure, Category = "Inventory Functions")
	UTexture2D* GetThumbnailAtInventorySlot(int32 slot);

	/*Gets the item name for a given inventory slot*/
	UFUNCTION(BlueprintPure, Category = "Inventory Functions")
	FString GetItemNameAtInventorySlot(int32 slot);

	/*Gets the item description for a given inventory slot*/
	UFUNCTION(BlueprintPure, Category = "Inventory Functions")
	FString GetItemDescriptionAtInventorySlot(int32 slot);

	/*Uses the item at a given inventory slot*/
	UFUNCTION(BlueprintCallable, Category = "Inventory Functions")
	void UseItemAtInventorySlot(int32 slot);

	/*Uses the item at a given inventory slot*/
	UFUNCTION(BlueprintCallable, Category = "Inventory Functions")
	void DeleteItemAtInventorySlot(int32 slot);

	UFUNCTION(BlueprintCallable, Category = "Pause Menu")
	void PauseGame();

	UFUNCTION(BlueprintCallable, Category = "Pause Menu")
	void OpenOptions();

	UFUNCTION(BlueprintCallable, Category = "Pause Menu")
	void CloseOptions();

	UFUNCTION(BlueprintCallable, Category = "Pause Menu")
	void QuitToMenu();

	/*Toggles between inventory and game*/
	void ToggleInventory();

	/*The players inventory, represented as a tarray of pickup objects*/
	UPROPERTY(EditAnywhere)
	TArray<APickup*>inventory;

protected:
	
	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay();

	virtual void Tick(float DeltaTime) override;

private:
	void Interact();
	void TestArea();
	void MapArea();
	void DecreaseSuspicion();
	void IncreaseSuspicion();

	/*Checks for interactable items directly in front of the player using a linetrace, called on a per tick basis*/
	void CheckForInteractables();

	/*The interactable the player is currently looking at*/
	AInteractable* currentInteractable;

	/*How many items can be in the inventory*/
	UPROPERTY(EditAnywhere, Category = "Inventory Functions")
	int inventoryLimit;

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};