// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonParadigm_Game/Components/ScoreComponent.h"

// Sets default values for this component's properties
UScoreComponent::UScoreComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	CurrentRankIndex = 0;
	RankProgress = 0.0f;
	DepletionRate = 0.01f;
	ProgressIncreaseRate = 0.10f; // Points to progress bar when scoring
	PerfectTimingPercentEncounter = 0.0f;

	// ...
}


// Called when the game starts
void UScoreComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	UE_LOG(LogTemp, Error, TEXT("SCORE COMP, is attached to game mode!!!"));

}


// Called every frame
void UScoreComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UScoreComponent::Testing()
{
	UE_LOG(LogTemp, Warning, TEXT("SCORE COMP, USING FUNCTION FROM SCORE COMP ON GAME MODE!!!!!!!!!!!"));

}

void UScoreComponent::IncrementScore(int ScoreToAdd)
{
	CurrentScore += ScoreToAdd;
	UE_LOG(LogTemp, Warning, TEXT("SCORE COMP, %d Points!!!!!!!!!!!"), CurrentScore);
	AddProgress(ProgressIncreaseRate);
}

float UScoreComponent::GetCurrentScore()
{
	return CurrentScore;
}

int32 UScoreComponent::GetCurrentRankIndex() const
{
	return CurrentRankIndex;
}

float UScoreComponent::GetRankProgress()
{
	return RankProgress;
}

void UScoreComponent::AddProgress(float Amount)
{
	RankProgress += Amount;

	// Check if we've filled the bar
	if (RankProgress >= 1.0f)  // check to see if max rank!!! *****************
	{
		RankProgress = 0.2f; // Set to 20% for the new rank

		// Move to the next rank
		CurrentRankIndex = FMath::Clamp(CurrentRankIndex + 1, 0, 3);
	}
}

void UScoreComponent::DepleteProgress()
{
	RankProgress -= DepletionRate;
	RankProgress = FMath::Clamp(RankProgress, 0.0f, 1.0f);

	if (RankProgress == 0.0f)
	{
		if (CurrentRankIndex > 0)
		{
			CurrentRankIndex = FMath::Clamp(CurrentRankIndex - 1, 0, 3);
			RankProgress = 0.9f; // Set to 90% for the previous rank

			UE_LOG(LogTemp, Warning, TEXT("Rank decreased to: %d"), CurrentRankIndex);
		}
		else
		{
			RankProgress = 0.0f;
			UE_LOG(LogTemp, Warning, TEXT("Rank At lowest rank: %d"), CurrentRankIndex);
		}
	}
}

// Called In BP_Spawner
void UScoreComponent::StartEncounter() 
{
	// Set the starting time to the current game time
	EncounterStartTime = GetWorld()->GetTimeSeconds();
	CurrentCombatEnounters++;
}

void UScoreComponent::EndEncounter()
{
	// Set the ending time to the current game time
	EncounterEndTime = GetWorld()->GetTimeSeconds();

}

void UScoreComponent::TrackHit(bool bIsPerfectHit)
{
	TotalEncounterHits++;

	if (bIsPerfectHit)
	{
		PerfectHits++;
	}
}

float UScoreComponent::CalculatePerfectTimingBonus()
{
	if (TotalEncounterHits == 0) return 0.0f;

	PerfectHitPercentage = (float)PerfectHits / (float)TotalEncounterHits;

	//CalculatePerfectTimingGrade(PerfectHitPercentage);
	SetPerfectTimingPercentage(PerfectHitPercentage);

	// Example: Bonus = 1000 points for 100% average
	return PerfectHitPercentage * 1000.0f; //
}


int32 UScoreComponent::CalculateOverallPerfectTimingBonus()
{
	// Determine rank based on time thresholds
	if (GetOverallPerfectTimingPercentage() >= OverallPerfectTimingThresholdSGrade)
	{
		return 2000.0f; // S rank
	}
	else if (GetOverallPerfectTimingPercentage() >= OverallPerfectTimingThresholdAGrade)
	{
		return 1500.0f; // A rank
	}
	else if (GetOverallPerfectTimingPercentage() >= OverallPerfectTimingThresholdBGrade)
	{
		return 1000.0f; // B rank
	}
	else
	{
		return 0; // C rank
	}
}

