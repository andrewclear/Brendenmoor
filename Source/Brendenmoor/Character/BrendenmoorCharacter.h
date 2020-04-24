// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BlueprintWrappers/SkyBlueprintWrapper.h"
#include "BrendenmoorCharacter.generated.h"

UCLASS(config=Game)
class ABrendenmoorCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ABrendenmoorCharacter();

	UPROPERTY(BlueprintReadOnly, Category = "Spawners")
	ASkyBlueprintWrapper* SkyBlueprintWrapper;

};

