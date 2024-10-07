// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NeonParadigm_Game/Components/AttackComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAttackComponent() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_ANeonParadigm_GameCharacter_NoRegister();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UAttackComponent();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UAttackComponent_NoRegister();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UCharacterStateComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_NeonParadigm_Game();
// End Cross Module References
	void UAttackComponent::StaticRegisterNativesUAttackComponent()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UAttackComponent);
	UClass* Z_Construct_UClass_UAttackComponent_NoRegister()
	{
		return UAttackComponent::StaticClass();
	}
	struct Z_Construct_UClass_UAttackComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MyCharacter_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MyCharacter;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bSaveLightAttack_MetaData[];
#endif
		static void NewProp_bSaveLightAttack_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bSaveLightAttack;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CharacterState_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CharacterState;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LightAttackMontages_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LightAttackMontages_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_LightAttackMontages;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_LightAttackImpactTimes_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LightAttackImpactTimes_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_LightAttackImpactTimes;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_HeavyAttackMontages_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HeavyAttackMontages_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_HeavyAttackMontages;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UAttackComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_NeonParadigm_Game,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAttackComponent_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAttackComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "Components/AttackComponent.h" },
		{ "ModuleRelativePath", "Components/AttackComponent.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAttackComponent_Statics::NewProp_MyCharacter_MetaData[] = {
		{ "Category", "AttackComponent" },
		{ "ModuleRelativePath", "Components/AttackComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UAttackComponent_Statics::NewProp_MyCharacter = { "MyCharacter", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAttackComponent, MyCharacter), Z_Construct_UClass_ANeonParadigm_GameCharacter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAttackComponent_Statics::NewProp_MyCharacter_MetaData), Z_Construct_UClass_UAttackComponent_Statics::NewProp_MyCharacter_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAttackComponent_Statics::NewProp_bSaveLightAttack_MetaData[] = {
		{ "ModuleRelativePath", "Components/AttackComponent.h" },
	};
#endif
	void Z_Construct_UClass_UAttackComponent_Statics::NewProp_bSaveLightAttack_SetBit(void* Obj)
	{
		((UAttackComponent*)Obj)->bSaveLightAttack = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UAttackComponent_Statics::NewProp_bSaveLightAttack = { "bSaveLightAttack", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UAttackComponent), &Z_Construct_UClass_UAttackComponent_Statics::NewProp_bSaveLightAttack_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAttackComponent_Statics::NewProp_bSaveLightAttack_MetaData), Z_Construct_UClass_UAttackComponent_Statics::NewProp_bSaveLightAttack_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAttackComponent_Statics::NewProp_CharacterState_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "State" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Components/AttackComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UAttackComponent_Statics::NewProp_CharacterState = { "CharacterState", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAttackComponent, CharacterState), Z_Construct_UClass_UCharacterStateComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAttackComponent_Statics::NewProp_CharacterState_MetaData), Z_Construct_UClass_UAttackComponent_Statics::NewProp_CharacterState_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UAttackComponent_Statics::NewProp_LightAttackMontages_Inner = { "LightAttackMontages", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAttackComponent_Statics::NewProp_LightAttackMontages_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Attack" },
		{ "ModuleRelativePath", "Components/AttackComponent.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UAttackComponent_Statics::NewProp_LightAttackMontages = { "LightAttackMontages", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAttackComponent, LightAttackMontages), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAttackComponent_Statics::NewProp_LightAttackMontages_MetaData), Z_Construct_UClass_UAttackComponent_Statics::NewProp_LightAttackMontages_MetaData) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UAttackComponent_Statics::NewProp_LightAttackImpactTimes_Inner = { "LightAttackImpactTimes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAttackComponent_Statics::NewProp_LightAttackImpactTimes_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Attack" },
		{ "ModuleRelativePath", "Components/AttackComponent.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UAttackComponent_Statics::NewProp_LightAttackImpactTimes = { "LightAttackImpactTimes", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAttackComponent, LightAttackImpactTimes), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAttackComponent_Statics::NewProp_LightAttackImpactTimes_MetaData), Z_Construct_UClass_UAttackComponent_Statics::NewProp_LightAttackImpactTimes_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UAttackComponent_Statics::NewProp_HeavyAttackMontages_Inner = { "HeavyAttackMontages", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAttackComponent_Statics::NewProp_HeavyAttackMontages_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Attack" },
		{ "ModuleRelativePath", "Components/AttackComponent.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UAttackComponent_Statics::NewProp_HeavyAttackMontages = { "HeavyAttackMontages", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAttackComponent, HeavyAttackMontages), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAttackComponent_Statics::NewProp_HeavyAttackMontages_MetaData), Z_Construct_UClass_UAttackComponent_Statics::NewProp_HeavyAttackMontages_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UAttackComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttackComponent_Statics::NewProp_MyCharacter,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttackComponent_Statics::NewProp_bSaveLightAttack,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttackComponent_Statics::NewProp_CharacterState,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttackComponent_Statics::NewProp_LightAttackMontages_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttackComponent_Statics::NewProp_LightAttackMontages,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttackComponent_Statics::NewProp_LightAttackImpactTimes_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttackComponent_Statics::NewProp_LightAttackImpactTimes,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttackComponent_Statics::NewProp_HeavyAttackMontages_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttackComponent_Statics::NewProp_HeavyAttackMontages,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UAttackComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAttackComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UAttackComponent_Statics::ClassParams = {
		&UAttackComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UAttackComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UAttackComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAttackComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UAttackComponent_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAttackComponent_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UAttackComponent()
	{
		if (!Z_Registration_Info_UClass_UAttackComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAttackComponent.OuterSingleton, Z_Construct_UClass_UAttackComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UAttackComponent.OuterSingleton;
	}
	template<> NEONPARADIGM_GAME_API UClass* StaticClass<UAttackComponent>()
	{
		return UAttackComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAttackComponent);
	UAttackComponent::~UAttackComponent() {}
	struct Z_CompiledInDeferFile_FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Components_AttackComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Components_AttackComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UAttackComponent, UAttackComponent::StaticClass, TEXT("UAttackComponent"), &Z_Registration_Info_UClass_UAttackComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAttackComponent), 2399745378U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Components_AttackComponent_h_792134799(TEXT("/Script/NeonParadigm_Game"),
		Z_CompiledInDeferFile_FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Components_AttackComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Components_AttackComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
