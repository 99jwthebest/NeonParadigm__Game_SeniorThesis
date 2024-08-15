// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonParadigm_Game/Enums/CharacterStateComponent.h"
#include "NeonParadigm_Game/Components/AttackComponent.h"
#include "NeonParadigm_Game/NeonParadigm_GameCharacter.h"



// Sets default values for this component's properties
UCharacterStateComponent::UCharacterStateComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	NoneState = ECharacterStates::None;
	AttackState = ECharacterStates::Attack;
	DodgeState = ECharacterStates::Dodge;
	DeathState = ECharacterStates::Death;
	DisabledState = ECharacterStates::Disabled;

	CurrentState = ECharacterStates::None;

}


// Called when the game starts
void UCharacterStateComponent::BeginPlay()
{
	Super::BeginPlay();

	MyCharacter = Cast<ANeonParadigm_GameCharacter>(GetOwner());
	AttackComp = MyCharacter->FindComponentByClass<UAttackComponent>();

}


// Called every frame
void UCharacterStateComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UCharacterStateComponent::SetState(ECharacterStates NewState)
{

	if(NewState != CurrentState)
		CurrentState = NewState;
}

ECharacterStates UCharacterStateComponent::GetState() const
{
	return CurrentState;
}

bool UCharacterStateComponent::IsCurrentStateEqualToAny(const TArray<ECharacterStates>& StatesToCheck)
{
	UE_LOG(LogTemp, Log, TEXT("CurrentState: %d"), (int32)CurrentState);

	for (ECharacterStates State : StatesToCheck)
	{
		UE_LOG(LogTemp, Log, TEXT("State to Check: %d"), (int32)State);
	}

	return StatesToCheck.Contains(CurrentState);
}

void UCharacterStateComponent::ResetState()
{
	SetState(ECharacterStates::None);
	AttackComp->ResetLightAttack();
	AttackComp->ResetHeavyAttack();
	MyCharacter->ResetTimelines();
	MyCharacter->ResetSoftLockTarget();
	MyCharacter->SetIsDodgeSaved(false);
	
}


