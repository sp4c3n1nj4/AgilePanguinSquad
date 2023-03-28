#pragma once

#include "CoreMinimal.h"
#include "../Pickup.h"
#include "Pickup_Oil.generated.h"

/**
 *
 */
UCLASS()
class EXPERIMENTAL_API APickup_Oil : public APickup
{
	GENERATED_BODY()

public:
	APickup_Oil();
	virtual void Use_Implementation() override;
	virtual void Discard_Implementation() override;

protected:
	virtual void BeginPlay();
};