// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup_Knife.h"
#include "Kismet/GameplayStatics.h"
#include "ExperimentalCharacter.h"

APickup_Knife::APickup_Knife()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	itemName = "Knife";
	itemAction = "pick up";
	itemDescription = "This is a knife";
	uses = NULL;
}

void APickup_Knife::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_Knife::Use_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a knife: Use_Implementation() IT'S COOL IF YOU'RE SEEING THIS"));
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	MyCharacter->ToggleInventory();
}

void APickup_Knife::Discard_Implementation()
{
	interactableMesh->SetVisibility(true);
	interactableMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}