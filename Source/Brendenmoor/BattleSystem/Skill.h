// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Skill.generated.h"

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class ETargetType : uint8
{
	Single 						UMETA(DisplayName = "Single Target Attack"),
	AOEAroundTarget 			UMETA(DisplayName = "AOE Around Target"),
	AOEAroundAttacker			UMETA(DisplayName = "AOE Around Attacker"),
	AOEInFrontOfAttacker		UMETA(DisplayName = "AOE In Front Attacker")
};


UCLASS(Blueprintable)
class BRENDENMOOR_API USkill : public UObject
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	USkill();
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Skills")
	AActor* Attacker;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Skills")
	TArray<AActor*> Defenders;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Skills")
	AActor* Defender;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum)
	ETargetType TargetTypeEnum;

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "Execute"))
	void Execute();
	void Execute_Implementation() { };

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "Show Targeted Enemies"))
	void ShowTargetedEnemies();
	void ShowTargetedEnemies_Implementation() { }

};
