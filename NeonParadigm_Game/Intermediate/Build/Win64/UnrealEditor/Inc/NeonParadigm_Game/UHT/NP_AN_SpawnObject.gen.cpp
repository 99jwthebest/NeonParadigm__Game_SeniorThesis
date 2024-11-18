// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NeonParadigm_Game/AnimNotify/NP_AN_SpawnObject.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNP_AN_SpawnObject() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UAnimNotify();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UNP_AN_SpawnObject();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UNP_AN_SpawnObject_NoRegister();
	UPackage* Z_Construct_UPackage__Script_NeonParadigm_Game();
// End Cross Module References
	void UNP_AN_SpawnObject::StaticRegisterNativesUNP_AN_SpawnObject()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UNP_AN_SpawnObject);
	UClass* Z_Construct_UClass_UNP_AN_SpawnObject_NoRegister()
	{
		return UNP_AN_SpawnObject::StaticClass();
	}
	struct Z_Construct_UClass_UNP_AN_SpawnObject_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ObjectClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_ObjectClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SpawnPoint_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_SpawnPoint;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UNP_AN_SpawnObject_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimNotify,
		(UObject* (*)())Z_Construct_UPackage__Script_NeonParadigm_Game,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNP_AN_SpawnObject_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNP_AN_SpawnObject_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Object" },
		{ "IncludePath", "AnimNotify/NP_AN_SpawnObject.h" },
		{ "ModuleRelativePath", "AnimNotify/NP_AN_SpawnObject.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNP_AN_SpawnObject_Statics::NewProp_ObjectClass_MetaData[] = {
		{ "Category", "Spawn" },
		{ "ModuleRelativePath", "AnimNotify/NP_AN_SpawnObject.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UNP_AN_SpawnObject_Statics::NewProp_ObjectClass = { "ObjectClass", nullptr, (EPropertyFlags)0x0044000000000011, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNP_AN_SpawnObject, ObjectClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNP_AN_SpawnObject_Statics::NewProp_ObjectClass_MetaData), Z_Construct_UClass_UNP_AN_SpawnObject_Statics::NewProp_ObjectClass_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNP_AN_SpawnObject_Statics::NewProp_SpawnPoint_MetaData[] = {
		{ "Category", "Spawn" },
		{ "ModuleRelativePath", "AnimNotify/NP_AN_SpawnObject.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UNP_AN_SpawnObject_Statics::NewProp_SpawnPoint = { "SpawnPoint", nullptr, (EPropertyFlags)0x0040000000000011, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNP_AN_SpawnObject, SpawnPoint), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNP_AN_SpawnObject_Statics::NewProp_SpawnPoint_MetaData), Z_Construct_UClass_UNP_AN_SpawnObject_Statics::NewProp_SpawnPoint_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UNP_AN_SpawnObject_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNP_AN_SpawnObject_Statics::NewProp_ObjectClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNP_AN_SpawnObject_Statics::NewProp_SpawnPoint,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UNP_AN_SpawnObject_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UNP_AN_SpawnObject>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UNP_AN_SpawnObject_Statics::ClassParams = {
		&UNP_AN_SpawnObject::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UNP_AN_SpawnObject_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UNP_AN_SpawnObject_Statics::PropPointers),
		0,
		0x001120A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNP_AN_SpawnObject_Statics::Class_MetaDataParams), Z_Construct_UClass_UNP_AN_SpawnObject_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNP_AN_SpawnObject_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UNP_AN_SpawnObject()
	{
		if (!Z_Registration_Info_UClass_UNP_AN_SpawnObject.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UNP_AN_SpawnObject.OuterSingleton, Z_Construct_UClass_UNP_AN_SpawnObject_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UNP_AN_SpawnObject.OuterSingleton;
	}
	template<> NEONPARADIGM_GAME_API UClass* StaticClass<UNP_AN_SpawnObject>()
	{
		return UNP_AN_SpawnObject::StaticClass();
	}
	UNP_AN_SpawnObject::UNP_AN_SpawnObject(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UNP_AN_SpawnObject);
	UNP_AN_SpawnObject::~UNP_AN_SpawnObject() {}
	struct Z_CompiledInDeferFile_FID_Users_drake_Documents_GitHub_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_NP_AN_SpawnObject_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_drake_Documents_GitHub_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_NP_AN_SpawnObject_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UNP_AN_SpawnObject, UNP_AN_SpawnObject::StaticClass, TEXT("UNP_AN_SpawnObject"), &Z_Registration_Info_UClass_UNP_AN_SpawnObject, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UNP_AN_SpawnObject), 2140623283U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_drake_Documents_GitHub_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_NP_AN_SpawnObject_h_3395846000(TEXT("/Script/NeonParadigm_Game"),
		Z_CompiledInDeferFile_FID_Users_drake_Documents_GitHub_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_NP_AN_SpawnObject_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_drake_Documents_GitHub_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_AnimNotify_NP_AN_SpawnObject_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
