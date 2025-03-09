// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonParadigm_Game/FMOD/NP_FMOD_AudioLatencyTest.h"
#include "FMODAudioComponent.h"
//#include "FMODBlueprintStatics.h"
#include "FMODEvent.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

// Sets default values
ANP_FMOD_AudioLatencyTest::ANP_FMOD_AudioLatencyTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create and attach the FMOD Audio Component
	FMODAudioComponent = CreateDefaultSubobject<UFMODAudioComponent>(TEXT("FMODAudioComponent"));
	FMODAudioComponent->SetupAttachment(RootComponent);

	FMODAudioComponent->bEnableTimelineCallbacks = true;

}

// Called when the game starts or when spawned
void ANP_FMOD_AudioLatencyTest::BeginPlay()
{
	Super::BeginPlay();
	

   // BPM_Started = false;
    //FirstTime = true;
    //TimesPlayed = 0;
    
    // Ensure the FMODAudioComponent is valid
    if (FMODAudioComponent)
    {
        if (MusicFMODEvent)
        {
            // Set the FMOD event to trigger
            FMODAudioComponent->SetEvent(MusicFMODEvent);

            // Bind the OnTimelineBeat delegate
            FMODAudioComponent->OnTimelineBeat.AddDynamic(this, &ANP_FMOD_AudioLatencyTest::OnTimelineBeat);
            // Bind the delegate to handle timeline beat events
            FMODAudioComponent->OnTimelineMarker.AddDynamic(this, &ANP_FMOD_AudioLatencyTest::OnTimelineMarker);

            // Start playing the FMOD event
          //FMODAudioComponent->Play();

            UE_LOG(LogTemp, Error, TEXT("We the BEST music! Playing!!"));

        }
    }



}

// Called every frame
void ANP_FMOD_AudioLatencyTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANP_FMOD_AudioLatencyTest::OnTimelineBeat(int32 Bar, int32 Beat, int32 Position, float Tempo, int32 TimeSignatureUpper, int32 TimeSignatureLower)
{
    UE_LOG(LogTemp, Error, TEXT("Timeline Beat Event Triggered: Bar %d, Beat %d, Tempo %f"), Bar, Beat, Tempo);

   /*
    if (Tempo != GlobalTempo && BPM_Started)
    {
        UE_LOG(LogTemp, Warning, TEXT("We the BEST music! Playing!!  BEATERS  TEMPO CHANGERS!!!!"));
        GlobalTempo = Tempo;
        PlayerCharacter->UpdateBPM_Visuals();
    }

    GlobalTempo = Tempo;

    FVector SpawnPoint = PlayerCharacter->GetActorLocation() - FVector(150.0f, 0.0f, 0.0f);
    // Spawn the actor at the beat's location
    UE_LOG(LogTemp, Warning, TEXT("We the BEST music! Playing!!  BEATERS  ju aasdf df  ggg d ftgyrdt TEMPO CHANGERS!!!!"));

    // Turn on the emission when the beat hits
    PlayerCharacter->ToggleOrbEmission();

    GetWorld()->GetTimerManager().SetTimer(TimerForBPM, PlayerCharacter, &ANeonParadigm_GameCharacter::ToggleOrbEmissionOff, 0.2f, true); // 0.0167f

    //UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), TempBPMParticle, SpawnPoint, PlayerCharacter->GetActorRotation(), true, EPSCPoolMethod::None, true);

    M_CurrentTempoDelay = 60 / Tempo;
    PlayerCharacter->SetCurrentTempoDelay(M_CurrentTempoDelay);
    UE_LOG(LogTemp, Warning, TEXT("Timeline Beat Event Triggered: CurrentTempoDelay %f"), M_CurrentTempoDelay);

    UE_LOG(LogTemp, Warning, TEXT("Timeline Beat Event Triggered: Beat Tick: %f"), GetWorld()->GetTimeSeconds());

    PlayerCharacter->SetLastBeatTime(GetWorld()->GetTimeSeconds());
    UE_LOG(LogTemp, Warning, TEXT("A_Timeline Beat Event Triggered: Last Beat Time: %f"), PlayerCharacter->GetLastBeatTime());

    M_NextBeatTime = GetWorld()->GetTimeSeconds() + M_CurrentTempoDelay;
    PlayerCharacter->SetNextBeatTime(M_NextBeatTime);
    UE_LOG(LogTemp, Warning, TEXT("A_Timeline Beat Event Triggered: Next Beat Time: %f"), PlayerCharacter->GetNextBeatTime());

    M_ThirdBeatTime = GetWorld()->GetTimeSeconds() + M_CurrentTempoDelay * 2;
    PlayerCharacter->SetThirdBeatTime(M_ThirdBeatTime);
    UE_LOG(LogTemp, Warning, TEXT("A_Timeline Beat Event Triggered: Third Beat Time: %f"), PlayerCharacter->GetThirdBeatTime());


    if (SpawnedEnemies.Num() > 0)
    {
        SendMusicInfoToEnemies(Tempo);
        // Turn On Walls
    }

    // BPM UI
    //PlayerCharacter->PlayBPM_HalfCirle(Tempo);

    UE_LOG(LogTemp, Warning, TEXT("Timeline Beat Event Triggered: CurrentTempoDelay: Player Character: %f"), PlayerCharacter->GetCurrentTempoDelay());

    if (!BPM_Started)
    {
        PlayerCharacter->BeginBPM_Bar();
        UE_LOG(LogTemp, Warning, TEXT("Timeline Beat Event Triggered: CurrentTempoDelay: Player Character: in What THE Crucke!!! %f"), PlayerCharacter->GetCurrentTempoDelay());



        UE_LOG(LogTemp, Warning, TEXT("Timeline MARKER Event Triggered: Last Beat Time: %f"), PlayerCharacter->GetLastBeatTime());
        BPM_Started = true;
    }
    PlayerCharacter->PlayBPM_BallAnim();
    UE_LOG(LogTemp, Warning, TEXT("Timeline Beat Event Triggered: CurrentTempoDelay: Player Character: in What THE Crucke!!! YEAH YEAH %f"), PlayerCharacter->GetCurrentTempoDelay());

    if (Beat == 4)
    {
        UE_LOG(LogTemp, Error, TEXT("We the BEST music! Playing!!  BEATERS  44444!!!!"));
        PlayerCharacter->SetBPM_SoundBarsHeight();
    }
    if (Beat == 1)
    {
        UE_LOG(LogTemp, Error, TEXT("We the BEST music! Playing!!  BEATERS  111111!!!!"));
        PlayerCharacter->SetBPM_SoundBarsHeight();
    }
    UE_LOG(LogTemp, Error, TEXT("We the BEST music! Playing!!  BEATERS 10 15 15 eyc dhfds8fe8d sd98fd8fd !!!!"));

    // Play attack sound
   // if (AttackSound)
      //  UGameplayStatics::PlaySoundAtLocation(this, AttackSound, PlayerCharacter->GetActorLocation(), AttackSoundVolumeMultiplier, 1.1f, AttackSoundDelay);

   */
}

