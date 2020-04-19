// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemySpawner.h"
#include "Character/BrendenmoorNonPlayableCharacter.h"
#include "Engine/World.h"
#include "Engine.h"

void AEnemySpawner::Spawn()
{
	AActor* spawnedEnemy = SpawnObject(EnemyToSpawn);

	if (spawnedEnemy != nullptr) {
		ABrendenmoorNonPlayableCharacter* enemyNPC = Cast< ABrendenmoorNonPlayableCharacter>(spawnedEnemy);

		if (enemyNPC != nullptr) {
			enemyNPC->SetSpawner(this);
		}
	}
}