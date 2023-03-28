// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
#include "Pickup_FuelTank.generated.h"

/**
 * 
 */
UCLASS()
class EXPERIMENTAL_API APickup_FuelTank : public APickup
{
	GENERATED_BODY()

public:
	APickup_FuelTank();
	virtual void Use_Implementation() override;
	virtual void Discard_Implementation() override;

protected:
	virtual void BeginPlay();
	
};
