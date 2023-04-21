// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup_Pie.h"
#include "Kismet/GameplayStatics.h"
#include "../ExperimentalCharacter.h"

APickup_Pie::APickup_Pie()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	itemName = "Pie";
	itemAction = "pick up";
	itemDescription = "This is a pie";
	uses = 1;
	bUsable = false;
}

void APickup_Pie::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_Pie::Use_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a pie: Use_Implementation() IT'S COOL IF YOU'RE SEEING THIS"));
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	MyCharacter->ToggleInventory();
	MyCharacter->DecreaseSus();
	bUsable = true;
}

void APickup_Pie::Discard_Implementation()
{
	interactableMesh->SetVisibility(true);
	interactableMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

void APickup_Pie::Reset_Uses()
{
	uses = 1;
}