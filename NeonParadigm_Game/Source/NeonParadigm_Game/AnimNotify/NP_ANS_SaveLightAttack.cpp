// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonParadigm_Game/AnimNotify/NP_ANS_SaveLightAttack.h"
#include "NeonParadigm_Game/Components/AttackComponent.h"



void UNP_ANS_SaveLightAttack::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);
}

void UNP_ANS_SaveLightAttack::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyTick(MeshComp, Animation, FrameDeltaTime, EventReference);

	if (MeshComp == nullptr)
		return;

	const AActor* OwnerActor = MeshComp->GetOwner();


	if (!IsValid(OwnerActor))
		return;
		
	UAttackComponent* AttackComp = OwnerActor->GetComponentByClass<UAttackComponent>();

	if (AttackComp == nullptr)
		return;

	UE_LOG(LogTemp, Warning, TEXT("INitializing CHARACTER IN NOTIFY!!!!!!!!"));
	if(AttackComp)
		AttackComp->SaveLightAttack();
	UE_LOG(LogTemp, Warning, TEXT("INside NotifyTickFor SAVELIGHTATTACK!!!!"));
}

