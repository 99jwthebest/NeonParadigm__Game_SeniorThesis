// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonParadigm_Game/Enemies/NP_EnemySpawner.h"
#include "Components/BoxComponent.h"

// Sets default values
ANP_EnemySpawner::ANP_EnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	// Create the box component
	EnemySpawnBoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));

	RootComponent = EnemySpawnBoxCollision;

	// Bind the overlap event
	EnemySpawnBoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ANP_EnemySpawner::OnBoxOverlapBegin);
}

// Called when the game starts or when spawned
void ANP_EnemySpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANP_EnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANP_EnemySpawner::OnBoxOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlapped with"));

	// Check if the OtherActor is valid and not this actor
	if (OtherActor && (OtherActor != this))
	{
		// Do something when overlap begins, e.g., print the name of the overlapping actor
		UE_LOG(LogTemp, Warning, TEXT("Overlapped with %s"), *OtherActor->GetName());
	}
}

