// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "NP_ANS_SaveDodge.generated.h"

/**
 * 
 */
class ANeonParadigm_GameCharacter;

UCLASS()
class NEONPARADIGM_GAME_API UNP_ANS_SaveDodge : public UAnimNotifyState
{
	GENERATED_BODY()

public:

	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference) override;
	virtual void NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime, const FAnimNotifyEventReference& EventReference) override;


public:
	ANeonParadigm_GameCharacter* CharacterMoveComp;


};
