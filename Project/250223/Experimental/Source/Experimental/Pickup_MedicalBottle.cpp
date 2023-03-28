// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup_MedicalBottle.h"
#include "Kismet/GameplayStatics.h"
#include "ExperimentalCharacter.h"

APickup_MedicalBottle::APickup_MedicalBottle()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	itemName = "Medical Bottle";
	itemAction = "pick up";
	itemDescription = "This is a medical bottle";
	uses = 3;
}

void APickup_MedicalBottle::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_MedicalBottle::Use_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a medical bottle: Use_Implementation() IT'S COOL IF YOU'RE SEEING THIS"));
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	MyCharacter->ToggleInventory();
}

void APickup_MedicalBottle::Discard_Implementation()
{
	interactableMesh->SetVisibility(true);
	interactableMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}