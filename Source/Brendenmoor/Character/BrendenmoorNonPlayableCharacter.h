// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/BrendenmoorCharacter.h"
#include "Spawners/Spawner.h"
#include "BrendenmoorNonPlayableCharacter.generated.h"

/**
 * 
 */
UCLASS()
class BRENDENMOOR_API ABrendenmoorNonPlayableCharacter : public ABrendenmoorCharacter
{
	GENERATED_BODY()

	ASpawner*	spawnerReference;

public:
	ABrendenmoorNonPlayableCharacter();

	UFUNCTION(BlueprintCallable, Category = "Spawners")
	ASpawner* GetSpawner() const { return spawnerReference; }

	//UFUNCTION(BlueprintCallable, Category = "Spawners")
	void SetSpawner(ASpawner* spawner) { spawnerReference = spawner; }
};
