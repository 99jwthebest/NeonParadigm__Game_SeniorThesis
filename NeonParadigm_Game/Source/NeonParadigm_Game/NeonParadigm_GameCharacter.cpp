// Copyright Epic Games, Inc. All Rights Reserved.

#include "NeonParadigm_GameCharacter.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/TimelineComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "NeonParadigm_Game/Enums/CharacterStateComponent.h"
#include "NeonParadigm_Game/Components/AttackComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "NeonParadigm_Game/Components/DamageComponent.h"
#include "NeonParadigm_Game/Enemies/NP_BaseEnemy.h"
#include "Kismet/KismetSystemLibrary.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"
#include "NeonParadigm_Game/Components/ScoreComponent.h"


DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// ANeonParadigm_GameCharacter

ANeonParadigm_GameCharacter::ANeonParadigm_GameCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
		
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera1"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)

	CharacterState = CreateDefaultSubobject<UCharacterStateComponent>(TEXT("Character State Component"));

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Weapon Mesh"));

	AttackComp = CreateDefaultSubobject<UAttackComponent>(TEXT("Attack Component"));

	DoubleJumpVelocity = 1000.0f;

	DamageComp = CreateDefaultSubobject<UDamageComponent>(TEXT("Damage Component"));
	
	ScoreComp = CreateDefaultSubobject<UScoreComponent>(TEXT("Score Component"));

	MaxTargetingDistance = 2500.0f;

	SpeedOfRotation = 10.0f;
	SpeedOfSoftRotation = 20.0f;  
	// this speed controls how fast the character rotates in soft rotation ******* Maybe you can let player rotate character with this soft rotation to give more control or maybe to see if it's better. so far, this makes character more magnetic to the enemy.

	bIsTargeting = false;

	// SetCurrentAnimTimeDelay(1.0f);  just for testing purposes
	TimelineComponent = CreateDefaultSubobject<UTimelineComponent>("Timeline Component");

	BPM_OrbSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("BPM Orb Spring Arm"));
	BPM_OrbSpringArm->SetupAttachment(RootComponent);
	BPM_OrbSpringArm->TargetArmLength = 200.0f;  // Temp Length, Needs to be tweaked depending on user needs.
	BPM_OrbSpringArm->bUsePawnControlRotation = true;  // Rotate the arm based on the controller
	BPM_OrbSpringArm->bEnableCameraLag = true;
	BPM_OrbSpringArm->bEnableCameraRotationLag = true;
	// Default Setting speeds, Extremely low, probably need to change.
	BPM_OrbSpringArm->CameraLagSpeed = 1.0f;
	BPM_OrbSpringArm->CameraRotationLagSpeed = 1.0f;

	// Create BPM Music Orb
	BPM_OrbMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BPM Orb Mesh"));
	BPM_OrbMesh->SetupAttachment(BPM_OrbSpringArm, USpringArmComponent::SocketName);

	MaxRage = 100.0f;

}

void ANeonParadigm_GameCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	DynOrbMaterial = BPM_OrbMesh->CreateAndSetMaterialInstanceDynamic(0);

	if (SoftTargetCurve)
	{
		FOnTimelineFloat TimelineCallback;
		TimelineCallback.BindUFunction(this, FName("SoftTargetingTimelineUpdated"));

		TimelineComponent->AddInterpFloat(SoftTargetCurve, TimelineCallback);
	}

	// Attach the StaticMesh to the SkeletalMesh (Parent) at a specified socket
	WeaponMesh->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, TEXT("WeaponSocket"));

	//Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}

	CurrentHealth = MaxHealth;

	OnTakeAnyDamage.AddDynamic(this, &ANeonParadigm_GameCharacter::HandleTakeAnyDamage);

}

void ANeonParadigm_GameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (bIsTargeting && TargetActor->IsValidLowLevel())
	{
		// Attempt to cast TargetActor to NP_BaseEnemy
		ANP_BaseEnemy* Enemy = Cast<ANP_BaseEnemy>(TargetActor);
		if(Enemy)
		{
			//UE_LOG(LogTemp, Warning, TEXT("Successfully casted to NP_BaseEnemy and called SomeEnemyFunction."));
			if (Enemy->GetState() != ECharacterStates::Death)
			{
				// If The Distance Between the player and Enemy is greater than MaxTargetingDistance Then Stop Targeting.
				if (GetDistanceTo(TargetActor) < MaxTargetingDistance)
				{
					FRotator currentRotation = GetController()->GetControlRotation();

					FVector TargetVector = TargetActor->GetActorLocation() - TargetingOffset;

					FRotator TargetRot(UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), TargetVector));

					float RDeltaTime = GetWorld()->GetDeltaSeconds();

					FRotator NewRotation = FMath::RInterpTo(currentRotation, TargetRot, RDeltaTime, CameraRotationSpeed);

					GetController()->SetControlRotation(NewRotation);
					UE_LOG(LogTemp, Warning, TEXT("rotating Camera"));

				}
				else
				{
					UE_LOG(LogTemp, Error, TEXT("TARGET ACTOR TOO FAR."));
				}
			}
			else
			{
				EndTarget();
			}
		}
		//else
		//{
		//	// The cast failed, handle accordingly
		//	UE_LOG(LogTemp, Warning, TEXT("Failed to cast TargetActor to NP_BaseEnemy."));
		//}
	}
	else if(bIsTargeting) // this might be the fix of constant null object message
	{
		EndTarget();
	}
}


//////////////////////////////////////////////////////////////////////////
// Input

void ANeonParadigm_GameCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ANeonParadigm_GameCharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ANeonParadigm_GameCharacter::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ANeonParadigm_GameCharacter::Look);
		
		// Light Attack
		EnhancedInputComponent->BindAction(LightAttackAction, ETriggerEvent::Triggered, this, &ANeonParadigm_GameCharacter::LightAttack);

		// Heavy Attack
		EnhancedInputComponent->BindAction(HeavyAttackAction, ETriggerEvent::Triggered, this, &ANeonParadigm_GameCharacter::HeavyAttack);

		// Dodge
		EnhancedInputComponent->BindAction(DodgeAction, ETriggerEvent::Triggered, this, &ANeonParadigm_GameCharacter::Dodge);
	
		// Target
		EnhancedInputComponent->BindAction(TargetAction, ETriggerEvent::Triggered, this, &ANeonParadigm_GameCharacter::Target);

		// Parry
		EnhancedInputComponent->BindAction(ParryAction, ETriggerEvent::Triggered, this, &ANeonParadigm_GameCharacter::ParryInput);
		
		// Rage
		EnhancedInputComponent->BindAction(RageAction, ETriggerEvent::Triggered, this, &ANeonParadigm_GameCharacter::Rage);

	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void ANeonParadigm_GameCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	MovementVector = Value.Get<FVector2D>();
	
	if (GetCharacterMovement()->IsFlying())  // this is causing trace for softtarget to not work!!! ***********
		return;

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
		/*const FInputActionInstance& Instance;
		Instance.Get*/
	}
}

