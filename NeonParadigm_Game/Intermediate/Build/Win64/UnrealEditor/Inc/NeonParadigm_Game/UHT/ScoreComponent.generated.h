// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Components/ScoreComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef NEONPARADIGM_GAME_ScoreComponent_generated_h
#error "ScoreComponent.generated.h already included, missing '#pragma once' in ScoreComponent.h"
#endif
#define NEONPARADIGM_GAME_ScoreComponent_generated_h

#define FID_NeonParadigm_Game_Source_NeonParadigm_Game_Components_ScoreComponent_h_13_SPARSE_DATA
#define FID_NeonParadigm_Game_Source_NeonParadigm_Game_Components_ScoreComponent_h_13_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_NeonParadigm_Game_Source_NeonParadigm_Game_Components_ScoreComponent_h_13_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_NeonParadigm_Game_Source_NeonParadigm_Game_Components_ScoreComponent_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetOverallScoreGrade); \
	DECLARE_FUNCTION(execCalculateOverallScore); \
	DECLARE_FUNCTION(execGetClearTime); \
	DECLARE_FUNCTION(execCalculateClearTimingGrade); \
	DECLARE_FUNCTION(execCalculateClearTimeBonus); \
	DECLARE_FUNCTION(execCalculatePerfectTimingGrade); \
	DECLARE_FUNCTION(execGetPerfectTimingPercentage); \
	DECLARE_FUNCTION(execCalculatePerfectTimingBonus); \
	DECLARE_FUNCTION(execEndEncounter); \
	DECLARE_FUNCTION(execStartEncounter); \
	DECLARE_FUNCTION(execDepleteProgress); \
	DECLARE_FUNCTION(execGetRankProgress); \
	DECLARE_FUNCTION(execGetCurrentRankIndex); \
	DECLARE_FUNCTION(execCalculateGradeBonus); \
	DECLARE_FUNCTION(execCalculateGrade); \
	DECLARE_FUNCTION(execGetCurrentScore);


#define FID_NeonParadigm_Game_Source_NeonParadigm_Game_Components_ScoreComponent_h_13_ACCESSORS
#define FID_NeonParadigm_Game_Source_NeonParadigm_Game_Components_ScoreComponent_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUScoreComponent(); \
	friend struct Z_Construct_UClass_UScoreComponent_Statics; \
public: \
	DECLARE_CLASS(UScoreComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/NeonParadigm_Game"), NO_API) \
	DECLARE_SERIALIZER(UScoreComponent)


#define FID_NeonParadigm_Game_Source_NeonParadigm_Game_Components_ScoreComponent_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UScoreComponent(UScoreComponent&&); \
	NO_API UScoreComponent(const UScoreComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UScoreComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UScoreComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UScoreComponent) \
	NO_API virtual ~UScoreComponent();


#define FID_NeonParadigm_Game_Source_NeonParadigm_Game_Components_ScoreComponent_h_10_PROLOG
#define FID_NeonParadigm_Game_Source_NeonParadigm_Game_Components_ScoreComponent_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_NeonParadigm_Game_Source_NeonParadigm_Game_Components_ScoreComponent_h_13_SPARSE_DATA \
	FID_NeonParadigm_Game_Source_NeonParadigm_Game_Components_ScoreComponent_h_13_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_NeonParadigm_Game_Source_NeonParadigm_Game_Components_ScoreComponent_h_13_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_NeonParadigm_Game_Source_NeonParadigm_Game_Components_ScoreComponent_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_NeonParadigm_Game_Source_NeonParadigm_Game_Components_ScoreComponent_h_13_ACCESSORS \
	FID_NeonParadigm_Game_Source_NeonParadigm_Game_Components_ScoreComponent_h_13_INCLASS_NO_PURE_DECLS \
	FID_NeonParadigm_Game_Source_NeonParadigm_Game_Components_ScoreComponent_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> NEONPARADIGM_GAME_API UClass* StaticClass<class UScoreComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_NeonParadigm_Game_Source_NeonParadigm_Game_Components_ScoreComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
