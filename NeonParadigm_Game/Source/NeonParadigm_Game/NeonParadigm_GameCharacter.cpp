// Copyright Epic Games, Inc. All Rights Reserved.

#include "NeonParadigm_GameCharacter.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
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

	MaxTargetingDistance = 2500.0f;

	SpeedOfRotation = 10.0f;
	SpeedOfSoftRotation = 10.0f;

	bIsTargeting = false;
}

void ANeonParadigm_GameCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

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
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void ANeonParadigm_GameCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();
	
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
	}
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

void ANeonParadigm_GameCharacter::Landed(const FHitResult& Hit)
{
	ResetDoubleJump();
}

void ANeonParadigm_GameCharacter::ResetDoubleJump()
{
	DoubleJumped = false;
}

void ANeonParadigm_GameCharacter::Dodge()
{
	/*TSubclassOf<UNP_DamageType> DamageTypeClass = UNP_DamageType::StaticClass();
	if (DamageTypeClass != nullptr)
	{
		float Damage = UGameplayStatics::ApplyDamage(this, 10.0f, GetController(), this, DamageTypeClass);
		UE_LOG(LogTemp, Warning, TEXT("Applied %f damage to self."), Damage);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("DamageTypeClass is not valid."));
	}*/

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

void ANeonParadigm_GameCharacter::DodgeEvent()
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

	return !CharacterState->IsCurrentStateEqualToAny(CurrentCharacterState) && !GetCharacterMovement()->IsFalling();
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
	EDrawDebugTrace::Type DrawDebugType = EDrawDebugTrace::ForDuration;
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
		EDrawDebugTrace::Type DrawDebugType2 = EDrawDebugTrace::ForDuration;
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
	}
	else
	{
		if (SoftTargetActor->IsValidLowLevel())
		{
			ANP_BaseEnemy* TempSoftTargetEnemy = Cast<ANP_BaseEnemy>(SoftTargetActor);
			if (TempSoftTargetEnemy)
			{
				if (TempSoftTargetEnemy->GetState() != ECharacterStates::Death)
				{
					SoftTargetEnemy = TempSoftTargetEnemy;
					StopRotationToSoftTargetTimer();
					GetWorld()->GetTimerManager().SetTimer(TimerForSoftRotationToTarget, this, &ANeonParadigm_GameCharacter::UpdateCharacterSoftRotation, 0.01f, true); // 0.0167f
				}
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
		//ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECC_WorldDynamic));
		// Trace against simple collision
		bool bTraceComplex = false;
		// Actors to ignore (e.g., this actor)
		TArray<AActor*> ActorsToIgnore;
		ActorsToIgnore.Add(this);
		ActorsToIgnore.Add(SoftTargetActor);
		ActorsToIgnore.Add(SoftTargetEnemy);
		ActorsToIgnore.Add(LastSoftTargetActor);

		// Debug draw type
		EDrawDebugTrace::Type DrawDebugType = EDrawDebugTrace::ForDuration;
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

			ANP_BaseEnemy* Enemy = Cast<ANP_BaseEnemy>(OutHit.GetActor());
			if (Enemy)
			{
				if (Enemy->GetState() != ECharacterStates::Death)
				{
					if (OutHit.GetActor() != SoftTargetActor)
					{
						if (SoftTargetActor->IsValidLowLevel())
						{
							LastSoftTargetActor = SoftTargetActor;
							SoftTargetActor = OutHit.GetActor();
						}
						else
						{
							SoftTargetActor = OutHit.GetActor();
						}
					}
					else
					{
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
				SoftTargetActor = nullptr;
				SoftTargetEnemy = nullptr;
				LastSoftTargetActor = nullptr;
			}
		}
		else
		{
			LastSoftTargetActor = nullptr;
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

void ANeonParadigm_GameCharacter::StopRotationToSoftTargetTimer()
{
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
			FRotator StartRotation(GetActorRotation());
			FRotator FindLookAtRot(UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), SoftTargetActor->GetActorLocation()));
			FRotator TargetRotator(StartRotation.Pitch, FindLookAtRot.Yaw, StartRotation.Roll);
			FRotator AttackRotation = FMath::RInterpTo(StartRotation, TargetRotator, GetWorld()->GetDeltaSeconds(), SpeedOfSoftRotation);
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

float ANeonParadigm_GameCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	// Call the base class implementation
	float ActualDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	if (!bEnabledIFrames)
	{
		TArray<ECharacterStates> CurrentCharacterState;
		CurrentCharacterState.Add(ECharacterStates::Parry);

		if (!CharacterState->IsCurrentStateEqualToAny(CurrentCharacterState))
		{
			UE_LOG(LogTemp, Warning, TEXT("Actor took damage"));

			CurrentHealth -= DamageAmount;
			// Step 1: Create or obtain an instance of UNP_DamageType
			UNP_DamageType* MyDamageType = NewObject<UNP_DamageType>(GetWorld());

			if (CurrentHealth > 0.0f)
			{

				// Step 2: Ensure the instance is valid
				if (MyDamageType)
				{
					UE_LOG(LogTemp, Warning, TEXT("vALID !!"));

					if (IsValid(DamageComp->GetHitReactionMontage(MyDamageType->GetDamageType())))
					{
						CharacterState->SetState(ECharacterStates::Disabled);
						PlayAnimMontage(DamageComp->GetHitReactionMontage(MyDamageType->GetDamageType()));
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

	return ActualDamage;
}

void ANeonParadigm_GameCharacter::HandleTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{

}

void ANeonParadigm_GameCharacter::PerformDeath()
{
	CharacterState->SetState(ECharacterStates::Death);
	PlayAnimMontage(DeathMontage);
	DisableInput(UGameplayStatics::GetPlayerController(GetWorld(), 0));

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