FVector2D ANeonParadigm_GameCharacter::GetMoveInputValue()
{
	return MovementVector;
}

void ANeonParadigm_GameCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();
	
	if (Controller != nullptr)
	{
		if (!bIsTargeting)
		{
			// add yaw and pitch inphealut to controller
			AddControllerYawInput(LookAxisVector.X);
			AddControllerPitchInput(LookAxisVector.Y);
		}
	}
}

void ANeonParadigm_GameCharacter::LightAttack()
{
	AttackComp->SetSaveHeavyAttack(false);
	
	TArray<ECharacterStates> CurrentCharacterState;
	CurrentCharacterState.Add(ECharacterStates::Attack);

	if (CharacterState->IsCurrentStateEqualToAny(CurrentCharacterState))
	{
		//If Current State is Equal to Attack Then Save The Input
		UE_LOG(LogTemp, Warning, TEXT("Light ATTACKING!!!!!!!!"));
		AttackComp->SetSaveLightAttack(true);
	}
	else
	{
		//If Current State is Not Attacking Then Attempt To Attack
		UE_LOG(LogTemp, Error, TEXT("Cant ATTack!!!!"));
		AttackComp->LightAttackEvent();
	}

}

void ANeonParadigm_GameCharacter::HeavyAttack()
{
	AttackComp->SetSaveLightAttack(false);

	TArray<ECharacterStates> CurrentCharacterState;
	CurrentCharacterState.Add(ECharacterStates::Attack);

	if (CharacterState->IsCurrentStateEqualToAny(CurrentCharacterState))
	{
		//If Current State is Equal to Attack Then Save The Input
		UE_LOG(LogTemp, Warning, TEXT("Heavy ATTACKING!!!!!!!!"));
		AttackComp->SetSaveHeavyAttack(true);
	}
	else
	{
		//If Current State is Not Attacking Then Attempt To Attack
		UE_LOG(LogTemp, Error, TEXT("Cant ATTack!!!!"));
		AttackComp->HeavyAttackEvent();
	}
}

void ANeonParadigm_GameCharacter::Jump()
{

	TArray<ECharacterStates> CurrentCharacterState;
	CurrentCharacterState.Add(ECharacterStates::None);

	if (CharacterState->IsCurrentStateEqualToAny(CurrentCharacterState))
	{
		if (GetCharacterMovement()->IsFalling() && !DoubleJumped)
		{
			DoubleJumped = true;
			PlayAnimMontage(DoubleJumpMontage);
			LaunchCharacter(FVector(0.0f, 0.0f, DoubleJumpVelocity), false, true);
		}
		else
		{
			Super::Jump();
		}
	}
	else
	{
		Super::StopJumping();
	}

}

void ANeonParadigm_GameCharacter::Landed(const FHitResult& Hit)   // OnLanded blueprint is called Landed in C++
{
	Super::Landed(Hit);

	ResetDoubleJump();
	if (CharacterState->GetOnLandReset())  // On Landed Reset
	{
		GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Walking);
		CharacterState->SetOnLandReset(false);
		AttackComp->ResetLaunched();
		CharacterState->ResetState();
	}
	AttackComp->ResetLaunched();  

}

void ANeonParadigm_GameCharacter::ResetDoubleJump()
{
	DoubleJumped = false;
}

void ANeonParadigm_GameCharacter::Dodge()
{
	TArray<ECharacterStates> CurrentCharacterState;
	CurrentCharacterState.Add(ECharacterStates::Attack);
	CurrentCharacterState.Add(ECharacterStates::Dodge);

	if (CharacterState->IsCurrentStateEqualToAny(CurrentCharacterState))
	{
		bIsDodgeSaved = true;
	}
	else
	{
		DodgeEvent();
	}
}

void ANeonParadigm_GameCharacter::DodgeEvent()  //   ******  Have to look over this for the perfect timing, i might be causing some glitches, maybe ********
{
	if (CanDodge())
	{
		AttackComp->ResetLightAttack();
		AttackComp->ResetHeavyAttack();

		if (GetDesiredRotation() != FRotator(0.0f, 0.0f, 0.0f))
		{
			SetActorRotation(GetDesiredRotation());
			/*CharacterState->SetState(ECharacterStates::Dodge);
			PlayAnimMontage(DodgeMontage);*/
		}

		CharacterState->SetState(ECharacterStates::Dodge);
		TestRhythmDelayEvent();
		if (bPerfectBeatHit)
		{
			DamageComp->PerfectHitOperations();
		}
		PlayAnimMontage(DodgeMontage);
		AttackComp->AttackMovement(15.0f); // maybe increase to 20 max
	}
}

bool ANeonParadigm_GameCharacter::CanDodge()
{
	TArray<ECharacterStates> CurrentCharacterState;
	CurrentCharacterState.Add(ECharacterStates::Attack);
	CurrentCharacterState.Add(ECharacterStates::Dodge);
	CurrentCharacterState.Add(ECharacterStates::Disabled);
	CurrentCharacterState.Add(ECharacterStates::Death);
	CurrentCharacterState.Add(ECharacterStates::Parry);
	//UE_LOG(LogTemp, Error, TEXT("LIGHT ATTACK MONTAGE INVALID"));

	return !CharacterState->IsCurrentStateEqualToAny(CurrentCharacterState); //&& !GetCharacterMovement()->IsFalling();
}

FRotator ANeonParadigm_GameCharacter::GetDesiredRotation() const
{

	if (GetCharacterMovement()->GetLastInputVector() != FVector(0.0f, 0.0f, 0.0f))
	{
		FRotator RotFromXVector = UKismetMathLibrary::MakeRotFromX(GetCharacterMovement()->GetLastInputVector());
		return RotFromXVector;
	}

	return FRotator(0.0f, 0.0f, 0.0f);
}

void ANeonParadigm_GameCharacter::SetIsDodgeSaved(bool bSetIsDodgeSaved)
{
	bIsDodgeSaved = bSetIsDodgeSaved;
}

void ANeonParadigm_GameCharacter::SetIFrames(bool bEnableIFrames)
{
	bEnabledIFrames = bEnableIFrames;
}

bool ANeonParadigm_GameCharacter::IsIFramesEnabled()
{
	return bEnabledIFrames;
}

void ANeonParadigm_GameCharacter::Target()
{
	if (!bIsTargeting) 
	{
		StartTargeting();
	}
	else
	{
		EndTarget();
	}
}

