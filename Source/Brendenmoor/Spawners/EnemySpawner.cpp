// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/World.h"
#include "EnemySpawner.h"
#include "Engine.h"

void UEnemySpawner::Spawn()
{
	//SpawnObject(EnemyToSpawn);

	if (EnemyToSpawn)
	{
		FActorSpawnParameters SpawnParams;


		UWorld* world = GetOwner()->GetWorld();

		//Actual Spawn. The following function returns a reference to the spawned actor
		if (world == nullptr)
		{
			GEngine->AddOnScreenDebugMessage(-1, 30.0f, FColor::Green, "Spawn, GetWorld() is nullptr");
			return;
		}

		FVector2D spawnLocation = GetSpawnLocation();
		FTransform spawnTransform = FTransform(FVector(spawnLocation.X, spawnLocation.Y, GetComponentLocation().Z + 50));

		ABrendenmoorCharacter* ActorRef = world->SpawnActor<ABrendenmoorCharacter>(EnemyToSpawn, spawnTransform, SpawnParams);
		//AActor* SpawnedActor1 = world->SpawnActor(EnemyToSpawn, NAME_None, GetComponentLocation());


		if (ActorRef == nullptr)
		{
			GEngine->AddOnScreenDebugMessage(-1, 30.0f, FColor::Green, "Spawn, ActorRef is nullptr");
		}
		else
		{
			//FVector2D spawnLocation = GetSpawnLocation();
			//ActorRef->SetActorLocation(GetComponentLocation());
			//ActorRef->SetActorLocation(FVector(spawnLocation.X, spawnLocation.Y, GetComponentLocation().Z + 10));
		}
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 30.0f, FColor::Green, "Spawn, EnemyToSpawn is nullptr");
	}
}