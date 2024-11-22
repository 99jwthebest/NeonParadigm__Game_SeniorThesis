// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonParadigm_Game/AnimNotify/NP_AN_RageComplete.h"
#include "NeonParadigm_Game/NeonParadigm_GameCharacter.h"


void UNP_AN_RageComplete::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	if (MeshComp == nullptr)
		return;

	const AActor* OwnerActor = MeshComp->GetOwner();

	if (OwnerActor == nullptr)
		return;

	ANeonParadigm_GameCharacter* PlayerCharacter = Cast<ANeonParadigm_GameCharacter>(MeshComp->GetOwner());
	
	if (PlayerCharacter)
		PlayerCharacter->RageComplete();
	else
		UE_LOG(LogTemp, Warning, TEXT("Cant FIND Player IN Rage NOFITY!!!!!!!!"));
}
