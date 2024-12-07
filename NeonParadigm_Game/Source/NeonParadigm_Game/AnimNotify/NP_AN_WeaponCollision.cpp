// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonParadigm_Game/AnimNotify/NP_AN_WeaponCollision.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"
#include "NeonParadigm_Game/NeonParadigm_GameCharacter.h"
#include "NeonParadigm_Game/Components/DamageComponent.h"


void UNP_AN_WeaponCollision::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
    Super::Notify(MeshComp, Animation, EventReference);

    if (!MeshComp || !MeshComp->GetWorld()) // Ensure MeshComp and World are valid
        return;

    const AActor* OwnerActor = MeshComp->GetOwner();

    if (!OwnerActor || !OwnerActor->GetWorld()->IsGameWorld()) // Ensure it's a valid actor in a game world
        return;

    CharacterMoveComp = Cast<ANeonParadigm_GameCharacter>(MeshComp->GetOwner());

    if (CharacterMoveComp)
        DamageComp = OwnerActor->FindComponentByClass<UDamageComponent>();

    if (!DamageComp)
        return;
        
    if (!CharacterMoveComp->IsRaging())
    {
        UE_LOG(LogTemp, Error, TEXT("A_TimelineBeat TIME Triggered: RhythmAttack In WC Notify Beat Tick: %f"), OwnerActor->GetWorld()->GetTimeSeconds());
        DamageComp->DrawWeaponCollision(End, Radius, AmountOfDamage, DamageTypeClass);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("A_TimelineBeat TIME Triggered: RhythmAttack Beat Tick: %f"), OwnerActor->GetWorld()->GetTimeSeconds());
        DamageComp->DrawWeaponCollision(End, Radius, AmountOfDamage * 10, DamageTypeClass); // Rage mode damage
    }
}
