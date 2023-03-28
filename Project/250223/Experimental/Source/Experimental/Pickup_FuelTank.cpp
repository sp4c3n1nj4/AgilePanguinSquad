// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup_FuelTank.h"
#include "Kismet/GameplayStatics.h"
#include "ExperimentalCharacter.h"

APickup_FuelTank::APickup_FuelTank()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	itemName = "Fuel Tank";
	itemAction = "pick up";
	itemDescription = "This is a fuel tank";
	uses = 3;
}

void APickup_FuelTank::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_FuelTank::Use_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a fuel tank: Use_Implementation() IT'S COOL IF YOU'RE SEEING THIS"));
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	MyCharacter->ToggleInventory();
}

void APickup_FuelTank::Discard_Implementation()
{
	interactableMesh->SetVisibility(true);
	interactableMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}