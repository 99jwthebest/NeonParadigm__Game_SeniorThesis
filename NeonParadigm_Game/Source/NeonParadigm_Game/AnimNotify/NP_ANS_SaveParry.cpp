// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonParadigm_Game/AnimNotify/NP_ANS_SaveParry.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "NeonParadigm_Game/NeonParadigm_GameCharacter.h"

void UNP_ANS_SaveParry::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);

	const AActor* OwnerActor = MeshComp->GetOwner();

	if (OwnerActor)
		CharacterMoveComp = Cast<ANeonParadigm_GameCharacter>(MeshComp->GetOwner());

}

void UNP_ANS_SaveParry::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyTick(MeshComp, Animation, FrameDeltaTime, EventReference);

	if (CharacterMoveComp)
		CharacterMoveComp->SaveParry();
	else
		UE_LOG(LogTemp, Warning, TEXT("Parry NOT WORKIUNG!!!!"));
}