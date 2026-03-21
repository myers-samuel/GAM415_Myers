// Copyright Epic Games, Inc. All Rights Reserved.

#include "myersfirstperson415GameMode.h"
#include "myersfirstperson415Character.h"
#include "UObject/ConstructorHelpers.h"

Amyersfirstperson415GameMode::Amyersfirstperson415GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
