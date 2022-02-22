// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef UNREALCLIENT_MainGameMode_generated_h
#error "MainGameMode.generated.h already included, missing '#pragma once' in MainGameMode.h"
#endif
#define UNREALCLIENT_MainGameMode_generated_h

#define UnrealClient_Source_UnrealClient_Main_MainGameMode_h_11_SPARSE_DATA
#define UnrealClient_Source_UnrealClient_Main_MainGameMode_h_11_RPC_WRAPPERS
#define UnrealClient_Source_UnrealClient_Main_MainGameMode_h_11_RPC_WRAPPERS_NO_PURE_DECLS
#define UnrealClient_Source_UnrealClient_Main_MainGameMode_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMainGameMode(); \
	friend struct Z_Construct_UClass_AMainGameMode_Statics; \
public: \
	DECLARE_CLASS(AMainGameMode, AGameMode, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/UnrealClient"), NO_API) \
	DECLARE_SERIALIZER(AMainGameMode)


#define UnrealClient_Source_UnrealClient_Main_MainGameMode_h_11_INCLASS \
private: \
	static void StaticRegisterNativesAMainGameMode(); \
	friend struct Z_Construct_UClass_AMainGameMode_Statics; \
public: \
	DECLARE_CLASS(AMainGameMode, AGameMode, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/UnrealClient"), NO_API) \
	DECLARE_SERIALIZER(AMainGameMode)


#define UnrealClient_Source_UnrealClient_Main_MainGameMode_h_11_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMainGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMainGameMode) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMainGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMainGameMode); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMainGameMode(AMainGameMode&&); \
	NO_API AMainGameMode(const AMainGameMode&); \
public:


#define UnrealClient_Source_UnrealClient_Main_MainGameMode_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMainGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMainGameMode(AMainGameMode&&); \
	NO_API AMainGameMode(const AMainGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMainGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMainGameMode); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMainGameMode)


#define UnrealClient_Source_UnrealClient_Main_MainGameMode_h_11_PRIVATE_PROPERTY_OFFSET
#define UnrealClient_Source_UnrealClient_Main_MainGameMode_h_8_PROLOG
#define UnrealClient_Source_UnrealClient_Main_MainGameMode_h_11_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UnrealClient_Source_UnrealClient_Main_MainGameMode_h_11_PRIVATE_PROPERTY_OFFSET \
	UnrealClient_Source_UnrealClient_Main_MainGameMode_h_11_SPARSE_DATA \
	UnrealClient_Source_UnrealClient_Main_MainGameMode_h_11_RPC_WRAPPERS \
	UnrealClient_Source_UnrealClient_Main_MainGameMode_h_11_INCLASS \
	UnrealClient_Source_UnrealClient_Main_MainGameMode_h_11_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UnrealClient_Source_UnrealClient_Main_MainGameMode_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UnrealClient_Source_UnrealClient_Main_MainGameMode_h_11_PRIVATE_PROPERTY_OFFSET \
	UnrealClient_Source_UnrealClient_Main_MainGameMode_h_11_SPARSE_DATA \
	UnrealClient_Source_UnrealClient_Main_MainGameMode_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	UnrealClient_Source_UnrealClient_Main_MainGameMode_h_11_INCLASS_NO_PURE_DECLS \
	UnrealClient_Source_UnrealClient_Main_MainGameMode_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UNREALCLIENT_API UClass* StaticClass<class AMainGameMode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UnrealClient_Source_UnrealClient_Main_MainGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
