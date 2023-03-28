// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup_Bomb.h"
#include "Kismet/GameplayStatics.h"
#include "ExperimentalCharacter.h"

APickup_Bomb::APickup_Bomb()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	itemName = "Bomb";
	itemAction = "pick up";
	itemDescription = "This is a bomb";
}

void APickup_Bomb::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_Bomb::Use_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a bomb: Use_Implementation() IT'S COOL IF YOU'RE SEEING THIS"));
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	MyCharacter->ToggleInventory();
}
