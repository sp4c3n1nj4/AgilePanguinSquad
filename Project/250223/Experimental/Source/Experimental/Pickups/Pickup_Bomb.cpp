// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup_Bomb.h"
#include "Kismet/GameplayStatics.h"
#include "../ExperimentalCharacter.h"

APickup_Bomb::APickup_Bomb()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	uses = 1;
	itemName = FString::Printf(TEXT("Bomb (x%d)"), uses);
	itemAction = "pick up";
	itemDescription = "Destroys one charging port. 1x use.";
}

void APickup_Bomb::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_Bomb::Use_Implementation()
{
	AExperimentalGameMode* GM = Cast<AExperimentalGameMode>(GetWorld()->GetAuthGameMode());
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));

	if (MyCharacter->bTutorial3Overlap == true)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a bomb for tutorial door 3"));
		MyCharacter->ToggleInventory();
		GM->bOpenTutorialDoor2 = true;
		return;
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("You can't use the bomb here"));
	}
}

void APickup_Bomb::Discard_Implementation()
{
	interactableMesh->SetVisibility(true);
	interactableMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}