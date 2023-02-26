// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup_DataTablet.h"
#include "Kismet/GameplayStatics.h"
#include "ExperimentalCharacter.h"

APickup_DataTablet::APickup_DataTablet()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	itemName = "Data Tablet";
	itemAction = "pick up";
	itemDescription = "This is a data tablet";
}

void APickup_DataTablet::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_DataTablet::Use_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a data tablet: Use_Implementation() IT'S COOL IF YOU'RE SEEING THIS"));
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	MyCharacter->ToggleInventory();
}