// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup_Shovel.h"
#include "Kismet/GameplayStatics.h"
#include "../ExperimentalCharacter.h"

APickup_Shovel::APickup_Shovel()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	itemName = "Shovel";
	itemAction = "pick up";
	itemDescription = "This is a shovel";
	uses = NULL;
}

void APickup_Shovel::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_Shovel::Use_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a shovel: Use_Implementation() IT'S COOL IF YOU'RE SEEING THIS"));
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	MyCharacter->ToggleInventory();
}

void APickup_Shovel::Discard_Implementation()
{
	interactableMesh->SetVisibility(true);
	interactableMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}