// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup_Chair.h"

APickup_Chair::APickup_Chair()
{
	/*Default values, 
	best to set the thumbnail, & mesh in the editor*/
	itemName = "Chair";
	itemAction = "pick up";
	itemDescription = "This is a chair";
}

void APickup_Chair::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_Chair::Use_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a chair: Use_Implementation() IT'S COOL IF YOU'RE SEEING THIS"));
}
