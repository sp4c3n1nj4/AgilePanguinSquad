// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactable.h"

// Sets default values
AInteractable::AInteractable()
{
	/*Default text, will be overriden later*/
	interactableHelpText = FString("Press E to interact with item.");
}

// Called when the game starts or when spawned
void AInteractable::BeginPlay()
{
	Super::BeginPlay();
	
}

/*Interacting with the base class, if you see this you've made a mistake*/
void AInteractable::Interact_Implementation()
{
	GLog->Log("Interact base class: Interact() YOU SHOULD NOT BE SEEING THIS");
}
