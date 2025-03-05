// Fill out your copyright notice in the Description page of Project Settings.


#include "GameInstance/NP_GameInstance.h"


void UNP_GameInstance::Init()
{
    BooleanSettings.Add(EGameSetting::AutoTargetCamera, true);
    BooleanSettings.Add(EGameSetting::InvertedXAxis, false);
    BooleanSettings.Add(EGameSetting::InvertedYAxis, false);
    BooleanSettings.Add(EGameSetting::DifficultyMode, false);
}

void UNP_GameInstance::SetOptionBooleanValue(EGameSetting Setting, bool Value)
{
    BooleanSettings.Add(Setting, Value);
    OnSettingsChanged.Broadcast(); // Notify listeners
    UE_LOG(LogTemp, Warning, TEXT("DUE, BT Work Delegate Because I'm ancy grancy in GAME INSTANCE!!!!"));

}

bool UNP_GameInstance::GetOptionBooleanValue(EGameSetting Setting)
{
    if (BooleanSettings.Contains(Setting))
    {
        return BooleanSettings[Setting];
    }
    return false; // Default value if key is not found
}

