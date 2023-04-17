// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup_FuelTank.h"
#include "Kismet/GameplayStatics.h"
#include "../ExperimentalCharacter.h"
#include "../ExperimentalGameMode.h"

APickup_FuelTank::APickup_FuelTank()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	uses = 3;
	itemName = FString::Printf(TEXT("Fuel Tank (x%d)"), uses);
	itemAction = "pick up";
	itemDescription = "Refuels fuel storage. 3x use.";
}

void APickup_FuelTank::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_FuelTank::Use_Implementation()
{
	AExperimentalGameMode* GM = Cast<AExperimentalGameMode>(GetWorld()->GetAuthGameMode());
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	
	if (MyCharacter->bFuelStorageOverlap == true)
	{
		if (GM->bFuelStorageBroken == true)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You added fuel to the pipes"));
			MyCharacter->ToggleInventory();
			GM->AddStable();
			GM->bFuelStorageBroken = false;
			uses--;
			if (uses == 0)
			{
				Discard_Implementation();
				uses = 3;
			}
			else
			{
				itemName = FString::Printf(TEXT("Fuel Tank (x%d)"), uses);
			}
			return;
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("The pipes don't need fuel yet"));
		}
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("You can't use the fuel tank here"));
	}
}

void APickup_FuelTank::Discard_Implementation()
{
	interactableMesh->SetVisibility(true);
	interactableMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}