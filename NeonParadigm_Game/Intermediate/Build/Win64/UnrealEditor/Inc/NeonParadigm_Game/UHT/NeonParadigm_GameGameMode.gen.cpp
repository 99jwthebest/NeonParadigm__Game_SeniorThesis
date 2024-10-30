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
	const FCppClassTypeInfoStatic Z_Construct_UClass_ANeonParadigm_GameGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANeonParadigm_GameGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ANeonParadigm_GameGameMode_Statics::ClassParams = {
		&ANeonParadigm_GameGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANeonParadigm_GameGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ANeonParadigm_GameGameMode_Statics::Class_MetaDataParams)
	};
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
	struct Z_CompiledInDeferFile_FID__J_Hernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_NeonParadigm_GameGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID__J_Hernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_NeonParadigm_GameGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ANeonParadigm_GameGameMode, ANeonParadigm_GameGameMode::StaticClass, TEXT("ANeonParadigm_GameGameMode"), &Z_Registration_Info_UClass_ANeonParadigm_GameGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ANeonParadigm_GameGameMode), 2602507711U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID__J_Hernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_NeonParadigm_GameGameMode_h_1947900633(TEXT("/Script/NeonParadigm_Game"),
		Z_CompiledInDeferFile_FID__J_Hernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_NeonParadigm_GameGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID__J_Hernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_NeonParadigm_GameGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
