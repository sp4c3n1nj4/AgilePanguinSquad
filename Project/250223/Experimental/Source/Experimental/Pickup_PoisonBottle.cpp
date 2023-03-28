// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup_PoisonBottle.h"
#include "Kismet/GameplayStatics.h"
#include "ExperimentalCharacter.h"

APickup_PoisonBottle::APickup_PoisonBottle()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	itemName = "Poison Bottle";
	itemAction = "pick up";
	itemDescription = "This is a poison bottle";
	uses = 3;
}

void APickup_PoisonBottle::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_PoisonBottle::Use_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a poison bottle: Use_Implementation() IT'S COOL IF YOU'RE SEEING THIS"));
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	MyCharacter->ToggleInventory();
}

void APickup_PoisonBottle::Discard_Implementation()
{
	interactableMesh->SetVisibility(true);
	interactableMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}