void ANeonParadigm_GameCharacter::StartTargeting()
{

	// Trace start and end points
	FVector StartVec = FollowCamera->GetComponentLocation();
	FVector MultiplyVec = FollowCamera->GetForwardVector() * TargetingDistance;
	FVector EndVec = StartVec + MultiplyVec;
	// Trace radius
	float Radius = 250.0f;
	// Object types to trace against (e.g., WorldDynamic, Pawn)
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));
	// Trace against simple collision
	bool bTraceComplex = false;
	// Actors to ignore (e.g., this actor)
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(this);
	// Debug draw type
	EDrawDebugTrace::Type DrawDebugType = EDrawDebugTrace::None; // ForDuration
	// Output hit result
	FHitResult OutHit;
	// Ignore self
	bool bIgnoreSelf = true;

	// Trace For Enemies
	bool bSphereTrace = UKismetSystemLibrary::SphereTraceSingleForObjects(
		GetWorld(),
		StartVec,
		EndVec,
		Radius,
		ObjectTypes,
		bTraceComplex,
		ActorsToIgnore,
		DrawDebugType,
		OutHit,
		bIgnoreSelf,
		FLinearColor::Red,
		FLinearColor::Green,
		5.0f
	);

	if (bSphereTrace)
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit Actor: %s"), *OutHit.GetActor()->GetName());

		UE_LOG(LogTemp, Log, TEXT("Hit actor: %s"), *OutHit.GetActor()->GetName());

		if (OutHit.GetActor()->IsValidLowLevel())
		{
			ANP_BaseEnemy* Enemy = Cast<ANP_BaseEnemy>(OutHit.GetActor());
			if (Enemy)
			{
				if (Enemy->GetState() != ECharacterStates::Death)
				{
					TargetActor = Enemy;
					bIsTargeting = true;
					Enemy->OnTargeted();
				}
				else
				{
					EndTarget();
				}
			}
		}
		else
		{
			EndTarget();
		}
	}
	else
	{
		// Find Target From Surrounding
		UE_LOG(LogTemp, Warning, TEXT("No Hit for first trace"));

		// Trace start and end points
		FVector StartVec2 = GetActorLocation();
		FVector EndVec2 = GetActorLocation();
		// Trace radius
		float Radius2 = 500.0f;
		// Object types to trace against (e.g., WorldDynamic, Pawn)
		TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes2;
		ObjectTypes2.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));
		// Trace against simple collision
		bool bTraceComplex2 = false;
		// Actors to ignore (e.g., this actor)
		TArray<AActor*> ActorsToIgnore2;
		ActorsToIgnore2.Add(this);
		// Debug draw type
		EDrawDebugTrace::Type DrawDebugType2 = EDrawDebugTrace::None; // ForDuration
		// Output hit result
		FHitResult OutHit2;
		// Ignore self
		bool bIgnoreSelf2 = true;

		// Trace For Enemies
		bool bSphereTrace2 = UKismetSystemLibrary::SphereTraceSingleForObjects(
			GetWorld(),
			StartVec2,
			EndVec2,
			Radius2,
			ObjectTypes2,
			bTraceComplex2,
			ActorsToIgnore2,
			DrawDebugType2,
			OutHit2,
			bIgnoreSelf2,
			FLinearColor::Red,
			FLinearColor::Green,
			5.0f
		);

		if (bSphereTrace2)
		{
			UE_LOG(LogTemp, Warning, TEXT("Hit Actor: %s"), *OutHit2.GetActor()->GetName());

			UE_LOG(LogTemp, Log, TEXT("Hit actor: %s"), *OutHit2.GetActor()->GetName());

			if (OutHit2.GetActor()->IsValidLowLevel())
			{
				ANP_BaseEnemy* Enemy2 = Cast<ANP_BaseEnemy>(OutHit2.GetActor());
				if (Enemy2)
				{
					if (Enemy2->GetState() != ECharacterStates::Death)
					{
						TargetActor = Enemy2;
						bIsTargeting = true;
						Enemy2->OnTargeted();
					}
					else
					{
						EndTarget();
					}
				}
			}
			else
			{
				EndTarget();
			}
		}
		else
		{
			EndTarget();
		}

	}
}

void ANeonParadigm_GameCharacter::EndTarget()
{
	bIsTargeting = false;

	if (TargetActor->IsValidLowLevel())
	{
		// Attempt to cast TargetActor to NP_BaseEnemy
		ANP_BaseEnemy* Enemy = Cast<ANP_BaseEnemy>(TargetActor);
		if (Enemy)
		{
			Enemy->EndTarget();
		}
	}

	TargetActor = nullptr;

}

void ANeonParadigm_GameCharacter::RotateToTarget()
{
	if (TargetActor->IsValidLowLevel())
	{
		StopRotateToTargetTimer();
		GetWorld()->GetTimerManager().SetTimer(TimerForRotationToTarget, this, &ANeonParadigm_GameCharacter::UpdateCharacterRotation, 0.01f, true); // 0.0167f
		return;
	}
	
	if (SoftTargetActor->IsValidLowLevel())
	{
		ANP_BaseEnemy* TempSoftTargetEnemy = Cast<ANP_BaseEnemy>(SoftTargetActor);
		if (TempSoftTargetEnemy)
		{
			if (TempSoftTargetEnemy->GetState() != ECharacterStates::Death)
			{
				SoftTargetEnemy = TempSoftTargetEnemy;
				StopRotationToSoftTargetTimer();
				//GetWorld()->GetTimerManager().SetTimer(TimerForSoftRotationToTarget, this, &ANeonParadigm_GameCharacter::UpdateCharacterSoftRotation, 0.01f, true); // 0.0167f
				TimelineComponent->PlayFromStart();
			}
		}
	}
	
}

bool ANeonParadigm_GameCharacter::GetIsTargeting()
{
	return bIsTargeting;
}

void ANeonParadigm_GameCharacter::StopRotateToTargetTimer()
{
	GetWorld()->GetTimerManager().ClearTimer(TimerForRotationToTarget); // this might not work
}

void ANeonParadigm_GameCharacter::UpdateCharacterRotation()
{
	DurationOfRotation++;
	UE_LOG(LogTemp, Warning, TEXT("Duration Of Rotation: %d"), DurationOfRotation);

	if (DurationOfRotation >= 25)
	{
		StopRotateToTargetTimer();
		DurationOfRotation = 0;
		UE_LOG(LogTemp, Warning, TEXT("Duration Of Rotation Reset: %d"), DurationOfRotation);
	}

	if (TargetActor->IsValidLowLevel())
	{
		FRotator StartRotation(GetActorRotation());
		FRotator FindLookAtRot(UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), TargetActor->GetActorLocation()));
		FRotator TargetRotator(StartRotation.Pitch, FindLookAtRot.Yaw, StartRotation.Roll);
		FRotator AttackRotation = FMath::RInterpTo(StartRotation, TargetRotator, GetWorld()->GetDeltaSeconds(), SpeedOfRotation);
		SetActorRotation(AttackRotation);
		UE_LOG(LogTemp, Error, TEXT("IS DOING THIS!!!????"));
		// Get the actor's rotation
		FRotator ActorRotation = GetActorRotation();

		// Log the rotation to the console
		UE_LOG(LogTemp, Error, TEXT("Character Rotation: Pitch = %f, Yaw = %f, Roll = %f"),
			ActorRotation.Pitch, ActorRotation.Yaw, ActorRotation.Roll);
		

	}
	else
	{
		DurationOfRotation = 0;
		UE_LOG(LogTemp, Warning, TEXT("Duration Of Rotation Reset Final: %d"), DurationOfRotation);
		StopRotateToTargetTimer();
	}

}

