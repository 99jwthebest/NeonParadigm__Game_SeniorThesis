// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonParadigm_Game/FMOD/NP_FMOD_Music.h"
#include "FMODAudioComponent.h"
//#include "FMODBlueprintStatics.h"
#include "FMODEvent.h"
#include "Kismet/GameplayStatics.h"
#include "NeonParadigm_Game/NeonParadigm_GameCharacter.h"
#include "NeonParadigm_Game/TestActor.h"
#include "TimerManager.h"
#include "NeonParadigm_Game/Enemies/NP_BaseEnemy.h"

namespace Markers {
    FString SectionA = TEXT("SectionA_Transition");
    FString SectionC = TEXT("SectionC_Transition");
    FString SectionD = TEXT("SectionD_Transition");
    FString SectionE = TEXT("SectionE_Transition");
    FString SectionF = TEXT("SectionF_Transition");
}

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
	
    BPM_Started = false;
    FirstTime = true;
    TimesPlayed = 0;
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
            // Bind the delegate to handle timeline beat events
            FMODAudioComponent->OnTimelineMarker.AddDynamic(this, &ANP_FMOD_Music::OnTimelineMarker);

            // Start playing the FMOD event
            //FMODAudioComponent->Play();
            FMODAudioComponent->Play();

            //GetWorld()->GetTimerManager().SetTimerForNextTick(this, &ANP_FMOD_Music::TryPlay); // 0.0167f
            GetWorld()->GetTimerManager().SetTimer(TimerForFMODtoPlay, this, &ANP_FMOD_Music::TryPlay, .01f, false);
            /*         FTimerDelegate TimerDelegate;
            TimerDelegate.BindUObject(FMODAudioComponent, &UFMODAudioComponent::Activate, false);
            GetWorld()->GetTimerManager().SetTimerForNextTick(TimerDelegate);*/ // 0.0167f

            UE_LOG(LogTemp, Error, TEXT("We the BEST music! Playing!!"));

            UE_LOG(LogTemp, Error, TEXT("We the BEST music! Playing!!"));
            UE_LOG(LogTemp, Log, TEXT("We the BEST music! Playing!?!? huh %s"), FMODAudioComponent->IsPlaying() ? TEXT("true") : TEXT("false"));
            UE_LOG(LogTemp, Log, TEXT("We the BEST music! Playing!?!? huh Paused %s"), FMODAudioComponent->GetPaused() ? TEXT("true") : TEXT("false"));
            UE_LOG(LogTemp, Log, TEXT("We the BEST music! Playing!?!? huh Length %d"), FMODAudioComponent->GetLength());
            UE_LOG(LogTemp, Log, TEXT("We the BEST music! Playing!?!? huh Timeline Position %d"), FMODAudioComponent->GetTimelinePosition());


            //FMODAudioComponent->Play();



        }
    }


    //FindAllEnemies();
}

// Called every frame
void ANP_FMOD_Music::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANP_FMOD_Music::OnTimelineBeat(int32 Bar, int32 Beat, int32 Position, float Tempo, int32 TimeSignatureUpper, int32 TimeSignatureLower)
{
    UE_LOG(LogTemp, Error, TEXT("Timeline Beat Event Triggered: Bar %d, Beat %d, Tempo %f"), Bar, Beat, Tempo);

    if (Tempo != GlobalTempo && BPM_Started)
    {
        UE_LOG(LogTemp, Warning, TEXT("We the BEST music! Playing!!  BEATERS  TEMPO CHANGERS!!!!"));
        GlobalTempo = Tempo;
        PlayerCharacter->UpdateBPM_Visuals();
        M_CurrentTempoDelay = 60 / Tempo;
        PlayerCharacter->SetCurrentTempoDelay(M_CurrentTempoDelay);
        PlayerCharacter->PlayBPM_FlipBook();

    }

    GlobalTempo = Tempo;

    FVector SpawnPoint = PlayerCharacter->GetActorLocation() - FVector(150.0f, 0.0f, 0.0f);
    // Spawn the actor at the beat's location
    UE_LOG(LogTemp, Warning, TEXT("We the BEST music! Playing!!  BEATERS  YAY AHHHHHH TEMPO CHANGERS!!!!"));

    // Turn on the emission when the beat hits
    PlayerCharacter->ToggleOrbEmission();

    //GetWorld()->GetTimerManager().SetTimer(TimerForBPM, PlayerCharacter, &ANeonParadigm_GameCharacter::ToggleOrbEmissionOff, 0.2f, false); // 0.0167f

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

        PlayerCharacter->PlayBPM_FlipBook();

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
    if (AttackSound)
        UGameplayStatics::PlaySoundAtLocation(this, AttackSound, PlayerCharacter->GetActorLocation(), AttackSoundVolumeMultiplier, 1.1f, AttackSoundDelay);

}

