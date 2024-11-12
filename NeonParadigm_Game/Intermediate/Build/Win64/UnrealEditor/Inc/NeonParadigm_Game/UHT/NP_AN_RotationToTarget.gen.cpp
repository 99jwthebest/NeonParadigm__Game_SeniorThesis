// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NeonParadigm_Game/AnimNotify/NP_AN_RotationToTarget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNP_AN_RotationToTarget() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UAnimNotify();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UNP_AN_RotationToTarget();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UNP_AN_RotationToTarget_NoRegister();
	UPackage* Z_Construct_UPackage__Script_NeonParadigm_Game();
// End Cross Module References
	void UNP_AN_RotationToTarget::StaticRegisterNativesUNP_AN_RotationToTarget()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UNP_AN_RotationToTarget);
	UClass* Z_Construct_UClass_UNP_AN_RotationToTarget_NoRegister()
	{
		return UNP_AN_RotationToTarget::StaticClass();
	}
	struct Z_Construct_UClass_UNP_AN_RotationToTarget_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UNP_AN_RotationToTarget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimNotify,
		(UObject* (*)())Z_Construct_UPackage__Script_NeonParadigm_Game,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNP_AN_RotationToTarget_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNP_AN_RotationToTarget_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Object" },
		{ "IncludePath", "AnimNotify/NP_AN_RotationToTarget.h" },
		{ "ModuleRelativePath", "AnimNotify/NP_AN_RotationToTarget.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UNP_AN_RotationToTarget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UNP_AN_RotationToTarget>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UNP_AN_RotationToTarget_Statics::ClassParams = {
		&UNP_AN_RotationToTarget::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNP_AN_RotationToTarget_Statics::Class_MetaDataParams), Z_Construct_UClass_UNP_AN_RotationToTarget_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UNP_AN_RotationToTarget()
	{
		if (!Z_Registration_Info_UClass_UNP_AN_RotationToTarget.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UNP_AN_RotationToTarget.OuterSingleton, Z_Construct_UClass_UNP_AN_RotationToTarget_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UNP_AN_RotationToTarget.OuterSingleton;
	}
	template<> NEONPARADIGM_GAME_API UClass* StaticClass<UNP_AN_RotationToTarget>()
	{
		return UNP_AN_RotationToTarget::StaticClass();
	}
	UNP_AN_RotationToTarget::UNP_AN_RotationToTarget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UNP_AN_RotationToTarget);
	UNP_AN_RotationToTarget::~UNP_AN_RotationToTarget() {}
	struct Z_CompiledInDeferFile_FID__Jhernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_NP_AN_RotationToTarget_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID__Jhernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_NP_AN_RotationToTarget_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UNP_AN_RotationToTarget, UNP_AN_RotationToTarget::StaticClass, TEXT("UNP_AN_RotationToTarget"), &Z_Registration_Info_UClass_UNP_AN_RotationToTarget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UNP_AN_RotationToTarget), 1781809188U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID__Jhernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_NP_AN_RotationToTarget_h_4272179963(TEXT("/Script/NeonParadigm_Game"),
		Z_CompiledInDeferFile_FID__Jhernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_NP_AN_RotationToTarget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID__Jhernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_NP_AN_RotationToTarget_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
