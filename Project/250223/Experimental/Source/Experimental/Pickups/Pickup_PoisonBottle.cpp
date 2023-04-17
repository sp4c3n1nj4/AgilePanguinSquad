// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup_PoisonBottle.h"
#include "Kismet/GameplayStatics.h"
#include "../ExperimentalCharacter.h"
#include "../ExperimentalGameMode.h"

APickup_PoisonBottle::APickup_PoisonBottle()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	uses = 3;
	itemName = FString::Printf(TEXT("Poison Bottle (x%d)"), uses);
	itemAction = "pick up";
	itemDescription = "Poisons oxygen/water storage. 3x use.";
}

void APickup_PoisonBottle::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_PoisonBottle::Use_Implementation()
{
	AExperimentalGameMode* GM = Cast<AExperimentalGameMode>(GetWorld()->GetAuthGameMode());
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));

	if (MyCharacter->bO2H2OStorageOverlap == true)
	{
		if (GM->bO2H2OStorageBroken == false)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You poisoned the oxygen/water"));
			MyCharacter->ToggleInventory();
			GM->DecreaseStable();
			GM->bO2H2OStorageBroken = true;
			uses--;
			if (uses == 0)
			{
				Discard_Implementation();
				uses = 3;
			}
			else
			{
				itemName = FString::Printf(TEXT("Poison Bottle (x%d)"), uses);
			}
			return;
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("The oxygen/water is already poisoned"));
			return;
		}
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("You can't use the poison bottle here"));
	}
}

void APickup_PoisonBottle::Discard_Implementation()
{
	interactableMesh->SetVisibility(true);
	interactableMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}