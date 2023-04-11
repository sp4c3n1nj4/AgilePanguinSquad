// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup_Wrench.h"
#include "Kismet/GameplayStatics.h"
#include "../ExperimentalCharacter.h"
#include "../ExperimentalGameMode.h"

APickup_Wrench::APickup_Wrench()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	itemName = "Wrench";
	itemAction = "pick up";
	itemDescription = "Used to fix either engine, and the steering room. Infinite use.";
	uses = NULL;
}

void APickup_Wrench::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_Wrench::Use_Implementation()
{
	AExperimentalGameMode* GM = Cast<AExperimentalGameMode>(GetWorld()->GetAuthGameMode());
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));

	if (MyCharacter->bEngineOverlap_0 == true)
	{
		if (GM->bEngineBroken_0 == true)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a wrench to fix engine 1"));
			MyCharacter->ToggleInventory();
			GM->AddStable();
			GM->bEngineBroken_0 = false;
			GM->EngineTimer_0();
			return;
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("£ngine 1 doesn't need fixing yet"));
			return;
		}
	}

	if (MyCharacter->bEngineOverlap_1 == true)
	{
		if (GM->bEngineBroken_1 == true)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a wrench to fix engine 2"));
			MyCharacter->ToggleInventory();
			GM->AddStable();
			GM->bEngineBroken_1 = false;
			GM->EngineTimer_1();
			return;
		}

		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Engine 2 doesn't need fixing yet"));
			return;
		}
	}

	if (MyCharacter->bSteeringOverlap == true)
	{
		if (GM->bSteeringBroken == true)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a wrench to fix steering"));
			MyCharacter->ToggleInventory();
			GM->AddStable();
			GM->bSteeringBroken = false;
			GM->SteeringTimer();
			return;
		}

		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Steering doesn't need fixing yet"));
			return;
		}
	}

	if (MyCharacter->bTutorial2Overlap == true)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a wrench for Tutorial Door 2"));
		MyCharacter->ToggleInventory();
		GM->bOpenTutorialDoor2 = true;
		return;
	}

	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("You can't use the wrench here"));
	}
}

void APickup_Wrench::Discard_Implementation()
{
	interactableMesh->SetVisibility(true);
	interactableMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}