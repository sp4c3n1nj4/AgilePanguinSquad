// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup_WineBottle.h"
#include "Kismet/GameplayStatics.h"
#include "ExperimentalCharacter.h"

APickup_WineBottle::APickup_WineBottle()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	itemName = "Wine Bottle";
	itemAction = "pick up";
	itemDescription = "This is a wine bottle";
	uses = 1;
}

void APickup_WineBottle::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_WineBottle::Use_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a wine bottle: Use_Implementation() IT'S COOL IF YOU'RE SEEING THIS"));
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	MyCharacter->ToggleInventory();
}

void APickup_WineBottle::Discard_Implementation()
{
	interactableMesh->SetVisibility(true);
	interactableMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}