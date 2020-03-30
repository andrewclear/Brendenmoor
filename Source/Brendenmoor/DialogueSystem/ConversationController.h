#pragma once

#include "UnrealOverrides/BrendenmoorObject.h"
#include "EventSystem/GlobalEventSubscriber.h"
#include "ConversationController.generated.h"

class UConversation;

USTRUCT(BlueprintType)
struct FConversationsContainer
{
	GENERATED_BODY()

	TArray<UConversation*>			m_Conversations;
};

UCLASS()
class BRENDENMOOR_API UConversationController : public UBrendenmoorObject, public IGlobalEventSubscriber
{
	GENERATED_BODY()

	TMap<FName, FConversationsContainer>		m_Conversations;

	UConversation*								m_ActiveConversation;

	void OnLevelLoaded(FName levelName);
	void OnLevelUnloaded(FName levelName);

public:
	UConversationController(const FObjectInitializer& ObjectInitializer);
	~UConversationController();

	bool SubscribeToEvents();
	bool UnsubscribeFromEvents();
};