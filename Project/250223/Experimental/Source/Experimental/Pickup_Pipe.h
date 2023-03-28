#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
#include "Pickup_Pipe.generated.h"

/**
 *
 */
UCLASS()
class EXPERIMENTAL_API APickup_Pipe : public APickup
{
	GENERATED_BODY()

public:
	APickup_Pipe();
	virtual void Use_Implementation() override;

protected:
	virtual void BeginPlay();
};
