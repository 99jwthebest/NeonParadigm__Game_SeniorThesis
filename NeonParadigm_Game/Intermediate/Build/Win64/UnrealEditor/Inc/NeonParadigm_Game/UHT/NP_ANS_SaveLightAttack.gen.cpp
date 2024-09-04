// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NeonParadigm_Game/AnimNotify/NP_ANS_SaveLightAttack.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNP_ANS_SaveLightAttack() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UAnimNotifyState();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UAttackComponent_NoRegister();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UNP_ANS_SaveLightAttack();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UNP_ANS_SaveLightAttack_NoRegister();
	UPackage* Z_Construct_UPackage__Script_NeonParadigm_Game();
// End Cross Module References
	void UNP_ANS_SaveLightAttack::StaticRegisterNativesUNP_ANS_SaveLightAttack()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UNP_ANS_SaveLightAttack);
	UClass* Z_Construct_UClass_UNP_ANS_SaveLightAttack_NoRegister()
	{
		return UNP_ANS_SaveLightAttack::StaticClass();
	}
	struct Z_Construct_UClass_UNP_ANS_SaveLightAttack_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AttackComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AttackComp;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UNP_ANS_SaveLightAttack_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimNotifyState,
		(UObject* (*)())Z_Construct_UPackage__Script_NeonParadigm_Game,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNP_ANS_SaveLightAttack_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNP_ANS_SaveLightAttack_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Object" },
		{ "IncludePath", "AnimNotify/NP_ANS_SaveLightAttack.h" },
		{ "ModuleRelativePath", "AnimNotify/NP_ANS_SaveLightAttack.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNP_ANS_SaveLightAttack_Statics::NewProp_AttackComp_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "AnimNotify/NP_ANS_SaveLightAttack.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UNP_ANS_SaveLightAttack_Statics::NewProp_AttackComp = { "AttackComp", nullptr, (EPropertyFlags)0x0010000000080018, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNP_ANS_SaveLightAttack, AttackComp), Z_Construct_UClass_UAttackComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNP_ANS_SaveLightAttack_Statics::NewProp_AttackComp_MetaData), Z_Construct_UClass_UNP_ANS_SaveLightAttack_Statics::NewProp_AttackComp_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UNP_ANS_SaveLightAttack_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNP_ANS_SaveLightAttack_Statics::NewProp_AttackComp,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UNP_ANS_SaveLightAttack_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UNP_ANS_SaveLightAttack>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UNP_ANS_SaveLightAttack_Statics::ClassParams = {
		&UNP_ANS_SaveLightAttack::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UNP_ANS_SaveLightAttack_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UNP_ANS_SaveLightAttack_Statics::PropPointers),
		0,
		0x009130A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNP_ANS_SaveLightAttack_Statics::Class_MetaDataParams), Z_Construct_UClass_UNP_ANS_SaveLightAttack_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNP_ANS_SaveLightAttack_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UNP_ANS_SaveLightAttack()
	{
		if (!Z_Registration_Info_UClass_UNP_ANS_SaveLightAttack.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UNP_ANS_SaveLightAttack.OuterSingleton, Z_Construct_UClass_UNP_ANS_SaveLightAttack_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UNP_ANS_SaveLightAttack.OuterSingleton;
	}
	template<> NEONPARADIGM_GAME_API UClass* StaticClass<UNP_ANS_SaveLightAttack>()
	{
		return UNP_ANS_SaveLightAttack::StaticClass();
	}
	UNP_ANS_SaveLightAttack::UNP_ANS_SaveLightAttack(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UNP_ANS_SaveLightAttack);
	UNP_ANS_SaveLightAttack::~UNP_ANS_SaveLightAttack() {}
	struct Z_CompiledInDeferFile_FID__JHernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_NP_ANS_SaveLightAttack_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID__JHernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_NP_ANS_SaveLightAttack_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UNP_ANS_SaveLightAttack, UNP_ANS_SaveLightAttack::StaticClass, TEXT("UNP_ANS_SaveLightAttack"), &Z_Registration_Info_UClass_UNP_ANS_SaveLightAttack, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UNP_ANS_SaveLightAttack), 636124179U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID__JHernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_NP_ANS_SaveLightAttack_h_1208843618(TEXT("/Script/NeonParadigm_Game"),
		Z_CompiledInDeferFile_FID__JHernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_NP_ANS_SaveLightAttack_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID__JHernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_NP_ANS_SaveLightAttack_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
