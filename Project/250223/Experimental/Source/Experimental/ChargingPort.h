// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "ChargingPort.generated.h"

UCLASS()
class EXPERIMENTAL_API AChargingPort : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChargingPort();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	UBoxComponent* BoxCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables")
	bool AIOverlap;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
