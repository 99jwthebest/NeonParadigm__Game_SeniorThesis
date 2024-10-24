// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "NeonParadigm_GameCharacter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class AController;
class UDamageType;
#ifdef NEONPARADIGM_GAME_NeonParadigm_GameCharacter_generated_h
#error "NeonParadigm_GameCharacter.generated.h already included, missing '#pragma once' in NeonParadigm_GameCharacter.h"
#endif
#define NEONPARADIGM_GAME_NeonParadigm_GameCharacter_generated_h

#define FID_NeonParadigm_Game_Source_NeonParadigm_Game_NeonParadigm_GameCharacter_h_27_SPARSE_DATA
#define FID_NeonParadigm_Game_Source_NeonParadigm_Game_NeonParadigm_GameCharacter_h_27_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_NeonParadigm_Game_Source_NeonParadigm_Game_NeonParadigm_GameCharacter_h_27_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_NeonParadigm_Game_Source_NeonParadigm_Game_NeonParadigm_GameCharacter_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execCounter); \
	DECLARE_FUNCTION(execHandleTakeAnyDamage); \
	DECLARE_FUNCTION(execIsIFramesEnabled);


#define FID_NeonParadigm_Game_Source_NeonParadigm_Game_NeonParadigm_GameCharacter_h_27_ACCESSORS
#define FID_NeonParadigm_Game_Source_NeonParadigm_Game_NeonParadigm_GameCharacter_h_27_CALLBACK_WRAPPERS
#define FID_NeonParadigm_Game_Source_NeonParadigm_Game_NeonParadigm_GameCharacter_h_27_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesANeonParadigm_GameCharacter(); \
	friend struct Z_Construct_UClass_ANeonParadigm_GameCharacter_Statics; \
public: \
	DECLARE_CLASS(ANeonParadigm_GameCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/NeonParadigm_Game"), NO_API) \
	DECLARE_SERIALIZER(ANeonParadigm_GameCharacter)


#define FID_NeonParadigm_Game_Source_NeonParadigm_Game_NeonParadigm_GameCharacter_h_27_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ANeonParadigm_GameCharacter(ANeonParadigm_GameCharacter&&); \
	NO_API ANeonParadigm_GameCharacter(const ANeonParadigm_GameCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ANeonParadigm_GameCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ANeonParadigm_GameCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ANeonParadigm_GameCharacter) \
	NO_API virtual ~ANeonParadigm_GameCharacter();


#define FID_NeonParadigm_Game_Source_NeonParadigm_Game_NeonParadigm_GameCharacter_h_24_PROLOG
#define FID_NeonParadigm_Game_Source_NeonParadigm_Game_NeonParadigm_GameCharacter_h_27_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_NeonParadigm_Game_Source_NeonParadigm_Game_NeonParadigm_GameCharacter_h_27_SPARSE_DATA \
	FID_NeonParadigm_Game_Source_NeonParadigm_Game_NeonParadigm_GameCharacter_h_27_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_NeonParadigm_Game_Source_NeonParadigm_Game_NeonParadigm_GameCharacter_h_27_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_NeonParadigm_Game_Source_NeonParadigm_Game_NeonParadigm_GameCharacter_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_NeonParadigm_Game_Source_NeonParadigm_Game_NeonParadigm_GameCharacter_h_27_ACCESSORS \
	FID_NeonParadigm_Game_Source_NeonParadigm_Game_NeonParadigm_GameCharacter_h_27_CALLBACK_WRAPPERS \
	FID_NeonParadigm_Game_Source_NeonParadigm_Game_NeonParadigm_GameCharacter_h_27_INCLASS_NO_PURE_DECLS \
	FID_NeonParadigm_Game_Source_NeonParadigm_Game_NeonParadigm_GameCharacter_h_27_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> NEONPARADIGM_GAME_API UClass* StaticClass<class ANeonParadigm_GameCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_NeonParadigm_Game_Source_NeonParadigm_Game_NeonParadigm_GameCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
