// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "NP_AN_TestRhythmPunch.generated.h"

/**
 * 
 */
UCLASS()
class NEONPARADIGM_GAME_API UNP_AN_TestRhythmPunch : public UAnimNotify
{
	GENERATED_BODY()

public:

	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;

private:
	//UPROPERTY()
	//class UCharacterStateComponent* CharacterStateComp;
};
