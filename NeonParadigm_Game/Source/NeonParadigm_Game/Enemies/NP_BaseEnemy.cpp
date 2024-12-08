// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonParadigm_Game/Enemies/NP_BaseEnemy.h"
#include "NeonParadigm_Game/DamageType/NP_DamageType.h"
#include "Animation/AnimMontage.h"
#include "NeonParadigm_Game/Components/AttackComponent.h"
#include "NeonParadigm_Game/Enums/CharacterStateComponent.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/WidgetComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
ANP_BaseEnemy::ANP_BaseEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	NoneState = ECharacterStates::None;
	AttackState = ECharacterStates::Attack;
	DodgeState = ECharacterStates::Dodge;
	DeathState = ECharacterStates::Death;
	DisabledState = ECharacterStates::Disabled;

	CurrentState = ECharacterStates::None;

	//CharacterState = CreateDefaultSubobject<UCharacterStateComponent>(TEXT("Character State Component"));
	SpeedOfAttackMovement = 300.0f;

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Weapon Mesh"));

	// Create the Widget Component and attach it to the root component
	HealthBarWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("Health Bar Widget"));
	HealthBarWidget->SetupAttachment(GetMesh());

	LockOnWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("Lock On Widget"));
	LockOnWidget->SetupAttachment(GetMesh());
}

// Called when the game starts or when spawned
void ANP_BaseEnemy::BeginPlay()
{
	Super::BeginPlay();

	// Attach the StaticMesh to the SkeletalMesh (Parent) at a specified socket
	WeaponMesh->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, TEXT("WeaponSocket"));


	CurrentHealth = MaxHealth;

	//MyCharacter = Cast<ANP_BaseEnemy>(GetOwner());
	//AttackComp = FindComponentByClass<UAttackComponent>();

	OnTakeAnyDamage.AddDynamic(this, &ANP_BaseEnemy::HandleTakeAnyDamage);

	if (HealthBarWidget)
	{
		// Proceed with your logic
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("HealthBarWidget is null!"));
	}
	
}

// Called every frame
void ANP_BaseEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANP_BaseEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ANP_BaseEnemy::AttackMovement(float Distance)
{
	gDistance = Distance;
	StopAttackMovement();
	if (Distance != 0.0f)
	{
		GetWorld()->GetTimerManager().SetTimer(TimerForAttackMovement, this, &ANP_BaseEnemy::UpdateCharacterLocation, 0.01f, true); // 0.0167f
	}
}

void ANP_BaseEnemy::StopAttackMovement()
{
	GetWorld()->GetTimerManager().ClearTimer(TimerForAttackMovement); // this might not work
}

void ANP_BaseEnemy::UpdateCharacterLocation()
{
	DurationOfMovement++;
	UE_LOG(LogTemp, Warning, TEXT("Duration Of Movement: %d"), DurationOfMovement);

	if (DurationOfMovement >= 10)
	{
		StopAttackMovement();
		DurationOfMovement = 0;
		UE_LOG(LogTemp, Warning, TEXT("Duration Of Movement Reset: %d"), DurationOfMovement);
	}
	FVector TargetLocation = GetActorLocation();
	FVector ReversedForwardVec = GetActorForwardVector() * -1.0f;
	TargetLocation += ReversedForwardVec * gDistance;
	FVector AttackMovementLocation = FMath::VInterpTo(GetActorLocation(), TargetLocation, GetWorld()->GetDeltaSeconds(), SpeedOfAttackMovement);
	SetActorLocation(AttackMovementLocation);
}

