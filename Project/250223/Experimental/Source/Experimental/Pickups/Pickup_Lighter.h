#pragma once

#include "CoreMinimal.h"
#include "../Pickup.h"
#include "Pickup_Lighter.generated.h"

/**
 *
 */
UCLASS()
class EXPERIMENTAL_API APickup_Lighter : public APickup
{
	GENERATED_BODY()

public:
	APickup_Lighter();
	virtual void Use_Implementation() override;
	virtual void Discard_Implementation() override;

protected:
	virtual void BeginPlay();
};