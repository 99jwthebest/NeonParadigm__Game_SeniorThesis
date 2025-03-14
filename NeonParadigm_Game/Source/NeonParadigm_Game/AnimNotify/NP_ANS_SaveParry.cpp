// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonParadigm_Game/AnimNotify/NP_ANS_SaveParry.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "NeonParadigm_Game/NeonParadigm_GameCharacter.h"

void UNP_ANS_SaveParry::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);

	if (!MeshComp || !MeshComp->GetWorld()) // Ensure MeshComp and World are valid
		return;

	const AActor* OwnerActor = MeshComp->GetOwner();

	if (!OwnerActor || !OwnerActor->GetWorld()->IsGameWorld()) // Ensure it's a valid actor in a game world
		return;

	if (OwnerActor)
		CharacterMoveComp = Cast<ANeonParadigm_GameCharacter>(MeshComp->GetOwner());

}

void UNP_ANS_SaveParry::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyTick(MeshComp, Animation, FrameDeltaTime, EventReference);

	if (!MeshComp || !MeshComp->GetWorld()) // Ensure MeshComp and World are valid
		return;

	const AActor* OwnerActor = MeshComp->GetOwner();

	if (!OwnerActor || !OwnerActor->GetWorld()->IsGameWorld()) // Ensure it's a valid actor in a game world
		return;

	if (CharacterMoveComp)
		CharacterMoveComp->SaveParry();
	else
		UE_LOG(LogTemp, Warning, TEXT("Parry NOT WORKIUNG!!!!"));
}