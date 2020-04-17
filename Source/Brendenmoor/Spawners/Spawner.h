// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Math/Vector2D.h"
#include "Spawner.generated.h"

UCLASS(Blueprintable, ClassGroup="Spawners", meta=(BlueprintSpawnableComponent))
class BRENDENMOOR_API USpawner : public USceneComponent
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	USpawner();

protected:
	// Called when the game starts or when spawned
	//virtual void BeginPlay() override;

	FVector2D GetSpawnLocation();

	void SpawnObject(TSubclassOf<AActor> objectToSpawn);
public:	
	UFUNCTION(BlueprintCallable, Category ="Spawners", meta=(DisplayName = "Spawner"))
	virtual void Spawn();

	UPROPERTY(BlueprintReadWrite, Category = "Spawners")
	FVector2D SpawnRegionMin;

	UPROPERTY(BlueprintReadWrite, Category = "Spawners")
	FVector2D SpawnRegionMax;
};
