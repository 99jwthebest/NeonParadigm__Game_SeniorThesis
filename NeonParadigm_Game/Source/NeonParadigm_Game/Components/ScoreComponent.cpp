// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonParadigm_Game/Components/ScoreComponent.h"

// Sets default values for this component's properties
UScoreComponent::UScoreComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

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

}

float UScoreComponent::GetCurrentScore()
{
	return TotalScore;
}


