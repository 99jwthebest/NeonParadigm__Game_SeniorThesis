// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonParadigm_Game/AnimNotify/NP_AN_EnemyResetState.h"
#include "NeonParadigm_Game/Enemies/NP_BaseEnemy.h"


void UNP_AN_EnemyResetState::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	const AActor* OwnerActor = MeshComp->GetOwner();

	if (OwnerActor)
		EnemyCharacter = Cast<ANP_BaseEnemy>(MeshComp->GetOwner());

	if (EnemyCharacter)
		EnemyCharacter->ResetState();
	else
		UE_LOG(LogTemp, Warning, TEXT("Cant FIND AllowRotation COMP In NOFITY!!!!!!!!"));


	UE_LOG(LogTemp, Warning, TEXT("RESETING STATE TRUCKER!!!!!!!!"));
}
