#pragma once

#include "CoreMinimal.h"
#include "../Pickup.h"
#include "Pickup_Turnip.generated.h"

/**
 *
 */
UCLASS()
class EXPERIMENTAL_API APickup_Turnip : public APickup
{
	GENERATED_BODY()

public:
	APickup_Turnip();
	virtual void Use_Implementation() override;
	virtual void Discard_Implementation() override;
	virtual void Reset_Uses() override;

protected:
	virtual void BeginPlay();
};