// Fill out your copyright notice in the Description page of Project Settings.


#include "SkyBlueprintWrapper.h"

// Sets default values
ASkyBlueprintWrapper::ASkyBlueprintWrapper()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ASkyBlueprintWrapper::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASkyBlueprintWrapper::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float ASkyBlueprintWrapper::GetTimeOfDay_Implementation()
{ 
	return 0.0f; 
}

