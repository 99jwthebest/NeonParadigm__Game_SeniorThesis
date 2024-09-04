// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NeonParadigm_Game/AnimNotify/NP_ANS_SaveHeavyAttack.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNP_ANS_SaveHeavyAttack() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UAnimNotifyState();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UAttackComponent_NoRegister();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UNP_ANS_SaveHeavyAttack();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UNP_ANS_SaveHeavyAttack_NoRegister();
	UPackage* Z_Construct_UPackage__Script_NeonParadigm_Game();
// End Cross Module References
	void UNP_ANS_SaveHeavyAttack::StaticRegisterNativesUNP_ANS_SaveHeavyAttack()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UNP_ANS_SaveHeavyAttack);
	UClass* Z_Construct_UClass_UNP_ANS_SaveHeavyAttack_NoRegister()
	{
		return UNP_ANS_SaveHeavyAttack::StaticClass();
	}
	struct Z_Construct_UClass_UNP_ANS_SaveHeavyAttack_Statics
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
	UObject* (*const Z_Construct_UClass_UNP_ANS_SaveHeavyAttack_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimNotifyState,
		(UObject* (*)())Z_Construct_UPackage__Script_NeonParadigm_Game,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNP_ANS_SaveHeavyAttack_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNP_ANS_SaveHeavyAttack_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Object" },
		{ "IncludePath", "AnimNotify/NP_ANS_SaveHeavyAttack.h" },
		{ "ModuleRelativePath", "AnimNotify/NP_ANS_SaveHeavyAttack.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNP_ANS_SaveHeavyAttack_Statics::NewProp_AttackComp_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "AnimNotify/NP_ANS_SaveHeavyAttack.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UNP_ANS_SaveHeavyAttack_Statics::NewProp_AttackComp = { "AttackComp", nullptr, (EPropertyFlags)0x0010000000080018, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNP_ANS_SaveHeavyAttack, AttackComp), Z_Construct_UClass_UAttackComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNP_ANS_SaveHeavyAttack_Statics::NewProp_AttackComp_MetaData), Z_Construct_UClass_UNP_ANS_SaveHeavyAttack_Statics::NewProp_AttackComp_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UNP_ANS_SaveHeavyAttack_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNP_ANS_SaveHeavyAttack_Statics::NewProp_AttackComp,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UNP_ANS_SaveHeavyAttack_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UNP_ANS_SaveHeavyAttack>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UNP_ANS_SaveHeavyAttack_Statics::ClassParams = {
		&UNP_ANS_SaveHeavyAttack::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UNP_ANS_SaveHeavyAttack_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UNP_ANS_SaveHeavyAttack_Statics::PropPointers),
		0,
		0x009130A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNP_ANS_SaveHeavyAttack_Statics::Class_MetaDataParams), Z_Construct_UClass_UNP_ANS_SaveHeavyAttack_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNP_ANS_SaveHeavyAttack_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UNP_ANS_SaveHeavyAttack()
	{
		if (!Z_Registration_Info_UClass_UNP_ANS_SaveHeavyAttack.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UNP_ANS_SaveHeavyAttack.OuterSingleton, Z_Construct_UClass_UNP_ANS_SaveHeavyAttack_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UNP_ANS_SaveHeavyAttack.OuterSingleton;
	}
	template<> NEONPARADIGM_GAME_API UClass* StaticClass<UNP_ANS_SaveHeavyAttack>()
	{
		return UNP_ANS_SaveHeavyAttack::StaticClass();
	}
	UNP_ANS_SaveHeavyAttack::UNP_ANS_SaveHeavyAttack(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UNP_ANS_SaveHeavyAttack);
	UNP_ANS_SaveHeavyAttack::~UNP_ANS_SaveHeavyAttack() {}
	struct Z_CompiledInDeferFile_FID__JHernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_NP_ANS_SaveHeavyAttack_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID__JHernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_NP_ANS_SaveHeavyAttack_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UNP_ANS_SaveHeavyAttack, UNP_ANS_SaveHeavyAttack::StaticClass, TEXT("UNP_ANS_SaveHeavyAttack"), &Z_Registration_Info_UClass_UNP_ANS_SaveHeavyAttack, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UNP_ANS_SaveHeavyAttack), 1054905094U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID__JHernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_NP_ANS_SaveHeavyAttack_h_2458929030(TEXT("/Script/NeonParadigm_Game"),
		Z_CompiledInDeferFile_FID__JHernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_NP_ANS_SaveHeavyAttack_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID__JHernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_NP_ANS_SaveHeavyAttack_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