void ANP_FMOD_Music::OnTimelineMarker(FString Name, int32 Position)
{
    // Example marker: if marker name is "StartAction", set the parameter to some value
    if (Name == Markers::SectionA || Name == "SectionB_Transition" || 
        Name == Markers::SectionC || Name == Markers::SectionD ||
        Name == Markers::SectionE || Name == Markers::SectionF)
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


    if (Name == "BPM_Start")
    {
        if (FMODAudioComponent)
        {
           
        }

        UE_LOG(LogTemp, Log, TEXT("Marker %s at position %d triggered."), *Name, Position);
    }
}

void ANP_FMOD_Music::TryPlay()
{
    FMOD_STUDIO_PLAYBACK_STATE PlayBackState = FMOD_STUDIO_PLAYBACK_STOPPED;
    if (!FMODAudioComponent->StudioInstance)
    {
        FMOD::Studio::EventDescription* EventDesc = IFMODStudioModule::Get().GetEventDescription(FMODAudioComponent->Event);
        EventDesc->createInstance(&FMODAudioComponent->StudioInstance);
    }
    
    FMOD_RESULT Result = FMODAudioComponent->StudioInstance->getPlaybackState(&PlayBackState);
    if (Result == FMOD_RESULT::FMOD_ERR_INVALID_HANDLE)
    {
        GetWorld()->GetTimerManager().SetTimerForNextTick(this, &ANP_FMOD_Music::TryPlay);
        return;
    }

    FMODAudioComponent->Play();

    UE_LOG(LogTemp, Error, TEXT("We the BEST music! Playing!!"));
    UE_LOG(LogTemp, Log, TEXT("We the BEST music! Playing!?!? huh %s"), FMODAudioComponent->IsPlaying() ? TEXT("true") : TEXT("false"));
    UE_LOG(LogTemp, Log, TEXT("We the BEST music! Playing!?!? huh Paused %s"), FMODAudioComponent->GetPaused() ? TEXT("true") : TEXT("false"));
    UE_LOG(LogTemp, Log, TEXT("We the BEST music! Playing!?!? huh Length %d"), FMODAudioComponent->GetLength());
    UE_LOG(LogTemp, Log, TEXT("We the BEST music! Playing!?!? huh Timeline Position %d"), FMODAudioComponent->GetTimelinePosition());

}


