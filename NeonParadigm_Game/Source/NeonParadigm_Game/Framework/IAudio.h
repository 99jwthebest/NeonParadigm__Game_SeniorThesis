// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IAudio.generated.h"

/**
 * 
 */
UINTERFACE(MinimalAPI)
class UAudio : public UInterface
{
	GENERATED_BODY()
};

class NEONPARADIGM_GAME_API IAudio
{
	GENERATED_BODY()

public:
	virtual float GetCurrentTempDelay() = 0;
	virtual float GetNextBeatTime() = 0;
	virtual float GetThirdBeatTime() = 0;

};
