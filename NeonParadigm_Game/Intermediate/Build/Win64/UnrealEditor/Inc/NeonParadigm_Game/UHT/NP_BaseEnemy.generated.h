// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Enemies/NP_BaseEnemy.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class AController;
class UAnimMontage;
class UDamageType;
enum class ECharacterStates : uint8;
#ifdef NEONPARADIGM_GAME_NP_BaseEnemy_generated_h
#error "NP_BaseEnemy.generated.h already included, missing '#pragma once' in NP_BaseEnemy.h"
#endif
#define NEONPARADIGM_GAME_NP_BaseEnemy_generated_h

#define FID__J_Hernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enemies_NP_BaseEnemy_h_18_SPARSE_DATA
#define FID__J_Hernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enemies_NP_BaseEnemy_h_18_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID__J_Hernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enemies_NP_BaseEnemy_h_18_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID__J_Hernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enemies_NP_BaseEnemy_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetNotifyTriggerTime); \
	DECLARE_FUNCTION(execFindNotifyTriggerTime); \
	DECLARE_FUNCTION(execCheckToWaitForBeat); \
	DECLARE_FUNCTION(execTestRhythmDelayEvent); \
	DECLARE_FUNCTION(execGetCurrentAnimPlayRate); \
	DECLARE_FUNCTION(execSetCurrentAnimTimeDelay); \
	DECLARE_FUNCTION(execIsCurrentStateEqualToAny); \
	DECLARE_FUNCTION(execSetState); \
	DECLARE_FUNCTION(execHandleTakeAnyDamage);


#define FID__J_Hernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enemies_NP_BaseEnemy_h_18_ACCESSORS
#define FID__J_Hernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enemies_NP_BaseEnemy_h_18_CALLBACK_WRAPPERS
#define FID__J_Hernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enemies_NP_BaseEnemy_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesANP_BaseEnemy(); \
	friend struct Z_Construct_UClass_ANP_BaseEnemy_Statics; \
public: \
	DECLARE_CLASS(ANP_BaseEnemy, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/NeonParadigm_Game"), NO_API) \
	DECLARE_SERIALIZER(ANP_BaseEnemy)


#define FID__J_Hernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enemies_NP_BaseEnemy_h_18_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ANP_BaseEnemy(ANP_BaseEnemy&&); \
	NO_API ANP_BaseEnemy(const ANP_BaseEnemy&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ANP_BaseEnemy); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ANP_BaseEnemy); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ANP_BaseEnemy) \
	NO_API virtual ~ANP_BaseEnemy();


#define FID__J_Hernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enemies_NP_BaseEnemy_h_15_PROLOG
#define FID__J_Hernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enemies_NP_BaseEnemy_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID__J_Hernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enemies_NP_BaseEnemy_h_18_SPARSE_DATA \
	FID__J_Hernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enemies_NP_BaseEnemy_h_18_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID__J_Hernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enemies_NP_BaseEnemy_h_18_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID__J_Hernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enemies_NP_BaseEnemy_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	FID__J_Hernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enemies_NP_BaseEnemy_h_18_ACCESSORS \
	FID__J_Hernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enemies_NP_BaseEnemy_h_18_CALLBACK_WRAPPERS \
	FID__J_Hernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enemies_NP_BaseEnemy_h_18_INCLASS_NO_PURE_DECLS \
	FID__J_Hernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enemies_NP_BaseEnemy_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> NEONPARADIGM_GAME_API UClass* StaticClass<class ANP_BaseEnemy>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID__J_Hernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enemies_NP_BaseEnemy_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
