// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonParadigm_Game/AnimNotify/NP_ANS_AllowRotationOnRootMotion.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"
#include "NeonParadigm_Game/NeonParadigm_GameCharacter.h"


void UNP_ANS_AllowRotationOnRootMotion::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);

	if (MeshComp == nullptr)
		return;

	const AActor* OwnerActor = MeshComp->GetOwner();

	if (OwnerActor)
		CharacterMoveComp = Cast<ANeonParadigm_GameCharacter>(MeshComp->GetOwner());

	if (CharacterMoveComp)
	{
		if (!CharacterMoveComp->GetIsTargeting() && !IsValid(CharacterMoveComp->GetSoftTargetActor()))
		{
			CharacterMoveComp->GetCharacterMovement()->bAllowPhysicsRotationDuringAnimRootMotion = true;
			UE_LOG(LogTemp, Error, TEXT("DO WE KNOW MOTHER FUKCERJDLSKFJSDLKFJ AllowRotation COMP In NOFITY!!!!!!!!"));
		}
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("Cant FIND AllowRotation COMP In NOFITY!!!!!!!!"));

}

void UNP_ANS_AllowRotationOnRootMotion::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);

	if (MeshComp == nullptr)
		return;

	const AActor* OwnerActor = MeshComp->GetOwner();

	if (OwnerActor)
		CharacterMoveComp = Cast<ANeonParadigm_GameCharacter>(MeshComp->GetOwner());

	if (CharacterMoveComp)
		CharacterMoveComp->GetCharacterMovement()->bAllowPhysicsRotationDuringAnimRootMotion = false;
	else
		UE_LOG(LogTemp, Warning, TEXT("Cant FIND AllowRotation COMP In NOFITY!!!!!!!!"));
}
