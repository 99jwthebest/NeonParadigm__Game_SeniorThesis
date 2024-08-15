// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonParadigm_Game/AnimNotify/NP_AN_ResetState.h"
#include "NeonParadigm_Game/Enums/CharacterStateComponent.h"


void UNP_AN_ResetState::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	const AActor* OwnerActor = MeshComp->GetOwner();
	if(OwnerActor)
	CharacterStateComp = OwnerActor->GetComponentByClass<UCharacterStateComponent>();

	if(CharacterStateComp)
	CharacterStateComp->ResetState();
	else
		UE_LOG(LogTemp, Warning, TEXT("Cant FIND COMP In NOFITY!!!!!!!!"));


	UE_LOG(LogTemp, Warning, TEXT("RESETING STATE TRUCKER!!!!!!!!"));

}
