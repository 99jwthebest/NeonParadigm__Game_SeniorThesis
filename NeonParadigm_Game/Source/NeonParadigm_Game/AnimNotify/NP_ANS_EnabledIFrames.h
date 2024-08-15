// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "NP_ANS_EnabledIFrames.generated.h"

/**
 * 
 */
class ANeonParadigm_GameCharacter;

UCLASS()
class NEONPARADIGM_GAME_API UNP_ANS_EnabledIFrames : public UAnimNotifyState
{
	GENERATED_BODY()

public:

	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference) override;
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;

	ANeonParadigm_GameCharacter* CharacterMoveComp;

};
