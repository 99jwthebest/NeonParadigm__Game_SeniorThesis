// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NeonParadigm_Game/Enemies/NP_EnemySpawner.h"
#include "../../Source/Runtime/Engine/Classes/Engine/HitResult.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNP_EnemySpawner() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_ANP_EnemySpawner();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_ANP_EnemySpawner_NoRegister();
	UPackage* Z_Construct_UPackage__Script_NeonParadigm_Game();
// End Cross Module References
	DEFINE_FUNCTION(ANP_EnemySpawner::execOnBoxOverlapBegin)
	{
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent);
		P_GET_OBJECT(AActor,Z_Param_OtherActor);
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp);
		P_GET_PROPERTY(FIntProperty,Z_Param_OtherBodyIndex);
		P_GET_UBOOL(Z_Param_bFromSweep);
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnBoxOverlapBegin(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult);
		P_NATIVE_END;
	}
	void ANP_EnemySpawner::StaticRegisterNativesANP_EnemySpawner()
	{
		UClass* Class = ANP_EnemySpawner::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnBoxOverlapBegin", &ANP_EnemySpawner::execOnBoxOverlapBegin },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ANP_EnemySpawner_OnBoxOverlapBegin_Statics
	{
		struct NP_EnemySpawner_eventOnBoxOverlapBegin_Parms
		{
			UPrimitiveComponent* OverlappedComponent;
			AActor* OtherActor;
			UPrimitiveComponent* OtherComp;
			int32 OtherBodyIndex;
			bool bFromSweep;
			FHitResult SweepResult;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OverlappedComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OverlappedComponent;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherComp;
		static const UECodeGen_Private::FIntPropertyParams NewProp_OtherBodyIndex;
		static void NewProp_bFromSweep_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bFromSweep;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SweepResult_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_SweepResult;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANP_EnemySpawner_OnBoxOverlapBegin_Statics::NewProp_OverlappedComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ANP_EnemySpawner_OnBoxOverlapBegin_Statics::NewProp_OverlappedComponent = { "OverlappedComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NP_EnemySpawner_eventOnBoxOverlapBegin_Parms, OverlappedComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_EnemySpawner_OnBoxOverlapBegin_Statics::NewProp_OverlappedComponent_MetaData), Z_Construct_UFunction_ANP_EnemySpawner_OnBoxOverlapBegin_Statics::NewProp_OverlappedComponent_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ANP_EnemySpawner_OnBoxOverlapBegin_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NP_EnemySpawner_eventOnBoxOverlapBegin_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANP_EnemySpawner_OnBoxOverlapBegin_Statics::NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ANP_EnemySpawner_OnBoxOverlapBegin_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NP_EnemySpawner_eventOnBoxOverlapBegin_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_EnemySpawner_OnBoxOverlapBegin_Statics::NewProp_OtherComp_MetaData), Z_Construct_UFunction_ANP_EnemySpawner_OnBoxOverlapBegin_Statics::NewProp_OtherComp_MetaData) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ANP_EnemySpawner_OnBoxOverlapBegin_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NP_EnemySpawner_eventOnBoxOverlapBegin_Parms, OtherBodyIndex), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_ANP_EnemySpawner_OnBoxOverlapBegin_Statics::NewProp_bFromSweep_SetBit(void* Obj)
	{
		((NP_EnemySpawner_eventOnBoxOverlapBegin_Parms*)Obj)->bFromSweep = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ANP_EnemySpawner_OnBoxOverlapBegin_Statics::NewProp_bFromSweep = { "bFromSweep", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(NP_EnemySpawner_eventOnBoxOverlapBegin_Parms), &Z_Construct_UFunction_ANP_EnemySpawner_OnBoxOverlapBegin_Statics::NewProp_bFromSweep_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANP_EnemySpawner_OnBoxOverlapBegin_Statics::NewProp_SweepResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ANP_EnemySpawner_OnBoxOverlapBegin_Statics::NewProp_SweepResult = { "SweepResult", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NP_EnemySpawner_eventOnBoxOverlapBegin_Parms, SweepResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_EnemySpawner_OnBoxOverlapBegin_Statics::NewProp_SweepResult_MetaData), Z_Construct_UFunction_ANP_EnemySpawner_OnBoxOverlapBegin_Statics::NewProp_SweepResult_MetaData) }; // 1891709922
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANP_EnemySpawner_OnBoxOverlapBegin_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANP_EnemySpawner_OnBoxOverlapBegin_Statics::NewProp_OverlappedComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANP_EnemySpawner_OnBoxOverlapBegin_Statics::NewProp_OtherActor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANP_EnemySpawner_OnBoxOverlapBegin_Statics::NewProp_OtherComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANP_EnemySpawner_OnBoxOverlapBegin_Statics::NewProp_OtherBodyIndex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANP_EnemySpawner_OnBoxOverlapBegin_Statics::NewProp_bFromSweep,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANP_EnemySpawner_OnBoxOverlapBegin_Statics::NewProp_SweepResult,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANP_EnemySpawner_OnBoxOverlapBegin_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Enemies/NP_EnemySpawner.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANP_EnemySpawner_OnBoxOverlapBegin_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANP_EnemySpawner, nullptr, "OnBoxOverlapBegin", nullptr, nullptr, Z_Construct_UFunction_ANP_EnemySpawner_OnBoxOverlapBegin_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_EnemySpawner_OnBoxOverlapBegin_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANP_EnemySpawner_OnBoxOverlapBegin_Statics::NP_EnemySpawner_eventOnBoxOverlapBegin_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00440401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_EnemySpawner_OnBoxOverlapBegin_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANP_EnemySpawner_OnBoxOverlapBegin_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_EnemySpawner_OnBoxOverlapBegin_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ANP_EnemySpawner_OnBoxOverlapBegin_Statics::NP_EnemySpawner_eventOnBoxOverlapBegin_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANP_EnemySpawner_OnBoxOverlapBegin()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANP_EnemySpawner_OnBoxOverlapBegin_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ANP_EnemySpawner);
	UClass* Z_Construct_UClass_ANP_EnemySpawner_NoRegister()
	{
		return ANP_EnemySpawner::StaticClass();
	}
	struct Z_Construct_UClass_ANP_EnemySpawner_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EnemySpawnBoxCollision_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_EnemySpawnBoxCollision;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ANP_EnemySpawner_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_NeonParadigm_Game,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANP_EnemySpawner_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_ANP_EnemySpawner_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ANP_EnemySpawner_OnBoxOverlapBegin, "OnBoxOverlapBegin" }, // 3209410405
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANP_EnemySpawner_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANP_EnemySpawner_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Enemies/NP_EnemySpawner.h" },
		{ "ModuleRelativePath", "Enemies/NP_EnemySpawner.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANP_EnemySpawner_Statics::NewProp_EnemySpawnBoxCollision_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Collision" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Enemies/NP_EnemySpawner.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANP_EnemySpawner_Statics::NewProp_EnemySpawnBoxCollision = { "EnemySpawnBoxCollision", nullptr, (EPropertyFlags)0x004000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANP_EnemySpawner, EnemySpawnBoxCollision), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANP_EnemySpawner_Statics::NewProp_EnemySpawnBoxCollision_MetaData), Z_Construct_UClass_ANP_EnemySpawner_Statics::NewProp_EnemySpawnBoxCollision_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ANP_EnemySpawner_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANP_EnemySpawner_Statics::NewProp_EnemySpawnBoxCollision,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ANP_EnemySpawner_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANP_EnemySpawner>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ANP_EnemySpawner_Statics::ClassParams = {
		&ANP_EnemySpawner::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ANP_EnemySpawner_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ANP_EnemySpawner_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANP_EnemySpawner_Statics::Class_MetaDataParams), Z_Construct_UClass_ANP_EnemySpawner_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANP_EnemySpawner_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ANP_EnemySpawner()
	{
		if (!Z_Registration_Info_UClass_ANP_EnemySpawner.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ANP_EnemySpawner.OuterSingleton, Z_Construct_UClass_ANP_EnemySpawner_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ANP_EnemySpawner.OuterSingleton;
	}
	template<> NEONPARADIGM_GAME_API UClass* StaticClass<ANP_EnemySpawner>()
	{
		return ANP_EnemySpawner::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANP_EnemySpawner);
	ANP_EnemySpawner::~ANP_EnemySpawner() {}
	struct Z_CompiledInDeferFile_FID_Users_angie_Desktop_soulfroge_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enemies_NP_EnemySpawner_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_angie_Desktop_soulfroge_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enemies_NP_EnemySpawner_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ANP_EnemySpawner, ANP_EnemySpawner::StaticClass, TEXT("ANP_EnemySpawner"), &Z_Registration_Info_UClass_ANP_EnemySpawner, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ANP_EnemySpawner), 2986508115U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_angie_Desktop_soulfroge_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enemies_NP_EnemySpawner_h_3796886695(TEXT("/Script/NeonParadigm_Game"),
		Z_CompiledInDeferFile_FID_Users_angie_Desktop_soulfroge_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enemies_NP_EnemySpawner_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_angie_Desktop_soulfroge_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enemies_NP_EnemySpawner_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
