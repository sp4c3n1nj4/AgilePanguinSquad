// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup_Lighter.h"
#include "Kismet/GameplayStatics.h"
#include "../ExperimentalCharacter.h"
#include "../ExperimentalGameMode.h"

APickup_Lighter::APickup_Lighter()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	itemName = "Lighter";
	itemAction = "pick up";
	itemDescription = "Damages the laptop in the oxygen refresher room. Infinite use.";
	uses = NULL;
	bUsable = false;
}

void APickup_Lighter::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_Lighter::Use_Implementation()
{
	AExperimentalGameMode* GM = Cast<AExperimentalGameMode>(GetWorld()->GetAuthGameMode());
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	
	if (MyCharacter->bO2RefresherOverlap == true)
	{
		if (GM->bO2RefreshBroken == false)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You broke the oxygen refresher"));
			MyCharacter->ToggleInventory();
			MyCharacter->AddSus();
			GM->DecreaseStable();
			bUsable = true;
			GM->bO2RefreshBroken = true;
			return;
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("The oxygen refresher is already broken"));
			bUsable = false;
			return;
		}
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("You can't use the lighter here"));
		bUsable = false;
	}
}

void APickup_Lighter::Discard_Implementation()
{
	interactableMesh->SetVisibility(true);
	interactableMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}