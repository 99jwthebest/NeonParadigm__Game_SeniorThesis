// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonParadigm_Game/Enemies/NP_BaseEnemy.h"
#include "NeonParadigm_Game/DamageType/NP_DamageType.h"
#include "Animation/AnimMontage.h"
#include "NeonParadigm_Game/Components/AttackComponent.h"
#include "NeonParadigm_Game/Enums/CharacterStateComponent.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/WidgetComponent.h"

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
		// Step 1: Create or obtain an instance of UNP_DamageType
		UNP_DamageType* MyDamageType = NewObject<UNP_DamageType>(GetWorld());

		/*if (MyDamageType)
		{

		}
		else 
		{

			UE_LOG(LogTemp, Error, TEXT("!@!! SOmething Wrong!!!!"));
			return;
		}*/


		TArray<ECharacterStates> CurrentCharacterState;
		CurrentCharacterState.Add(ECharacterStates::Death);

		if (!IsCurrentStateEqualToAny(CurrentCharacterState)) //&& IsValid(GetHitReactionMontage(MyDamageType->GetDamageType())))
		{
			UE_LOG(LogTemp, Warning, TEXT("ENEMY STATE IS VALId!!!!!!!!"));
			if (IsValid(GetHitReactionMontage(MyDamageType->GetDamageType())))
			{
				SetState(ECharacterStates::Disabled);
				UpdateCharacterRotationWhenHit(DamageCauser);
				StopAttackMovement();
				AttackMovement(10.0f); //15.0f  should maybe be the value
				PlayAnimMontage(GetHitReactionMontage(MyDamageType->GetDamageType()));
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

UAnimMontage* ANP_BaseEnemy::GetHitReactionMontage(EDamageTypes DamageType)
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

void ANP_BaseEnemy::PerformDeath()
{
	SetState(ECharacterStates::Death);
	PlayAnimMontage(DeathMontage);
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
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

	if (NewState != CurrentState)
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

void ANP_BaseEnemy::ResetState()
{
	SetState(ECharacterStates::None);
	/*AttackComp->ResetLightAttack();
	AttackComp->ResetHeavyAttack();*/
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



