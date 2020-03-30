#pragma once
#include "CoreMinimal.h"

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EAttributes : uint8
{
	Strength 		UMETA(DisplayName = "Strength"),
	Agility 		UMETA(DisplayName = "Agility"),
	MaxHealth		UMETA(DisplayName = "Max Health"),
	CurrentHealth	UMETA(DisplayName = "Current Health"),
};
