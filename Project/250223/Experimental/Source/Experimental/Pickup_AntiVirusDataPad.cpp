// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup_AntiVirusDataPad.h"
#include "Kismet/GameplayStatics.h"
#include "ExperimentalCharacter.h"

APickup_AntiVirusDataPad::APickup_AntiVirusDataPad()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	itemName = "Anti-Virus Data Pad";
	itemAction = "pick up";
	itemDescription = "This is an anti-virus data pad";
	uses = NULL;
}

void APickup_AntiVirusDataPad::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_AntiVirusDataPad::Use_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used an anti-virus data pad: Use_Implementation() IT'S COOL IF YOU'RE SEEING THIS"));
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	MyCharacter->ToggleInventory();
}

void APickup_AntiVirusDataPad::Discard_Implementation()
{
	interactableMesh->SetVisibility(true);
	interactableMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}
