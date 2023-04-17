// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup_Turnip.h"
#include "Kismet/GameplayStatics.h"
#include "../ExperimentalCharacter.h"

APickup_Turnip::APickup_Turnip()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	itemName = "Turnip";
	itemAction = "pick up";
	itemDescription = "This is a turnip";
	uses = 1;
}

void APickup_Turnip::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_Turnip::Use_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a turnip: Use_Implementation() IT'S COOL IF YOU'RE SEEING THIS"));
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	MyCharacter->ToggleInventory();
	uses--;
	if (uses == 0)
	{
		Discard_Implementation();
		uses = 1;
	}
}

void APickup_Turnip::Discard_Implementation()
{
	interactableMesh->SetVisibility(true);
	interactableMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}
