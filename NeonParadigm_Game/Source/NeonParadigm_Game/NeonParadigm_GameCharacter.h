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
class UScoreComponent;
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

	/** Rage Mode Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* RageAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = State, meta = (AllowPrivateAccess = "true"))
	UCharacterStateComponent* CharacterState;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* WeaponMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Attack, meta = (AllowPrivateAccess = "true"))
	UAttackComponent* AttackComp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Damage, meta = (AllowPrivateAccess = "true"))
	UDamageComponent* DamageComp;

	/** BPM Orb Spring Arm */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* BPM_OrbSpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BPM_OrbMesh;

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

	FVector2D MovementVector;

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

	FVector2D GetMoveInputValue();

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


private:

	float CurrentTempoDelay;
	float CurrentAnimTimeDelay;
	float LastBeatTime;
	float NextBeatTime;
	float ThirdBeatTime;
	float DelayFromLastBeat;
	float DelayFromNextBeat;
	float TotalTimeDelayToNextBeat;
	float DelayFromThirdBeat;
	float TotalTimeDelayToThirdBeat;
	float PlayRateForAnimMontages;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Test, meta = (AllowPrivateAccess = "true"))
	UAnimMontage* TestRhythmMontage;


public:

	void SetCurrentTempoDelay(float CurTempoDelay);
	float GetCurrentTempoDelay();

	void SetCurrentAnimTimeDelay(float CurAnimTimeDelay);
	float GetCurrentAnimTimeDelay();

	void SetLastBeatTime(float fLastBeatTime);
	float GetLastBeatTime();
	void SetNextBeatTime(float fNextBeatTime);
	float GetNextBeatTime();
	void SetThirdBeatTime(float fThirdBeatTime);
	float GetThirdBeatTime();

	float GetCurrentAnimPlayRate();

	void TestRhythmDelayEvent();



private:

	bool bRageSaved;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rage", meta = (AllowPrivateAccess = "true"))
	UParticleSystem* RageEmitter;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rage", meta = (AllowPrivateAccess = "true"))
	UAnimMontage* RageAnim;

	class UParticleSystemComponent* RageParticleComponent;
	bool bRage;
	FTimerHandle RageTimerHandle;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rage", meta = (AllowPrivateAccess = "true"))
	float RageDuration;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rage", meta = (AllowPrivateAccess = "true"))
	class UMaterialInterface* RageOverlayMaterial;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rage", meta = (AllowPrivateAccess = "true"))
	class UMaterialInterface* InitialRageOverlayMaterial;

public:

	void Rage();
	void RageEvent();
	void RageComplete();
	void EndRage();
	bool CanRage();
	bool IsRaging();


private:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Attack, meta = (AllowPrivateAccess = "true"))
	UScoreComponent* ScoreComp;
	bool bPerfectBeatHit;


public:

	void SetPerfectBeatHit(bool bPerfectHit);
	bool IsPerfectBeatHit();

private:
	float SoftTargetLerpAmt = 0.f;
	class UTimelineComponent* TimelineComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Targeting")
	UCurveFloat* SoftTargetCurve;

	UFUNCTION()
	void SoftTargetingTimelineUpdated(float Alpha);

public:

	void ToggleOrbEmission();
	void ToggleOrbEmissionOff();
	UStaticMeshComponent* GetBPM_OrbMesh();

private:
	UMaterialInterface* CurrentOrbMaterial;
	UMaterialInstanceDynamic* DynOrbMaterial;

};

