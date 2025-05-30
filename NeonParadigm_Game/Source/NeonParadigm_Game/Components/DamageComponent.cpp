// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonParadigm_Game/Components/DamageComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "NeonParadigm_Game/NeonParadigm_GameCharacter.h"
#include "Kismet/KismetArrayLibrary.h"
#include "NeonParadigm_Game/Enums/CharacterStateComponent.h"
#include "Animation/AnimMontage.h"
#include "NeonParadigm_Game/Components/ScoreComponent.h"
#include "TimerManager.h"
#include "Kismet/KismetSystemLibrary.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "GameInstance/NP_GameInstance.h"
#include "NeonParadigm_Game/Enemies/NP_BaseEnemy.h"

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

	ScoreComp = MyCharacter->FindComponentByClass<UScoreComponent>();
	if (ScoreComp != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Found SCORE Compo!!!!!"))
	}
	GameInstance = Cast<UNP_GameInstance>(MyCharacter->GetGameInstance());

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
	/*TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Pawn)); */
	// Add more ObjectTypes if needed
	// Array to hold the hit results
	TArray<FHitResult> OutHits;

	// Perform the multi-sphere trace by channel
	bool bMultiSphereHit = UKismetSystemLibrary::SphereTraceMulti(
		GetWorld(),                        // World context
		MyCharacter->GetActorLocation(),                          // Start of the trace
		EndVec,                            // End of the trace
		Radius,                            // Radius of the sphere
		UEngineTypes::ConvertToTraceType(ECollisionChannel::ECC_GameTraceChannel1), // Use custom trace channel for weapon trace
		false,                             // bTraceComplex - false unless you want complex collision
		ActorsToIgnore,                    // Actors to ignore (MyCharacter)
		EDrawDebugTrace::None,      // Draw the trace for debugging  // ForDuration *****************
		OutHits,                           // Output array to store hit results
		true,                              // Ignore the tracing actor (self)
		FLinearColor::Red,               // Trace line color
		FLinearColor::Green,                 // Hit color
		2.0f                               // How long to draw the debug trace
	);

	if (bMultiSphereHit)
	{
		for (FHitResult& Hit : OutHits)
		{
			LastHitResult = Hit;
			// Handle each hit result here
			UE_LOG(LogTemp, Log, TEXT("Hit actor: %s"), *Hit.GetActor()->GetName());
			if (!HitActors.Contains(Hit.GetActor()) && Hit.GetActor()->IsValidLowLevel())
			{
				//UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactEffect, Hit.ImpactPoint, FRotator::ZeroRotator);  // replace with another particle effect.
				float Damage = UGameplayStatics::ApplyDamage(Hit.GetActor(), AmountOfDamage * DifficultyModeDamageModifier(), MyCharacter->GetController(), MyCharacter, DamageTypeClass);
				HitActors.AddUnique(Hit.GetActor());
				UE_LOG(LogTemp, Log, TEXT("Is this Firing??!?!!?! %f"), Damage);

				ScoreComp->TrackHit(MyCharacter->IsPerfectBeatHit());

				// Play attack sound
				if (AttackSound)
					UGameplayStatics::PlaySoundAtLocation(this, AttackSound, MyCharacter->GetActorLocation(), AttackSoundVolumeMultiplier, 1.1f, AttackSoundDelay);
				UE_LOG(LogTemp, Warning, TEXT("A_Freaking World Time In IMpactPoint is:  %f"), GetWorld()->GetTimeSeconds());

				const UNP_DamageType* YNP_DamageType = DamageTypeClass->GetDefaultObject<UNP_DamageType>();

				if (!DamageTypeClass)
				{
					UE_LOG(LogTemp, Error, TEXT("DamageTypeClass is nullptr!"));
					return;
				}

				if (YNP_DamageType->DamageType == EDamageTypes::Left) // light atttack
				{
					MyCharacter->PlayLightAttackShake();
				}
				else if(YNP_DamageType->DamageType == EDamageTypes::Right) // heavy attack
				{
					MyCharacter->PlayHeavyAttackShake();
				}


				// Call OnTargeted if the actor is valid and can be targeted
				if (AActor* HitActor = Hit.GetActor())
				{
					if (ANP_BaseEnemy* Enemy = Cast<ANP_BaseEnemy>(HitActor))
					{
						Enemy->OnTargeted();  // Call the OnTargeted function if the hit actor is of type ANP_BaseEnemy
					}
				}


				if (MyCharacter->IsPerfectBeatHit())
				{
					SpawnRagePickups(Hit);

					//UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactEffect, Hit.ImpactPoint, FRotator::ZeroRotator);  // replace with another particle effect.  *****
					FVector NiagaraPSpawnLocation = Hit.ImpactPoint + FVector(0, 0, 50.0f); // Raises effect by 20 units
					UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), WeaponHitEffect, NiagaraPSpawnLocation, Hit.ImpactNormal.Rotation());
					UE_LOG(LogTemp, Error, TEXT("ITHOUGHT THIS ONLY GET CALLED ON PERFECT HIT???"));

					PerfectHitOperations();
					ScoreComp->IncrementScore(500);
					MyCharacter->UpdateScoreEvent();
					MyCharacter->SetPerfectBeatHit(false);
				}
			}
		}
	}
}


