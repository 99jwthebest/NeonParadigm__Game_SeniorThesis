// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NP_Projectile.generated.h"

UCLASS()
class NEONPARADIGM_GAME_API ANP_Projectile : public AActor
{
	GENERATED_BODY()
	
public:	
	ANP_Projectile();

protected:
	virtual void BeginPlay() override;

private:
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditDefaultsOnly, Category = "Projectile")
	class USphereComponent* CollisionSphere;

	UPROPERTY(EditDefaultsOnly, Category = "Projectile")
	class UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(EditDefaultsOnly, Category = "Projectile")
	float StartingVelocity = 500.0f;
};