void UScoreComponent::SetPerfectTimingPercentage(float PerfectTimingPercentF)
{
	PerfectTimingPercentEncounter = PerfectTimingPercentF;
}

float UScoreComponent::GetPerfectTimingPercentage()
{
	return PerfectTimingPercentEncounter * 100.0f;
}

int32 UScoreComponent::CalculatePerfectTimingGrade(float PerfectHitPercentageIn, int32 SGradeThreshold, int32 AGradeThreshold, int32 BGradeThreshold) const
{
	// Determine rank based on time thresholds
	if (PerfectHitPercentageIn >= SGradeThreshold)
	{
		return 3; // S rank
	}
	else if (PerfectHitPercentageIn >= AGradeThreshold)
	{
		return 2; // A rank
	}
	else if (PerfectHitPercentageIn >= BGradeThreshold)
	{
		return 1; // B rank
	}
	else
	{
		return 0; // C rank
	}
}


float UScoreComponent::CalculateClearTimeBonus()
{
	CurrentEncounterClearTime = EncounterEndTime - EncounterStartTime;

	// Determine rank based on time thresholds
	if (CurrentEncounterClearTime <= TimeThresholdSGrade)
	{
		return 1500.0f; // S rank
	}
	else if (CurrentEncounterClearTime <= TimeThresholdAGrade)
	{
		return 1000.0f; // A rank
	}
	else if (CurrentEncounterClearTime <= TimeThresholdBGrade)
	{
		return 500.0f; // B rank
	}
	else
	{
		return 0.0f; // C rank
	}
}

int32 UScoreComponent::CalculateClearTimingGrade()
{
	CurrentEncounterClearTime = EncounterEndTime - EncounterStartTime;

	// Determine rank based on time thresholds
	if (CurrentEncounterClearTime <= TimeThresholdSGrade)
	{
		return 3; // S rank
	}
	else if (CurrentEncounterClearTime <= TimeThresholdAGrade)
	{
		return 2; // A rank
	}
	else if (CurrentEncounterClearTime <= TimeThresholdBGrade)
	{
		return 1; // B rank
	}
	else
	{
		return 0; // C rank
	}
}

float UScoreComponent::GetClearTime()
{
	return CurrentEncounterClearTime;
}

float UScoreComponent::CalculateOverallClearTimeBonus()
{
	// Determine rank based on time thresholds
	if (OverallClearTime <= OverallTimeThresholdSGrade)
	{
		return 1500.0f; // S rank
	}
	else if (OverallClearTime <= OverallTimeThresholdAGrade)
	{
		return 1000.0f; // A rank
	}
	else if (OverallClearTime <= OverallTimeThresholdBGrade)
	{
		return 500.0f; // B rank
	}
	else
	{
		return 0.0f; // C rank
	}
}

int32 UScoreComponent::CalculateOverallClearTimingGrade()
{
	// Determine rank based on time thresholds
	if (OverallClearTime <= OverallTimeThresholdSGrade)
	{
		return 3; // S rank
	}
	else if (OverallClearTime <= OverallTimeThresholdAGrade)
	{
		return 2; // A rank
	}
	else if (OverallClearTime <= OverallTimeThresholdBGrade)
	{
		return 1; // B rank
	}
	else
	{
		return 0; // C rank
	}
}

int32 UScoreComponent::CalculateGrade(float BaseScore, int32 SGradeThreshold, int32 AGradeThreshold, int32 BGradeThreshold) const
{
	if (BaseScore >= SGradeThreshold)
	{
		return 3; // S rank
	}
	else if (BaseScore >= AGradeThreshold)
	{
		return 2; // A rank
	}
	else if (BaseScore >= BGradeThreshold)
	{
		return 1; // B rank
	}
	else
	{
		return 0; // C rank
	}
}

float UScoreComponent::CalculateGradeBonus(float BaseScore, int32 SGradeThreshold, int32 AGradeThreshold, int32 BGradeThreshold)
{
	if (BaseScore >= SGradeThreshold)
	{
		return BaseScoreGradeBonus = 2000.0f; // S rank
	}
	else if (BaseScore >= AGradeThreshold)
	{
		return BaseScoreGradeBonus = 1500.0f; // A rank
	}
	else if (BaseScore >= BGradeThreshold)
	{
		return BaseScoreGradeBonus = 1000.0f; // B rank
	}
	else
	{
		return BaseScoreGradeBonus = 0.0f; // C rank
	}
}

