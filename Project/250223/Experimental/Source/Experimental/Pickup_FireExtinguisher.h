#include "CoreMinimal.h"
#include "Pickup.h"
#include "Pickup_FireExtinguisher.generated.h"

/**
 *
 */
UCLASS()
class EXPERIMENTAL_API APickup_FireExtinguisher : public APickup
{
	GENERATED_BODY()

public:
	APickup_FireExtinguisher();
	virtual void Use_Implementation() override;

protected:
	virtual void BeginPlay();
};