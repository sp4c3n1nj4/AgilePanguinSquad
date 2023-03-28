// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup_VirusDataPad.h"
#include "Kismet/GameplayStatics.h"
#include "ExperimentalCharacter.h"

APickup_VirusDataPad::APickup_VirusDataPad()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	itemName = "Virus Data Pad";
	itemAction = "pick up";
	itemDescription = "This is a virus data pad";
	uses = 1;
}

void APickup_VirusDataPad::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_VirusDataPad::Use_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a virus data pad: Use_Implementation() IT'S COOL IF YOU'RE SEEING THIS"));
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	MyCharacter->ToggleInventory();
}

void APickup_VirusDataPad::Discard_Implementation()
{
	interactableMesh->SetVisibility(true);
	interactableMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}