void ANP_BaseEnemy::HandleTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	// Handle the damage taken event here
	UE_LOG(LogTemp, Warning, TEXT("Actor %s took %f damage"), *DamagedActor->GetName(), Damage);


	CurrentHealth -= Damage;


	if (CurrentHealth > 0.0f)
	{
		const UNP_DamageType* NP_DamageType = Cast<const UNP_DamageType>(DamageType);
		if (NP_DamageType)
		{
			// Successfully cast to UNP_DamageType
			// You can now access members or functions of UNP_DamageType
			UE_LOG(LogTemp, Error, TEXT("DAMAGE TYPE!@!! SOmething RIGHT!!!!"));
			//NP_DamageType->DamageType;
		}
		else
		{
			// Handle case where the cast failed (if the damage type is not of UNP_DamageType)
			UE_LOG(LogTemp, Error, TEXT("DAMAGE TYPE!@!! SOmething Wrong!!!!"));

		}


		TArray<ECharacterStates> CurrentCharacterState;
		CurrentCharacterState.Add(ECharacterStates::Death);

		if (!IsCurrentStateEqualToAny(CurrentCharacterState)) //&& IsValid(GetHitReactionMontage(MyDamageType->GetDamageType())))
		{
			UE_LOG(LogTemp, Warning, TEXT("ENEMY STATE IS VALId!!!!!!!!"));
			if (IsValid(GetHitReactionMontage(NP_DamageType->DamageType)))
			{
				SetState(ECharacterStates::Disabled);
				UpdateCharacterRotationWhenHit(DamageCauser);
				StopAttackMovement();

				if (!GetCharacterMovement()->IsFalling() && !GetCharacterMovement()->IsFlying() && 
					NP_DamageType->DamageType != EDamageTypes::Knockback &&
					NP_DamageType->DamageType != EDamageTypes::Knockdown) // this might need to be an or statement or something.
				{
					AttackMovement(10.0f); //15.0f  should maybe be the value
				}
				else
				{
					FVector SettingEnemyActorLocation (GetActorLocation().X, GetActorLocation().Y, DamageCauser->GetActorLocation().Z);  // we could have it so that the enemy's height is a little lower than the player's **********
					SetActorLocation(SettingEnemyActorLocation, true);
				}

				PlayAnimMontage(GetHitReactionMontage(NP_DamageType->DamageType));
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("ENEMY DAMAGETYPE NOTTTT VALId!!!!!!!!"));
			}

		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("ENEMY HIT REACTION IS NOT VALId"));
		}
	}
	else
	{
		PerformDeath();
	}
}

