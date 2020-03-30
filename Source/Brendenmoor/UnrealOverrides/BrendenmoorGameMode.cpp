// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "UnrealOverrides/BrendenmoorGameMode.h"
#include "Character/BrendenmoorCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABrendenmoorGameMode::ABrendenmoorGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ParagonShinbi/Characters/Heroes/Shinbi/ShinbiPlayerCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
