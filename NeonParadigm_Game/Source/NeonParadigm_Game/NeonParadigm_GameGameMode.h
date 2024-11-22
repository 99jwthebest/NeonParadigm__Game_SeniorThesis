// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NeonParadigm_GameGameMode.generated.h"

class ANeonParadigm_GameCharacter;
class UScoreComponent;

UCLASS(minimalapi)
class ANeonParadigm_GameGameMode : public AGameModeBase
{
	GENERATED_BODY()


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Attack, meta = (AllowPrivateAccess = "true"))
	UScoreComponent* ScoreComp;

public:
	ANeonParadigm_GameGameMode();


protected:
	// Override BeginPlay function
	virtual void BeginPlay() override;


private:

	ANeonParadigm_GameCharacter* PlayerCharacter;

};



