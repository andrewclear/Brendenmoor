// Fill out your copyright notice in the Description page of Project Settings.


#include "Engine/World.h"
#include "Spawner.h"
#include "Engine.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
USpawner::USpawner()
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

void USpawner::Spawn()
{

}

FVector2D USpawner::GetSpawnLocation()
{
	float randX = FMath::FRandRange(SpawnRegionMin.X, SpawnRegionMax.X);
	float randY = FMath::FRandRange(SpawnRegionMin.Y, SpawnRegionMax.Y);

	return FVector2D(randX, randY);
}

void USpawner::SpawnObject(TSubclassOf<AActor> objectToSpawn)
{
	if (objectToSpawn)
	{
		FActorSpawnParameters SpawnParams;


		UWorld* world = GetOwner()->GetWorld();

		//Actual Spawn. The following function returns a reference to the spawned actor
		if (world == nullptr) 
		{
			GEngine->AddOnScreenDebugMessage(-1, 30.0f, FColor::Green, "SpawnObject, GetWorld() is nullptr");
			return;
		}
		
		AActor* ActorRef = world->SpawnActor<AActor>(objectToSpawn, GetComponentTransform(), SpawnParams);
		//AActor* SpawnedActor1 = world->SpawnActor(objectToSpawn, NAME_None, GetComponentLocation());
		//ActorRef->SetActorLocation(GetOwner()->GetActorLocation());
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 30.0f, FColor::Green, "SpawnObject, objectToSpawn is nullptr");
	}
}


