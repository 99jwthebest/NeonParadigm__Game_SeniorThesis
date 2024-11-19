// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ScoreComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEONPARADIGM_GAME_API UScoreComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UScoreComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


private:

	int TotalScore;
	int CurrentScore;

	// Grade thresholds
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 ThresholdBGrade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 ThresholdAGrade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 ThresholdSGrade;


	// below for Style Letter Progress Bar
	UPROPERTY(BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
	int32 CurrentRankIndex;

	UPROPERTY(BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
	float RankProgress;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
	float DepletionRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
	float ProgressIncreaseRate;

	FTimerHandle DepletionTimer;


public:

	void Testing();
	void IncrementScore(int ScoreToAdd);
	UFUNCTION(BlueprintPure)
	float GetCurrentScore();
	UFUNCTION(BlueprintCallable, Category = "Score")
	int32 CalculateGrade() const;

	UFUNCTION(BlueprintPure)
	float GetRankProgress();

	void AddProgress(float Amount);
	UFUNCTION(BlueprintCallable)
	void DepleteProgress();

};
