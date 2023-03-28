#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
#include "Pickup_Screwdriver.generated.h"

/**
 *
 */
UCLASS()
class EXPERIMENTAL_API APickup_Screwdriver : public APickup
{
	GENERATED_BODY()

public:
	APickup_Screwdriver();
	virtual void Use_Implementation() override;
	virtual void Discard_Implementation() override;

protected:
	virtual void BeginPlay();
};