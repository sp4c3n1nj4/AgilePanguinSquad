// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Pickup.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef EXPERIMENTAL_Pickup_generated_h
#error "Pickup.generated.h already included, missing '#pragma once' in Pickup.h"
#endif
#define EXPERIMENTAL_Pickup_generated_h

#define FID_Experimental_Source_Experimental_Pickup_h_15_SPARSE_DATA
#define FID_Experimental_Source_Experimental_Pickup_h_15_RPC_WRAPPERS \
	virtual void Use_Implementation(); \
 \
	DECLARE_FUNCTION(execUse);


#define FID_Experimental_Source_Experimental_Pickup_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execUse);


#define FID_Experimental_Source_Experimental_Pickup_h_15_ACCESSORS
#define FID_Experimental_Source_Experimental_Pickup_h_15_CALLBACK_WRAPPERS
#define FID_Experimental_Source_Experimental_Pickup_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPickup(); \
	friend struct Z_Construct_UClass_APickup_Statics; \
public: \
	DECLARE_CLASS(APickup, AInteractable, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Experimental"), NO_API) \
	DECLARE_SERIALIZER(APickup)


#define FID_Experimental_Source_Experimental_Pickup_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAPickup(); \
	friend struct Z_Construct_UClass_APickup_Statics; \
public: \
	DECLARE_CLASS(APickup, AInteractable, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Experimental"), NO_API) \
	DECLARE_SERIALIZER(APickup)


#define FID_Experimental_Source_Experimental_Pickup_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APickup(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APickup) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APickup); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APickup); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APickup(APickup&&); \
	NO_API APickup(const APickup&); \
public: \
	NO_API virtual ~APickup();


#define FID_Experimental_Source_Experimental_Pickup_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APickup(APickup&&); \
	NO_API APickup(const APickup&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APickup); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APickup); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APickup) \
	NO_API virtual ~APickup();


#define FID_Experimental_Source_Experimental_Pickup_h_12_PROLOG
#define FID_Experimental_Source_Experimental_Pickup_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Experimental_Source_Experimental_Pickup_h_15_SPARSE_DATA \
	FID_Experimental_Source_Experimental_Pickup_h_15_RPC_WRAPPERS \
	FID_Experimental_Source_Experimental_Pickup_h_15_ACCESSORS \
	FID_Experimental_Source_Experimental_Pickup_h_15_CALLBACK_WRAPPERS \
	FID_Experimental_Source_Experimental_Pickup_h_15_INCLASS \
	FID_Experimental_Source_Experimental_Pickup_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Experimental_Source_Experimental_Pickup_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Experimental_Source_Experimental_Pickup_h_15_SPARSE_DATA \
	FID_Experimental_Source_Experimental_Pickup_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Experimental_Source_Experimental_Pickup_h_15_ACCESSORS \
	FID_Experimental_Source_Experimental_Pickup_h_15_CALLBACK_WRAPPERS \
	FID_Experimental_Source_Experimental_Pickup_h_15_INCLASS_NO_PURE_DECLS \
	FID_Experimental_Source_Experimental_Pickup_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> EXPERIMENTAL_API UClass* StaticClass<class APickup>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Experimental_Source_Experimental_Pickup_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