void UDamageComponent::DrawProjectileWeaponCollision()
{
	if (!MyCharacter)
	{
		GetWorld()->GetTimerManager().ClearTimer(TimerForProjectileWeaponCollision);
		return;
	}

	AActor* CameraTarget = MyCharacter->GetCameraTargetActor();
	if (!CameraTarget)
	{
		GetWorld()->GetTimerManager().ClearTimer(TimerForProjectileWeaponCollision);
		return;
	}



	HitActors.Empty();

	// Actors to ignore
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(MyCharacter);

	// Array to hold the hit results
	TArray<FHitResult> OutHits;

	// Perform the multi-sphere trace by channel
	bool bMultiSphereHit = UKismetSystemLibrary::SphereTraceMulti(
		GetWorld(),
		CameraTarget->GetActorLocation(), // Start
		CameraTarget->GetActorLocation(), // End (stationary)
		RadiusForProjectileWeapon,
		UEngineTypes::ConvertToTraceType(ECollisionChannel::ECC_GameTraceChannel1),
		false, // bTraceComplex
		ActorsToIgnore,
		EDrawDebugTrace::None,
		OutHits,
		true, // Ignore self
		FLinearColor::Red,
		FLinearColor::Green,
		2.0f
	);

	if (bMultiSphereHit)
	{
		for (FHitResult& Hit : OutHits)
		{
			AActor* HitActor = Hit.GetActor();
			if (HitActor && !HitActors.Contains(HitActor) && HitActor->IsValidLowLevel())
			{
				float Damage = UGameplayStatics::ApplyDamage(HitActor, AmountOfDamageForProjectileWeapon, MyCharacter->GetController(), MyCharacter, DamageTypeClassForProjectileWeapon);
				HitActors.AddUnique(HitActor);

				UE_LOG(LogTemp, Log, TEXT("Hit actor: %s"), *HitActor->GetName());
				UE_LOG(LogTemp, Log, TEXT("Is this Firing??!?!!?! %f"), Damage);

				ScoreComp->TrackHit(MyCharacter->IsPerfectBeatHit());

				if (MyCharacter->IsPerfectBeatHit())
				{
					SpawnRagePickups(Hit);

					UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactEffect, Hit.ImpactPoint, FRotator::ZeroRotator);

					UE_LOG(LogTemp, Error, TEXT("ITHOUGHT THIS ONLY GET CALLED ON PERFECT HIT???"));

					PerfectHitOperations();
					ScoreComp->IncrementScore(500);
					MyCharacter->UpdateScoreEvent();
					MyCharacter->SetPerfectBeatHit(false);
				}
			}
		}
	}

	ProjectileCollisionSpawned++;
	if (ProjectileCollisionSpawned >= 2)
	{
		ProjectileCollisionSpawned = 0;
		GetWorld()->GetTimerManager().ClearTimer(TimerForProjectileWeaponCollision);
	}
}

