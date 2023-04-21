// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup_AntiVirusDataPad.h"
#include "Kismet/GameplayStatics.h"
#include "../ExperimentalCharacter.h"
#include "../ExperimentalGameMode.h"

APickup_AntiVirusDataPad::APickup_AntiVirusDataPad()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	itemName = "Anti-Virus Data Pad";
	itemAction = "pick up";
	itemDescription = "Can be used to remove viruses on the bridge. Infinite use.";
	uses = NULL;
	bUsable = false;
}

void APickup_AntiVirusDataPad::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_AntiVirusDataPad::Use_Implementation()
{
	AExperimentalGameMode* GM = Cast<AExperimentalGameMode>(GetWorld()->GetAuthGameMode());
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	
	if (MyCharacter->bBridgeOverlap == true)
	{
		if (GM->bBridgeBroken == true)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You have wiped the viruses"));
			MyCharacter->ToggleInventory();
			MyCharacter->DecreaseSus();
			GM->AddStable();
			bUsable = true;
			GM->bBridgeBroken = false;
			return;
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("The bridge is already virus free"));
			bUsable = false;
		}
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("You can't use the anti-virus data pad here"));
		bUsable = false;
	}
}

void APickup_AntiVirusDataPad::Discard_Implementation()
{
	interactableMesh->SetVisibility(true);
	interactableMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}
