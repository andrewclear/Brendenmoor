// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UnrealOverrides/BrendenmoorActorComponent.h"
#include "BattleSystemComponent.generated.h"

class USkill;
class UStatusEffect;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BRENDENMOOR_API UBattleSystemComponent : public UBrendenmoorActorComponent
{
	GENERATED_BODY()

	USkill*					m_AutoAttackSkill;
	USkill*					m_ActiveSkill;
	USkill*					m_QueuedSkill;

	TArray<UStatusEffect*>	m_ActiveStatusEffects;

public:	
	// Sets default values for this component's properties
	UBattleSystemComponent(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintCallable, Category = "Battle System Component", meta = (DisplayName = "Activate Skill"))
	void ActivateSkill(UObject* skillToActivate);
	//void ActivateSkill(USkill* skillToActivate);

	UFUNCTION(BlueprintCallable, Category = "Battle System Component", meta = (DisplayName = "Apply the Status Effect to the Character"))
	void ApplyStatusEffect(UStatusEffect* statusEffect);
	
	void SetAutoAttackSkill(USkill* autoAttackSkill);

	void TestLoad();
};
