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

#define FID__JHernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enums_CharacterStateComponent_h_26_SPARSE_DATA
#define FID__JHernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enums_CharacterStateComponent_h_26_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID__JHernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enums_CharacterStateComponent_h_26_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID__JHernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enums_CharacterStateComponent_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetState); \
	DECLARE_FUNCTION(execSetState);


#define FID__JHernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enums_CharacterStateComponent_h_26_ACCESSORS
#define FID__JHernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enums_CharacterStateComponent_h_26_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCharacterStateComponent(); \
	friend struct Z_Construct_UClass_UCharacterStateComponent_Statics; \
public: \
	DECLARE_CLASS(UCharacterStateComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/NeonParadigm_Game"), NO_API) \
	DECLARE_SERIALIZER(UCharacterStateComponent)


#define FID__JHernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enums_CharacterStateComponent_h_26_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCharacterStateComponent(UCharacterStateComponent&&); \
	NO_API UCharacterStateComponent(const UCharacterStateComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCharacterStateComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCharacterStateComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCharacterStateComponent) \
	NO_API virtual ~UCharacterStateComponent();


#define FID__JHernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enums_CharacterStateComponent_h_23_PROLOG
#define FID__JHernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enums_CharacterStateComponent_h_26_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID__JHernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enums_CharacterStateComponent_h_26_SPARSE_DATA \
	FID__JHernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enums_CharacterStateComponent_h_26_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID__JHernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enums_CharacterStateComponent_h_26_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID__JHernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enums_CharacterStateComponent_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
	FID__JHernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enums_CharacterStateComponent_h_26_ACCESSORS \
	FID__JHernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enums_CharacterStateComponent_h_26_INCLASS_NO_PURE_DECLS \
	FID__JHernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enums_CharacterStateComponent_h_26_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> NEONPARADIGM_GAME_API UClass* StaticClass<class UCharacterStateComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID__JHernandez_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_Enums_CharacterStateComponent_h


#define FOREACH_ENUM_ECHARACTERSTATES(op) \
	op(ECharacterStates::None) \
	op(ECharacterStates::Attack) \
	op(ECharacterStates::Dodge) \
	op(ECharacterStates::Death) \
	op(ECharacterStates::Disabled) 

enum class ECharacterStates : uint8;
template<> struct TIsUEnumClass<ECharacterStates> { enum { Value = true }; };
template<> NEONPARADIGM_GAME_API UEnum* StaticEnum<ECharacterStates>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
