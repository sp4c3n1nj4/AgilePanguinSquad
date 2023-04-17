// Fill out your copyright notice in the Description page of Project Settings.

#include "ChargingPort.h"

// Sets default values
AChargingPort::AChargingPort()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));

}

// Called when the game starts or when spawned
void AChargingPort::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AChargingPort::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}