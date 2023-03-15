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
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a wrench to fix engine 1"));
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
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Engine 1 doesn't need fixing yet"));
			MyCharacter->usedSlot = NULL;
			return;
		}
	}
	if (MyCharacter->bEngineOverlap_1 == true)
	{
		if (GM->bEngineBroken_1 == true)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used a wrench to fix engine 2"));
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
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Engine 2 doesn't need fixing yet"));
			MyCharacter->usedSlot = NULL;
			return;
		}
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("You cannot use the wrench here"));
		MyCharacter->usedSlot = NULL;
	}
}