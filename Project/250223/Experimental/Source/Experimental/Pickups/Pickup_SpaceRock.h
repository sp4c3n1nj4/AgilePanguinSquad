#pragma once

#include "CoreMinimal.h"
#include "../Pickup.h"
#include "Pickup_SpaceRock.generated.h"

/**
 *
 */
UCLASS()
class EXPERIMENTAL_API APickup_SpaceRock : public APickup
{
	GENERATED_BODY()

public:
	APickup_SpaceRock();
	virtual void Use_Implementation() override;
	virtual void Discard_Implementation() override;

protected:
	virtual void BeginPlay();
};