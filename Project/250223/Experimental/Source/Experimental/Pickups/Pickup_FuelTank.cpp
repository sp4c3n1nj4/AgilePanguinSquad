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
	itemName = "Fuel Tank";
	itemAction = "pick up";
	itemDescription = "Refuels fuel tanks in the fuel storage room. 3x use.";
	bUsable = false;
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
			MyCharacter->DecreaseSus();
			GM->AddStable();
			GM->RepairCheck();
			bUsable = true;
			GM->bFuelStorageBroken = false;
			return;
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("The pipes don't need fuel yet"));
			bUsable = false;
			return;
		}
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("You can't use the fuel tank here"));
		bUsable = false;
	}
}

void APickup_FuelTank::Discard_Implementation()
{
	interactableMesh->SetVisibility(true);
	interactableMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

void APickup_FuelTank::Reset_Uses()
{
	uses = 3;
}