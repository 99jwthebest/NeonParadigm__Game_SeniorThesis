// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NeonParadigm_Game/Projectile/NP_Projectile.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNP_Projectile() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_UProjectileMovementComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_ANP_Projectile();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_ANP_Projectile_NoRegister();
	UPackage* Z_Construct_UPackage__Script_NeonParadigm_Game();
// End Cross Module References
	void ANP_Projectile::StaticRegisterNativesANP_Projectile()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ANP_Projectile);
	UClass* Z_Construct_UClass_ANP_Projectile_NoRegister()
	{
		return ANP_Projectile::StaticClass();
	}
	struct Z_Construct_UClass_ANP_Projectile_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CollisionSphere_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CollisionSphere;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ProjectileMovement_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ProjectileMovement;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StartingVelocity_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_StartingVelocity;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ANP_Projectile_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_NeonParadigm_Game,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANP_Projectile_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANP_Projectile_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Projectile/NP_Projectile.h" },
		{ "ModuleRelativePath", "Projectile/NP_Projectile.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANP_Projectile_Statics::NewProp_CollisionSphere_MetaData[] = {
		{ "Category", "Projectile" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Projectile/NP_Projectile.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANP_Projectile_Statics::NewProp_CollisionSphere = { "CollisionSphere", nullptr, (EPropertyFlags)0x0040000000090009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANP_Projectile, CollisionSphere), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANP_Projectile_Statics::NewProp_CollisionSphere_MetaData), Z_Construct_UClass_ANP_Projectile_Statics::NewProp_CollisionSphere_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANP_Projectile_Statics::NewProp_ProjectileMovement_MetaData[] = {
		{ "Category", "Projectile" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Projectile/NP_Projectile.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANP_Projectile_Statics::NewProp_ProjectileMovement = { "ProjectileMovement", nullptr, (EPropertyFlags)0x0040000000090009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANP_Projectile, ProjectileMovement), Z_Construct_UClass_UProjectileMovementComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANP_Projectile_Statics::NewProp_ProjectileMovement_MetaData), Z_Construct_UClass_ANP_Projectile_Statics::NewProp_ProjectileMovement_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANP_Projectile_Statics::NewProp_StartingVelocity_MetaData[] = {
		{ "Category", "Projectile" },
		{ "ModuleRelativePath", "Projectile/NP_Projectile.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ANP_Projectile_Statics::NewProp_StartingVelocity = { "StartingVelocity", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANP_Projectile, StartingVelocity), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANP_Projectile_Statics::NewProp_StartingVelocity_MetaData), Z_Construct_UClass_ANP_Projectile_Statics::NewProp_StartingVelocity_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ANP_Projectile_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANP_Projectile_Statics::NewProp_CollisionSphere,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANP_Projectile_Statics::NewProp_ProjectileMovement,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANP_Projectile_Statics::NewProp_StartingVelocity,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ANP_Projectile_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANP_Projectile>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ANP_Projectile_Statics::ClassParams = {
		&ANP_Projectile::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ANP_Projectile_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ANP_Projectile_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANP_Projectile_Statics::Class_MetaDataParams), Z_Construct_UClass_ANP_Projectile_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANP_Projectile_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ANP_Projectile()
	{
		if (!Z_Registration_Info_UClass_ANP_Projectile.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ANP_Projectile.OuterSingleton, Z_Construct_UClass_ANP_Projectile_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ANP_Projectile.OuterSingleton;
	}
	template<> NEONPARADIGM_GAME_API UClass* StaticClass<ANP_Projectile>()
	{
		return ANP_Projectile::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANP_Projectile);
	ANP_Projectile::~ANP_Projectile() {}
	struct Z_CompiledInDeferFile_FID_Users_drake_Documents_GitHub_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Projectile_NP_Projectile_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_drake_Documents_GitHub_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Projectile_NP_Projectile_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ANP_Projectile, ANP_Projectile::StaticClass, TEXT("ANP_Projectile"), &Z_Registration_Info_UClass_ANP_Projectile, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ANP_Projectile), 3741959176U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_drake_Documents_GitHub_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Projectile_NP_Projectile_h_243867062(TEXT("/Script/NeonParadigm_Game"),
		Z_CompiledInDeferFile_FID_Users_drake_Documents_GitHub_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Projectile_NP_Projectile_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_drake_Documents_GitHub_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Projectile_NP_Projectile_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
