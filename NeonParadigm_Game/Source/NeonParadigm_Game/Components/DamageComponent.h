// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NeonParadigm_Game/DamageType/NP_DamageType.h"
#include "DamageComponent.generated.h"

class UCharacterStateComponent;
class UNP_DamageType;
class ANeonParadigm_GameCharacter;
class UAnimMontage;
class UScoreComponent;
class UNiagaraSystem;
class UNP_GameInstance;
class ANP_BaseEnemy;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEONPARADIGM_GAME_API UDamageComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDamageComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void DrawWeaponCollision(float End, float Radius, float AmountOfDamage, TSubclassOf<UNP_DamageType> DamageTypeClass);
	//void HandleTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);
	UAnimMontage* GetHitReactionMontage(EDamageTypes DamageType);
	//void PerformDeath();
	void DrawProjectileWeaponCollision();
	void StartTimerProjectileWeaponCollision(float Radius, float AmountOfDamage, TSubclassOf<UNP_DamageType> DamageTypeClass);

	void DrawProjectileWeaponStunCollision(float Radius, float AmountOfDamage, TSubclassOf<UNP_DamageType> DamageTypeClass);
	void DrawEndComboWeaponCollision();
	void StartTimerEndComboWeaponCollision(float Radius, float AmountOfDamage, TSubclassOf<UNP_DamageType> DamageTypeClass);


	void PerfectHitOperations();
	void SpawnRagePickups(FHitResult& HitResult);
	float DifficultyModeDamageModifier();

private:
	
	TArray<AActor*> HitActors;
	ANeonParadigm_GameCharacter* MyCharacter;

	UNP_DamageType* NP_DamageType;

	UCharacterStateComponent* CharacterState;
	UScoreComponent* ScoreComp;

	FTimerHandle TimerForProjectileWeaponCollision;

	float RadiusForProjectileWeapon;
	float AmountOfDamageForProjectileWeapon;
	TSubclassOf<UNP_DamageType> DamageTypeClassForProjectileWeapon;

	int ProjectileCollisionSpawned;

	/*UPROPERTY(EditAnywhere, Category = "Damage")
	TSubclassOf<class UNP_DamageType> DamageTypeClass;*/

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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects, meta = (AllowPrivateAccess = "true"))
	UParticleSystem* ImpactEffect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Effects, meta = (AllowPrivateAccess = "true"))
	UParticleSystem* PerfectParticle;

	UPROPERTY(EditAnywhere, Category = "Effects")
	UNiagaraSystem* WeaponHitEffect;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HitReaction, meta = (AllowPrivateAccess = "true"))
	//UAnimMontage* DeathMontage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stats", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AActor> RagePickup;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound", meta = (AllowPrivateAccess = "true"))
	USoundBase* AttackSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound", meta = (AllowPrivateAccess = "true"))
	float AttackSoundVolumeMultiplier;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound", meta = (AllowPrivateAccess = "true"))
	float AttackSoundDelay;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Damage", meta = (AllowPrivateAccess = "true"))
	FHitResult LastHitResult;

	UNP_GameInstance* GameInstance;

};
