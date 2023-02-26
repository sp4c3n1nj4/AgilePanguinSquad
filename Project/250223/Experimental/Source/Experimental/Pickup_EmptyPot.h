#include "CoreMinimal.h"
#include "Pickup.h"
#include "Pickup_EmptyPot.generated.h"

/**
 *
 */
UCLASS()
class EXPERIMENTAL_API APickup_EmptyPot : public APickup
{
	GENERATED_BODY()

public:
	APickup_EmptyPot();
	virtual void Use_Implementation() override;

protected:
	virtual void BeginPlay();
};