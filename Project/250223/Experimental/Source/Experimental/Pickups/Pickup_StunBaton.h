#pragma once

#include "CoreMinimal.h"
#include "../Pickup.h"
#include "Pickup_StunBaton.generated.h"

/**
 *
 */
UCLASS()
class EXPERIMENTAL_API APickup_StunBaton : public APickup
{
	GENERATED_BODY()

public:
	APickup_StunBaton();
	virtual void Use_Implementation() override;
	virtual void Discard_Implementation() override;

protected:
	virtual void BeginPlay();
};