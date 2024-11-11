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
	void UScoreComponent::StaticRegisterNativesUScoreComponent()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UScoreComponent);
	UClass* Z_Construct_UClass_UScoreComponent_NoRegister()
	{
		return UScoreComponent::StaticClass();
	}
	struct Z_Construct_UClass_UScoreComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
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
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
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
		{ Z_Construct_UClass_UScoreComponent, UScoreComponent::StaticClass, TEXT("UScoreComponent"), &Z_Registration_Info_UClass_UScoreComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UScoreComponent), 1381426868U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Components_ScoreComponent_h_3920246027(TEXT("/Script/NeonParadigm_Game"),
		Z_CompiledInDeferFile_FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Components_ScoreComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Components_ScoreComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
