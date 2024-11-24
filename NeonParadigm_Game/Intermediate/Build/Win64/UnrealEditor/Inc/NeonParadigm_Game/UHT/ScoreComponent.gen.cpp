// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NeonParadigm_Game/Components/ScoreComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeScoreComponent() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UScoreComponent();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UScoreComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_NeonParadigm_Game();
// End Cross Module References
	DEFINE_FUNCTION(UScoreComponent::execGetClearTime)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetClearTime();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UScoreComponent::execCalculateClearTimingGrade)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->CalculateClearTimingGrade();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UScoreComponent::execCalculateClearTimeBonus)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->CalculateClearTimeBonus();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UScoreComponent::execCalculatePerfectTimingGrade)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_PerfectHitPercentageIn);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->CalculatePerfectTimingGrade(Z_Param_PerfectHitPercentageIn);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UScoreComponent::execGetPerfectTimingPercentage)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetPerfectTimingPercentage();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UScoreComponent::execCalculatePerfectTimingBonus)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->CalculatePerfectTimingBonus();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UScoreComponent::execEndEncounter)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->EndEncounter();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UScoreComponent::execStartEncounter)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StartEncounter();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UScoreComponent::execDepleteProgress)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DepleteProgress();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UScoreComponent::execGetRankProgress)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetRankProgress();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UScoreComponent::execGetCurrentRankIndex)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetCurrentRankIndex();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UScoreComponent::execCalculateGrade)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->CalculateGrade();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UScoreComponent::execGetCurrentScore)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetCurrentScore();
		P_NATIVE_END;
	}
	void UScoreComponent::StaticRegisterNativesUScoreComponent()
	{
		UClass* Class = UScoreComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CalculateClearTimeBonus", &UScoreComponent::execCalculateClearTimeBonus },
			{ "CalculateClearTimingGrade", &UScoreComponent::execCalculateClearTimingGrade },
			{ "CalculateGrade", &UScoreComponent::execCalculateGrade },
			{ "CalculatePerfectTimingBonus", &UScoreComponent::execCalculatePerfectTimingBonus },
			{ "CalculatePerfectTimingGrade", &UScoreComponent::execCalculatePerfectTimingGrade },
			{ "DepleteProgress", &UScoreComponent::execDepleteProgress },
			{ "EndEncounter", &UScoreComponent::execEndEncounter },
			{ "GetClearTime", &UScoreComponent::execGetClearTime },
			{ "GetCurrentRankIndex", &UScoreComponent::execGetCurrentRankIndex },
			{ "GetCurrentScore", &UScoreComponent::execGetCurrentScore },
			{ "GetPerfectTimingPercentage", &UScoreComponent::execGetPerfectTimingPercentage },
			{ "GetRankProgress", &UScoreComponent::execGetRankProgress },
			{ "StartEncounter", &UScoreComponent::execStartEncounter },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UScoreComponent_CalculateClearTimeBonus_Statics
	{
		struct ScoreComponent_eventCalculateClearTimeBonus_Parms
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
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UScoreComponent_CalculateClearTimeBonus_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ScoreComponent_eventCalculateClearTimeBonus_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UScoreComponent_CalculateClearTimeBonus_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UScoreComponent_CalculateClearTimeBonus_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UScoreComponent_CalculateClearTimeBonus_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Components/ScoreComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UScoreComponent_CalculateClearTimeBonus_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UScoreComponent, nullptr, "CalculateClearTimeBonus", nullptr, nullptr, Z_Construct_UFunction_UScoreComponent_CalculateClearTimeBonus_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UScoreComponent_CalculateClearTimeBonus_Statics::PropPointers), sizeof(Z_Construct_UFunction_UScoreComponent_CalculateClearTimeBonus_Statics::ScoreComponent_eventCalculateClearTimeBonus_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UScoreComponent_CalculateClearTimeBonus_Statics::Function_MetaDataParams), Z_Construct_UFunction_UScoreComponent_CalculateClearTimeBonus_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UScoreComponent_CalculateClearTimeBonus_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UScoreComponent_CalculateClearTimeBonus_Statics::ScoreComponent_eventCalculateClearTimeBonus_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UScoreComponent_CalculateClearTimeBonus()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UScoreComponent_CalculateClearTimeBonus_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UScoreComponent_CalculateClearTimingGrade_Statics
	{
		struct ScoreComponent_eventCalculateClearTimingGrade_Parms
		{
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UScoreComponent_CalculateClearTimingGrade_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ScoreComponent_eventCalculateClearTimingGrade_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UScoreComponent_CalculateClearTimingGrade_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UScoreComponent_CalculateClearTimingGrade_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UScoreComponent_CalculateClearTimingGrade_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Components/ScoreComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UScoreComponent_CalculateClearTimingGrade_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UScoreComponent, nullptr, "CalculateClearTimingGrade", nullptr, nullptr, Z_Construct_UFunction_UScoreComponent_CalculateClearTimingGrade_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UScoreComponent_CalculateClearTimingGrade_Statics::PropPointers), sizeof(Z_Construct_UFunction_UScoreComponent_CalculateClearTimingGrade_Statics::ScoreComponent_eventCalculateClearTimingGrade_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UScoreComponent_CalculateClearTimingGrade_Statics::Function_MetaDataParams), Z_Construct_UFunction_UScoreComponent_CalculateClearTimingGrade_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UScoreComponent_CalculateClearTimingGrade_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UScoreComponent_CalculateClearTimingGrade_Statics::ScoreComponent_eventCalculateClearTimingGrade_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UScoreComponent_CalculateClearTimingGrade()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UScoreComponent_CalculateClearTimingGrade_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UScoreComponent_CalculateGrade_Statics
	{
		struct ScoreComponent_eventCalculateGrade_Parms
		{
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UScoreComponent_CalculateGrade_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ScoreComponent_eventCalculateGrade_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UScoreComponent_CalculateGrade_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UScoreComponent_CalculateGrade_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UScoreComponent_CalculateGrade_Statics::Function_MetaDataParams[] = {
		{ "Category", "Score" },
		{ "ModuleRelativePath", "Components/ScoreComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UScoreComponent_CalculateGrade_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UScoreComponent, nullptr, "CalculateGrade", nullptr, nullptr, Z_Construct_UFunction_UScoreComponent_CalculateGrade_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UScoreComponent_CalculateGrade_Statics::PropPointers), sizeof(Z_Construct_UFunction_UScoreComponent_CalculateGrade_Statics::ScoreComponent_eventCalculateGrade_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UScoreComponent_CalculateGrade_Statics::Function_MetaDataParams), Z_Construct_UFunction_UScoreComponent_CalculateGrade_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UScoreComponent_CalculateGrade_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UScoreComponent_CalculateGrade_Statics::ScoreComponent_eventCalculateGrade_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UScoreComponent_CalculateGrade()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UScoreComponent_CalculateGrade_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UScoreComponent_CalculatePerfectTimingBonus_Statics
	{
		struct ScoreComponent_eventCalculatePerfectTimingBonus_Parms
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
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UScoreComponent_CalculatePerfectTimingBonus_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ScoreComponent_eventCalculatePerfectTimingBonus_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UScoreComponent_CalculatePerfectTimingBonus_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UScoreComponent_CalculatePerfectTimingBonus_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UScoreComponent_CalculatePerfectTimingBonus_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Components/ScoreComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UScoreComponent_CalculatePerfectTimingBonus_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UScoreComponent, nullptr, "CalculatePerfectTimingBonus", nullptr, nullptr, Z_Construct_UFunction_UScoreComponent_CalculatePerfectTimingBonus_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UScoreComponent_CalculatePerfectTimingBonus_Statics::PropPointers), sizeof(Z_Construct_UFunction_UScoreComponent_CalculatePerfectTimingBonus_Statics::ScoreComponent_eventCalculatePerfectTimingBonus_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UScoreComponent_CalculatePerfectTimingBonus_Statics::Function_MetaDataParams), Z_Construct_UFunction_UScoreComponent_CalculatePerfectTimingBonus_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UScoreComponent_CalculatePerfectTimingBonus_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UScoreComponent_CalculatePerfectTimingBonus_Statics::ScoreComponent_eventCalculatePerfectTimingBonus_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UScoreComponent_CalculatePerfectTimingBonus()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UScoreComponent_CalculatePerfectTimingBonus_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UScoreComponent_CalculatePerfectTimingGrade_Statics
	{
		struct ScoreComponent_eventCalculatePerfectTimingGrade_Parms
		{
			float PerfectHitPercentageIn;
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_PerfectHitPercentageIn;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UScoreComponent_CalculatePerfectTimingGrade_Statics::NewProp_PerfectHitPercentageIn = { "PerfectHitPercentageIn", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ScoreComponent_eventCalculatePerfectTimingGrade_Parms, PerfectHitPercentageIn), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UScoreComponent_CalculatePerfectTimingGrade_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ScoreComponent_eventCalculatePerfectTimingGrade_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UScoreComponent_CalculatePerfectTimingGrade_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UScoreComponent_CalculatePerfectTimingGrade_Statics::NewProp_PerfectHitPercentageIn,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UScoreComponent_CalculatePerfectTimingGrade_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UScoreComponent_CalculatePerfectTimingGrade_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Components/ScoreComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UScoreComponent_CalculatePerfectTimingGrade_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UScoreComponent, nullptr, "CalculatePerfectTimingGrade", nullptr, nullptr, Z_Construct_UFunction_UScoreComponent_CalculatePerfectTimingGrade_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UScoreComponent_CalculatePerfectTimingGrade_Statics::PropPointers), sizeof(Z_Construct_UFunction_UScoreComponent_CalculatePerfectTimingGrade_Statics::ScoreComponent_eventCalculatePerfectTimingGrade_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UScoreComponent_CalculatePerfectTimingGrade_Statics::Function_MetaDataParams), Z_Construct_UFunction_UScoreComponent_CalculatePerfectTimingGrade_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UScoreComponent_CalculatePerfectTimingGrade_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UScoreComponent_CalculatePerfectTimingGrade_Statics::ScoreComponent_eventCalculatePerfectTimingGrade_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UScoreComponent_CalculatePerfectTimingGrade()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UScoreComponent_CalculatePerfectTimingGrade_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UScoreComponent_DepleteProgress_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UScoreComponent_DepleteProgress_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Components/ScoreComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UScoreComponent_DepleteProgress_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UScoreComponent, nullptr, "DepleteProgress", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UScoreComponent_DepleteProgress_Statics::Function_MetaDataParams), Z_Construct_UFunction_UScoreComponent_DepleteProgress_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UScoreComponent_DepleteProgress()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UScoreComponent_DepleteProgress_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UScoreComponent_EndEncounter_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UScoreComponent_EndEncounter_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Components/ScoreComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UScoreComponent_EndEncounter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UScoreComponent, nullptr, "EndEncounter", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UScoreComponent_EndEncounter_Statics::Function_MetaDataParams), Z_Construct_UFunction_UScoreComponent_EndEncounter_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UScoreComponent_EndEncounter()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UScoreComponent_EndEncounter_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UScoreComponent_GetClearTime_Statics
	{
		struct ScoreComponent_eventGetClearTime_Parms
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
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UScoreComponent_GetClearTime_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ScoreComponent_eventGetClearTime_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UScoreComponent_GetClearTime_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UScoreComponent_GetClearTime_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UScoreComponent_GetClearTime_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Components/ScoreComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UScoreComponent_GetClearTime_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UScoreComponent, nullptr, "GetClearTime", nullptr, nullptr, Z_Construct_UFunction_UScoreComponent_GetClearTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UScoreComponent_GetClearTime_Statics::PropPointers), sizeof(Z_Construct_UFunction_UScoreComponent_GetClearTime_Statics::ScoreComponent_eventGetClearTime_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UScoreComponent_GetClearTime_Statics::Function_MetaDataParams), Z_Construct_UFunction_UScoreComponent_GetClearTime_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UScoreComponent_GetClearTime_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UScoreComponent_GetClearTime_Statics::ScoreComponent_eventGetClearTime_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UScoreComponent_GetClearTime()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UScoreComponent_GetClearTime_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UScoreComponent_GetCurrentRankIndex_Statics
	{
		struct ScoreComponent_eventGetCurrentRankIndex_Parms
		{
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UScoreComponent_GetCurrentRankIndex_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ScoreComponent_eventGetCurrentRankIndex_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UScoreComponent_GetCurrentRankIndex_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UScoreComponent_GetCurrentRankIndex_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UScoreComponent_GetCurrentRankIndex_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Components/ScoreComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UScoreComponent_GetCurrentRankIndex_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UScoreComponent, nullptr, "GetCurrentRankIndex", nullptr, nullptr, Z_Construct_UFunction_UScoreComponent_GetCurrentRankIndex_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UScoreComponent_GetCurrentRankIndex_Statics::PropPointers), sizeof(Z_Construct_UFunction_UScoreComponent_GetCurrentRankIndex_Statics::ScoreComponent_eventGetCurrentRankIndex_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UScoreComponent_GetCurrentRankIndex_Statics::Function_MetaDataParams), Z_Construct_UFunction_UScoreComponent_GetCurrentRankIndex_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UScoreComponent_GetCurrentRankIndex_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UScoreComponent_GetCurrentRankIndex_Statics::ScoreComponent_eventGetCurrentRankIndex_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UScoreComponent_GetCurrentRankIndex()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UScoreComponent_GetCurrentRankIndex_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UScoreComponent_GetCurrentScore_Statics
	{
		struct ScoreComponent_eventGetCurrentScore_Parms
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
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UScoreComponent_GetCurrentScore_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ScoreComponent_eventGetCurrentScore_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UScoreComponent_GetCurrentScore_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UScoreComponent_GetCurrentScore_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UScoreComponent_GetCurrentScore_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Components/ScoreComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UScoreComponent_GetCurrentScore_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UScoreComponent, nullptr, "GetCurrentScore", nullptr, nullptr, Z_Construct_UFunction_UScoreComponent_GetCurrentScore_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UScoreComponent_GetCurrentScore_Statics::PropPointers), sizeof(Z_Construct_UFunction_UScoreComponent_GetCurrentScore_Statics::ScoreComponent_eventGetCurrentScore_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UScoreComponent_GetCurrentScore_Statics::Function_MetaDataParams), Z_Construct_UFunction_UScoreComponent_GetCurrentScore_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UScoreComponent_GetCurrentScore_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UScoreComponent_GetCurrentScore_Statics::ScoreComponent_eventGetCurrentScore_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UScoreComponent_GetCurrentScore()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UScoreComponent_GetCurrentScore_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UScoreComponent_GetPerfectTimingPercentage_Statics
	{
		struct ScoreComponent_eventGetPerfectTimingPercentage_Parms
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
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UScoreComponent_GetPerfectTimingPercentage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ScoreComponent_eventGetPerfectTimingPercentage_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UScoreComponent_GetPerfectTimingPercentage_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UScoreComponent_GetPerfectTimingPercentage_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UScoreComponent_GetPerfectTimingPercentage_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Components/ScoreComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UScoreComponent_GetPerfectTimingPercentage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UScoreComponent, nullptr, "GetPerfectTimingPercentage", nullptr, nullptr, Z_Construct_UFunction_UScoreComponent_GetPerfectTimingPercentage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UScoreComponent_GetPerfectTimingPercentage_Statics::PropPointers), sizeof(Z_Construct_UFunction_UScoreComponent_GetPerfectTimingPercentage_Statics::ScoreComponent_eventGetPerfectTimingPercentage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UScoreComponent_GetPerfectTimingPercentage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UScoreComponent_GetPerfectTimingPercentage_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UScoreComponent_GetPerfectTimingPercentage_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UScoreComponent_GetPerfectTimingPercentage_Statics::ScoreComponent_eventGetPerfectTimingPercentage_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UScoreComponent_GetPerfectTimingPercentage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UScoreComponent_GetPerfectTimingPercentage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UScoreComponent_GetRankProgress_Statics
	{
		struct ScoreComponent_eventGetRankProgress_Parms
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
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UScoreComponent_GetRankProgress_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ScoreComponent_eventGetRankProgress_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UScoreComponent_GetRankProgress_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UScoreComponent_GetRankProgress_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UScoreComponent_GetRankProgress_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Components/ScoreComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UScoreComponent_GetRankProgress_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UScoreComponent, nullptr, "GetRankProgress", nullptr, nullptr, Z_Construct_UFunction_UScoreComponent_GetRankProgress_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UScoreComponent_GetRankProgress_Statics::PropPointers), sizeof(Z_Construct_UFunction_UScoreComponent_GetRankProgress_Statics::ScoreComponent_eventGetRankProgress_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UScoreComponent_GetRankProgress_Statics::Function_MetaDataParams), Z_Construct_UFunction_UScoreComponent_GetRankProgress_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UScoreComponent_GetRankProgress_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UScoreComponent_GetRankProgress_Statics::ScoreComponent_eventGetRankProgress_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UScoreComponent_GetRankProgress()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UScoreComponent_GetRankProgress_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UScoreComponent_StartEncounter_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UScoreComponent_StartEncounter_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Components/ScoreComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UScoreComponent_StartEncounter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UScoreComponent, nullptr, "StartEncounter", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UScoreComponent_StartEncounter_Statics::Function_MetaDataParams), Z_Construct_UFunction_UScoreComponent_StartEncounter_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UScoreComponent_StartEncounter()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UScoreComponent_StartEncounter_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UScoreComponent);
	UClass* Z_Construct_UClass_UScoreComponent_NoRegister()
	{
		return UScoreComponent::StaticClass();
	}
	struct Z_Construct_UClass_UScoreComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PerfectHits_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_PerfectHits;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TotalHits_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_TotalHits;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EncounterStartTime_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_EncounterStartTime;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EncounterEndTime_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_EncounterEndTime;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TimeThresholdBGrade_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_TimeThresholdBGrade;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TimeThresholdAGrade_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_TimeThresholdAGrade;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TimeThresholdSGrade_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_TimeThresholdSGrade;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CurrentEncounterClearTime_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentEncounterClearTime;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PerfectTimingThresholdBGrade_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_PerfectTimingThresholdBGrade;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PerfectTimingThresholdAGrade_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_PerfectTimingThresholdAGrade;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PerfectTimingThresholdSGrade_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_PerfectTimingThresholdSGrade;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PerfectTimingPercent_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_PerfectTimingPercent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OverallScore_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_OverallScore;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FinalRank_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_FinalRank;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ThresholdBGrade_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_ThresholdBGrade;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ThresholdAGrade_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_ThresholdAGrade;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ThresholdSGrade_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_ThresholdSGrade;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CurrentRankIndex_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentRankIndex;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RankProgress_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_RankProgress;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DepletionRate_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DepletionRate;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ProgressIncreaseRate_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ProgressIncreaseRate;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UScoreComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_NeonParadigm_Game,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UScoreComponent_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UScoreComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UScoreComponent_CalculateClearTimeBonus, "CalculateClearTimeBonus" }, // 894259878
		{ &Z_Construct_UFunction_UScoreComponent_CalculateClearTimingGrade, "CalculateClearTimingGrade" }, // 1323070227
		{ &Z_Construct_UFunction_UScoreComponent_CalculateGrade, "CalculateGrade" }, // 609094439
		{ &Z_Construct_UFunction_UScoreComponent_CalculatePerfectTimingBonus, "CalculatePerfectTimingBonus" }, // 1281009352
		{ &Z_Construct_UFunction_UScoreComponent_CalculatePerfectTimingGrade, "CalculatePerfectTimingGrade" }, // 93639576
		{ &Z_Construct_UFunction_UScoreComponent_DepleteProgress, "DepleteProgress" }, // 1311843279
		{ &Z_Construct_UFunction_UScoreComponent_EndEncounter, "EndEncounter" }, // 290903661
		{ &Z_Construct_UFunction_UScoreComponent_GetClearTime, "GetClearTime" }, // 825575240
		{ &Z_Construct_UFunction_UScoreComponent_GetCurrentRankIndex, "GetCurrentRankIndex" }, // 3102506199
		{ &Z_Construct_UFunction_UScoreComponent_GetCurrentScore, "GetCurrentScore" }, // 1017296062
		{ &Z_Construct_UFunction_UScoreComponent_GetPerfectTimingPercentage, "GetPerfectTimingPercentage" }, // 2063625543
		{ &Z_Construct_UFunction_UScoreComponent_GetRankProgress, "GetRankProgress" }, // 807171787
		{ &Z_Construct_UFunction_UScoreComponent_StartEncounter, "StartEncounter" }, // 1206630286
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UScoreComponent_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UScoreComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "Components/ScoreComponent.h" },
		{ "ModuleRelativePath", "Components/ScoreComponent.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UScoreComponent_Statics::NewProp_PerfectHits_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Score" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Perfect Timing Score\n" },
#endif
		{ "ModuleRelativePath", "Components/ScoreComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Perfect Timing Score" },
#endif
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UScoreComponent_Statics::NewProp_PerfectHits = { "PerfectHits", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UScoreComponent, PerfectHits), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UScoreComponent_Statics::NewProp_PerfectHits_MetaData), Z_Construct_UClass_UScoreComponent_Statics::NewProp_PerfectHits_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UScoreComponent_Statics::NewProp_TotalHits_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Score" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Tracks the number of perfect hits\n" },
#endif
		{ "ModuleRelativePath", "Components/ScoreComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Tracks the number of perfect hits" },
#endif
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UScoreComponent_Statics::NewProp_TotalHits = { "TotalHits", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UScoreComponent, TotalHits), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UScoreComponent_Statics::NewProp_TotalHits_MetaData), Z_Construct_UClass_UScoreComponent_Statics::NewProp_TotalHits_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UScoreComponent_Statics::NewProp_EncounterStartTime_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Score" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Time Efficiency\n" },
#endif
		{ "ModuleRelativePath", "Components/ScoreComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Time Efficiency" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UScoreComponent_Statics::NewProp_EncounterStartTime = { "EncounterStartTime", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UScoreComponent, EncounterStartTime), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UScoreComponent_Statics::NewProp_EncounterStartTime_MetaData), Z_Construct_UClass_UScoreComponent_Statics::NewProp_EncounterStartTime_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UScoreComponent_Statics::NewProp_EncounterEndTime_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Score" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Time when the encounter started\n" },
