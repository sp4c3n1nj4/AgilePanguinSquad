// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup_Wrench.h"
#include "Kismet/GameplayStatics.h"
#include "ExperimentalCharacter.h"

APickup_Wrench::APickup_Wrench()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	itemName = "Wrench";
	itemAction = "pick up";
	itemDescription = "This is a wrench";
}

void APickup_Wrench::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_Wrench::Use_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a wrench: Use_Implementation() IT'S COOL IF YOU'RE SEEING THIS"));
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	MyCharacter->ToggleInventory();
}