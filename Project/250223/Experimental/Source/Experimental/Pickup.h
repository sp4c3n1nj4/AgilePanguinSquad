// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "Components/AudioComponent.h"
#include "Pickup.generated.h"

/**
 * 
 */
UCLASS()
class EXPERIMENTAL_API APickup : public AInteractable
{
	GENERATED_BODY()

public:

	APickup();

	virtual void BeginPlay() override;

	virtual void Interact_Implementation() override;
	
	UFUNCTION(BlueprintNativeEvent)
	void Use();

	virtual void Use_Implementation();
	virtual void Discard_Implementation();
	virtual void Reset_Uses();
	
	/*Item image*/
	UPROPERTY(EditAnywhere, Category = "Pickup Properties")
	UTexture2D* pickupThumbnail;
	
	/*Item name*/
	UPROPERTY(EditAnywhere, Category = "Pickup Properties")
	FString itemName;

	UPROPERTY(EditAnywhere, Category = "Pickup Properties")
	FString itemAction;

	UPROPERTY(EditAnywhere, Category = "Pickup Properties")
	FString itemDescription;

	UPROPERTY(EditAnywhere, Category = "Pickup SFX")
	UAudioComponent* pickupSFX;

	UPROPERTY(EditAnywhere, Category = "Pickup SFX")
	UAudioComponent* useSFX;

	UPROPERTY(EditAnywhere, Category = "Pickup SFX")
	UAudioComponent* discardSFX;

	int uses;
	bool bUsable;

	/*This is called when item is picked up and needs to be cleaned up from the level*/
	virtual void OnPickedUp();
};