// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NeonParadigm_Game/NeonParadigm_GameCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNeonParadigm_GameCharacter() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	ENGINE_API UClass* Z_Construct_UClass_AController_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCurveFloat_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UDamageType_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UParticleSystem_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_ANeonParadigm_GameCharacter();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_ANeonParadigm_GameCharacter_NoRegister();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UAttackComponent_NoRegister();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UCharacterStateComponent_NoRegister();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UDamageComponent_NoRegister();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UScoreComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_NeonParadigm_Game();
// End Cross Module References
	DEFINE_FUNCTION(ANeonParadigm_GameCharacter::execStartEnemyEncounter)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StartEnemyEncounter();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANeonParadigm_GameCharacter::execAddToCurrentHealth)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_HealthToAdd);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddToCurrentHealth(Z_Param_HealthToAdd);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANeonParadigm_GameCharacter::execAddToCurrentRage)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_RageToAdd);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddToCurrentRage(Z_Param_RageToAdd);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANeonParadigm_GameCharacter::execSoftTargetingTimelineUpdated)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_Alpha);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SoftTargetingTimelineUpdated(Z_Param_Alpha);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANeonParadigm_GameCharacter::execIsPerfectBeatHit)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsPerfectBeatHit();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANeonParadigm_GameCharacter::execCounter)
	{
		P_GET_UBOOL(Z_Param_ProjectileCounter);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Counter(Z_Param_ProjectileCounter);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANeonParadigm_GameCharacter::execHandleTakeAnyDamage)
	{
		P_GET_OBJECT(AActor,Z_Param_DamagedActor);
		P_GET_PROPERTY(FFloatProperty,Z_Param_Damage);
		P_GET_OBJECT(UDamageType,Z_Param_DamageType);
		P_GET_OBJECT(AController,Z_Param_InstigatedBy);
		P_GET_OBJECT(AActor,Z_Param_DamageCauser);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->HandleTakeAnyDamage(Z_Param_DamagedActor,Z_Param_Damage,Z_Param_DamageType,Z_Param_InstigatedBy,Z_Param_DamageCauser);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANeonParadigm_GameCharacter::execIsIFramesEnabled)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsIFramesEnabled();
		P_NATIVE_END;
	}
	struct NeonParadigm_GameCharacter_eventPlayBPM_HalfCirle_Parms
	{
		float CurrentTempo;
	};
	static FName NAME_ANeonParadigm_GameCharacter_BeginBPM_Bar = FName(TEXT("BeginBPM_Bar"));
	void ANeonParadigm_GameCharacter::BeginBPM_Bar()
	{
		ProcessEvent(FindFunctionChecked(NAME_ANeonParadigm_GameCharacter_BeginBPM_Bar),NULL);
	}
	static FName NAME_ANeonParadigm_GameCharacter_ParryProjectile = FName(TEXT("ParryProjectile"));
	void ANeonParadigm_GameCharacter::ParryProjectile()
	{
		ProcessEvent(FindFunctionChecked(NAME_ANeonParadigm_GameCharacter_ParryProjectile),NULL);
	}
	static FName NAME_ANeonParadigm_GameCharacter_PlayBPM_HalfCirle = FName(TEXT("PlayBPM_HalfCirle"));
	void ANeonParadigm_GameCharacter::PlayBPM_HalfCirle(float CurrentTempo)
	{
		NeonParadigm_GameCharacter_eventPlayBPM_HalfCirle_Parms Parms;
		Parms.CurrentTempo=CurrentTempo;
		ProcessEvent(FindFunctionChecked(NAME_ANeonParadigm_GameCharacter_PlayBPM_HalfCirle),&Parms);
	}
	static FName NAME_ANeonParadigm_GameCharacter_SpawnLoseMenu = FName(TEXT("SpawnLoseMenu"));
	void ANeonParadigm_GameCharacter::SpawnLoseMenu()
	{
		ProcessEvent(FindFunctionChecked(NAME_ANeonParadigm_GameCharacter_SpawnLoseMenu),NULL);
	}
	static FName NAME_ANeonParadigm_GameCharacter_ToggleCombatStyleGrade = FName(TEXT("ToggleCombatStyleGrade"));
	void ANeonParadigm_GameCharacter::ToggleCombatStyleGrade()
	{
		ProcessEvent(FindFunctionChecked(NAME_ANeonParadigm_GameCharacter_ToggleCombatStyleGrade),NULL);
	}
	static FName NAME_ANeonParadigm_GameCharacter_ToggleEncounterResults = FName(TEXT("ToggleEncounterResults"));
	void ANeonParadigm_GameCharacter::ToggleEncounterResults()
	{
		ProcessEvent(FindFunctionChecked(NAME_ANeonParadigm_GameCharacter_ToggleEncounterResults),NULL);
	}
	static FName NAME_ANeonParadigm_GameCharacter_TogglePerfectHitTextBox = FName(TEXT("TogglePerfectHitTextBox"));
	void ANeonParadigm_GameCharacter::TogglePerfectHitTextBox()
	{
		ProcessEvent(FindFunctionChecked(NAME_ANeonParadigm_GameCharacter_TogglePerfectHitTextBox),NULL);
	}
	static FName NAME_ANeonParadigm_GameCharacter_UpdateHealthBarEvent = FName(TEXT("UpdateHealthBarEvent"));
	void ANeonParadigm_GameCharacter::UpdateHealthBarEvent()
	{
		ProcessEvent(FindFunctionChecked(NAME_ANeonParadigm_GameCharacter_UpdateHealthBarEvent),NULL);
	}
	static FName NAME_ANeonParadigm_GameCharacter_UpdateProjectileWeaponBarEvent = FName(TEXT("UpdateProjectileWeaponBarEvent"));
	void ANeonParadigm_GameCharacter::UpdateProjectileWeaponBarEvent()
	{
		ProcessEvent(FindFunctionChecked(NAME_ANeonParadigm_GameCharacter_UpdateProjectileWeaponBarEvent),NULL);
	}
	static FName NAME_ANeonParadigm_GameCharacter_UpdateRageBarEvent = FName(TEXT("UpdateRageBarEvent"));
	void ANeonParadigm_GameCharacter::UpdateRageBarEvent()
	{
		ProcessEvent(FindFunctionChecked(NAME_ANeonParadigm_GameCharacter_UpdateRageBarEvent),NULL);
	}
	static FName NAME_ANeonParadigm_GameCharacter_UpdateScoreEvent = FName(TEXT("UpdateScoreEvent"));
	void ANeonParadigm_GameCharacter::UpdateScoreEvent()
	{
		ProcessEvent(FindFunctionChecked(NAME_ANeonParadigm_GameCharacter_UpdateScoreEvent),NULL);
	}
	void ANeonParadigm_GameCharacter::StaticRegisterNativesANeonParadigm_GameCharacter()
	{
		UClass* Class = ANeonParadigm_GameCharacter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddToCurrentHealth", &ANeonParadigm_GameCharacter::execAddToCurrentHealth },
			{ "AddToCurrentRage", &ANeonParadigm_GameCharacter::execAddToCurrentRage },
			{ "Counter", &ANeonParadigm_GameCharacter::execCounter },
			{ "HandleTakeAnyDamage", &ANeonParadigm_GameCharacter::execHandleTakeAnyDamage },
			{ "IsIFramesEnabled", &ANeonParadigm_GameCharacter::execIsIFramesEnabled },
			{ "IsPerfectBeatHit", &ANeonParadigm_GameCharacter::execIsPerfectBeatHit },
			{ "SoftTargetingTimelineUpdated", &ANeonParadigm_GameCharacter::execSoftTargetingTimelineUpdated },
			{ "StartEnemyEncounter", &ANeonParadigm_GameCharacter::execStartEnemyEncounter },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ANeonParadigm_GameCharacter_AddToCurrentHealth_Statics
	{
		struct NeonParadigm_GameCharacter_eventAddToCurrentHealth_Parms
		{
			float HealthToAdd;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_HealthToAdd;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ANeonParadigm_GameCharacter_AddToCurrentHealth_Statics::NewProp_HealthToAdd = { "HealthToAdd", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NeonParadigm_GameCharacter_eventAddToCurrentHealth_Parms, HealthToAdd), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANeonParadigm_GameCharacter_AddToCurrentHealth_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANeonParadigm_GameCharacter_AddToCurrentHealth_Statics::NewProp_HealthToAdd,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANeonParadigm_GameCharacter_AddToCurrentHealth_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANeonParadigm_GameCharacter_AddToCurrentHealth_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANeonParadigm_GameCharacter, nullptr, "AddToCurrentHealth", nullptr, nullptr, Z_Construct_UFunction_ANeonParadigm_GameCharacter_AddToCurrentHealth_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANeonParadigm_GameCharacter_AddToCurrentHealth_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANeonParadigm_GameCharacter_AddToCurrentHealth_Statics::NeonParadigm_GameCharacter_eventAddToCurrentHealth_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANeonParadigm_GameCharacter_AddToCurrentHealth_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANeonParadigm_GameCharacter_AddToCurrentHealth_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANeonParadigm_GameCharacter_AddToCurrentHealth_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ANeonParadigm_GameCharacter_AddToCurrentHealth_Statics::NeonParadigm_GameCharacter_eventAddToCurrentHealth_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANeonParadigm_GameCharacter_AddToCurrentHealth()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANeonParadigm_GameCharacter_AddToCurrentHealth_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANeonParadigm_GameCharacter_AddToCurrentRage_Statics
	{
		struct NeonParadigm_GameCharacter_eventAddToCurrentRage_Parms
		{
			float RageToAdd;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_RageToAdd;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ANeonParadigm_GameCharacter_AddToCurrentRage_Statics::NewProp_RageToAdd = { "RageToAdd", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NeonParadigm_GameCharacter_eventAddToCurrentRage_Parms, RageToAdd), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANeonParadigm_GameCharacter_AddToCurrentRage_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANeonParadigm_GameCharacter_AddToCurrentRage_Statics::NewProp_RageToAdd,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANeonParadigm_GameCharacter_AddToCurrentRage_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANeonParadigm_GameCharacter_AddToCurrentRage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANeonParadigm_GameCharacter, nullptr, "AddToCurrentRage", nullptr, nullptr, Z_Construct_UFunction_ANeonParadigm_GameCharacter_AddToCurrentRage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANeonParadigm_GameCharacter_AddToCurrentRage_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANeonParadigm_GameCharacter_AddToCurrentRage_Statics::NeonParadigm_GameCharacter_eventAddToCurrentRage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANeonParadigm_GameCharacter_AddToCurrentRage_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANeonParadigm_GameCharacter_AddToCurrentRage_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANeonParadigm_GameCharacter_AddToCurrentRage_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ANeonParadigm_GameCharacter_AddToCurrentRage_Statics::NeonParadigm_GameCharacter_eventAddToCurrentRage_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANeonParadigm_GameCharacter_AddToCurrentRage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANeonParadigm_GameCharacter_AddToCurrentRage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANeonParadigm_GameCharacter_BeginBPM_Bar_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANeonParadigm_GameCharacter_BeginBPM_Bar_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANeonParadigm_GameCharacter_BeginBPM_Bar_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANeonParadigm_GameCharacter, nullptr, "BeginBPM_Bar", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANeonParadigm_GameCharacter_BeginBPM_Bar_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANeonParadigm_GameCharacter_BeginBPM_Bar_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ANeonParadigm_GameCharacter_BeginBPM_Bar()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANeonParadigm_GameCharacter_BeginBPM_Bar_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANeonParadigm_GameCharacter_Counter_Statics
	{
		struct NeonParadigm_GameCharacter_eventCounter_Parms
		{
			bool ProjectileCounter;
		};
		static void NewProp_ProjectileCounter_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ProjectileCounter;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ANeonParadigm_GameCharacter_Counter_Statics::NewProp_ProjectileCounter_SetBit(void* Obj)
	{
		((NeonParadigm_GameCharacter_eventCounter_Parms*)Obj)->ProjectileCounter = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ANeonParadigm_GameCharacter_Counter_Statics::NewProp_ProjectileCounter = { "ProjectileCounter", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(NeonParadigm_GameCharacter_eventCounter_Parms), &Z_Construct_UFunction_ANeonParadigm_GameCharacter_Counter_Statics::NewProp_ProjectileCounter_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANeonParadigm_GameCharacter_Counter_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANeonParadigm_GameCharacter_Counter_Statics::NewProp_ProjectileCounter,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANeonParadigm_GameCharacter_Counter_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANeonParadigm_GameCharacter_Counter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANeonParadigm_GameCharacter, nullptr, "Counter", nullptr, nullptr, Z_Construct_UFunction_ANeonParadigm_GameCharacter_Counter_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANeonParadigm_GameCharacter_Counter_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANeonParadigm_GameCharacter_Counter_Statics::NeonParadigm_GameCharacter_eventCounter_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANeonParadigm_GameCharacter_Counter_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANeonParadigm_GameCharacter_Counter_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANeonParadigm_GameCharacter_Counter_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ANeonParadigm_GameCharacter_Counter_Statics::NeonParadigm_GameCharacter_eventCounter_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANeonParadigm_GameCharacter_Counter()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANeonParadigm_GameCharacter_Counter_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANeonParadigm_GameCharacter_HandleTakeAnyDamage_Statics
	{
		struct NeonParadigm_GameCharacter_eventHandleTakeAnyDamage_Parms
		{
			AActor* DamagedActor;
			float Damage;
			const UDamageType* DamageType;
			AController* InstigatedBy;
			AActor* DamageCauser;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DamagedActor;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Damage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DamageType_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DamageType;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InstigatedBy;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DamageCauser;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ANeonParadigm_GameCharacter_HandleTakeAnyDamage_Statics::NewProp_DamagedActor = { "DamagedActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NeonParadigm_GameCharacter_eventHandleTakeAnyDamage_Parms, DamagedActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ANeonParadigm_GameCharacter_HandleTakeAnyDamage_Statics::NewProp_Damage = { "Damage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NeonParadigm_GameCharacter_eventHandleTakeAnyDamage_Parms, Damage), METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANeonParadigm_GameCharacter_HandleTakeAnyDamage_Statics::NewProp_DamageType_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ANeonParadigm_GameCharacter_HandleTakeAnyDamage_Statics::NewProp_DamageType = { "DamageType", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NeonParadigm_GameCharacter_eventHandleTakeAnyDamage_Parms, DamageType), Z_Construct_UClass_UDamageType_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANeonParadigm_GameCharacter_HandleTakeAnyDamage_Statics::NewProp_DamageType_MetaData), Z_Construct_UFunction_ANeonParadigm_GameCharacter_HandleTakeAnyDamage_Statics::NewProp_DamageType_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ANeonParadigm_GameCharacter_HandleTakeAnyDamage_Statics::NewProp_InstigatedBy = { "InstigatedBy", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NeonParadigm_GameCharacter_eventHandleTakeAnyDamage_Parms, InstigatedBy), Z_Construct_UClass_AController_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ANeonParadigm_GameCharacter_HandleTakeAnyDamage_Statics::NewProp_DamageCauser = { "DamageCauser", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NeonParadigm_GameCharacter_eventHandleTakeAnyDamage_Parms, DamageCauser), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANeonParadigm_GameCharacter_HandleTakeAnyDamage_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANeonParadigm_GameCharacter_HandleTakeAnyDamage_Statics::NewProp_DamagedActor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANeonParadigm_GameCharacter_HandleTakeAnyDamage_Statics::NewProp_Damage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANeonParadigm_GameCharacter_HandleTakeAnyDamage_Statics::NewProp_DamageType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANeonParadigm_GameCharacter_HandleTakeAnyDamage_Statics::NewProp_InstigatedBy,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANeonParadigm_GameCharacter_HandleTakeAnyDamage_Statics::NewProp_DamageCauser,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANeonParadigm_GameCharacter_HandleTakeAnyDamage_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANeonParadigm_GameCharacter_HandleTakeAnyDamage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANeonParadigm_GameCharacter, nullptr, "HandleTakeAnyDamage", nullptr, nullptr, Z_Construct_UFunction_ANeonParadigm_GameCharacter_HandleTakeAnyDamage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANeonParadigm_GameCharacter_HandleTakeAnyDamage_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANeonParadigm_GameCharacter_HandleTakeAnyDamage_Statics::NeonParadigm_GameCharacter_eventHandleTakeAnyDamage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANeonParadigm_GameCharacter_HandleTakeAnyDamage_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANeonParadigm_GameCharacter_HandleTakeAnyDamage_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANeonParadigm_GameCharacter_HandleTakeAnyDamage_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ANeonParadigm_GameCharacter_HandleTakeAnyDamage_Statics::NeonParadigm_GameCharacter_eventHandleTakeAnyDamage_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANeonParadigm_GameCharacter_HandleTakeAnyDamage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANeonParadigm_GameCharacter_HandleTakeAnyDamage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANeonParadigm_GameCharacter_IsIFramesEnabled_Statics
	{
		struct NeonParadigm_GameCharacter_eventIsIFramesEnabled_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ANeonParadigm_GameCharacter_IsIFramesEnabled_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((NeonParadigm_GameCharacter_eventIsIFramesEnabled_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ANeonParadigm_GameCharacter_IsIFramesEnabled_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(NeonParadigm_GameCharacter_eventIsIFramesEnabled_Parms), &Z_Construct_UFunction_ANeonParadigm_GameCharacter_IsIFramesEnabled_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANeonParadigm_GameCharacter_IsIFramesEnabled_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANeonParadigm_GameCharacter_IsIFramesEnabled_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANeonParadigm_GameCharacter_IsIFramesEnabled_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANeonParadigm_GameCharacter_IsIFramesEnabled_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANeonParadigm_GameCharacter, nullptr, "IsIFramesEnabled", nullptr, nullptr, Z_Construct_UFunction_ANeonParadigm_GameCharacter_IsIFramesEnabled_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANeonParadigm_GameCharacter_IsIFramesEnabled_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANeonParadigm_GameCharacter_IsIFramesEnabled_Statics::NeonParadigm_GameCharacter_eventIsIFramesEnabled_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANeonParadigm_GameCharacter_IsIFramesEnabled_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANeonParadigm_GameCharacter_IsIFramesEnabled_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANeonParadigm_GameCharacter_IsIFramesEnabled_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ANeonParadigm_GameCharacter_IsIFramesEnabled_Statics::NeonParadigm_GameCharacter_eventIsIFramesEnabled_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANeonParadigm_GameCharacter_IsIFramesEnabled()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANeonParadigm_GameCharacter_IsIFramesEnabled_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANeonParadigm_GameCharacter_IsPerfectBeatHit_Statics
	{
		struct NeonParadigm_GameCharacter_eventIsPerfectBeatHit_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ANeonParadigm_GameCharacter_IsPerfectBeatHit_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((NeonParadigm_GameCharacter_eventIsPerfectBeatHit_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ANeonParadigm_GameCharacter_IsPerfectBeatHit_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(NeonParadigm_GameCharacter_eventIsPerfectBeatHit_Parms), &Z_Construct_UFunction_ANeonParadigm_GameCharacter_IsPerfectBeatHit_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANeonParadigm_GameCharacter_IsPerfectBeatHit_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANeonParadigm_GameCharacter_IsPerfectBeatHit_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANeonParadigm_GameCharacter_IsPerfectBeatHit_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANeonParadigm_GameCharacter_IsPerfectBeatHit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANeonParadigm_GameCharacter, nullptr, "IsPerfectBeatHit", nullptr, nullptr, Z_Construct_UFunction_ANeonParadigm_GameCharacter_IsPerfectBeatHit_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANeonParadigm_GameCharacter_IsPerfectBeatHit_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANeonParadigm_GameCharacter_IsPerfectBeatHit_Statics::NeonParadigm_GameCharacter_eventIsPerfectBeatHit_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANeonParadigm_GameCharacter_IsPerfectBeatHit_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANeonParadigm_GameCharacter_IsPerfectBeatHit_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANeonParadigm_GameCharacter_IsPerfectBeatHit_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ANeonParadigm_GameCharacter_IsPerfectBeatHit_Statics::NeonParadigm_GameCharacter_eventIsPerfectBeatHit_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANeonParadigm_GameCharacter_IsPerfectBeatHit()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANeonParadigm_GameCharacter_IsPerfectBeatHit_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANeonParadigm_GameCharacter_ParryProjectile_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANeonParadigm_GameCharacter_ParryProjectile_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANeonParadigm_GameCharacter_ParryProjectile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANeonParadigm_GameCharacter, nullptr, "ParryProjectile", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANeonParadigm_GameCharacter_ParryProjectile_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANeonParadigm_GameCharacter_ParryProjectile_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ANeonParadigm_GameCharacter_ParryProjectile()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANeonParadigm_GameCharacter_ParryProjectile_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANeonParadigm_GameCharacter_PlayBPM_HalfCirle_Statics
	{
		static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentTempo;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ANeonParadigm_GameCharacter_PlayBPM_HalfCirle_Statics::NewProp_CurrentTempo = { "CurrentTempo", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NeonParadigm_GameCharacter_eventPlayBPM_HalfCirle_Parms, CurrentTempo), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANeonParadigm_GameCharacter_PlayBPM_HalfCirle_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANeonParadigm_GameCharacter_PlayBPM_HalfCirle_Statics::NewProp_CurrentTempo,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANeonParadigm_GameCharacter_PlayBPM_HalfCirle_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANeonParadigm_GameCharacter_PlayBPM_HalfCirle_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANeonParadigm_GameCharacter, nullptr, "PlayBPM_HalfCirle", nullptr, nullptr, Z_Construct_UFunction_ANeonParadigm_GameCharacter_PlayBPM_HalfCirle_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANeonParadigm_GameCharacter_PlayBPM_HalfCirle_Statics::PropPointers), sizeof(NeonParadigm_GameCharacter_eventPlayBPM_HalfCirle_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANeonParadigm_GameCharacter_PlayBPM_HalfCirle_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANeonParadigm_GameCharacter_PlayBPM_HalfCirle_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANeonParadigm_GameCharacter_PlayBPM_HalfCirle_Statics::PropPointers) < 2048);
	static_assert(sizeof(NeonParadigm_GameCharacter_eventPlayBPM_HalfCirle_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANeonParadigm_GameCharacter_PlayBPM_HalfCirle()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANeonParadigm_GameCharacter_PlayBPM_HalfCirle_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANeonParadigm_GameCharacter_SoftTargetingTimelineUpdated_Statics
	{
		struct NeonParadigm_GameCharacter_eventSoftTargetingTimelineUpdated_Parms
		{
			float Alpha;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Alpha;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ANeonParadigm_GameCharacter_SoftTargetingTimelineUpdated_Statics::NewProp_Alpha = { "Alpha", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NeonParadigm_GameCharacter_eventSoftTargetingTimelineUpdated_Parms, Alpha), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANeonParadigm_GameCharacter_SoftTargetingTimelineUpdated_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANeonParadigm_GameCharacter_SoftTargetingTimelineUpdated_Statics::NewProp_Alpha,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANeonParadigm_GameCharacter_SoftTargetingTimelineUpdated_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANeonParadigm_GameCharacter_SoftTargetingTimelineUpdated_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANeonParadigm_GameCharacter, nullptr, "SoftTargetingTimelineUpdated", nullptr, nullptr, Z_Construct_UFunction_ANeonParadigm_GameCharacter_SoftTargetingTimelineUpdated_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANeonParadigm_GameCharacter_SoftTargetingTimelineUpdated_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANeonParadigm_GameCharacter_SoftTargetingTimelineUpdated_Statics::NeonParadigm_GameCharacter_eventSoftTargetingTimelineUpdated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANeonParadigm_GameCharacter_SoftTargetingTimelineUpdated_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANeonParadigm_GameCharacter_SoftTargetingTimelineUpdated_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANeonParadigm_GameCharacter_SoftTargetingTimelineUpdated_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ANeonParadigm_GameCharacter_SoftTargetingTimelineUpdated_Statics::NeonParadigm_GameCharacter_eventSoftTargetingTimelineUpdated_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANeonParadigm_GameCharacter_SoftTargetingTimelineUpdated()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANeonParadigm_GameCharacter_SoftTargetingTimelineUpdated_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANeonParadigm_GameCharacter_SpawnLoseMenu_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANeonParadigm_GameCharacter_SpawnLoseMenu_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANeonParadigm_GameCharacter_SpawnLoseMenu_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANeonParadigm_GameCharacter, nullptr, "SpawnLoseMenu", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANeonParadigm_GameCharacter_SpawnLoseMenu_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANeonParadigm_GameCharacter_SpawnLoseMenu_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ANeonParadigm_GameCharacter_SpawnLoseMenu()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANeonParadigm_GameCharacter_SpawnLoseMenu_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANeonParadigm_GameCharacter_StartEnemyEncounter_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANeonParadigm_GameCharacter_StartEnemyEncounter_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANeonParadigm_GameCharacter_StartEnemyEncounter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANeonParadigm_GameCharacter, nullptr, "StartEnemyEncounter", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANeonParadigm_GameCharacter_StartEnemyEncounter_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANeonParadigm_GameCharacter_StartEnemyEncounter_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ANeonParadigm_GameCharacter_StartEnemyEncounter()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANeonParadigm_GameCharacter_StartEnemyEncounter_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANeonParadigm_GameCharacter_ToggleCombatStyleGrade_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANeonParadigm_GameCharacter_ToggleCombatStyleGrade_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANeonParadigm_GameCharacter_ToggleCombatStyleGrade_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANeonParadigm_GameCharacter, nullptr, "ToggleCombatStyleGrade", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANeonParadigm_GameCharacter_ToggleCombatStyleGrade_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANeonParadigm_GameCharacter_ToggleCombatStyleGrade_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ANeonParadigm_GameCharacter_ToggleCombatStyleGrade()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANeonParadigm_GameCharacter_ToggleCombatStyleGrade_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANeonParadigm_GameCharacter_ToggleEncounterResults_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANeonParadigm_GameCharacter_ToggleEncounterResults_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANeonParadigm_GameCharacter_ToggleEncounterResults_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANeonParadigm_GameCharacter, nullptr, "ToggleEncounterResults", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANeonParadigm_GameCharacter_ToggleEncounterResults_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANeonParadigm_GameCharacter_ToggleEncounterResults_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ANeonParadigm_GameCharacter_ToggleEncounterResults()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANeonParadigm_GameCharacter_ToggleEncounterResults_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANeonParadigm_GameCharacter_TogglePerfectHitTextBox_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANeonParadigm_GameCharacter_TogglePerfectHitTextBox_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANeonParadigm_GameCharacter_TogglePerfectHitTextBox_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANeonParadigm_GameCharacter, nullptr, "TogglePerfectHitTextBox", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANeonParadigm_GameCharacter_TogglePerfectHitTextBox_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANeonParadigm_GameCharacter_TogglePerfectHitTextBox_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ANeonParadigm_GameCharacter_TogglePerfectHitTextBox()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANeonParadigm_GameCharacter_TogglePerfectHitTextBox_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANeonParadigm_GameCharacter_UpdateHealthBarEvent_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANeonParadigm_GameCharacter_UpdateHealthBarEvent_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANeonParadigm_GameCharacter_UpdateHealthBarEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANeonParadigm_GameCharacter, nullptr, "UpdateHealthBarEvent", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANeonParadigm_GameCharacter_UpdateHealthBarEvent_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANeonParadigm_GameCharacter_UpdateHealthBarEvent_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ANeonParadigm_GameCharacter_UpdateHealthBarEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANeonParadigm_GameCharacter_UpdateHealthBarEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANeonParadigm_GameCharacter_UpdateProjectileWeaponBarEvent_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANeonParadigm_GameCharacter_UpdateProjectileWeaponBarEvent_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANeonParadigm_GameCharacter_UpdateProjectileWeaponBarEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANeonParadigm_GameCharacter, nullptr, "UpdateProjectileWeaponBarEvent", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANeonParadigm_GameCharacter_UpdateProjectileWeaponBarEvent_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANeonParadigm_GameCharacter_UpdateProjectileWeaponBarEvent_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ANeonParadigm_GameCharacter_UpdateProjectileWeaponBarEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANeonParadigm_GameCharacter_UpdateProjectileWeaponBarEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANeonParadigm_GameCharacter_UpdateRageBarEvent_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANeonParadigm_GameCharacter_UpdateRageBarEvent_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANeonParadigm_GameCharacter_UpdateRageBarEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANeonParadigm_GameCharacter, nullptr, "UpdateRageBarEvent", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANeonParadigm_GameCharacter_UpdateRageBarEvent_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANeonParadigm_GameCharacter_UpdateRageBarEvent_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ANeonParadigm_GameCharacter_UpdateRageBarEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANeonParadigm_GameCharacter_UpdateRageBarEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANeonParadigm_GameCharacter_UpdateScoreEvent_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANeonParadigm_GameCharacter_UpdateScoreEvent_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANeonParadigm_GameCharacter_UpdateScoreEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANeonParadigm_GameCharacter, nullptr, "UpdateScoreEvent", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANeonParadigm_GameCharacter_UpdateScoreEvent_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANeonParadigm_GameCharacter_UpdateScoreEvent_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ANeonParadigm_GameCharacter_UpdateScoreEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANeonParadigm_GameCharacter_UpdateScoreEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ANeonParadigm_GameCharacter);
	UClass* Z_Construct_UClass_ANeonParadigm_GameCharacter_NoRegister()
	{
		return ANeonParadigm_GameCharacter::StaticClass();
	}
	struct Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FollowCamera_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_FollowCamera;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultMappingContext_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultMappingContext;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_JumpAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MoveAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LookAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LookAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LightAttackAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LightAttackAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HeavyAttackAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_HeavyAttackAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DodgeAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DodgeAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TargetAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ParryAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ParryAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RageAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_RageAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileWeaponAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ProjectileWeaponAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CharacterState_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CharacterState;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WeaponMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WeaponMesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AttackComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AttackComp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DamageComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DamageComp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BPM_OrbSpringArm_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_BPM_OrbSpringArm;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BPM_OrbMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_BPM_OrbMesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DodgeMontage_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DodgeMontage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DoubleJumpMontage_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DoubleJumpMontage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxTargetingDistance_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxTargetingDistance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TargetingOffset_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_TargetingOffset;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CameraRotationSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_CameraRotationSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TargetingDistance_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_TargetingDistance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxSoftTargetDistance_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxSoftTargetDistance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CurrentHealth_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentHealth;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxHealth_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxHealth;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CurrentRage_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentRage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxRage_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxRage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RageDepletionRate_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_RageDepletionRate;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RageDepletionAmount_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_RageDepletionAmount;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RageActivationThreshold_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_RageActivationThreshold;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DeathMontage_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DeathMontage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ParryMontage_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ParryMontage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CounterMontage_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CounterMontage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileCounterMontage_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ProjectileCounterMontage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TestRhythmMontage_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TestRhythmMontage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RageEmitter_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_RageEmitter;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RageAnim_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_RageAnim;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RageOverlayMaterial_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_RageOverlayMaterial;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InitialRageOverlayMaterial_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InitialRageOverlayMaterial;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ScoreComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ScoreComp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SoftTargetCurve_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SoftTargetCurve;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileWeaponMontage_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ProjectileWeaponMontage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultCameraBoomLength_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DefaultCameraBoomLength;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CameraBoomLength_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_CameraBoomLength;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CooldownProjectileDuration_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_CooldownProjectileDuration;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileCooldownProgress_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ProjectileCooldownProgress;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_NeonParadigm_Game,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ANeonParadigm_GameCharacter_AddToCurrentHealth, "AddToCurrentHealth" }, // 2749478277
		{ &Z_Construct_UFunction_ANeonParadigm_GameCharacter_AddToCurrentRage, "AddToCurrentRage" }, // 3015622019
		{ &Z_Construct_UFunction_ANeonParadigm_GameCharacter_BeginBPM_Bar, "BeginBPM_Bar" }, // 2382676977
		{ &Z_Construct_UFunction_ANeonParadigm_GameCharacter_Counter, "Counter" }, // 1905309954
		{ &Z_Construct_UFunction_ANeonParadigm_GameCharacter_HandleTakeAnyDamage, "HandleTakeAnyDamage" }, // 1697673734
		{ &Z_Construct_UFunction_ANeonParadigm_GameCharacter_IsIFramesEnabled, "IsIFramesEnabled" }, // 966977221
		{ &Z_Construct_UFunction_ANeonParadigm_GameCharacter_IsPerfectBeatHit, "IsPerfectBeatHit" }, // 888660779
		{ &Z_Construct_UFunction_ANeonParadigm_GameCharacter_ParryProjectile, "ParryProjectile" }, // 650497423
		{ &Z_Construct_UFunction_ANeonParadigm_GameCharacter_PlayBPM_HalfCirle, "PlayBPM_HalfCirle" }, // 4169588176
		{ &Z_Construct_UFunction_ANeonParadigm_GameCharacter_SoftTargetingTimelineUpdated, "SoftTargetingTimelineUpdated" }, // 3836165723
		{ &Z_Construct_UFunction_ANeonParadigm_GameCharacter_SpawnLoseMenu, "SpawnLoseMenu" }, // 1954400783
		{ &Z_Construct_UFunction_ANeonParadigm_GameCharacter_StartEnemyEncounter, "StartEnemyEncounter" }, // 3159900810
		{ &Z_Construct_UFunction_ANeonParadigm_GameCharacter_ToggleCombatStyleGrade, "ToggleCombatStyleGrade" }, // 1868853353
		{ &Z_Construct_UFunction_ANeonParadigm_GameCharacter_ToggleEncounterResults, "ToggleEncounterResults" }, // 4206137137
		{ &Z_Construct_UFunction_ANeonParadigm_GameCharacter_TogglePerfectHitTextBox, "TogglePerfectHitTextBox" }, // 629264535
		{ &Z_Construct_UFunction_ANeonParadigm_GameCharacter_UpdateHealthBarEvent, "UpdateHealthBarEvent" }, // 733924716
		{ &Z_Construct_UFunction_ANeonParadigm_GameCharacter_UpdateProjectileWeaponBarEvent, "UpdateProjectileWeaponBarEvent" }, // 1061568246
		{ &Z_Construct_UFunction_ANeonParadigm_GameCharacter_UpdateRageBarEvent, "UpdateRageBarEvent" }, // 2654697491
		{ &Z_Construct_UFunction_ANeonParadigm_GameCharacter_UpdateScoreEvent, "UpdateScoreEvent" }, // 3055866101
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "NeonParadigm_GameCharacter.h" },
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CameraBoom_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Camera boom positioning the camera behind the character */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Camera boom positioning the camera behind the character" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CameraBoom_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CameraBoom_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_FollowCamera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Follow camera */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Follow camera" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_FollowCamera = { "FollowCamera", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, FollowCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_FollowCamera_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_FollowCamera_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_DefaultMappingContext_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** MappingContext */" },
#endif
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "MappingContext" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_DefaultMappingContext = { "DefaultMappingContext", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, DefaultMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_DefaultMappingContext_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_DefaultMappingContext_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_JumpAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Jump Input Action */" },
#endif
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Jump Input Action" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_JumpAction = { "JumpAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, JumpAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_JumpAction_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_JumpAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_MoveAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Move Input Action */" },
#endif
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Move Input Action" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_MoveAction = { "MoveAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, MoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_MoveAction_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_MoveAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_LookAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Look Input Action */" },
#endif
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Look Input Action" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_LookAction = { "LookAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, LookAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_LookAction_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_LookAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_LightAttackAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Light Attack Input Action */" },
#endif
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Light Attack Input Action" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_LightAttackAction = { "LightAttackAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, LightAttackAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_LightAttackAction_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_LightAttackAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_HeavyAttackAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Heavy Attack Input Action */" },
#endif
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Heavy Attack Input Action" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_HeavyAttackAction = { "HeavyAttackAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, HeavyAttackAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_HeavyAttackAction_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_HeavyAttackAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_DodgeAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Dodge Input Action */" },
#endif
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Dodge Input Action" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_DodgeAction = { "DodgeAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, DodgeAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_DodgeAction_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_DodgeAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_TargetAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Target Input Action */" },
#endif
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Target Input Action" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_TargetAction = { "TargetAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, TargetAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_TargetAction_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_TargetAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_ParryAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Parry Input Action */" },
#endif
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Parry Input Action" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_ParryAction = { "ParryAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, ParryAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_ParryAction_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_ParryAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_RageAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Rage Mode Input Action */" },
#endif
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Rage Mode Input Action" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_RageAction = { "RageAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, RageAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_RageAction_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_RageAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_ProjectileWeaponAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Projectile Weapon Input Action */" },
#endif
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Projectile Weapon Input Action" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_ProjectileWeaponAction = { "ProjectileWeaponAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, ProjectileWeaponAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_ProjectileWeaponAction_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_ProjectileWeaponAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CharacterState_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "State" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CharacterState = { "CharacterState", nullptr, (EPropertyFlags)0x004000000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, CharacterState), Z_Construct_UClass_UCharacterStateComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CharacterState_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CharacterState_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_WeaponMesh_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_WeaponMesh = { "WeaponMesh", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, WeaponMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_WeaponMesh_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_WeaponMesh_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_AttackComp_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Attack" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_AttackComp = { "AttackComp", nullptr, (EPropertyFlags)0x004000000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, AttackComp), Z_Construct_UClass_UAttackComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_AttackComp_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_AttackComp_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_DamageComp_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Damage" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_DamageComp = { "DamageComp", nullptr, (EPropertyFlags)0x004000000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, DamageComp), Z_Construct_UClass_UDamageComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_DamageComp_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_DamageComp_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_BPM_OrbSpringArm_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Mesh" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** BPM Orb Spring Arm */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "BPM Orb Spring Arm" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_BPM_OrbSpringArm = { "BPM_OrbSpringArm", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, BPM_OrbSpringArm), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_BPM_OrbSpringArm_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_BPM_OrbSpringArm_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_BPM_OrbMesh_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Mesh" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_BPM_OrbMesh = { "BPM_OrbMesh", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, BPM_OrbMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_BPM_OrbMesh_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_BPM_OrbMesh_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_DodgeMontage_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Attack" },
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_DodgeMontage = { "DodgeMontage", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, DodgeMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_DodgeMontage_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_DodgeMontage_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_DoubleJumpMontage_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Attack" },
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_DoubleJumpMontage = { "DoubleJumpMontage", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, DoubleJumpMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_DoubleJumpMontage_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_DoubleJumpMontage_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_MaxTargetingDistance_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Targeting" },
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_MaxTargetingDistance = { "MaxTargetingDistance", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, MaxTargetingDistance), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_MaxTargetingDistance_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_MaxTargetingDistance_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_TargetingOffset_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Targeting" },
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_TargetingOffset = { "TargetingOffset", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, TargetingOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_TargetingOffset_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_TargetingOffset_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CameraRotationSpeed_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Targeting" },
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CameraRotationSpeed = { "CameraRotationSpeed", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, CameraRotationSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CameraRotationSpeed_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CameraRotationSpeed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_TargetingDistance_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Targeting" },
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_TargetingDistance = { "TargetingDistance", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, TargetingDistance), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_TargetingDistance_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_TargetingDistance_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_MaxSoftTargetDistance_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Targeting" },
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_MaxSoftTargetDistance = { "MaxSoftTargetDistance", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, MaxSoftTargetDistance), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_MaxSoftTargetDistance_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_MaxSoftTargetDistance_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CurrentHealth_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Stats" },
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CurrentHealth = { "CurrentHealth", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, CurrentHealth), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CurrentHealth_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CurrentHealth_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_MaxHealth_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Stats" },
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_MaxHealth = { "MaxHealth", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, MaxHealth), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_MaxHealth_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_MaxHealth_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CurrentRage_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Rage" },
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CurrentRage = { "CurrentRage", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, CurrentRage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CurrentRage_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CurrentRage_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_MaxRage_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Rage" },
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_MaxRage = { "MaxRage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, MaxRage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_MaxRage_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_MaxRage_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_RageDepletionRate_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Rage" },
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_RageDepletionRate = { "RageDepletionRate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, RageDepletionRate), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_RageDepletionRate_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_RageDepletionRate_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_RageDepletionAmount_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Rage" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Decrease rage every second\n" },
#endif
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Decrease rage every second" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_RageDepletionAmount = { "RageDepletionAmount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, RageDepletionAmount), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_RageDepletionAmount_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_RageDepletionAmount_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_RageActivationThreshold_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Rage" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Amount to reduce per tick\n" },
#endif
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Amount to reduce per tick" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_RageActivationThreshold = { "RageActivationThreshold", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, RageActivationThreshold), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_RageActivationThreshold_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_RageActivationThreshold_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_DeathMontage_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "HitReaction" },
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_DeathMontage = { "DeathMontage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, DeathMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_DeathMontage_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_DeathMontage_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_ParryMontage_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "CounterS" },
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_ParryMontage = { "ParryMontage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, ParryMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_ParryMontage_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_ParryMontage_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CounterMontage_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "CounterS" },
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CounterMontage = { "CounterMontage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, CounterMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CounterMontage_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CounterMontage_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_ProjectileCounterMontage_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "CounterS" },
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_ProjectileCounterMontage = { "ProjectileCounterMontage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, ProjectileCounterMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_ProjectileCounterMontage_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_ProjectileCounterMontage_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_TestRhythmMontage_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Test" },
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_TestRhythmMontage = { "TestRhythmMontage", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, TestRhythmMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_TestRhythmMontage_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_TestRhythmMontage_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_RageEmitter_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Rage" },
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_RageEmitter = { "RageEmitter", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, RageEmitter), Z_Construct_UClass_UParticleSystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_RageEmitter_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_RageEmitter_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_RageAnim_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Rage" },
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_RageAnim = { "RageAnim", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, RageAnim), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_RageAnim_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_RageAnim_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_RageOverlayMaterial_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Rage" },
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_RageOverlayMaterial = { "RageOverlayMaterial", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, RageOverlayMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_RageOverlayMaterial_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_RageOverlayMaterial_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_InitialRageOverlayMaterial_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Rage" },
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_InitialRageOverlayMaterial = { "InitialRageOverlayMaterial", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, InitialRageOverlayMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_InitialRageOverlayMaterial_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_InitialRageOverlayMaterial_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_ScoreComp_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Attack" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_ScoreComp = { "ScoreComp", nullptr, (EPropertyFlags)0x004000000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, ScoreComp), Z_Construct_UClass_UScoreComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_ScoreComp_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_ScoreComp_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_SoftTargetCurve_MetaData[] = {
		{ "Category", "Targeting" },
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_SoftTargetCurve = { "SoftTargetCurve", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, SoftTargetCurve), Z_Construct_UClass_UCurveFloat_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_SoftTargetCurve_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_SoftTargetCurve_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_ProjectileWeaponMontage_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Attack" },
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_ProjectileWeaponMontage = { "ProjectileWeaponMontage", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, ProjectileWeaponMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_ProjectileWeaponMontage_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_ProjectileWeaponMontage_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_DefaultCameraBoomLength_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_DefaultCameraBoomLength = { "DefaultCameraBoomLength", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, DefaultCameraBoomLength), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_DefaultCameraBoomLength_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_DefaultCameraBoomLength_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CameraBoomLength_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CameraBoomLength = { "CameraBoomLength", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, CameraBoomLength), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CameraBoomLength_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CameraBoomLength_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CooldownProjectileDuration_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Projectile" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Maximum consecutive \n" },
#endif
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum consecutive" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CooldownProjectileDuration = { "CooldownProjectileDuration", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, CooldownProjectileDuration), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CooldownProjectileDuration_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CooldownProjectileDuration_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_ProjectileCooldownProgress_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Projectile" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Beat delay (in seconds) before dodge resets\n" },
#endif
		{ "ModuleRelativePath", "NeonParadigm_GameCharacter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Beat delay (in seconds) before dodge resets" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_ProjectileCooldownProgress = { "ProjectileCooldownProgress", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameCharacter, ProjectileCooldownProgress), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_ProjectileCooldownProgress_MetaData), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_ProjectileCooldownProgress_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CameraBoom,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_FollowCamera,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_DefaultMappingContext,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_JumpAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_MoveAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_LookAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_LightAttackAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_HeavyAttackAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_DodgeAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_TargetAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_ParryAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_RageAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_ProjectileWeaponAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CharacterState,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_WeaponMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_AttackComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_DamageComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_BPM_OrbSpringArm,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_BPM_OrbMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_DodgeMontage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_DoubleJumpMontage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_MaxTargetingDistance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_TargetingOffset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CameraRotationSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_TargetingDistance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_MaxSoftTargetDistance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CurrentHealth,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_MaxHealth,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CurrentRage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_MaxRage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_RageDepletionRate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_RageDepletionAmount,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_RageActivationThreshold,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_DeathMontage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_ParryMontage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CounterMontage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_ProjectileCounterMontage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_TestRhythmMontage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_RageEmitter,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_RageAnim,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_RageOverlayMaterial,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_InitialRageOverlayMaterial,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_ScoreComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_SoftTargetCurve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_ProjectileWeaponMontage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_DefaultCameraBoomLength,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CameraBoomLength,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CooldownProjectileDuration,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_ProjectileCooldownProgress,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANeonParadigm_GameCharacter>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::ClassParams = {
		&ANeonParadigm_GameCharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::PropPointers),
		0,
		0x008000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ANeonParadigm_GameCharacter()
	{
		if (!Z_Registration_Info_UClass_ANeonParadigm_GameCharacter.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ANeonParadigm_GameCharacter.OuterSingleton, Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ANeonParadigm_GameCharacter.OuterSingleton;
	}
	template<> NEONPARADIGM_GAME_API UClass* StaticClass<ANeonParadigm_GameCharacter>()
	{
		return ANeonParadigm_GameCharacter::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANeonParadigm_GameCharacter);
	ANeonParadigm_GameCharacter::~ANeonParadigm_GameCharacter() {}
	struct Z_CompiledInDeferFile_FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_NeonParadigm_GameCharacter_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_NeonParadigm_GameCharacter_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ANeonParadigm_GameCharacter, ANeonParadigm_GameCharacter::StaticClass, TEXT("ANeonParadigm_GameCharacter"), &Z_Registration_Info_UClass_ANeonParadigm_GameCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ANeonParadigm_GameCharacter), 101553007U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_NeonParadigm_GameCharacter_h_817907356(TEXT("/Script/NeonParadigm_Game"),
		Z_CompiledInDeferFile_FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_NeonParadigm_GameCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_NeonParadigm_GameCharacter_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
