// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotifys/NP_AN_EndComboCollisions.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"
#include "NeonParadigm_Game/NeonParadigm_GameCharacter.h"
#include "NeonParadigm_Game/Components/DamageComponent.h"

void UNP_AN_EndComboCollisions::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	if (!MeshComp || !MeshComp->GetWorld()) // Ensure MeshComp and World are valid
		return;

	const AActor* OwnerActor = MeshComp->GetOwner();

	if (!OwnerActor || !OwnerActor->GetWorld()->IsGameWorld()) // Ensure it's a valid actor in a game world
		return;

	if (OwnerActor)
		CharacterMoveComp = Cast<ANeonParadigm_GameCharacter>(MeshComp->GetOwner());

	if (CharacterMoveComp)
		DamageComp = OwnerActor->GetComponentByClass<UDamageComponent>();

	if (DamageComp && CharacterMoveComp->IsRaging() == false)
		DamageComp->StartTimerEndComboWeaponCollision(Radius, AmountOfDamage, DamageTypeClass);
	else if (DamageComp && CharacterMoveComp->IsRaging())
		DamageComp->StartTimerEndComboWeaponCollision(Radius, AmountOfDamage * RageDamageMultiplier, DamageTypeClass);
}
