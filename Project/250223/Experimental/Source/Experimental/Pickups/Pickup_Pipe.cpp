// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup_Pipe.h"
#include "Kismet/GameplayStatics.h"
#include "../ExperimentalCharacter.h"
#include "../ExperimentalGameMode.h"

APickup_Pipe::APickup_Pipe()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	itemName = "Pipe";
	itemAction = "pick up";
	itemDescription = "Damages generators in the steering room. Infinite use.";
	uses = NULL;
	bUsable = false;
}

void APickup_Pipe::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_Pipe::Use_Implementation()
{
	AExperimentalGameMode* GM = Cast<AExperimentalGameMode>(GetWorld()->GetAuthGameMode());
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));

	if (MyCharacter->bSteeringOverlap == true)
	{
		if (GM->bSteeringBroken == false)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You damaged the steering room"));
			MyCharacter->ToggleInventory();
			MyCharacter->AddSus();
			GM->DecreaseStable();
			bUsable = true;
			GM->bSteeringBroken = true;
			return;
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("The steering room isn't damaged"));
			bUsable = false;
			return;
		}
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("You can't use the pipe here"));
		bUsable = false;
	}
}

void APickup_Pipe::Discard_Implementation()
{
	interactableMesh->SetVisibility(true);
	interactableMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}