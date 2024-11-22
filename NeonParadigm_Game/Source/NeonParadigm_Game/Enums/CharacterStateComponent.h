// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CharacterStateComponent.generated.h"


UENUM(BlueprintType)
enum class ECharacterStates : uint8
{
	None, //UMETA(DisplayName = "Option 1"),
	Attack, //UMETA(DisplayName = "Option 2"),
	Dodge, //UMETA(DisplayName = "Option 3"),
	Death, //UMETA(DisplayName = "Option 4"),
	Disabled, //UMETA(DisplayName = "Option 5"),
	Parry,
};

class UAttackComponent;
class ANeonParadigm_GameCharacter;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEONPARADIGM_GAME_API UCharacterStateComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCharacterStateComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


private:

	ECharacterStates PreviousState;
	UPROPERTY(BlueprintReadWrite, Category = State, meta = (AllowPrivateAccess = "true"))
	ECharacterStates CurrentState;

	ECharacterStates NoneState;
	ECharacterStates AttackState;
	ECharacterStates DodgeState;
	ECharacterStates DeathState;
	ECharacterStates DisabledState;
	ECharacterStates ParryState;

	ANeonParadigm_GameCharacter* MyCharacter;
	UAttackComponent* AttackComp;

	bool bOnLandReset;


public:
	UFUNCTION()
	void SetState(ECharacterStates NewState);

	UFUNCTION(BlueprintPure, Category = "State")
	ECharacterStates GetState() const;
	bool IsCurrentStateEqualToAny(const TArray<ECharacterStates>& StatesToCheck);

	void ResetState();
	bool GetOnLandReset();
	void SetOnLandReset(bool SetOnlandReset);
};