UAnimMontage* ANP_BaseEnemy::GetHitReactionMontage(EDamageTypes DamageType)  // ****************  
{
	/*if (DamageType != EDamageTypes::Launch &&
		DamageType != EDamageTypes::Default &&
		DamageType != EDamageTypes::Knockback &&
		DamageType != EDamageTypes::Knockdown &&
		DamageType != EDamageTypes::Left &&
		DamageType != EDamageTypes::Right &&
		DamageType != EDamageTypes::Middle)
		return HR_Left;*/

	if (GetCharacterMovement()->IsFalling() || GetCharacterMovement()->IsFlying())
	{
		GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Flying);

		switch (DamageType)
		{
			case EDamageTypes::Default:
				UE_LOG(LogTemp, Error, TEXT("ENEMY HIT REACTION IS NOT Default AERIAL"));
				return HR_Launch;

			case EDamageTypes::Right:
				UE_LOG(LogTemp, Error, TEXT("ENEMY HIT REACTION IS NOT Right AERIAL"));
				return HR_Launch;

			case EDamageTypes::Left:
				UE_LOG(LogTemp, Error, TEXT("ENEMY HIT REACTION IS NOT Left AERIAL"));
				return HR_Launch;

			case EDamageTypes::Middle:
				UE_LOG(LogTemp, Error, TEXT("ENEMY HIT REACTION IS NOT Middle AERIAL"));
				return HR_Launch;

			case EDamageTypes::Knockdown:
				UE_LOG(LogTemp, Error, TEXT("ENEMY HIT REACTION IS NOT Knockdown AERIAL"));
				return HR_Launch;

			case EDamageTypes::Knockback:
				UE_LOG(LogTemp, Error, TEXT("ENEMY HIT REACTION IS NOT Knockback AERIAL"));
				GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Falling); // set to flying maybe
				AttackMovement(40.0f); //15.0f  should maybe be the value
				bAirKnockback = true;
				return HR_Air_Knockback;

			case EDamageTypes::Launch:
				UE_LOG(LogTemp, Error, TEXT("ENEMY HIT REACTION IS NOT Launch AERIAL"));
				return HR_Launch;
			case EDamageTypes::Stun:
				UE_LOG(LogTemp, Error, TEXT("ENEMY HIT REACTION IS NOT Stun AERIAL"));
				return HR_Stun;
			case EDamageTypes::Projectiles:
				UE_LOG(LogTemp, Error, TEXT("ENEMY HIT REACTION IS NOT Projectiles AERIAL"));
				return HR_Stun;
			case EDamageTypes::Explosion:
				UE_LOG(LogTemp, Error, TEXT("ENEMY HIT REACTION IS NOT Explosion AERIAL"));
				return HR_Stun;
		}
	}
	else
	{
		switch (DamageType)
		{
			case EDamageTypes::Default:
				UE_LOG(LogTemp, Error, TEXT("ENEMY HIT REACTION IS NOT Default"));
				return HR_Knockback;

			case EDamageTypes::Right:
				UE_LOG(LogTemp, Error, TEXT("ENEMY HIT REACTION IS NOT Right"));
				return HR_Right;

			case EDamageTypes::Left:
				UE_LOG(LogTemp, Error, TEXT("ENEMY HIT REACTION IS NOT Left"));
				return HR_Left;

			case EDamageTypes::Middle:
				UE_LOG(LogTemp, Error, TEXT("ENEMY HIT REACTION IS NOT Middle"));
				return HR_Middle;

			case EDamageTypes::Knockdown:
				UE_LOG(LogTemp, Error, TEXT("ENEMY HIT REACTION IS NOT Knockdown"));
				return HR_Knockdown;

			case EDamageTypes::Knockback:
				UE_LOG(LogTemp, Error, TEXT("ENEMY HIT REACTION IS NOT Knockback"));
				return HR_Knockback;

			case EDamageTypes::Launch:
				UE_LOG(LogTemp, Error, TEXT("ENEMY HIT REACTION IS NOT Launch"));
				LaunchEnemyIntoAir();
				return HR_Launch;
			case EDamageTypes::Stun:
				UE_LOG(LogTemp, Error, TEXT("ENEMY HIT REACTION IS NOT Stun"));
				EnemyStunned();
				return HR_Stun;
			case EDamageTypes::Projectiles:
				UE_LOG(LogTemp, Error, TEXT("ENEMY HIT REACTION IS NOT Projectiles"));
				EnemyStunnedWithProjectiles();
				AttackMovement(15.0f); //15.0f  should maybe be the value
				return HR_Stun;
			case EDamageTypes::Explosion:
				UE_LOG(LogTemp, Error, TEXT("ENEMY HIT REACTION IS NOT Explosion"));
				EnemyStunnedWithProjectiles();
				AttackMovement(25.0f); //15.0f  should maybe be the value
				PlayCameraShake();
				return HR_Stun;
		}
	}

	UE_LOG(LogTemp, Error, TEXT("ENEMY HIT REACTION IS OUTSIDE"));
	return HR_Knockback;
}

void ANP_BaseEnemy::PerformDeath()
{
	SetState(ECharacterStates::Death);
	PlayAnimMontage(DeathMontage);
	//GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Block);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel1, ECollisionResponse::ECR_Ignore);

	PerformThingsAfterDeath();
}

void ANP_BaseEnemy::Parried()
{
	if (bCanBeParried)
	{
		SetState(ECharacterStates::Disabled);
		PlayAnimMontage(ParryStaggerMontage);
	}
}

