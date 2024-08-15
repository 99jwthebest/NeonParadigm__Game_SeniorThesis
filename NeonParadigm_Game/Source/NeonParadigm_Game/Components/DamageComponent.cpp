// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonParadigm_Game/Components/DamageComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "NeonParadigm_Game/NeonParadigm_GameCharacter.h"
#include "Kismet/KismetArrayLibrary.h"
#include "NeonParadigm_Game/Enums/CharacterStateComponent.h"
#include "Animation/AnimMontage.h"



// Sets default values for this component's properties
UDamageComponent::UDamageComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDamageComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
	MyCharacter = Cast<ANeonParadigm_GameCharacter>(GetOwner());
	CharacterState = MyCharacter->FindComponentByClass<UCharacterStateComponent>();
	if (CharacterState != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Found CharacterState Compo!!!!!"))
	}


}


// Called every frame
void UDamageComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UDamageComponent::DrawWeaponCollision(float End, float Radius, float AmountOfDamage, TSubclassOf<UNP_DamageType> DamageTypeClass)
{
	HitActors.Empty();

	// For Sphere Trace
	FVector MultipliedVec = MyCharacter->GetActorForwardVector() * End;
	FVector EndVec = MultipliedVec + MyCharacter->GetActorLocation();

	// Actors to ignore
    TArray<AActor*> ActorsToIgnore;
    ActorsToIgnore.Add(MyCharacter); 
	// Object types to trace for
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Pawn)); 
	// Add more ObjectTypes if needed
	// Array to hold the hit results
	TArray<FHitResult> OutHits;

	bool bMultiSphereHit = UKismetSystemLibrary::SphereTraceMultiForObjects(
		GetWorld(), 
		MyCharacter->GetActorLocation(), 
		EndVec, 
		Radius, 
		ObjectTypes, 
		false, 
		ActorsToIgnore, 
		EDrawDebugTrace::ForDuration, 
		OutHits, 
		true);

	if (bMultiSphereHit)
	{
		for (FHitResult& Hit : OutHits)
		{
			// Handle each hit result here
			UE_LOG(LogTemp, Log, TEXT("Hit actor: %s"), *Hit.GetActor()->GetName());
			if (!HitActors.Contains(Hit.GetActor()) && Hit.GetActor()->IsValidLowLevel())
			{
				float Damage = UGameplayStatics::ApplyDamage(Hit.GetActor(), AmountOfDamage, MyCharacter->GetController(), MyCharacter, DamageTypeClass);
				HitActors.AddUnique(Hit.GetActor());
				UE_LOG(LogTemp, Log, TEXT("Is this Firing??!?!!?! %f"), Damage);

			}
		}
	}
}

//void UDamageComponent::HandleTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
//{
//	// Step 1: Create or obtain an instance of UNP_DamageType
//	UNP_DamageType* MyDamageType = NewObject<UNP_DamageType>(GetWorld());
//	UE_LOG(LogTemp, Warning, TEXT("Actor %s took %f damage"), *DamagedActor->GetName(), Damage);
//
//	MyCharacter->CurrentHealth -= Damage;
//
//	if (MyCharacter->CurrentHealth > 0.0f)
//	{
//		// Step 2: Ensure the instance is valid
//		if (MyDamageType)
//		{
//			if (IsValid(GetHitReactionMontage(MyDamageType->GetDamageType())))
//			{
//				CharacterState->SetState(ECharacterStates::Disabled);
//				MyCharacter->PlayAnimMontage(GetHitReactionMontage(MyDamageType->GetDamageType()));
//			}
//
//			// You can now use the value of Damage as needed
//			//UE_LOG(LogTemp, Log, TEXT("Damage Type: %f"), Damage);
//		}
//	}
//	else
//	{
//		PerformDeath();
//	}
//	
//}

UAnimMontage* UDamageComponent::GetHitReactionMontage(EDamageTypes DamageType)
{
	switch (DamageType)
	{
		case EDamageTypes::Default:
			return HR_Knockback; 

		case EDamageTypes::Right:
			return HR_Right; 

		case EDamageTypes::Left:
			return HR_Left; 

		case EDamageTypes::Middle:
			return HR_Middle; 

		case EDamageTypes::Knockdown:
			return HR_Knockdown; 

		case EDamageTypes::Knockback:
			return HR_Knockback; 
	}
	return HR_Knockback;
}

//void UDamageComponent::PerformDeath()
//{
//	CharacterState->SetState(ECharacterStates::Death);
//	MyCharacter->PlayAnimMontage(DeathMontage);
//	MyCharacter->GetController()->DisableInput(UGameplayStatics::GetPlayerController(GetWorld(), 0));
//}

