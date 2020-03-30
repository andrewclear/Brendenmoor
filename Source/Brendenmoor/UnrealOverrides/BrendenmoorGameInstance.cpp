#include "BrendenmoorGameInstance.h"
#include "BattleSystem/BattleCommandProcessor.h"
#include "DialogueSystem/ConversationController.h"
#include "EventSystem/GlobalEventSystem.h"

UBrendenmoorGameInstance::UBrendenmoorGameInstance(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	GlobalEvents = NewObject<UGlobalEventSystem>(UGlobalEventSystem::StaticClass());

	m_BattleCommandProcessor = NewObject<UBattleCommandProcessor>(UBattleCommandProcessor::StaticClass());
	m_ConversationController = NewObject<UConversationController>(UConversationController::StaticClass());
}