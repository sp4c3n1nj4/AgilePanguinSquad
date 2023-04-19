#pragma once

#include "CoreMinimal.h"
#include "../Pickup.h"
#include "Pickup_VirusDataPad.generated.h"

/**
 *
 */
UCLASS()
class EXPERIMENTAL_API APickup_VirusDataPad : public APickup
{
	GENERATED_BODY()

public:
	APickup_VirusDataPad();
	
	void UseAccepted();
	void DOSSReboot();
	
	virtual void Use_Implementation() override;
	virtual void Discard_Implementation() override;

protected:
	virtual void BeginPlay();
};