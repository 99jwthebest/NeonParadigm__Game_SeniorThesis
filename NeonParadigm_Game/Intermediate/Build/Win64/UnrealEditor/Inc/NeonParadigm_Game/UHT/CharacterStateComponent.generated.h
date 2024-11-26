// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Enums/CharacterStateComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class ECharacterStates : uint8;
#ifdef NEONPARADIGM_GAME_CharacterStateComponent_generated_h
#error "CharacterStateComponent.generated.h already included, missing '#pragma once' in CharacterStateComponent.h"
#endif
#define NEONPARADIGM_GAME_CharacterStateComponent_generated_h

#define FID_Angie_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enums_CharacterStateComponent_h_27_SPARSE_DATA
#define FID_Angie_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enums_CharacterStateComponent_h_27_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Angie_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enums_CharacterStateComponent_h_27_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Angie_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enums_CharacterStateComponent_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetState); \
	DECLARE_FUNCTION(execSetState);


#define FID_Angie_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enums_CharacterStateComponent_h_27_ACCESSORS
#define FID_Angie_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enums_CharacterStateComponent_h_27_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCharacterStateComponent(); \
	friend struct Z_Construct_UClass_UCharacterStateComponent_Statics; \
public: \
	DECLARE_CLASS(UCharacterStateComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/NeonParadigm_Game"), NO_API) \
	DECLARE_SERIALIZER(UCharacterStateComponent)


#define FID_Angie_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enums_CharacterStateComponent_h_27_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCharacterStateComponent(UCharacterStateComponent&&); \
	NO_API UCharacterStateComponent(const UCharacterStateComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCharacterStateComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCharacterStateComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCharacterStateComponent) \
	NO_API virtual ~UCharacterStateComponent();


#define FID_Angie_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enums_CharacterStateComponent_h_24_PROLOG
#define FID_Angie_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enums_CharacterStateComponent_h_27_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Angie_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enums_CharacterStateComponent_h_27_SPARSE_DATA \
	FID_Angie_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enums_CharacterStateComponent_h_27_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Angie_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enums_CharacterStateComponent_h_27_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Angie_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enums_CharacterStateComponent_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Angie_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enums_CharacterStateComponent_h_27_ACCESSORS \
	FID_Angie_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enums_CharacterStateComponent_h_27_INCLASS_NO_PURE_DECLS \
	FID_Angie_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enums_CharacterStateComponent_h_27_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> NEONPARADIGM_GAME_API UClass* StaticClass<class UCharacterStateComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Angie_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enums_CharacterStateComponent_h


#define FOREACH_ENUM_ECHARACTERSTATES(op) \
	op(ECharacterStates::None) \
	op(ECharacterStates::Attack) \
	op(ECharacterStates::Dodge) \
	op(ECharacterStates::Death) \
	op(ECharacterStates::Disabled) \
	op(ECharacterStates::Parry) 

enum class ECharacterStates : uint8;
template<> struct TIsUEnumClass<ECharacterStates> { enum { Value = true }; };
template<> NEONPARADIGM_GAME_API UEnum* StaticEnum<ECharacterStates>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
