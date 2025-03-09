// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NP_FMOD_AudioLatencyTest.generated.h"

class UFMODAudioComponent;
class UFMODEvent;
class ANeonParadigm_GameCharacter;

UCLASS()
class NEONPARADIGM_GAME_API ANP_FMOD_AudioLatencyTest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANP_FMOD_AudioLatencyTest();

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
	UFMODEvent* MusicFMODEvent;

	// Function to handle the timeline beat event
	UFUNCTION()
	void OnTimelineBeat(int32 Bar, int32 Beat, int32 Position, float Tempo, int32 TimeSignatureUpper, int32 TimeSignatureLower);
	UFUNCTION()
	void OnTimelineMarker(FString Name, int32 Position);

private:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Audio", meta = (AllowPrivateAccess = "true"))
	UParticleSystem* TempBPMParticle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Audio", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AActor> TempBPMMusic;


	bool FirstTime;
	int TimesPlayed;
	bool BPM_Started;

	/*
	FMOD::System* System = nullptr; // Initialize this with your FMOD system
	FMOD::Channel* Channel = nullptr; // The channel playing your music
	float SpectrumData[512]; // Array to hold the FFT data
	*/

	float GlobalTempo;

public:

	/*
	UFUNCTION(BlueprintCallable, Category = "Music")
	void SetFirstTimeBool(bool bSetFirstTime);

	UFUNCTION(BlueprintPure)
	float GetGlobalTempo();
	*/

	UFUNCTION(BlueprintImplementableEvent)
	void StartAudioLatTestBarAnim();


};
