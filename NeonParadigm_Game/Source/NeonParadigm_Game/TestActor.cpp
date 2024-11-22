// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActor.h"

// Sets default values
ATestActor::ATestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	Super::BeginPlay();


    Mesh = FindComponentByClass<UStaticMeshComponent>();

}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATestActor::ToggleEmission()
{

    if (IsValid(Mesh))
    {

        // Check if the material is present in slot 0
        CurrentMaterial = Mesh->GetMaterial(0);

        if (!CurrentMaterial)
        {
            UE_LOG(LogTemp, Warning, TEXT("No material found on StaticMeshComponent."));
            return;
        }

        DynMaterial = Mesh->CreateAndSetMaterialInstanceDynamic(0);

        if (DynMaterial)
        {
            //UE_LOG(LogTemp, Error, TEXT("Mother FUCKER EMITTTIN ASTUDSUDFFU Playing!!"));
            float EmissiveValue = 20.0f;  // Turn on or off the emission
            DynMaterial->SetScalarParameterValue(TEXT("EmissiveIntensity"), EmissiveValue);
        }
    }
}

void ATestActor::ToggleEmissionOff()
{
    Mesh = FindComponentByClass<UStaticMeshComponent>();

    if (IsValid(Mesh))
    {
        DynMaterial = Mesh->CreateAndSetMaterialInstanceDynamic(0);

        if (DynMaterial)
        {
            float EmissiveValue = 0.0f;  // Turn on or off the emission
            DynMaterial->SetScalarParameterValue(TEXT("EmissiveIntensity"), EmissiveValue);
        }
    }
}
