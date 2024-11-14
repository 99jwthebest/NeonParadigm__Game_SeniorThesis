// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NeonParadigm_Game/Framework/IAudio.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeIAudio() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UAudio();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UAudio_NoRegister();
	UPackage* Z_Construct_UPackage__Script_NeonParadigm_Game();
// End Cross Module References
	void UAudio::StaticRegisterNativesUAudio()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UAudio);
	UClass* Z_Construct_UClass_UAudio_NoRegister()
	{
		return UAudio::StaticClass();
	}
	struct Z_Construct_UClass_UAudio_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UAudio_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_NeonParadigm_Game,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAudio_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAudio_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Framework/IAudio.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UAudio_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IAudio>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UAudio_Statics::ClassParams = {
		&UAudio::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x000840A1u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAudio_Statics::Class_MetaDataParams), Z_Construct_UClass_UAudio_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UAudio()
	{
		if (!Z_Registration_Info_UClass_UAudio.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAudio.OuterSingleton, Z_Construct_UClass_UAudio_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UAudio.OuterSingleton;
	}
	template<> NEONPARADIGM_GAME_API UClass* StaticClass<UAudio>()
	{
		return UAudio::StaticClass();
	}
	UAudio::UAudio(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAudio);
	UAudio::~UAudio() {}
	struct Z_CompiledInDeferFile_FID_NeonParadigm_Game_Source_NeonParadigm_Game_Framework_IAudio_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_NeonParadigm_Game_Source_NeonParadigm_Game_Framework_IAudio_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UAudio, UAudio::StaticClass, TEXT("UAudio"), &Z_Registration_Info_UClass_UAudio, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAudio), 3187926722U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_NeonParadigm_Game_Source_NeonParadigm_Game_Framework_IAudio_h_2774273157(TEXT("/Script/NeonParadigm_Game"),
		Z_CompiledInDeferFile_FID_NeonParadigm_Game_Source_NeonParadigm_Game_Framework_IAudio_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_NeonParadigm_Game_Source_NeonParadigm_Game_Framework_IAudio_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
