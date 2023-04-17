// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup_DuctTape.h"
#include "Kismet/GameplayStatics.h"
#include "../ExperimentalCharacter.h"

APickup_DuctTape::APickup_DuctTape()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	itemName = "Duct Tape";
	itemAction = "pick up";
	itemDescription = "This is duct tape";
	uses = 3;
}

void APickup_DuctTape::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_DuctTape::Use_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used duct tape: Use_Implementation() IT'S COOL IF YOU'RE SEEING THIS"));
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	MyCharacter->ToggleInventory();
	uses--;
	if (uses == 0)
	{
		Discard_Implementation();
		uses = 3;
	}
	else
	{
		itemName = FString::Printf(TEXT("Duct Tape (x%d)"), uses);
	}
}

void APickup_DuctTape::Discard_Implementation()
{
	interactableMesh->SetVisibility(true);
	interactableMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}