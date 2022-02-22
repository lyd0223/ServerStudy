// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef UNREALCLIENT_PlayerClientCharacter_generated_h
#error "PlayerClientCharacter.generated.h already included, missing '#pragma once' in PlayerClientCharacter.h"
#endif
#define UNREALCLIENT_PlayerClientCharacter_generated_h

#define UnrealClient_Source_UnrealClient_Main_Character_Player_PlayerClientCharacter_h_15_SPARSE_DATA
#define UnrealClient_Source_UnrealClient_Main_Character_Player_PlayerClientCharacter_h_15_RPC_WRAPPERS
#define UnrealClient_Source_UnrealClient_Main_Character_Player_PlayerClientCharacter_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define UnrealClient_Source_UnrealClient_Main_Character_Player_PlayerClientCharacter_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPlayerClientCharacter(); \
	friend struct Z_Construct_UClass_APlayerClientCharacter_Statics; \
public: \
	DECLARE_CLASS(APlayerClientCharacter, AClientCharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/UnrealClient"), NO_API) \
	DECLARE_SERIALIZER(APlayerClientCharacter)


#define UnrealClient_Source_UnrealClient_Main_Character_Player_PlayerClientCharacter_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAPlayerClientCharacter(); \
	friend struct Z_Construct_UClass_APlayerClientCharacter_Statics; \
public: \
	DECLARE_CLASS(APlayerClientCharacter, AClientCharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/UnrealClient"), NO_API) \
	DECLARE_SERIALIZER(APlayerClientCharacter)


#define UnrealClient_Source_UnrealClient_Main_Character_Player_PlayerClientCharacter_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APlayerClientCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APlayerClientCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlayerClientCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlayerClientCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APlayerClientCharacter(APlayerClientCharacter&&); \
	NO_API APlayerClientCharacter(const APlayerClientCharacter&); \
public:


#define UnrealClient_Source_UnrealClient_Main_Character_Player_PlayerClientCharacter_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APlayerClientCharacter(APlayerClientCharacter&&); \
	NO_API APlayerClientCharacter(const APlayerClientCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlayerClientCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlayerClientCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APlayerClientCharacter)


#define UnrealClient_Source_UnrealClient_Main_Character_Player_PlayerClientCharacter_h_15_PRIVATE_PROPERTY_OFFSET
#define UnrealClient_Source_UnrealClient_Main_Character_Player_PlayerClientCharacter_h_12_PROLOG
#define UnrealClient_Source_UnrealClient_Main_Character_Player_PlayerClientCharacter_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UnrealClient_Source_UnrealClient_Main_Character_Player_PlayerClientCharacter_h_15_PRIVATE_PROPERTY_OFFSET \
	UnrealClient_Source_UnrealClient_Main_Character_Player_PlayerClientCharacter_h_15_SPARSE_DATA \
	UnrealClient_Source_UnrealClient_Main_Character_Player_PlayerClientCharacter_h_15_RPC_WRAPPERS \
	UnrealClient_Source_UnrealClient_Main_Character_Player_PlayerClientCharacter_h_15_INCLASS \
	UnrealClient_Source_UnrealClient_Main_Character_Player_PlayerClientCharacter_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UnrealClient_Source_UnrealClient_Main_Character_Player_PlayerClientCharacter_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UnrealClient_Source_UnrealClient_Main_Character_Player_PlayerClientCharacter_h_15_PRIVATE_PROPERTY_OFFSET \
	UnrealClient_Source_UnrealClient_Main_Character_Player_PlayerClientCharacter_h_15_SPARSE_DATA \
	UnrealClient_Source_UnrealClient_Main_Character_Player_PlayerClientCharacter_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	UnrealClient_Source_UnrealClient_Main_Character_Player_PlayerClientCharacter_h_15_INCLASS_NO_PURE_DECLS \
	UnrealClient_Source_UnrealClient_Main_Character_Player_PlayerClientCharacter_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UNREALCLIENT_API UClass* StaticClass<class APlayerClientCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UnrealClient_Source_UnrealClient_Main_Character_Player_PlayerClientCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
