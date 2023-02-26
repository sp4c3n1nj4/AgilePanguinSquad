// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup_Pipe.h"
#include "Kismet/GameplayStatics.h"
#include "ExperimentalCharacter.h"

APickup_Pipe::APickup_Pipe()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	itemName = "Pipe";
	itemAction = "pick up";
	itemDescription = "This is a pipe";
}

void APickup_Pipe::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_Pipe::Use_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a pipe: Use_Implementation() IT'S COOL IF YOU'RE SEEING THIS"));
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	MyCharacter->ToggleInventory();
}