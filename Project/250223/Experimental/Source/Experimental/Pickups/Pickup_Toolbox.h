// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Pickup.h"
#include "Pickup_Toolbox.generated.h"

/**
 * 
 */
UCLASS()
class EXPERIMENTAL_API APickup_Toolbox : public APickup
{
	GENERATED_BODY()

	APickup_Toolbox();
	virtual void Use_Implementation() override;
	virtual void Discard_Implementation() override;
	virtual void OnPickedUp() override;

protected:
	virtual void BeginPlay();
};
