#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
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

	int uses;

protected:
	virtual void BeginPlay();
};