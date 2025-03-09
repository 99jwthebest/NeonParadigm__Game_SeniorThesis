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
	int CurrentScore;
	//int TotalScore;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
	int32 OverallBaseScore;

	// Perfect Timing Score
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 PerfectHits; // Tracks the number of perfect hits
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 TotalEncounterHits; // Tracks the total number of hits
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 TotalLevelHits; // Tracks the total number of hits

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
		// Time thresholds
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 OverallTimeThresholdBGrade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 OverallTimeThresholdAGrade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 OverallTimeThresholdSGrade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		float CurrentEncounterClearTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		float OverallClearTime;

	// Pefect Timing thresholds
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 PerfectTimingThresholdBGrade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 PerfectTimingThresholdAGrade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 PerfectTimingThresholdSGrade;
		// Pefect Timing thresholds
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 OverallPerfectTimingThresholdBGrade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 OverallPerfectTimingThresholdAGrade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 OverallPerfectTimingThresholdSGrade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		float PerfectHitPercentage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		float PerfectTimingPercentEncounter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		float PerfectTimingPercentOverall;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 OverallLevelScore;
	// Final Rank and Overall Score
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 OverallEncounterScore;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 OverallEncounterScoreBThreshold;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 OverallEncounterScoreAThreshold;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 OverallEncounterScoreSThreshold;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 OverallLevelScoreBThreshold;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 OverallLevelScoreAThreshold;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 OverallLevelScoreSThreshold;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 FinalRank; // 0 = C, 1 = B, 2 = A, 3 = S

	// Grade thresholds
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 ThresholdBGrade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 ThresholdAGrade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 ThresholdSGrade;
		// Grade thresholds
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 OverallBaseScoreThresholdBGrade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 OverallBaseScoreThresholdAGrade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 OverallBaseScoreThresholdSGrade;

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

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
	//TArray<int32> SetScoreEncounters; // Set ScoreThreshold For Encounter scores for each encounter
	//TArray<int32> StoreEncounterScores; // Store scores for each encounter
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 MaxPossibleScore = 0; // Sum of all maximum scores for encounters
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 CurrentCombatEnounters;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score", meta = (AllowPrivateAccess = "true"))
		int32 TotalCombatEncounters;


	float BaseScoreGradeBonus;
	float JustTimingBonus;
	float TimeBonus;

public:

	void Testing();
	void IncrementScore(int ScoreToAdd);
	UFUNCTION(BlueprintPure)
		float GetCurrentScore();
	UFUNCTION(BlueprintPure, Category = "Score")
		int32 CalculateGrade(float BaseScore, int32 SGradeThreshold, int32 AGradeThreshold, int32 BGradeThreshold) const;
	UFUNCTION(BlueprintPure)
		float CalculateGradeBonus(float BaseScore, int32 SGradeThreshold, int32 AGradeThreshold, int32 BGradeThreshold);

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
	UFUNCTION(BlueprintPure)
		int32 CalculateOverallPerfectTimingBonus();

		void SetPerfectTimingPercentage(float PerfectHitPercentageF);
	UFUNCTION(BlueprintPure)
		float GetPerfectTimingPercentage();
	UFUNCTION(BlueprintPure)
		int32 CalculatePerfectTimingGrade(float PerfectHitPercentageIn, int32 SGradeThreshold, int32 AGradeThreshold, int32 BGradeThreshold) const;

	UFUNCTION(BlueprintPure)
		float CalculateClearTimeBonus();
	UFUNCTION(BlueprintPure)
		int32 CalculateClearTimingGrade();
	UFUNCTION(BlueprintPure)
		float GetClearTime();
	UFUNCTION(BlueprintPure)
		float CalculateOverallClearTimeBonus();
	UFUNCTION(BlueprintPure)
		int32 CalculateOverallClearTimingGrade();
	UFUNCTION(BlueprintPure)
		float CalculateOverallEncounterScore();
	UFUNCTION(BlueprintPure)
		int GetOverallScoreGrade(int32 OverallScoreType, int32 SGradeThreshold, int32 AGradeThreshold, int32 BGradeThreshold);


	UFUNCTION(BlueprintPure)
		bool MaxHealthCollectiblePickup();
	UFUNCTION(BlueprintPure)
		bool MaxRageCollectiblePickup();

	int32 CalculateFinalScore(const TArray<int32>& Scores);

	FString GetFinalRank();

	void AddToOverallLevelScore(int32 Score);

	void AddToOverallBaseScore(int32 Score);

	void AddToOverallPerfectTimingPercentage(float Percentage);

	UFUNCTION(BlueprintPure)
	float GetOverallPerfectTimingPercentage();

	void AddToOverallClearTime(float ClearTime);

	void FinalizeScore(int32 MaxPossibleScoreIn);

	void AddEncounterMaxScore(int32 MaxScore);

	bool GetWinEncounterCondition();

	void ResetAllEncounterScores();

};
