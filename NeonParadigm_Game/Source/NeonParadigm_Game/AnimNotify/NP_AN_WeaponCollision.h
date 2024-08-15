// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "NP_AN_WeaponCollision.generated.h"

/**
 * 
 */

class UDamageComponent;
class ANeonParadigm_GameCharacter;
UCLASS()
class NEONPARADIGM_GAME_API UNP_AN_WeaponCollision : public UAnimNotify
{
	GENERATED_BODY()

public:

	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;


private:

	ANeonParadigm_GameCharacter* CharacterMoveComp;
	UDamageComponent* DamageComp;

	UPROPERTY(EditAnywhere, Category = "Damage")
	float End;
	UPROPERTY(EditAnywhere, Category = "Damage")
	float Radius;
	UPROPERTY(EditAnywhere, Category = "Damage")
	float AmountOfDamage;
	UPROPERTY(EditAnywhere, Category = "Damage")
	TSubclassOf<class UNP_DamageType> DamageTypeClass;
};
