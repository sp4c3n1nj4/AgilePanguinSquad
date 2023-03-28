#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
#include "Pickup_Suitcase.generated.h"

/**
 *
 */
UCLASS()
class EXPERIMENTAL_API APickup_Suitcase : public APickup
{
	GENERATED_BODY()

public:
	APickup_Suitcase();
	virtual void Use_Implementation() override;
	virtual void Discard_Implementation() override;

protected:
	virtual void BeginPlay();
};