// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NeonParadigm_Game/FMOD/NP_FMOD_Music.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNP_FMOD_Music() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UParticleSystem_NoRegister();
	FMODSTUDIO_API UClass* Z_Construct_UClass_UFMODAudioComponent_NoRegister();
	FMODSTUDIO_API UClass* Z_Construct_UClass_UFMODEvent_NoRegister();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_ANP_BaseEnemy_NoRegister();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_ANP_FMOD_Music();
	NEONPARADIGM_GAME_API UClass* Z_Construct_UClass_ANP_FMOD_Music_NoRegister();
	UPackage* Z_Construct_UPackage__Script_NeonParadigm_Game();
// End Cross Module References
	DEFINE_FUNCTION(ANP_FMOD_Music::execAddSpawnedEnemy)
	{
		P_GET_OBJECT(ANP_BaseEnemy,Z_Param_SpawnedEnemy);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddSpawnedEnemy(Z_Param_SpawnedEnemy);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANP_FMOD_Music::execOnTimelineMarker)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_Name);
		P_GET_PROPERTY(FIntProperty,Z_Param_Position);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnTimelineMarker(Z_Param_Name,Z_Param_Position);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ANP_FMOD_Music::execOnTimelineBeat)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Bar);
		P_GET_PROPERTY(FIntProperty,Z_Param_Beat);
		P_GET_PROPERTY(FIntProperty,Z_Param_Position);
		P_GET_PROPERTY(FFloatProperty,Z_Param_Tempo);
		P_GET_PROPERTY(FIntProperty,Z_Param_TimeSignatureUpper);
		P_GET_PROPERTY(FIntProperty,Z_Param_TimeSignatureLower);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnTimelineBeat(Z_Param_Bar,Z_Param_Beat,Z_Param_Position,Z_Param_Tempo,Z_Param_TimeSignatureUpper,Z_Param_TimeSignatureLower);
		P_NATIVE_END;
	}
	void ANP_FMOD_Music::StaticRegisterNativesANP_FMOD_Music()
	{
		UClass* Class = ANP_FMOD_Music::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddSpawnedEnemy", &ANP_FMOD_Music::execAddSpawnedEnemy },
			{ "OnTimelineBeat", &ANP_FMOD_Music::execOnTimelineBeat },
			{ "OnTimelineMarker", &ANP_FMOD_Music::execOnTimelineMarker },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ANP_FMOD_Music_AddSpawnedEnemy_Statics
	{
		struct NP_FMOD_Music_eventAddSpawnedEnemy_Parms
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
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ANP_FMOD_Music_AddSpawnedEnemy_Statics::NewProp_SpawnedEnemy = { "SpawnedEnemy", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NP_FMOD_Music_eventAddSpawnedEnemy_Parms, SpawnedEnemy), Z_Construct_UClass_ANP_BaseEnemy_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANP_FMOD_Music_AddSpawnedEnemy_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANP_FMOD_Music_AddSpawnedEnemy_Statics::NewProp_SpawnedEnemy,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANP_FMOD_Music_AddSpawnedEnemy_Statics::Function_MetaDataParams[] = {
		{ "Category", "Music" },
		{ "ModuleRelativePath", "FMOD/NP_FMOD_Music.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANP_FMOD_Music_AddSpawnedEnemy_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANP_FMOD_Music, nullptr, "AddSpawnedEnemy", nullptr, nullptr, Z_Construct_UFunction_ANP_FMOD_Music_AddSpawnedEnemy_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_FMOD_Music_AddSpawnedEnemy_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANP_FMOD_Music_AddSpawnedEnemy_Statics::NP_FMOD_Music_eventAddSpawnedEnemy_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_FMOD_Music_AddSpawnedEnemy_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANP_FMOD_Music_AddSpawnedEnemy_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_FMOD_Music_AddSpawnedEnemy_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ANP_FMOD_Music_AddSpawnedEnemy_Statics::NP_FMOD_Music_eventAddSpawnedEnemy_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANP_FMOD_Music_AddSpawnedEnemy()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANP_FMOD_Music_AddSpawnedEnemy_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineBeat_Statics
	{
		struct NP_FMOD_Music_eventOnTimelineBeat_Parms
		{
			int32 Bar;
			int32 Beat;
			int32 Position;
			float Tempo;
			int32 TimeSignatureUpper;
			int32 TimeSignatureLower;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Bar;
		static const UECodeGen_Private::FIntPropertyParams NewProp_Beat;
		static const UECodeGen_Private::FIntPropertyParams NewProp_Position;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Tempo;
		static const UECodeGen_Private::FIntPropertyParams NewProp_TimeSignatureUpper;
		static const UECodeGen_Private::FIntPropertyParams NewProp_TimeSignatureLower;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineBeat_Statics::NewProp_Bar = { "Bar", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NP_FMOD_Music_eventOnTimelineBeat_Parms, Bar), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineBeat_Statics::NewProp_Beat = { "Beat", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NP_FMOD_Music_eventOnTimelineBeat_Parms, Beat), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineBeat_Statics::NewProp_Position = { "Position", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NP_FMOD_Music_eventOnTimelineBeat_Parms, Position), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineBeat_Statics::NewProp_Tempo = { "Tempo", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NP_FMOD_Music_eventOnTimelineBeat_Parms, Tempo), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineBeat_Statics::NewProp_TimeSignatureUpper = { "TimeSignatureUpper", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NP_FMOD_Music_eventOnTimelineBeat_Parms, TimeSignatureUpper), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineBeat_Statics::NewProp_TimeSignatureLower = { "TimeSignatureLower", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NP_FMOD_Music_eventOnTimelineBeat_Parms, TimeSignatureLower), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineBeat_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineBeat_Statics::NewProp_Bar,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineBeat_Statics::NewProp_Beat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineBeat_Statics::NewProp_Position,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineBeat_Statics::NewProp_Tempo,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineBeat_Statics::NewProp_TimeSignatureUpper,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineBeat_Statics::NewProp_TimeSignatureLower,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineBeat_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Function to handle the timeline beat event\n" },
#endif
		{ "ModuleRelativePath", "FMOD/NP_FMOD_Music.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Function to handle the timeline beat event" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineBeat_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANP_FMOD_Music, nullptr, "OnTimelineBeat", nullptr, nullptr, Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineBeat_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineBeat_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineBeat_Statics::NP_FMOD_Music_eventOnTimelineBeat_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineBeat_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineBeat_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineBeat_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineBeat_Statics::NP_FMOD_Music_eventOnTimelineBeat_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineBeat()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineBeat_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineMarker_Statics
	{
		struct NP_FMOD_Music_eventOnTimelineMarker_Parms
		{
			FString Name;
			int32 Position;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
		static const UECodeGen_Private::FIntPropertyParams NewProp_Position;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineMarker_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NP_FMOD_Music_eventOnTimelineMarker_Parms, Name), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineMarker_Statics::NewProp_Position = { "Position", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NP_FMOD_Music_eventOnTimelineMarker_Parms, Position), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineMarker_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineMarker_Statics::NewProp_Name,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineMarker_Statics::NewProp_Position,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineMarker_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "FMOD/NP_FMOD_Music.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineMarker_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ANP_FMOD_Music, nullptr, "OnTimelineMarker", nullptr, nullptr, Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineMarker_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineMarker_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineMarker_Statics::NP_FMOD_Music_eventOnTimelineMarker_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineMarker_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineMarker_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineMarker_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineMarker_Statics::NP_FMOD_Music_eventOnTimelineMarker_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineMarker()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineMarker_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ANP_FMOD_Music);
	UClass* Z_Construct_UClass_ANP_FMOD_Music_NoRegister()
	{
		return ANP_FMOD_Music::StaticClass();
	}
	struct Z_Construct_UClass_ANP_FMOD_Music_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FMODAudioComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_FMODAudioComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MusicFMODEvent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MusicFMODEvent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TempBPMParticle_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TempBPMParticle;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TempBPMMusic_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_TempBPMMusic;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ANP_FMOD_Music_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_NeonParadigm_Game,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANP_FMOD_Music_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_ANP_FMOD_Music_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ANP_FMOD_Music_AddSpawnedEnemy, "AddSpawnedEnemy" }, // 3507476801
		{ &Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineBeat, "OnTimelineBeat" }, // 4125278527
		{ &Z_Construct_UFunction_ANP_FMOD_Music_OnTimelineMarker, "OnTimelineMarker" }, // 3013220962
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANP_FMOD_Music_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANP_FMOD_Music_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "FMOD/NP_FMOD_Music.h" },
		{ "ModuleRelativePath", "FMOD/NP_FMOD_Music.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANP_FMOD_Music_Statics::NewProp_FMODAudioComponent_MetaData[] = {
		{ "Category", "Audio" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// FMOD Audio Component\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FMOD/NP_FMOD_Music.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "FMOD Audio Component" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANP_FMOD_Music_Statics::NewProp_FMODAudioComponent = { "FMODAudioComponent", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANP_FMOD_Music, FMODAudioComponent), Z_Construct_UClass_UFMODAudioComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANP_FMOD_Music_Statics::NewProp_FMODAudioComponent_MetaData), Z_Construct_UClass_ANP_FMOD_Music_Statics::NewProp_FMODAudioComponent_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANP_FMOD_Music_Statics::NewProp_MusicFMODEvent_MetaData[] = {
		{ "Category", "Audio" },
		{ "ModuleRelativePath", "FMOD/NP_FMOD_Music.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANP_FMOD_Music_Statics::NewProp_MusicFMODEvent = { "MusicFMODEvent", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANP_FMOD_Music, MusicFMODEvent), Z_Construct_UClass_UFMODEvent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANP_FMOD_Music_Statics::NewProp_MusicFMODEvent_MetaData), Z_Construct_UClass_ANP_FMOD_Music_Statics::NewProp_MusicFMODEvent_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANP_FMOD_Music_Statics::NewProp_TempBPMParticle_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Audio" },
		{ "ModuleRelativePath", "FMOD/NP_FMOD_Music.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANP_FMOD_Music_Statics::NewProp_TempBPMParticle = { "TempBPMParticle", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANP_FMOD_Music, TempBPMParticle), Z_Construct_UClass_UParticleSystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANP_FMOD_Music_Statics::NewProp_TempBPMParticle_MetaData), Z_Construct_UClass_ANP_FMOD_Music_Statics::NewProp_TempBPMParticle_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANP_FMOD_Music_Statics::NewProp_TempBPMMusic_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Audio" },
		{ "ModuleRelativePath", "FMOD/NP_FMOD_Music.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ANP_FMOD_Music_Statics::NewProp_TempBPMMusic = { "TempBPMMusic", nullptr, (EPropertyFlags)0x0044000000010015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANP_FMOD_Music, TempBPMMusic), Z_Construct_UClass_UClass, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANP_FMOD_Music_Statics::NewProp_TempBPMMusic_MetaData), Z_Construct_UClass_ANP_FMOD_Music_Statics::NewProp_TempBPMMusic_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ANP_FMOD_Music_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANP_FMOD_Music_Statics::NewProp_FMODAudioComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANP_FMOD_Music_Statics::NewProp_MusicFMODEvent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANP_FMOD_Music_Statics::NewProp_TempBPMParticle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANP_FMOD_Music_Statics::NewProp_TempBPMMusic,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ANP_FMOD_Music_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANP_FMOD_Music>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ANP_FMOD_Music_Statics::ClassParams = {
		&ANP_FMOD_Music::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ANP_FMOD_Music_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ANP_FMOD_Music_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANP_FMOD_Music_Statics::Class_MetaDataParams), Z_Construct_UClass_ANP_FMOD_Music_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANP_FMOD_Music_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ANP_FMOD_Music()
	{
		if (!Z_Registration_Info_UClass_ANP_FMOD_Music.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ANP_FMOD_Music.OuterSingleton, Z_Construct_UClass_ANP_FMOD_Music_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ANP_FMOD_Music.OuterSingleton;
	}
	template<> NEONPARADIGM_GAME_API UClass* StaticClass<ANP_FMOD_Music>()
	{
		return ANP_FMOD_Music::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANP_FMOD_Music);
	ANP_FMOD_Music::~ANP_FMOD_Music() {}
	struct Z_CompiledInDeferFile_FID__J_Hernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_FMOD_NP_FMOD_Music_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID__J_Hernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_FMOD_NP_FMOD_Music_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ANP_FMOD_Music, ANP_FMOD_Music::StaticClass, TEXT("ANP_FMOD_Music"), &Z_Registration_Info_UClass_ANP_FMOD_Music, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ANP_FMOD_Music), 590864808U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID__J_Hernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_FMOD_NP_FMOD_Music_h_761738647(TEXT("/Script/NeonParadigm_Game"),
		Z_CompiledInDeferFile_FID__J_Hernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_FMOD_NP_FMOD_Music_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID__J_Hernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_FMOD_NP_FMOD_Music_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
