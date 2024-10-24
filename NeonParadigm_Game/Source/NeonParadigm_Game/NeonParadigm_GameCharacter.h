// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"

#include "NeonParadigm_GameCharacter.generated.h"

class UAttackComponent;
class UAnimMontage;
class UCharacterStateComponent;
class UDamageComponent;
class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
class ANP_BaseEnemy;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class ANeonParadigm_GameCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

	/** Light Attack Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LightAttackAction;

	/** Heavy Attack Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* HeavyAttackAction;

	/** Dodge Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* DodgeAction;

	/** Target Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* TargetAction;

	/** Parry Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* ParryAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = State, meta = (AllowPrivateAccess = "true"))
	UCharacterStateComponent* CharacterState;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* WeaponMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Attack, meta = (AllowPrivateAccess = "true"))
	UAttackComponent* AttackComp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Damage, meta = (AllowPrivateAccess = "true"))
	UDamageComponent* DamageComp;


private:

	bool bIsDodgeSaved;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attack, meta = (AllowPrivateAccess = "true"))
	UAnimMontage* DodgeMontage;
	bool bEnabledIFrames;
	
	bool DoubleJumped;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attack, meta = (AllowPrivateAccess = "true"))
	UAnimMontage* DoubleJumpMontage;
	float DoubleJumpVelocity;

public:
	ANeonParadigm_GameCharacter();
	void SaveDodge();
	void SetIsDodgeSaved(bool bSetIsDodgeSaved);
	void SetIFrames(bool bEnableIFrames);
	UFUNCTION(BlueprintPure)
	bool IsIFramesEnabled();



public:

	void Target();
	void StartTargeting();
	void EndTarget();
	void RotateToTarget();
	bool GetIsTargeting();

public:
	void StopRotateToTargetTimer();
	void UpdateCharacterRotation();

	void FindSoftLockTarget();
	void SoftTarget();
	void ResetSoftLockTarget();
	AActor* GetSoftTargetActor();

public:
	void StopRotationToSoftTargetTimer();
	void UpdateCharacterSoftRotation();

	void ResetTimelines();

	// Override the TakeDamage function
	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	UFUNCTION()
	void HandleTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);
	void PerformDeath();

	void Parry();
	bool CanParry();
	UFUNCTION(BlueprintCallable)
	void Counter(bool ProjectileCounter);
	void SaveParry();
	void ParryInput();
	UFUNCTION(BlueprintImplementableEvent)
	void ParryProjectile();
	void ResetParry();

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	void LightAttack();

	void HeavyAttack();

	virtual void Jump() override;
	virtual void Landed(const FHitResult& Hit) override;
	//This declares a virtual function named "Landed" that takes an FHitResult structure as a parameter and overrides the default implementation in the AActor class
	void ResetDoubleJump();
	

	void Dodge();
	void DodgeEvent();
	bool CanDodge();
	FRotator GetDesiredRotation() const;


protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay();

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

public:

	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:

	bool bIsTargeting;
	AActor* TargetActor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Targeting, meta = (AllowPrivateAccess = "true"))
	float MaxTargetingDistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Targeting, meta = (AllowPrivateAccess = "true"))
	FVector TargetingOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Targeting, meta = (AllowPrivateAccess = "true"))
	float CameraRotationSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Targeting, meta = (AllowPrivateAccess = "true"))
	float TargetingDistance;

	AActor* SoftTargetActor;
	FTimerHandle TimerForRotationToTarget;
	int DurationOfRotation;

	float SpeedOfRotation;

	FTimerHandle TimerForSoftRotationToTarget;
	int DurationOfSoftRotation;

	float SpeedOfSoftRotation;

	ANP_BaseEnemy* SoftTargetEnemy;

	AActor* LastSoftTargetActor;

	bool bIsParrySaved;

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Stats, meta = (AllowPrivateAccess = "true"))
	float CurrentHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats, meta = (AllowPrivateAccess = "true"))
	float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HitReaction, meta = (AllowPrivateAccess = "true"))
	UAnimMontage* DeathMontage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CounterS, meta = (AllowPrivateAccess = "true"))
	UAnimMontage* ParryMontage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CounterS, meta = (AllowPrivateAccess = "true"))
	UAnimMontage* CounterMontage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CounterS, meta = (AllowPrivateAccess = "true"))
	UAnimMontage* ProjectileCounterMontage;


};

