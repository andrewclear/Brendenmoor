
#include "ConversationController.h"
#include "UnrealOverrides/BrendenmoorGameInstance.h"
#include "EventSystem/GlobalEventSystem.h"

UConversationController::UConversationController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	m_ActiveConversation = nullptr;

	SubscribeToEvents();
}

UConversationController::~UConversationController()
{
	m_ActiveConversation = nullptr;

	UnsubscribeFromEvents();
}

void UConversationController::OnLevelLoaded(FName levelName)
{

}

void UConversationController::OnLevelUnloaded(FName levelName)
{

}

bool UConversationController::SubscribeToEvents()
{
	if (m_GameInstance != nullptr && m_GameInstance->GlobalEvents != nullptr)
	{
		m_GameInstance->GlobalEvents->OnLevelLoaded.AddDynamic(this, &UConversationController::OnLevelLoaded);
		m_GameInstance->GlobalEvents->OnLevelUnloaded.AddDynamic(this, &UConversationController::OnLevelUnloaded);

		return true;
	}

	return false;
}

bool UConversationController::UnsubscribeFromEvents()
{
	if (m_GameInstance != nullptr && m_GameInstance->GlobalEvents != nullptr)
	{
		m_GameInstance->GlobalEvents->OnLevelLoaded.RemoveAll(this);
		m_GameInstance->GlobalEvents->OnLevelUnloaded.RemoveAll(this);

		return true;
	}

	return false;
}