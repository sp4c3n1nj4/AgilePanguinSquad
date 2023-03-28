// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup_VirusDataPad.h"
#include "Kismet/GameplayStatics.h"
#include "../ExperimentalCharacter.h"
#include "../ExperimentalGameMode.h"

APickup_VirusDataPad::APickup_VirusDataPad()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	itemName = "Virus Data Pad";
	itemAction = "pick up";
	itemDescription = "Infect viruses on the bridge, or DOSS. Infinite use.";
	uses = NULL;
}

void APickup_VirusDataPad::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_VirusDataPad::Use_Implementation()
{
	AExperimentalGameMode* GM = Cast<AExperimentalGameMode>(GetWorld()->GetAuthGameMode());
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	FTimerHandle delayHandle;

	if (MyCharacter->bBridgeOverlap == true)
	{
		if (GM->bBridgeBroken == false)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You have infected the bridge with viruses"));
			MyCharacter->ToggleInventory();
			GM->DecreaseStable();
			GM->bBridgeBroken = true;
			return;
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("The bridge is already infected with viruses"));
		}
	}

	if (MyCharacter->bDOSSOverlap == true)
	{
		if (GM->bDOSSBroken == false)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You infected DOSS with viruses for 1 minute"));
			MyCharacter->ToggleInventory();
			GM->DecreaseStable();
			GM->bDOSSBroken = true;
			GetWorldTimerManager().SetTimer(delayHandle, this, &APickup_VirusDataPad::DOSSReboot, 60.f, false);
			return;
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("DOSS is already infected with viruses"));
			return;
		}
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("You can't use the virus data pad here"));
	}
}

void APickup_VirusDataPad::Discard_Implementation()
{
	interactableMesh->SetVisibility(true);
	interactableMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

void APickup_VirusDataPad::DOSSReboot()
{
	AExperimentalGameMode* GM = Cast<AExperimentalGameMode>(GetWorld()->GetAuthGameMode());

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("DOSS has rebooted"));
	GM->AddStable();
	GM->bDOSSBroken = false;
}