// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SkyBlueprintWrapper.generated.h"

UCLASS()
class BRENDENMOOR_API ASkyBlueprintWrapper : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASkyBlueprintWrapper();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spawners")
	AActor* SkyBlueprintReference;

protected:
	float	m_TimeOfDay = 0.0f;


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Time Management")
	void SetTimeOfDay(float time) { m_TimeOfDay = time; }

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Time Management")
	float GetTimeOfDay();
	virtual float GetTimeOfDay_Implementation();

};