void UDamageComponent::StartTimerProjectileWeaponCollision(float Radius, float AmountOfDamage, TSubclassOf<UNP_DamageType> DamageTypeClass)
{
	RadiusForProjectileWeapon = Radius;
	AmountOfDamageForProjectileWeapon = AmountOfDamage;
	DamageTypeClassForProjectileWeapon = DamageTypeClass;

    //GetWorld()->GetTimerManager().ClearTimer(TimerForProjectileWeaponCollision);
	UE_LOG(LogTemp, Error, TEXT("B_ITHOUGHT THIS ONLY GET CALLED ON PERFECT HIT???"));

	GetWorld()->GetTimerManager().SetTimer(TimerForProjectileWeaponCollision, this, &UDamageComponent::DrawProjectileWeaponCollision, MyCharacter->GetCurrentTempoDelay(), true); // 0.0167f
}


void UDamageComponent::DrawProjectileWeaponStunCollision(float Radius, float AmountOfDamage, TSubclassOf<UNP_DamageType> DamageTypeClass)
{

	HitActors.Empty();

	// Actors to ignore
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(MyCharacter);
	// Object types to trace for
	/*TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Pawn)); */
	// Add more ObjectTypes if needed
	// Array to hold the hit results
	TArray<FHitResult> OutHits;

	// Perform the multi-sphere trace by channel
	bool bMultiSphereHit = UKismetSystemLibrary::SphereTraceMulti(
		GetWorld(),                        // World context
		MyCharacter->GetActorLocation(),                          // Start of the trace
		MyCharacter->GetActorLocation(),                            // End of the trace
		Radius,                            // Radius of the sphere
		UEngineTypes::ConvertToTraceType(ECollisionChannel::ECC_GameTraceChannel1), // Use custom trace channel for weapon trace
		false,                             // bTraceComplex - false unless you want complex collision
		ActorsToIgnore,                    // Actors to ignore (MyCharacter)
		EDrawDebugTrace::None,      // Draw the trace for debugging  // ForDuration *****************
		OutHits,                           // Output array to store hit results
		true,                              // Ignore the tracing actor (self)
		FLinearColor::Red,               // Trace line color
		FLinearColor::Green,                 // Hit color
		2.0f                               // How long to draw the debug trace
	);

	if (bMultiSphereHit)
	{
		for (FHitResult& Hit : OutHits)
		{
			// Handle each hit result here
			UE_LOG(LogTemp, Log, TEXT("Hit actor: %s"), *Hit.GetActor()->GetName());
			if (!HitActors.Contains(Hit.GetActor()) && Hit.GetActor()->IsValidLowLevel())
			{
				//UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactEffect, Hit.ImpactPoint, FRotator::ZeroRotator);  // replace with another particle effect.
				float Damage = UGameplayStatics::ApplyDamage(Hit.GetActor(), AmountOfDamage, MyCharacter->GetController(), MyCharacter, DamageTypeClass);
				HitActors.AddUnique(Hit.GetActor());
				UE_LOG(LogTemp, Log, TEXT("Is this Firing??!?!!?! %f"), Damage);

				ScoreComp->TrackHit(MyCharacter->IsPerfectBeatHit());

				if (MyCharacter->IsPerfectBeatHit())
				{
					SpawnRagePickups(Hit);

					UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactEffect, Hit.ImpactPoint, FRotator::ZeroRotator);  // replace with another particle effect.  *****

					UE_LOG(LogTemp, Error, TEXT("ITHOUGHT THIS ONLY GET CALLED ON PERFECT HIT???"));

					PerfectHitOperations();
					ScoreComp->IncrementScore(500);
					MyCharacter->UpdateScoreEvent();
					MyCharacter->SetPerfectBeatHit(false);
				}
			}
		}
	}
}

