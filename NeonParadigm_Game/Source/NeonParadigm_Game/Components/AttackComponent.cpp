// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonParadigm_Game/Components/AttackComponent.h"
#include "NeonParadigm_Game/Enums/CharacterStateComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "NeonParadigm_Game/NeonParadigm_GameCharacter.h"
#include "Animation/AnimMontage.h"
#include "TimerManager.h"


// Sets default values for this component's properties
UAttackComponent::UAttackComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;



	SpeedOfAttackMovement = 300.0f;
	DurationOfMovement = 0;
	LightAttackIndex = 0;
	HeavyAttackIndex = 0;
	// ...
}


// Called when the game starts
void UAttackComponent::BeginPlay()
{
	Super::BeginPlay();

	MyCharacter = Cast<ANeonParadigm_GameCharacter>(GetOwner());

	CharacterState = MyCharacter->FindComponentByClass<UCharacterStateComponent>();
	if (CharacterState != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Found CharacterState Compo!!!!!"))
	}
}


// Called every frame
void UAttackComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAttackComponent::SetSaveLightAttack(bool bSetSaveLightAttack)
{
	bSaveLightAttack = bSetSaveLightAttack;
}

void UAttackComponent::LightAttackEvent()
{
	if (CanAttack())
	{
		ResetHeavyAttack();
		PerformLightAttack(LightAttackIndex);
	}
}

bool UAttackComponent::CanAttack()
{

	TArray<ECharacterStates> CurrentCharacterState;
	CurrentCharacterState.Add(ECharacterStates::Attack);
	CurrentCharacterState.Add(ECharacterStates::Dodge);
	CurrentCharacterState.Add(ECharacterStates::Disabled);
	CurrentCharacterState.Add(ECharacterStates::Death);
	//UE_LOG(LogTemp, Error, TEXT("LIGHT ATTACK MONTAGE INVALID"));

	return !CharacterState->IsCurrentStateEqualToAny(CurrentCharacterState) && !MyCharacter->GetCharacterMovement()->IsFalling();
	
}

void UAttackComponent::PerformLightAttack(int AttackIndex)
{
	if (AttackIndex >= LightAttackMontages.Num())
	{
		//Reset Light Attack Index If Index Is Equal Or Greater Than Length Of Light Attack Sequence
		LightAttackIndex = 0;
	}

	if (LightAttackMontages.IsValidIndex(LightAttackIndex))
	{
		UAnimMontage* Montage = LightAttackMontages[LightAttackIndex];
		if (IsValid(Montage))
		{
			UAnimMontage* LightAttackMontage = Montage;
			CharacterState->SetState(ECharacterStates::Attack);
			AttackMovement(5.0f);
			MyCharacter->PlayAnimMontage(LightAttackMontage);
			LightAttackIndex++;
			if (LightAttackIndex >= LightAttackMontages.Num())
			{
				//Reset Light Attack Index If Index Becomes Equal Or Greater Than Light Attack Sequence
				LightAttackIndex = 0;
				return;
			}
			else
			{
				return;
			}
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("LIGHT ATTACK MONTAGE INVALID"));
			return;
		}
	}
}

void UAttackComponent::CheckingMontage(const int AttackMontageIndex)
{
	if (LightAttackMontages.IsValidIndex(AttackMontageIndex))
	{
		UAnimMontage* Montage = LightAttackMontages[LightAttackIndex];
		if (IsValid(Montage))
		{
			UAnimMontage* LightAttackMontage = Montage;
		}
	}
}

void UAttackComponent::AttackMovement(float Distance)
{
	gDistance = Distance;
	StopAttackMovement();
	if (Distance != 0.0f)
	{
		GetWorld()->GetTimerManager().SetTimer(TimerForAttackMovement, this, &UAttackComponent::UpdateCharacterLocation, 0.01f, true); // 0.0167f
	}
}

void UAttackComponent::StopAttackMovement()
{
	GetWorld()->GetTimerManager().ClearTimer(TimerForAttackMovement); // this might not work
}