void ANeonParadigm_GameCharacter::FindSoftLockTarget()
{
	if (UKismetMathLibrary::NotEqual_VectorVector(GetCharacterMovement()->GetLastInputVector(), FVector(0.0f, 0.0f, 0.0f), 0.05f))  
	{
		// Trace start and end points
		FVector StartVec = GetActorLocation();
		FVector MultiplyVec = GetCharacterMovement()->GetLastInputVector() * TargetingDistance;
		FVector EndVec = StartVec + MultiplyVec;

		// Trace radius
		float Radius = 80.0f;

		// Object types to trace against (e.g., WorldDynamic, Pawn)
		TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
		ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));

		// Trace against simple collision
		bool bTraceComplex = false;

		// Actors to ignore (e.g., this actor)
		TArray<AActor*> ActorsToIgnore;
		ActorsToIgnore.Add(this); // Ignore self

		// Debug draw type
		EDrawDebugTrace::Type DrawDebugType = EDrawDebugTrace::None; // ForDuration

		// Output hit result
		FHitResult OutHit;

		// Ignore self
		bool bIgnoreSelf = true;
		
		// Trace for enemies
		bool bSphereTrace = UKismetSystemLibrary::SphereTraceSingleForObjects(
			GetWorld(),
			StartVec,
			EndVec,
			Radius,
			ObjectTypes,
			bTraceComplex,
			ActorsToIgnore,
			DrawDebugType,
			OutHit,
			bIgnoreSelf,
			FLinearColor::Red,
			FLinearColor::Green,
			5.0f
		);

		if (bSphereTrace)
		{
			UE_LOG(LogTemp, Warning, TEXT("Hit Actor: %s"), *OutHit.GetActor()->GetName());

			UE_LOG(LogTemp, Log, TEXT("Hit actor: %s"), *OutHit.GetActor()->GetName());

			ANP_BaseEnemy* Enemy = Cast<ANP_BaseEnemy>(OutHit.GetActor());
			if (Enemy)
			{
				if (Enemy->GetState() != ECharacterStates::Death)
				{
					if (OutHit.GetActor() != SoftTargetActor || !SoftTargetActor->IsValidLowLevel())
					{
						LastSoftTargetActor = SoftTargetActor;
						SoftTargetActor = OutHit.GetActor();
						SoftTargetEnemy = Enemy;  
					}
				}
				else
				{
					SoftTargetActor = nullptr;
					SoftTargetEnemy = nullptr;
					LastSoftTargetActor = nullptr;
				}
			}
			else
			{
				SoftTargetActor = nullptr;
				SoftTargetEnemy = nullptr;
				LastSoftTargetActor = nullptr;
			}
		}
		else
		{
			// Trace start and end points
			FVector StartVec2 = GetActorLocation();
			FVector EndVec2 = StartVec2; // EndVec2 can be updated based on targeting distance if needed

			// Trace radius
			float Radius2 = 500.0f; // Adjust this value to balance the detection range for the lock-on system

			// Object types to trace against (e.g., WorldDynamic, Pawn)
			TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes2;
			ObjectTypes2.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));

			// Trace against simple collision
			bool bTraceComplex2 = false;

			// Actors to ignore (e.g., this actor)
			TArray<AActor*> ActorsToIgnore2;
			ActorsToIgnore2.Add(this); // Ignore self

			// Debug draw type
			EDrawDebugTrace::Type DrawDebugType2 = EDrawDebugTrace::None; // ForDuration

			// Output hit result
			FHitResult OutHit2;

			// Ignore self
			bool bIgnoreSelf2 = true;

			// Trace for enemies
			bool bSphereTrace2 = UKismetSystemLibrary::SphereTraceSingleForObjects(
				GetWorld(),
				StartVec2,
				EndVec2,
				Radius2,
				ObjectTypes2,
				bTraceComplex2,
				ActorsToIgnore2,
				DrawDebugType2,
				OutHit2,
				bIgnoreSelf2,
				FLinearColor::Red,
				FLinearColor::Green,
				5.0f
			);

			if (bSphereTrace2)
			{
				UE_LOG(LogTemp, Warning, TEXT("Hit Actor: %s"), *OutHit2.GetActor()->GetName());

				ANP_BaseEnemy* Enemy2 = Cast<ANP_BaseEnemy>(OutHit2.GetActor());
				if (Enemy2 && Enemy2->GetState() != ECharacterStates::Death)
				{
					if (!SoftTargetActor || SoftTargetActor != OutHit2.GetActor())
					{
						LastSoftTargetActor = SoftTargetActor;
						SoftTargetActor = OutHit2.GetActor();
						SoftTargetEnemy = Enemy2;
					}
				}
				else
				{
					// Reset targets if the hit actor is invalid or dead
					LastSoftTargetActor = nullptr;
					SoftTargetActor = nullptr;
					SoftTargetEnemy = nullptr;
				}
			}
			else
			{
				// Reset targets if nothing is hit
				LastSoftTargetActor = nullptr;
				SoftTargetActor = nullptr;
				SoftTargetEnemy = nullptr;
			}

		}
	}
	else
	{
		FVector StartVec2 = GetActorLocation();
		FVector EndVec2 = StartVec2; 

		float Radius2 = 500.0f; 
		TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes2;
		ObjectTypes2.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));

		bool bTraceComplex2 = false;
		TArray<AActor*> ActorsToIgnore2;
		ActorsToIgnore2.Add(this); 
		EDrawDebugTrace::Type DrawDebugType2 = EDrawDebugTrace::None; // ForDuration
		TArray<FHitResult> OutHits2;

		bool bSphereTrace2 = UKismetSystemLibrary::SphereTraceMultiForObjects(
			GetWorld(),
			StartVec2,
			EndVec2,
			Radius2,
			ObjectTypes2,
			bTraceComplex2,
			ActorsToIgnore2,
			DrawDebugType2,
			OutHits2,
			true, // Ignore self
			FLinearColor::Red,
			FLinearColor::Green,
			5.0f
		);

		if (bSphereTrace2)
		{
			float ClosestDistance = FLT_MAX;
			AActor* ClosestActor = nullptr;

			for (const FHitResult& Hit : OutHits2)
			{
				if (AActor* HitActor = Hit.GetActor())
				{
					// Calculate distance
					float Distance = FVector::Dist(StartVec2, Hit.ImpactPoint);

					// Debug log
					UE_LOG(LogTemp, Warning, TEXT("Detected Actor: %s, Distance: %f"), *HitActor->GetName(), Distance);

					// Find the closest actor
					if (Distance < ClosestDistance)
					{
						ClosestDistance = Distance;
						ClosestActor = HitActor;
					}
				}
			}

			// Check if the current target is valid (alive and within range)
			if (SoftTargetActor && IsTargetValid(SoftTargetEnemy))
			{
				// Do nothing, keep the current target
				UE_LOG(LogTemp, Warning, TEXT("Current target is valid, keeping target: %s"), *SoftTargetActor->GetName());
			}
			else
			{
				// Set the closest actor as the target
				if (ClosestActor)
				{
					ANP_BaseEnemy* ClosestEnemy = Cast<ANP_BaseEnemy>(ClosestActor);
					if (ClosestEnemy && ClosestEnemy->GetState() != ECharacterStates::Death)
					{
						LastSoftTargetActor = SoftTargetActor;
						SoftTargetActor = ClosestActor;
						SoftTargetEnemy = ClosestEnemy;

						UE_LOG(LogTemp, Warning, TEXT("Locking onto Closest Actor: %s, Distance: %f"), *ClosestActor->GetName(), ClosestDistance);
					}
					else
					{
						SoftTargetActor = nullptr;
						SoftTargetEnemy = nullptr;
					}
				}
			}
		}
		else
		{
			LastSoftTargetActor = nullptr;
			SoftTargetActor = nullptr;
			SoftTargetEnemy = nullptr;
		}
	}
}

