// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup_StunBaton.h"
#include "Kismet/GameplayStatics.h"
#include "ExperimentalCharacter.h"

APickup_StunBaton::APickup_StunBaton()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	itemName = "Stun Baton";
	itemAction = "pick up";
	itemDescription = "This is a stun baton";
}

void APickup_StunBaton::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_StunBaton::Use_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a stun baton: Use_Implementation() IT'S COOL IF YOU'RE SEEING THIS"));
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	MyCharacter->ToggleInventory();
}