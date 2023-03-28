#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
#include "Pickup_Knife.generated.h"

/**
 *
 */
UCLASS()
class EXPERIMENTAL_API APickup_Knife : public APickup
{
	GENERATED_BODY()

public:
	APickup_Knife();
	virtual void Use_Implementation() override;

protected:
	virtual void BeginPlay();
};