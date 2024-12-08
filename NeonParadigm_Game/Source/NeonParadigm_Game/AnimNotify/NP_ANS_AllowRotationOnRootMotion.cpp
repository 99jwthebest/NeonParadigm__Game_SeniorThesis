// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonParadigm_Game/AnimNotify/NP_ANS_AllowRotationOnRootMotion.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"
#include "NeonParadigm_Game/NeonParadigm_GameCharacter.h"


void UNP_ANS_AllowRotationOnRootMotion::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
    Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);

    if (!MeshComp || !MeshComp->GetWorld()) // Ensure MeshComp and World are valid
        return;

    const AActor* OwnerActor = MeshComp->GetOwner();

    if (!OwnerActor || !OwnerActor->GetWorld()->IsGameWorld()) // Ensure it's a valid actor in a game world
        return;

    CharacterMoveComp = Cast<ANeonParadigm_GameCharacter>(MeshComp->GetOwner());

    if (CharacterMoveComp)
    {
        if (!CharacterMoveComp->GetIsTargeting() && !IsValid(CharacterMoveComp->GetSoftTargetActor()))
        {
            CharacterMoveComp->GetCharacterMovement()->bAllowPhysicsRotationDuringAnimRootMotion = true;
            UE_LOG(LogTemp, Error, TEXT("AllowRotation COMP enabled in NOTIFY Begin!"));
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Cannot find CharacterMoveComp in NOTIFY Begin!"));
    }

}

void UNP_ANS_AllowRotationOnRootMotion::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
    Super::NotifyEnd(MeshComp, Animation, EventReference);

    if (!MeshComp || !MeshComp->GetWorld()) // Ensure MeshComp and World are valid
        return;

    const AActor* OwnerActor = MeshComp->GetOwner();

    if (!OwnerActor || !OwnerActor->GetWorld()->IsGameWorld()) // Ensure it's a valid actor in a game world
        return;

    CharacterMoveComp = Cast<ANeonParadigm_GameCharacter>(MeshComp->GetOwner());

    if (CharacterMoveComp)
    {
        CharacterMoveComp->GetCharacterMovement()->bAllowPhysicsRotationDuringAnimRootMotion = false;
        UE_LOG(LogTemp, Error, TEXT("AllowRotation COMP disabled in NOTIFY End!"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Cannot find CharacterMoveComp in NOTIFY End!"));
    }
}
