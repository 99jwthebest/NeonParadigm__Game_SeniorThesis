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
	ENGINE_API UClass* Z_Construct_UClass_UDamageType_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_ANeonParadigm_GameCharacter();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_ANeonParadigm_GameCharacter_NoRegister();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UAttackComponent_NoRegister();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UCharacterStateComponent_NoRegister();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UDamageComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_NeonParadigm_Game();
// End Cross Module References
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
	static FName NAME_ANeonParadigm_GameCharacter_ParryProjectile = FName(TEXT("ParryProjectile"));
	void ANeonParadigm_GameCharacter::ParryProjectile()
	{
		ProcessEvent(FindFunctionChecked(NAME_ANeonParadigm_GameCharacter_ParryProjectile),NULL);
	}
	void ANeonParadigm_GameCharacter::StaticRegisterNativesANeonParadigm_GameCharacter()
	{
		UClass* Class = ANeonParadigm_GameCharacter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Counter", &ANeonParadigm_GameCharacter::execCounter },
			{ "HandleTakeAnyDamage", &ANeonParadigm_GameCharacter::execHandleTakeAnyDamage },
			{ "IsIFramesEnabled", &ANeonParadigm_GameCharacter::execIsIFramesEnabled },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
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
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CurrentHealth_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentHealth;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxHealth_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxHealth;
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
		{ &Z_Construct_UFunction_ANeonParadigm_GameCharacter_Counter, "Counter" }, // 1905309954
		{ &Z_Construct_UFunction_ANeonParadigm_GameCharacter_HandleTakeAnyDamage, "HandleTakeAnyDamage" }, // 1697673734
		{ &Z_Construct_UFunction_ANeonParadigm_GameCharacter_IsIFramesEnabled, "IsIFramesEnabled" }, // 966977221
		{ &Z_Construct_UFunction_ANeonParadigm_GameCharacter_ParryProjectile, "ParryProjectile" }, // 650497423
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
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CharacterState,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_WeaponMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_AttackComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_DamageComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_DodgeMontage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_DoubleJumpMontage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_MaxTargetingDistance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_TargetingOffset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CameraRotationSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_TargetingDistance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CurrentHealth,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_MaxHealth,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_DeathMontage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_ParryMontage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_CounterMontage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics::NewProp_ProjectileCounterMontage,
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
	struct Z_CompiledInDeferFile_FID_NeonParadigm_Game_Source_NeonParadigm_Game_NeonParadigm_GameCharacter_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_NeonParadigm_Game_Source_NeonParadigm_Game_NeonParadigm_GameCharacter_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ANeonParadigm_GameCharacter, ANeonParadigm_GameCharacter::StaticClass, TEXT("ANeonParadigm_GameCharacter"), &Z_Registration_Info_UClass_ANeonParadigm_GameCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ANeonParadigm_GameCharacter), 1418393248U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_NeonParadigm_Game_Source_NeonParadigm_Game_NeonParadigm_GameCharacter_h_2329103679(TEXT("/Script/NeonParadigm_Game"),
		Z_CompiledInDeferFile_FID_NeonParadigm_Game_Source_NeonParadigm_Game_NeonParadigm_GameCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_NeonParadigm_Game_Source_NeonParadigm_Game_NeonParadigm_GameCharacter_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
