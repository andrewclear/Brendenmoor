#include "BattleCommandProcessor.h"
#include "EventSystem/GlobalEventSystem.h"
#include "Skill.h"

UBattleCommandProcessor::UBattleCommandProcessor(const FObjectInitializer& ObjectInitializer) 
	: Super(ObjectInitializer)
{
	SubscribeToEvents();
}

void UBattleCommandProcessor::OnQueueBattleCommand(USkill* battleCommand)
{
	if (battleCommand != nullptr)
	{
		battleCommand->Execute();
	}
}

bool UBattleCommandProcessor::SubscribeToEvents()
{
	if (m_GameInstance != nullptr && m_GameInstance->GlobalEvents != nullptr)
	{
		m_GameInstance->GlobalEvents->OnQueueBattleCommand.AddDynamic(this, &UBattleCommandProcessor::OnQueueBattleCommand);

		return true;
	}

	return false;
}

bool UBattleCommandProcessor::UnsubscribeFromEvents()
{
	if (m_GameInstance != nullptr && m_GameInstance->GlobalEvents != nullptr)
	{
		m_GameInstance->GlobalEvents->OnQueueBattleCommand.RemoveAll(this);

		return true;
	}

	return false;
}
