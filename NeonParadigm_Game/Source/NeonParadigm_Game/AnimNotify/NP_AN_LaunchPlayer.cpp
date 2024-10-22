// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonParadigm_Game/AnimNotify/NP_AN_LaunchPlayer.h"
#include "NeonParadigm_Game/Components/AttackComponent.h"


void UNP_AN_LaunchPlayer::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	if (MeshComp == nullptr)
		return;

	const AActor* OwnerActor = MeshComp->GetOwner();


	if (!IsValid(OwnerActor))
		return;

	UAttackComponent* AttackComp = OwnerActor->GetComponentByClass<UAttackComponent>();

	if (AttackComp == nullptr)
		return;

	UE_LOG(LogTemp, Warning, TEXT("INitializing ATTACK COMP IN LaunchPLAYER NOTIFY!!!!!!!!"));
	if (AttackComp)
		AttackComp->LaunchPlayerIntoAir();
	UE_LOG(LogTemp, Warning, TEXT("INside Notify for LaunchPLAYER!!!!"));
}
