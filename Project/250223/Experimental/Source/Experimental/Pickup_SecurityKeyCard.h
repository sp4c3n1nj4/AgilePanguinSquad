#include "CoreMinimal.h"
#include "Pickup.h"
#include "Pickup_SecurityKeyCard.generated.h"

/**
 *
 */
UCLASS()
class EXPERIMENTAL_API APickup_SecurityKeyCard : public APickup
{
	GENERATED_BODY()

public:
	APickup_SecurityKeyCard();
	virtual void Use_Implementation() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	int securityLevel;

	UPROPERTY()
	FString securityLevelText;

protected:
	virtual void BeginPlay();
};