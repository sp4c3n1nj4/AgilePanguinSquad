// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup_Lighter.h"
#include "Kismet/GameplayStatics.h"
#include "ExperimentalCharacter.h"
#include "ExperimentalGameMode.h"

APickup_Lighter::APickup_Lighter()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	itemName = "Lighter";
	itemAction = "pick up";
	itemDescription = "This is a lighter";
	uses = NULL;
}

void APickup_Lighter::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_Lighter::Use_Implementation()
{
	AExperimentalGameMode* GM = Cast<AExperimentalGameMode>(GetWorld()->GetAuthGameMode());
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a lighter: Use_Implementation() IT'S COOL IF YOU'RE SEEING THIS"));
	MyCharacter->ToggleInventory();
}

void APickup_Lighter::Discard_Implementation()
{
	interactableMesh->SetVisibility(true);
	interactableMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}