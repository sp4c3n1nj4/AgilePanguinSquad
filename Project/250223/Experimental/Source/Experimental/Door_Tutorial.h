// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door_Tutorial.generated.h"

UCLASS()
class EXPERIMENTAL_API ADoor_Tutorial : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor_Tutorial();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	int doorInt;
};