// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonParadigm_Game/AnimNotify/NP_AN_SpawnObject.h"
#include "NP_AN_SpawnObject.h"
#include "GameFramework/Actor.h"

void UNP_AN_SpawnObject::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	if (!IsValid(MeshComp)) return;

	Super::Notify(MeshComp, Animation, EventReference);

	if (!IsValid(ObjectClass)) return;

	AActor* Owner = MeshComp->GetOwner();
	if (!IsValid(Owner)) return;

	FVector Location = Owner->GetActorLocation();
	FVector SpawnLocation = Location + SpawnPoint;

	FRotator Rotation = Owner->GetActorRotation();

	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = Owner;

	AActor* SpawnedObject = Owner->GetWorld()->SpawnActor<AActor>(ObjectClass, SpawnLocation, Rotation, SpawnParams);
	if (!IsValid(SpawnedObject)) return;

}
