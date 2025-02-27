// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "NP_GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class UNP_GameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
    // Variables to store across level transitions
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bIsPlayerReady;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float PlayerHealth;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 Score;

    // Functions to update values
    UFUNCTION(BlueprintCallable)
    void SetPlayerReady(bool bReady);

    UFUNCTION(BlueprintCallable)
    void SetPlayerHealth(float Health);

    UFUNCTION(BlueprintCallable)
    void SetScore(int32 NewScore);
};