void UDamageComponent::DrawEndComboWeaponCollision()
{
	if (!MyCharacter)
	{
		GetWorld()->GetTimerManager().ClearTimer(TimerForProjectileWeaponCollision);
		return;
	}

	AActor* CameraTarget = MyCharacter->GetCameraTargetActor();
	if (!CameraTarget)
	{
		GetWorld()->GetTimerManager().ClearTimer(TimerForProjectileWeaponCollision);
		return;
	}

	ANP_BaseEnemy* EnemyTarget = Cast<ANP_BaseEnemy>(CameraTarget);
	if (EnemyTarget && EnemyTarget->GetbIsBoss())
	{
		UE_LOG(LogTemp, Warning, TEXT("CameraTarget is a boss character. Skipping projectile hit check."));
		GetWorld()->GetTimerManager().ClearTimer(TimerForProjectileWeaponCollision);
		return;
	}

	HitActors.Empty();

	// Actors to ignore
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(MyCharacter);

	// Array to hold the hit results
	TArray<FHitResult> OutHits;

	// Perform the multi-sphere trace by channel
	bool bMultiSphereHit = UKismetSystemLibrary::SphereTraceMulti(
		GetWorld(),
		CameraTarget->GetActorLocation(), // Start
		CameraTarget->GetActorLocation(), // End (stationary)
		RadiusForProjectileWeapon,
		UEngineTypes::ConvertToTraceType(ECollisionChannel::ECC_GameTraceChannel1),
		false, // bTraceComplex
		ActorsToIgnore,
		EDrawDebugTrace::None,
		OutHits,
		true, // Ignore self
		FLinearColor::Red,
		FLinearColor::Green,
		2.0f
	);

	if (bMultiSphereHit)
	{
		for (FHitResult& Hit : OutHits)
		{
			AActor* HitActor = Hit.GetActor();
			if (HitActor && !HitActors.Contains(HitActor) && HitActor->IsValidLowLevel())
			{
				float Damage = UGameplayStatics::ApplyDamage(HitActor, AmountOfDamageForProjectileWeapon, MyCharacter->GetController(), MyCharacter, DamageTypeClassForProjectileWeapon);
				HitActors.AddUnique(HitActor);

				UE_LOG(LogTemp, Log, TEXT("WOAHHit actor: %s"), *HitActor->GetName());
				UE_LOG(LogTemp, Log, TEXT("Is this Firing??!?!!?! %f"), Damage);

				ScoreComp->TrackHit(MyCharacter->IsPerfectBeatHit());

				if (MyCharacter->IsPerfectBeatHit())
				{
					SpawnRagePickups(Hit);

					UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactEffect, Hit.ImpactPoint, FRotator::ZeroRotator);

					UE_LOG(LogTemp, Error, TEXT("ITHOUGHT THIS ONLY GET CALLED ON PERFECT HIT???"));

					PerfectHitOperations();
					ScoreComp->IncrementScore(500);
					MyCharacter->UpdateScoreEvent();
					MyCharacter->SetPerfectBeatHit(false);
				}
			}
		}
	}

	ProjectileCollisionSpawned++;
	if (ProjectileCollisionSpawned >= 2)
	{
		ProjectileCollisionSpawned = 0;
		GetWorld()->GetTimerManager().ClearTimer(TimerForProjectileWeaponCollision);
	}
}

void UDamageComponent::StartTimerEndComboWeaponCollision(float Radius, float AmountOfDamage, TSubclassOf<UNP_DamageType> DamageTypeClass)
{
	RadiusForProjectileWeapon = Radius;
	AmountOfDamageForProjectileWeapon = AmountOfDamage;
	DamageTypeClassForProjectileWeapon = DamageTypeClass;

	//GetWorld()->GetTimerManager().ClearTimer(TimerForProjectileWeaponCollision);
	UE_LOG(LogTemp, Error, TEXT("B_ITHOUGHT THIS ONLY GET CALLED ON PERFECT HIT???"));

	GetWorld()->GetTimerManager().SetTimer(TimerForProjectileWeaponCollision, this, &UDamageComponent::DrawEndComboWeaponCollision, MyCharacter->GetCurrentTempoDelay(), true); // 0.0167f
}


UAnimMontage* UDamageComponent::GetHitReactionMontage(EDamageTypes DamageType)
{
	switch (DamageType)
	{
		case EDamageTypes::Default:
			UE_LOG(LogTemp, Error, TEXT("PLAYER HIT REACTION IS Default"));
			return HR_Knockback;

		case EDamageTypes::Right:
			UE_LOG(LogTemp, Error, TEXT("PLAYER HIT REACTION IS Right"));
			return HR_Right;

		case EDamageTypes::Left:
			UE_LOG(LogTemp, Error, TEXT("PLAYER HIT REACTION IS Left"));
			return HR_Left;

		case EDamageTypes::Middle:
			UE_LOG(LogTemp, Error, TEXT("PLAYER HIT REACTION IS Middle"));
			return HR_Middle;

		case EDamageTypes::Knockdown:
			UE_LOG(LogTemp, Error, TEXT("PLAYER HIT REACTION IS Knockdown"));
			return HR_Knockdown;

		case EDamageTypes::Knockback:
			UE_LOG(LogTemp, Error, TEXT("PLAYER HIT REACTION IS Knockback"));
			return HR_Knockback;

		case EDamageTypes::Launch:
			UE_LOG(LogTemp, Error, TEXT("PLAYER HIT REACTION IS Launch"));
			return HR_Knockback;
	}
	UE_LOG(LogTemp, Error, TEXT("PLAYER HIT REACTION IS OUTSIDE"));
	return HR_Knockback;
}


