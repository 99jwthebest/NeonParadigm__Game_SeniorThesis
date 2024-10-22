// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DamageType/NP_DamageType.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef NEONPARADIGM_GAME_NP_DamageType_generated_h
#error "NP_DamageType.generated.h already included, missing '#pragma once' in NP_DamageType.h"
#endif
#define NEONPARADIGM_GAME_NP_DamageType_generated_h

#define FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_DamageType_NP_DamageType_h_28_SPARSE_DATA
#define FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_DamageType_NP_DamageType_h_28_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_DamageType_NP_DamageType_h_28_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_DamageType_NP_DamageType_h_28_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_DamageType_NP_DamageType_h_28_ACCESSORS
#define FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_DamageType_NP_DamageType_h_28_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUNP_DamageType(); \
	friend struct Z_Construct_UClass_UNP_DamageType_Statics; \
public: \
	DECLARE_CLASS(UNP_DamageType, UDamageType, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/NeonParadigm_Game"), NO_API) \
	DECLARE_SERIALIZER(UNP_DamageType)


#define FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_DamageType_NP_DamageType_h_28_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UNP_DamageType(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UNP_DamageType(UNP_DamageType&&); \
	NO_API UNP_DamageType(const UNP_DamageType&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UNP_DamageType); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UNP_DamageType); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UNP_DamageType) \
	NO_API virtual ~UNP_DamageType();


#define FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_DamageType_NP_DamageType_h_25_PROLOG
#define FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_DamageType_NP_DamageType_h_28_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_DamageType_NP_DamageType_h_28_SPARSE_DATA \
	FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_DamageType_NP_DamageType_h_28_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_DamageType_NP_DamageType_h_28_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_DamageType_NP_DamageType_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_DamageType_NP_DamageType_h_28_ACCESSORS \
	FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_DamageType_NP_DamageType_h_28_INCLASS_NO_PURE_DECLS \
	FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_DamageType_NP_DamageType_h_28_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> NEONPARADIGM_GAME_API UClass* StaticClass<class UNP_DamageType>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_josep_Documents_Unreal_Projects_NeonParadigm__Game_SeniorThesis_NeonParadigm_Game_Source_NeonParadigm_Game_DamageType_NP_DamageType_h


#define FOREACH_ENUM_EDAMAGETYPES(op) \
	op(EDamageTypes::Default) \
	op(EDamageTypes::Right) \
	op(EDamageTypes::Left) \
	op(EDamageTypes::Middle) \
	op(EDamageTypes::Knockdown) \
	op(EDamageTypes::Knockback) \
	op(EDamageTypes::Launch) 

enum class EDamageTypes : uint8;
template<> struct TIsUEnumClass<EDamageTypes> { enum { Value = true }; };
template<> NEONPARADIGM_GAME_API UEnum* StaticEnum<EDamageTypes>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