void ANP_BaseEnemy::UpdateCharacterRotationWhenHit(AActor* DamageCauserCharacter)
{
	FRotator FindLookAtRot(UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), DamageCauserCharacter->GetActorLocation()));
	FRotator TargetRotator(GetActorRotation().Pitch, FindLookAtRot.Yaw, GetActorRotation().Roll);
	SetActorRotation(TargetRotator);
}

void ANP_BaseEnemy::SetState(ECharacterStates NewState)
{

	if (NewState != CurrentState && CurrentState != ECharacterStates::Death)
		CurrentState = NewState;
}

ECharacterStates ANP_BaseEnemy::GetState() const
{
	return CurrentState;
}

bool ANP_BaseEnemy::IsCurrentStateEqualToAny(const TArray<ECharacterStates>& StatesToCheck)
{
	UE_LOG(LogTemp, Log, TEXT("CurrentState: %d"), (int32)CurrentState);

	for (ECharacterStates State : StatesToCheck)
	{
		UE_LOG(LogTemp, Log, TEXT("State to Check: %d"), (int32)State);
	}

	return StatesToCheck.Contains(CurrentState);
}

void ANP_BaseEnemy::ResetState() // move reset state in anim notify to make adjust how fast the enemy falls with player.
{
	if (GetCharacterMovement()->MovementMode == EMovementMode::MOVE_Falling ||
		GetCharacterMovement()->MovementMode == EMovementMode::MOVE_Flying)
	{
		bOnLandReset = true;
		GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Walking); // this is glitching when the enemy dies ****
	}
	else
	{
		SetState(ECharacterStates::None);
	}

}

void ANP_BaseEnemy::OnTargeted()
{
	HealthBarWidget->SetVisibility(true);
	LockOnWidget->SetVisibility(true);
}

void ANP_BaseEnemy::EndTarget()
{
	HealthBarWidget->SetVisibility(false);
	LockOnWidget->SetVisibility(false);
}



void ANP_BaseEnemy::SetCurrentTempoDelay(float CurTempoDelay)
{
	CurrentTempoDelay = CurTempoDelay;
}

float ANP_BaseEnemy::GetCurrentTempoDelay()
{
	return CurrentTempoDelay;
}

void ANP_BaseEnemy::SetCurrentAnimTimeDelay(float CurAnimTimeDelay)
{
	CurrentAnimTimeDelay = CurAnimTimeDelay;
}

float ANP_BaseEnemy::GetCurrentAnimTimeDelay()
{
	return CurrentAnimTimeDelay;
}

void ANP_BaseEnemy::SetLastBeatTime(float fLastBeatTime)
{
	LastBeatTime = fLastBeatTime;
}

float ANP_BaseEnemy::GetLastBeatTime()
{
	return LastBeatTime;
}

void ANP_BaseEnemy::SetNextBeatTime(float fNextBeatTime)
{
	NextBeatTime = fNextBeatTime;
}

float ANP_BaseEnemy::GetNextBeatTime()
{
	return NextBeatTime;
}

void ANP_BaseEnemy::SetThirdBeatTime(float fThirdBeatTime)
{
	ThirdBeatTime = fThirdBeatTime;
}

float ANP_BaseEnemy::GetThirdBeatTime()
{
	return ThirdBeatTime;
}

float ANP_BaseEnemy::GetCurrentAnimPlayRate()
{
	return PlayRateForAnimMontages;
}

