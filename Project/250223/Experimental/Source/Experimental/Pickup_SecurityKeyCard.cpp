// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup_SecurityKeyCard.h"
#include "Kismet/GameplayStatics.h"
#include "ExperimentalCharacter.h"

APickup_SecurityKeyCard::APickup_SecurityKeyCard()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	securityLevel = 1;
	securityLevelText = FString::FromInt(securityLevel);
	itemName = FString::Printf(TEXT("Security Key Card %s"), *securityLevelText);
	itemAction = "pick up";
	itemDescription = "This is a data tablet";
}

void APickup_SecurityKeyCard::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_SecurityKeyCard::Use_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a security key card: Use_Implementation() IT'S COOL IF YOU'RE SEEING THIS"));
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	MyCharacter->ToggleInventory();
}