void ANeonParadigm_GameCharacter::SoftTarget()
{
	if (!bIsTargeting)
		FindSoftLockTarget();
}

void ANeonParadigm_GameCharacter::ResetSoftLockTarget()
{
	SoftTargetActor = nullptr;
	LastSoftTargetActor = nullptr;
}

AActor* ANeonParadigm_GameCharacter::GetSoftTargetActor()
{
	return SoftTargetActor;
}

bool ANeonParadigm_GameCharacter::IsTargetValid(ANP_BaseEnemy* Target)
{
	if (Target && Target->GetState() != ECharacterStates::Death)
	{
		float Distance = FVector::Dist(GetActorLocation(), Target->GetActorLocation());
		return Distance <= MaxSoftTargetDistance;  // Only valid if within range
	}
	return false;
}

void ANeonParadigm_GameCharacter::StopRotationToSoftTargetTimer()
{
	SoftTargetLerpAmt = 0.f;
	UE_LOG(LogTemp, Warning, TEXT("rotating changed"))
	GetWorld()->GetTimerManager().ClearTimer(TimerForSoftRotationToTarget); // this might not work
}

void ANeonParadigm_GameCharacter::UpdateCharacterSoftRotation()
{
	DurationOfSoftRotation++;
	UE_LOG(LogTemp, Warning, TEXT("Duration Of Soft Rotation: %d"), DurationOfSoftRotation);

	if (DurationOfSoftRotation >= 10)
	{
		StopRotationToSoftTargetTimer();
		DurationOfSoftRotation = 0;
		UE_LOG(LogTemp, Warning, TEXT("Duration Of Soft Rotation Reset: %d"), DurationOfSoftRotation);
	}

	if (SoftTargetActor->IsValidLowLevel())
	{
		if (SoftTargetEnemy->GetState() != ECharacterStates::Death)
		{
			
			SoftTargetLerpAmt += 0.1f;
			FRotator StartRotation(GetActorRotation());
			FRotator FindLookAtRot(UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), SoftTargetActor->GetActorLocation()));
			FRotator TargetRotator(StartRotation.Pitch, FindLookAtRot.Yaw, StartRotation.Roll);
			FRotator AttackRotation = UKismetMathLibrary::RLerp(StartRotation, TargetRotator, SoftTargetLerpAmt, false);
			UE_LOG(LogTemp, Warning, TEXT("rotating to: %s"), *TargetRotator.ToString())
			SetActorRotation(AttackRotation);
			
			
		}
		else
		{
			DurationOfSoftRotation = 0;
			UE_LOG(LogTemp, Warning, TEXT("Duration Of Soft Rotation Reset Final: %d"), DurationOfSoftRotation);
			StopRotationToSoftTargetTimer();

			SoftTargetEnemy = nullptr;
			SoftTargetActor = nullptr;
		}
	}
	else
	{
		DurationOfSoftRotation = 0;
		UE_LOG(LogTemp, Warning, TEXT("Duration Of Soft Rotation Reset Final: %d"), DurationOfSoftRotation);
		StopRotationToSoftTargetTimer();

		SoftTargetEnemy = nullptr;
		SoftTargetActor = nullptr;

	}
}

void ANeonParadigm_GameCharacter::ResetTimelines()
{
	AttackComp->StopAttackMovement();
	StopRotateToTargetTimer();
	StopRotationToSoftTargetTimer();
}


void ANeonParadigm_GameCharacter::SaveDodge()
{
	if (bIsDodgeSaved)
	{
		bIsDodgeSaved = false;
		TArray<ECharacterStates> CurrentCharacterState;
		CurrentCharacterState.Add(ECharacterStates::Attack);
		CurrentCharacterState.Add(ECharacterStates::Dodge);

		if (CharacterState->IsCurrentStateEqualToAny(CurrentCharacterState))
		{
			CharacterState->SetState(ECharacterStates::None);
		}

		DodgeEvent();
	}
	else
	{
		return;
	}
}

