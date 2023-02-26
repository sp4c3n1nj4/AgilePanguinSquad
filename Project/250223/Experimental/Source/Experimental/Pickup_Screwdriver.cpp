// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup_Screwdriver.h"
#include "Kismet/GameplayStatics.h"
#include "ExperimentalCharacter.h"

APickup_Screwdriver::APickup_Screwdriver()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	itemName = "Screwdriver";
	itemAction = "pick up";
	itemDescription = "This is a screwdriver";
}

void APickup_Screwdriver::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_Screwdriver::Use_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a screwdriver: Use_Implementation() IT'S COOL IF YOU'RE SEEING THIS"));
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	MyCharacter->ToggleInventory();
}