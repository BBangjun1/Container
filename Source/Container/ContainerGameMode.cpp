// Copyright Epic Games, Inc. All Rights Reserved.

#include "ContainerGameMode.h"
#include "ContainerCharacter.h"
#include "UObject/ConstructorHelpers.h"

AContainerGameMode::AContainerGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
