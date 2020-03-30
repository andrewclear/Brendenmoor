#pragma once

//Essential Include
#include "Engine/GameInstance.h"
#include "BrendenmoorGameInstance.generated.h"

class UBattleCommandProcessor;
class UGlobalEventSystem;
class UConversationController;

UCLASS()
class BRENDENMOOR_API UBrendenmoorGameInstance : public UGameInstance
{
	GENERATED_BODY()

	UBattleCommandProcessor*		m_BattleCommandProcessor;
	UConversationController*		m_ConversationController;

public:
	UBrendenmoorGameInstance(const FObjectInitializer& ObjectInitializer);

	UGlobalEventSystem* GlobalEvents;

};