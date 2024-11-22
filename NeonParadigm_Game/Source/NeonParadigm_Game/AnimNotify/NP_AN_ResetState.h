// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "NP_AN_ResetState.generated.h"

/**
 * 
 */

class ANeonParadigm_GameCharacter;
UCLASS()
class NEONPARADIGM_GAME_API UNP_AN_ResetState : public UAnimNotify
{
	GENERATED_BODY()
	
public:
	UNP_AN_ResetState();
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;

};
