// Copyright Epic Games, Inc. All Rights Reserved.

#include "NeonParadigm_GameGameMode.h"
#include "NeonParadigm_GameCharacter.h"
#include "UObject/ConstructorHelpers.h"

ANeonParadigm_GameGameMode::ANeonParadigm_GameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/_MyFiles/Blueprints/BP_Clair_NeonParadigm"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
