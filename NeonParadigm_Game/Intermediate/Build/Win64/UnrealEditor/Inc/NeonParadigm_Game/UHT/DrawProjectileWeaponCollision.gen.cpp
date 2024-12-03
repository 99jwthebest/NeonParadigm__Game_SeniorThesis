// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NeonParadigm_Game/AnimNotify/DrawProjectileWeaponCollision.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDrawProjectileWeaponCollision() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_UAnimNotify();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UDrawProjectileWeaponCollision();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UDrawProjectileWeaponCollision_NoRegister();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UNP_DamageType_NoRegister();
	UPackage* Z_Construct_UPackage__Script_NeonParadigm_Game();
// End Cross Module References
	void UDrawProjectileWeaponCollision::StaticRegisterNativesUDrawProjectileWeaponCollision()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDrawProjectileWeaponCollision);
	UClass* Z_Construct_UClass_UDrawProjectileWeaponCollision_NoRegister()
	{
		return UDrawProjectileWeaponCollision::StaticClass();
	}
	struct Z_Construct_UClass_UDrawProjectileWeaponCollision_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Radius_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Radius;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AmountOfDamage_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_AmountOfDamage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DamageTypeClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_DamageTypeClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RageDamageMultiplier_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_RageDamageMultiplier;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDrawProjectileWeaponCollision_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimNotify,
		(UObject* (*)())Z_Construct_UPackage__Script_NeonParadigm_Game,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDrawProjectileWeaponCollision_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDrawProjectileWeaponCollision_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Object" },
		{ "IncludePath", "AnimNotify/DrawProjectileWeaponCollision.h" },
		{ "ModuleRelativePath", "AnimNotify/DrawProjectileWeaponCollision.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDrawProjectileWeaponCollision_Statics::NewProp_Radius_MetaData[] = {
		{ "Category", "Damage" },
		{ "ModuleRelativePath", "AnimNotify/DrawProjectileWeaponCollision.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDrawProjectileWeaponCollision_Statics::NewProp_Radius = { "Radius", nullptr, (EPropertyFlags)0x0040000000000011, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDrawProjectileWeaponCollision, Radius), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDrawProjectileWeaponCollision_Statics::NewProp_Radius_MetaData), Z_Construct_UClass_UDrawProjectileWeaponCollision_Statics::NewProp_Radius_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDrawProjectileWeaponCollision_Statics::NewProp_AmountOfDamage_MetaData[] = {
		{ "Category", "Damage" },
		{ "ModuleRelativePath", "AnimNotify/DrawProjectileWeaponCollision.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDrawProjectileWeaponCollision_Statics::NewProp_AmountOfDamage = { "AmountOfDamage", nullptr, (EPropertyFlags)0x0040000000000011, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDrawProjectileWeaponCollision, AmountOfDamage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDrawProjectileWeaponCollision_Statics::NewProp_AmountOfDamage_MetaData), Z_Construct_UClass_UDrawProjectileWeaponCollision_Statics::NewProp_AmountOfDamage_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDrawProjectileWeaponCollision_Statics::NewProp_DamageTypeClass_MetaData[] = {
		{ "Category", "Damage" },
		{ "ModuleRelativePath", "AnimNotify/DrawProjectileWeaponCollision.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UDrawProjectileWeaponCollision_Statics::NewProp_DamageTypeClass = { "DamageTypeClass", nullptr, (EPropertyFlags)0x0044000000000011, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDrawProjectileWeaponCollision, DamageTypeClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UNP_DamageType_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDrawProjectileWeaponCollision_Statics::NewProp_DamageTypeClass_MetaData), Z_Construct_UClass_UDrawProjectileWeaponCollision_Statics::NewProp_DamageTypeClass_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDrawProjectileWeaponCollision_Statics::NewProp_RageDamageMultiplier_MetaData[] = {
		{ "Category", "Damage" },
		{ "ModuleRelativePath", "AnimNotify/DrawProjectileWeaponCollision.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDrawProjectileWeaponCollision_Statics::NewProp_RageDamageMultiplier = { "RageDamageMultiplier", nullptr, (EPropertyFlags)0x0040000000000011, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDrawProjectileWeaponCollision, RageDamageMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDrawProjectileWeaponCollision_Statics::NewProp_RageDamageMultiplier_MetaData), Z_Construct_UClass_UDrawProjectileWeaponCollision_Statics::NewProp_RageDamageMultiplier_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDrawProjectileWeaponCollision_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDrawProjectileWeaponCollision_Statics::NewProp_Radius,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDrawProjectileWeaponCollision_Statics::NewProp_AmountOfDamage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDrawProjectileWeaponCollision_Statics::NewProp_DamageTypeClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDrawProjectileWeaponCollision_Statics::NewProp_RageDamageMultiplier,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDrawProjectileWeaponCollision_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDrawProjectileWeaponCollision>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDrawProjectileWeaponCollision_Statics::ClassParams = {
		&UDrawProjectileWeaponCollision::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UDrawProjectileWeaponCollision_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UDrawProjectileWeaponCollision_Statics::PropPointers),
		0,
		0x001120A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDrawProjectileWeaponCollision_Statics::Class_MetaDataParams), Z_Construct_UClass_UDrawProjectileWeaponCollision_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDrawProjectileWeaponCollision_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UDrawProjectileWeaponCollision()
	{
		if (!Z_Registration_Info_UClass_UDrawProjectileWeaponCollision.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDrawProjectileWeaponCollision.OuterSingleton, Z_Construct_UClass_UDrawProjectileWeaponCollision_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDrawProjectileWeaponCollision.OuterSingleton;
	}
	template<> NEONPARADIGM_GAME_API UClass* StaticClass<UDrawProjectileWeaponCollision>()
	{
		return UDrawProjectileWeaponCollision::StaticClass();
	}
	UDrawProjectileWeaponCollision::UDrawProjectileWeaponCollision(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDrawProjectileWeaponCollision);
	UDrawProjectileWeaponCollision::~UDrawProjectileWeaponCollision() {}
	struct Z_CompiledInDeferFile_FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_DrawProjectileWeaponCollision_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_DrawProjectileWeaponCollision_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDrawProjectileWeaponCollision, UDrawProjectileWeaponCollision::StaticClass, TEXT("UDrawProjectileWeaponCollision"), &Z_Registration_Info_UClass_UDrawProjectileWeaponCollision, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDrawProjectileWeaponCollision), 169402074U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_DrawProjectileWeaponCollision_h_27762444(TEXT("/Script/NeonParadigm_Game"),
		Z_CompiledInDeferFile_FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_DrawProjectileWeaponCollision_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_DrawProjectileWeaponCollision_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