void ANP_BaseEnemy::TestRhythmDelayEvent()
{
	UE_LOG(LogTemp, Error, TEXT("ENEMY Input Tick: %f"), GetWorld()->GetTimeSeconds());

	DelayFromLastBeat = GetWorld()->GetTimeSeconds() - LastBeatTime;
	UE_LOG(LogTemp, Error, TEXT("ENEMY Delay From Last Beat: %f"), DelayFromLastBeat);

	DelayFromNextBeat = NextBeatTime - GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Error, TEXT("ENEMY Delay From Next Beat: %f"), DelayFromNextBeat);

	DelayFromThirdBeat = ThirdBeatTime - GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Error, TEXT("ENEMY Delay From Third Beat: %f"), DelayFromThirdBeat);

	if (DelayFromLastBeat <= 0.33f && GetCurrentAnimTimeDelay() <= 0.9f)
	{
		UE_LOG(LogTemp, Warning, TEXT("ENEMY Input Was CLOSER to LAST Beat: %f"), DelayFromLastBeat);

		PlayRateForAnimMontages = CurrentAnimTimeDelay / DelayFromNextBeat;

		UE_LOG(LogTemp, Error, TEXT("ENEMY Play Rate For AnimMontage: %f"), PlayRateForAnimMontages);

	}
	else if (GetCurrentAnimTimeDelay() <= 0.9f)
	{
		UE_LOG(LogTemp, Warning, TEXT("ENEMY Input Was CLOSER to NEXT Beat: %f"), DelayFromNextBeat);

		TotalTimeDelayToNextBeat = DelayFromNextBeat + GetCurrentTempoDelay(); // need to get time delay from tempo in music component

		UE_LOG(LogTemp, Warning, TEXT("ENEMY Total Time Delay To Next Beat: %f"), TotalTimeDelayToNextBeat);

		PlayRateForAnimMontages = CurrentAnimTimeDelay / TotalTimeDelayToNextBeat;

		UE_LOG(LogTemp, Error, TEXT("ENEMY Play Rate For AnimMontage: %f"), PlayRateForAnimMontages);
	}
	else
	{
		//TotalTimeDelayToThirdBeat = DelayFromNextBeat + GetCurrentTempoDelay(); // need to get time delay from tempo in music component

		//UE_LOG(LogTemp, Warning, TEXT("Total Time Delay To Next Beat: %f"), TotalTimeDelayToNextBeat);

		//PlayRateForAnimMontages = CurrentAnimTimeDelay / TotalTimeDelayToNextBeat;

		PlayRateForAnimMontages = CurrentAnimTimeDelay / DelayFromThirdBeat;

		UE_LOG(LogTemp, Error, TEXT("ENEMY Play Rate For AnimMontage: %f"), PlayRateForAnimMontages);
	}


	//float ClampedValueForPlayRate = FMath::Clamp(PlayRateForAnimMontages, 0.5f, 2.5f); // Definetly Might change this so make them variables. 

	//PlayRateForAnimMontages = ClampedValueForPlayRate;

	//float MontageLength = PlayAnimMontage(TestRhythmMontage, ClampedValueForPlayRate);

	//UE_LOG(LogTemp, Display, TEXT("ENEMY Montage Length: %f"), MontageLength);



}

float ANP_BaseEnemy::CheckToWaitForBeat()
{
	UE_LOG(LogTemp, Error, TEXT("ENEMY CHECK Input Tick: %f"), GetWorld()->GetTimeSeconds());

	DelayFromLastBeat = GetWorld()->GetTimeSeconds() - LastBeatTime;
	UE_LOG(LogTemp, Error, TEXT("ENEMY CHECK Delay From Last Beat: %f"), DelayFromLastBeat);

	DelayFromNextBeat = NextBeatTime - GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Error, TEXT("ENEMY CHECK Delay From Next Beat: %f"), DelayFromNextBeat);

	DelayFromThirdBeat = ThirdBeatTime - GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Error, TEXT("ENEMY CHECK Delay From Third Beat: %f"), DelayFromThirdBeat);

	return DelayFromNextBeat;

}