void ANeonParadigm_GameCharacter::HandleTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if (!bEnabledIFrames)
	{
		TArray<ECharacterStates> CurrentCharacterState;
		CurrentCharacterState.Add(ECharacterStates::Parry);

		if (!CharacterState->IsCurrentStateEqualToAny(CurrentCharacterState))
		{
			UE_LOG(LogTemp, Warning, TEXT("Actor took damage"));

			CurrentHealth -= Damage;

			if (CurrentHealth > 0.0f)
			{
				const UNP_DamageType* NP_DamageType = Cast<UNP_DamageType>(DamageType);
				if (NP_DamageType)
				{
					// Successfully cast to UNP_DamageType
					// You can now access members or functions of UNP_DamageType
					UE_LOG(LogTemp, Error, TEXT("DAMAGE TYPE!@!! SOmething RIGHT!!!!"));
					//NP_DamageType->DamageType;
				}
				else
				{
					// Handle case where the cast failed (if the damage type is not of UNP_DamageType)
					UE_LOG(LogTemp, Error, TEXT("DAMAGE TYPE!@!! SOmething Wrong!!!!"));

				}

				// Step 2: Ensure the instance is valid
				if (IsValid(NP_DamageType))
				{
					UE_LOG(LogTemp, Warning, TEXT("vALID !!"));

					if (IsValid(DamageComp->GetHitReactionMontage(NP_DamageType->DamageType)))
					{
						CharacterState->SetState(ECharacterStates::Disabled);
						PlayAnimMontage(DamageComp->GetHitReactionMontage(NP_DamageType->DamageType));
					}
					else
					{
						UE_LOG(LogTemp, Warning, TEXT("Invalid Hit Reaction Montage!!"));

					}
					// You can now use the value of Damage as needed
					//UE_LOG(LogTemp, Log, TEXT("Damage Type: %f"), Damage);
				}
			}
			else
			{
				PerformDeath();
			}
		}
		else
		{
			ANP_BaseEnemy* Enemy = Cast<ANP_BaseEnemy>(DamageCauser);
			if (Enemy)
			{
				Enemy->Parried();

				FRotator TargetRot(UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), Enemy->GetActorLocation()));

				//GetController()->SetControlRotation(TargetRot);
				SetActorRotation(TargetRot);
				Counter(false);

			}
			else
			{

				ParryProjectile();
			}
		}
	}
}

void ANeonParadigm_GameCharacter::PerformDeath()
{
	CharacterState->SetState(ECharacterStates::Death);
	PlayAnimMontage(DeathMontage);
	DisableInput(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	SpawnLoseMenu();
}

void ANeonParadigm_GameCharacter::Parry()
{
	if (CanParry())
	{
		CharacterState->SetState(ECharacterStates::Parry);
		PlayAnimMontage(ParryMontage);
	}
}

bool ANeonParadigm_GameCharacter::CanParry()
{

	TArray<ECharacterStates> CurrentCharacterState;
	CurrentCharacterState.Reserve(5);
	// Preallocate in begin play
	CurrentCharacterState.Add(ECharacterStates::Attack);
	CurrentCharacterState.Add(ECharacterStates::Dodge);
	CurrentCharacterState.Add(ECharacterStates::Disabled);
	CurrentCharacterState.Add(ECharacterStates::Death);
	CurrentCharacterState.Add(ECharacterStates::Parry);
	//UE_LOG(LogTemp, Error, TEXT("LIGHT ATTACK MONTAGE INVALID"));

	return !CharacterState->IsCurrentStateEqualToAny(CurrentCharacterState) && !GetCharacterMovement()->IsFalling();
}

void ANeonParadigm_GameCharacter::Counter(bool ProjectileCounter)
{
	CharacterState->SetState(ECharacterStates::Attack);

	if (ProjectileCounter)
	{
		PlayAnimMontage(ProjectileCounterMontage);

	}
	else
	{
		PlayAnimMontage(CounterMontage);
	}
}

void ANeonParadigm_GameCharacter::SaveParry()
{
	if (bIsParrySaved)
	{
		bIsParrySaved = false;
		TArray<ECharacterStates> CurrentCharacterState;
		CurrentCharacterState.Add(ECharacterStates::Attack);

		if (CharacterState->IsCurrentStateEqualToAny(CurrentCharacterState))
		{
			CharacterState->SetState(ECharacterStates::None);
		}

		Parry();
	}
}

void ANeonParadigm_GameCharacter::ParryInput()
{
	TArray<ECharacterStates> CurrentCharacterState;
	CurrentCharacterState.Add(ECharacterStates::Attack);

	if (CharacterState->IsCurrentStateEqualToAny(CurrentCharacterState))
	{
		bIsParrySaved = true;
	}
	else
	{
		Parry();
	}
}

void ANeonParadigm_GameCharacter::ResetParry()
{
	bIsParrySaved = false;
}

void ANeonParadigm_GameCharacter::SetCurrentTempoDelay(float CurTempoDelay)
{
	CurrentTempoDelay = CurTempoDelay;
}

float ANeonParadigm_GameCharacter::GetCurrentTempoDelay()
{
	return CurrentTempoDelay;
}

void ANeonParadigm_GameCharacter::SetCurrentAnimTimeDelay(float CurAnimTimeDelay)
{
	CurrentAnimTimeDelay = CurAnimTimeDelay;
}

float ANeonParadigm_GameCharacter::GetCurrentAnimTimeDelay()
{
	return CurrentAnimTimeDelay;
}

void ANeonParadigm_GameCharacter::SetLastBeatTime(float fLastBeatTime)
{
	LastBeatTime = fLastBeatTime;
}

float ANeonParadigm_GameCharacter::GetLastBeatTime()
{
	return LastBeatTime;
}

void ANeonParadigm_GameCharacter::SetNextBeatTime(float fNextBeatTime)
{
	NextBeatTime = fNextBeatTime;
}

float ANeonParadigm_GameCharacter::GetNextBeatTime()
{
	return NextBeatTime;
}

void ANeonParadigm_GameCharacter::SetThirdBeatTime(float fThirdBeatTime)
{
	ThirdBeatTime = fThirdBeatTime;
}

float ANeonParadigm_GameCharacter::GetThirdBeatTime()
{
	return ThirdBeatTime;
}

float ANeonParadigm_GameCharacter::GetCurrentAnimPlayRate()
{
	return PlayRateForAnimMontages;
}

void ANeonParadigm_GameCharacter::TestRhythmDelayEvent()
{
	UE_LOG(LogTemp, Error, TEXT("Player Input Tick: %f"), GetWorld()->GetTimeSeconds());

	DelayFromLastBeat = GetWorld()->GetTimeSeconds() - LastBeatTime;
	UE_LOG(LogTemp, Error, TEXT("Delay From Last Beat: %f"), DelayFromLastBeat);

	DelayFromNextBeat = NextBeatTime - GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Error, TEXT("Delay From Next Beat: %f"), DelayFromNextBeat);

	DelayFromThirdBeat = ThirdBeatTime - GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Error, TEXT("Delay From Third Beat: %f"), DelayFromThirdBeat);

	if (DelayFromLastBeat <= 0.13f && GetCurrentAnimTimeDelay() <= 0.9f)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Input Was PERFECT to LAST Beat: %f"), DelayFromLastBeat);

		PlayRateForAnimMontages = CurrentAnimTimeDelay / DelayFromNextBeat;

		UE_LOG(LogTemp, Error, TEXT("Play Rate For AnimMontage: %f"), PlayRateForAnimMontages);
		SetPerfectBeatHit(true);  // ***** find references to see if this bool gets reset when supposed to!!!!!
		//ScoreComp->IncrementScore(100);  // *****  score to Add!!!!

	}
	else if (DelayFromNextBeat <= 0.13f && GetCurrentAnimTimeDelay() <= 0.9f)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Input Was PERFECT to NEXT Beat: %f"), DelayFromNextBeat);

		TotalTimeDelayToNextBeat = DelayFromNextBeat + GetCurrentTempoDelay(); // need to get time delay from tempo in music component

		UE_LOG(LogTemp, Warning, TEXT("Total Time Delay To Next Beat: %f"), TotalTimeDelayToNextBeat);

		PlayRateForAnimMontages = CurrentAnimTimeDelay / TotalTimeDelayToNextBeat;

		UE_LOG(LogTemp, Error, TEXT("Play Rate For AnimMontage: %f"), PlayRateForAnimMontages);
		SetPerfectBeatHit(true);   // ***** find references to see if this bool gets reset when supposed to!!!!!
		//ScoreComp->IncrementScore(100);  // *****  score to Add!!!!

	}
	else if (DelayFromLastBeat <= 0.33f && GetCurrentAnimTimeDelay() <= 0.9f)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Input Was CLOSER to LAST Beat: %f"), DelayFromLastBeat);

		PlayRateForAnimMontages = CurrentAnimTimeDelay / DelayFromNextBeat;

		UE_LOG(LogTemp, Error, TEXT("Play Rate For AnimMontage: %f"), PlayRateForAnimMontages);

	}
	else if(GetCurrentAnimTimeDelay() <= 0.9f)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Input Was CLOSER to NEXT Beat: %f"), DelayFromNextBeat);

		TotalTimeDelayToNextBeat = DelayFromNextBeat + GetCurrentTempoDelay(); // need to get time delay from tempo in music component
		
		UE_LOG(LogTemp, Warning, TEXT("Total Time Delay To Next Beat: %f"), TotalTimeDelayToNextBeat);

		PlayRateForAnimMontages = CurrentAnimTimeDelay / TotalTimeDelayToNextBeat;

		UE_LOG(LogTemp, Error, TEXT("Play Rate For AnimMontage: %f"), PlayRateForAnimMontages);
	}
	else
	{
		//TotalTimeDelayToThirdBeat = DelayFromNextBeat + GetCurrentTempoDelay(); // need to get time delay from tempo in music component

		//UE_LOG(LogTemp, Warning, TEXT("Total Time Delay To Next Beat: %f"), TotalTimeDelayToNextBeat);

		//PlayRateForAnimMontages = CurrentAnimTimeDelay / TotalTimeDelayToNextBeat;

		PlayRateForAnimMontages = CurrentAnimTimeDelay / DelayFromThirdBeat;

		UE_LOG(LogTemp, Error, TEXT("Play Rate For AnimMontage: %f"), PlayRateForAnimMontages);
	}


	float ClampedValueForPlayRate = FMath::Clamp(PlayRateForAnimMontages, 0.5f, 2.5f); // Definetly Might change this so make them variables. 

	float MontageLength = PlayAnimMontage(TestRhythmMontage, ClampedValueForPlayRate);

	UE_LOG(LogTemp, Display, TEXT("Montage Length: %f"), MontageLength);

}

