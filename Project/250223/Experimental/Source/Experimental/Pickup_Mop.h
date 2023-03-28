#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
#include "Pickup_Mop.generated.h"

/**
 *
 */
UCLASS()
class EXPERIMENTAL_API APickup_Mop : public APickup
{
	GENERATED_BODY()

public:
	APickup_Mop();
	virtual void Use_Implementation() override;
	virtual void Discard_Implementation() override;

protected:
	virtual void BeginPlay();
};