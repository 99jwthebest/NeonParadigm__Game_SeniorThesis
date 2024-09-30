// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonParadigm_Game/FMOD/NP_FMOD_Music.h"
#include "FMODAudioComponent.h"
#include "FMODEvent.h"
#include "Kismet/GameplayStatics.h"
#include "NeonParadigm_Game/NeonParadigm_GameCharacter.h"


// Sets default values
ANP_FMOD_Music::ANP_FMOD_Music()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create and attach the FMOD Audio Component
	FMODAudioComponent = CreateDefaultSubobject<UFMODAudioComponent>(TEXT("FMODAudioComponent"));
	FMODAudioComponent->SetupAttachment(RootComponent);

    FMODAudioComponent->bEnableTimelineCallbacks = true;
}

// Called when the game starts or when spawned
void ANP_FMOD_Music::BeginPlay()
{
	Super::BeginPlay();
	
    // Ensure the FMODAudioComponent is valid
    if (FMODAudioComponent)
    {
        APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

        if (PlayerController)
            PlayerCharacter = Cast<ANeonParadigm_GameCharacter>(PlayerController->GetCharacter());

        //PlayerCharacter->

        //MusicFMODEvent = LoadObject<UFMODEvent>(nullptr, TEXT("/Game/FMOD/Events/Music/BackgroundMusic.BackgroundMusic"));
        if(MusicFMODEvent)
        {
            // Set the FMOD event to trigger
            FMODAudioComponent->SetEvent(MusicFMODEvent);

            // Bind the OnTimelineBeat delegate
            FMODAudioComponent->OnTimelineBeat.AddDynamic(this, &ANP_FMOD_Music::OnTimelineBeat);

            // Start playing the FMOD event
            FMODAudioComponent->Play();

            UE_LOG(LogTemp, Error, TEXT("We the BEST music! Playing!!"));

        }
    }

}

// Called every frame
void ANP_FMOD_Music::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANP_FMOD_Music::OnTimelineBeat(int32 Bar, int32 Beat, int32 Position, float Tempo, int32 TimeSignatureUpper, int32 TimeSignatureLower)
{
    UE_LOG(LogTemp, Error, TEXT("Timeline Beat Event Triggered: Bar %d, Beat %d, Tempo %f"), Bar, Beat, Tempo);

    UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), TempBPMParticle, PlayerCharacter->GetActorLocation(), PlayerCharacter->GetActorRotation(), true, EPSCPoolMethod::None, true);

    M_CurrentTimeDelay = 60 / Tempo;
    PlayerCharacter->SetCurrentTimeDelay(M_CurrentTimeDelay);
    UE_LOG(LogTemp, Warning, TEXT("Timeline Beat Event Triggered: CurrentTimeDelay %f"), M_CurrentTimeDelay);

    UE_LOG(LogTemp, Warning, TEXT("Timeline Beat Event Triggered: Beat Tick: %f"), GetWorld()->GetTimeSeconds());

    PlayerCharacter->SetLastBeatTime(GetWorld()->GetTimeSeconds());
    UE_LOG(LogTemp, Warning, TEXT("Timeline Beat Event Triggered: Last Beat Time: %f"), PlayerCharacter->GetLastBeatTime());

    M_NextBeatTime = GetWorld()->GetTimeSeconds() + M_CurrentTimeDelay;
    PlayerCharacter->SetNextBeatTime(M_NextBeatTime);
    UE_LOG(LogTemp, Warning, TEXT("Timeline Beat Event Triggered: Next Beat Time: %f"), PlayerCharacter->GetNextBeatTime());


}


