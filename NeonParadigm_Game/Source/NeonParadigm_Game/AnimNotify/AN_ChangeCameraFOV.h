// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AN_ChangeCameraFOV.generated.h"

/**
 * 
 */
class ANeonParadigm_GameCharacter;
UCLASS()
class NEONPARADIGM_GAME_API UAN_ChangeCameraFOV : public UAnimNotify
{
	GENERATED_BODY()

public:
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
	float TargetCameraFOV;
	//FTimerHandle TimerForFOVChange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
	float CameraFOVSpeedChange;

};
