// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NeonParadigm_Game/Enums/CharacterStateComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCharacterStateComponent() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UCharacterStateComponent();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_UCharacterStateComponent_NoRegister();
	NEONPARADIGM_GAME_API UEnum* Z_Construct_UEnum_NeonParadigm_Game_ECharacterStates();
	UPackage* Z_Construct_UPackage__Script_NeonParadigm_Game();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ECharacterStates;
	static UEnum* ECharacterStates_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ECharacterStates.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ECharacterStates.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_NeonParadigm_Game_ECharacterStates, (UObject*)Z_Construct_UPackage__Script_NeonParadigm_Game(), TEXT("ECharacterStates"));
		}
		return Z_Registration_Info_UEnum_ECharacterStates.OuterSingleton;
	}
	template<> NEONPARADIGM_GAME_API UEnum* StaticEnum<ECharacterStates>()
	{
		return ECharacterStates_StaticEnum();
	}
	struct Z_Construct_UEnum_NeonParadigm_Game_ECharacterStates_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_NeonParadigm_Game_ECharacterStates_Statics::Enumerators[] = {
		{ "ECharacterStates::None", (int64)ECharacterStates::None },
		{ "ECharacterStates::Attack", (int64)ECharacterStates::Attack },
		{ "ECharacterStates::Dodge", (int64)ECharacterStates::Dodge },
		{ "ECharacterStates::Death", (int64)ECharacterStates::Death },
		{ "ECharacterStates::Disabled", (int64)ECharacterStates::Disabled },
		{ "ECharacterStates::Parry", (int64)ECharacterStates::Parry },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_NeonParadigm_Game_ECharacterStates_Statics::Enum_MetaDataParams[] = {
		{ "Attack.Comment", "//UMETA(DisplayName = \"Option 1\"),\n" },
		{ "Attack.Name", "ECharacterStates::Attack" },
		{ "Attack.ToolTip", "UMETA(DisplayName = \"Option 1\")," },
		{ "BlueprintType", "true" },
		{ "Death.Comment", "//UMETA(DisplayName = \"Option 3\"),\n" },
		{ "Death.Name", "ECharacterStates::Death" },
		{ "Death.ToolTip", "UMETA(DisplayName = \"Option 3\")," },
		{ "Disabled.Comment", "//UMETA(DisplayName = \"Option 4\"),\n" },
		{ "Disabled.Name", "ECharacterStates::Disabled" },
		{ "Disabled.ToolTip", "UMETA(DisplayName = \"Option 4\")," },
		{ "Dodge.Comment", "//UMETA(DisplayName = \"Option 2\"),\n" },
		{ "Dodge.Name", "ECharacterStates::Dodge" },
		{ "Dodge.ToolTip", "UMETA(DisplayName = \"Option 2\")," },
		{ "ModuleRelativePath", "Enums/CharacterStateComponent.h" },
		{ "None.Name", "ECharacterStates::None" },
		{ "Parry.Comment", "//UMETA(DisplayName = \"Option 5\"),\n" },
		{ "Parry.Name", "ECharacterStates::Parry" },
		{ "Parry.ToolTip", "UMETA(DisplayName = \"Option 5\")," },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_NeonParadigm_Game_ECharacterStates_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_NeonParadigm_Game,
		nullptr,
		"ECharacterStates",
		"ECharacterStates",
		Z_Construct_UEnum_NeonParadigm_Game_ECharacterStates_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_NeonParadigm_Game_ECharacterStates_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_NeonParadigm_Game_ECharacterStates_Statics::Enum_MetaDataParams), Z_Construct_UEnum_NeonParadigm_Game_ECharacterStates_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_NeonParadigm_Game_ECharacterStates()
	{
		if (!Z_Registration_Info_UEnum_ECharacterStates.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ECharacterStates.InnerSingleton, Z_Construct_UEnum_NeonParadigm_Game_ECharacterStates_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ECharacterStates.InnerSingleton;
	}
	DEFINE_FUNCTION(UCharacterStateComponent::execGetState)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(ECharacterStates*)Z_Param__Result=P_THIS->GetState();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCharacterStateComponent::execSetState)
	{
		P_GET_ENUM(ECharacterStates,Z_Param_NewState);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetState(ECharacterStates(Z_Param_NewState));
		P_NATIVE_END;
	}
	void UCharacterStateComponent::StaticRegisterNativesUCharacterStateComponent()
	{
		UClass* Class = UCharacterStateComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetState", &UCharacterStateComponent::execGetState },
			{ "SetState", &UCharacterStateComponent::execSetState },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UCharacterStateComponent_GetState_Statics
	{
		struct CharacterStateComponent_eventGetState_Parms
		{
			ECharacterStates ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCharacterStateComponent_GetState_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UCharacterStateComponent_GetState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CharacterStateComponent_eventGetState_Parms, ReturnValue), Z_Construct_UEnum_NeonParadigm_Game_ECharacterStates, METADATA_PARAMS(0, nullptr) }; // 1500412229
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCharacterStateComponent_GetState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCharacterStateComponent_GetState_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCharacterStateComponent_GetState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCharacterStateComponent_GetState_Statics::Function_MetaDataParams[] = {
		{ "Category", "State" },
		{ "ModuleRelativePath", "Enums/CharacterStateComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCharacterStateComponent_GetState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCharacterStateComponent, nullptr, "GetState", nullptr, nullptr, Z_Construct_UFunction_UCharacterStateComponent_GetState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCharacterStateComponent_GetState_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCharacterStateComponent_GetState_Statics::CharacterStateComponent_eventGetState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCharacterStateComponent_GetState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCharacterStateComponent_GetState_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCharacterStateComponent_GetState_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UCharacterStateComponent_GetState_Statics::CharacterStateComponent_eventGetState_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UCharacterStateComponent_GetState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCharacterStateComponent_GetState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCharacterStateComponent_SetState_Statics
	{
		struct CharacterStateComponent_eventSetState_Parms
		{
			ECharacterStates NewState;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_NewState_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_NewState;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCharacterStateComponent_SetState_Statics::NewProp_NewState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UCharacterStateComponent_SetState_Statics::NewProp_NewState = { "NewState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CharacterStateComponent_eventSetState_Parms, NewState), Z_Construct_UEnum_NeonParadigm_Game_ECharacterStates, METADATA_PARAMS(0, nullptr) }; // 1500412229
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCharacterStateComponent_SetState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCharacterStateComponent_SetState_Statics::NewProp_NewState_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCharacterStateComponent_SetState_Statics::NewProp_NewState,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCharacterStateComponent_SetState_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Enums/CharacterStateComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCharacterStateComponent_SetState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCharacterStateComponent, nullptr, "SetState", nullptr, nullptr, Z_Construct_UFunction_UCharacterStateComponent_SetState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCharacterStateComponent_SetState_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCharacterStateComponent_SetState_Statics::CharacterStateComponent_eventSetState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCharacterStateComponent_SetState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCharacterStateComponent_SetState_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCharacterStateComponent_SetState_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UCharacterStateComponent_SetState_Statics::CharacterStateComponent_eventSetState_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UCharacterStateComponent_SetState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCharacterStateComponent_SetState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCharacterStateComponent);
	UClass* Z_Construct_UClass_UCharacterStateComponent_NoRegister()
	{
		return UCharacterStateComponent::StaticClass();
	}
	struct Z_Construct_UClass_UCharacterStateComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_CurrentState_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CurrentState_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_CurrentState;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCharacterStateComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_NeonParadigm_Game,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCharacterStateComponent_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UCharacterStateComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UCharacterStateComponent_GetState, "GetState" }, // 527585594
		{ &Z_Construct_UFunction_UCharacterStateComponent_SetState, "SetState" }, // 2237817368
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCharacterStateComponent_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCharacterStateComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "Enums/CharacterStateComponent.h" },
		{ "ModuleRelativePath", "Enums/CharacterStateComponent.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UCharacterStateComponent_Statics::NewProp_CurrentState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCharacterStateComponent_Statics::NewProp_CurrentState_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "State" },
		{ "ModuleRelativePath", "Enums/CharacterStateComponent.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UCharacterStateComponent_Statics::NewProp_CurrentState = { "CurrentState", nullptr, (EPropertyFlags)0x0040000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCharacterStateComponent, CurrentState), Z_Construct_UEnum_NeonParadigm_Game_ECharacterStates, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCharacterStateComponent_Statics::NewProp_CurrentState_MetaData), Z_Construct_UClass_UCharacterStateComponent_Statics::NewProp_CurrentState_MetaData) }; // 1500412229
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCharacterStateComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCharacterStateComponent_Statics::NewProp_CurrentState_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCharacterStateComponent_Statics::NewProp_CurrentState,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCharacterStateComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCharacterStateComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UCharacterStateComponent_Statics::ClassParams = {
		&UCharacterStateComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UCharacterStateComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UCharacterStateComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCharacterStateComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UCharacterStateComponent_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCharacterStateComponent_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UCharacterStateComponent()
	{
		if (!Z_Registration_Info_UClass_UCharacterStateComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCharacterStateComponent.OuterSingleton, Z_Construct_UClass_UCharacterStateComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UCharacterStateComponent.OuterSingleton;
	}
	template<> NEONPARADIGM_GAME_API UClass* StaticClass<UCharacterStateComponent>()
	{
		return UCharacterStateComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCharacterStateComponent);
	UCharacterStateComponent::~UCharacterStateComponent() {}
	struct Z_CompiledInDeferFile_FID_Angie_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enums_CharacterStateComponent_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Angie_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enums_CharacterStateComponent_h_Statics::EnumInfo[] = {
		{ ECharacterStates_StaticEnum, TEXT("ECharacterStates"), &Z_Registration_Info_UEnum_ECharacterStates, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1500412229U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Angie_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enums_CharacterStateComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UCharacterStateComponent, UCharacterStateComponent::StaticClass, TEXT("UCharacterStateComponent"), &Z_Registration_Info_UClass_UCharacterStateComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCharacterStateComponent), 916186401U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Angie_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enums_CharacterStateComponent_h_2803762899(TEXT("/Script/NeonParadigm_Game"),
		Z_CompiledInDeferFile_FID_Angie_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enums_CharacterStateComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Angie_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enums_CharacterStateComponent_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Angie_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enums_CharacterStateComponent_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Angie_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enums_CharacterStateComponent_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
