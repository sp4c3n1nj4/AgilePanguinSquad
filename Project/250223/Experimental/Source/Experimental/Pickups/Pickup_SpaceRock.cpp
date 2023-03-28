// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup_SpaceRock.h"
#include "Kismet/GameplayStatics.h"
#include "../ExperimentalCharacter.h"

APickup_SpaceRock::APickup_SpaceRock()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	itemName = "Space Rock";
	itemAction = "pick up";
	itemDescription = "This is a space rock";
	uses = NULL;
}

void APickup_SpaceRock::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_SpaceRock::Use_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a space rock: Use_Implementation() IT'S COOL IF YOU'RE SEEING THIS"));
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	MyCharacter->ToggleInventory();
}

void APickup_SpaceRock::Discard_Implementation()
{
	interactableMesh->SetVisibility(true);
	interactableMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}