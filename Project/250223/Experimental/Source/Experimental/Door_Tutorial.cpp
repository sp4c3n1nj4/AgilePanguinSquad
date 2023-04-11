// Fill out your copyright notice in the Description page of Project Settings.


#include "Door_Tutorial.h"

// Sets default values
ADoor_Tutorial::ADoor_Tutorial()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bDoorOpen = false;
	doorInt = 1;
}