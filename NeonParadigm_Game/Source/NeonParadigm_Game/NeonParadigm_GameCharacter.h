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

	/** Projectile Weapon Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* ProjectileWeaponAction;

	/** Projectile Weapon Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* ProjectileWeaponStunAction;
	
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
	

	int32 PerfectDodgeCount = 0; // Tracks consecutive perfect dodges
	float DodgePushMultiplier = 1.0f; // Increases push distance
	float DodgeCooldownEndTime = 0.0f; // Time when dodging becomes available again
	const int32 MaxPerfectDodges = 3; // Maximum consecutive dodges
	const float CooldownDodgeDuration = 1.0f; // Beat delay (in seconds) before dodge resets


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
	bool IsTargetValid(ANP_BaseEnemy* Target);

public:
	void StopRotationToSoftTargetTimer();
	void UpdateCharacterSoftRotation();

	void ResetTimelines();

	UFUNCTION()
	void HandleTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);
	void PerformDeath();
	UFUNCTION(BlueprintImplementableEvent)
	void SpawnLoseMenu();

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
	FVector2D LookAxisVector;

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

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	float DodgeCooldownProgress;

public:

	void ResetDodgeCountAndMultiplier();


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
	FVector2D GetLookInputValue();


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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Targeting, meta = (AllowPrivateAccess = "true"))
	float MaxSoftTargetDistance = 500.0f;

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Stats, meta = (AllowPrivateAccess = "true"))
	float CurrentHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats, meta = (AllowPrivateAccess = "true"))
	float MaxHealth;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Rage", meta = (AllowPrivateAccess = "true"))
	float CurrentRage = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rage", meta = (AllowPrivateAccess = "true"))
	float MaxRage;
	FTimerHandle RageDepletionTimerHandle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rage", meta = (AllowPrivateAccess = "true"))
	float RageDepletionRate = 1.0f;  // Decrease rage every second
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rage", meta = (AllowPrivateAccess = "true"))
	float RageDepletionAmount = 10.0f;  // Amount to reduce per tick
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rage", meta = (AllowPrivateAccess = "true"))
	float RageActivationThreshold = 50.0f;  

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
	float PlayRateUIBallAnim;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Test, meta = (AllowPrivateAccess = "true"))
	UAnimMontage* TestRhythmMontage;


public:

	void SetCurrentTempoDelay(float CurTempoDelay);
	UFUNCTION(BlueprintPure)
	float GetCurrentTempoDelay();

	void SetCurrentAnimTimeDelay(float CurAnimTimeDelay);
	float GetCurrentAnimTimeDelay();

	void SetLastBeatTime(float fLastBeatTime);
	float GetLastBeatTime();
	void SetNextBeatTime(float fNextBeatTime);
	float GetNextBeatTime();
	void SetThirdBeatTime(float fThirdBeatTime);
	float GetThirdBeatTime();

	UFUNCTION(BlueprintPure)
	float GetCurrentUIBallAnimPlayRate();

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
	void DepleteRage();


private:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Attack, meta = (AllowPrivateAccess = "true"))
	UScoreComponent* ScoreComp;
	bool bPerfectBeatHit;


public:

	void SetPerfectBeatHit(bool bPerfectHit);
	UFUNCTION(BlueprintCallable)
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


public:

	UFUNCTION(BlueprintCallable)
	void AddToCurrentRage(float RageToAdd);
	UFUNCTION(BlueprintCallable)
	void IncreaseMaxRage(float AmountToAdd);
	float GetCurrentRage();
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateRageBarEvent();
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateMaxRageBarEvent();

	UFUNCTION(BlueprintCallable)
	void AddToCurrentHealth(float HealthToAdd);
	UFUNCTION(BlueprintCallable)
	void IncreaseMaxHealth(float AmountToAdd);
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateHealthBarEvent();
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateMaxHealthBarEvent();
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateScoreEvent();
	UFUNCTION(BlueprintImplementableEvent)
	void ToggleCombatStyleGrade();
	UFUNCTION(BlueprintImplementableEvent)
	void PlayBPM_BallAnim();
	UFUNCTION(BlueprintImplementableEvent)
	void PlayBPM_HalfCirle(float CurrentTempo);
	UFUNCTION(BlueprintImplementableEvent)
	void BeginBPM_Bar();
	UFUNCTION(BlueprintImplementableEvent)
	void TogglePerfectHitTextBox();
	UFUNCTION(BlueprintImplementableEvent)
	void ToggleEncounterResults();
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateProjectileWeaponBarEvent();
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateProjectileWeaponStunBarEvent();
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateDodgeBarEvent();
	UFUNCTION(BlueprintImplementableEvent)
	void SpawnWinMenuEvent();

public:


	//FORCEINLINE 
	/** Returns ScoreComp SubObject **/
	FORCEINLINE class UScoreComponent* GetScoreComponent() const { return ScoreComp; }

	UFUNCTION(BlueprintCallable)
	void StartEnemyEncounter();
	void EndEnemyEncounter();


