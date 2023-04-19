// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup_Knife.h"
#include "Kismet/GameplayStatics.h"
#include "../ExperimentalCharacter.h"
#include "../ExperimentalGameMode.h"

APickup_Knife::APickup_Knife()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	itemName = "Knife";
	itemAction = "pick up";
	itemDescription = "Used to cut the pipes in the fuel storage room. Infinite use.";
	uses = NULL;
	bUsable = false;
}

void APickup_Knife::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_Knife::Use_Implementation()
{
	AExperimentalGameMode* GM = Cast<AExperimentalGameMode>(GetWorld()->GetAuthGameMode());
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	
	if (MyCharacter->bFuelStorageOverlap == true)
	{
		if (GM->bFuelStorageBroken == false)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You cut the pipes"));
			MyCharacter->ToggleInventory();
			GM->DecreaseStable();
			bUsable = true;
			GM->bFuelStorageBroken = true;
			return;
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("The pipes are already cut"));
			bUsable = false;
			return;
		}
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("You can't use the knife here"));
		bUsable = false;
	}
}

void APickup_Knife::Discard_Implementation()
{
	interactableMesh->SetVisibility(true);
	interactableMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}