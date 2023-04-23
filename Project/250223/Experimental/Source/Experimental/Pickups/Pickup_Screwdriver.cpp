// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup_Screwdriver.h"
#include "Kismet/GameplayStatics.h"
#include "../ExperimentalCharacter.h"
#include "../ExperimentalGameMode.h"

APickup_Screwdriver::APickup_Screwdriver()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	itemName = "Screwdriver";
	itemAction = "pick up";
	itemDescription = "Permanently damages the staff maintenance safety switch. Infinite use.";
	uses = NULL;
	bUsable = false;
}

void APickup_Screwdriver::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_Screwdriver::Use_Implementation()
{
	AExperimentalGameMode* GM = Cast<AExperimentalGameMode>(GetWorld()->GetAuthGameMode());
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));

	if (MyCharacter->bStaffMainOverlap == true)
	{
		if (GM->bStaffMainBroken == false)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You damaged the staff maintenance room"));
			MyCharacter->ToggleInventory();
			MyCharacter->AddSus();
			GM->DecreaseStable();
			bUsable = true;
			GM->bStaffMainBroken = true;
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Staff maintenance is already damaged"));
			bUsable = false;
			return;
		}
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Screwdriver can't be used here"));
		bUsable = false;
	}
}

void APickup_Screwdriver::Discard_Implementation()
{
	interactableMesh->SetVisibility(true);
	interactableMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}