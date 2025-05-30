// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "NP_AN_EndComboCollisions.generated.h"

/**
 * 
 */
class UDamageComponent;
class ANeonParadigm_GameCharacter;
UCLASS()
class UNP_AN_EndComboCollisions : public UAnimNotify
{
	GENERATED_BODY()

public:

	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;


private:

	ANeonParadigm_GameCharacter* CharacterMoveComp;
	UDamageComponent* DamageComp;


	UPROPERTY(EditAnywhere, Category = "Damage")
	float Radius;
	UPROPERTY(EditAnywhere, Category = "Damage")
	float AmountOfDamage;
	UPROPERTY(EditAnywhere, Category = "Damage")
	TSubclassOf<class UNP_DamageType> DamageTypeClass;
	UPROPERTY(EditAnywhere, Category = "Damage")
	float RageDamageMultiplier;
};
