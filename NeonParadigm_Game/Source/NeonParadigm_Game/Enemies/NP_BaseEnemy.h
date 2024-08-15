// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NeonParadigm_Game/Enums/CharacterStateComponent.h"
#include "NeonParadigm_Game/DamageType/NP_DamageType.h"
#include "NP_BaseEnemy.generated.h"

class UNP_DamageType;
class UAnimMontage;
class UAttackComponent;
class UWidgetComponent;
UCLASS()
class NEONPARADIGM_GAME_API ANP_BaseEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANP_BaseEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


private:

	FTimerHandle TimerForAttackMovement;
	float SpeedOfAttackMovement;
	float gDistance;
	int DurationOfMovement;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Stats, meta = (AllowPrivateAccess = "true"))
	float CurrentHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats, meta = (AllowPrivateAccess = "true"))
	float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HitReaction, meta = (AllowPrivateAccess = "true"))
	UAnimMontage* HR_Right;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HitReaction, meta = (AllowPrivateAccess = "true"))
	UAnimMontage* HR_Left;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HitReaction, meta = (AllowPrivateAccess = "true"))
	UAnimMontage* HR_Middle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HitReaction, meta = (AllowPrivateAccess = "true"))
	UAnimMontage* HR_Knockdown;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HitReaction, meta = (AllowPrivateAccess = "true"))
	UAnimMontage* HR_Knockback;

private:

	ECharacterStates PreviousState;
	UPROPERTY(BlueprintReadWrite, Category = State, meta = (AllowPrivateAccess = "true"))
	ECharacterStates CurrentState;

	ECharacterStates NoneState;
	ECharacterStates AttackState;
	ECharacterStates DodgeState;
	ECharacterStates DeathState;
	ECharacterStates DisabledState;

	ANP_BaseEnemy* MyCharacter;
	UAttackComponent* AttackComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Death, meta = (AllowPrivateAccess = "true"))
	UAnimMontage* DeathMontage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* WeaponMesh;

private:

	// The widget component
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI", meta = (AllowPrivateAccess = "true"))
	UWidgetComponent* HealthBarWidget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI", meta = (AllowPrivateAccess = "true"))
	UWidgetComponent* LockOnWidget;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void AttackMovement(float Distance);
	void StopAttackMovement();
	void UpdateCharacterLocation();

	UFUNCTION()
	void HandleTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);

	UAnimMontage* GetHitReactionMontage(EDamageTypes DamageType);
	void PerformDeath();

public:
	void UpdateCharacterRotationWhenHit(AActor* DamageCauserCharacter);


public:
	UFUNCTION(BlueprintCallable, Category = "State")
	void SetState(ECharacterStates NewState);
	ECharacterStates GetState() const;
	UFUNCTION(BlueprintPure, Category = "State")
	bool IsCurrentStateEqualToAny(const TArray<ECharacterStates>& StatesToCheck);

	void ResetState();

public:

	void OnTargeted();
	void EndTarget();

};
