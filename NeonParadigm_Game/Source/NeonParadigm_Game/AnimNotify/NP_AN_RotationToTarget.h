// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "NP_AN_RotationToTarget.generated.h"

/**
 * 
 */
class ANeonParadigm_GameCharacter;

UCLASS()
class NEONPARADIGM_GAME_API UNP_AN_RotationToTarget : public UAnimNotify
{
	GENERATED_BODY()

public:

	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;

	ANeonParadigm_GameCharacter* CharacterMoveComp;

};