#endif
		{ "ModuleRelativePath", "Components/ScoreComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Time when the encounter started" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UScoreComponent_Statics::NewProp_EncounterEndTime = { "EncounterEndTime", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UScoreComponent, EncounterEndTime), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UScoreComponent_Statics::NewProp_EncounterEndTime_MetaData), Z_Construct_UClass_UScoreComponent_Statics::NewProp_EncounterEndTime_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UScoreComponent_Statics::NewProp_TimeThresholdBGrade_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Score" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Time thresholds\n" },
#endif
		{ "ModuleRelativePath", "Components/ScoreComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Time thresholds" },
#endif
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UScoreComponent_Statics::NewProp_TimeThresholdBGrade = { "TimeThresholdBGrade", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UScoreComponent, TimeThresholdBGrade), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UScoreComponent_Statics::NewProp_TimeThresholdBGrade_MetaData), Z_Construct_UClass_UScoreComponent_Statics::NewProp_TimeThresholdBGrade_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UScoreComponent_Statics::NewProp_TimeThresholdAGrade_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Score" },
		{ "ModuleRelativePath", "Components/ScoreComponent.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UScoreComponent_Statics::NewProp_TimeThresholdAGrade = { "TimeThresholdAGrade", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UScoreComponent, TimeThresholdAGrade), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UScoreComponent_Statics::NewProp_TimeThresholdAGrade_MetaData), Z_Construct_UClass_UScoreComponent_Statics::NewProp_TimeThresholdAGrade_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UScoreComponent_Statics::NewProp_TimeThresholdSGrade_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Score" },
		{ "ModuleRelativePath", "Components/ScoreComponent.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UScoreComponent_Statics::NewProp_TimeThresholdSGrade = { "TimeThresholdSGrade", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UScoreComponent, TimeThresholdSGrade), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UScoreComponent_Statics::NewProp_TimeThresholdSGrade_MetaData), Z_Construct_UClass_UScoreComponent_Statics::NewProp_TimeThresholdSGrade_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UScoreComponent_Statics::NewProp_CurrentEncounterClearTime_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Score" },
		{ "ModuleRelativePath", "Components/ScoreComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UScoreComponent_Statics::NewProp_CurrentEncounterClearTime = { "CurrentEncounterClearTime", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UScoreComponent, CurrentEncounterClearTime), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UScoreComponent_Statics::NewProp_CurrentEncounterClearTime_MetaData), Z_Construct_UClass_UScoreComponent_Statics::NewProp_CurrentEncounterClearTime_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UScoreComponent_Statics::NewProp_PerfectTimingThresholdBGrade_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Score" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Pefect Timing thresholds\n" },
#endif
		{ "ModuleRelativePath", "Components/ScoreComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Pefect Timing thresholds" },
#endif
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UScoreComponent_Statics::NewProp_PerfectTimingThresholdBGrade = { "PerfectTimingThresholdBGrade", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UScoreComponent, PerfectTimingThresholdBGrade), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UScoreComponent_Statics::NewProp_PerfectTimingThresholdBGrade_MetaData), Z_Construct_UClass_UScoreComponent_Statics::NewProp_PerfectTimingThresholdBGrade_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UScoreComponent_Statics::NewProp_PerfectTimingThresholdAGrade_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Score" },
		{ "ModuleRelativePath", "Components/ScoreComponent.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UScoreComponent_Statics::NewProp_PerfectTimingThresholdAGrade = { "PerfectTimingThresholdAGrade", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UScoreComponent, PerfectTimingThresholdAGrade), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UScoreComponent_Statics::NewProp_PerfectTimingThresholdAGrade_MetaData), Z_Construct_UClass_UScoreComponent_Statics::NewProp_PerfectTimingThresholdAGrade_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UScoreComponent_Statics::NewProp_PerfectTimingThresholdSGrade_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Score" },
		{ "ModuleRelativePath", "Components/ScoreComponent.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UScoreComponent_Statics::NewProp_PerfectTimingThresholdSGrade = { "PerfectTimingThresholdSGrade", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UScoreComponent, PerfectTimingThresholdSGrade), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UScoreComponent_Statics::NewProp_PerfectTimingThresholdSGrade_MetaData), Z_Construct_UClass_UScoreComponent_Statics::NewProp_PerfectTimingThresholdSGrade_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UScoreComponent_Statics::NewProp_PerfectTimingPercent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Score" },
		{ "ModuleRelativePath", "Components/ScoreComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UScoreComponent_Statics::NewProp_PerfectTimingPercent = { "PerfectTimingPercent", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UScoreComponent, PerfectTimingPercent), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UScoreComponent_Statics::NewProp_PerfectTimingPercent_MetaData), Z_Construct_UClass_UScoreComponent_Statics::NewProp_PerfectTimingPercent_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UScoreComponent_Statics::NewProp_OverallScore_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Score" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Final Rank and Overall Score\n" },
#endif
		{ "ModuleRelativePath", "Components/ScoreComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Final Rank and Overall Score" },
#endif
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UScoreComponent_Statics::NewProp_OverallScore = { "OverallScore", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UScoreComponent, OverallScore), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UScoreComponent_Statics::NewProp_OverallScore_MetaData), Z_Construct_UClass_UScoreComponent_Statics::NewProp_OverallScore_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UScoreComponent_Statics::NewProp_FinalRank_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Score" },
		{ "ModuleRelativePath", "Components/ScoreComponent.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UScoreComponent_Statics::NewProp_FinalRank = { "FinalRank", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UScoreComponent, FinalRank), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UScoreComponent_Statics::NewProp_FinalRank_MetaData), Z_Construct_UClass_UScoreComponent_Statics::NewProp_FinalRank_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UScoreComponent_Statics::NewProp_ThresholdBGrade_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Score" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Grade thresholds\n" },
#endif
		{ "ModuleRelativePath", "Components/ScoreComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Grade thresholds" },
#endif
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UScoreComponent_Statics::NewProp_ThresholdBGrade = { "ThresholdBGrade", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UScoreComponent, ThresholdBGrade), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UScoreComponent_Statics::NewProp_ThresholdBGrade_MetaData), Z_Construct_UClass_UScoreComponent_Statics::NewProp_ThresholdBGrade_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UScoreComponent_Statics::NewProp_ThresholdAGrade_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Score" },
		{ "ModuleRelativePath", "Components/ScoreComponent.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UScoreComponent_Statics::NewProp_ThresholdAGrade = { "ThresholdAGrade", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UScoreComponent, ThresholdAGrade), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UScoreComponent_Statics::NewProp_ThresholdAGrade_MetaData), Z_Construct_UClass_UScoreComponent_Statics::NewProp_ThresholdAGrade_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UScoreComponent_Statics::NewProp_ThresholdSGrade_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Score" },
		{ "ModuleRelativePath", "Components/ScoreComponent.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UScoreComponent_Statics::NewProp_ThresholdSGrade = { "ThresholdSGrade", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UScoreComponent, ThresholdSGrade), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UScoreComponent_Statics::NewProp_ThresholdSGrade_MetaData), Z_Construct_UClass_UScoreComponent_Statics::NewProp_ThresholdSGrade_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UScoreComponent_Statics::NewProp_CurrentRankIndex_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Score" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// below for Style Letter Progress Bar\n" },
#endif
		{ "ModuleRelativePath", "Components/ScoreComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "below for Style Letter Progress Bar" },
#endif
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UScoreComponent_Statics::NewProp_CurrentRankIndex = { "CurrentRankIndex", nullptr, (EPropertyFlags)0x0040000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UScoreComponent, CurrentRankIndex), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UScoreComponent_Statics::NewProp_CurrentRankIndex_MetaData), Z_Construct_UClass_UScoreComponent_Statics::NewProp_CurrentRankIndex_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UScoreComponent_Statics::NewProp_RankProgress_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Score" },
		{ "ModuleRelativePath", "Components/ScoreComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UScoreComponent_Statics::NewProp_RankProgress = { "RankProgress", nullptr, (EPropertyFlags)0x0040000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UScoreComponent, RankProgress), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UScoreComponent_Statics::NewProp_RankProgress_MetaData), Z_Construct_UClass_UScoreComponent_Statics::NewProp_RankProgress_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UScoreComponent_Statics::NewProp_DepletionRate_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Score" },
		{ "ModuleRelativePath", "Components/ScoreComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UScoreComponent_Statics::NewProp_DepletionRate = { "DepletionRate", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UScoreComponent, DepletionRate), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UScoreComponent_Statics::NewProp_DepletionRate_MetaData), Z_Construct_UClass_UScoreComponent_Statics::NewProp_DepletionRate_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UScoreComponent_Statics::NewProp_ProgressIncreaseRate_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Score" },
		{ "ModuleRelativePath", "Components/ScoreComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UScoreComponent_Statics::NewProp_ProgressIncreaseRate = { "ProgressIncreaseRate", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UScoreComponent, ProgressIncreaseRate), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UScoreComponent_Statics::NewProp_ProgressIncreaseRate_MetaData), Z_Construct_UClass_UScoreComponent_Statics::NewProp_ProgressIncreaseRate_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UScoreComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UScoreComponent_Statics::NewProp_PerfectHits,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UScoreComponent_Statics::NewProp_TotalHits,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UScoreComponent_Statics::NewProp_EncounterStartTime,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UScoreComponent_Statics::NewProp_EncounterEndTime,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UScoreComponent_Statics::NewProp_TimeThresholdBGrade,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UScoreComponent_Statics::NewProp_TimeThresholdAGrade,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UScoreComponent_Statics::NewProp_TimeThresholdSGrade,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UScoreComponent_Statics::NewProp_CurrentEncounterClearTime,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UScoreComponent_Statics::NewProp_PerfectTimingThresholdBGrade,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UScoreComponent_Statics::NewProp_PerfectTimingThresholdAGrade,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UScoreComponent_Statics::NewProp_PerfectTimingThresholdSGrade,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UScoreComponent_Statics::NewProp_PerfectTimingPercent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UScoreComponent_Statics::NewProp_OverallScore,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UScoreComponent_Statics::NewProp_FinalRank,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UScoreComponent_Statics::NewProp_ThresholdBGrade,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UScoreComponent_Statics::NewProp_ThresholdAGrade,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UScoreComponent_Statics::NewProp_ThresholdSGrade,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UScoreComponent_Statics::NewProp_CurrentRankIndex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UScoreComponent_Statics::NewProp_RankProgress,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UScoreComponent_Statics::NewProp_DepletionRate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UScoreComponent_Statics::NewProp_ProgressIncreaseRate,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UScoreComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UScoreComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UScoreComponent_Statics::ClassParams = {
		&UScoreComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UScoreComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UScoreComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UScoreComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UScoreComponent_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UScoreComponent_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UScoreComponent()
	{
		if (!Z_Registration_Info_UClass_UScoreComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UScoreComponent.OuterSingleton, Z_Construct_UClass_UScoreComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UScoreComponent.OuterSingleton;
	}
	template<> NEONPARADIGM_GAME_API UClass* StaticClass<UScoreComponent>()
	{
		return UScoreComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UScoreComponent);
	UScoreComponent::~UScoreComponent() {}
	struct Z_CompiledInDeferFile_FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Components_ScoreComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Components_ScoreComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UScoreComponent, UScoreComponent::StaticClass, TEXT("UScoreComponent"), &Z_Registration_Info_UClass_UScoreComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UScoreComponent), 3627014035U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Components_ScoreComponent_h_2549980438(TEXT("/Script/NeonParadigm_Game"),
		Z_CompiledInDeferFile_FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Components_ScoreComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Components_ScoreComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
