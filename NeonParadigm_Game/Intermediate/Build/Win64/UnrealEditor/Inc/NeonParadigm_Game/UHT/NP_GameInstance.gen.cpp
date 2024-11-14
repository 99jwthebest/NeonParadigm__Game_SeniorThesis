// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NeonParadigm_Game/Framework/NP_GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNP_GameInstance() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_ANP_BaseEnemy_NoRegister();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UNP_GameInstance();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UNP_GameInstance_NoRegister();
	UPackage* Z_Construct_UPackage__Script_NeonParadigm_Game();
// End Cross Module References
	DEFINE_FUNCTION(UNP_GameInstance::execAddSpawnedEnemy)
	{
		P_GET_OBJECT(ANP_BaseEnemy,Z_Param_SpawnedEnemy);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddSpawnedEnemy(Z_Param_SpawnedEnemy);
		P_NATIVE_END;
	}
	void UNP_GameInstance::StaticRegisterNativesUNP_GameInstance()
	{
		UClass* Class = UNP_GameInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddSpawnedEnemy", &UNP_GameInstance::execAddSpawnedEnemy },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UNP_GameInstance_AddSpawnedEnemy_Statics
	{
		struct NP_GameInstance_eventAddSpawnedEnemy_Parms
		{
			ANP_BaseEnemy* SpawnedEnemy;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SpawnedEnemy;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UNP_GameInstance_AddSpawnedEnemy_Statics::NewProp_SpawnedEnemy = { "SpawnedEnemy", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NP_GameInstance_eventAddSpawnedEnemy_Parms, SpawnedEnemy), Z_Construct_UClass_ANP_BaseEnemy_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UNP_GameInstance_AddSpawnedEnemy_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UNP_GameInstance_AddSpawnedEnemy_Statics::NewProp_SpawnedEnemy,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UNP_GameInstance_AddSpawnedEnemy_Statics::Function_MetaDataParams[] = {
		{ "Category", "Music" },
		{ "ModuleRelativePath", "Framework/NP_GameInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UNP_GameInstance_AddSpawnedEnemy_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UNP_GameInstance, nullptr, "AddSpawnedEnemy", nullptr, nullptr, Z_Construct_UFunction_UNP_GameInstance_AddSpawnedEnemy_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UNP_GameInstance_AddSpawnedEnemy_Statics::PropPointers), sizeof(Z_Construct_UFunction_UNP_GameInstance_AddSpawnedEnemy_Statics::NP_GameInstance_eventAddSpawnedEnemy_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UNP_GameInstance_AddSpawnedEnemy_Statics::Function_MetaDataParams), Z_Construct_UFunction_UNP_GameInstance_AddSpawnedEnemy_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UNP_GameInstance_AddSpawnedEnemy_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UNP_GameInstance_AddSpawnedEnemy_Statics::NP_GameInstance_eventAddSpawnedEnemy_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UNP_GameInstance_AddSpawnedEnemy()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UNP_GameInstance_AddSpawnedEnemy_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UNP_GameInstance);
	UClass* Z_Construct_UClass_UNP_GameInstance_NoRegister()
	{
		return UNP_GameInstance::StaticClass();
	}
	struct Z_Construct_UClass_UNP_GameInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UNP_GameInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_NeonParadigm_Game,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNP_GameInstance_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UNP_GameInstance_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UNP_GameInstance_AddSpawnedEnemy, "AddSpawnedEnemy" }, // 675475899
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNP_GameInstance_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNP_GameInstance_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Framework/NP_GameInstance.h" },
		{ "ModuleRelativePath", "Framework/NP_GameInstance.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UNP_GameInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UNP_GameInstance>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UNP_GameInstance_Statics::ClassParams = {
		&UNP_GameInstance::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x009000A8u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNP_GameInstance_Statics::Class_MetaDataParams), Z_Construct_UClass_UNP_GameInstance_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UNP_GameInstance()
	{
		if (!Z_Registration_Info_UClass_UNP_GameInstance.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UNP_GameInstance.OuterSingleton, Z_Construct_UClass_UNP_GameInstance_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UNP_GameInstance.OuterSingleton;
	}
	template<> NEONPARADIGM_GAME_API UClass* StaticClass<UNP_GameInstance>()
	{
		return UNP_GameInstance::StaticClass();
	}
	UNP_GameInstance::UNP_GameInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UNP_GameInstance);
	UNP_GameInstance::~UNP_GameInstance() {}
	struct Z_CompiledInDeferFile_FID_NeonParadigm_Game_Source_NeonParadigm_Game_Framework_NP_GameInstance_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_NeonParadigm_Game_Source_NeonParadigm_Game_Framework_NP_GameInstance_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UNP_GameInstance, UNP_GameInstance::StaticClass, TEXT("UNP_GameInstance"), &Z_Registration_Info_UClass_UNP_GameInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UNP_GameInstance), 2246988493U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_NeonParadigm_Game_Source_NeonParadigm_Game_Framework_NP_GameInstance_h_3775466322(TEXT("/Script/NeonParadigm_Game"),
		Z_CompiledInDeferFile_FID_NeonParadigm_Game_Source_NeonParadigm_Game_Framework_NP_GameInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_NeonParadigm_Game_Source_NeonParadigm_Game_Framework_NP_GameInstance_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
