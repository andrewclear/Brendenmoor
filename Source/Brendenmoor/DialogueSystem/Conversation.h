#pragma once

#include "CoreMinimal.h"
#include "UnrealOverrides/BrendenmoorObject.h"
#include "Conversation.generated.h"

USTRUCT(BlueprintType)
struct FSequence
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FDialogueSequence : public FSequence
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = DialogueSystem, meta = (DisplayName = "Name of Character Speaking"))
		FName CharacterName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = DialogueSystem, meta = (DisplayName = "The Lines of Dialogue"))
		TArray<FText> Dialogue;
};

USTRUCT(BlueprintType)
struct FEventSequence : public FSequence
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = DialogueSystem, meta = (DisplayName = "The Event to Send"))
		FName EventToSend;
};

UCLASS(BlueprintType)
class BRENDENMOOR_API UConversation : public UBrendenmoorObject
{
	GENERATED_BODY()

	TArray<FName>		m_RequiredCharacters;
	TArray<FName>		m_RequiredStates;
	TArray<FSequence>	m_Sequences;


	FSequence*			m_CurrentSequence;
	bool				m_HasAlreadyBeenShown;
	bool				m_Repeatable;

public:
	UConversation(const FObjectInitializer& ObjectInitializer);
	~UConversation();

};
