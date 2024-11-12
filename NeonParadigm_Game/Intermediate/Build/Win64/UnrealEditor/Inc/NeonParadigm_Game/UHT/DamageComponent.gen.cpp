// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NeonParadigm_Game/Components/DamageComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDamageComponent() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UParticleSystem_NoRegister();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UDamageComponent();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UDamageComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_NeonParadigm_Game();
// End Cross Module References
	void UDamageComponent::StaticRegisterNativesUDamageComponent()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDamageComponent);
	UClass* Z_Construct_UClass_UDamageComponent_NoRegister()
	{
		return UDamageComponent::StaticClass();
	}
	struct Z_Construct_UClass_UDamageComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HR_Right_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_HR_Right;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HR_Left_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_HR_Left;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HR_Middle_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_HR_Middle;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HR_Knockdown_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_HR_Knockdown;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HR_Knockback_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_HR_Knockback;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ImpactEffect_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ImpactEffect;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PerfectParticle_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PerfectParticle;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RagePickup_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_RagePickup;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDamageComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_NeonParadigm_Game,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDamageComponent_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDamageComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "Components/DamageComponent.h" },
		{ "ModuleRelativePath", "Components/DamageComponent.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDamageComponent_Statics::NewProp_HR_Right_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "HitReaction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*UPROPERTY(EditAnywhere, Category = \"Damage\")\n\x09TSubclassOf<class UNP_DamageType> DamageTypeClass;*/" },
#endif
		{ "ModuleRelativePath", "Components/DamageComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UPROPERTY(EditAnywhere, Category = \"Damage\")\n       TSubclassOf<class UNP_DamageType> DamageTypeClass;" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDamageComponent_Statics::NewProp_HR_Right = { "HR_Right", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDamageComponent, HR_Right), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDamageComponent_Statics::NewProp_HR_Right_MetaData), Z_Construct_UClass_UDamageComponent_Statics::NewProp_HR_Right_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDamageComponent_Statics::NewProp_HR_Left_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "HitReaction" },
		{ "ModuleRelativePath", "Components/DamageComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDamageComponent_Statics::NewProp_HR_Left = { "HR_Left", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDamageComponent, HR_Left), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDamageComponent_Statics::NewProp_HR_Left_MetaData), Z_Construct_UClass_UDamageComponent_Statics::NewProp_HR_Left_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDamageComponent_Statics::NewProp_HR_Middle_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "HitReaction" },
		{ "ModuleRelativePath", "Components/DamageComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDamageComponent_Statics::NewProp_HR_Middle = { "HR_Middle", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDamageComponent, HR_Middle), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDamageComponent_Statics::NewProp_HR_Middle_MetaData), Z_Construct_UClass_UDamageComponent_Statics::NewProp_HR_Middle_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDamageComponent_Statics::NewProp_HR_Knockdown_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "HitReaction" },
		{ "ModuleRelativePath", "Components/DamageComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDamageComponent_Statics::NewProp_HR_Knockdown = { "HR_Knockdown", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDamageComponent, HR_Knockdown), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDamageComponent_Statics::NewProp_HR_Knockdown_MetaData), Z_Construct_UClass_UDamageComponent_Statics::NewProp_HR_Knockdown_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDamageComponent_Statics::NewProp_HR_Knockback_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "HitReaction" },
		{ "ModuleRelativePath", "Components/DamageComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDamageComponent_Statics::NewProp_HR_Knockback = { "HR_Knockback", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDamageComponent, HR_Knockback), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDamageComponent_Statics::NewProp_HR_Knockback_MetaData), Z_Construct_UClass_UDamageComponent_Statics::NewProp_HR_Knockback_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDamageComponent_Statics::NewProp_ImpactEffect_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Effects" },
		{ "ModuleRelativePath", "Components/DamageComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDamageComponent_Statics::NewProp_ImpactEffect = { "ImpactEffect", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDamageComponent, ImpactEffect), Z_Construct_UClass_UParticleSystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDamageComponent_Statics::NewProp_ImpactEffect_MetaData), Z_Construct_UClass_UDamageComponent_Statics::NewProp_ImpactEffect_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDamageComponent_Statics::NewProp_PerfectParticle_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Effects" },
		{ "ModuleRelativePath", "Components/DamageComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDamageComponent_Statics::NewProp_PerfectParticle = { "PerfectParticle", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDamageComponent, PerfectParticle), Z_Construct_UClass_UParticleSystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDamageComponent_Statics::NewProp_PerfectParticle_MetaData), Z_Construct_UClass_UDamageComponent_Statics::NewProp_PerfectParticle_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDamageComponent_Statics::NewProp_RagePickup_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HitReaction, meta = (AllowPrivateAccess = \"true\"))\n//UAnimMontage* DeathMontage;\n" },
#endif
		{ "ModuleRelativePath", "Components/DamageComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HitReaction, meta = (AllowPrivateAccess = \"true\"))\nUAnimMontage* DeathMontage;" },
#endif
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UDamageComponent_Statics::NewProp_RagePickup = { "RagePickup", nullptr, (EPropertyFlags)0x0044000000010015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDamageComponent, RagePickup), Z_Construct_UClass_UClass, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDamageComponent_Statics::NewProp_RagePickup_MetaData), Z_Construct_UClass_UDamageComponent_Statics::NewProp_RagePickup_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDamageComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDamageComponent_Statics::NewProp_HR_Right,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDamageComponent_Statics::NewProp_HR_Left,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDamageComponent_Statics::NewProp_HR_Middle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDamageComponent_Statics::NewProp_HR_Knockdown,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDamageComponent_Statics::NewProp_HR_Knockback,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDamageComponent_Statics::NewProp_ImpactEffect,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDamageComponent_Statics::NewProp_PerfectParticle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDamageComponent_Statics::NewProp_RagePickup,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDamageComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDamageComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDamageComponent_Statics::ClassParams = {
		&UDamageComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UDamageComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UDamageComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDamageComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UDamageComponent_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDamageComponent_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UDamageComponent()
	{
		if (!Z_Registration_Info_UClass_UDamageComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDamageComponent.OuterSingleton, Z_Construct_UClass_UDamageComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDamageComponent.OuterSingleton;
	}
	template<> NEONPARADIGM_GAME_API UClass* StaticClass<UDamageComponent>()
	{
		return UDamageComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDamageComponent);
	UDamageComponent::~UDamageComponent() {}
	struct Z_CompiledInDeferFile_FID__Jhernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Components_DamageComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID__Jhernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Components_DamageComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDamageComponent, UDamageComponent::StaticClass, TEXT("UDamageComponent"), &Z_Registration_Info_UClass_UDamageComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDamageComponent), 1730914574U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID__Jhernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Components_DamageComponent_h_2187053025(TEXT("/Script/NeonParadigm_Game"),
		Z_CompiledInDeferFile_FID__Jhernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Components_DamageComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID__Jhernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Components_DamageComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
