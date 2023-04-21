// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup_Duster.h"
#include "Kismet/GameplayStatics.h"
#include "../ExperimentalCharacter.h"

APickup_Duster::APickup_Duster()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	itemName = "Duster";
	itemAction = "pick up";
	itemDescription = "This is a duster";
	uses = NULL;
	bUsable = false;
}

void APickup_Duster::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_Duster::Use_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a duster: Use_Implementation() IT'S COOL IF YOU'RE SEEING THIS"));
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	MyCharacter->ToggleInventory();
	MyCharacter->DecreaseSus();
	bUsable = true;
}

void APickup_Duster::Discard_Implementation()
{
	interactableMesh->SetVisibility(true);
	interactableMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}