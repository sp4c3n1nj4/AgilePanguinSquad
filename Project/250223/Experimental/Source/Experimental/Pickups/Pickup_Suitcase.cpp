// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup_Suitcase.h"
#include "Kismet/GameplayStatics.h"
#include "../ExperimentalCharacter.h"

APickup_Suitcase::APickup_Suitcase()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	itemName = "Suitcase";
	itemAction = "pick up";
	itemDescription = "This is a suitcase";
	uses = 1;
	bUsable = false;
}

void APickup_Suitcase::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_Suitcase::Use_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a suitcase: Use_Implementation() IT'S COOL IF YOU'RE SEEING THIS"));
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	MyCharacter->ToggleInventory();
	MyCharacter->AddSus();
	bUsable = true;
}

void APickup_Suitcase::Discard_Implementation()
{
	interactableMesh->SetVisibility(true);
	interactableMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

void APickup_Suitcase::Reset_Uses()
{
	uses = 1;
}