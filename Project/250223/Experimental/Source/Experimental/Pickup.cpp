// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup.h"
#include "Experimental.h"
#include "ExperimentalCharacter.h"
#include <Kismet/GameplayStatics.h>

APickup::APickup()
{
	/*Set up the mesh for the pickup, and set the item name, help text and item value*/
	interactableMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickUpMesh"));
	interactableMesh->SetMobility(EComponentMobility::Static);
	interactableVFX = CreateDefaultSubobject<UParticleSystem>(TEXT("VFX"));

	itemName = FString("Enter an item name here..."); /*Default string, can be overriden later*/
	itemAction = FString("Enter an action here...");
	itemDescription = FString("Enter description here...");
	interactableHelpText = FString("Press E to pick item up."); /*Default help string, can be overriden later*/
	uses = 0;
	bUsable = false;
	pickupSFX = nullptr;
	useSFX = nullptr;
	discardSFX = nullptr;
}

void APickup::BeginPlay()
{
	Super::BeginPlay();

	interactableHelpText = FString::Printf(TEXT("%s: Press E to %s."), *itemName, *itemAction);
}

void APickup::Interact_Implementation()
{
	/*Character cast*/
	AExperimentalCharacter* Character = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));

	if (Character->AddItemToInventory(this))
	{
		OnPickedUp();
	}
}

/*Interacting with the base class, if you see this you've made a mistake*/
void APickup::Use_Implementation()
{
	GLog->Log("Use() from based pickup class : YOU SHOULD NOT BE SEEING THIS");
	useSFX->Play();
}

void APickup::Discard_Implementation()
{
	GLog->Log("Discard() from based pickup class : YOU SHOULD NOT BE SEEING THIS");
	discardSFX->Play();
}

void APickup::Reset_Uses()
{
	GLog->Log("Reset_Uses() from based pickup class : YOU SHOULD NOT BE SEEING THIS");
}

/*Doesn't destroy the pick up as it needs to be in world for the inventory, 
however, this will make the pickup invisible, with no physics or collision*/
void APickup::OnPickedUp()
{
	interactableMesh->SetVisibility(false);
	interactableMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	pickupSFX->Play();
}