void UDamageComponent::PerfectHitOperations()
{
	UE_LOG(LogTemp, Error, TEXT("ITHOUGHT THIS ONLY GET CALLED ON PERFECT HIT???"));

	MyCharacter->SetPerfectBeatHit(false);
}

void UDamageComponent::SpawnRagePickups(FHitResult& HitResult)
{
	FRotator SpawnRotation(0.0f, 0.0f, 0.0f);  // Set rotation for spawning
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = MyCharacter;                   // Set the owner of the spawned actor, optional
	SpawnParams.Instigator = MyCharacter->GetInstigator();   // Set the instigator, optional

	if (GetWorld())
	{
		int32 NumPickupsToSpawn = 9; // Number of pickups to spawn
		float RandomRange = 100.0f; // Range for random spawn offset
		float ExplosionForce = 700.0f; // Force magnitude for impulse
		float UpwardForce = 300.0f; // Additional upward force

		for (int32 i = 0; i < NumPickupsToSpawn; ++i)
		{
			// Generate a random direction with limited vertical randomness
			FVector RandomDirection = FMath::VRand();
			RandomDirection.Z *= 0.3f; // Scale Z for less vertical randomness
			RandomDirection.Normalize();

			// Calculate random offset for spawning
			FVector RandomOffset = RandomDirection * RandomRange;

			// Height Spawn Offset
			float HeightSpawnOffset = 100.0f;

			// Calculate spawn location
			FVector SpawnLocation = HitResult.GetActor()->GetActorLocation() + FVector(0.0f, 0.0f, HeightSpawnOffset) + RandomOffset;

			// Debug visualization of spawn location
			//DrawDebugSphere(GetWorld(), SpawnLocation, 10.0f, 12, FColor::Green, false, 2.0f);

			// Spawn the actor
			AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(RagePickup, SpawnLocation, FRotator::ZeroRotator, SpawnParams);
			if (!SpawnedActor) continue;

			// Add impulse to the spawned actor
			UStaticMeshComponent* MeshComp = Cast<UStaticMeshComponent>(SpawnedActor->GetComponentByClass(UStaticMeshComponent::StaticClass()));
			if (MeshComp && MeshComp->IsSimulatingPhysics())
			{
				// Calculate explosion force direction and apply impulse
				FVector ExplosionForceDirection = RandomDirection;
				MeshComp->AddImpulse(ExplosionForceDirection * ExplosionForce, NAME_None, true);

				// Apply optional upward force
				MeshComp->AddImpulse(FVector(0, 0, UpwardForce), NAME_None, true);
			}
		}
	}
}

float UDamageComponent::DifficultyModeDamageModifier()
{
	// Get difficulty from GameInstance
	float DamageMultiplier = 1.0f;

	switch (GameInstance->GetCurrentDifficultyMode())
	{
	case 0:
		UE_LOG(LogTemp, Error, TEXT("DOOOOM It's Boring"));
		DamageMultiplier = 1.0f;  // Increase damage
		break;
	case 1:
		UE_LOG(LogTemp, Error, TEXT("DOOOOM It's MID"));
		DamageMultiplier = .5f;  // Normal damage
		break;
	case 2:
		UE_LOG(LogTemp, Error, TEXT("DOOOOM It's Hard"));
		DamageMultiplier = 0.2f; // Reduce damage
		break;
	}

	return DamageMultiplier;
}

//void UDamageComponent::PerformDeath()
//{
//	CharacterState->SetState(ECharacterStates::Death);
//	MyCharacter->PlayAnimMontage(DeathMontage);
//	MyCharacter->GetController()->DisableInput(UGameplayStatics::GetPlayerController(GetWorld(), 0));
//}

