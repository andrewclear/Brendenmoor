#pragma once

#include "CoreMinimal.h"
#include "BrendenmoorGameInstance.h"
#include "BrendenmoorObject.generated.h"

UCLASS()
class BRENDENMOOR_API UBrendenmoorObject : public UObject
{
	GENERATED_BODY()

protected:
	UBrendenmoorGameInstance* m_GameInstance;

public:
	UBrendenmoorObject(const FObjectInitializer& ObjectInitializer);
	~UBrendenmoorObject();
};

