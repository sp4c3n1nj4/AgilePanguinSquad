#include "CoreMinimal.h"
#include "Pickup.h"
#include "Pickup_DataTablet.generated.h"

/**
 *
 */
UCLASS()
class EXPERIMENTAL_API APickup_DataTablet : public APickup
{
	GENERATED_BODY()

public:
	APickup_DataTablet();
	virtual void Use_Implementation() override;

protected:
	virtual void BeginPlay();
};