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
	PerfectTimingPercent = 0.0f;

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
	TotalScore += ScoreToAdd;
	UE_LOG(LogTemp, Warning, TEXT("SCORE COMP, %d Points!!!!!!!!!!!"), TotalScore);
	AddProgress(ProgressIncreaseRate);
}

float UScoreComponent::GetCurrentScore()
{
	return TotalScore;
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
	TotalHits++;

	if (bIsPerfectHit)
	{
		PerfectHits++;
	}
}

float UScoreComponent::CalculatePerfectTimingBonus()
{
	if (TotalHits == 0) return 0.0f;

	PerfectHitPercentage = (float)PerfectHits / (float)TotalHits;

	CalculatePerfectTimingGrade(PerfectHitPercentage);
	SetPerfectTimingPercentage(PerfectHitPercentage);

	// Example: Bonus = 1000 points for 100% average
	return PerfectHitPercentage * 1000.0f; //
}

void UScoreComponent::SetPerfectTimingPercentage(float PerfectTimingPercentF)
{
	PerfectTimingPercent = PerfectTimingPercentF;
}

float UScoreComponent::GetPerfectTimingPercentage()
{
	return PerfectTimingPercent * 100.0f;
}

int32 UScoreComponent::CalculatePerfectTimingGrade(float PerfectHitPercentageIn) const
{
	// Determine rank based on time thresholds
	if (PerfectHitPercentageIn >= PerfectTimingThresholdSGrade)
	{
		return 3; // S rank
	}
	else if (PerfectHitPercentageIn >= PerfectTimingThresholdAGrade)
	{
		return 2; // A rank
	}
	else if (PerfectHitPercentageIn >= PerfectTimingThresholdBGrade)
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

int32 UScoreComponent::CalculateGrade() const
{
	if (TotalScore >= ThresholdSGrade)
	{
		return 3; // S rank
	}
	else if (TotalScore >= ThresholdAGrade)
	{
		return 2; // A rank
	}
	else if (TotalScore >= ThresholdBGrade)
	{
		return 1; // B rank
	}
	else
	{
		return 0; // C rank
	}
}

float UScoreComponent::CalculateGradeBonus()
{
	if (TotalScore >= ThresholdSGrade)
	{
		return 2000.0f; // S rank
	}
	else if (TotalScore >= ThresholdAGrade)
	{
		return 1500.0f; // A rank
	}
	else if (TotalScore >= ThresholdBGrade)
	{
		return 1000.0f; // B rank
	}
	else
	{
		return 0.0f; // C rank
	}
}

float UScoreComponent::CalculateOverallScore()
{
	// Combine all scores
	float BaseScoreGradeBonus = CalculateGradeBonus();
	float JustTimingBonus = CalculatePerfectTimingBonus();
	float TimeBonus = CalculateClearTimeBonus();
	
	return OverallScore = TotalScore + BaseScoreGradeBonus + JustTimingBonus + TimeBonus;
}

int UScoreComponent::GetOverallScoreGrade()
{
	// Determine final rank based on OverallScore thresholds
	if (OverallScore >= OverallScoreSThreshold)
	{
		return 3; // S rank
	}
	else if (OverallScore >= OverallScoreAThreshold)
	{
		return 2; // A rank
	}
	else if (OverallScore >= OverallScoreBThreshold)
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

FString UScoreComponent::GetFinalRank(int32 FinalScore, int32 MaxPossibleScoreIn)
{
	float Percentage = (float)FinalScore / (float)MaxPossibleScoreIn * 100.0f;

	if (Percentage >= 90.0f) return TEXT("S");
	else if (Percentage >= 75.0f) return TEXT("A");
	else if (Percentage >= 50.0f) return TEXT("B");
	else return TEXT("C");
}

void UScoreComponent::AddEncounterScore(int32 Score)
{
	EncounterScores.Add(Score);
}

void UScoreComponent::FinalizeScore(int32 MaxPossibleScoreIn)
{
	int32 FinalScore = CalculateFinalScore(EncounterScores);
	FString FinalRankLocal = GetFinalRank(FinalScore, MaxPossibleScoreIn);

	UE_LOG(LogTemp, Log, TEXT("Final Score: %d"), FinalScore);
	UE_LOG(LogTemp, Log, TEXT("Final Rank: %s"), *FinalRankLocal);

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

