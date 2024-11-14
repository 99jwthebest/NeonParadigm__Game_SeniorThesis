// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonParadigm_Game/Framework/NP_GameInstance.h"

void UNP_GameInstance::InitAudioInterface(IAudio* Audio)
{
	if (Audio == nullptr) return;

	AudioInterface = Audio;
}

void UNP_GameInstance::AddSpawnedEnemy(ANP_BaseEnemy* SpawnedEnemy)
{
    if (SpawnedEnemy)
    {
        // Add the spawned enemy to the array
        SpawnedEnemies.Add(SpawnedEnemy);

        // Log that the enemy has been added
        UE_LOG(LogTemp, Warning, TEXT("Enemy %s added to FMOD Music"), *SpawnedEnemy->GetName());

        UE_LOG(LogTemp, Warning, TEXT("Total Enemies Found: %d"), SpawnedEnemies.Num());

    }
}
