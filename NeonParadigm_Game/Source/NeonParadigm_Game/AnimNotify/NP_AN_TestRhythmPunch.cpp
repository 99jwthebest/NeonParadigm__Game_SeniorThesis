// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonParadigm_Game/AnimNotify/NP_AN_TestRhythmPunch.h"

void UNP_AN_TestRhythmPunch::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

    if (Animation && MeshComp->GetAnimInstance())
    {
        // Get the total animation length
        float TotalAnimationTime = Animation->GetPlayLength();

        // Get the current time within the animation sequence or montage
        float CurrentTime = 0.0f;

        // Check if this is a montage
        if (MeshComp->GetAnimInstance()->GetCurrentActiveMontage())
        {
            CurrentTime = MeshComp->GetAnimInstance()->Montage_GetPosition(MeshComp->GetAnimInstance()->GetCurrentActiveMontage());
            // Set the play rate of the currently active montage
            float NewPlayRate = 1.0f;  // This will double the speed of the montage
            MeshComp->GetAnimInstance()->Montage_SetPlayRate(MeshComp->GetAnimInstance()->GetCurrentActiveMontage(), NewPlayRate);
        }
        else
        {
            // For single animation sequences, it may be different depending on the setup
            // If you're working with animation sequences, this would need custom handling
        }

        UE_LOG(LogTemp, Error, TEXT("CD_Total Animation Play Rate:  %f"), MeshComp->GetAnimInstance()->Montage_GetPlayRate(MeshComp->GetAnimInstance()->GetCurrentActiveMontage()));
    }
}