void ANP_FMOD_AudioLatencyTest::OnTimelineMarker(FString Name, int32 Position)
{
    /*
    // Example marker: if marker name is "StartAction", set the parameter to some value
    if (Name == Markers::SectionA || Name == "SectionB_Transition")
    {
        if (FMODAudioComponent)
        {

            if (FirstTime)
            {
                FName ParameterName = "Music_Transition";
                float UserValue = 0.0f;
                float FinalValue = 0.0f;

                FMODAudioComponent->GetParameterValue(ParameterName, UserValue, FinalValue);

                UE_LOG(LogTemp, Log, TEXT("Parameter: %s | UserValue: %f | FinalValue: %f"), *ParameterName.ToString(), UserValue, FinalValue);
                FMODAudioComponent->SetParameter("Music_Transition", 2.0f);

                FMODAudioComponent->GetParameterValue(ParameterName, UserValue, FinalValue);

                UE_LOG(LogTemp, Log, TEXT("Parameter: %s | UserValue: %f | FinalValue: %f"), *ParameterName.ToString(), UserValue, FinalValue);

                //TimesPlayed++;
            }
            else
            {
                FName ParameterName = "Music_Transition";
                float UserValue = 0.0f;
                float FinalValue = 0.0f;

                FMODAudioComponent->GetParameterValue(ParameterName, UserValue, FinalValue);

                UE_LOG(LogTemp, Log, TEXT("Parameter: %s | UserValue: %f | FinalValue: %f"), *ParameterName.ToString(), UserValue, FinalValue);
                FMODAudioComponent->SetParameter("Music_Transition", 0.0f);

                FMODAudioComponent->GetParameterValue(ParameterName, UserValue, FinalValue);

                UE_LOG(LogTemp, Log, TEXT("Parameter: %s | UserValue: %f | FinalValue: %f"), *ParameterName.ToString(), UserValue, FinalValue);

                //TimesPlayed = 0;
            }

        }

        UE_LOG(LogTemp, Log, TEXT("Marker %s at position %d triggered."), *Name, Position);
    }

    if (Name == "ResetFirstTimeBool")
    {
        if (FMODAudioComponent)
        {
            // TimesPlayed = 0;
            FirstTime = true;
        }

        UE_LOG(LogTemp, Log, TEXT("Marker %s at position %d triggered."), *Name, Position);
    }

    */

    if (Name == "BPM_Start")
    {
        if (FMODAudioComponent)
        {
            StartAudioLatTestBarAnim();
        }

        UE_LOG(LogTemp, Log, TEXT("Marker %s at position %d triggered."), *Name, Position);
    }
}

