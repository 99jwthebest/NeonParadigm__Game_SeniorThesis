// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NeonParadigm_Game/Enemies/NP_BaseEnemy.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNP_BaseEnemy() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	ENGINE_API UClass* Z_Construct_UClass_AController_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UDamageType_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_ANP_BaseEnemy();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_ANP_BaseEnemy_NoRegister();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UNP_DamageType_NoRegister();
	NEONPARADIGM_GAME_API UEnum* Z_Construct_UEnum_NeonParadigm_Game_ECharacterStates();
	UMG_API UClass* Z_Construct_UClass_UWidgetComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_NeonParadigm_Game();
// End Cross Module References
	DEFINE_FUNCTION(ANP_BaseEnemy::execGetNotifyTriggerTime)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetNotifyTriggerTime();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANP_BaseEnemy::execFindNotifyTriggerTime)
	{
		P_GET_OBJECT(UAnimMontage,Z_Param_Montage);
		P_GET_PROPERTY(FNameProperty,Z_Param_NotifyName);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->FindNotifyTriggerTime(Z_Param_Montage,Z_Param_NotifyName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANP_BaseEnemy::execCheckToWaitForBeat)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->CheckToWaitForBeat();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANP_BaseEnemy::execTestRhythmDelayEvent)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->TestRhythmDelayEvent();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANP_BaseEnemy::execGetCurrentAnimPlayRate)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetCurrentAnimPlayRate();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANP_BaseEnemy::execSetCurrentAnimTimeDelay)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_CurAnimTimeDelay);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetCurrentAnimTimeDelay(Z_Param_CurAnimTimeDelay);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANP_BaseEnemy::execIsCurrentStateEqualToAny)
	{
		P_GET_TARRAY_REF(ECharacterStates,Z_Param_Out_StatesToCheck);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsCurrentStateEqualToAny(Z_Param_Out_StatesToCheck);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANP_BaseEnemy::execSetState)
	{
		P_GET_ENUM(ECharacterStates,Z_Param_NewState);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetState(ECharacterStates(Z_Param_NewState));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANP_BaseEnemy::execHandleTakeAnyDamage)
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
	static FName NAME_ANP_BaseEnemy_PerformThingsAfterDeath = FName(TEXT("PerformThingsAfterDeath"));
	void ANP_BaseEnemy::PerformThingsAfterDeath()
	{
		ProcessEvent(FindFunctionChecked(NAME_ANP_BaseEnemy_PerformThingsAfterDeath),NULL);
	}
	void ANP_BaseEnemy::StaticRegisterNativesANP_BaseEnemy()
	{
		UClass* Class = ANP_BaseEnemy::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CheckToWaitForBeat", &ANP_BaseEnemy::execCheckToWaitForBeat },
			{ "FindNotifyTriggerTime", &ANP_BaseEnemy::execFindNotifyTriggerTime },
			{ "GetCurrentAnimPlayRate", &ANP_BaseEnemy::execGetCurrentAnimPlayRate },
			{ "GetNotifyTriggerTime", &ANP_BaseEnemy::execGetNotifyTriggerTime },
			{ "HandleTakeAnyDamage", &ANP_BaseEnemy::execHandleTakeAnyDamage },
			{ "IsCurrentStateEqualToAny", &ANP_BaseEnemy::execIsCurrentStateEqualToAny },
			{ "SetCurrentAnimTimeDelay", &ANP_BaseEnemy::execSetCurrentAnimTimeDelay },
			{ "SetState", &ANP_BaseEnemy::execSetState },
			{ "TestRhythmDelayEvent", &ANP_BaseEnemy::execTestRhythmDelayEvent },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ANP_BaseEnemy_CheckToWaitForBeat_Statics
	{
		struct NP_BaseEnemy_eventCheckToWaitForBeat_Parms
		{
			float ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ANP_BaseEnemy_CheckToWaitForBeat_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NP_BaseEnemy_eventCheckToWaitForBeat_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANP_BaseEnemy_CheckToWaitForBeat_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANP_BaseEnemy_CheckToWaitForBeat_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANP_BaseEnemy_CheckToWaitForBeat_Statics::Function_MetaDataParams[] = {
		{ "Category", "Music" },
		{ "ModuleRelativePath", "Enemies/NP_BaseEnemy.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANP_BaseEnemy_CheckToWaitForBeat_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANP_BaseEnemy, nullptr, "CheckToWaitForBeat", nullptr, nullptr, Z_Construct_UFunction_ANP_BaseEnemy_CheckToWaitForBeat_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_BaseEnemy_CheckToWaitForBeat_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANP_BaseEnemy_CheckToWaitForBeat_Statics::NP_BaseEnemy_eventCheckToWaitForBeat_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_BaseEnemy_CheckToWaitForBeat_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANP_BaseEnemy_CheckToWaitForBeat_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_BaseEnemy_CheckToWaitForBeat_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ANP_BaseEnemy_CheckToWaitForBeat_Statics::NP_BaseEnemy_eventCheckToWaitForBeat_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANP_BaseEnemy_CheckToWaitForBeat()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANP_BaseEnemy_CheckToWaitForBeat_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANP_BaseEnemy_FindNotifyTriggerTime_Statics
	{
		struct NP_BaseEnemy_eventFindNotifyTriggerTime_Parms
		{
			UAnimMontage* Montage;
			FName NotifyName;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Montage;
		static const UECodeGen_Private::FNamePropertyParams NewProp_NotifyName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ANP_BaseEnemy_FindNotifyTriggerTime_Statics::NewProp_Montage = { "Montage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NP_BaseEnemy_eventFindNotifyTriggerTime_Parms, Montage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ANP_BaseEnemy_FindNotifyTriggerTime_Statics::NewProp_NotifyName = { "NotifyName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NP_BaseEnemy_eventFindNotifyTriggerTime_Parms, NotifyName), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANP_BaseEnemy_FindNotifyTriggerTime_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANP_BaseEnemy_FindNotifyTriggerTime_Statics::NewProp_Montage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANP_BaseEnemy_FindNotifyTriggerTime_Statics::NewProp_NotifyName,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANP_BaseEnemy_FindNotifyTriggerTime_Statics::Function_MetaDataParams[] = {
		{ "Category", "Music" },
		{ "ModuleRelativePath", "Enemies/NP_BaseEnemy.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANP_BaseEnemy_FindNotifyTriggerTime_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANP_BaseEnemy, nullptr, "FindNotifyTriggerTime", nullptr, nullptr, Z_Construct_UFunction_ANP_BaseEnemy_FindNotifyTriggerTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_BaseEnemy_FindNotifyTriggerTime_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANP_BaseEnemy_FindNotifyTriggerTime_Statics::NP_BaseEnemy_eventFindNotifyTriggerTime_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_BaseEnemy_FindNotifyTriggerTime_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANP_BaseEnemy_FindNotifyTriggerTime_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_BaseEnemy_FindNotifyTriggerTime_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ANP_BaseEnemy_FindNotifyTriggerTime_Statics::NP_BaseEnemy_eventFindNotifyTriggerTime_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANP_BaseEnemy_FindNotifyTriggerTime()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANP_BaseEnemy_FindNotifyTriggerTime_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANP_BaseEnemy_GetCurrentAnimPlayRate_Statics
	{
		struct NP_BaseEnemy_eventGetCurrentAnimPlayRate_Parms
		{
			float ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ANP_BaseEnemy_GetCurrentAnimPlayRate_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NP_BaseEnemy_eventGetCurrentAnimPlayRate_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANP_BaseEnemy_GetCurrentAnimPlayRate_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANP_BaseEnemy_GetCurrentAnimPlayRate_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANP_BaseEnemy_GetCurrentAnimPlayRate_Statics::Function_MetaDataParams[] = {
		{ "Category", "Music" },
		{ "ModuleRelativePath", "Enemies/NP_BaseEnemy.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANP_BaseEnemy_GetCurrentAnimPlayRate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANP_BaseEnemy, nullptr, "GetCurrentAnimPlayRate", nullptr, nullptr, Z_Construct_UFunction_ANP_BaseEnemy_GetCurrentAnimPlayRate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_BaseEnemy_GetCurrentAnimPlayRate_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANP_BaseEnemy_GetCurrentAnimPlayRate_Statics::NP_BaseEnemy_eventGetCurrentAnimPlayRate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_BaseEnemy_GetCurrentAnimPlayRate_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANP_BaseEnemy_GetCurrentAnimPlayRate_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_BaseEnemy_GetCurrentAnimPlayRate_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ANP_BaseEnemy_GetCurrentAnimPlayRate_Statics::NP_BaseEnemy_eventGetCurrentAnimPlayRate_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANP_BaseEnemy_GetCurrentAnimPlayRate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANP_BaseEnemy_GetCurrentAnimPlayRate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANP_BaseEnemy_GetNotifyTriggerTime_Statics
	{
		struct NP_BaseEnemy_eventGetNotifyTriggerTime_Parms
		{
			float ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ANP_BaseEnemy_GetNotifyTriggerTime_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NP_BaseEnemy_eventGetNotifyTriggerTime_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANP_BaseEnemy_GetNotifyTriggerTime_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANP_BaseEnemy_GetNotifyTriggerTime_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANP_BaseEnemy_GetNotifyTriggerTime_Statics::Function_MetaDataParams[] = {
		{ "Category", "Music" },
		{ "ModuleRelativePath", "Enemies/NP_BaseEnemy.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANP_BaseEnemy_GetNotifyTriggerTime_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANP_BaseEnemy, nullptr, "GetNotifyTriggerTime", nullptr, nullptr, Z_Construct_UFunction_ANP_BaseEnemy_GetNotifyTriggerTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_BaseEnemy_GetNotifyTriggerTime_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANP_BaseEnemy_GetNotifyTriggerTime_Statics::NP_BaseEnemy_eventGetNotifyTriggerTime_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_BaseEnemy_GetNotifyTriggerTime_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANP_BaseEnemy_GetNotifyTriggerTime_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_BaseEnemy_GetNotifyTriggerTime_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ANP_BaseEnemy_GetNotifyTriggerTime_Statics::NP_BaseEnemy_eventGetNotifyTriggerTime_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANP_BaseEnemy_GetNotifyTriggerTime()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANP_BaseEnemy_GetNotifyTriggerTime_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANP_BaseEnemy_HandleTakeAnyDamage_Statics
	{
		struct NP_BaseEnemy_eventHandleTakeAnyDamage_Parms
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
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ANP_BaseEnemy_HandleTakeAnyDamage_Statics::NewProp_DamagedActor = { "DamagedActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NP_BaseEnemy_eventHandleTakeAnyDamage_Parms, DamagedActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ANP_BaseEnemy_HandleTakeAnyDamage_Statics::NewProp_Damage = { "Damage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NP_BaseEnemy_eventHandleTakeAnyDamage_Parms, Damage), METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANP_BaseEnemy_HandleTakeAnyDamage_Statics::NewProp_DamageType_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ANP_BaseEnemy_HandleTakeAnyDamage_Statics::NewProp_DamageType = { "DamageType", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NP_BaseEnemy_eventHandleTakeAnyDamage_Parms, DamageType), Z_Construct_UClass_UDamageType_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_BaseEnemy_HandleTakeAnyDamage_Statics::NewProp_DamageType_MetaData), Z_Construct_UFunction_ANP_BaseEnemy_HandleTakeAnyDamage_Statics::NewProp_DamageType_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ANP_BaseEnemy_HandleTakeAnyDamage_Statics::NewProp_InstigatedBy = { "InstigatedBy", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NP_BaseEnemy_eventHandleTakeAnyDamage_Parms, InstigatedBy), Z_Construct_UClass_AController_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ANP_BaseEnemy_HandleTakeAnyDamage_Statics::NewProp_DamageCauser = { "DamageCauser", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NP_BaseEnemy_eventHandleTakeAnyDamage_Parms, DamageCauser), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANP_BaseEnemy_HandleTakeAnyDamage_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANP_BaseEnemy_HandleTakeAnyDamage_Statics::NewProp_DamagedActor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANP_BaseEnemy_HandleTakeAnyDamage_Statics::NewProp_Damage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANP_BaseEnemy_HandleTakeAnyDamage_Statics::NewProp_DamageType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANP_BaseEnemy_HandleTakeAnyDamage_Statics::NewProp_InstigatedBy,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANP_BaseEnemy_HandleTakeAnyDamage_Statics::NewProp_DamageCauser,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANP_BaseEnemy_HandleTakeAnyDamage_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Enemies/NP_BaseEnemy.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANP_BaseEnemy_HandleTakeAnyDamage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANP_BaseEnemy, nullptr, "HandleTakeAnyDamage", nullptr, nullptr, Z_Construct_UFunction_ANP_BaseEnemy_HandleTakeAnyDamage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_BaseEnemy_HandleTakeAnyDamage_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANP_BaseEnemy_HandleTakeAnyDamage_Statics::NP_BaseEnemy_eventHandleTakeAnyDamage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_BaseEnemy_HandleTakeAnyDamage_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANP_BaseEnemy_HandleTakeAnyDamage_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_BaseEnemy_HandleTakeAnyDamage_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ANP_BaseEnemy_HandleTakeAnyDamage_Statics::NP_BaseEnemy_eventHandleTakeAnyDamage_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANP_BaseEnemy_HandleTakeAnyDamage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANP_BaseEnemy_HandleTakeAnyDamage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANP_BaseEnemy_IsCurrentStateEqualToAny_Statics
	{
		struct NP_BaseEnemy_eventIsCurrentStateEqualToAny_Parms
		{
			TArray<ECharacterStates> StatesToCheck;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_StatesToCheck_Inner_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_StatesToCheck_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StatesToCheck_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_StatesToCheck;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ANP_BaseEnemy_IsCurrentStateEqualToAny_Statics::NewProp_StatesToCheck_Inner_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_ANP_BaseEnemy_IsCurrentStateEqualToAny_Statics::NewProp_StatesToCheck_Inner = { "StatesToCheck", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_NeonParadigm_Game_ECharacterStates, METADATA_PARAMS(0, nullptr) }; // 1500412229
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANP_BaseEnemy_IsCurrentStateEqualToAny_Statics::NewProp_StatesToCheck_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ANP_BaseEnemy_IsCurrentStateEqualToAny_Statics::NewProp_StatesToCheck = { "StatesToCheck", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NP_BaseEnemy_eventIsCurrentStateEqualToAny_Parms, StatesToCheck), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_BaseEnemy_IsCurrentStateEqualToAny_Statics::NewProp_StatesToCheck_MetaData), Z_Construct_UFunction_ANP_BaseEnemy_IsCurrentStateEqualToAny_Statics::NewProp_StatesToCheck_MetaData) }; // 1500412229
	void Z_Construct_UFunction_ANP_BaseEnemy_IsCurrentStateEqualToAny_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((NP_BaseEnemy_eventIsCurrentStateEqualToAny_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ANP_BaseEnemy_IsCurrentStateEqualToAny_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(NP_BaseEnemy_eventIsCurrentStateEqualToAny_Parms), &Z_Construct_UFunction_ANP_BaseEnemy_IsCurrentStateEqualToAny_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANP_BaseEnemy_IsCurrentStateEqualToAny_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANP_BaseEnemy_IsCurrentStateEqualToAny_Statics::NewProp_StatesToCheck_Inner_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANP_BaseEnemy_IsCurrentStateEqualToAny_Statics::NewProp_StatesToCheck_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANP_BaseEnemy_IsCurrentStateEqualToAny_Statics::NewProp_StatesToCheck,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANP_BaseEnemy_IsCurrentStateEqualToAny_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANP_BaseEnemy_IsCurrentStateEqualToAny_Statics::Function_MetaDataParams[] = {
		{ "Category", "State" },
		{ "ModuleRelativePath", "Enemies/NP_BaseEnemy.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANP_BaseEnemy_IsCurrentStateEqualToAny_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANP_BaseEnemy, nullptr, "IsCurrentStateEqualToAny", nullptr, nullptr, Z_Construct_UFunction_ANP_BaseEnemy_IsCurrentStateEqualToAny_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_BaseEnemy_IsCurrentStateEqualToAny_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANP_BaseEnemy_IsCurrentStateEqualToAny_Statics::NP_BaseEnemy_eventIsCurrentStateEqualToAny_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_BaseEnemy_IsCurrentStateEqualToAny_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANP_BaseEnemy_IsCurrentStateEqualToAny_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_BaseEnemy_IsCurrentStateEqualToAny_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ANP_BaseEnemy_IsCurrentStateEqualToAny_Statics::NP_BaseEnemy_eventIsCurrentStateEqualToAny_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANP_BaseEnemy_IsCurrentStateEqualToAny()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANP_BaseEnemy_IsCurrentStateEqualToAny_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANP_BaseEnemy_PerformThingsAfterDeath_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANP_BaseEnemy_PerformThingsAfterDeath_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Enemies/NP_BaseEnemy.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANP_BaseEnemy_PerformThingsAfterDeath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANP_BaseEnemy, nullptr, "PerformThingsAfterDeath", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_BaseEnemy_PerformThingsAfterDeath_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANP_BaseEnemy_PerformThingsAfterDeath_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ANP_BaseEnemy_PerformThingsAfterDeath()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANP_BaseEnemy_PerformThingsAfterDeath_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANP_BaseEnemy_SetCurrentAnimTimeDelay_Statics
	{
		struct NP_BaseEnemy_eventSetCurrentAnimTimeDelay_Parms
		{
			float CurAnimTimeDelay;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_CurAnimTimeDelay;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ANP_BaseEnemy_SetCurrentAnimTimeDelay_Statics::NewProp_CurAnimTimeDelay = { "CurAnimTimeDelay", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NP_BaseEnemy_eventSetCurrentAnimTimeDelay_Parms, CurAnimTimeDelay), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANP_BaseEnemy_SetCurrentAnimTimeDelay_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANP_BaseEnemy_SetCurrentAnimTimeDelay_Statics::NewProp_CurAnimTimeDelay,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANP_BaseEnemy_SetCurrentAnimTimeDelay_Statics::Function_MetaDataParams[] = {
		{ "Category", "Music" },
		{ "ModuleRelativePath", "Enemies/NP_BaseEnemy.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANP_BaseEnemy_SetCurrentAnimTimeDelay_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANP_BaseEnemy, nullptr, "SetCurrentAnimTimeDelay", nullptr, nullptr, Z_Construct_UFunction_ANP_BaseEnemy_SetCurrentAnimTimeDelay_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_BaseEnemy_SetCurrentAnimTimeDelay_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANP_BaseEnemy_SetCurrentAnimTimeDelay_Statics::NP_BaseEnemy_eventSetCurrentAnimTimeDelay_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_BaseEnemy_SetCurrentAnimTimeDelay_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANP_BaseEnemy_SetCurrentAnimTimeDelay_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_BaseEnemy_SetCurrentAnimTimeDelay_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ANP_BaseEnemy_SetCurrentAnimTimeDelay_Statics::NP_BaseEnemy_eventSetCurrentAnimTimeDelay_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANP_BaseEnemy_SetCurrentAnimTimeDelay()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANP_BaseEnemy_SetCurrentAnimTimeDelay_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANP_BaseEnemy_SetState_Statics
	{
		struct NP_BaseEnemy_eventSetState_Parms
		{
			ECharacterStates NewState;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_NewState_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_NewState;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ANP_BaseEnemy_SetState_Statics::NewProp_NewState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_ANP_BaseEnemy_SetState_Statics::NewProp_NewState = { "NewState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NP_BaseEnemy_eventSetState_Parms, NewState), Z_Construct_UEnum_NeonParadigm_Game_ECharacterStates, METADATA_PARAMS(0, nullptr) }; // 1500412229
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANP_BaseEnemy_SetState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANP_BaseEnemy_SetState_Statics::NewProp_NewState_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANP_BaseEnemy_SetState_Statics::NewProp_NewState,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANP_BaseEnemy_SetState_Statics::Function_MetaDataParams[] = {
		{ "Category", "State" },
		{ "ModuleRelativePath", "Enemies/NP_BaseEnemy.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANP_BaseEnemy_SetState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANP_BaseEnemy, nullptr, "SetState", nullptr, nullptr, Z_Construct_UFunction_ANP_BaseEnemy_SetState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_BaseEnemy_SetState_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANP_BaseEnemy_SetState_Statics::NP_BaseEnemy_eventSetState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_BaseEnemy_SetState_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANP_BaseEnemy_SetState_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_BaseEnemy_SetState_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ANP_BaseEnemy_SetState_Statics::NP_BaseEnemy_eventSetState_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANP_BaseEnemy_SetState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANP_BaseEnemy_SetState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANP_BaseEnemy_TestRhythmDelayEvent_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANP_BaseEnemy_TestRhythmDelayEvent_Statics::Function_MetaDataParams[] = {
		{ "Category", "Music" },
		{ "ModuleRelativePath", "Enemies/NP_BaseEnemy.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANP_BaseEnemy_TestRhythmDelayEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANP_BaseEnemy, nullptr, "TestRhythmDelayEvent", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_BaseEnemy_TestRhythmDelayEvent_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANP_BaseEnemy_TestRhythmDelayEvent_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ANP_BaseEnemy_TestRhythmDelayEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANP_BaseEnemy_TestRhythmDelayEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ANP_BaseEnemy);
	UClass* Z_Construct_UClass_ANP_BaseEnemy_NoRegister()
	{
		return ANP_BaseEnemy::StaticClass();
	}
	struct Z_Construct_UClass_ANP_BaseEnemy_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CurrentHealth_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentHealth;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxHealth_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxHealth;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HR_Right_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_HR_Right;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HR_Left_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_HR_Left;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HR_Middle_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_HR_Middle;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HR_Knockdown_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_HR_Knockdown;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HR_Knockback_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_HR_Knockback;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HR_Launch_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_HR_Launch;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ParryStaggerMontage_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ParryStaggerMontage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bCanBeParried_MetaData[];
#endif
		static void NewProp_bCanBeParried_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bCanBeParried;
		static const UECodeGen_Private::FBytePropertyParams NewProp_CurrentState_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CurrentState_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_CurrentState;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DeathMontage_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DeathMontage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WeaponMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WeaponMesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HealthBarWidget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_HealthBarWidget;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LockOnWidget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LockOnWidget;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TestRhythmMontage_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TestRhythmMontage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MyDamageType_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MyDamageType;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ANP_BaseEnemy_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_NeonParadigm_Game,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANP_BaseEnemy_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_ANP_BaseEnemy_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ANP_BaseEnemy_CheckToWaitForBeat, "CheckToWaitForBeat" }, // 1671672958
		{ &Z_Construct_UFunction_ANP_BaseEnemy_FindNotifyTriggerTime, "FindNotifyTriggerTime" }, // 1452380284
		{ &Z_Construct_UFunction_ANP_BaseEnemy_GetCurrentAnimPlayRate, "GetCurrentAnimPlayRate" }, // 1714036484
		{ &Z_Construct_UFunction_ANP_BaseEnemy_GetNotifyTriggerTime, "GetNotifyTriggerTime" }, // 3270409843
		{ &Z_Construct_UFunction_ANP_BaseEnemy_HandleTakeAnyDamage, "HandleTakeAnyDamage" }, // 3611324083
		{ &Z_Construct_UFunction_ANP_BaseEnemy_IsCurrentStateEqualToAny, "IsCurrentStateEqualToAny" }, // 3945352412
		{ &Z_Construct_UFunction_ANP_BaseEnemy_PerformThingsAfterDeath, "PerformThingsAfterDeath" }, // 3771025194
		{ &Z_Construct_UFunction_ANP_BaseEnemy_SetCurrentAnimTimeDelay, "SetCurrentAnimTimeDelay" }, // 938796568
		{ &Z_Construct_UFunction_ANP_BaseEnemy_SetState, "SetState" }, // 4264504257
		{ &Z_Construct_UFunction_ANP_BaseEnemy_TestRhythmDelayEvent, "TestRhythmDelayEvent" }, // 1271510468
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANP_BaseEnemy_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANP_BaseEnemy_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Enemies/NP_BaseEnemy.h" },
		{ "ModuleRelativePath", "Enemies/NP_BaseEnemy.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_CurrentHealth_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Stats" },
		{ "ModuleRelativePath", "Enemies/NP_BaseEnemy.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_CurrentHealth = { "CurrentHealth", nullptr, (EPropertyFlags)0x0040000000020005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANP_BaseEnemy, CurrentHealth), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_CurrentHealth_MetaData), Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_CurrentHealth_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_MaxHealth_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Stats" },
		{ "ModuleRelativePath", "Enemies/NP_BaseEnemy.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_MaxHealth = { "MaxHealth", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANP_BaseEnemy, MaxHealth), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_MaxHealth_MetaData), Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_MaxHealth_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_HR_Right_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "HitReaction" },
		{ "ModuleRelativePath", "Enemies/NP_BaseEnemy.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_HR_Right = { "HR_Right", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANP_BaseEnemy, HR_Right), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_HR_Right_MetaData), Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_HR_Right_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_HR_Left_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "HitReaction" },
		{ "ModuleRelativePath", "Enemies/NP_BaseEnemy.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_HR_Left = { "HR_Left", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANP_BaseEnemy, HR_Left), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_HR_Left_MetaData), Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_HR_Left_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_HR_Middle_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "HitReaction" },
		{ "ModuleRelativePath", "Enemies/NP_BaseEnemy.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_HR_Middle = { "HR_Middle", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANP_BaseEnemy, HR_Middle), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_HR_Middle_MetaData), Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_HR_Middle_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_HR_Knockdown_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "HitReaction" },
		{ "ModuleRelativePath", "Enemies/NP_BaseEnemy.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_HR_Knockdown = { "HR_Knockdown", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANP_BaseEnemy, HR_Knockdown), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_HR_Knockdown_MetaData), Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_HR_Knockdown_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_HR_Knockback_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "HitReaction" },
		{ "ModuleRelativePath", "Enemies/NP_BaseEnemy.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_HR_Knockback = { "HR_Knockback", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANP_BaseEnemy, HR_Knockback), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_HR_Knockback_MetaData), Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_HR_Knockback_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_HR_Launch_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "HitReaction" },
		{ "ModuleRelativePath", "Enemies/NP_BaseEnemy.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_HR_Launch = { "HR_Launch", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANP_BaseEnemy, HR_Launch), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_HR_Launch_MetaData), Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_HR_Launch_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_ParryStaggerMontage_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "HitReaction" },
		{ "ModuleRelativePath", "Enemies/NP_BaseEnemy.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_ParryStaggerMontage = { "ParryStaggerMontage", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANP_BaseEnemy, ParryStaggerMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_ParryStaggerMontage_MetaData), Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_ParryStaggerMontage_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_bCanBeParried_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "HitReaction" },
		{ "ModuleRelativePath", "Enemies/NP_BaseEnemy.h" },
	};
#endif
	void Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_bCanBeParried_SetBit(void* Obj)
	{
		((ANP_BaseEnemy*)Obj)->bCanBeParried = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_bCanBeParried = { "bCanBeParried", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ANP_BaseEnemy), &Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_bCanBeParried_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_bCanBeParried_MetaData), Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_bCanBeParried_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_CurrentState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_CurrentState_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "State" },
		{ "ModuleRelativePath", "Enemies/NP_BaseEnemy.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_CurrentState = { "CurrentState", nullptr, (EPropertyFlags)0x0040000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANP_BaseEnemy, CurrentState), Z_Construct_UEnum_NeonParadigm_Game_ECharacterStates, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_CurrentState_MetaData), Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_CurrentState_MetaData) }; // 1500412229
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_DeathMontage_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Death" },
		{ "ModuleRelativePath", "Enemies/NP_BaseEnemy.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_DeathMontage = { "DeathMontage", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANP_BaseEnemy, DeathMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_DeathMontage_MetaData), Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_DeathMontage_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_WeaponMesh_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Enemies/NP_BaseEnemy.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_WeaponMesh = { "WeaponMesh", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANP_BaseEnemy, WeaponMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_WeaponMesh_MetaData), Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_WeaponMesh_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_HealthBarWidget_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// The widget component\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Enemies/NP_BaseEnemy.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The widget component" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_HealthBarWidget = { "HealthBarWidget", nullptr, (EPropertyFlags)0x004000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANP_BaseEnemy, HealthBarWidget), Z_Construct_UClass_UWidgetComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_HealthBarWidget_MetaData), Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_HealthBarWidget_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_LockOnWidget_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "UI" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Enemies/NP_BaseEnemy.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_LockOnWidget = { "LockOnWidget", nullptr, (EPropertyFlags)0x004000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANP_BaseEnemy, LockOnWidget), Z_Construct_UClass_UWidgetComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_LockOnWidget_MetaData), Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_LockOnWidget_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_TestRhythmMontage_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Test" },
		{ "ModuleRelativePath", "Enemies/NP_BaseEnemy.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_TestRhythmMontage = { "TestRhythmMontage", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANP_BaseEnemy, TestRhythmMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_TestRhythmMontage_MetaData), Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_TestRhythmMontage_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_MyDamageType_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Don't play to save Transient property, just temporary, use when generating in runtime. Hold a reference without getting garbage collected.\n" },
#endif
		{ "ModuleRelativePath", "Enemies/NP_BaseEnemy.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Don't play to save Transient property, just temporary, use when generating in runtime. Hold a reference without getting garbage collected." },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_MyDamageType = { "MyDamageType", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANP_BaseEnemy, MyDamageType), Z_Construct_UClass_UNP_DamageType_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_MyDamageType_MetaData), Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_MyDamageType_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ANP_BaseEnemy_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_CurrentHealth,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_MaxHealth,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_HR_Right,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_HR_Left,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_HR_Middle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_HR_Knockdown,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_HR_Knockback,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_HR_Launch,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_ParryStaggerMontage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_bCanBeParried,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_CurrentState_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_CurrentState,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_DeathMontage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_WeaponMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_HealthBarWidget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_LockOnWidget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_TestRhythmMontage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANP_BaseEnemy_Statics::NewProp_MyDamageType,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ANP_BaseEnemy_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANP_BaseEnemy>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ANP_BaseEnemy_Statics::ClassParams = {
		&ANP_BaseEnemy::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ANP_BaseEnemy_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ANP_BaseEnemy_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANP_BaseEnemy_Statics::Class_MetaDataParams), Z_Construct_UClass_ANP_BaseEnemy_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANP_BaseEnemy_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ANP_BaseEnemy()
	{
		if (!Z_Registration_Info_UClass_ANP_BaseEnemy.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ANP_BaseEnemy.OuterSingleton, Z_Construct_UClass_ANP_BaseEnemy_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ANP_BaseEnemy.OuterSingleton;
	}
	template<> NEONPARADIGM_GAME_API UClass* StaticClass<ANP_BaseEnemy>()
	{
		return ANP_BaseEnemy::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANP_BaseEnemy);
	ANP_BaseEnemy::~ANP_BaseEnemy() {}
	struct Z_CompiledInDeferFile_FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enemies_NP_BaseEnemy_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enemies_NP_BaseEnemy_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ANP_BaseEnemy, ANP_BaseEnemy::StaticClass, TEXT("ANP_BaseEnemy"), &Z_Registration_Info_UClass_ANP_BaseEnemy, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ANP_BaseEnemy), 2461128983U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enemies_NP_BaseEnemy_h_2686192764(TEXT("/Script/NeonParadigm_Game"),
		Z_CompiledInDeferFile_FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enemies_NP_BaseEnemy_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enemies_NP_BaseEnemy_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
