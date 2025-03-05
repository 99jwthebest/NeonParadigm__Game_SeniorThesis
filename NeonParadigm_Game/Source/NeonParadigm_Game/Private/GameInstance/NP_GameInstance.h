// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "NP_GameInstance.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EGameSetting : uint8
{
    AutoTargetCamera UMETA(DisplayName = "Auto Target Camera"),
    InvertedXAxis UMETA(DisplayName = "Inverted X Axis"),
    InvertedYAxis UMETA(DisplayName = "Inverted Y Axis"),
    DifficultyMode UMETA(DisplayName = "Difficulty Mode")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSettingsChanged);


UCLASS()
class UNP_GameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

    virtual void Init() override;

    UFUNCTION(BlueprintCallable)
    void SetOptionBooleanValue(EGameSetting Setting, bool Value);
    UFUNCTION(BlueprintPure)
    bool GetOptionBooleanValue(EGameSetting Setting);

    UPROPERTY(BlueprintAssignable, Category = "Settings")
    FOnSettingsChanged OnSettingsChanged;

private:

    TMap<EGameSetting, bool> BooleanSettings;

    
};
