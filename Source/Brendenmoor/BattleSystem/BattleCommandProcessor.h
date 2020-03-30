#pragma once

#include "CoreMinimal.h"
#include "UnrealOverrides/BrendenmoorObject.h"
#include "EventSystem/GlobalEventSubscriber.h"
#include "BattleCommandProcessor.generated.h"

class USkill;

/**
 *
 */
UCLASS()
class BRENDENMOOR_API UBattleCommandProcessor : public UBrendenmoorObject, public IGlobalEventSubscriber
{
	GENERATED_BODY()

	void OnQueueBattleCommand(USkill* battleCommand);

public:
	UBattleCommandProcessor(const FObjectInitializer& ObjectInitializer);
	~UBattleCommandProcessor() {}

	bool SubscribeToEvents();
	bool UnsubscribeFromEvents();
};