void ANP_FMOD_Music::SendMusicInfoToEnemies(float TempoOfCurrentSong)
{
    for (int i = 0; i < SpawnedEnemies.Num(); i++) 
    {
        /*if (!SpawnedEnemies[i])
        {
            return;
        }*/

        if (!SpawnedEnemies[i])
        {
            SpawnedEnemies.RemoveAt(i);
            UE_LOG(LogTemp, Warning, TEXT("Total Enemies Found: %d"), SpawnedEnemies.Num());

            continue;
        }

        // Check if the enemy is dead and remove if true
        if (SpawnedEnemies[i]->GetState() == ECharacterStates::Death)
        {
            UE_LOG(LogTemp, Warning, TEXT("Enemy %s is dead and removed from the array"), *SpawnedEnemies[i]->GetName());
            SpawnedEnemies.RemoveAt(i);
            UE_LOG(LogTemp, Error, TEXT("Total Enemies Found: %d"), SpawnedEnemies.Num());
            if (SpawnedEnemies.Num() <= 2)
                PlayerCharacter->TimerCameraDistance(500.0f);

            if (SpawnedEnemies.Num() <= 0)
            {
                for (AActor* BlockingActor : BlockingActors)  // **** this code is obviously ugly!!!!!
                {
                    if (BlockingActor)
                    {
                        // Disable or hide the blocking actor (e.g., turn off collision, hide actor)
                        BlockingActor->SetActorHiddenInGame(true);
                        BlockingActor->SetActorEnableCollision(false);
                        UE_LOG(LogTemp, Warning, TEXT("Disabled blocking actor: %s"), *BlockingActor->GetName());
                    }
                }
                PlayerCharacter->ToggleCombatStyleGrade();
                PlayerCharacter->EndEnemyEncounter();
            }

            continue; // Skip further processing for this enemy
        }

        //UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), TempBPMParticle, SpawnPoint, PlayerCharacter->GetActorRotation(), true, EPSCPoolMethod::None, true);

        M_CurrentTempoDelay = 60 / TempoOfCurrentSong;
        SpawnedEnemies[i]->SetCurrentTempoDelay(M_CurrentTempoDelay);
        UE_LOG(LogTemp, Warning, TEXT("ENEMY Timeline Beat Event Triggered: CurrentTempoDelay %f"), M_CurrentTempoDelay);

        UE_LOG(LogTemp, Warning, TEXT("ENEMY Timeline Beat Event Triggered: Beat Tick: %f"), GetWorld()->GetTimeSeconds());

        SpawnedEnemies[i]->SetLastBeatTime(GetWorld()->GetTimeSeconds());
        UE_LOG(LogTemp, Warning, TEXT("ENEMY Timeline Beat Event Triggered: Last Beat Time: %f"), PlayerCharacter->GetLastBeatTime());

        M_NextBeatTime = GetWorld()->GetTimeSeconds() + M_CurrentTempoDelay;
        SpawnedEnemies[i]->SetNextBeatTime(M_NextBeatTime);
        UE_LOG(LogTemp, Warning, TEXT("ENEMY Timeline Beat Event Triggered: Next Beat Time: %f"), PlayerCharacter->GetNextBeatTime());

        M_ThirdBeatTime = GetWorld()->GetTimeSeconds() + M_CurrentTempoDelay * 2;
        SpawnedEnemies[i]->SetThirdBeatTime(M_ThirdBeatTime);
        UE_LOG(LogTemp, Warning, TEXT("ENEMY Timeline Beat Event Triggered: Third Beat Time: %f"), PlayerCharacter->GetThirdBeatTime());
        
    }
}

void ANP_FMOD_Music::AddSpawnedEnemy(ANP_BaseEnemy* SpawnedEnemy)
{
    if (SpawnedEnemy)
    {
        // Add the spawned enemy to the array
        SpawnedEnemies.Add(SpawnedEnemy);

        // Log that the enemy has been added
        UE_LOG(LogTemp, Warning, TEXT("Enemy %s added to FMOD Music"), *SpawnedEnemy->GetName());

        UE_LOG(LogTemp, Warning, TEXT("Total Enemies Found: %d"), SpawnedEnemies.Num());
     
    }
}

void ANP_FMOD_Music::SetFirstTimeBool(bool bSetFirstTime)
{
    FirstTime = bSetFirstTime;

}

void ANP_FMOD_Music::SetWallBlockActors(const TArray<AActor*>& WallBlockActors)
{
    BlockingActors = WallBlockActors;

    // Log that blocking actors have been set
    for (AActor* BlockingActor : BlockingActors)
    {
        if (BlockingActor)
        {
            UE_LOG(LogTemp, Warning, TEXT("Blocking Actor %s added to FMOD Music"), *BlockingActor->GetName());
        }
    }
    /*if (Channel)
    {
        Channel->getSpectrum(SpectrumData, 512, 0, FMOD_DSP_FFT_WINDOW_HANNING);
    }*/
}

float ANP_FMOD_Music::GetGlobalTempo()
{
    return GlobalTempo;
}

int32 ANP_FMOD_Music::GetNumOfSpawnedEnemies()
{
    return SpawnedEnemies.Num();
}


