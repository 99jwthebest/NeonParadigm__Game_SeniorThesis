// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonParadigm_Game/AnimNotify/NP_AN_RotationToTarget.h"
#include "NeonParadigm_Game/NeonParadigm_GameCharacter.h"

void UNP_AN_RotationToTarget::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	if (MeshComp == nullptr)
		return;

	const AActor* OwnerActor = MeshComp->GetOwner();

	if (OwnerActor)
		CharacterMoveComp = Cast<ANeonParadigm_GameCharacter>(MeshComp->GetOwner());

	if (CharacterMoveComp)
		CharacterMoveComp->RotateToTarget();
	else
		UE_LOG(LogTemp, Warning, TEXT("Cant FIND Rotation ToTarget COMP In NOFITY!!!!!!!!"));
}
