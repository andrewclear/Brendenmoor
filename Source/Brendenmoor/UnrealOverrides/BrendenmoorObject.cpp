#include "BrendenmoorObject.h"
#include "Engine.h"

UBrendenmoorObject::UBrendenmoorObject(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	if (GEngine != nullptr && GEngine->GetWorld() != nullptr)
	{
		m_GameInstance = Cast<UBrendenmoorGameInstance>(GEngine->GetWorld()->GetGameInstance());
	}
}

UBrendenmoorObject::~UBrendenmoorObject()
{
	m_GameInstance = nullptr;
}