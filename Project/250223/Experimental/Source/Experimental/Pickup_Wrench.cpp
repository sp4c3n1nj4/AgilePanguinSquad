// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup_Wrench.h"
#include "Kismet/GameplayStatics.h"
#include "ExperimentalCharacter.h"
#include "ExperimentalGameMode.h"

APickup_Wrench::APickup_Wrench()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	itemName = "Wrench";
	itemAction = "pick up";
	itemDescription = "This is a wrench";
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
	FTimerHandle TimerHandle;
	
	if (MyCharacter->bEngineOverlap_0 == true)
	{
		if (GM->bEngineBroken_0 == true)
		{
			GM->alertText = "You used a wrench to fix engine 1";
			GM->bAlertGreen = true;
			if (MyCharacter->bAlertText == false)
			{
				MyCharacter->bAlertText = true;
				GetWorld()->GetTimerManager().SetTimer(TimerHandle, MyCharacter, &AExperimentalCharacter::RemoveAlertText, 3.0f, false);
			}
			interactableMesh->SetVisibility(true);
			interactableMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
			MyCharacter->ToggleInventory();
			MyCharacter->DeleteItemAtInventorySlot(MyCharacter->usedSlot);
			GM->stableNum = GM->stableNum + 20;
			GM->bEngineBroken_0 = false;
			GM->EngineTimer_0();
			return;
		}
		else
		{
			GM->alertText = "Engine 1 doesn't need fixing yet";
			GM->bAlertGreen = false;
			MyCharacter->usedSlot = NULL;
			MyCharacter->ToggleInventory();
			if (MyCharacter->bAlertText == false)
			{
				MyCharacter->bAlertText = true;
				GetWorld()->GetTimerManager().SetTimer(TimerHandle, MyCharacter, &AExperimentalCharacter::RemoveAlertText, 3.0f, false);
			}
			return;
		}
	}
	if (MyCharacter->bEngineOverlap_1 == true)
	{
		if (GM->bEngineBroken_1 == true)
		{
			GM->alertText = "You used a wrench to fix engine 2";
			GM->bAlertGreen = true;
			if (MyCharacter->bAlertText == false)
			{
				MyCharacter->bAlertText = true;
				GetWorld()->GetTimerManager().SetTimer(TimerHandle, MyCharacter, &AExperimentalCharacter::RemoveAlertText, 3.0f, false);
			}
			interactableMesh->SetVisibility(true);
			interactableMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
			MyCharacter->ToggleInventory();
			MyCharacter->DeleteItemAtInventorySlot(MyCharacter->usedSlot);
			GM->stableNum = GM->stableNum + 20;
			GM->bEngineBroken_1 = false;
			GM->EngineTimer_1();
			return;
		}
		else
		{
			GM->alertText = "Engine 2 doesn't need fixing yet";
			GM->bAlertGreen = false;
			MyCharacter->usedSlot = NULL;
			MyCharacter->ToggleInventory();
			if (MyCharacter->bAlertText == false)
			{
				MyCharacter->bAlertText = true;
				GetWorld()->GetTimerManager().SetTimer(TimerHandle, MyCharacter, &AExperimentalCharacter::RemoveAlertText, 3.0f, false);
			}
			return;
		}
	}
	else
	{
		GM->alertText = "You cannot use the wrench here";
		GM->bAlertGreen = false;
		MyCharacter->usedSlot = NULL;
		MyCharacter->ToggleInventory();
		if (MyCharacter->bAlertText == false)
		{
			MyCharacter->bAlertText = true;
			GetWorld()->GetTimerManager().SetTimer(TimerHandle, MyCharacter, &AExperimentalCharacter::RemoveAlertText, 3.0f, false);
		}
	}
}