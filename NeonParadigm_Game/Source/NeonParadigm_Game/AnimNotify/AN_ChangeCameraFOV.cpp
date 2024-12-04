// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonParadigm_Game/AnimNotify/AN_ChangeCameraFOV.h"
#include "NeonParadigm_Game/NeonParadigm_GameCharacter.h"

void UAN_ChangeCameraFOV::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	if (MeshComp == nullptr)
		return;

	const AActor* OwnerActor = MeshComp->GetOwner();

	if (OwnerActor == nullptr)
		return;

	ANeonParadigm_GameCharacter* PlayerCharacter = Cast<ANeonParadigm_GameCharacter>(MeshComp->GetOwner());

	if (PlayerCharacter)
		PlayerCharacter->TimerCameraFOV(TargetCameraFOV, CameraFOVSpeedChange);
	else
		UE_LOG(LogTemp, Warning, TEXT("Cant FIND Player IN Rage NOFITY!!!!!!!!"));
}
