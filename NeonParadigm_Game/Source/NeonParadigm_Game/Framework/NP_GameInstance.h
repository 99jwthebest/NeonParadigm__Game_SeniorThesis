// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "NeonParadigm_Game/Framework/IAudio.h"
#include "NP_GameInstance.generated.h"

class UFMODAudioComponent;
class UFMODEvent;
class ANeonParadigm_GameCharacter;
class ATestActor;
class ANP_BaseEnemy;

/**
 * 
 */
UCLASS()
class NEONPARADIGM_GAME_API UNP_GameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	void InitAudioInterface(IAudio* Audio);

	IAudio* GetAudioInterface() const { return AudioInterface; }

	UFUNCTION(BlueprintCallable, Category = "Music")
	void AddSpawnedEnemy(ANP_BaseEnemy* SpawnedEnemy); // Can Move To Somewhere Else

	TArray<ANP_BaseEnemy*> GetSpawnedEnemies() const { return SpawnedEnemies; }

private:
	TArray<ANP_BaseEnemy*> SpawnedEnemies;

	class IAudio* AudioInterface;
};
