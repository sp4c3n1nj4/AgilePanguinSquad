// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup_Oil.h"
#include "Kismet/GameplayStatics.h"
#include "ExperimentalCharacter.h"

APickup_Oil::APickup_Oil()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	itemName = "Oil";
	itemAction = "pick up";
	itemDescription = "This is oil";
}

void APickup_Oil::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_Oil::Use_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used oil: Use_Implementation() IT'S COOL IF YOU'RE SEEING THIS"));
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	MyCharacter->ToggleInventory();
}