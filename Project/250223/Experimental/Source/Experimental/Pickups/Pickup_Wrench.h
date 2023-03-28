#pragma once

#include "CoreMinimal.h"
#include "../Pickup.h"
#include "Pickup_Wrench.generated.h"

/**
 *
 */
UCLASS()
class EXPERIMENTAL_API APickup_Wrench : public APickup
{
	GENERATED_BODY()

public:
	APickup_Wrench();
	virtual void Use_Implementation() override;
	virtual void Discard_Implementation() override;

protected:
	virtual void BeginPlay();
};