void ANeonParadigm_GameCharacter::Rage()
{
	if (CanRage())
	{
		RageEvent();
	}
	else
	{
		TArray<ECharacterStates> CurrentCharacterState;
		CurrentCharacterState.Add(ECharacterStates::Attack);
		CurrentCharacterState.Add(ECharacterStates::Dodge);

		if (CharacterState->IsCurrentStateEqualToAny(CurrentCharacterState) && !bRage) // this might just be for saving attacks for switching the rage attack mode if we want differnt anims
		{
			bRageSaved = true;
			// savelightAttack = true;
		}
	}
}

void ANeonParadigm_GameCharacter::RageEvent()
{
	SetIFrames(true);

	//UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactEffect, Hit.ImpactPoint, FRotator::ZeroRotator);
	RageParticleComponent = UGameplayStatics::SpawnEmitterAttached(
		RageEmitter,        // The particle system you want to spawn
		GetMesh(),                 // The component to attach the particle system to (could be character mesh)
		FName("root"),           // Socket name or bone to attach to (can be NAME_None if not using sockets)
		FVector(0.0f, 0.0f, 200.0f),     // Optional location (relative offset)
		FRotator(0.0f, 0.0f, 0.0f),    // Optional rotation
		FVector(1.0f, 1.0f, 1.0f),     // Optional scale
		EAttachLocation::KeepRelativeOffset,  // Keep relative or snap to target
		true,                          // Auto-destroy when finished
		EPSCPoolMethod::None,          // No pooling
		true                           // Auto-activate);
	);

	CharacterState->SetState(ECharacterStates::Attack);

	PlayAnimMontage(RageAnim); // **** we can have this so that it can't be interuppted by enemy attacks.

	GetMesh()->SetOverlayMaterial(InitialRageOverlayMaterial);
}

void ANeonParadigm_GameCharacter::RageComplete() 
{
	if (RageParticleComponent)
	{
		RageParticleComponent->DestroyComponent();
		RageParticleComponent = nullptr;
		bRage = true;
		if (RageOverlayMaterial)
		{
			GetMesh()->SetOverlayMaterial(RageOverlayMaterial);
		}
		GetWorld()->GetTimerManager().SetTimer(RageDepletionTimerHandle, this, &ANeonParadigm_GameCharacter::DepleteRage, RageDepletionRate, true);
	}
}

void ANeonParadigm_GameCharacter::EndRage()
{
	bRage = false;
	GetMesh()->SetOverlayMaterial(nullptr);
	SetIFrames(false);

	GetWorld()->GetTimerManager().ClearTimer(RageDepletionTimerHandle);  // Stop depletion
}

bool ANeonParadigm_GameCharacter::CanRage()
{
	TArray<ECharacterStates> CurrentCharacterState;
	CurrentCharacterState.Add(ECharacterStates::Attack);
	CurrentCharacterState.Add(ECharacterStates::Dodge);
	CurrentCharacterState.Add(ECharacterStates::Disabled);
	CurrentCharacterState.Add(ECharacterStates::Death);
	CurrentCharacterState.Add(ECharacterStates::Parry);

	return !CharacterState->IsCurrentStateEqualToAny(CurrentCharacterState) && !GetCharacterMovement()->IsFalling() && !bRage && CurrentRage > RageActivationThreshold;  // **** This could be changed to use while falling.
}

bool ANeonParadigm_GameCharacter::IsRaging()
{
	return bRage;
}

void ANeonParadigm_GameCharacter::DepleteRage()
{
	if (CurrentRage > 0.0f)
	{
		CurrentRage -= RageDepletionAmount;
		UpdateRageBarEvent();  // Update UI or rage bar
		if (CurrentRage <= 0.0f)
		{
			CurrentRage = 0.0f;
			EndRage();  // Stop rage mode if depleted
		}
	}
	else
	{
		EndRage();  // Stop rage mode if depleted
	}
}

