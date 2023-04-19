// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Particles/ParticleSystem.h"
#include "Interactable.generated.h"

UCLASS()
class EXPERIMENTAL_API AInteractable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractable();

	/*Assuming all interactables have help text*/
	UPROPERTY(EditAnywhere, Category = "Interact Properties")
	FString interactableHelpText;

	UFUNCTION(BlueprintNativeEvent) /*Allows this function to be overriden whilst keeping the implementation*/
	void Interact(); /*Will be used in blueprint*/
	virtual void Interact_Implementation(); /*Reacts to blueprint, does nothing*/

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;	

	/*Assuming all interactables have a mesh*/
	UPROPERTY(EditAnywhere, Category = "Interact Properties")
	class UStaticMeshComponent* interactableMesh;

	/*Assuming all interactables have a mesh*/
	UPROPERTY(EditAnywhere, Category = "Interact Properties")
	class UParticleSystem* interactableVFX;
};