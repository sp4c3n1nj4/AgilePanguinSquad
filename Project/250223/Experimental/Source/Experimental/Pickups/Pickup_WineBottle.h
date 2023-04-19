#pragma once

#include "CoreMinimal.h"
#include "../Pickup.h"
#include "Pickup_WineBottle.generated.h"

/**
 *
 */
UCLASS()
class EXPERIMENTAL_API APickup_WineBottle : public APickup
{
	GENERATED_BODY()

public:
	APickup_WineBottle();
	virtual void Use_Implementation() override;
	virtual void Discard_Implementation() override;
	virtual void Reset_Uses() override;

protected:
	virtual void BeginPlay();
};