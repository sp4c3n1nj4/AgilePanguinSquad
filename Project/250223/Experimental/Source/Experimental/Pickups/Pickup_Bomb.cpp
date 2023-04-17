// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup_Bomb.h"
#include "Kismet/GameplayStatics.h"
#include "../ExperimentalCharacter.h"
#include "../ExperimentalGameMode.h"

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

	if (MyCharacter)
	
	if (MyCharacter->bTutorial3Overlap == true)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a bomb for tutorial door 3"));
		GM->bOpenTutorialDoor3 = true;
		UseAccepted();
		return;
	}
	if (MyCharacter->bAPSRDChargeOverlap == true)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a bomb for the APSRD's charging port"));
		GM->bAPSRDChargeBroken = true;
		UseAccepted();
		return;
	}
	if (MyCharacter->bC2M2ChargeOverlap == true)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a bomb for the C2-M2's charging port"));
		GM->bC2M2ChargeBroken = true;
		UseAccepted();
		return;
	}
	if (MyCharacter->bCaptainChargeOverlap == true)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a bomb for the Captains charging port"));
		GM->bCaptainChargeBroken = true;
		UseAccepted();
		return;
	}
	if (MyCharacter->bCarGOChargeOverlap == true)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a bomb for the CarGO's charging port"));
		GM->bCarGOChargeBroken = true;
		UseAccepted();
		return;
	}
	if (MyCharacter->bMIMAChargeOverlap == true)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a bomb for the MIMA's charging port"));
		GM->bMIMAChargeBroken = true;
		UseAccepted();
		return;
	}
	if (MyCharacter->bSOSChargeOverlap == true)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a bomb for the SOS's charging port"));
		GM->bSOSChargeBroken = true;
		UseAccepted();
		return;
	}
	if (MyCharacter->bSSRChargeOverlap == true)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a bomb for the SSR's charging port"));
		GM->bSSRChargeBroken = true;
		UseAccepted();
		return;
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("You can't use the bomb here"));
	}
}

void APickup_Bomb::UseAccepted()
{
	AExperimentalGameMode* GM = Cast<AExperimentalGameMode>(GetWorld()->GetAuthGameMode());
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	
	MyCharacter->ToggleInventory();
	GM->DecreaseStable();
	uses--;
	if (uses == 0)
	{
		Discard_Implementation();
		uses = 1;
	}
}

void APickup_Bomb::Discard_Implementation()
{
	interactableMesh->SetVisibility(true);
	interactableMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}