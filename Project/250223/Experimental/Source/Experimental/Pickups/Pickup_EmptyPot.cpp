// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup_EmptyPot.h"
#include "Kismet/GameplayStatics.h"
#include "../ExperimentalCharacter.h"

APickup_EmptyPot::APickup_EmptyPot()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	itemName = "Empty Pot";
	itemAction = "pick up";
	itemDescription = "This is an empty pot";
	uses = 1;
}

void APickup_EmptyPot::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_EmptyPot::Use_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used an empty pot: Use_Implementation() IT'S COOL IF YOU'RE SEEING THIS"));
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	MyCharacter->ToggleInventory();
	uses--;
	if (uses == 0)
	{
		Discard_Implementation();
		uses = 1;
	}
}

void APickup_EmptyPot::Discard_Implementation()
{
	interactableMesh->SetVisibility(true);
	interactableMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}