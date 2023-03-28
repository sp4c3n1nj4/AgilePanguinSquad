// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup_EMP.h"
#include "Kismet/GameplayStatics.h"
#include "../ExperimentalCharacter.h"

APickup_EMP::APickup_EMP()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	itemName = "EMP";
	itemAction = "pick up";
	itemDescription = "This is an EMP";
	uses = NULL;
}

void APickup_EMP::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_EMP::Use_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used an EMP: Use_Implementation() IT'S COOL IF YOU'RE SEEING THIS"));
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	MyCharacter->ToggleInventory();
}

void APickup_EMP::Discard_Implementation()
{
	interactableMesh->SetVisibility(true);
	interactableMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}