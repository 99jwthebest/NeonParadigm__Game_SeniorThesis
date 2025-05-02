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
#include "GameInstance/NP_GameInstance.h"



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
	DefaultCameraBoomLength = 500.0f;
	DefaultCameraFOV = 90.0f;

	DodgeBaseForce = 1500.0f;
}

void ANeonParadigm_GameCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	GameInstance = Cast<UNP_GameInstance>(GetGameInstance());
	bAutoTargetCamera = GameInstance->GetOptionBooleanValue(EGameSetting::AutoTargetCamera);

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
	GameInstance->OnSettingsChanged.AddUObject(this, &ANeonParadigm_GameCharacter::OnSettingsChanged);

}

void ANeonParadigm_GameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Log, TEXT("SUCK_CurrentState: %d"), (int32)CharacterState->GetState());

	if (!bAutoTargetCamera)
		return;

	if (bIsTargeting)
		return;
	
	// Define a threshold for input to be considered significant
	const float InputThreshold = 0.25f;  // Adjust this threshold to ignore small mouse movements
	const float Deadzone = 0.1f;  // Values below this will be ignored (adjust for sensitivity)
	static float InputHoldTime = 0.0f;  // Track how long input is above the threshold
	const float InputHoldTimeThreshold = 0.1f;  // 0.1 seconds of continuous input before disabling rotation
	
	// Check for significant camera input above the threshold
	if (FMath::Abs(LookAxisVector.X) > InputThreshold || FMath::Abs(LookAxisVector.Y) > InputThreshold)
	{
		// Player is moving the camera; disable auto-rotation
		bCanRotateBack = false;
		LookAxisVector.X = 0.0f;  // Ignore small horizontal movements

		LookAxisVector.Y = 0.0f;  // Ignore small vertical movements

		UE_LOG(LogTemp, Log, TEXT("LookAxisVector.X: %f, LookAxisVector.Y: %f"), LookAxisVector.X, LookAxisVector.Y);
		UE_LOG(LogTemp, Log, TEXT("Abs(LookAxisVector.X): %f, Abs(LookAxisVector.Y): %f"), FMath::Abs(LookAxisVector.X), FMath::Abs(LookAxisVector.Y));
		
		// Reset the timer and start the delay for camera auto-rotation
		GetWorld()->GetTimerManager().ClearTimer(CheckForTargetInCamViewTimerHandle);
		GetWorld()->GetTimerManager().SetTimer(
			CheckForTargetInCamViewTimerHandle,
			this,
			&ANeonParadigm_GameCharacter::CheckForTargetInCameraView,
			0.2f, // Delay duration
			false // Only run once
		);

		// Reset the timer and start the delay for camera auto-rotation
		GetWorld()->GetTimerManager().ClearTimer(CameraDelayTimerHandle);
		GetWorld()->GetTimerManager().SetTimer(
			CameraDelayTimerHandle,
			this,
			&ANeonParadigm_GameCharacter::EnableCameraAutoRotate,
			0.5f, // Delay duration
			false // Only run once
		);

		UE_LOG(LogTemp, Log, TEXT("Camera input detected. Disabling auto-rotation."));
	}
	else
	{
		// Reset input hold time if no significant input
		UE_LOG(LogTemp, Log, TEXT("No camera input. Waiting to enable auto-rotation."));
	}

	if (!bCanRotateBack)
		return;


	if (CameraTargetActor && CameraTargetActor->IsValidLowLevel()) // check if targeting
	{
		ANP_BaseEnemy* Enemy = Cast<ANP_BaseEnemy>(CameraTargetActor);
		if (Enemy)
		{
			if (!Enemy->GetCanBeTargeted())
				return;

			if (Enemy->GetState() != ECharacterStates::Death)
			{
				// Check the distance between the player and the enemy
				if (GetDistanceTo(CameraTargetActor) < MaxTargetingDistance)
				{
					UE_LOG(LogTemp, Log, TEXT("TargetingOffset: %s"), *TargetingOffset.ToString());
					FVector PlayerLocation = GetActorLocation();
					FVector TargetLocation = CameraTargetActor->GetActorLocation() - TargetingOffset;

					// Project the target's location onto the screen
					FVector2D ScreenPosition;
					bool bIsOnScreen = UGameplayStatics::ProjectWorldToScreen(
						GetWorld()->GetFirstPlayerController(),
						TargetLocation,
						ScreenPosition
					);

					FVector2D ViewportSize;
					GEngine->GameViewport->GetViewportSize(ViewportSize);
					FVector2D ScreenCenter = ViewportSize * 0.5f;

					// Scale the threshold distance based on screen resolution
					float Diagonal = FMath::Sqrt(FMath::Square(ViewportSize.X) + FMath::Square(ViewportSize.Y));
					const float ThresholdDistance = Diagonal * 0.25f; // e.g., 40% of the screen diagonal

					// Calculate the distance from the center of the screen
					float DistanceFromCenter = bIsOnScreen
						? FVector2D::Distance(ScreenCenter, ScreenPosition)
						: FLT_MAX;

					float MaxSpeed = 4.0f;
					float MinSpeed = .3f;
					float DistanceFromThreshold = FMath::Max(0.0f, DistanceFromCenter - ThresholdDistance);
					float MaxDistance = Diagonal * 0.5f;

					// Smooth the rotation speed using a static variable
					static float SmoothedRotationSpeed = MinSpeed;

					// Calculate desired speed based on distance from center
					float DesiredRotationSpeed = FMath::Clamp(
						FMath::Lerp(MinSpeed, MaxSpeed, DistanceFromThreshold / MaxDistance),
						MinSpeed,
						MaxSpeed
					);

					// Interpolate the rotation speed for smoother transitions
					float SpeedSmoothFactor = 5.0f; // Adjust this to control how quickly the speed stabilizes
					SmoothedRotationSpeed = FMath::FInterpTo(SmoothedRotationSpeed, DesiredRotationSpeed, GetWorld()->GetDeltaSeconds(), SpeedSmoothFactor);

					// Use the smoothed rotation speed
					float RotationSpeed = SmoothedRotationSpeed;

					// Debug to verify smooth changes
					UE_LOG(LogTemp, Log, TEXT("DesiredRotationSpeed: %f, SmoothedRotationSpeed: %f"), DesiredRotationSpeed, SmoothedRotationSpeed);


					// If target is far from center or off-screen, rotate the camera
					if (DistanceFromCenter > ThresholdDistance || !bIsOnScreen)
					{
						UE_LOG(LogTemp, Warning, TEXT("No camera input. Is it Past this!!!!!!! Threshhold!!!"));


						FRotator TargetRotation = UKismetMathLibrary::FindLookAtRotation(PlayerLocation, TargetLocation);
						FRotator NewRotation = FMath::RInterpTo(GetController()->GetControlRotation(), TargetRotation, DeltaTime, RotationSpeed);

						GetController()->SetControlRotation(NewRotation);
						UE_LOG(LogTemp, Warning, TEXT("Rotating camera towards target. Distance from center: %f"), DistanceFromCenter);
					}
					else
					{
						UE_LOG(LogTemp, Warning, TEXT("Target within screen center threshold. Distance: %f"), DistanceFromCenter);
					}
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
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to cast TargetActor to NP_BaseEnemy."));
		}
	}
	else if (bIsTargeting) // fix for constant null object messages
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
		//LookAction->bTriggerWhenPaused = true;
		// Light Attack
		EnhancedInputComponent->BindAction(LightAttackAction, ETriggerEvent::Completed, this, &ANeonParadigm_GameCharacter::LightAttack);
		
		// Launch Attack
		EnhancedInputComponent->BindAction(LightAttackAction, ETriggerEvent::Triggered, this, &ANeonParadigm_GameCharacter::LaunchAttack);
		
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

		// Projectile Weapon
		EnhancedInputComponent->BindAction(ProjectileWeaponAction, ETriggerEvent::Triggered, this, &ANeonParadigm_GameCharacter::ProjectileWeapon);
		
		// Projectile Weapon Stun
		EnhancedInputComponent->BindAction(ProjectileWeaponStunAction, ETriggerEvent::Triggered, this, &ANeonParadigm_GameCharacter::ProjectileWeaponStun);

		// Moving
		EnhancedInputComponent->BindAction(NavigateAction, ETriggerEvent::Triggered, this, &ANeonParadigm_GameCharacter::NavigateMenus);
		NavigateAction->bTriggerWhenPaused = true;

		// Moving
		EnhancedInputComponent->BindAction(NavigateActionKeyboard, ETriggerEvent::Triggered, this, &ANeonParadigm_GameCharacter::NavigateMenusKeyBor);
		NavigateActionKeyboard->bTriggerWhenPaused = true;

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
	
	TArray<ECharacterStates> CurrentCharacterState;
	CurrentCharacterState.Add(ECharacterStates::Attack);

	if (GetCharacterMovement()->IsFlying() ||
		CharacterState->IsCurrentStateEqualToAny(CurrentCharacterState))
	{
		// this is causing trace for softtarget to not work!!! ***********
		UE_LOG(LogTemp, Warning, TEXT("JK_This Should Be ON When AttackingG!!!!!!!!"));

		return;
	}

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

FVector2D ANeonParadigm_GameCharacter::GetLookInputValue()
{
	return LookAxisVector;
}

void ANeonParadigm_GameCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	LookAxisVector = Value.Get<FVector2D>();
	
	if (Controller != nullptr)
	{
		if (!bIsTargeting)
		{
			if (!GameInstance)
				return;

			// Invert X-axis if the setting is enabled
			float InvertedX = GameInstance->GetOptionBooleanValue(EGameSetting::InvertedXAxis) ? -LookAxisVector.X : LookAxisVector.X;

			// Invert Y-axis if the setting is enabled
			float InvertedY = GameInstance->GetOptionBooleanValue(EGameSetting::InvertedYAxis) ? -LookAxisVector.Y : LookAxisVector.Y;


			// add yaw and pitch inphealut to controller
			AddControllerYawInput(InvertedX);
			AddControllerPitchInput(InvertedY);
		}
	}
}

void ANeonParadigm_GameCharacter::LightAttack()
{

	TArray<ECharacterStates> CurrentCharacterState2;
	CurrentCharacterState2.Add(ECharacterStates::Dodge);

	if (CharacterState->IsCurrentStateEqualToAny(CurrentCharacterState2) &&
		!AttackComp->GetNotifyLaunchPassed())
	{
		AttackComp->SetSaveLaunchAttack(true);
		return;
	}


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

void ANeonParadigm_GameCharacter::LaunchAttack(const FInputActionInstance& Instance)
{

	float HeldDuration = Instance.GetElapsedTime();
	if (HeldDuration >= 0.5f && AttackComp->CanAttack())
	{
		AttackComp->LaunchAttack();
		HeldDuration = 0.0f;
		UE_LOG(LogTemp, Warning, TEXT("BAY_Launch!!!!!!!!"));

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
	UE_LOG(LogTemp, Log, TEXT("SHUCK_CurrentState: %d"), (int32)CharacterState->GetState());

}

void ANeonParadigm_GameCharacter::ResetDoubleJump()
{
	DoubleJumped = false;
}

void ANeonParadigm_GameCharacter::Dodge()
{
	//if(CanDodge())
		TestRhythmDelayEvent();
	
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
		}

		CharacterState->SetState(ECharacterStates::Dodge);

		if (bPerfectBeatHit)
		{
			PerfectDodgeCount++;
			DodgePushMultiplier = FMath::Min(1.0f + (PerfectDodgeCount * 0.5f), 2.5f); // Max push multiplier is 2.0
			DamageComp->PerfectHitOperations();
			TurnOnMagnetizedDodge();
			ToggleEmissivityEmergenLights();
			// Debug PerfectDodgeCount and DodgePushMultiplier when a perfect beat is hit
			UE_LOG(LogTemp, Log, TEXT("Perfect Beat Hit! PerfectDodgeCount: %d, DodgePushMultiplier: %f"), PerfectDodgeCount, DodgePushMultiplier);
		}
		else
		{
			PerfectDodgeCount = 0;
			DodgePushMultiplier = 1.0f;

			// Debug when a perfect beat is missed
			UE_LOG(LogTemp, Log, TEXT("Perfect Beat Missed. Resetting PerfectDodgeCount to %d, DodgePushMultiplier to %f"), PerfectDodgeCount, DodgePushMultiplier);
		}

		PlayAnimMontage(DodgeMontage);
		
		// Calculate progress (0.0 = full ammo, 1.0 = all shots used)
		DodgeCooldownProgress = 1.0f - FMath::Clamp(static_cast<float>(PerfectDodgeCount) / static_cast<float>(MaxPerfectDodges), 0.0f, 1.0f);
		UpdateDodgeBarEvent();
		//StartTimerForDodgeCooldown();

		// Calculate new FOV based on Perfect Dodge Count
		float TargetFOV = 90.0f + PerfectDodgeCount * 5.0f; // Adjust FOV range as needed
		TimerCameraFOV(TargetFOV, 10.0f);

		// Apply movement with multiplier
		AttackComp->DodgeMovement(DodgeBaseForce * DodgePushMultiplier);

		if (PerfectDodgeCount >= MaxPerfectDodges)
		{
			DodgeCooldownEndTime = GetWorld()->GetTimeSeconds() + CooldownDodgeDuration;

			// Debug DodgeCooldownEndTime when max perfect dodges are reached
			UE_LOG(LogTemp, Log, TEXT("PerfectDodgeCount: Max Perfect Dodges Reached. DodgeCooldownEndTime set to: %f"), DodgeCooldownEndTime);

			PerfectDodgeCount = 0;
			DodgePushMultiplier = 1.0f;

			CharacterState->SetState(ECharacterStates::None);
			StartTimerForDodgeCooldown();
			// Debug PerfectDodgeCount reset and DodgePushMultiplier reset
			UE_LOG(LogTemp, Log, TEXT("PerfectDodgeCount reset to %d, DodgePushMultiplier reset to %f"), PerfectDodgeCount, DodgePushMultiplier);
		}
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

	// Check if cooldown has ended
	const bool bCooldownComplete = GetWorld()->GetTimeSeconds() >= DodgeCooldownEndTime;

	return bCooldownComplete && !CharacterState->IsCurrentStateEqualToAny(CurrentCharacterState); //&& !GetCharacterMovement()->IsFalling();
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

void ANeonParadigm_GameCharacter::ResetDodgeCountAndMultiplier()
{
	PerfectDodgeCount = 0;
	DodgePushMultiplier = 1.0f;
	DodgeCooldownProgress = 1.0f - FMath::Clamp(static_cast<float>(PerfectDodgeCount) / static_cast<float>(MaxPerfectDodges), 0.0f, 1.0f);
	UpdateDodgeBarEvent();
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
			if (TempSoftTargetEnemy->GetbIsBoss())
				return;

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

			UE_LOG(LogTemp, Log, TEXT("PR1_Hit actor: %s"), *OutHit.GetActor()->GetName());

			ANP_BaseEnemy* Enemy = Cast<ANP_BaseEnemy>(OutHit.GetActor());
			if (Enemy)
			{
				if (Enemy->GetbIsBoss())
					return;

				if (Enemy->GetState() != ECharacterStates::Death)
				{
					if (OutHit.GetActor() != SoftTargetActor || !SoftTargetActor->IsValidLowLevel())
					{
						LastSoftTargetActor = SoftTargetActor;
						SoftTargetActor = OutHit.GetActor();
						CameraTargetActor = SoftTargetActor;
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
			EDrawDebugTrace::Type DrawDebugType2 = EDrawDebugTrace::ForDuration; // ForDuration

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
				UE_LOG(LogTemp, Warning, TEXT("PR2_Hit Actor: %s"), *OutHit2.GetActor()->GetName());

				ANP_BaseEnemy* Enemy2 = Cast<ANP_BaseEnemy>(OutHit2.GetActor());
				if (Enemy2 && Enemy2->GetState() != ECharacterStates::Death)
				{
					if (!SoftTargetActor || SoftTargetActor != OutHit2.GetActor())
					{
						LastSoftTargetActor = SoftTargetActor;
						SoftTargetActor = OutHit2.GetActor();
						CameraTargetActor = SoftTargetActor;
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

		TArray<AActor*> ActorsToIgnore2;
		ActorsToIgnore2.Add(this);

		TArray<FHitResult> OutHits2;

		bool bSphereTrace2 = UKismetSystemLibrary::SphereTraceMultiForObjects(
			GetWorld(),
			StartVec2,
			EndVec2,
			Radius2,
			ObjectTypes2,
			false,
			ActorsToIgnore2,
			EDrawDebugTrace::None,
			OutHits2,
			true,
			FLinearColor::Red,
			FLinearColor::Green,
			5.0f
		);

		if (bSphereTrace2)
		{
			float ClosestDistance = FLT_MAX;
			AActor* ClosestTarget = nullptr;

			bool bPlayerIsAirborne = GetCharacterMovement()->IsFalling() || GetCharacterMovement()->IsFlying();
			UE_LOG(LogTemp, Warning, TEXT("Player airborne: %s, Flying: %s"),
				GetCharacterMovement()->IsFalling() ? TEXT("true") : TEXT("false"),
				GetCharacterMovement()->IsFlying() ? TEXT("true") : TEXT("false"));

			for (const FHitResult& Hit : OutHits2)
			{
				AActor* HitActor = Hit.GetActor();
				ANP_BaseEnemy* HitEnemy = Cast<ANP_BaseEnemy>(HitActor);
				if (HitEnemy && HitEnemy->GetMesh())
				{
					FVector MeshLocation = HitEnemy->GetMesh()->GetComponentLocation();
					float Distance = FVector::Dist(StartVec2, MeshLocation);

					bool bIsFlyingEnemy = !HitEnemy->GetCanBeParried();
					bool bIsCurrentTarget = (HitEnemy == SoftTargetEnemy);

					UE_LOG(LogTemp, Warning, TEXT("%s - bCanBeParried: %s"),
						*HitEnemy->GetName(),
						HitEnemy->GetCanBeParried() ? TEXT("true") : TEXT("false"));

					//  Skip flying enemies while grounded
					if (!bPlayerIsAirborne && bIsFlyingEnemy)
					{
						UE_LOG(LogTemp, Warning, TEXT("Skipping flying enemy while grounded: %s"), *HitEnemy->GetName());
						continue;
					}

					//  Skip other melee enemies while airborne unless it's the current target
					if (bPlayerIsAirborne && !bIsFlyingEnemy && !bIsCurrentTarget)
					{
						UE_LOG(LogTemp, Warning, TEXT("Skipping non-target ground enemy while airborne: %s"), *HitEnemy->GetName());
						continue;
					}

					//  This enemy is valid
					if (Distance < ClosestDistance)
					{
						ClosestDistance = Distance;
						ClosestTarget = HitActor;
					}
				}
			}

			// Reject old ground target if we're airborne and it's not flying
			if (SoftTargetEnemy && SoftTargetEnemy->GetCanBeParried() && bPlayerIsAirborne)
			{
				UE_LOG(LogTemp, Warning, TEXT("Clearing ground SoftTarget because player is airborne."));
				SoftTargetActor = nullptr;
				SoftTargetEnemy = nullptr;
				LastSoftTargetActor = nullptr;
			}

			// Final targeting logic
			if (SoftTargetActor && IsTargetValid(SoftTargetEnemy))
			{
				UE_LOG(LogTemp, Log, TEXT("DUCK_Keeping valid soft target: %s"), *SoftTargetActor->GetName());
			}
			else if (ClosestTarget)
			{
				ANP_BaseEnemy* ClosestEnemy = Cast<ANP_BaseEnemy>(ClosestTarget);
				if (ClosestEnemy && ClosestEnemy->GetState() != ECharacterStates::Death)
				{
					LastSoftTargetActor = SoftTargetActor;
					SoftTargetActor = ClosestTarget;
					CameraTargetActor = SoftTargetActor;
					SoftTargetEnemy = ClosestEnemy;

					UE_LOG(LogTemp, Warning, TEXT("DUCK_NEW soft target: %s (Flying: %s)"),
						*ClosestTarget->GetName(),
						(!ClosestEnemy->GetCanBeParried() ? TEXT("Yes") : TEXT("No")));
				}
				else
				{
					SoftTargetActor = nullptr;
					SoftTargetEnemy = nullptr;
				}
			}
			else
			{
				SoftTargetActor = nullptr;
				SoftTargetEnemy = nullptr;
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

			
			// Get difficulty from GameInstance
			float DamageMultiplier = 1.0f;

			switch (GameInstance->GetCurrentDifficultyMode())
			{
			case 0:
				DamageMultiplier = .5f; // Reduce damage
				UE_LOG(LogTemp, Error, TEXT("DOOOOM It's Boring"));
				break;
			case 1:
				DamageMultiplier = 1.0f;  // Normal damage
				UE_LOG(LogTemp, Error, TEXT("DOOOOM It's MID"));
				break;
			case 2:
				DamageMultiplier = 2.0f;  // Increase damage
				UE_LOG(LogTemp, Error, TEXT("DOOOOM It's Hard"));
				break;
			}

			// Apply difficulty scaling
			float FinalDamage = Damage * DamageMultiplier;
			CurrentHealth -= FinalDamage;


			//CurrentHealth -= Damage;
			PlayDamageCameraShake();

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
					UE_LOG(LogTemp, Warning, TEXT("BUCK_vALID Is IT valid!!"));

					if (IsValid(DamageComp->GetHitReactionMontage(NP_DamageType->DamageType)))
					{
						CharacterState->SetState(ECharacterStates::Disabled);
						PlayAnimMontage(DamageComp->GetHitReactionMontage(NP_DamageType->DamageType));
						UE_LOG(LogTemp, Warning, TEXT("BUCK_vALID Is IT valid!!"));
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

float ANeonParadigm_GameCharacter::GetCurrentUIBallAnimPlayRate()
{
	DelayFromNextBeat = NextBeatTime - GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Error, TEXT("Delay From Next Beat: %f"), DelayFromNextBeat);

	PlayRateUIBallAnim = 1 / DelayFromNextBeat;

	return PlayRateUIBallAnim;
}

float ANeonParadigm_GameCharacter::GetCurrentAnimPlayRate()
{
	return PlayRateForAnimMontages;
}

void ANeonParadigm_GameCharacter::TestRhythmDelayEvent()
{
	UE_LOG(LogTemp, Error, TEXT("CD_Player Input Tick: %f"), GetWorld()->GetTimeSeconds());

	DelayFromLastBeat = GetWorld()->GetTimeSeconds() - LastBeatTime;
	UE_LOG(LogTemp, Error, TEXT("CD_Delay From Last Beat: %f"), DelayFromLastBeat);

	DelayFromNextBeat = NextBeatTime - GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Error, TEXT("CD_Delay From Next Beat: %f"), DelayFromNextBeat);

	DelayFromThirdBeat = ThirdBeatTime - GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Error, TEXT("CD_Delay 1 From Third Beat: %f"), DelayFromThirdBeat);

	UE_LOG(LogTemp, Error, TEXT("CD_Delay Tempo Delay Threshold From Third Beat: %f"), GetCurrentTempoDelay() / 2);


	if (DelayFromLastBeat <= 0.13f && GetCurrentAnimTimeDelay() <= 1.1f)
	{
		UE_LOG(LogTemp, Warning, TEXT("CD_Player Input Was PERFECT to LAST Beat: %f"), DelayFromLastBeat);

		PlayRateForAnimMontages = CurrentAnimTimeDelay / DelayFromNextBeat;

		UE_LOG(LogTemp, Error, TEXT("CD_Play Rate For AnimMontage: %f"), PlayRateForAnimMontages);
		SetPerfectBeatHit(true);  // ***** find references to see if this bool gets reset when supposed to!!!!!
		//ScoreComp->IncrementScore(100);  // *****  score to Add!!!!
		TogglePerfectHitTextBox();

	}
	else if (DelayFromNextBeat <= 0.13f && GetCurrentAnimTimeDelay() <= 1.1f)
	{
		UE_LOG(LogTemp, Warning, TEXT("CD_Player Input Was PERFECT to NEXT Beat: %f"), DelayFromNextBeat);

		TotalTimeDelayToNextBeat = DelayFromNextBeat + GetCurrentTempoDelay(); // need to get time delay from tempo in music component

		UE_LOG(LogTemp, Warning, TEXT("CD_Total Time Delay To Next Beat: %f"), TotalTimeDelayToNextBeat);

		PlayRateForAnimMontages = CurrentAnimTimeDelay / TotalTimeDelayToNextBeat;

		UE_LOG(LogTemp, Error, TEXT("CD_Play Rate For AnimMontage: %f"), PlayRateForAnimMontages);
		SetPerfectBeatHit(true);   // ***** find references to see if this bool gets reset when supposed to!!!!!
		//ScoreComp->IncrementScore(100);  // *****  score to Add!!!!
		TogglePerfectHitTextBox();

	}
	else if (DelayFromLastBeat <= GetCurrentTempoDelay() / 2 && GetCurrentAnimTimeDelay() <= 1.1f)
	{
		UE_LOG(LogTemp, Warning, TEXT("CD_Player Input Was CLOSER to LAST Beat: %f"), DelayFromLastBeat);

		PlayRateForAnimMontages = CurrentAnimTimeDelay / DelayFromNextBeat;

		UE_LOG(LogTemp, Error, TEXT("CD_Play Rate For AnimMontage: %f"), PlayRateForAnimMontages);

	}
	else if(GetCurrentAnimTimeDelay() <= 1.1f)
	{
		UE_LOG(LogTemp, Warning, TEXT("CD_Player Input Was CLOSER to NEXT Beat: %f"), DelayFromNextBeat);

		TotalTimeDelayToNextBeat = DelayFromNextBeat + GetCurrentTempoDelay(); // need to get time delay from tempo in music component
		
		UE_LOG(LogTemp, Warning, TEXT("CD_Total Time Delay To Next Beat: %f"), TotalTimeDelayToNextBeat);

		PlayRateForAnimMontages = CurrentAnimTimeDelay / TotalTimeDelayToNextBeat;

		UE_LOG(LogTemp, Error, TEXT("CD_Play Rate For AnimMontage: %f"), PlayRateForAnimMontages);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("CD_Player Input Was CLOSER to NEXT Beat: %f"), DelayFromNextBeat);

		TotalTimeDelayToNextBeat = DelayFromNextBeat + GetCurrentTempoDelay() * 2; // need to get time delay from tempo in music component
		
		UE_LOG(LogTemp, Warning, TEXT("CD_Total Time Delay To Next Beat: %f"), TotalTimeDelayToNextBeat);

		PlayRateForAnimMontages = CurrentAnimTimeDelay / TotalTimeDelayToNextBeat;

		UE_LOG(LogTemp, Error, TEXT("CD_Play Rate For AnimMontage: %f"), PlayRateForAnimMontages);
	}


	float ClampedValueForPlayRate = FMath::Clamp(PlayRateForAnimMontages, 0.5f, 2.5f); // Definetly Might change this so make them variables. 

	float MontageLength = PlayAnimMontage(TestRhythmMontage, ClampedValueForPlayRate);

	UE_LOG(LogTemp, Display, TEXT("Montage Length: %f"), MontageLength);

	//DelayFromNextBeat = NextBeatTime - GetWorld()->GetTimeSeconds();
	//UE_LOG(LogTemp, Error, TEXT("A_Delay 2 From Next Beat: %f"), DelayFromNextBeat);

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

float ANeonParadigm_GameCharacter::UpdateFlipBookPlayRate()
{
	float FB_PlayRate = 1 / GetCurrentTempoDelay();

	return FB_PlayRate;
}

void ANeonParadigm_GameCharacter::AddToCurrentRage(float RageToAdd)
{
	if (CurrentRage >= MaxRage)
		return;

	CurrentRage += RageToAdd;
	UpdateRageBarEvent();  // this might need to be changed   ************
}

void ANeonParadigm_GameCharacter::IncreaseMaxRage(float AmountToAdd)
{
	MaxRage += AmountToAdd;

	UpdateMaxRageBarEvent();
}

float ANeonParadigm_GameCharacter::GetCurrentRage()
{
	return CurrentRage;
}

void ANeonParadigm_GameCharacter::AddToCurrentHealth(float HealthToAdd)
{
	if (CurrentHealth >= MaxHealth)
		return;
	UE_LOG(LogTemp, Warning, TEXT("ADD ING TO CURRENT HEALT !!!!!!!"));

	CurrentHealth += HealthToAdd;
	UpdateHealthBarEvent();  // this might need to be changed   ************
}

void ANeonParadigm_GameCharacter::IncreaseMaxHealth(float AmountToAdd)
{

	MaxHealth += AmountToAdd;

	UpdateMaxHealthBarEvent();
}

// Called in BP_Spawner
void ANeonParadigm_GameCharacter::StartEnemyEncounter()
{
	ScoreComp->StartEncounter();
}

void ANeonParadigm_GameCharacter::EndEnemyEncounter()
{
	ScoreComp->EndEncounter();
	ScoreComp->AddToOverallLevelScore(ScoreComp->CalculateOverallEncounterScore());
	ScoreComp->AddToOverallBaseScore(ScoreComp->GetCurrentScore());
	ScoreComp->AddToOverallPerfectTimingPercentage(ScoreComp->GetPerfectTimingPercentage());
	ScoreComp->AddToOverallClearTime(ScoreComp->GetClearTime());

	if (ScoreComp->GetWinEncounterCondition())
	{
		SpawnWinMenuEvent();
	}
	else
	{
		ToggleEncounterResults();
	}
	TimerCameraDistance(DefaultCameraBoomLength);
	
	

	ScoreComp->ResetAllEncounterScores();
	
	UE_LOG(LogTemp, Warning, TEXT("Is End Encounter Happening Twice!!!!!!!"));

}

void ANeonParadigm_GameCharacter::ProjectileWeapon()
{
	TArray<ECharacterStates> CurrentCharacterState;
	CurrentCharacterState.Add(ECharacterStates::Attack);
	CurrentCharacterState.Add(ECharacterStates::Dodge);

	if (CharacterState->IsCurrentStateEqualToAny(CurrentCharacterState))
	{
		bIsShootSaved = true;
	}
	else
	{
		ProjectileWeaponEvent();
	}
}

void ANeonParadigm_GameCharacter::ProjectileWeaponEvent()
{
	if (CanShoot())
	{
		AttackComp->ResetLightAttack();
		AttackComp->ResetHeavyAttack();

        // Trigger the projectile attack animation
		if (IsValid(ProjectileWeaponMontage))
		{
			AttackComp->FindNotifyTriggerTime(ProjectileWeaponMontage, FName("NP_AN_TestRhythmPunch"));
			SetCurrentAnimTimeDelay(AttackComp->GetNotifyTriggerTime());
			TestRhythmDelayEvent();
			CharacterState->SetState(ECharacterStates::Attack);
			
			PlayAnimMontage(ProjectileWeaponMontage, GetCurrentAnimPlayRate());
		}

		ProjectileShot++;

		UE_LOG(LogTemp, Log, TEXT("Projectile Shot!! %d"), ProjectileShot);

		// Calculate progress (0.0 = full ammo, 1.0 = all shots used)
		ProjectileCooldownProgress = 1.0f - FMath::Clamp(static_cast<float>(ProjectileShot) / static_cast<float>(MaxProjectiles), 0.0f, 1.0f);
		UpdateProjectileWeaponBarEvent();

		//// Apply movement or effects with the multiplier
		//AttackComp->AttackMovement(15.0f * PerfectProjectileMultiplier); // Adjust value as needed for the projectile system

		// Reset logic when max perfect projectiles are reached
		if (ProjectileShot >= MaxProjectiles)
		{

			ProjectileCooldownEndTime = GetWorld()->GetTimeSeconds() + CooldownProjectileDuration;

			ProjectileShot = 0;
			UE_LOG(LogTemp, Log, TEXT("Projectile Shot Reset!! %d"), ProjectileShot);

			StartTimerForProjectileCooldown();

		}

		/*

		// Perfect beat handling for the projectile system
        if (bPerfectBeatHit)
        {
            PerfectProjectileCount++;
            PerfectProjectileMultiplier = FMath::Min(1.0f + (PerfectProjectileCount * 0.5f), 2.5f); // Max multiplier is 2.5
            DamageComp->PerfectHitOperations();

            // Debug PerfectProjectileCount and PerfectProjectileMultiplier when a perfect beat is hit
            UE_LOG(LogTemp, Log, TEXT("Perfect Beat Hit! PerfectProjectileCount: %d, PerfectProjectileMultiplier: %f"), PerfectProjectileCount, PerfectProjectileMultiplier);
        }
        else
        {
            PerfectProjectileCount = 0;
            PerfectProjectileMultiplier = 1.0f;

            // Debug when a perfect beat is missed
            UE_LOG(LogTemp, Log, TEXT("Perfect Beat Missed. Resetting PerfectProjectileCount to %d, PerfectProjectileMultiplier to %f"), PerfectProjectileCount, PerfectProjectileMultiplier);
        }


        //// Apply movement or effects with the multiplier
        //AttackComp->AttackMovement(15.0f * PerfectProjectileMultiplier); // Adjust value as needed for the projectile system

        // Reset logic when max perfect projectiles are reached
        if (PerfectProjectileCount >= MaxPerfectProjectiles)
        {
            PerfectProjectileCooldownEndTime = GetWorld()->GetTimeSeconds() + CooldownPerfectProjectileDuration;

            // Debug ProjectileCooldownEndTime when max perfect projectiles are reached
            UE_LOG(LogTemp, Log, TEXT("PerfectProjectileCount: Max Perfect Projectiles Reached. ProjectileCooldownEndTime set to: %f"), PerfectProjectileCooldownEndTime);

            PerfectProjectileCount = 0;
            PerfectProjectileMultiplier = 1.0f;

            // Debug PerfectProjectileCount and PerfectProjectileMultiplier reset
            UE_LOG(LogTemp, Log, TEXT("PerfectProjectileCount reset to %d, PerfectProjectileMultiplier reset to %f"), PerfectProjectileCount, PerfectProjectileMultiplier);
        }

		*/

	}
}

bool ANeonParadigm_GameCharacter::CanShoot()
{
	TArray<ECharacterStates> CurrentCharacterState;
	CurrentCharacterState.Add(ECharacterStates::Attack);
	CurrentCharacterState.Add(ECharacterStates::Dodge);
	CurrentCharacterState.Add(ECharacterStates::Disabled);
	CurrentCharacterState.Add(ECharacterStates::Death);
	CurrentCharacterState.Add(ECharacterStates::Parry);
	//UE_LOG(LogTemp, Error, TEXT("LIGHT ATTACK MONTAGE INVALID"));

	// Check if cooldown has ended
	const bool bCooldownComplete = GetWorld()->GetTimeSeconds() >= ProjectileCooldownEndTime;
	//return bCooldownComplete && !CharacterState->IsCurrentStateEqualToAny(CurrentCharacterState); //&& !GetCharacterMovement()->IsFalling();

	return bCooldownComplete && !CharacterState->IsCurrentStateEqualToAny(CurrentCharacterState) && !GetCharacterMovement()->IsFalling();
}


void ANeonParadigm_GameCharacter::SetIsShootSaved(bool bSetIsShootSaved)
{
	bIsShootSaved = bSetIsShootSaved;
}

void ANeonParadigm_GameCharacter::SaveShoot()
{
	if (bIsShootSaved)
	{
		bIsShootSaved = false;
		TArray<ECharacterStates> CurrentCharacterState;
		CurrentCharacterState.Add(ECharacterStates::Attack);
		CurrentCharacterState.Add(ECharacterStates::Dodge);

		if (CharacterState->IsCurrentStateEqualToAny(CurrentCharacterState))
		{
			CharacterState->SetState(ECharacterStates::None);
		}

		ProjectileWeaponEvent();
	}
	else
	{
		return;
	}
}

void ANeonParadigm_GameCharacter::ProjectileWeaponStun()
{
	TArray<ECharacterStates> CurrentCharacterState;
	CurrentCharacterState.Add(ECharacterStates::Attack);
	CurrentCharacterState.Add(ECharacterStates::Dodge);

	if (CharacterState->IsCurrentStateEqualToAny(CurrentCharacterState))
	{
		bIsStunSaved = true;
	}
	else
	{
		ProjectileWeaponStunEvent();
	}
}

void ANeonParadigm_GameCharacter::ProjectileWeaponStunEvent()
{
	if (CanStun())
	{
		AttackComp->ResetLightAttack();
		AttackComp->ResetHeavyAttack();

		// Trigger the projectile attack animation
		if (IsValid(ProjectileWeaponStunMontage))
		{
			AttackComp->FindNotifyTriggerTime(ProjectileWeaponStunMontage, FName("NP_AN_TestRhythmPunch"));
			SetCurrentAnimTimeDelay(AttackComp->GetNotifyTriggerTime());
			TestRhythmDelayEvent();
			CharacterState->SetState(ECharacterStates::Attack);

			PlayAnimMontage(ProjectileWeaponStunMontage, GetCurrentAnimPlayRate());
		}

		ProjectileStunShot++;

		UE_LOG(LogTemp, Log, TEXT("Projectile Stun Shot!! %d"), ProjectileStunShot);

		// Calculate progress (0.0 = full ammo, 1.0 = all shots used)
		ProjectileStunCooldownProgress = 1.0f - FMath::Clamp(static_cast<float>(ProjectileStunShot) / static_cast<float>(MaxStunProjectiles), 0.0f, 1.0f);
		UpdateProjectileWeaponStunBarEvent();

		//// Apply movement or effects with the multiplier
		//AttackComp->AttackMovement(15.0f * PerfectProjectileMultiplier); // Adjust value as needed for the projectile system

		// Reset logic when max perfect projectiles are reached
		if (ProjectileStunShot >= MaxStunProjectiles)
		{

			ProjectileStunCooldownEndTime = GetWorld()->GetTimeSeconds() + CooldownProjectileStunDuration;

			ProjectileStunShot = 0;
			UE_LOG(LogTemp, Log, TEXT("Projectile Stun Shot Reset!! %d"), ProjectileStunShot);

			StartTimerForProjectileStunCooldown();

		}

	}
}

bool ANeonParadigm_GameCharacter::CanStun()
{
	TArray<ECharacterStates> CurrentCharacterState;
	CurrentCharacterState.Add(ECharacterStates::Attack);
	CurrentCharacterState.Add(ECharacterStates::Dodge);
	CurrentCharacterState.Add(ECharacterStates::Disabled);
	CurrentCharacterState.Add(ECharacterStates::Death);
	CurrentCharacterState.Add(ECharacterStates::Parry);
	//UE_LOG(LogTemp, Error, TEXT("LIGHT ATTACK MONTAGE INVALID"));

	// Check if cooldown has ended
	const bool bCooldownComplete = GetWorld()->GetTimeSeconds() >= ProjectileStunCooldownEndTime;
	//return bCooldownComplete && !CharacterState->IsCurrentStateEqualToAny(CurrentCharacterState); //&& !GetCharacterMovement()->IsFalling();

	return bCooldownComplete && !CharacterState->IsCurrentStateEqualToAny(CurrentCharacterState) && !GetCharacterMovement()->IsFalling();
}

void ANeonParadigm_GameCharacter::SetIsStunSaved(bool bSetIsStunSaved)
{
	bIsStunSaved = bSetIsStunSaved;
}

void ANeonParadigm_GameCharacter::SaveStun()
{
	if (bIsStunSaved)
	{
		bIsStunSaved = false;
		TArray<ECharacterStates> CurrentCharacterState;
		CurrentCharacterState.Add(ECharacterStates::Attack);
		CurrentCharacterState.Add(ECharacterStates::Dodge);

		if (CharacterState->IsCurrentStateEqualToAny(CurrentCharacterState))
		{
			CharacterState->SetState(ECharacterStates::None);
		}

		ProjectileWeaponStunEvent();
	}
	else
	{
		return;
	}
}

float ANeonParadigm_GameCharacter::GetProjectileStunCooldownEndTime()
{
	return ProjectileStunCooldownEndTime;
}

float ANeonParadigm_GameCharacter::GetProjectileStunCooldownDuration()
{
	return CooldownProjectileStunDuration;
}

void ANeonParadigm_GameCharacter::StartTimerForProjectileStunCooldown()
{
	GetWorld()->GetTimerManager().SetTimer(TimerForProjectileStunCooldown, this, &ANeonParadigm_GameCharacter::CalculateTimeForProjectileStunWeaponCooldown, GetWorld()->GetDeltaSeconds(), true); // 0.0167f

}

void ANeonParadigm_GameCharacter::CalculateTimeForProjectileStunWeaponCooldown()
{

	float CurrentTime = GetWorld()->GetTimeSeconds();
	float RemainingTime = ProjectileStunCooldownEndTime - CurrentTime;

	// Calculate progress (0.0 = no cooldown, 1.0 = cooldown complete)
	ProjectileStunCooldownProgress = FMath::Clamp(1.0f - (RemainingTime / CooldownProjectileStunDuration), 0.0f, 1.0f);

	//CooldownWidgetInstance->SetCooldownProgress(CooldownProgress);
	UpdateProjectileWeaponStunBarEvent();

	// Stop the timer when the cooldown is complete
	if (ProjectileStunCooldownProgress >= 1.0f)
	{
		GetWorldTimerManager().ClearTimer(TimerForProjectileStunCooldown);
	}
}


void ANeonParadigm_GameCharacter::TimerCameraDistance(float CameraBoomLengthF)
{
	CameraBoomLength = CameraBoomLengthF;
	GetWorld()->GetTimerManager().SetTimer(TimerForCameraDistanceChange, this, &ANeonParadigm_GameCharacter::ChangeCameraDistance, GetWorld()->GetDeltaSeconds(), true); // 0.0167f
}

void ANeonParadigm_GameCharacter::ChangeCameraDistance()
{
	// Smoothly interpolate the arm length
	float CurrentArmLength = CameraBoom->TargetArmLength;
	CameraBoom->TargetArmLength = FMath::FInterpTo(
		CurrentArmLength,
		CameraBoomLength,
		GetWorld()->GetDeltaSeconds(),
		1.0f
	);

	// Define a small tolerance value
	const float SmallNumberTolerance = 0.1f;

	// Check if the current arm length is close enough to the target
	if (FMath::Abs(CameraBoom->TargetArmLength - CameraBoomLength) <= SmallNumberTolerance)
	{
		GetWorld()->GetTimerManager().ClearTimer(TimerForCameraDistanceChange);
		UE_LOG(LogTemp, Log, TEXT("Camera distance change completed."));
	}

}

void ANeonParadigm_GameCharacter::TimerCameraFOV(float TargetFOVValue, float TargetFOVSpeedChangeValue)
{
	TargetCameraFOV = TargetFOVValue;
	TargetCameraFOVSpeedChange = TargetFOVSpeedChangeValue;
	GetWorld()->GetTimerManager().SetTimer(
		TimerForFOVChange,
		this,
		&ANeonParadigm_GameCharacter::ChangeCameraFOV,
		GetWorld()->GetDeltaSeconds(),
		true
	);
}

void ANeonParadigm_GameCharacter::ChangeCameraFOV()
{
	// Smoothly interpolate the camera FOV
	float CurrentFOV = FollowCamera->FieldOfView;
	FollowCamera->FieldOfView = FMath::FInterpTo(
		CurrentFOV,
		TargetCameraFOV,
		GetWorld()->GetDeltaSeconds(),
		TargetCameraFOVSpeedChange // Interpolation speed, adjust as needed
	);

	// Define a small tolerance value
	const float SmallNumberTolerance = 0.2f;

	// Check if the current FOV is close enough to the target
	if (FMath::Abs(FollowCamera->FieldOfView - TargetCameraFOV) <= SmallNumberTolerance)
	{
		GetWorld()->GetTimerManager().ClearTimer(TimerForFOVChange);
		UE_LOG(LogTemp, Log, TEXT("Camera FOV change completed."));
	}
}

float ANeonParadigm_GameCharacter::GetDefaultCameraFOV()
{
	return DefaultCameraFOV;
}

float ANeonParadigm_GameCharacter::GetDefaultCameraFOVSpeedChange()
{
	return DefaultCameraFOVSpeedChange;
}

float ANeonParadigm_GameCharacter::GetProjectileCooldownEndTime()
{
	return ProjectileCooldownEndTime;
}

float ANeonParadigm_GameCharacter::GetProjectileCooldownDuration()
{
	return CooldownProjectileDuration;
}

void ANeonParadigm_GameCharacter::StartTimerForProjectileCooldown()
{
	GetWorld()->GetTimerManager().SetTimer(TimerForProjectileCooldown, this, &ANeonParadigm_GameCharacter::CalculateTimeForProjectileWeaponCooldown, GetWorld()->GetDeltaSeconds(), true); // 0.0167f

}

void ANeonParadigm_GameCharacter::CalculateTimeForProjectileWeaponCooldown()
{

	float CurrentTime = GetWorld()->GetTimeSeconds();
	float RemainingTime = ProjectileCooldownEndTime - CurrentTime;

	// Calculate progress (0.0 = no cooldown, 1.0 = cooldown complete)
	ProjectileCooldownProgress = FMath::Clamp(1.0f - (RemainingTime / CooldownProjectileDuration), 0.0f, 1.0f);

	//CooldownWidgetInstance->SetCooldownProgress(CooldownProgress);
	UpdateProjectileWeaponBarEvent();

	// Stop the timer when the cooldown is complete
	if (ProjectileCooldownProgress >= 1.0f)
	{
		GetWorldTimerManager().ClearTimer(TimerForProjectileCooldown);
	}
}

void ANeonParadigm_GameCharacter::StartTimerForDodgeCooldown()
{
	GetWorld()->GetTimerManager().SetTimer(TimerDodgeCooldown, this, &ANeonParadigm_GameCharacter::CalculateTimeForDodgeCooldown, GetWorld()->GetDeltaSeconds(), true); // 0.0167f

}

void ANeonParadigm_GameCharacter::CalculateTimeForDodgeCooldown()
{

	float CurrentTime = GetWorld()->GetTimeSeconds();
	float RemainingTime = DodgeCooldownEndTime - CurrentTime;

	// Calculate progress (0.0 = no cooldown, 1.0 = cooldown complete)
	DodgeCooldownProgress = FMath::Clamp(1.0f - (RemainingTime / CooldownDodgeDuration), 0.0f, 1.0f);

	//CooldownWidgetInstance->SetCooldownProgress(CooldownProgress);
	UpdateDodgeBarEvent();

	// Stop the timer when the cooldown is complete
	if (DodgeCooldownProgress >= 1.0f)
	{
		GetWorldTimerManager().ClearTimer(TimerDodgeCooldown);
	}
}


void ANeonParadigm_GameCharacter::EnableCameraAutoRotate()
{
	bCanRotateBack = true;
	UE_LOG(LogTemp, Log, TEXT("No camera input detected. Auto-rotation re-enabled after delay."));
}

void ANeonParadigm_GameCharacter::CheckForTargetInCameraView()
{

	// Get the player camera's location and forward vector
	FVector CameraLocation = FollowCamera->GetComponentLocation();
	FVector CameraForward = FollowCamera->GetForwardVector();

	// Define the field of view angle (in degrees) for detection
	float FieldOfView = 45.0f; // Half-angle of the camera's field of view
	float CosFieldOfView = FMath::Cos(FMath::DegreesToRadians(FieldOfView));

	// Get all potential enemies in the world
	TArray<AActor*> AllEnemies;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ANP_BaseEnemy::StaticClass(), AllEnemies);

	// Store the closest enemy and minimum distance
	AActor* ClosestEnemy = nullptr;
	float MinDistance = FLT_MAX;

	UE_LOG(LogTemp, Log, TEXT("@Number of potential enemies: %d"), AllEnemies.Num());

	for (AActor* EnemyActor : AllEnemies)
	{
		// Check if the enemy is valid
		if (!IsValid(EnemyActor))
		{
			UE_LOG(LogTemp, Warning, TEXT("@Invalid enemy actor."));
			continue;
		}

		ANP_BaseEnemy* Enemy = Cast<ANP_BaseEnemy>(EnemyActor);
		if (!Enemy || Enemy->GetState() == ECharacterStates::Death)
		{
			UE_LOG(LogTemp, Warning, TEXT("@Enemy is invalid or dead: %s"), *EnemyActor->GetName());
			continue;
		}

		// Calculate the vector to the enemy from the camera
		FVector ToEnemy = Enemy->GetActorLocation() - CameraLocation;
		float DistanceToEnemy = ToEnemy.Size(); // Calculate distance
		ToEnemy.Normalize();

		// Use the dot product to check if the enemy is within the field of view
		float DotProduct = FVector::DotProduct(CameraForward, ToEnemy);

		if (DotProduct >= CosFieldOfView)
		{
			UE_LOG(LogTemp, Log, TEXT("@Enemy within FOV: %s"), *EnemyActor->GetName());

			// Perform a line trace to check if the enemy is visible
			FHitResult HitResult;
			bool bHit = GetWorld()->LineTraceSingleByChannel(
				HitResult,
				CameraLocation,
				Enemy->GetActorLocation(),
				ECC_Pawn
			);

			if (bHit)
			{
				UE_LOG(LogTemp, Log, TEXT("@Line trace hit: %s"), *HitResult.GetActor()->GetName());

				// Ensure the trace hits the enemy
				if (HitResult.GetActor() == EnemyActor)
				{
					UE_LOG(LogTemp, Log, TEXT("@Enemy is visible: %s"), *EnemyActor->GetName());

					// Update the closest enemy if this one is closer
					if (DistanceToEnemy < MinDistance)
					{
						MinDistance = DistanceToEnemy;
						ClosestEnemy = EnemyActor;
						UE_LOG(LogTemp, Error, TEXT("@Updated closest enemy: %s"), *ClosestEnemy->GetName());
					}
				}
				else
				{
					UE_LOG(LogTemp, Warning, TEXT("@Line trace hit something else: %s"), *HitResult.GetActor()->GetName());
				}
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("@Line trace did not hit any actor."));
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("@Enemy outside FOV: %s"), *EnemyActor->GetName());
		}
	}

	// Process the closest enemy in view
	if (ClosestEnemy)
	{
		UE_LOG(LogTemp, Log, TEXT("@Closest Enemy in View: %s"), *ClosestEnemy->GetName());

		// Update target references
		LastSoftTargetActor = SoftTargetActor;
		SoftTargetActor = ClosestEnemy;
		CameraTargetActor = SoftTargetActor;
		SoftTargetEnemy = Cast<ANP_BaseEnemy>(ClosestEnemy);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("@No enemies in view."));
	}
	/*
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
						CameraTargetActor = SoftTargetActor;
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
	*/
}

AActor* ANeonParadigm_GameCharacter::GetCameraTargetActor()
{
	return CameraTargetActor;
}

void ANeonParadigm_GameCharacter::TurnOnMagnetizedDodge()
{
	bIsMagnetizeDodgeActive = true;
	GetWorld()->GetTimerManager().SetTimer(TimerForMagnetizedDodge, this, &ANeonParadigm_GameCharacter::TurnOffMagnetizedDodge, MagnetizationDuration, false); // 0.0167f
}

void ANeonParadigm_GameCharacter::TurnOffMagnetizedDodge()
{
	bIsMagnetizeDodgeActive = false;
}

void ANeonParadigm_GameCharacter::ToggleEmissivityEmergenLights()
{

	// Array to store found actors
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("PerfectDodgeMesh"), FoundActors);

	for (AActor* Actor : FoundActors)
	{
		UStaticMeshComponent* MeshComponent = Actor->FindComponentByClass<UStaticMeshComponent>();
		if (MeshComponent)
		{
			// Create or retrieve the dynamic material instance
			UMaterialInstanceDynamic* MID = MeshComponent->CreateAndSetMaterialInstanceDynamic(0);
			if (MID)
			{
				MID->SetScalarParameterValue(FName("EmissiveStrength"), 1.0f); // Adjust value as needed
			}
		}
	}
	GetWorld()->GetTimerManager().SetTimer(TimerForEmissiveEmergenLights, this, &ANeonParadigm_GameCharacter::ToggleEmissivityEmergenLightsOff, 0.2f, false); // 0.0167f

}

void ANeonParadigm_GameCharacter::ToggleEmissivityEmergenLightsOff()
{
	// Array to store found actors
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("PerfectDodgeMesh"), FoundActors);

	for (AActor* Actor : FoundActors)
	{
		UStaticMeshComponent* MeshComponent = Actor->FindComponentByClass<UStaticMeshComponent>();
		if (MeshComponent)
		{
			// Create or retrieve the dynamic material instance
			UMaterialInstanceDynamic* MID = MeshComponent->CreateAndSetMaterialInstanceDynamic(0);
			if (MID)
			{
				// Set emissive value
				MID->SetScalarParameterValue(FName("EmissiveStrength"), 0.0f);
			}
		}
	}
}

void ANeonParadigm_GameCharacter::OnSettingsChanged()
{
	bAutoTargetCamera = GameInstance->GetOptionBooleanValue(EGameSetting::AutoTargetCamera);
	UE_LOG(LogTemp, Warning, TEXT("DUE, BT Work Delegate Because I'm ancy grancy"));
}

void ANeonParadigm_GameCharacter::NavigateMenus()
{
	UE_LOG(LogTemp, Error, TEXT("X_AHHHHHHH_YAAAAHH, IT Better Work!!!"));

}

void ANeonParadigm_GameCharacter::NavigateMenusKeyBor()
{
	UE_LOG(LogTemp, Error, TEXT("X_AHHHHHHH_YAAAAHH, KEYSSSSSS!!!"));

}
