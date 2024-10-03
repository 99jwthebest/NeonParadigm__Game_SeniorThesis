// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonParadigm_Game/AnimNotify/NP_AN_SoftTarget.h"
#include "NeonParadigm_Game/NeonParadigm_GameCharacter.h"


void UNP_AN_SoftTarget::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	const AActor* OwnerActor = MeshComp->GetOwner();

	if (!OwnerActor)
		return;
	
	ANeonParadigm_GameCharacter* CharacterMoveComp = Cast<ANeonParadigm_GameCharacter>(MeshComp->GetOwner());

	if (CharacterMoveComp)
	{
		CharacterMoveComp->SoftTarget();
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("Cant FIND SoftTarget COMP In NOFITY!!!!!!!!"));

}
