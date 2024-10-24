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
	SpeedOfLaunch = 10.0f;
	DurationOfLaunch = 0;
	bLaunched = false;
	bCanAerialAttack = true;
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
		if (!DetermineDesiredAttack())
		{
			ResetHeavyAttack();
			PerformLightAttack(LightAttackIndex);
		}
	}
	else
	{
		if (CanAerialAttack()) 
		{
			PerformAerialLightAttack(LightAttackIndex);
		}
	}
}

bool UAttackComponent::CanAttack()
{

	TArray<ECharacterStates> CurrentCharacterState;
	CurrentCharacterState.Add(ECharacterStates::Attack);
	CurrentCharacterState.Add(ECharacterStates::Dodge);
	CurrentCharacterState.Add(ECharacterStates::Disabled);
	CurrentCharacterState.Add(ECharacterStates::Death);
	CurrentCharacterState.Add(ECharacterStates::Parry);
	//UE_LOG(LogTemp, Error, TEXT("LIGHT ATTACK MONTAGE INVALID"));
	UE_LOG(LogTemp, Log, TEXT("Is bLaunched False??: %s"), bLaunched ? TEXT("true") : TEXT("false"));
	return !CharacterState->IsCurrentStateEqualToAny(CurrentCharacterState) && !MyCharacter->GetCharacterMovement()->IsFalling() && !bLaunched && !MyCharacter->GetCharacterMovement()->IsFlying();
	
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
		// Find the notify trigger time
		FindNotifyTriggerTime(Montage, FName("NP_AN_TestRhythmPunch"));
		MyCharacter->SetCurrentAnimTimeDelay(GetNotifyTriggerTime());
		MyCharacter->TestRhythmDelayEvent();

		if (IsValid(Montage))
		{
			UAnimMontage* LightAttackMontage = Montage;
			CharacterState->SetState(ECharacterStates::Attack);
			AttackMovement(5.0f);
			MyCharacter->PlayAnimMontage(LightAttackMontage, MyCharacter->GetCurrentAnimPlayRate());
			// Log the impact time for debugging
			UE_LOG(LogTemp, Error, TEXT("Impact Time for Attack %d: %f seconds"), LightAttackIndex, GetNotifyTriggerTime());
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
		// Find the notify trigger time
		FindNotifyTriggerTime(Montage, FName("NP_AN_TestRhythmPunch"));
		MyCharacter->SetCurrentAnimTimeDelay(GetNotifyTriggerTime());
		MyCharacter->TestRhythmDelayEvent();

		if (IsValid(Montage))
		{
			UAnimMontage* HeavyAttackMontage = Montage;
			CharacterState->SetState(ECharacterStates::Attack);
			AttackMovement(5.0f);
			MyCharacter->PlayAnimMontage(HeavyAttackMontage, MyCharacter->GetCurrentAnimTimeDelay());
			// Log the impact time for debugging
			UE_LOG(LogTemp, Error, TEXT("Impact Time for Attack %d: %f seconds"), HeavyAttackIndex, GetNotifyTriggerTime());
			HeavyAttackIndex++;

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

void UAttackComponent::FindNotifyTriggerTime(UAnimMontage* Montage, FName NotifyName)
{
	if (!Montage)
	{
		UE_LOG(LogTemp, Warning, TEXT("Montage is null."));
		return;
	}

	TArray<FAnimNotifyEvent>& NotifyEvents = Montage->Notifies; // gets ref instead copy, & from notifies array "Montage->Notifies"

	for (const FAnimNotifyEvent& NotifyEvent : NotifyEvents)
	{
		if (NotifyEvent.Notify && NotifyEvent.Notify->GetNotifyName() == NotifyName)
		{
			NotifyTriggerTime = NotifyEvent.GetTriggerTime();
			UE_LOG(LogTemp, Log, TEXT("Notify %s triggers at time: %f seconds"), *NotifyName.ToString(), NotifyTriggerTime);
			return;
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("Notify with name %s not found in montage."), *NotifyName.ToString());
}

float UAttackComponent::GetNotifyTriggerTime()
{
	return NotifyTriggerTime;
}

bool UAttackComponent::DetermineDesiredAttack()
{

	MyCharacter->GetMoveInputValue().Y;
	MyCharacter->GetMoveInputValue().X;

	// he is only allowing it when targeting but i need it to work when it is also not targetting. *******

	if (MyCharacter->GetMoveInputValue().Y <= -0.5f) // For Air Begin Attack
	{
		UE_LOG(LogTemp, Warning, TEXT("CAN LAUNCH!!!!"));
		LaunchAttack();
		return bAnythingPlayed = true;
	}

	return bAnythingPlayed = false;

}

void UAttackComponent::LaunchAttack()
{

	if (IsValid(LaunchAnimMontage))
	{
		// Find the notify trigger time
		FindNotifyTriggerTime(LaunchAnimMontage, FName("NP_AN_TestRhythmPunch"));
		MyCharacter->SetCurrentAnimTimeDelay(GetNotifyTriggerTime());
		MyCharacter->TestRhythmDelayEvent();


		CharacterState->SetState(ECharacterStates::Attack);
		//AttackMovement(5.0f); // We probably don't need it!!!! ****** 
		bLaunched = true;
		MyCharacter->PlayAnimMontage(LaunchAnimMontage, MyCharacter->GetCurrentAnimPlayRate());
		//MyCharacter->PlayAnimMontage(LaunchAnimMontage, 1.0f);
		MyCharacter->GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Flying);
		LightAttackIndex = 0;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("NO LAUNCH ANIMATION!!!!"));
		return;
	}


			
}

void UAttackComponent::LaunchPlayerIntoAir()
{
	LaunchLocation = MyCharacter->GetActorLocation() + FVector(0.0f, 0.0f, 300.0f); // May have to lower height for players air launch attack *********

	GetWorld()->GetTimerManager().SetTimer(TimerForLaunchMovement, this, &UAttackComponent::MovePlayerIntoAir , 0.01f, true); // 0.0167f

}

void UAttackComponent::MovePlayerIntoAir()
{
	DurationOfLaunch++;
	UE_LOG(LogTemp, Warning, TEXT("Duration Of Launch: %d"), DurationOfLaunch);

	if (DurationOfLaunch >= 25)  // may have to change this to 50 or more
	{
		StopLaunchMovement();
		DurationOfLaunch = 0;
		UE_LOG(LogTemp, Warning, TEXT("Duration Of Launch Reset: %d"), DurationOfLaunch);
	}
	float Alpha = 0.1f;  // You can adjust this based on how fast you want the rotation
	// Linearly interpolate between the start and launch locations based on progress
	FVector LaunchMovementLocation = FMath::Lerp(MyCharacter->GetActorLocation(), LaunchLocation, Alpha);
	//FVector LaunchMovementLocation = FMath::VInterpTo(MyCharacter->GetActorLocation(), LaunchLocation, GetWorld()->GetDeltaSeconds(), SpeedOfLaunch);
	MyCharacter->SetActorLocation(LaunchMovementLocation);
}

void UAttackComponent::StopLaunchMovement()
{
	GetWorld()->GetTimerManager().ClearTimer(TimerForLaunchMovement); // this might not work
}

bool UAttackComponent::CanAerialAttack()
{
	return bCanAerialAttack && bLaunched;
}

void UAttackComponent::PerformAerialLightAttack(int AttackIndex)
{
	if (AttackIndex >= LightAerialAttackMontages.Num())
	{
		//Reset Light Attack Index If Index Is Equal Or Greater Than Length Of Light Attack Sequence
		LightAttackIndex = 0;
	}

	if (LightAerialAttackMontages.IsValidIndex(LightAttackIndex))
	{
		UAnimMontage* Montage = LightAerialAttackMontages[LightAttackIndex];
		// Find the notify trigger time
		FindNotifyTriggerTime(Montage, FName("NP_AN_TestRhythmPunch"));
		MyCharacter->SetCurrentAnimTimeDelay(GetNotifyTriggerTime());
		MyCharacter->TestRhythmDelayEvent();

		if (IsValid(Montage))
		{
			UAnimMontage* LightAerialAttackMontage = Montage;
			MyCharacter->GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Flying);

			CharacterState->SetState(ECharacterStates::Attack);
			//AttackMovement(5.0f); // we probably don't need this!!!! ********
			//MyCharacter->PlayAnimMontage(LightAerialAttackMontage, 1.0f);
			MyCharacter->PlayAnimMontage(LightAerialAttackMontage, MyCharacter->GetCurrentAnimPlayRate());
			// Log the impact time for debugging
			UE_LOG(LogTemp, Error, TEXT("Impact Time for Attack %d: %f seconds"), LightAttackIndex, GetNotifyTriggerTime());
			LightAttackIndex++;
			if (LightAttackIndex >= LightAerialAttackMontages.Num())
			{
				//Reset Light Attack Index If Index Becomes Equal Or Greater Than Light Attack Sequence
				LightAttackIndex = 0;
				bCanAerialAttack = false;
				return;
			}
			else
			{
				return;
			}
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("LIGHT AERIAL ATTACK MONTAGE INVALID"));
			return;
		}
	}
}

void UAttackComponent::ResetLightAerialAttack()
{
	bCanAerialAttack = true;
}

void UAttackComponent::ResetLaunched()
{
	bLaunched = false;
}

bool UAttackComponent::GetLaunched()
{
	return bLaunched;
}
