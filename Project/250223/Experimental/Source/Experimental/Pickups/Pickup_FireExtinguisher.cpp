// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup_FireExtinguisher.h"
#include "Kismet/GameplayStatics.h"
#include "../ExperimentalCharacter.h"
#include "../ExperimentalGameMode.h"

APickup_FireExtinguisher::APickup_FireExtinguisher()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	uses = 3;
	itemName = FString::Printf(TEXT("Fire Extinguisher (x%d)"), uses);
	itemAction = "pick up";
	itemDescription = "Used to repair oxygen refreshers. 3x use.";
}

void APickup_FireExtinguisher::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_FireExtinguisher::Use_Implementation()
{
	AExperimentalGameMode* GM = Cast<AExperimentalGameMode>(GetWorld()->GetAuthGameMode());
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	
	if (MyCharacter->bO2RefresherOverlap == true)
	{
		if (GM->bO2RefreshBroken == false)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You fixed the oxygen refresher"));
			MyCharacter->ToggleInventory();
			GM->AddStable();
			GM->bO2RefreshBroken = false;
			uses--;
			return;
		}

		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("The oxygen refresher doesn't need fixing yet"));
			return;
		}
	}

	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("You can't use the fire extinguisher here"));
	}
	

}

void APickup_FireExtinguisher::Discard_Implementation()
{
	interactableMesh->SetVisibility(true);
	interactableMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}