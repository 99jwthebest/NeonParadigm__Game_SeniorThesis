// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NP_FMOD_Music.generated.h"

class UFMODAudioComponent;
class UFMODEvent;

UCLASS()
class NEONPARADIGM_GAME_API ANP_FMOD_Music : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANP_FMOD_Music();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public:
	// FMOD Audio Component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Audio")
	UFMODAudioComponent* FMODAudioComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audio")
	UFMODEvent* MusicFMODEvent;

	// Function to handle the timeline beat event
	UFUNCTION()
	void OnTimelineBeat(int32 Bar, int32 Beat, int32 Position, float Tempo, int32 TimeSignatureUpper, int32 TimeSignatureLower);

};
