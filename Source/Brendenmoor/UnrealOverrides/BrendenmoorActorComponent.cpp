#include "BrendenmoorActorComponent.h"
#include "Engine.h"

UBrendenmoorActorComponent::UBrendenmoorActorComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	
}

UBrendenmoorActorComponent::~UBrendenmoorActorComponent()
{
	m_GameInstance = nullptr;
}

void UBrendenmoorActorComponent::BeginPlay()
{
	Super::BeginPlay();
		
	m_GameInstance = Cast<UBrendenmoorGameInstance>(GetOwner()->GetGameInstance());
	
}