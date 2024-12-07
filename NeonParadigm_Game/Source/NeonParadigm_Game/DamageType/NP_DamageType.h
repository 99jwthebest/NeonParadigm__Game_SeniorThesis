// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DamageType.h"
#include "NP_DamageType.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EDamageTypes : uint8
{
	Default, //UMETA(DisplayName = "Option 1"),
	Right, //UMETA(DisplayName = "Option 2"),
	Left, //UMETA(DisplayName = "Option 3"),
	Middle, //UMETA(DisplayName = "Option 4"),
	Knockdown, //UMETA(DisplayName = "Option 5"),
	Knockback, //UMETA(DisplayName = "Option 5"),
	Launch, //UMETA(DisplayName = "Option 5"),
	Stun, //UMETA(DisplayName = "Option 5"),
	Projectiles, //UMETA(DisplayName = "Option 5"),
	Explosion, //UMETA(DisplayName = "Option 5"),
};

UCLASS()
class NEONPARADIGM_GAME_API UNP_DamageType : public UDamageType
{
	GENERATED_BODY()
	

public:
	EDamageTypes GetDamageType();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = DamageType)
	EDamageTypes DamageType;
private:

};
