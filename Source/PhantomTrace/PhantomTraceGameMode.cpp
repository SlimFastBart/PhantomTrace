// Copyright Epic Games, Inc. All Rights Reserved.

#include "PhantomTraceGameMode.h"
#include "PhantomTraceCharacter.h"
#include "UObject/ConstructorHelpers.h"

APhantomTraceGameMode::APhantomTraceGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
