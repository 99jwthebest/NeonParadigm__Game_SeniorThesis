// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NeonParadigm_Game/AnimNotify/NP_AN_ResetState.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNP_AN_ResetState() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UAnimNotify();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UCharacterStateComponent_NoRegister();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UNP_AN_ResetState();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UNP_AN_ResetState_NoRegister();
	UPackage* Z_Construct_UPackage__Script_NeonParadigm_Game();
// End Cross Module References
	void UNP_AN_ResetState::StaticRegisterNativesUNP_AN_ResetState()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UNP_AN_ResetState);
	UClass* Z_Construct_UClass_UNP_AN_ResetState_NoRegister()
	{
		return UNP_AN_ResetState::StaticClass();
	}
	struct Z_Construct_UClass_UNP_AN_ResetState_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CharacterStateComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CharacterStateComp;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UNP_AN_ResetState_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimNotify,
		(UObject* (*)())Z_Construct_UPackage__Script_NeonParadigm_Game,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNP_AN_ResetState_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNP_AN_ResetState_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Object" },
		{ "IncludePath", "AnimNotify/NP_AN_ResetState.h" },
		{ "ModuleRelativePath", "AnimNotify/NP_AN_ResetState.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNP_AN_ResetState_Statics::NewProp_CharacterStateComp_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "AnimNotify/NP_AN_ResetState.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UNP_AN_ResetState_Statics::NewProp_CharacterStateComp = { "CharacterStateComp", nullptr, (EPropertyFlags)0x0040000000080018, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNP_AN_ResetState, CharacterStateComp), Z_Construct_UClass_UCharacterStateComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNP_AN_ResetState_Statics::NewProp_CharacterStateComp_MetaData), Z_Construct_UClass_UNP_AN_ResetState_Statics::NewProp_CharacterStateComp_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UNP_AN_ResetState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNP_AN_ResetState_Statics::NewProp_CharacterStateComp,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UNP_AN_ResetState_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UNP_AN_ResetState>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UNP_AN_ResetState_Statics::ClassParams = {
		&UNP_AN_ResetState::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UNP_AN_ResetState_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UNP_AN_ResetState_Statics::PropPointers),
		0,
		0x009120A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNP_AN_ResetState_Statics::Class_MetaDataParams), Z_Construct_UClass_UNP_AN_ResetState_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNP_AN_ResetState_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UNP_AN_ResetState()
	{
		if (!Z_Registration_Info_UClass_UNP_AN_ResetState.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UNP_AN_ResetState.OuterSingleton, Z_Construct_UClass_UNP_AN_ResetState_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UNP_AN_ResetState.OuterSingleton;
	}
	template<> NEONPARADIGM_GAME_API UClass* StaticClass<UNP_AN_ResetState>()
	{
		return UNP_AN_ResetState::StaticClass();
	}
	UNP_AN_ResetState::UNP_AN_ResetState(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UNP_AN_ResetState);
	UNP_AN_ResetState::~UNP_AN_ResetState() {}
	struct Z_CompiledInDeferFile_FID_Users_anmart28_Documents_GitHub_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_NP_AN_ResetState_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_anmart28_Documents_GitHub_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_NP_AN_ResetState_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UNP_AN_ResetState, UNP_AN_ResetState::StaticClass, TEXT("UNP_AN_ResetState"), &Z_Registration_Info_UClass_UNP_AN_ResetState, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UNP_AN_ResetState), 291130442U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_anmart28_Documents_GitHub_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_NP_AN_ResetState_h_2582155844(TEXT("/Script/NeonParadigm_Game"),
		Z_CompiledInDeferFile_FID_Users_anmart28_Documents_GitHub_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_NP_AN_ResetState_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_anmart28_Documents_GitHub_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_NP_AN_ResetState_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
