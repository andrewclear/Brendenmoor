// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Spawners/Spawner.h"
#include "Character/BrendenmoorCharacter.h"
#include "EnemySpawner.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, ClassGroup = "Spawners", meta = (BlueprintSpawnableComponent))
class BRENDENMOOR_API UEnemySpawner : public USpawner
{
	GENERATED_BODY()
	
public:

	/*Blueprint Reference of UsefulActor class*/
	UPROPERTY(BlueprintReadWrite, Category = "Actor Spawning")
	TSubclassOf<ABrendenmoorCharacter> EnemyToSpawn;

	//UFUNCTION(BlueprintCallable, Category ="Spawners", meta = (DisplayName = "Spawn Enemy"))
	virtual void Spawn() override;

};
