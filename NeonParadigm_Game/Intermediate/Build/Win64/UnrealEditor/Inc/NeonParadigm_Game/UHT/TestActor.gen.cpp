// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NeonParadigm_Game/TestActor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTestActor() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AController_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UDamageType_NoRegister();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_ATestActor();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_ATestActor_NoRegister();
	UPackage* Z_Construct_UPackage__Script_NeonParadigm_Game();
// End Cross Module References
	DEFINE_FUNCTION(ATestActor::execHandleTakeAnyDamage)
	{
		P_GET_OBJECT(AActor,Z_Param_DamagedActor);
		P_GET_PROPERTY(FFloatProperty,Z_Param_Damage);
		P_GET_OBJECT(UDamageType,Z_Param_DamageType);
		P_GET_OBJECT(AController,Z_Param_InstigatedBy);
		P_GET_OBJECT(AActor,Z_Param_DamageCauser);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->HandleTakeAnyDamage(Z_Param_DamagedActor,Z_Param_Damage,Z_Param_DamageType,Z_Param_InstigatedBy,Z_Param_DamageCauser);
		P_NATIVE_END;
	}
	void ATestActor::StaticRegisterNativesATestActor()
	{
		UClass* Class = ATestActor::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "HandleTakeAnyDamage", &ATestActor::execHandleTakeAnyDamage },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ATestActor_HandleTakeAnyDamage_Statics
	{
		struct TestActor_eventHandleTakeAnyDamage_Parms
		{
			AActor* DamagedActor;
			float Damage;
			const UDamageType* DamageType;
			AController* InstigatedBy;
			AActor* DamageCauser;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DamagedActor;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Damage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DamageType_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DamageType;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InstigatedBy;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DamageCauser;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATestActor_HandleTakeAnyDamage_Statics::NewProp_DamagedActor = { "DamagedActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TestActor_eventHandleTakeAnyDamage_Parms, DamagedActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ATestActor_HandleTakeAnyDamage_Statics::NewProp_Damage = { "Damage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TestActor_eventHandleTakeAnyDamage_Parms, Damage), METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATestActor_HandleTakeAnyDamage_Statics::NewProp_DamageType_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATestActor_HandleTakeAnyDamage_Statics::NewProp_DamageType = { "DamageType", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TestActor_eventHandleTakeAnyDamage_Parms, DamageType), Z_Construct_UClass_UDamageType_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATestActor_HandleTakeAnyDamage_Statics::NewProp_DamageType_MetaData), Z_Construct_UFunction_ATestActor_HandleTakeAnyDamage_Statics::NewProp_DamageType_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATestActor_HandleTakeAnyDamage_Statics::NewProp_InstigatedBy = { "InstigatedBy", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TestActor_eventHandleTakeAnyDamage_Parms, InstigatedBy), Z_Construct_UClass_AController_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATestActor_HandleTakeAnyDamage_Statics::NewProp_DamageCauser = { "DamageCauser", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TestActor_eventHandleTakeAnyDamage_Parms, DamageCauser), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATestActor_HandleTakeAnyDamage_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATestActor_HandleTakeAnyDamage_Statics::NewProp_DamagedActor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATestActor_HandleTakeAnyDamage_Statics::NewProp_Damage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATestActor_HandleTakeAnyDamage_Statics::NewProp_DamageType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATestActor_HandleTakeAnyDamage_Statics::NewProp_InstigatedBy,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATestActor_HandleTakeAnyDamage_Statics::NewProp_DamageCauser,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATestActor_HandleTakeAnyDamage_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "TestActor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATestActor_HandleTakeAnyDamage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATestActor, nullptr, "HandleTakeAnyDamage", nullptr, nullptr, Z_Construct_UFunction_ATestActor_HandleTakeAnyDamage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATestActor_HandleTakeAnyDamage_Statics::PropPointers), sizeof(Z_Construct_UFunction_ATestActor_HandleTakeAnyDamage_Statics::TestActor_eventHandleTakeAnyDamage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATestActor_HandleTakeAnyDamage_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATestActor_HandleTakeAnyDamage_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ATestActor_HandleTakeAnyDamage_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ATestActor_HandleTakeAnyDamage_Statics::TestActor_eventHandleTakeAnyDamage_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ATestActor_HandleTakeAnyDamage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATestActor_HandleTakeAnyDamage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATestActor);
	UClass* Z_Construct_UClass_ATestActor_NoRegister()
	{
		return ATestActor::StaticClass();
	}
	struct Z_Construct_UClass_ATestActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATestActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_NeonParadigm_Game,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATestActor_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_ATestActor_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ATestActor_HandleTakeAnyDamage, "HandleTakeAnyDamage" }, // 3198369646
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATestActor_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATestActor_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "TestActor.h" },
		{ "ModuleRelativePath", "TestActor.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATestActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATestActor>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ATestActor_Statics::ClassParams = {
		&ATestActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATestActor_Statics::Class_MetaDataParams), Z_Construct_UClass_ATestActor_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_ATestActor()
	{
		if (!Z_Registration_Info_UClass_ATestActor.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATestActor.OuterSingleton, Z_Construct_UClass_ATestActor_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ATestActor.OuterSingleton;
	}
	template<> NEONPARADIGM_GAME_API UClass* StaticClass<ATestActor>()
	{
		return ATestActor::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATestActor);
	ATestActor::~ATestActor() {}
	struct Z_CompiledInDeferFile_FID_Users_anmart28_Documents_GitHub_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_TestActor_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_anmart28_Documents_GitHub_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_TestActor_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ATestActor, ATestActor::StaticClass, TEXT("ATestActor"), &Z_Registration_Info_UClass_ATestActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATestActor), 3682140161U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_anmart28_Documents_GitHub_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_TestActor_h_1050678421(TEXT("/Script/NeonParadigm_Game"),
		Z_CompiledInDeferFile_FID_Users_anmart28_Documents_GitHub_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_TestActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_anmart28_Documents_GitHub_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_TestActor_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
