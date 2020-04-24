// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemySpawner.h"
#include "Character/BrendenmoorNonPlayableCharacter.h"
#include "Engine/World.h"
#include "Engine.h"

void AEnemySpawner::Spawn()
{
	AActor* spawnedEnemy = nullptr;
	ABrendenmoorNonPlayableCharacter* spawnedNPC = nullptr;

	for (int i = 0; i < SpawnerData[0].EnemiesToSpawn.Num(); i++)
	{
		if (SpawnerData[0].EnemiesToSpawn[i])
		{
			spawnedEnemy = SpawnObject(SpawnerData[0].EnemiesToSpawn[i]);
			spawnedNPC = Cast<ABrendenmoorNonPlayableCharacter>(spawnedEnemy);

			if (spawnedNPC != nullptr)
			{
				spawnedNPC->SetSpawner(this);
				spawnedNPC->SkyBlueprintWrapper = SkyBlueprintWrapper;
			}
		}
	}
}