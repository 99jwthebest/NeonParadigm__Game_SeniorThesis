// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttackComponent.generated.h"

class ANeonParadigm_GameCharacter;
class UCharacterStateComponent;
class UAnimMontage;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEONPARADIGM_GAME_API UAttackComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAttackComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SetSaveLightAttack(bool bSetSaveLightAttack);
	void LightAttackEvent();
	UFUNCTION(BlueprintPure)
	bool CanAttack();
	void PerformLightAttack(int AttackIndex);
	void CheckingMontage(const int AttackMontageIndex);
	UFUNCTION(BlueprintCallable)
	void AttackMovement(float Distance);
	void StopAttackMovement();
	void UpdateCharacterLocationAttack();
	// High float values for Effectiveness, e.g. 1000.0f
	UFUNCTION(BlueprintCallable)
	void DodgeMovement(float Distance);
	void StopDodgeMovement();
	void UpdateCharacterLocationDodge();
	FVector AdjustLocationToFloor(FVector TargetLocation);
	void SaveLightAttack();
	void ResetLightAttack();

	void SetSaveHeavyAttack(bool bSetSaveHeavyAttack);
	void HeavyAttackEvent();
	void PerformHeavyAttack(int AttackIndex);
	void SaveHeavyAttack();
	void ResetHeavyAttack();

	void FindNotifyTriggerTime(UAnimMontage* Montage, FName NotifyName);
	float GetNotifyTriggerTime();

	bool DetermineDesiredAttack();
	void LaunchAttack();
	void LaunchPlayerIntoAir();
	void MovePlayerIntoAir();
	void StopLaunchMovement();

	bool CanAerialAttack();
	void PerformAerialLightAttack(int AttackIndex);
	void ResetLightAerialAttack();
	void ResetLaunched();
	UFUNCTION(BlueprintPure)
	bool GetLaunched();

	bool GetSaveLaunchAttack();

	void SetSaveLaunchAttack(bool bSetSaveLaunchAttack);

	void SetNotifyLaunchPassed(bool bNotifyLaunchPassed);
	bool GetNotifyLaunchPassed();

	bool GetSaveLightAttack();

	bool GetSaveHeavyAttack();

	UPROPERTY(VisibleAnywhere)
	ANeonParadigm_GameCharacter* MyCharacter;
private:

	UPROPERTY()
	bool bSaveLightAttack;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = State, meta = (AllowPrivateAccess = "true"))
	UCharacterStateComponent* CharacterState;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attack, meta = (AllowPrivateAccess = "true"))
	TArray<UAnimMontage*> LightAttackMontages;
	int LightAttackIndex;
	FTimerHandle TimerForAttackMovement;
	float SpeedOfAttackMovement;
	float gDistance;
	int DurationOfMovement;

	bool bSaveHeavyAttack;
	int HeavyAttackIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attack, meta = (AllowPrivateAccess = "true"))
	TArray<UAnimMontage*> HeavyAttackMontages;

	float NotifyTriggerTime;

	bool bAnythingPlayed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attack, meta = (AllowPrivateAccess = "true"))
	UAnimMontage* LaunchAnimMontage;

	FTimerHandle TimerForLaunchMovement;
	FVector LaunchLocation;
	float SpeedOfLaunch;
	int DurationOfLaunch;
	bool bLaunched;
	bool bCanAerialAttack;

	bool bSaveLaunchAttack;
	bool bNotifyLaunchAttackPassed;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attack, meta = (AllowPrivateAccess = "true"))
	TArray<UAnimMontage*> LightAerialAttackMontages;

	FOnMontageBlendingOutStarted OnMontageBlendoutStarted;

	void LightAttackBlendedOut(UAnimMontage* AttackMontage, bool bWasInterrupted);
};
