// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Experimental/ExperimentalCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeExperimentalCharacter() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
	EXPERIMENTAL_API UClass* Z_Construct_UClass_AExperimentalCharacter();
	EXPERIMENTAL_API UClass* Z_Construct_UClass_AExperimentalCharacter_NoRegister();
	EXPERIMENTAL_API UClass* Z_Construct_UClass_APickup_NoRegister();
	UPackage* Z_Construct_UPackage__Script_Experimental();
// End Cross Module References
	DEFINE_FUNCTION(AExperimentalCharacter::execQuitToMenu)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->QuitToMenu();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AExperimentalCharacter::execCloseOptions)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CloseOptions();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AExperimentalCharacter::execOpenOptions)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OpenOptions();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AExperimentalCharacter::execPauseGame)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->PauseGame();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AExperimentalCharacter::execUseItemAtInventorySlot)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_slot);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UseItemAtInventorySlot(Z_Param_slot);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AExperimentalCharacter::execGetItemDescriptionAtInventorySlot)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_slot);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetItemDescriptionAtInventorySlot(Z_Param_slot);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AExperimentalCharacter::execGetItemNameAtInventorySlot)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_slot);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetItemNameAtInventorySlot(Z_Param_slot);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AExperimentalCharacter::execGetThumbnailAtInventorySlot)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_slot);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UTexture2D**)Z_Param__Result=P_THIS->GetThumbnailAtInventorySlot(Z_Param_slot);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AExperimentalCharacter::execAddItemToInventory)
	{
		P_GET_OBJECT(APickup,Z_Param_Item);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->AddItemToInventory(Z_Param_Item);
		P_NATIVE_END;
	}
	void AExperimentalCharacter::StaticRegisterNativesAExperimentalCharacter()
	{
		UClass* Class = AExperimentalCharacter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddItemToInventory", &AExperimentalCharacter::execAddItemToInventory },
			{ "CloseOptions", &AExperimentalCharacter::execCloseOptions },
			{ "GetItemDescriptionAtInventorySlot", &AExperimentalCharacter::execGetItemDescriptionAtInventorySlot },
			{ "GetItemNameAtInventorySlot", &AExperimentalCharacter::execGetItemNameAtInventorySlot },
			{ "GetThumbnailAtInventorySlot", &AExperimentalCharacter::execGetThumbnailAtInventorySlot },
			{ "OpenOptions", &AExperimentalCharacter::execOpenOptions },
			{ "PauseGame", &AExperimentalCharacter::execPauseGame },
			{ "QuitToMenu", &AExperimentalCharacter::execQuitToMenu },
			{ "UseItemAtInventorySlot", &AExperimentalCharacter::execUseItemAtInventorySlot },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AExperimentalCharacter_AddItemToInventory_Statics
	{
		struct ExperimentalCharacter_eventAddItemToInventory_Parms
		{
			APickup* Item;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Item;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AExperimentalCharacter_AddItemToInventory_Statics::NewProp_Item = { "Item", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ExperimentalCharacter_eventAddItemToInventory_Parms, Item), Z_Construct_UClass_APickup_NoRegister, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_AExperimentalCharacter_AddItemToInventory_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((ExperimentalCharacter_eventAddItemToInventory_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AExperimentalCharacter_AddItemToInventory_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(ExperimentalCharacter_eventAddItemToInventory_Parms), &Z_Construct_UFunction_AExperimentalCharacter_AddItemToInventory_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AExperimentalCharacter_AddItemToInventory_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AExperimentalCharacter_AddItemToInventory_Statics::NewProp_Item,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AExperimentalCharacter_AddItemToInventory_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AExperimentalCharacter_AddItemToInventory_Statics::Function_MetaDataParams[] = {
		{ "Category", "Inventory Functions" },
		{ "Comment", "/*Adds an item to the inventory*/" },
		{ "ModuleRelativePath", "ExperimentalCharacter.h" },
		{ "ToolTip", "Adds an item to the inventory" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AExperimentalCharacter_AddItemToInventory_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AExperimentalCharacter, nullptr, "AddItemToInventory", nullptr, nullptr, sizeof(Z_Construct_UFunction_AExperimentalCharacter_AddItemToInventory_Statics::ExperimentalCharacter_eventAddItemToInventory_Parms), Z_Construct_UFunction_AExperimentalCharacter_AddItemToInventory_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AExperimentalCharacter_AddItemToInventory_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AExperimentalCharacter_AddItemToInventory_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AExperimentalCharacter_AddItemToInventory_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AExperimentalCharacter_AddItemToInventory()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AExperimentalCharacter_AddItemToInventory_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AExperimentalCharacter_CloseOptions_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AExperimentalCharacter_CloseOptions_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pause Menu" },
		{ "ModuleRelativePath", "ExperimentalCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AExperimentalCharacter_CloseOptions_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AExperimentalCharacter, nullptr, "CloseOptions", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AExperimentalCharacter_CloseOptions_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AExperimentalCharacter_CloseOptions_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AExperimentalCharacter_CloseOptions()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AExperimentalCharacter_CloseOptions_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AExperimentalCharacter_GetItemDescriptionAtInventorySlot_Statics
	{
		struct ExperimentalCharacter_eventGetItemDescriptionAtInventorySlot_Parms
		{
			int32 slot;
			FString ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_slot;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AExperimentalCharacter_GetItemDescriptionAtInventorySlot_Statics::NewProp_slot = { "slot", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ExperimentalCharacter_eventGetItemDescriptionAtInventorySlot_Parms, slot), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AExperimentalCharacter_GetItemDescriptionAtInventorySlot_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ExperimentalCharacter_eventGetItemDescriptionAtInventorySlot_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AExperimentalCharacter_GetItemDescriptionAtInventorySlot_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AExperimentalCharacter_GetItemDescriptionAtInventorySlot_Statics::NewProp_slot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AExperimentalCharacter_GetItemDescriptionAtInventorySlot_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AExperimentalCharacter_GetItemDescriptionAtInventorySlot_Statics::Function_MetaDataParams[] = {
		{ "Category", "Inventory Functions" },
		{ "Comment", "/*Gets the item description for a given inventory slot*/" },
		{ "ModuleRelativePath", "ExperimentalCharacter.h" },
		{ "ToolTip", "Gets the item description for a given inventory slot" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AExperimentalCharacter_GetItemDescriptionAtInventorySlot_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AExperimentalCharacter, nullptr, "GetItemDescriptionAtInventorySlot", nullptr, nullptr, sizeof(Z_Construct_UFunction_AExperimentalCharacter_GetItemDescriptionAtInventorySlot_Statics::ExperimentalCharacter_eventGetItemDescriptionAtInventorySlot_Parms), Z_Construct_UFunction_AExperimentalCharacter_GetItemDescriptionAtInventorySlot_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AExperimentalCharacter_GetItemDescriptionAtInventorySlot_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AExperimentalCharacter_GetItemDescriptionAtInventorySlot_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AExperimentalCharacter_GetItemDescriptionAtInventorySlot_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AExperimentalCharacter_GetItemDescriptionAtInventorySlot()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AExperimentalCharacter_GetItemDescriptionAtInventorySlot_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AExperimentalCharacter_GetItemNameAtInventorySlot_Statics
	{
		struct ExperimentalCharacter_eventGetItemNameAtInventorySlot_Parms
		{
			int32 slot;
			FString ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_slot;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AExperimentalCharacter_GetItemNameAtInventorySlot_Statics::NewProp_slot = { "slot", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ExperimentalCharacter_eventGetItemNameAtInventorySlot_Parms, slot), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AExperimentalCharacter_GetItemNameAtInventorySlot_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ExperimentalCharacter_eventGetItemNameAtInventorySlot_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AExperimentalCharacter_GetItemNameAtInventorySlot_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AExperimentalCharacter_GetItemNameAtInventorySlot_Statics::NewProp_slot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AExperimentalCharacter_GetItemNameAtInventorySlot_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AExperimentalCharacter_GetItemNameAtInventorySlot_Statics::Function_MetaDataParams[] = {
		{ "Category", "Inventory Functions" },
		{ "Comment", "/*Gets the item name for a given inventory slot*/" },
		{ "ModuleRelativePath", "ExperimentalCharacter.h" },
		{ "ToolTip", "Gets the item name for a given inventory slot" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AExperimentalCharacter_GetItemNameAtInventorySlot_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AExperimentalCharacter, nullptr, "GetItemNameAtInventorySlot", nullptr, nullptr, sizeof(Z_Construct_UFunction_AExperimentalCharacter_GetItemNameAtInventorySlot_Statics::ExperimentalCharacter_eventGetItemNameAtInventorySlot_Parms), Z_Construct_UFunction_AExperimentalCharacter_GetItemNameAtInventorySlot_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AExperimentalCharacter_GetItemNameAtInventorySlot_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AExperimentalCharacter_GetItemNameAtInventorySlot_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AExperimentalCharacter_GetItemNameAtInventorySlot_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AExperimentalCharacter_GetItemNameAtInventorySlot()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AExperimentalCharacter_GetItemNameAtInventorySlot_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AExperimentalCharacter_GetThumbnailAtInventorySlot_Statics
	{
		struct ExperimentalCharacter_eventGetThumbnailAtInventorySlot_Parms
		{
			int32 slot;
			UTexture2D* ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_slot;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AExperimentalCharacter_GetThumbnailAtInventorySlot_Statics::NewProp_slot = { "slot", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ExperimentalCharacter_eventGetThumbnailAtInventorySlot_Parms, slot), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AExperimentalCharacter_GetThumbnailAtInventorySlot_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ExperimentalCharacter_eventGetThumbnailAtInventorySlot_Parms, ReturnValue), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AExperimentalCharacter_GetThumbnailAtInventorySlot_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AExperimentalCharacter_GetThumbnailAtInventorySlot_Statics::NewProp_slot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AExperimentalCharacter_GetThumbnailAtInventorySlot_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AExperimentalCharacter_GetThumbnailAtInventorySlot_Statics::Function_MetaDataParams[] = {
		{ "Category", "Inventory Functions" },
		{ "Comment", "/*Gets the thumbnail for a given inventory slot*/" },
		{ "ModuleRelativePath", "ExperimentalCharacter.h" },
		{ "ToolTip", "Gets the thumbnail for a given inventory slot" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AExperimentalCharacter_GetThumbnailAtInventorySlot_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AExperimentalCharacter, nullptr, "GetThumbnailAtInventorySlot", nullptr, nullptr, sizeof(Z_Construct_UFunction_AExperimentalCharacter_GetThumbnailAtInventorySlot_Statics::ExperimentalCharacter_eventGetThumbnailAtInventorySlot_Parms), Z_Construct_UFunction_AExperimentalCharacter_GetThumbnailAtInventorySlot_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AExperimentalCharacter_GetThumbnailAtInventorySlot_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AExperimentalCharacter_GetThumbnailAtInventorySlot_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AExperimentalCharacter_GetThumbnailAtInventorySlot_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AExperimentalCharacter_GetThumbnailAtInventorySlot()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AExperimentalCharacter_GetThumbnailAtInventorySlot_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AExperimentalCharacter_OpenOptions_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AExperimentalCharacter_OpenOptions_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pause Menu" },
		{ "ModuleRelativePath", "ExperimentalCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AExperimentalCharacter_OpenOptions_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AExperimentalCharacter, nullptr, "OpenOptions", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AExperimentalCharacter_OpenOptions_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AExperimentalCharacter_OpenOptions_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AExperimentalCharacter_OpenOptions()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AExperimentalCharacter_OpenOptions_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AExperimentalCharacter_PauseGame_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AExperimentalCharacter_PauseGame_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pause Menu" },
		{ "ModuleRelativePath", "ExperimentalCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AExperimentalCharacter_PauseGame_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AExperimentalCharacter, nullptr, "PauseGame", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AExperimentalCharacter_PauseGame_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AExperimentalCharacter_PauseGame_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AExperimentalCharacter_PauseGame()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AExperimentalCharacter_PauseGame_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AExperimentalCharacter_QuitToMenu_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AExperimentalCharacter_QuitToMenu_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pause Menu" },
		{ "ModuleRelativePath", "ExperimentalCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AExperimentalCharacter_QuitToMenu_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AExperimentalCharacter, nullptr, "QuitToMenu", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AExperimentalCharacter_QuitToMenu_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AExperimentalCharacter_QuitToMenu_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AExperimentalCharacter_QuitToMenu()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AExperimentalCharacter_QuitToMenu_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AExperimentalCharacter_UseItemAtInventorySlot_Statics
	{
		struct ExperimentalCharacter_eventUseItemAtInventorySlot_Parms
		{
			int32 slot;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_slot;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AExperimentalCharacter_UseItemAtInventorySlot_Statics::NewProp_slot = { "slot", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ExperimentalCharacter_eventUseItemAtInventorySlot_Parms, slot), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AExperimentalCharacter_UseItemAtInventorySlot_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AExperimentalCharacter_UseItemAtInventorySlot_Statics::NewProp_slot,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AExperimentalCharacter_UseItemAtInventorySlot_Statics::Function_MetaDataParams[] = {
		{ "Category", "Inventory Functions" },
		{ "Comment", "/*Uses the item at a given inventory slot*/" },
		{ "ModuleRelativePath", "ExperimentalCharacter.h" },
		{ "ToolTip", "Uses the item at a given inventory slot" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AExperimentalCharacter_UseItemAtInventorySlot_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AExperimentalCharacter, nullptr, "UseItemAtInventorySlot", nullptr, nullptr, sizeof(Z_Construct_UFunction_AExperimentalCharacter_UseItemAtInventorySlot_Statics::ExperimentalCharacter_eventUseItemAtInventorySlot_Parms), Z_Construct_UFunction_AExperimentalCharacter_UseItemAtInventorySlot_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AExperimentalCharacter_UseItemAtInventorySlot_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AExperimentalCharacter_UseItemAtInventorySlot_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AExperimentalCharacter_UseItemAtInventorySlot_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AExperimentalCharacter_UseItemAtInventorySlot()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AExperimentalCharacter_UseItemAtInventorySlot_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AExperimentalCharacter);
	UClass* Z_Construct_UClass_AExperimentalCharacter_NoRegister()
	{
		return AExperimentalCharacter::StaticClass();
	}
	struct Z_Construct_UClass_AExperimentalCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FollowCamera_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_FollowCamera;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultMappingContext_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultMappingContext;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_JumpAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ToggleInventoryAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ToggleInventoryAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InteractAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InteractAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MoveAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LookAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LookAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PauseAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PauseAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MapAreaAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MapAreaAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TestAreaAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TestAreaAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_helpText_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_helpText;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_reach_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_reach;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bDeniedText_MetaData[];
#endif
		static void NewProp_bDeniedText_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bDeniedText;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_inventory_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_inventory_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_inventory;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_inventoryLimit_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_inventoryLimit;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AExperimentalCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_Experimental,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AExperimentalCharacter_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AExperimentalCharacter_AddItemToInventory, "AddItemToInventory" }, // 2205691492
		{ &Z_Construct_UFunction_AExperimentalCharacter_CloseOptions, "CloseOptions" }, // 2227866754
		{ &Z_Construct_UFunction_AExperimentalCharacter_GetItemDescriptionAtInventorySlot, "GetItemDescriptionAtInventorySlot" }, // 1032189938
		{ &Z_Construct_UFunction_AExperimentalCharacter_GetItemNameAtInventorySlot, "GetItemNameAtInventorySlot" }, // 3477186095
		{ &Z_Construct_UFunction_AExperimentalCharacter_GetThumbnailAtInventorySlot, "GetThumbnailAtInventorySlot" }, // 2248187567
		{ &Z_Construct_UFunction_AExperimentalCharacter_OpenOptions, "OpenOptions" }, // 1095216857
		{ &Z_Construct_UFunction_AExperimentalCharacter_PauseGame, "PauseGame" }, // 1290840269
		{ &Z_Construct_UFunction_AExperimentalCharacter_QuitToMenu, "QuitToMenu" }, // 970242395
		{ &Z_Construct_UFunction_AExperimentalCharacter_UseItemAtInventorySlot, "UseItemAtInventorySlot" }, // 2077065690
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AExperimentalCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "ExperimentalCharacter.h" },
		{ "ModuleRelativePath", "ExperimentalCharacter.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_CameraBoom_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/** Camera boom positioning the camera behind the character */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ExperimentalCharacter.h" },
		{ "ToolTip", "Camera boom positioning the camera behind the character" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AExperimentalCharacter, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_CameraBoom_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_CameraBoom_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_FollowCamera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/** Follow camera */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ExperimentalCharacter.h" },
		{ "ToolTip", "Follow camera" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_FollowCamera = { "FollowCamera", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AExperimentalCharacter, FollowCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_FollowCamera_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_FollowCamera_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_DefaultMappingContext_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "Comment", "/** MappingContext */" },
		{ "ModuleRelativePath", "ExperimentalCharacter.h" },
		{ "ToolTip", "MappingContext" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_DefaultMappingContext = { "DefaultMappingContext", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AExperimentalCharacter, DefaultMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_DefaultMappingContext_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_DefaultMappingContext_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_JumpAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "Comment", "/** Jump Input Action */" },
		{ "ModuleRelativePath", "ExperimentalCharacter.h" },
		{ "ToolTip", "Jump Input Action" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_JumpAction = { "JumpAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AExperimentalCharacter, JumpAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_JumpAction_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_JumpAction_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_ToggleInventoryAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "Comment", "/*Toggle inventory input action*/" },
		{ "ModuleRelativePath", "ExperimentalCharacter.h" },
		{ "ToolTip", "Toggle inventory input action" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_ToggleInventoryAction = { "ToggleInventoryAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AExperimentalCharacter, ToggleInventoryAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_ToggleInventoryAction_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_ToggleInventoryAction_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_InteractAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "Comment", "/*Interact input action*/" },
		{ "ModuleRelativePath", "ExperimentalCharacter.h" },
		{ "ToolTip", "Interact input action" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_InteractAction = { "InteractAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AExperimentalCharacter, InteractAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_InteractAction_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_InteractAction_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_MoveAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "Comment", "/** Move Input Action */" },
		{ "ModuleRelativePath", "ExperimentalCharacter.h" },
		{ "ToolTip", "Move Input Action" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_MoveAction = { "MoveAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AExperimentalCharacter, MoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_MoveAction_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_MoveAction_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_LookAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "Comment", "/** Look Input Action */" },
		{ "ModuleRelativePath", "ExperimentalCharacter.h" },
		{ "ToolTip", "Look Input Action" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_LookAction = { "LookAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AExperimentalCharacter, LookAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_LookAction_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_LookAction_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_PauseAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "Comment", "/** Look Input Action */" },
		{ "ModuleRelativePath", "ExperimentalCharacter.h" },
		{ "ToolTip", "Look Input Action" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_PauseAction = { "PauseAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AExperimentalCharacter, PauseAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_PauseAction_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_PauseAction_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_MapAreaAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "ExperimentalCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_MapAreaAction = { "MapAreaAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AExperimentalCharacter, MapAreaAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_MapAreaAction_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_MapAreaAction_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_TestAreaAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "ExperimentalCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_TestAreaAction = { "TestAreaAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AExperimentalCharacter, TestAreaAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_TestAreaAction_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_TestAreaAction_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_helpText_MetaData[] = {
		{ "Category", "HUD" },
		{ "Comment", "/*The players help text*/" },
		{ "ModuleRelativePath", "ExperimentalCharacter.h" },
		{ "ToolTip", "The players help text" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_helpText = { "helpText", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AExperimentalCharacter, helpText), METADATA_PARAMS(Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_helpText_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_helpText_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_reach_MetaData[] = {
		{ "Category", "Inventory Functions" },
		{ "Comment", "/*How close the player needs to be to the pickup*/" },
		{ "ModuleRelativePath", "ExperimentalCharacter.h" },
		{ "ToolTip", "How close the player needs to be to the pickup" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_reach = { "reach", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AExperimentalCharacter, reach), METADATA_PARAMS(Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_reach_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_reach_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_bDeniedText_MetaData[] = {
		{ "Category", "Inventory Functions" },
		{ "Comment", "/*Variable which represents the player not being able to pick up a third object*/" },
		{ "ModuleRelativePath", "ExperimentalCharacter.h" },
		{ "ToolTip", "Variable which represents the player not being able to pick up a third object" },
	};
#endif
	void Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_bDeniedText_SetBit(void* Obj)
	{
		((AExperimentalCharacter*)Obj)->bDeniedText = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_bDeniedText = { "bDeniedText", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(AExperimentalCharacter), &Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_bDeniedText_SetBit, METADATA_PARAMS(Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_bDeniedText_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_bDeniedText_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_inventory_Inner = { "inventory", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UClass_APickup_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_inventory_MetaData[] = {
		{ "Category", "ExperimentalCharacter" },
		{ "Comment", "/*The players inventory, represented as a tarray of pickup objects*/" },
		{ "ModuleRelativePath", "ExperimentalCharacter.h" },
		{ "ToolTip", "The players inventory, represented as a tarray of pickup objects" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_inventory = { "inventory", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AExperimentalCharacter, inventory), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_inventory_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_inventory_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_inventoryLimit_MetaData[] = {
		{ "Category", "Inventory Functions" },
		{ "Comment", "/*How many items can be in the inventory*/" },
		{ "ModuleRelativePath", "ExperimentalCharacter.h" },
		{ "ToolTip", "How many items can be in the inventory" },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_inventoryLimit = { "inventoryLimit", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AExperimentalCharacter, inventoryLimit), METADATA_PARAMS(Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_inventoryLimit_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_inventoryLimit_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AExperimentalCharacter_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_CameraBoom,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_FollowCamera,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_DefaultMappingContext,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_JumpAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_ToggleInventoryAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_InteractAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_MoveAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_LookAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_PauseAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_MapAreaAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_TestAreaAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_helpText,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_reach,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_bDeniedText,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_inventory_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_inventory,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AExperimentalCharacter_Statics::NewProp_inventoryLimit,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AExperimentalCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AExperimentalCharacter>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AExperimentalCharacter_Statics::ClassParams = {
		&AExperimentalCharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AExperimentalCharacter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AExperimentalCharacter_Statics::PropPointers),
		0,
		0x008000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AExperimentalCharacter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AExperimentalCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AExperimentalCharacter()
	{
		if (!Z_Registration_Info_UClass_AExperimentalCharacter.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AExperimentalCharacter.OuterSingleton, Z_Construct_UClass_AExperimentalCharacter_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AExperimentalCharacter.OuterSingleton;
	}
	template<> EXPERIMENTAL_API UClass* StaticClass<AExperimentalCharacter>()
	{
		return AExperimentalCharacter::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AExperimentalCharacter);
	AExperimentalCharacter::~AExperimentalCharacter() {}
	struct Z_CompiledInDeferFile_FID_Experimental_Source_Experimental_ExperimentalCharacter_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Experimental_Source_Experimental_ExperimentalCharacter_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AExperimentalCharacter, AExperimentalCharacter::StaticClass, TEXT("AExperimentalCharacter"), &Z_Registration_Info_UClass_AExperimentalCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AExperimentalCharacter), 792367705U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Experimental_Source_Experimental_ExperimentalCharacter_h_2447852040(TEXT("/Script/Experimental"),
		Z_CompiledInDeferFile_FID_Experimental_Source_Experimental_ExperimentalCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Experimental_Source_Experimental_ExperimentalCharacter_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
