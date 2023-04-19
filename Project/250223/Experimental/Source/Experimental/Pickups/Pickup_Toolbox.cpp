// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup_Toolbox.h"
#include "Kismet/GameplayStatics.h"
#include "../ExperimentalCharacter.h"
#include "../ExperimentalGameMode.h"

APickup_Toolbox::APickup_Toolbox()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	itemName = "Toolbox";
	itemAction = "pick up";
	itemDescription = "Holding the toolbox will double the chances of malfunctions.";
	uses = NULL;
	bUsable = false;
}

void APickup_Toolbox::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_Toolbox::Use_Implementation()
{
	GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Red, TEXT("Just hold it!"));
	bUsable = false;
}

void APickup_Toolbox::Discard_Implementation()
{
	AExperimentalGameMode* GM = Cast<AExperimentalGameMode>(GetWorld()->GetAuthGameMode());

	GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Green, TEXT("Toolbox discarded, malfunction chance has defaulted"));
	GM->chanceNum = 1;
	interactableMesh->SetVisibility(true);
	interactableMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

void APickup_Toolbox::OnPickedUp()
{
	AExperimentalGameMode* GM = Cast<AExperimentalGameMode>(GetWorld()->GetAuthGameMode());

	GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Green, TEXT("Toolbox held, malfunction chance has doubled"));
	GM->chanceNum = 2;
}