float UScoreComponent::CalculateOverallEncounterScore()
{
	// Combine all scores
	JustTimingBonus = CalculatePerfectTimingBonus();
	TimeBonus = CalculateClearTimeBonus();
	
	return OverallEncounterScore = CurrentScore + BaseScoreGradeBonus + JustTimingBonus + TimeBonus;
}

int UScoreComponent::GetOverallScoreGrade(int32 OverallScoreType,int32 SGradeThreshold, int32 AGradeThreshold, int32 BGradeThreshold)
{
	// Determine final rank based on OverallScore thresholds
	if (OverallScoreType >= SGradeThreshold)
	{
		return 3; // S rank
	}
	else if (OverallScoreType >= AGradeThreshold)
	{
		return 2; // A rank
	}
	else if (OverallScoreType >= BGradeThreshold)
	{
		return 1; // B rank
	}
	else
	{
		return 0; // C rank
	}
}

bool UScoreComponent::MaxHealthCollectiblePickup()
{
	// Increment the pickup count
	MaxHealthCollectiblesObtained++;

	// Check if the threshold is met
	if (MaxHealthCollectiblesObtained >= MaxHealthCollectiblesThreshold)
	{
		// Reset pickup count
		MaxHealthCollectiblesObtained = 0;

		// Increase the threshold for the next level
		MaxHealthCollectiblesThreshold += 2; // Adjust as needed (e.g., +2 for each level)

		return true;
	}

	return false;
}

bool UScoreComponent::MaxRageCollectiblePickup()
{
	// Increment the pickup count
	MaxRageCollectiblesObtained++;

	// Check if the threshold is met
	if (MaxRageCollectiblesObtained >= MaxRageCollectiblesThreshold)
	{
		// Reset pickup count
		MaxRageCollectiblesObtained = 0;

		// Increase the threshold for the next level
		MaxRageCollectiblesThreshold += 2; // Adjust as needed (e.g., +2 for each level)

		return true;
	}

	return false;
}

int32 UScoreComponent::CalculateFinalScore(const TArray<int32>& Scores)
{
	int32 TotalScoreLocal = 0;
	for (int32 Score : Scores)
	{
		TotalScoreLocal += Score;
	}
	return TotalScoreLocal;
}

FString UScoreComponent::GetFinalRank()
{
	float Percentage = (float)OverallLevelScore / (float)MaxPossibleScore * 100.0f;

	if (Percentage >= 90.0f) return TEXT("S");
	else if (Percentage >= 75.0f) return TEXT("A");
	else if (Percentage >= 50.0f) return TEXT("B");
	else return TEXT("C");
}

void UScoreComponent::AddToOverallLevelScore(int32 Score)
{
	OverallLevelScore += Score;
}

void UScoreComponent::AddToOverallBaseScore(int32 Score)
{
	OverallBaseScore += Score;
}

void UScoreComponent::AddToOverallPerfectTimingPercentage(float Percentage)
{
	PerfectTimingPercentOverall += Percentage;
}

float UScoreComponent::GetOverallPerfectTimingPercentage()
{
	return PerfectTimingPercentOverall / TotalCombatEncounters;
}

void UScoreComponent::AddToOverallClearTime(float ClearTime)
{
	OverallClearTime += ClearTime;
}


void UScoreComponent::FinalizeScore(int32 MaxPossibleScoreIn)
{
	//int32 FinalScore = CalculateFinalScore(StoreEncounterScores);
	//FString FinalRankLocal = GetFinalRank(FinalScore, MaxPossibleScoreIn);

	//UE_LOG(LogTemp, Log, TEXT("Final Score: %d"), FinalScore);
	//UE_LOG(LogTemp, Log, TEXT("Final Rank: %s"), *FinalRankLocal);

	// Additional logic for displaying the rank to the player
}

void UScoreComponent::AddEncounterMaxScore(int32 MaxScore)
{
	MaxPossibleScore += MaxScore;
}

bool UScoreComponent::GetWinEncounterCondition()
{
	if (CurrentCombatEnounters >= TotalCombatEncounters)
	{
		return true;
	}
	
	return false;
}

void UScoreComponent::ResetAllEncounterScores()
{
	CurrentScore = 0;
	PerfectHits = 0;
	TotalEncounterHits = 0;
	CurrentEncounterClearTime = 0;

}