private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attack, meta = (AllowPrivateAccess = "true"))
	UAnimMontage* ProjectileWeaponMontage;
	bool bIsShootSaved;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attack, meta = (AllowPrivateAccess = "true"))
	UAnimMontage* ProjectileWeaponStunMontage;

public:

	void ProjectileWeapon();
	void ProjectileWeaponEvent();
	bool CanShoot();

	void SetIsShootSaved(bool bSetIsShootSaved);

	void SaveShoot();




private:

	bool bIsStunSaved;

	int32 ProjectileStunShot = 0; // Tracks consecutive 
	//float PerfectProjectileMultiplier = 1.0f; // Increases push distance
	float ProjectileStunCooldownEndTime = 0.0f; // Time when dodging becomes available again
	const int32 MaxStunProjectiles = 1; // Maximum consecutive 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	float CooldownProjectileStunDuration = 15.0f; // Beat delay (in seconds) before dodge resets
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	float ProjectileStunCooldownProgress;
	FTimerHandle TimerForProjectileStunCooldown;

public:


	void ProjectileWeaponStun();
	void ProjectileWeaponStunEvent();
	bool CanStun();

	void SetIsStunSaved(bool bSetIsStunSaved);

	void SaveStun();

	float GetProjectileStunCooldownEndTime();

	float GetProjectileStunCooldownDuration();

	void StartTimerForProjectileStunCooldown();

	void CalculateTimeForProjectileStunWeaponCooldown();


private:

	FTimerHandle TimerForCameraDistanceChange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
		float DefaultCameraBoomLength;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
		float CameraBoomLength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
		float DefaultCameraFOV;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
		float TargetCameraFOV;
		FTimerHandle TimerForFOVChange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
		float DefaultCameraFOVSpeedChange;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		float TargetCameraFOVSpeedChange;

public:


	void TimerCameraDistance(float CameraBoomLengthF);
	
	void ChangeCameraDistance();

	void TimerCameraFOV(float TargetFOVValue, float TargetFOVSpeedChangeValue);

	void ChangeCameraFOV();
	float GetDefaultCameraFOV();

	float GetDefaultCameraFOVSpeedChange();


private:

	int32 ProjectileShot = 0; // Tracks consecutive 
	//float PerfectProjectileMultiplier = 1.0f; // Increases push distance
	float ProjectileCooldownEndTime = 0.0f; // Time when dodging becomes available again
	const int32 MaxProjectiles = 3; // Maximum consecutive 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Projectile, meta = (AllowPrivateAccess = "true"))
		float CooldownProjectileDuration = 2.0f; // Beat delay (in seconds) before dodge resets
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Projectile, meta = (AllowPrivateAccess = "true"))
		float ProjectileCooldownProgress;
	FTimerHandle TimerForProjectileCooldown;


	int32 PerfectProjectileCount = 0; // Tracks consecutive perfect dodges
	float PerfectProjectileMultiplier = 1.0f; // Increases push distance
	float PerfectProjectileCooldownEndTime = 0.0f; // Time when dodging becomes available again
	const int32 MaxPerfectProjectiles = 3; // Maximum consecutive dodges
	const float CooldownPerfectProjectileDuration = 1.0f; // Beat delay (in seconds) before dodge resets



public:

	float GetProjectileCooldownEndTime();
	float GetProjectileCooldownDuration();
	void StartTimerForProjectileCooldown();
	void CalculateTimeForProjectileWeaponCooldown();

	void StartTimerForDodgeCooldown();

	void CalculateTimeForDodgeCooldown();

	void EnableCameraAutoRotate();
	void CheckForTargetInCameraView();

private:

	AActor* CameraTargetActor;
	FTimerHandle CameraDelayTimerHandle;
	bool bCanRotateBack = true; // Starts true, becomes false during input

	FTimerHandle TimerDodgeCooldown;

	FTimerHandle CheckForTargetInCamViewTimerHandle;


public:

	void TurnOnMagnetizedDodge();
	void TurnOffMagnetizedDodge();

	void ToggleEmissivityEmergenLights();
	void ToggleEmissivityEmergenLightsOff();


private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	bool bIsMagnetizeDodgeActive;
	float MagnetizationRadius = 500.0f;  // Magnetization effect radius
	FTimerHandle TimerForEmissiveEmergenLights;
};

