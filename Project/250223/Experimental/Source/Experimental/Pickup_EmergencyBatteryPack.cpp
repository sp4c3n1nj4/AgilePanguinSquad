// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup_EmergencyBatteryPack.h"
#include "Kismet/GameplayStatics.h"
#include "ExperimentalCharacter.h"

APickup_EmergencyBatteryPack::APickup_EmergencyBatteryPack()
{
	/*Default values,
	best to set the thumbnail, & mesh in the editor*/
	itemName = "Emergency Battery Pack";
	itemAction = "pick up";
	itemDescription = "This is an emergency battery pack";
}

void APickup_EmergencyBatteryPack::BeginPlay()
{
	Super::BeginPlay();
}

/*When item is used*/
void APickup_EmergencyBatteryPack::Use_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("You used an emergency battery pack: Use_Implementation() IT'S COOL IF YOU'RE SEEING THIS"));
	AExperimentalCharacter* MyCharacter = Cast<AExperimentalCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	MyCharacter->ToggleInventory();
}