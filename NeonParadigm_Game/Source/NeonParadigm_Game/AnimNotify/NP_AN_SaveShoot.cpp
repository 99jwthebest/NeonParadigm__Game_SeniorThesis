// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonParadigm_Game/AnimNotify/NP_AN_SaveShoot.h"
#include "NeonParadigm_Game/NeonParadigm_GameCharacter.h"


void UNP_AN_SaveShoot::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	if (!MeshComp || !MeshComp->GetWorld()) // Ensure MeshComp and World are valid
		return;

	const AActor* OwnerActor = MeshComp->GetOwner();

	if (!OwnerActor || !OwnerActor->GetWorld()->IsGameWorld()) // Ensure it's a valid actor in a game world
		return;

	if (OwnerActor)
		PlayerCharacter = Cast<ANeonParadigm_GameCharacter>(MeshComp->GetOwner());

	if (PlayerCharacter)
		PlayerCharacter->SaveShoot();
	else
		UE_LOG(LogTemp, Warning, TEXT("Shoot Save NOT WORKIUNG!!!!"));


	/*UAttackComponent* AttackComp = OwnerActor->GetComponentByClass<UAttackComponent>();

	if (AttackComp == nullptr)
		return;

	UE_LOG(LogTemp, Warning, TEXT("INitializing ATTACK COMP IN SaveSHoot NOTIFY!!!!!!!!"));
	if (AttackComp)
		AttackComp->LaunchPlayerIntoAir();*/
	UE_LOG(LogTemp, Warning, TEXT("INside Notify for SaveShoot!!!!"));
}