void ANP_BaseEnemy::EnemFindNotifyTriggerTime(UAnimMontage* Montage, FString NotifyName)
{
	if (!Montage)
    {
        UE_LOG(LogTemp, Warning, TEXT("Montage is null."));
        return;
    }

    TArray<FAnimNotifyEvent>& NotifyEvents = Montage->Notifies; // Gets ref instead of copy

    for (const FAnimNotifyEvent& NotifyEvent : NotifyEvents)
    {
        // Skip if Notify is null or if it is a Notify State
        if (!NotifyEvent.Notify || NotifyEvent.NotifyStateClass)
        {
            UE_LOG(LogTemp, Warning, TEXT("Skipping NotifyEvent: It is either null or a Notify State."));
            continue;
        }

        // Process valid Notify
        UE_LOG(LogTemp, Log, TEXT("I'm checking Notify: %s"), *NotifyEvent.Notify->GetNotifyName());
        FString ActualNotifyName = NotifyEvent.Notify->GetNotifyName();
        UE_LOG(LogTemp, Log, TEXT("I'm checking Actual Notify Name: %s"), *ActualNotifyName);

        if (ActualNotifyName.StartsWith(NotifyName))
        {
            NotifyTriggerTime = NotifyEvent.GetTriggerTime();
            UE_LOG(LogTemp, Log, TEXT("Notify %s triggers at time: %f seconds"), *NotifyName, NotifyTriggerTime);
            return;
        }
    }


	UE_LOG(LogTemp, Warning, TEXT("Notify with name %s not found in montage."), *NotifyName);
}

float ANP_BaseEnemy::GetNotifyTriggerTime()
{
	return NotifyTriggerTime;
}



void ANP_BaseEnemy::LaunchEnemyIntoAir()
{

	LaunchLocation = GetActorLocation() + FVector(0.0f, 0.0f, 300.0f); // May have to lower height for players air launch attack *********
	GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Flying);
	PerformThingsAfterDeath();

	GetWorld()->GetTimerManager().SetTimer(TimerForLaunchMovement, this, &ANP_BaseEnemy::MoveEnemyIntoAir, 0.01f, true); // 0.0167f

}

void ANP_BaseEnemy::MoveEnemyIntoAir()
{
	DurationOfLaunch++;
	UE_LOG(LogTemp, Warning, TEXT("Duration Of Launch: %d"), DurationOfLaunch);

	if (DurationOfLaunch >= 25)  // may have to change this to 50 or more
	{
		StopLaunchMovement();
		GetCharacterMovement()->GravityScale = 1.0f;   // gravity scale **********************
		DurationOfLaunch = 0;
		UE_LOG(LogTemp, Warning, TEXT("Duration Of Launch Reset: %d"), DurationOfLaunch);
	}
	float Alpha = 0.1f;  // You can adjust this based on how fast you want the rotation
	// Linearly interpolate between the start and launch locations based on progress
	FVector LaunchMovementLocation = FMath::Lerp(GetActorLocation(), LaunchLocation, Alpha);
	//FVector LaunchMovementLocation = FMath::VInterpTo(MyCharacter->GetActorLocation(), LaunchLocation, GetWorld()->GetDeltaSeconds(), SpeedOfLaunch);
	SetActorLocation(LaunchMovementLocation);
}

void ANP_BaseEnemy::StopLaunchMovement()
{
	GetWorld()->GetTimerManager().ClearTimer(TimerForLaunchMovement); // this might not work
}

void ANP_BaseEnemy::Landed(const FHitResult& Hit)
{
	Super::Landed(Hit);

	if (bAirKnockback)
	{
		bAirKnockback = false;
		PlayAnimMontage(HR_Air_Knockback_OnLanded);
		GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Walking);
		GetCharacterMovement()->GravityScale = 2.5f;   // gravity scale **********************

		if (CurrentState != ECharacterStates::Death)
		{
			ResetAIToWorkAgain();
			SetState(ECharacterStates::None);
		}
	}
	else
	{
		if (bOnLandReset)  // On Landed Reset
		{
			GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Walking);
			bOnLandReset = false;
			ResetState();
			GetCharacterMovement()->GravityScale = 2.5f;   // gravity scale **********************
			
			if (CurrentState != ECharacterStates::Death)
			{
				ResetAIToWorkAgain();
				SetState(ECharacterStates::None);
			}
		}
	}
	//SetState(ECharacterStates::None);


}

UAnimMontage* ANP_BaseEnemy::GetGetupAnimMontage()
{
	return HR_Getup;
}

