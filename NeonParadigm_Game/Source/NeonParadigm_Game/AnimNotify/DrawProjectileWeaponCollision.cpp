// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonParadigm_Game/AnimNotify/DrawProjectileWeaponCollision.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"
#include "NeonParadigm_Game/NeonParadigm_GameCharacter.h"
#include "NeonParadigm_Game/Components/DamageComponent.h"

void UDrawProjectileWeaponCollision::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	if (MeshComp == nullptr)
		return;

	const AActor* OwnerActor = MeshComp->GetOwner();

	if (OwnerActor)
		CharacterMoveComp = Cast<ANeonParadigm_GameCharacter>(MeshComp->GetOwner());

	if (CharacterMoveComp)
		DamageComp = OwnerActor->GetComponentByClass<UDamageComponent>();

	if (DamageComp && CharacterMoveComp->IsRaging() == false)
		DamageComp->StartTimerProjectileWeaponCollision(Radius, AmountOfDamage, DamageTypeClass);
	else if (DamageComp && CharacterMoveComp->IsRaging())
		DamageComp->StartTimerProjectileWeaponCollision(Radius, AmountOfDamage * RageDamageMultiplier, DamageTypeClass);
}
