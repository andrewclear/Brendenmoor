// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Globals/GlobalEnums.h"
#include "StatusEffect.generated.h"
/**
 * 
 */
UCLASS()
class BRENDENMOOR_API UStatusEffect : public UObject
{
	GENERATED_BODY()

public:
	UStatusEffect();
	~UStatusEffect();

	///////////////////////////////////////
	// FUNCTIONS
	//////////////////////////////////////
	void Clone(UStatusEffect *otherStatusEffect);

	UFUNCTION(BlueprintCallable, Category = StatusEffect, meta = (DisplayName = "Start Applying the Status Effect on the Character"))
		void Start();

	/////////////////////////////////////
	// PROPERTIES
	/////////////////////////////////////
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = StatusEffect, meta = (DisplayName = "Status Effect Name"))
		FName Name = "Effect Name";

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = StatusEffect, meta = (DisplayName = "Status Effect Icon"))
		FName Icon = "Needs Implemented";

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = StatusEffect, meta = (DisplayNAme = "Status Effect Duration"))
		float Duration = 0.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = StatusEffect, meta = (DisplayName = "Does Status Effect Expire On Death"))
		float ExpiresOnDeath = false;

	UPROPERTY(EditAnywhere, Category = StatusEffect, meta = (DisplayName = "Attributes Affected by the Status Effect"))
		TMap<EAttributes, int32> StatsAfffected;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = StatusEffect, meta = (DisplayName = "Apply Status Effect Each Tick"))
		bool ApplyPerTick = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = StatusEffect, meta = (DisplayName = "Status Effect Tick Duration"))
		float TickLength = 0.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = StatusEffect, meta = (DisplayName = "Effect Strength Randomly Varies Per Tick"))
		bool RandomVariationPerTick = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = StatusEffect, meta = (DisplayName = "Effect Strength Varies by a Constant Amount Per Tick"))
		float VariationAmount = 0.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = StatusEffect, meta = (DisplayName = "Status Effect Particle Effect"))
		FName ParticleEffect = "Needs Implemented";

private:
	FTimerHandle m_TimerHandle;

	void OnTick();
};
