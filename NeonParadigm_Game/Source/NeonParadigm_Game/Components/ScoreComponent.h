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

	// Base score tracking
	int TotalScore;
	int CurrentScore;

	// Perfect Timing Score
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 PerfectHits; // Tracks the number of perfect hits
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 TotalHits; // Tracks the total number of hits

	// Time Efficiency
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		float EncounterStartTime; // Time when the encounter started
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		float EncounterEndTime; // Time when the encounter ended

	// Time thresholds
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 TimeThresholdBGrade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 TimeThresholdAGrade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 TimeThresholdSGrade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		float CurrentEncounterClearTime;

	// Pefect Timing thresholds
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 PerfectTimingThresholdBGrade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 PerfectTimingThresholdAGrade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 PerfectTimingThresholdSGrade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		float PerfectHitPercentage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		float PerfectTimingPercent;


	// Final Rank and Overall Score
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 OverallScore;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 OverallScoreBThreshold;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 OverallScoreAThreshold;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 OverallScoreSThreshold;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 FinalRank; // 0 = C, 1 = B, 2 = A, 3 = S

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


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 MaxHealthCollectiblesObtained;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 MaxHealthCollectiblesThreshold = 2;       // The initial threshold for increasing max health

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 MaxRageCollectiblesObtained;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 MaxRageCollectiblesThreshold = 2;       // The initial threshold for increasing max rage

public:

	void Testing();
	void IncrementScore(int ScoreToAdd);
	UFUNCTION(BlueprintPure)
		float GetCurrentScore();
	UFUNCTION(BlueprintCallable, Category = "Score")
	int32 CalculateGrade() const;
	UFUNCTION(BlueprintPure)
		float CalculateGradeBonus();

	UFUNCTION(BlueprintPure)
		int32 GetCurrentRankIndex() const;

	UFUNCTION(BlueprintPure)
		float GetRankProgress();

	void AddProgress(float Amount);
	UFUNCTION(BlueprintCallable)
		void DepleteProgress();

	UFUNCTION(BlueprintCallable)
		void StartEncounter();
	UFUNCTION(BlueprintCallable)
		void EndEncounter();

	void TrackHit(bool bIsPerfectHit);

	UFUNCTION(BlueprintPure)
		float CalculatePerfectTimingBonus();
	void SetPerfectTimingPercentage(float PerfectHitPercentageF);
	UFUNCTION(BlueprintPure)
		float GetPerfectTimingPercentage();
	UFUNCTION(BlueprintPure)
		int32 CalculatePerfectTimingGrade(float PerfectHitPercentageIn) const;

	UFUNCTION(BlueprintPure)
		float CalculateClearTimeBonus();
	UFUNCTION(BlueprintPure)
		int32 CalculateClearTimingGrade();
	UFUNCTION(BlueprintPure)
		float GetClearTime();
	UFUNCTION(BlueprintPure)
		float CalculateOverallScore();
	UFUNCTION(BlueprintPure)
		int GetOverallScoreGrade();


	UFUNCTION(BlueprintPure)
		bool MaxHealthCollectiblePickup();
	UFUNCTION(BlueprintPure)
		bool MaxRageCollectiblePickup();
};
