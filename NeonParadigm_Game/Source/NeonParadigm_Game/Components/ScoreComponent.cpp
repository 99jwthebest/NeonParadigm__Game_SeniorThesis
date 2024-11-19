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

int32 UScoreComponent::CalculateGrade() const
{
	if (TotalScore >= ThresholdSGrade)
	{
		return 3;
	}
	else if (TotalScore >= ThresholdAGrade)
	{
		return 2;
	}
	else if (TotalScore >= ThresholdBGrade)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void UScoreComponent::AddProgress(float Amount)
{
	RankProgress += Amount;

	// Check if we've filled the bar
	if (RankProgress >= 1.0f)
	{
		RankProgress = 0.0f;

		// Move to the next rank
		CurrentRankIndex = FMath::Clamp(CurrentRankIndex + 1, 0, 3);
	}

	UpdateRank();
}

void UScoreComponent::DepleteProgress()
{
	RankProgress -= DepletionRate;
	RankProgress = FMath::Clamp(RankProgress, 0.0f, 1.0f);

	// Check if we've depleted the bar completely
	if (RankProgress == 0.0f && CurrentRankIndex > 0)
	{
		CurrentRankIndex = FMath::Clamp(CurrentRankIndex - 1, 0, 3);
		RankProgress = 1.0f; // Reset to full for the previous rank
	}

	UpdateRank();
}



