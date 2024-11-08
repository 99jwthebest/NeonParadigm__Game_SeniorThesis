// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NeonParadigm_Game/NeonParadigm_GameGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNeonParadigm_GameGameMode() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_ANeonParadigm_GameGameMode();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_ANeonParadigm_GameGameMode_NoRegister();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UScoreComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_NeonParadigm_Game();
// End Cross Module References
	void ANeonParadigm_GameGameMode::StaticRegisterNativesANeonParadigm_GameGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ANeonParadigm_GameGameMode);
	UClass* Z_Construct_UClass_ANeonParadigm_GameGameMode_NoRegister()
	{
		return ANeonParadigm_GameGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ANeonParadigm_GameGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ScoreComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ScoreComp;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ANeonParadigm_GameGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_NeonParadigm_Game,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameGameMode_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "NeonParadigm_GameGameMode.h" },
		{ "ModuleRelativePath", "NeonParadigm_GameGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANeonParadigm_GameGameMode_Statics::NewProp_ScoreComp_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Attack" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "NeonParadigm_GameGameMode.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANeonParadigm_GameGameMode_Statics::NewProp_ScoreComp = { "ScoreComp", nullptr, (EPropertyFlags)0x004000000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANeonParadigm_GameGameMode, ScoreComp), Z_Construct_UClass_UScoreComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameGameMode_Statics::NewProp_ScoreComp_MetaData), Z_Construct_UClass_ANeonParadigm_GameGameMode_Statics::NewProp_ScoreComp_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ANeonParadigm_GameGameMode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANeonParadigm_GameGameMode_Statics::NewProp_ScoreComp,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ANeonParadigm_GameGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANeonParadigm_GameGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ANeonParadigm_GameGameMode_Statics::ClassParams = {
		&ANeonParadigm_GameGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ANeonParadigm_GameGameMode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameGameMode_Statics::PropPointers),
		0,
		0x008802ACu,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ANeonParadigm_GameGameMode_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameGameMode_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ANeonParadigm_GameGameMode()
	{
		if (!Z_Registration_Info_UClass_ANeonParadigm_GameGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ANeonParadigm_GameGameMode.OuterSingleton, Z_Construct_UClass_ANeonParadigm_GameGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ANeonParadigm_GameGameMode.OuterSingleton;
	}
	template<> NEONPARADIGM_GAME_API UClass* StaticClass<ANeonParadigm_GameGameMode>()
	{
		return ANeonParadigm_GameGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANeonParadigm_GameGameMode);
	ANeonParadigm_GameGameMode::~ANeonParadigm_GameGameMode() {}
	struct Z_CompiledInDeferFile_FID__Jhernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_NeonParadigm_GameGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID__Jhernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_NeonParadigm_GameGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ANeonParadigm_GameGameMode, ANeonParadigm_GameGameMode::StaticClass, TEXT("ANeonParadigm_GameGameMode"), &Z_Registration_Info_UClass_ANeonParadigm_GameGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ANeonParadigm_GameGameMode), 3770054027U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID__Jhernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_NeonParadigm_GameGameMode_h_3388648912(TEXT("/Script/NeonParadigm_Game"),
		Z_CompiledInDeferFile_FID__Jhernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_NeonParadigm_GameGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID__Jhernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_NeonParadigm_GameGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
