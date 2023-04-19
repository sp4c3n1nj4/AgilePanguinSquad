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
	itemName = "Bomb";
	itemAction = "pick up";
	itemDescription = "Destroys one charging port. 1x use.";
	bUsable = false;
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
		MyCharacter->ToggleInventory();
		bUsable = true;
		GM->bOpenTutorialDoor3 = true;
		return;
	}
	if (MyCharacter->bAPSRDChargeOverlap == true)
	{
		if (GM->bAPSRDChargeBroken == false)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a bomb for the APSRD's charging port"));
			GM->bAPSRDChargeBroken = true;
			UseAccepted();
			return;
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("The APSRD's charging port is already broken"));
			bUsable = false;
			return;
		}

	}
	if (MyCharacter->bC2M2ChargeOverlap == true)
	{
		if (GM->bC2M2ChargeBroken == false)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a bomb for the C2-M2's charging port"));
			GM->bC2M2ChargeBroken = true;
			UseAccepted();
			return;
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("The C2-M2's charging port is already broken"));
			bUsable = false;
			return;
		}
	}
	if (MyCharacter->bCaptainChargeOverlap == true)
	{
		if (GM->bCaptainChargeBroken == false)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a bomb for the Captains charging port"));
			GM->bCaptainChargeBroken = true;
			UseAccepted();
			return;
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("The Captains charging port is already broken"));
			bUsable = false;
			return;
		}
	}
	if (MyCharacter->bCarGOChargeOverlap == true)
	{
		if (GM->bCarGOChargeBroken == false)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a bomb for the CarGO's charging port"));
			GM->bCarGOChargeBroken = true;
			UseAccepted();
			return;
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("The CarGO's charging port is already broken"));
			bUsable = false;
			return;
		}
	}
	if (MyCharacter->bMIMAChargeOverlap == true)
	{
		if (GM->bMIMAChargeBroken == false)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a bomb for the MIMA's charging port"));
			GM->bMIMAChargeBroken = true;
			UseAccepted();
			return;
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("The MIMA's charging port is already broken"));
			bUsable = false;
			return;
		}
	}
	if (MyCharacter->bSOSChargeOverlap == true)
	{
		if (GM->bSOSChargeBroken == false)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a bomb for the SOS' charging port"));
			GM->bSOSChargeBroken = true;
			UseAccepted();
			return;
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("The SOS' charging port is already broken"));
			bUsable = false;
			return;
		}
	}
	if (MyCharacter->bSSRChargeOverlap == true)
	{
		if (GM->bSSRChargeBroken == false)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a bomb for the SSR's charging port"));
			GM->bSSRChargeBroken = true;
			UseAccepted();
			return;
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("The SSR's charging port is already broken"));
			bUsable = false;
			return;
		}
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("You can't use the bomb here"));
		bUsable = false;
	}
}

void APickup_Bomb::UseAccepted()
{
	AExperimentalGameMode* GM = Cast<AExperimentalGameMode>(GetWorld()->GetAuthGameMode());
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	
	MyCharacter->ToggleInventory();
	GM->DecreaseStable();
	bUsable = true;
}

void APickup_Bomb::Discard_Implementation()
{
	interactableMesh->SetVisibility(true);
	interactableMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

void APickup_Bomb::Reset_Uses()
{
	uses = 1;
}