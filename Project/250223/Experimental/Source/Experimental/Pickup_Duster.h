#include "CoreMinimal.h"
#include "Pickup.h"
#include "Pickup_Duster.generated.h"

/**
 *
 */
UCLASS()
class EXPERIMENTAL_API APickup_Duster : public APickup
{
	GENERATED_BODY()

public:
	APickup_Duster();
	virtual void Use_Implementation() override;

protected:
	virtual void BeginPlay();
};