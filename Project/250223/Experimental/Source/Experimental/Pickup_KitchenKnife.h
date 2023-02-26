#include "CoreMinimal.h"
#include "Pickup.h"
#include "Pickup_KitchenKnife.generated.h"

/**
 *
 */
UCLASS()
class EXPERIMENTAL_API APickup_KitchenKnife : public APickup
{
	GENERATED_BODY()

public:
	APickup_KitchenKnife();
	virtual void Use_Implementation() override;

protected:
	virtual void BeginPlay();
};