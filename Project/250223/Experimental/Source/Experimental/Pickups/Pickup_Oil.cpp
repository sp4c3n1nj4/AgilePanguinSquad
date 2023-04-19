// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup_Oil.h"
#include "Kismet/GameplayStatics.h"
#include "../ExperimentalCharacter.h"
#include "../ExperimentalGameMode.h"

APickup_Oil::APickup_Oil()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	uses = 3;
	itemName = "Oil";
	itemAction = "pick up";
	itemDescription = "Oil can be used to damage either engine. 3x use.";
	bUsable = false;
}

void APickup_Oil::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_Oil::Use_Implementation()
{
	AExperimentalGameMode* GM = Cast<AExperimentalGameMode>(GetWorld()->GetAuthGameMode());
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));

	if (MyCharacter->bEngineOverlap_0 == true)
	{
		if (GM->bEngineBroken_0 == false)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You broke Engine 1"));
			UseAccepted();
			GM->bEngineBroken_0 = true;
			return;
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Engine 1 is already broken"));
			bUsable = false;
			return;
		}
	}

	if (MyCharacter->bEngineOverlap_1 == true)
	{
		if (GM->bEngineBroken_1 == false)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You Broke Engine 2"));
			UseAccepted();
			GM->bEngineBroken_1 = true;
			return;
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Engine 2 is already broken"));
			bUsable = false;
			return;
		}
	}

	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("You can't use oil here"));
		bUsable = false;
	}
}

void APickup_Oil::UseAccepted()
{
	AExperimentalGameMode* GM = Cast<AExperimentalGameMode>(GetWorld()->GetAuthGameMode());
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));

	MyCharacter->ToggleInventory();
	GM->DecreaseStable();
	bUsable = true;
}

void APickup_Oil::Discard_Implementation()
{
	interactableMesh->SetVisibility(true);
	interactableMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

void APickup_Oil::Reset_Uses()
{
	uses = 3;
}