void ANeonParadigm_GameCharacter::SetPerfectBeatHit(bool bPerfectHit)
{
	bPerfectBeatHit = bPerfectHit;
}

bool ANeonParadigm_GameCharacter::IsPerfectBeatHit()
{
	return bPerfectBeatHit;
}

void ANeonParadigm_GameCharacter::SoftTargetingTimelineUpdated(float Alpha)
{
	UE_LOG(LogTemp, Warning, TEXT("alpha is now: %f"), Alpha);
	if (SoftTargetActor->IsValidLowLevel())
	{
		if (SoftTargetEnemy->GetState() != ECharacterStates::Death)
		{
			SoftTargetLerpAmt += 0.1f;
			FRotator StartRotation(GetActorRotation());
			FRotator FindLookAtRot(UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), SoftTargetActor->GetActorLocation()));
			FRotator TargetRotator(StartRotation.Pitch, FindLookAtRot.Yaw, StartRotation.Roll);
			FRotator AttackRotation = UKismetMathLibrary::RLerp(StartRotation, TargetRotator, Alpha, false);
			UE_LOG(LogTemp, Warning, TEXT("rotating to: %s"), *TargetRotator.ToString())
			SetActorRotation(AttackRotation);
		}
		else
		{
			DurationOfSoftRotation = 0;
			UE_LOG(LogTemp, Warning, TEXT("Duration Of Soft Rotation Reset Final: %d"), DurationOfSoftRotation);
			StopRotationToSoftTargetTimer();

			SoftTargetEnemy = nullptr;
			SoftTargetActor = nullptr;
		}
	}
	else
	{
		DurationOfSoftRotation = 0;
		UE_LOG(LogTemp, Warning, TEXT("Duration Of Soft Rotation Reset Final: %d"), DurationOfSoftRotation);
		StopRotationToSoftTargetTimer();

		SoftTargetEnemy = nullptr;
		SoftTargetActor = nullptr;

	}
}

void ANeonParadigm_GameCharacter::ToggleOrbEmission()
{
	// Check if the material is present in slot 0
	CurrentOrbMaterial = BPM_OrbMesh->GetMaterial(0);

	if (!CurrentOrbMaterial)
	{
		UE_LOG(LogTemp, Warning, TEXT("No material found on StaticMeshComponent."));
		return;
	}

	if (DynOrbMaterial)
	{
		float EmissiveValue = 20.0f;  // Turn on or off the emission
		DynOrbMaterial->SetScalarParameterValue(TEXT("EmissiveIntensity"), EmissiveValue);
		UE_LOG(LogTemp, Warning, TEXT("YOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO!!!!!!!"));

	}
}

void ANeonParadigm_GameCharacter::ToggleOrbEmissionOff()
{

	if (DynOrbMaterial)
	{
		float EmissiveValue = 0.0f;  // Turn on or off the emission
		DynOrbMaterial->SetScalarParameterValue(TEXT("EmissiveIntensity"), EmissiveValue);
		UE_LOG(LogTemp, Warning, TEXT("YEAH NOOOOOOOOOOOOO!!!!!!!"));

	}
}

UStaticMeshComponent* ANeonParadigm_GameCharacter::GetBPM_OrbMesh()
{
	return BPM_OrbMesh;
}

void ANeonParadigm_GameCharacter::AddToCurrentRage(float RageToAdd)
{
	if (CurrentRage >= 100)
		return;

	CurrentRage += RageToAdd;
	UpdateRageBarEvent();  // this might need to be changed   ************
}

float ANeonParadigm_GameCharacter::GetCurrentRage()
{
	return CurrentRage;
}

void ANeonParadigm_GameCharacter::AddToCurrentHealth(float HealthToAdd)
{
	if (CurrentHealth >= 1000)
		return;
	UE_LOG(LogTemp, Warning, TEXT("ADD ING TO CURRENT HEALT !!!!!!!"));

	CurrentHealth += HealthToAdd;
	UpdateHealthBarEvent();  // this might need to be changed   ************
}

void ANeonParadigm_GameCharacter::RotateCameraForSoftTargetting()
{
	/*
	if (SoftTargetActor)
	{
		FVector CameraLocation = GetActorLocation(); // Use your camera's current location
		FVector TargetLocation = SoftTargetActor->GetActorLocation();

		FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(CameraLocation, TargetLocation);

		// Apply the rotation to the camera
		FollowCamera->SetWorldRotation(LookAtRotation);
	}


	if (SoftTargetActor)
	{
		FVector CameraLocation = GetActorLocation(); // Use your camera's current location
		FVector TargetLocation = SoftTargetActor->GetActorLocation();

		FRotator CurrentRotation = CameraComponent->GetComponentRotation(); // Replace `CameraComponent` with your camera reference
		FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(CameraLocation, TargetLocation);

		// Interpolate rotation
		FRotator SmoothRotation = FMath::RInterpTo(CurrentRotation, LookAtRotation, GetWorld()->DeltaTimeSeconds, 5.0f);

		// Apply the smooth rotation to the camera
		CameraComponent->SetWorldRotation(SmoothRotation);
	}

	if (bIsLockedOn && SoftTargetActor)
	{
		FVector CameraLocation = GetActorLocation();
		FVector TargetLocation = SoftTargetActor->GetActorLocation();

		FRotator CurrentRotation = CameraComponent->GetComponentRotation();
		FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(CameraLocation, TargetLocation);

		FRotator SmoothRotation = FMath::RInterpTo(CurrentRotation, LookAtRotation, GetWorld()->DeltaTimeSeconds, 5.0f);
		CameraComponent->SetWorldRotation(SmoothRotation);
	}


	// alternative
	if (bIsLockedOn && SoftTargetActor)
	{
		FVector TargetLocation = SoftTargetActor->GetActorLocation();

		FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(SpringArmComponent->GetComponentLocation(), TargetLocation);

		FRotator SmoothRotation = FMath::RInterpTo(SpringArmComponent->GetComponentRotation(), LookAtRotation, GetWorld()->DeltaTimeSeconds, 5.0f);

		SpringArmComponent->SetWorldRotation(SmoothRotation);
	}

	if (SoftTargetActor)
	{
		bIsLockedOn = true;
	}
	else
	{
		bIsLockedOn = false;

		// Optionally reset camera to default view
		FRotator DefaultRotation = FRotator(-10.0f, 0.0f, 0.0f); // Example default values
		FRotator SmoothRotation = FMath::RInterpTo(CameraComponent->GetComponentRotation(), DefaultRotation, GetWorld()->DeltaTimeSeconds, 5.0f);
		CameraComponent->SetWorldRotation(SmoothRotation);
	}
	*/
}

