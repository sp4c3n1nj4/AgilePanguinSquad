// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ExperimentalCharacter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class APickup;
class UTexture2D;
#ifdef EXPERIMENTAL_ExperimentalCharacter_generated_h
#error "ExperimentalCharacter.generated.h already included, missing '#pragma once' in ExperimentalCharacter.h"
#endif
#define EXPERIMENTAL_ExperimentalCharacter_generated_h

#define FID_Experimental_Source_Experimental_ExperimentalCharacter_h_16_SPARSE_DATA
#define FID_Experimental_Source_Experimental_ExperimentalCharacter_h_16_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execQuitToMenu); \
	DECLARE_FUNCTION(execCloseOptions); \
	DECLARE_FUNCTION(execOpenOptions); \
	DECLARE_FUNCTION(execPauseGame); \
	DECLARE_FUNCTION(execUseItemAtInventorySlot); \
	DECLARE_FUNCTION(execGetItemDescriptionAtInventorySlot); \
	DECLARE_FUNCTION(execGetItemNameAtInventorySlot); \
	DECLARE_FUNCTION(execGetThumbnailAtInventorySlot); \
	DECLARE_FUNCTION(execAddItemToInventory);


#define FID_Experimental_Source_Experimental_ExperimentalCharacter_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execQuitToMenu); \
	DECLARE_FUNCTION(execCloseOptions); \
	DECLARE_FUNCTION(execOpenOptions); \
	DECLARE_FUNCTION(execPauseGame); \
	DECLARE_FUNCTION(execUseItemAtInventorySlot); \
	DECLARE_FUNCTION(execGetItemDescriptionAtInventorySlot); \
	DECLARE_FUNCTION(execGetItemNameAtInventorySlot); \
	DECLARE_FUNCTION(execGetThumbnailAtInventorySlot); \
	DECLARE_FUNCTION(execAddItemToInventory);


#define FID_Experimental_Source_Experimental_ExperimentalCharacter_h_16_ACCESSORS
#define FID_Experimental_Source_Experimental_ExperimentalCharacter_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAExperimentalCharacter(); \
	friend struct Z_Construct_UClass_AExperimentalCharacter_Statics; \
public: \
	DECLARE_CLASS(AExperimentalCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Experimental"), NO_API) \
	DECLARE_SERIALIZER(AExperimentalCharacter)


#define FID_Experimental_Source_Experimental_ExperimentalCharacter_h_16_INCLASS \
private: \
	static void StaticRegisterNativesAExperimentalCharacter(); \
	friend struct Z_Construct_UClass_AExperimentalCharacter_Statics; \
public: \
	DECLARE_CLASS(AExperimentalCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Experimental"), NO_API) \
	DECLARE_SERIALIZER(AExperimentalCharacter)


#define FID_Experimental_Source_Experimental_ExperimentalCharacter_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AExperimentalCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AExperimentalCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AExperimentalCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AExperimentalCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AExperimentalCharacter(AExperimentalCharacter&&); \
	NO_API AExperimentalCharacter(const AExperimentalCharacter&); \
public: \
	NO_API virtual ~AExperimentalCharacter();


#define FID_Experimental_Source_Experimental_ExperimentalCharacter_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AExperimentalCharacter(AExperimentalCharacter&&); \
	NO_API AExperimentalCharacter(const AExperimentalCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AExperimentalCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AExperimentalCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AExperimentalCharacter) \
	NO_API virtual ~AExperimentalCharacter();


#define FID_Experimental_Source_Experimental_ExperimentalCharacter_h_13_PROLOG
#define FID_Experimental_Source_Experimental_ExperimentalCharacter_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Experimental_Source_Experimental_ExperimentalCharacter_h_16_SPARSE_DATA \
	FID_Experimental_Source_Experimental_ExperimentalCharacter_h_16_RPC_WRAPPERS \
	FID_Experimental_Source_Experimental_ExperimentalCharacter_h_16_ACCESSORS \
	FID_Experimental_Source_Experimental_ExperimentalCharacter_h_16_INCLASS \
	FID_Experimental_Source_Experimental_ExperimentalCharacter_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Experimental_Source_Experimental_ExperimentalCharacter_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Experimental_Source_Experimental_ExperimentalCharacter_h_16_SPARSE_DATA \
	FID_Experimental_Source_Experimental_ExperimentalCharacter_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Experimental_Source_Experimental_ExperimentalCharacter_h_16_ACCESSORS \
	FID_Experimental_Source_Experimental_ExperimentalCharacter_h_16_INCLASS_NO_PURE_DECLS \
	FID_Experimental_Source_Experimental_ExperimentalCharacter_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> EXPERIMENTAL_API UClass* StaticClass<class AExperimentalCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Experimental_Source_Experimental_ExperimentalCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
