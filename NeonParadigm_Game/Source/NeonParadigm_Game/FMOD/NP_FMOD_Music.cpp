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
            FMODAudioComponent->Play();

            UE_LOG(LogTemp, Error, TEXT("We the BEST music! Playing!!"));

        }
    }

    //ActorInfo->OwnerActor.Get()
    AActor* PlayerActor = PlayerCharacter->GetOwner();

    FActorSpawnParameters SpawnParams;
    FVector SpawnPoint = PlayerCharacter->GetActorLocation() - FVector(80.0f, 100.0f, 0.0f) + FVector(0.0f, 0.0f, 110.0f);
    FRotator Rotation = PlayerActor->GetActorRotation();      // Rotation
    TempActor = GetWorld()->SpawnActor<ATestActor>(TempBPMMusic, SpawnPoint, Rotation, SpawnParams);

    // Attach the spawned actor to the player character
    FAttachmentTransformRules AttachRules(EAttachmentRule::KeepWorld, true);

    // Attach to the player character's root component (or any specific component)
    TempActor->AttachToComponent(PlayerCharacter->GetRootComponent(), AttachRules);

    UE_LOG(LogTemp, Log, TEXT("Spawned actor and attached to player."));

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

    FVector SpawnPoint = PlayerCharacter->GetActorLocation() - FVector(150.0f, 0.0f, 0.0f);
    // Spawn the actor at the beat's location

    if (IsValid(TempActor))
    {
        // Turn on the emission when the beat hits
        TempActor->ToggleEmission();

        GetWorld()->GetTimerManager().SetTimer(TimerForBPM, TempActor, &ATestActor::ToggleEmissionOff, 0.2f, true); // 0.0167f
    }

    //UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), TempBPMParticle, SpawnPoint, PlayerCharacter->GetActorRotation(), true, EPSCPoolMethod::None, true);

    M_CurrentTempoDelay = 60 / Tempo;
    PlayerCharacter->SetCurrentTempoDelay(M_CurrentTempoDelay);
    UE_LOG(LogTemp, Warning, TEXT("Timeline Beat Event Triggered: CurrentTempoDelay %f"), M_CurrentTempoDelay);

    UE_LOG(LogTemp, Warning, TEXT("Timeline Beat Event Triggered: Beat Tick: %f"), GetWorld()->GetTimeSeconds());

    PlayerCharacter->SetLastBeatTime(GetWorld()->GetTimeSeconds());
    UE_LOG(LogTemp, Warning, TEXT("Timeline Beat Event Triggered: Last Beat Time: %f"), PlayerCharacter->GetLastBeatTime());

    M_NextBeatTime = GetWorld()->GetTimeSeconds() + M_CurrentTempoDelay;
    PlayerCharacter->SetNextBeatTime(M_NextBeatTime);
    UE_LOG(LogTemp, Warning, TEXT("Timeline Beat Event Triggered: Next Beat Time: %f"), PlayerCharacter->GetNextBeatTime());

    M_ThirdBeatTime = GetWorld()->GetTimeSeconds() + M_CurrentTempoDelay * 2;
    PlayerCharacter->SetThirdBeatTime(M_ThirdBeatTime);
    UE_LOG(LogTemp, Warning, TEXT("Timeline Beat Event Triggered: Third Beat Time: %f"), PlayerCharacter->GetThirdBeatTime());


    if (SpawnedEnemies.Num() > 0)
    {
        SendMusicInfoToEnemies(Tempo);
    }
}

void ANP_FMOD_Music::OnTimelineMarker(FString Name, int32 Position)
{
    // Example marker: if marker name is "StartAction", set the parameter to some value
    if (Name == Markers::SectionA || Name == "SectionB_Transition")
    {
        if (FMODAudioComponent)
        {

            if (TimesPlayed < 2)
            {
                FName ParameterName = "Music_Transition"; 
                float UserValue = 0.0f;
                float FinalValue = 0.0f;

                FMODAudioComponent->GetParameterValue(ParameterName, UserValue, FinalValue);

                UE_LOG(LogTemp, Log, TEXT("Parameter: %s | UserValue: %f | FinalValue: %f"), *ParameterName.ToString(), UserValue, FinalValue);
                FMODAudioComponent->SetParameter("Music_Transition", 2.0f);

                FMODAudioComponent->GetParameterValue(ParameterName, UserValue, FinalValue);

                UE_LOG(LogTemp, Log, TEXT("Parameter: %s | UserValue: %f | FinalValue: %f"), *ParameterName.ToString(), UserValue, FinalValue);

                TimesPlayed++;
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

                TimesPlayed = 0;
            }

        }

        UE_LOG(LogTemp, Log, TEXT("Marker %s at position %d triggered."), *Name, Position);
    }

    if (Name == "ResetFirstTimeBool")
    {
        if (FMODAudioComponent)
        {
            TimesPlayed = 0;
        }

        UE_LOG(LogTemp, Log, TEXT("Marker %s at position %d triggered."), *Name, Position);
    }
}

void ANP_FMOD_Music::FindAllEnemies()
{
    TArray<AActor*> FoundEnemies;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ANP_BaseEnemy::StaticClass(), FoundEnemies);

    // Log the total number of enemies found
    UE_LOG(LogTemp, Warning, TEXT("Total Enemies Found: %d"), FoundEnemies.Num());

    // You can now iterate over FoundEnemies or cast them to ANP_BaseEnemy if needed
    for (AActor* Actor : FoundEnemies)
    {
        ANP_BaseEnemy* Enemy = Cast<ANP_BaseEnemy>(Actor);
        if (Enemy)
        {
            //Enemy->TestRhythmDelayEvent();
            //Enemy->SendMusicInfoToEnemies(,Enemy);
        }
    }
}

void ANP_FMOD_Music::SendMusicInfoToEnemies(float TempoOfCurrentSong)
{
    for (int i = 0; i < SpawnedEnemies.Num(); i++) 
    {
        if (!SpawnedEnemies[i])
            return;

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
        //SpawnedEnemies[0]->TestRhythmDelayEvent(); *****
        // Log that the enemy has been added
        UE_LOG(LogTemp, Warning, TEXT("Enemy %s added to FMOD Music"), *SpawnedEnemy->GetName());

        UE_LOG(LogTemp, Warning, TEXT("Total Enemies Found: %d"), SpawnedEnemies.Num());

    }
}

