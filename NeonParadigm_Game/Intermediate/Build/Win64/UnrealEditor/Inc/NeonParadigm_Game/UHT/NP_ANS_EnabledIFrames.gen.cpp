// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NeonParadigm_Game/AnimNotify/NP_ANS_EnabledIFrames.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNP_ANS_EnabledIFrames() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UAnimNotifyState();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UNP_ANS_EnabledIFrames();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UNP_ANS_EnabledIFrames_NoRegister();
	UPackage* Z_Construct_UPackage__Script_NeonParadigm_Game();
// End Cross Module References
	void UNP_ANS_EnabledIFrames::StaticRegisterNativesUNP_ANS_EnabledIFrames()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UNP_ANS_EnabledIFrames);
	UClass* Z_Construct_UClass_UNP_ANS_EnabledIFrames_NoRegister()
	{
		return UNP_ANS_EnabledIFrames::StaticClass();
	}
	struct Z_Construct_UClass_UNP_ANS_EnabledIFrames_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UNP_ANS_EnabledIFrames_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimNotifyState,
		(UObject* (*)())Z_Construct_UPackage__Script_NeonParadigm_Game,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNP_ANS_EnabledIFrames_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNP_ANS_EnabledIFrames_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Object" },
		{ "IncludePath", "AnimNotify/NP_ANS_EnabledIFrames.h" },
		{ "ModuleRelativePath", "AnimNotify/NP_ANS_EnabledIFrames.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UNP_ANS_EnabledIFrames_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UNP_ANS_EnabledIFrames>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UNP_ANS_EnabledIFrames_Statics::ClassParams = {
		&UNP_ANS_EnabledIFrames::StaticClass,
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
		0x001130A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNP_ANS_EnabledIFrames_Statics::Class_MetaDataParams), Z_Construct_UClass_UNP_ANS_EnabledIFrames_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UNP_ANS_EnabledIFrames()
	{
		if (!Z_Registration_Info_UClass_UNP_ANS_EnabledIFrames.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UNP_ANS_EnabledIFrames.OuterSingleton, Z_Construct_UClass_UNP_ANS_EnabledIFrames_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UNP_ANS_EnabledIFrames.OuterSingleton;
	}
	template<> NEONPARADIGM_GAME_API UClass* StaticClass<UNP_ANS_EnabledIFrames>()
	{
		return UNP_ANS_EnabledIFrames::StaticClass();
	}
	UNP_ANS_EnabledIFrames::UNP_ANS_EnabledIFrames(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UNP_ANS_EnabledIFrames);
	UNP_ANS_EnabledIFrames::~UNP_ANS_EnabledIFrames() {}
	struct Z_CompiledInDeferFile_FID_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_NP_ANS_EnabledIFrames_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_NP_ANS_EnabledIFrames_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UNP_ANS_EnabledIFrames, UNP_ANS_EnabledIFrames::StaticClass, TEXT("UNP_ANS_EnabledIFrames"), &Z_Registration_Info_UClass_UNP_ANS_EnabledIFrames, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UNP_ANS_EnabledIFrames), 1009179381U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_NP_ANS_EnabledIFrames_h_2203057861(TEXT("/Script/NeonParadigm_Game"),
		Z_CompiledInDeferFile_FID_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_NP_ANS_EnabledIFrames_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_NP_ANS_EnabledIFrames_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
