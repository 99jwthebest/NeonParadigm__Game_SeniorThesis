// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonParadigm_Game/AnimNotify/NP_AN_ChangeCameraFOV.h"
#include "NeonParadigm_Game/NeonParadigm_GameCharacter.h"

void UNP_AN_ChangeCameraFOV::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	if (MeshComp == nullptr)
		return;

	const AActor* OwnerActor = MeshComp->GetOwner();

	if (OwnerActor == nullptr)
		return;

	ANeonParadigm_GameCharacter* PlayerCharacter = Cast<ANeonParadigm_GameCharacter>(MeshComp->GetOwner());

	if (PlayerCharacter)
		PlayerCharacter->TimerCameraFOV(TargetCameraFOV, TargetCameraFOVSpeedChange);
	else
		UE_LOG(LogTemp, Warning, TEXT("Cant FIND Player IN FOV NOFITY!!!!!!!!"));
}
