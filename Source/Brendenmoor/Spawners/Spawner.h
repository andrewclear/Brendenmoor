// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/Vector2D.h"
#include "Spawner.generated.h"

UCLASS(Blueprintable, ClassGroup="Spawners", meta=(BlueprintSpawnableComponent))
class BRENDENMOOR_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawner();

protected:
	// Called when the game starts or when spawned
	//virtual void BeginPlay() override;

	FVector GetSpawnLocation();

	AActor* SpawnObject(TSubclassOf<AActor> objectToSpawn);
public:	
	UFUNCTION(BlueprintCallable, Category ="Spawners"                                                                                                                                                   )
	virtual void Spawn();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spawners")
	FVector SpawnAreaExtent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spawners")
	float NavAreaRadius;
};
