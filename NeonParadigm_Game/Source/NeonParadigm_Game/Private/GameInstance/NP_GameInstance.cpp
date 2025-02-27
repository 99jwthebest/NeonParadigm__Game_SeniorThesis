// Fill out your copyright notice in the Description page of Project Settings.


#include "GameInstance/NP_GameInstance.h"

void UNP_GameInstance::SetPlayerReady(bool bReady)
{
	bIsPlayerReady = bReady;
}

void UNP_GameInstance::SetPlayerHealth(float Health)
{
	PlayerHealth = Health;
}

void UNP_GameInstance::SetScore(int32 NewScore)
{
	Score = NewScore;
}
