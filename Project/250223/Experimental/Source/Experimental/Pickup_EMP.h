#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
#include "Pickup_EMP.generated.h"

/**
 *
 */
UCLASS()
class EXPERIMENTAL_API APickup_EMP : public APickup
{
	GENERATED_BODY()

public:
	APickup_EMP();
	virtual void Use_Implementation() override;
	virtual void Discard_Implementation() override;

protected:
	virtual void BeginPlay();
};