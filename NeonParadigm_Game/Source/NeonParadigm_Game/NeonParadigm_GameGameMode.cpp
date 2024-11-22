// Copyright Epic Games, Inc. All Rights Reserved.

#include "NeonParadigm_GameGameMode.h"
#include "NeonParadigm_GameCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "NeonParadigm_Game/NeonParadigm_GameCharacter.h"
#include "NeonParadigm_Game/Components/ScoreComponent.h"


ANeonParadigm_GameGameMode::ANeonParadigm_GameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/_MyFiles/Blueprints/BP_Player_NeonParadigm"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	ScoreComp = CreateDefaultSubobject<UScoreComponent>(TEXT("Score Component"));

}

void ANeonParadigm_GameGameMode::BeginPlay()
{
	Super::BeginPlay();

	// Your custom logic here
	UE_LOG(LogTemp, Error, TEXT("GameMode BeginPlay has been called"));

	PlayerCharacter = Cast<ANeonParadigm_GameCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	if (PlayerCharacter == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Couldn't Find PlayerCHaracter!!!!"));
		return;
	}


	if (ScoreComp)
	{
		ScoreComp->Testing();
	}



}
