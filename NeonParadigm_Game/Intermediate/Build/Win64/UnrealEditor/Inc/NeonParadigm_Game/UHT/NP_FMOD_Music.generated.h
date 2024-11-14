// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "FMOD/NP_FMOD_Music.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class ANP_BaseEnemy;
#ifdef NEONPARADIGM_GAME_NP_FMOD_Music_generated_h
#error "NP_FMOD_Music.generated.h already included, missing '#pragma once' in NP_FMOD_Music.h"
#endif
#define NEONPARADIGM_GAME_NP_FMOD_Music_generated_h

#define FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_FMOD_NP_FMOD_Music_h_19_SPARSE_DATA
#define FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_FMOD_NP_FMOD_Music_h_19_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_FMOD_NP_FMOD_Music_h_19_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_FMOD_NP_FMOD_Music_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetWallBlockActors); \
	DECLARE_FUNCTION(execSetFirstTimeBool); \
	DECLARE_FUNCTION(execAddSpawnedEnemy); \
	DECLARE_FUNCTION(execOnTimelineMarker); \
	DECLARE_FUNCTION(execOnTimelineBeat);


#define FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_FMOD_NP_FMOD_Music_h_19_ACCESSORS
#define FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_FMOD_NP_FMOD_Music_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesANP_FMOD_Music(); \
	friend struct Z_Construct_UClass_ANP_FMOD_Music_Statics; \
public: \
	DECLARE_CLASS(ANP_FMOD_Music, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/NeonParadigm_Game"), NO_API) \
	DECLARE_SERIALIZER(ANP_FMOD_Music)


#define FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_FMOD_NP_FMOD_Music_h_19_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ANP_FMOD_Music(ANP_FMOD_Music&&); \
	NO_API ANP_FMOD_Music(const ANP_FMOD_Music&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ANP_FMOD_Music); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ANP_FMOD_Music); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ANP_FMOD_Music) \
	NO_API virtual ~ANP_FMOD_Music();


#define FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_FMOD_NP_FMOD_Music_h_16_PROLOG
#define FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_FMOD_NP_FMOD_Music_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_FMOD_NP_FMOD_Music_h_19_SPARSE_DATA \
	FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_FMOD_NP_FMOD_Music_h_19_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_FMOD_NP_FMOD_Music_h_19_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_FMOD_NP_FMOD_Music_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_FMOD_NP_FMOD_Music_h_19_ACCESSORS \
	FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_FMOD_NP_FMOD_Music_h_19_INCLASS_NO_PURE_DECLS \
	FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_FMOD_NP_FMOD_Music_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> NEONPARADIGM_GAME_API UClass* StaticClass<class ANP_FMOD_Music>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_FMOD_NP_FMOD_Music_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
