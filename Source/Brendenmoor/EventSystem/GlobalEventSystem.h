// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GlobalEventSystem.generated.h"

class USkill;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEvent_OnCutsceneStarted);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEvent_OnQueueBattleCommand, USkill*, battleCommand);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEvent_OnLevelLoaded, FName, levelName);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEvent_OnLevelUnloaded, FName, levelName);

/**
 * 
 */
UCLASS()
class BRENDENMOOR_API UGlobalEventSystem : public UObject
{
	GENERATED_BODY()

public:
	UGlobalEventSystem() {}
	~UGlobalEventSystem() {}

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Global Event System")
		FEvent_OnCutsceneStarted OnCutsceneStarted;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Global Event System")
		FEvent_OnLevelLoaded OnLevelLoaded;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Global Event System")
		FEvent_OnLevelUnloaded OnLevelUnloaded;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Global Event System")
		FEvent_OnQueueBattleCommand OnQueueBattleCommand;
};
