// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Pickup.h"
#include "Pickup_Bomb.generated.h"

/**
 * 
 */
UCLASS()
class EXPERIMENTAL_API APickup_Bomb : public APickup
{
	GENERATED_BODY()

public:
	APickup_Bomb();
	virtual void Use_Implementation() override;
	void UseAccepted();
	virtual void Discard_Implementation() override;

protected:
	virtual void BeginPlay();
};
