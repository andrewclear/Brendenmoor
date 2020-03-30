#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BrendenmoorGameInstance.h"
#include "BrendenmoorActorComponent.generated.h"

UCLASS()
class BRENDENMOOR_API UBrendenmoorActorComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UBrendenmoorGameInstance* m_GameInstance;

public:
	UBrendenmoorActorComponent(const FObjectInitializer& ObjectInitializer);
	~UBrendenmoorActorComponent();

	void BeginPlay();
};

