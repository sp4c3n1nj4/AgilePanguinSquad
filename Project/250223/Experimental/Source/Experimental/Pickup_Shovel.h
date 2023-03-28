#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
#include "Pickup_Shovel.generated.h"

/**
 *
 */
UCLASS()
class EXPERIMENTAL_API APickup_Shovel : public APickup
{
	GENERATED_BODY()

public:
	APickup_Shovel();
	virtual void Use_Implementation() override;

protected:
	virtual void BeginPlay();
};