void UAttackComponent::UpdateCharacterLocation()
{
	DurationOfMovement++;
	UE_LOG(LogTemp, Warning, TEXT("Duration Of Movement: %d"), DurationOfMovement);

	if (DurationOfMovement >= 25)
	{
		StopAttackMovement();
		DurationOfMovement = 0;
		UE_LOG(LogTemp, Warning, TEXT("Duration Of Movement Reset: %d"), DurationOfMovement);
	}
	FVector TargetLocation = MyCharacter->GetActorLocation();
	TargetLocation += MyCharacter->GetActorForwardVector() * gDistance;
	FVector AttackMovementLocation = FMath::VInterpTo(MyCharacter->GetActorLocation(), TargetLocation, GetWorld()->GetDeltaSeconds(), SpeedOfAttackMovement);
	MyCharacter->SetActorLocation(AttackMovementLocation);
}

void UAttackComponent::SaveLightAttack()
{
	if (bSaveLightAttack)
	{
		// clear variable
		bSaveLightAttack = false;

		TArray<ECharacterStates> CurrentCharacterState;
		CurrentCharacterState.Add(ECharacterStates::Attack);

		if (CharacterState->IsCurrentStateEqualToAny(CurrentCharacterState))
		{
			//Reset Attack If Current State Is Equal To Attacking State
			CharacterState->SetState(ECharacterStates::None);
			LightAttackEvent();

		}
		else
		{
			LightAttackEvent();
		}
	}
	else
	{
		return;
	}
}

void UAttackComponent::ResetLightAttack()
{
	bSaveLightAttack = false;
	LightAttackIndex = 0;
}

void UAttackComponent::SetSaveHeavyAttack(bool bSetSaveHeavyAttack)
{
	bSaveHeavyAttack = bSetSaveHeavyAttack;
}

void UAttackComponent::HeavyAttackEvent()
{
	if (CanAttack())
	{
		ResetLightAttack();
		PerformHeavyAttack(HeavyAttackIndex);
	}
}

void UAttackComponent::PerformHeavyAttack(int AttackIndex)
{
	if (AttackIndex >= HeavyAttackMontages.Num())
	{
		//Reset Heavy Attack Index If Index Is Equal Or Greater Than Length Of Light Attack Sequence
		HeavyAttackIndex = 0;
	}

	if (HeavyAttackMontages.IsValidIndex(HeavyAttackIndex))
	{
		UAnimMontage* Montage = HeavyAttackMontages[HeavyAttackIndex];
		if (IsValid(Montage))
		{
			UAnimMontage* HeavyAttackMontage = Montage;
			CharacterState->SetState(ECharacterStates::Attack);
			AttackMovement(5.0f);
			MyCharacter->PlayAnimMontage(HeavyAttackMontage);
			HeavyAttackIndex++;

			UE_LOG(LogTemp, Error, TEXT("Heavy Attack Index Second: %d"), HeavyAttackIndex);

			if (HeavyAttackIndex >= HeavyAttackMontages.Num())
			{
				//Reset Heavy Attack Index If Index Becomes Equal Or Greater Than Light Attack Sequence
				UE_LOG(LogTemp, Error, TEXT("Is it RESETTING HEavy Index Too early: %d"), HeavyAttackIndex);

				HeavyAttackIndex = 0;
				return;
			}
			else
			{
				return;
			}
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("HEAVY ATTACK MONTAGE INVALID"));
			return;
		}
	}
}

void UAttackComponent::SaveHeavyAttack()
{
	if (bSaveHeavyAttack)
	{
		// clear variable
		bSaveHeavyAttack = false;

		TArray<ECharacterStates> CurrentCharacterState;
		CurrentCharacterState.Add(ECharacterStates::Attack);

		if (CharacterState->IsCurrentStateEqualToAny(CurrentCharacterState))
		{
			//Reset Attack If Current State Is Equal To Attacking State
			CharacterState->SetState(ECharacterStates::None);
			HeavyAttackEvent();

		}
		else
		{
			HeavyAttackEvent();
		}
	}
	else
	{
		return;
	}
}

void UAttackComponent::ResetHeavyAttack()
{
	bSaveHeavyAttack = false;
	HeavyAttackIndex = 0;
}

