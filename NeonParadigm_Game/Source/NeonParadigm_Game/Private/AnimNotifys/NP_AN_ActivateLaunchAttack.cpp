// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotifys/NP_AN_ActivateLaunchAttack.h"
#include "NeonParadigm_Game/Components/AttackComponent.h"


void UNP_AN_ActivateLaunchAttack::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	if (!MeshComp || !MeshComp->GetWorld()) // Ensure MeshComp and World are valid
		return;

	const AActor* OwnerActor = MeshComp->GetOwner();

	if (!OwnerActor || !OwnerActor->GetWorld()->IsGameWorld()) // Ensure it's a valid actor in a game world
		return;

	UAttackComponent* AttackComp = OwnerActor->GetComponentByClass<UAttackComponent>();

	if (AttackComp == nullptr)
		return;

	UE_LOG(LogTemp, Warning, TEXT("INitializing ATTACK COMP IN AttackMovement NOTIFY!!!!!!!!"));

	if(AttackComp->GetSaveLaunchAttack())
		AttackComp->LaunchAttack();

}
