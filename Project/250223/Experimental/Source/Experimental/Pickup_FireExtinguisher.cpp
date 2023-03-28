// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup_FireExtinguisher.h"
#include "Kismet/GameplayStatics.h"
#include "ExperimentalCharacter.h"

APickup_FireExtinguisher::APickup_FireExtinguisher()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	itemName = "Fire Extinguisher";
	itemAction = "pick up";
	itemDescription = "This is a fire extinguisher";
	uses = 3;
}

void APickup_FireExtinguisher::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_FireExtinguisher::Use_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a fire extinguisher: Use_Implementation() IT'S COOL IF YOU'RE SEEING THIS"));
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	MyCharacter->ToggleInventory();
}