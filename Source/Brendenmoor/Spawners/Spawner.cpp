// Fill out your copyright notice in the Description page of Project Settings.

#include "Spawner.h"
#include "Engine/World.h"
#include "Engine.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
ASpawner::ASpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

}


// Called when the game starts or when spawned
//void USpawner::BeginPlay()
//{
//	Super::BeginPlay();
	
//}


/*
// Called every frame
void USpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
*/

void ASpawner::Spawn()
{

}

FVector ASpawner::GetSpawnLocation()
{
	FVector center = GetActorLocation();
	float randX = FMath::FRandRange(center.X - SpawnAreaExtent.X, center.X + SpawnAreaExtent.X);
	float randY = FMath::FRandRange(center.Y - SpawnAreaExtent.Y, center.Y + SpawnAreaExtent.Y);
	float randZ = FMath::FRandRange(center.Z - SpawnAreaExtent.Z, center.Z + SpawnAreaExtent.Z);

	return FVector(randX, randY, randZ);
}

AActor* ASpawner::SpawnObject(TSubclassOf<AActor> objectToSpawn)
{
	AActor* actorRef = nullptr;

	if (objectToSpawn)
	{
		FActorSpawnParameters SpawnParams;

		UWorld* world = GetWorld();

		//Actual Spawn. The following function returns a reference to the spawned actor
		if (world == nullptr)
		{
			GEngine->AddOnScreenDebugMessage(-1, 30.0f, FColor::Green, "Spawn, GetWorld() is nullptr");
			return nullptr;
		}

		bool wasSuccessful = false;

		do
		{
			FVector spawnLocation = GetSpawnLocation();
			FRotator rotator;

			actorRef = world->SpawnActor(objectToSpawn, &spawnLocation, &rotator);

			if (actorRef == nullptr)
			{
				GEngine->AddOnScreenDebugMessage(-1, 30.0f, FColor::Red, "Spawn, ActorRef is nullptr");
			}
			else
			{
				wasSuccessful = true;
				GEngine->AddOnScreenDebugMessage(-1, 30.0f, FColor::Green, "Spawn successful");
			}

		} while (wasSuccessful == false);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 30.0f, FColor::Red, "Spawn, EnemyToSpawn is nullptr");
	}

	return actorRef;
}

