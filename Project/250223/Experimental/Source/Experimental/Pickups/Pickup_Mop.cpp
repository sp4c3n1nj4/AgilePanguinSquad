// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup_Mop.h"
#include "Kismet/GameplayStatics.h"
#include "../ExperimentalCharacter.h"
#include "../ExperimentalGameMode.h"

APickup_Mop::APickup_Mop()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	itemName = "Mop";
	itemAction = "pick up";
	itemDescription = "This is a mop";
	uses = NULL;
	bUsable = false;
}

void APickup_Mop::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_Mop::Use_Implementation()
{
	AExperimentalGameMode* GM = Cast<AExperimentalGameMode>(GetWorld()->GetAuthGameMode());
	
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a mop: Use_Implementation() IT'S COOL IF YOU'RE SEEING THIS"));
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	MyCharacter->ToggleInventory();
	MyCharacter->DecreaseSus();
	GM->RepairCheck();
	bUsable = false;
}

void APickup_Mop::Discard_Implementation()
{
	interactableMesh->SetVisibility(true);
	interactableMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}