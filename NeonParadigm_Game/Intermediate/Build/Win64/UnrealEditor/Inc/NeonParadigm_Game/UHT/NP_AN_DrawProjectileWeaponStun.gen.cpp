// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NeonParadigm_Game/AnimNotify/NP_AN_DrawProjectileWeaponStun.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNP_AN_DrawProjectileWeaponStun() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_UAnimNotify();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UNP_AN_DrawProjectileWeaponStun();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UNP_AN_DrawProjectileWeaponStun_NoRegister();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UNP_DamageType_NoRegister();
	UPackage* Z_Construct_UPackage__Script_NeonParadigm_Game();
// End Cross Module References
	void UNP_AN_DrawProjectileWeaponStun::StaticRegisterNativesUNP_AN_DrawProjectileWeaponStun()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UNP_AN_DrawProjectileWeaponStun);
	UClass* Z_Construct_UClass_UNP_AN_DrawProjectileWeaponStun_NoRegister()
	{
		return UNP_AN_DrawProjectileWeaponStun::StaticClass();
	}
	struct Z_Construct_UClass_UNP_AN_DrawProjectileWeaponStun_Statics
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
	UObject* (*const Z_Construct_UClass_UNP_AN_DrawProjectileWeaponStun_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimNotify,
		(UObject* (*)())Z_Construct_UPackage__Script_NeonParadigm_Game,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNP_AN_DrawProjectileWeaponStun_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNP_AN_DrawProjectileWeaponStun_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Object" },
		{ "IncludePath", "AnimNotify/NP_AN_DrawProjectileWeaponStun.h" },
		{ "ModuleRelativePath", "AnimNotify/NP_AN_DrawProjectileWeaponStun.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNP_AN_DrawProjectileWeaponStun_Statics::NewProp_Radius_MetaData[] = {
		{ "Category", "Damage" },
		{ "ModuleRelativePath", "AnimNotify/NP_AN_DrawProjectileWeaponStun.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UNP_AN_DrawProjectileWeaponStun_Statics::NewProp_Radius = { "Radius", nullptr, (EPropertyFlags)0x0040000000000011, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNP_AN_DrawProjectileWeaponStun, Radius), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNP_AN_DrawProjectileWeaponStun_Statics::NewProp_Radius_MetaData), Z_Construct_UClass_UNP_AN_DrawProjectileWeaponStun_Statics::NewProp_Radius_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNP_AN_DrawProjectileWeaponStun_Statics::NewProp_AmountOfDamage_MetaData[] = {
		{ "Category", "Damage" },
		{ "ModuleRelativePath", "AnimNotify/NP_AN_DrawProjectileWeaponStun.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UNP_AN_DrawProjectileWeaponStun_Statics::NewProp_AmountOfDamage = { "AmountOfDamage", nullptr, (EPropertyFlags)0x0040000000000011, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNP_AN_DrawProjectileWeaponStun, AmountOfDamage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNP_AN_DrawProjectileWeaponStun_Statics::NewProp_AmountOfDamage_MetaData), Z_Construct_UClass_UNP_AN_DrawProjectileWeaponStun_Statics::NewProp_AmountOfDamage_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNP_AN_DrawProjectileWeaponStun_Statics::NewProp_DamageTypeClass_MetaData[] = {
		{ "Category", "Damage" },
		{ "ModuleRelativePath", "AnimNotify/NP_AN_DrawProjectileWeaponStun.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UNP_AN_DrawProjectileWeaponStun_Statics::NewProp_DamageTypeClass = { "DamageTypeClass", nullptr, (EPropertyFlags)0x0044000000000011, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNP_AN_DrawProjectileWeaponStun, DamageTypeClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UNP_DamageType_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNP_AN_DrawProjectileWeaponStun_Statics::NewProp_DamageTypeClass_MetaData), Z_Construct_UClass_UNP_AN_DrawProjectileWeaponStun_Statics::NewProp_DamageTypeClass_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNP_AN_DrawProjectileWeaponStun_Statics::NewProp_RageDamageMultiplier_MetaData[] = {
		{ "Category", "Damage" },
		{ "ModuleRelativePath", "AnimNotify/NP_AN_DrawProjectileWeaponStun.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UNP_AN_DrawProjectileWeaponStun_Statics::NewProp_RageDamageMultiplier = { "RageDamageMultiplier", nullptr, (EPropertyFlags)0x0040000000000011, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNP_AN_DrawProjectileWeaponStun, RageDamageMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNP_AN_DrawProjectileWeaponStun_Statics::NewProp_RageDamageMultiplier_MetaData), Z_Construct_UClass_UNP_AN_DrawProjectileWeaponStun_Statics::NewProp_RageDamageMultiplier_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UNP_AN_DrawProjectileWeaponStun_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNP_AN_DrawProjectileWeaponStun_Statics::NewProp_Radius,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNP_AN_DrawProjectileWeaponStun_Statics::NewProp_AmountOfDamage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNP_AN_DrawProjectileWeaponStun_Statics::NewProp_DamageTypeClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNP_AN_DrawProjectileWeaponStun_Statics::NewProp_RageDamageMultiplier,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UNP_AN_DrawProjectileWeaponStun_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UNP_AN_DrawProjectileWeaponStun>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UNP_AN_DrawProjectileWeaponStun_Statics::ClassParams = {
		&UNP_AN_DrawProjectileWeaponStun::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UNP_AN_DrawProjectileWeaponStun_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UNP_AN_DrawProjectileWeaponStun_Statics::PropPointers),
		0,
		0x001120A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNP_AN_DrawProjectileWeaponStun_Statics::Class_MetaDataParams), Z_Construct_UClass_UNP_AN_DrawProjectileWeaponStun_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNP_AN_DrawProjectileWeaponStun_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UNP_AN_DrawProjectileWeaponStun()
	{
		if (!Z_Registration_Info_UClass_UNP_AN_DrawProjectileWeaponStun.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UNP_AN_DrawProjectileWeaponStun.OuterSingleton, Z_Construct_UClass_UNP_AN_DrawProjectileWeaponStun_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UNP_AN_DrawProjectileWeaponStun.OuterSingleton;
	}
	template<> NEONPARADIGM_GAME_API UClass* StaticClass<UNP_AN_DrawProjectileWeaponStun>()
	{
		return UNP_AN_DrawProjectileWeaponStun::StaticClass();
	}
	UNP_AN_DrawProjectileWeaponStun::UNP_AN_DrawProjectileWeaponStun(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UNP_AN_DrawProjectileWeaponStun);
	UNP_AN_DrawProjectileWeaponStun::~UNP_AN_DrawProjectileWeaponStun() {}
	struct Z_CompiledInDeferFile_FID__J_Hernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_NP_AN_DrawProjectileWeaponStun_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID__J_Hernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_NP_AN_DrawProjectileWeaponStun_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UNP_AN_DrawProjectileWeaponStun, UNP_AN_DrawProjectileWeaponStun::StaticClass, TEXT("UNP_AN_DrawProjectileWeaponStun"), &Z_Registration_Info_UClass_UNP_AN_DrawProjectileWeaponStun, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UNP_AN_DrawProjectileWeaponStun), 173137165U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID__J_Hernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_NP_AN_DrawProjectileWeaponStun_h_3676814983(TEXT("/Script/NeonParadigm_Game"),
		Z_CompiledInDeferFile_FID__J_Hernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_NP_AN_DrawProjectileWeaponStun_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID__J_Hernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_NP_AN_DrawProjectileWeaponStun_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
