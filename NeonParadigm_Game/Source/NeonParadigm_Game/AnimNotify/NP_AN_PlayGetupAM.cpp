// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonParadigm_Game/AnimNotify/NP_AN_PlayGetupAM.h"
#include "NeonParadigm_Game/Enemies/NP_BaseEnemy.h"


void UNP_AN_PlayGetupAM::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	if (!MeshComp || !MeshComp->GetWorld()) // Ensure MeshComp and World are valid
		return;

	const AActor* OwnerActor = MeshComp->GetOwner();

	if (!OwnerActor || !OwnerActor->GetWorld()->IsGameWorld()) // Ensure it's a valid actor in a game world
		return;

	ANP_BaseEnemy* EnemyCharacter = Cast<ANP_BaseEnemy>(MeshComp->GetOwner());

	if (IsValid(EnemyCharacter))
	{
		EnemyCharacter->PlayAnimMontage(EnemyCharacter->GetGetupAnimMontage());
		UE_LOG(LogTemp, Warning, TEXT("IS THIS BEING CASLLED STUPIDD AHHHHHHHHH  In NOFITY!!!!!!!!"));

	}
	else
		UE_LOG(LogTemp, Warning, TEXT("Cant FIND AllowRotation COMP In NOFITY!!!!!!!!"));


	UE_LOG(LogTemp, Warning, TEXT("RESETING STATE TRUCKER!!!!!!!!"));
}
