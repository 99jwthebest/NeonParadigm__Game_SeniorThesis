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

UENUM(BlueprintType)
enum class EDifficultySetting : uint8
{
    Easy UMETA(DisplayName = "Easy"),
    Medium UMETA(DisplayName = "Medium"),
    Hard UMETA(DisplayName = "Hard")
};

//DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSettingsChangedSignatureDynamic);
DECLARE_MULTICAST_DELEGATE(FOnSettingsChangedSignature);
//DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE(FOnSettingsChangedSignature, UNP_GameInstance, OnSettingsChanged);

//DECLARE_DYNAMIC_MULTICAST_DELEGATE()

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

    UFUNCTION(BlueprintCallable)
    void SetOptionEnumValue(int32 Value, EDifficultySetting Setting);
    UFUNCTION(BlueprintPure)
    EDifficultySetting GetOptionEnumValue(int32 Value);

    UFUNCTION(BlueprintPure)
    int32 GetCurrentDifficultyMode();


    //UPROPERTY(BlueprintAssignable, Category = "Settings")
    FOnSettingsChangedSignature OnSettingsChanged;

private:

    TMap<EGameSetting, bool> BooleanSettings;
    TMap<int32, EDifficultySetting> IntSettings;

    int CurrentDifficultyMode;

    UPROPERTY(BlueprintReadWrite, Category = Targeting, meta = (AllowPrivateAccess = "true"))
    bool bIsUsingGamepad = false;

};
