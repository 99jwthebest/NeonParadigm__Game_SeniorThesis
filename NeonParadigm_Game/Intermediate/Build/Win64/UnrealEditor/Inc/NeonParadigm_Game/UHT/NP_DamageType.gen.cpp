// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NeonParadigm_Game/DamageType/NP_DamageType.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNP_DamageType() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UDamageType();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UNP_DamageType();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UNP_DamageType_NoRegister();
	NEONPARADIGM_GAME_API UEnum* Z_Construct_UEnum_NeonParadigm_Game_EDamageTypes();
	UPackage* Z_Construct_UPackage__Script_NeonParadigm_Game();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EDamageTypes;
	static UEnum* EDamageTypes_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EDamageTypes.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EDamageTypes.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_NeonParadigm_Game_EDamageTypes, (UObject*)Z_Construct_UPackage__Script_NeonParadigm_Game(), TEXT("EDamageTypes"));
		}
		return Z_Registration_Info_UEnum_EDamageTypes.OuterSingleton;
	}
	template<> NEONPARADIGM_GAME_API UEnum* StaticEnum<EDamageTypes>()
	{
		return EDamageTypes_StaticEnum();
	}
	struct Z_Construct_UEnum_NeonParadigm_Game_EDamageTypes_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_NeonParadigm_Game_EDamageTypes_Statics::Enumerators[] = {
		{ "EDamageTypes::Default", (int64)EDamageTypes::Default },
		{ "EDamageTypes::Right", (int64)EDamageTypes::Right },
		{ "EDamageTypes::Left", (int64)EDamageTypes::Left },
		{ "EDamageTypes::Middle", (int64)EDamageTypes::Middle },
		{ "EDamageTypes::Knockdown", (int64)EDamageTypes::Knockdown },
		{ "EDamageTypes::Knockback", (int64)EDamageTypes::Knockback },
		{ "EDamageTypes::Launch", (int64)EDamageTypes::Launch },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_NeonParadigm_Game_EDamageTypes_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "Default.Comment", "/**\n * \n */" },
		{ "Default.Name", "EDamageTypes::Default" },
		{ "Knockback.Comment", "//UMETA(DisplayName = \"Option 5\"),\n" },
		{ "Knockback.Name", "EDamageTypes::Knockback" },
		{ "Knockback.ToolTip", "UMETA(DisplayName = \"Option 5\")," },
		{ "Knockdown.Comment", "//UMETA(DisplayName = \"Option 4\"),\n" },
		{ "Knockdown.Name", "EDamageTypes::Knockdown" },
		{ "Knockdown.ToolTip", "UMETA(DisplayName = \"Option 4\")," },
		{ "Launch.Comment", "//UMETA(DisplayName = \"Option 5\"),\n" },
		{ "Launch.Name", "EDamageTypes::Launch" },
		{ "Launch.ToolTip", "UMETA(DisplayName = \"Option 5\")," },
		{ "Left.Comment", "//UMETA(DisplayName = \"Option 2\"),\n" },
		{ "Left.Name", "EDamageTypes::Left" },
		{ "Left.ToolTip", "UMETA(DisplayName = \"Option 2\")," },
		{ "Middle.Comment", "//UMETA(DisplayName = \"Option 3\"),\n" },
		{ "Middle.Name", "EDamageTypes::Middle" },
		{ "Middle.ToolTip", "UMETA(DisplayName = \"Option 3\")," },
		{ "ModuleRelativePath", "DamageType/NP_DamageType.h" },
		{ "Right.Comment", "/**\n * \n *///UMETA(DisplayName = \"Option 1\"),\n" },
		{ "Right.Name", "EDamageTypes::Right" },
		{ "Right.ToolTip", "//UMETA(DisplayName = \"Option 1\")," },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_NeonParadigm_Game_EDamageTypes_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_NeonParadigm_Game,
		nullptr,
		"EDamageTypes",
		"EDamageTypes",
		Z_Construct_UEnum_NeonParadigm_Game_EDamageTypes_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_NeonParadigm_Game_EDamageTypes_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_NeonParadigm_Game_EDamageTypes_Statics::Enum_MetaDataParams), Z_Construct_UEnum_NeonParadigm_Game_EDamageTypes_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_NeonParadigm_Game_EDamageTypes()
	{
		if (!Z_Registration_Info_UEnum_EDamageTypes.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EDamageTypes.InnerSingleton, Z_Construct_UEnum_NeonParadigm_Game_EDamageTypes_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EDamageTypes.InnerSingleton;
	}
	void UNP_DamageType::StaticRegisterNativesUNP_DamageType()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UNP_DamageType);
	UClass* Z_Construct_UClass_UNP_DamageType_NoRegister()
	{
		return UNP_DamageType::StaticClass();
	}
	struct Z_Construct_UClass_UNP_DamageType_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_DamageType_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DamageType_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_DamageType;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UNP_DamageType_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UDamageType,
		(UObject* (*)())Z_Construct_UPackage__Script_NeonParadigm_Game,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNP_DamageType_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNP_DamageType_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "DamageType/NP_DamageType.h" },
		{ "ModuleRelativePath", "DamageType/NP_DamageType.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UNP_DamageType_Statics::NewProp_DamageType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNP_DamageType_Statics::NewProp_DamageType_MetaData[] = {
		{ "Category", "DamageType" },
		{ "ModuleRelativePath", "DamageType/NP_DamageType.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UNP_DamageType_Statics::NewProp_DamageType = { "DamageType", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNP_DamageType, DamageType), Z_Construct_UEnum_NeonParadigm_Game_EDamageTypes, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNP_DamageType_Statics::NewProp_DamageType_MetaData), Z_Construct_UClass_UNP_DamageType_Statics::NewProp_DamageType_MetaData) }; // 3617866817
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UNP_DamageType_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNP_DamageType_Statics::NewProp_DamageType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNP_DamageType_Statics::NewProp_DamageType,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UNP_DamageType_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UNP_DamageType>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UNP_DamageType_Statics::ClassParams = {
		&UNP_DamageType::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UNP_DamageType_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UNP_DamageType_Statics::PropPointers),
		0,
		0x001100A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNP_DamageType_Statics::Class_MetaDataParams), Z_Construct_UClass_UNP_DamageType_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNP_DamageType_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UNP_DamageType()
	{
		if (!Z_Registration_Info_UClass_UNP_DamageType.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UNP_DamageType.OuterSingleton, Z_Construct_UClass_UNP_DamageType_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UNP_DamageType.OuterSingleton;
	}
	template<> NEONPARADIGM_GAME_API UClass* StaticClass<UNP_DamageType>()
	{
		return UNP_DamageType::StaticClass();
	}
	UNP_DamageType::UNP_DamageType(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UNP_DamageType);
	UNP_DamageType::~UNP_DamageType() {}
	struct Z_CompiledInDeferFile_FID_Angie_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_DamageType_NP_DamageType_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Angie_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_DamageType_NP_DamageType_h_Statics::EnumInfo[] = {
		{ EDamageTypes_StaticEnum, TEXT("EDamageTypes"), &Z_Registration_Info_UEnum_EDamageTypes, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3617866817U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Angie_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_DamageType_NP_DamageType_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UNP_DamageType, UNP_DamageType::StaticClass, TEXT("UNP_DamageType"), &Z_Registration_Info_UClass_UNP_DamageType, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UNP_DamageType), 2746216219U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Angie_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_DamageType_NP_DamageType_h_2425702023(TEXT("/Script/NeonParadigm_Game"),
		Z_CompiledInDeferFile_FID_Angie_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_DamageType_NP_DamageType_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Angie_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_DamageType_NP_DamageType_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Angie_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_DamageType_NP_DamageType_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Angie_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_DamageType_NP_DamageType_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
