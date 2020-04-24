// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Spawners/Spawner.h"
#include "Character/BrendenmoorCharacter.h"
#include "EnemySpawner.generated.h"

USTRUCT(BlueprintType, Blueprintable)
struct FEnemySpawnerData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Enemy Spawner Data")
	TArray<TSubclassOf<ABrendenmoorCharacter>> EnemiesToSpawn;
};

UCLASS(Blueprintable, ClassGroup = "Spawners", meta = (BlueprintSpawnableComponent))
class BRENDENMOOR_API AEnemySpawner : public ASpawner
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spawners")
	TArray<FEnemySpawnerData> SpawnerData;

	virtual void Spawn() override;

};
