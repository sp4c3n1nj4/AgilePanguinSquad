#include "CoreMinimal.h"
#include "Pickup.h"
#include "Pickup_Pie.generated.h"

/**
 *
 */
UCLASS()
class EXPERIMENTAL_API APickup_Pie : public APickup
{
	GENERATED_BODY()

public:
	APickup_Pie();
	virtual void Use_Implementation() override;

protected:
	virtual void BeginPlay();
};