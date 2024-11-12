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
			{ "GetCurrentScore", &UScoreComponent::execGetCurrentScore },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
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
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UScoreComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_NeonParadigm_Game,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UScoreComponent_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UScoreComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UScoreComponent_GetCurrentScore, "GetCurrentScore" }, // 1017296062
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
	const FCppClassTypeInfoStatic Z_Construct_UClass_UScoreComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UScoreComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UScoreComponent_Statics::ClassParams = {
		&UScoreComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UScoreComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UScoreComponent_Statics::Class_MetaDataParams)
	};
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
		{ Z_Construct_UClass_UScoreComponent, UScoreComponent::StaticClass, TEXT("UScoreComponent"), &Z_Registration_Info_UClass_UScoreComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UScoreComponent), 1379708320U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Components_ScoreComponent_h_3002423260(TEXT("/Script/NeonParadigm_Game"),
		Z_CompiledInDeferFile_FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Components_ScoreComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Components_ScoreComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
