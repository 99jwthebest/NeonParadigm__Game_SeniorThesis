// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NeonParadigm_Game/AnimNotify/NP_AN_LaunchPlayer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNP_AN_LaunchPlayer() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UAnimNotify();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UNP_AN_LaunchPlayer();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UNP_AN_LaunchPlayer_NoRegister();
	UPackage* Z_Construct_UPackage__Script_NeonParadigm_Game();
// End Cross Module References
	void UNP_AN_LaunchPlayer::StaticRegisterNativesUNP_AN_LaunchPlayer()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UNP_AN_LaunchPlayer);
	UClass* Z_Construct_UClass_UNP_AN_LaunchPlayer_NoRegister()
	{
		return UNP_AN_LaunchPlayer::StaticClass();
	}
	struct Z_Construct_UClass_UNP_AN_LaunchPlayer_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UNP_AN_LaunchPlayer_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimNotify,
		(UObject* (*)())Z_Construct_UPackage__Script_NeonParadigm_Game,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNP_AN_LaunchPlayer_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNP_AN_LaunchPlayer_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Object" },
		{ "IncludePath", "AnimNotify/NP_AN_LaunchPlayer.h" },
		{ "ModuleRelativePath", "AnimNotify/NP_AN_LaunchPlayer.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UNP_AN_LaunchPlayer_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UNP_AN_LaunchPlayer>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UNP_AN_LaunchPlayer_Statics::ClassParams = {
		&UNP_AN_LaunchPlayer::StaticClass,
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
		0x001120A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNP_AN_LaunchPlayer_Statics::Class_MetaDataParams), Z_Construct_UClass_UNP_AN_LaunchPlayer_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UNP_AN_LaunchPlayer()
	{
		if (!Z_Registration_Info_UClass_UNP_AN_LaunchPlayer.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UNP_AN_LaunchPlayer.OuterSingleton, Z_Construct_UClass_UNP_AN_LaunchPlayer_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UNP_AN_LaunchPlayer.OuterSingleton;
	}
	template<> NEONPARADIGM_GAME_API UClass* StaticClass<UNP_AN_LaunchPlayer>()
	{
		return UNP_AN_LaunchPlayer::StaticClass();
	}
	UNP_AN_LaunchPlayer::UNP_AN_LaunchPlayer(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UNP_AN_LaunchPlayer);
	UNP_AN_LaunchPlayer::~UNP_AN_LaunchPlayer() {}
	struct Z_CompiledInDeferFile_FID__Jhernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_NP_AN_LaunchPlayer_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID__Jhernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_NP_AN_LaunchPlayer_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UNP_AN_LaunchPlayer, UNP_AN_LaunchPlayer::StaticClass, TEXT("UNP_AN_LaunchPlayer"), &Z_Registration_Info_UClass_UNP_AN_LaunchPlayer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UNP_AN_LaunchPlayer), 74358110U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID__Jhernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_NP_AN_LaunchPlayer_h_165033653(TEXT("/Script/NeonParadigm_Game"),
		Z_CompiledInDeferFile_FID__Jhernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_NP_AN_LaunchPlayer_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID__Jhernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_NP_AN_LaunchPlayer_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
