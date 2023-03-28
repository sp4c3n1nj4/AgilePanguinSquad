// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup_MedicalBottle.h"
#include "Kismet/GameplayStatics.h"
#include "../ExperimentalCharacter.h"
#include "../ExperimentalGameMode.h"

APickup_MedicalBottle::APickup_MedicalBottle()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	uses = 3;
	itemName = FString::Printf(TEXT("Medical Bottle (x%d)"), uses);
	itemAction = "pick up";
	itemDescription = "Unpoisons the oxygen/water storage. 3x use.";
}

void APickup_MedicalBottle::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_MedicalBottle::Use_Implementation()
{
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	AExperimentalGameMode* GM = Cast<AExperimentalGameMode>(GetWorld()->GetAuthGameMode());
	
	if (MyCharacter->bO2H2OStorageOverlap == true)
	{
		if (GM->bO2H2OStorageBroken == true)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You unpoisoned the oxygen/water"));
			MyCharacter->ToggleInventory();
			GM->DecreaseStable();
			GM->bO2H2OStorageBroken = false;
			uses--;
			return;
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("The oxygen/water isn't poisoned"));
			return;
		}
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("You can't use the medical bottle here"));
	}
}

void APickup_MedicalBottle::Discard_Implementation()
{
	interactableMesh->SetVisibility(true);
	interactableMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}