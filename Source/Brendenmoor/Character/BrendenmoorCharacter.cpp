// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "BrendenmoorCharacter.h"
#include "Components/CapsuleComponent.h"


//////////////////////////////////////////////////////////////////////////
// ABrendenmoorCharacter

ABrendenmoorCharacter::ABrendenmoorCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
}