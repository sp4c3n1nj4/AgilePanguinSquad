// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Experimental/Pickup.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePickup() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	EXPERIMENTAL_API UClass* Z_Construct_UClass_AInteractable();
	EXPERIMENTAL_API UClass* Z_Construct_UClass_APickup();
	EXPERIMENTAL_API UClass* Z_Construct_UClass_APickup_NoRegister();
	UPackage* Z_Construct_UPackage__Script_Experimental();
// End Cross Module References
	DEFINE_FUNCTION(APickup::execUse)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Use_Implementation();
		P_NATIVE_END;
	}
	static FName NAME_APickup_Use = FName(TEXT("Use"));
	void APickup::Use()
	{
		ProcessEvent(FindFunctionChecked(NAME_APickup_Use),NULL);
	}
	void APickup::StaticRegisterNativesAPickup()
	{
		UClass* Class = APickup::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Use", &APickup::execUse },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_APickup_Use_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APickup_Use_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Pickup.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APickup_Use_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APickup, nullptr, "Use", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_APickup_Use_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_APickup_Use_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_APickup_Use()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APickup_Use_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(APickup);
	UClass* Z_Construct_UClass_APickup_NoRegister()
	{
		return APickup::StaticClass();
	}
	struct Z_Construct_UClass_APickup_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_pickupThumbnail_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_pickupThumbnail;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_itemName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_itemName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_itemAction_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_itemAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_itemDescription_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_itemDescription;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APickup_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AInteractable,
		(UObject* (*)())Z_Construct_UPackage__Script_Experimental,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_APickup_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_APickup_Use, "Use" }, // 1792913067
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APickup_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Pickup.h" },
		{ "ModuleRelativePath", "Pickup.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APickup_Statics::NewProp_pickupThumbnail_MetaData[] = {
		{ "Category", "Pickup Properties" },
		{ "Comment", "/*Item image*/" },
		{ "ModuleRelativePath", "Pickup.h" },
		{ "ToolTip", "Item image" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APickup_Statics::NewProp_pickupThumbnail = { "pickupThumbnail", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(APickup, pickupThumbnail), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(Z_Construct_UClass_APickup_Statics::NewProp_pickupThumbnail_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APickup_Statics::NewProp_pickupThumbnail_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APickup_Statics::NewProp_itemName_MetaData[] = {
		{ "Category", "Pickup Properties" },
		{ "Comment", "/*Item name*/" },
		{ "ModuleRelativePath", "Pickup.h" },
		{ "ToolTip", "Item name" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_APickup_Statics::NewProp_itemName = { "itemName", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(APickup, itemName), METADATA_PARAMS(Z_Construct_UClass_APickup_Statics::NewProp_itemName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APickup_Statics::NewProp_itemName_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APickup_Statics::NewProp_itemAction_MetaData[] = {
		{ "Category", "Pickup Properties" },
		{ "ModuleRelativePath", "Pickup.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_APickup_Statics::NewProp_itemAction = { "itemAction", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(APickup, itemAction), METADATA_PARAMS(Z_Construct_UClass_APickup_Statics::NewProp_itemAction_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APickup_Statics::NewProp_itemAction_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APickup_Statics::NewProp_itemDescription_MetaData[] = {
		{ "Category", "Pickup Properties" },
		{ "ModuleRelativePath", "Pickup.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_APickup_Statics::NewProp_itemDescription = { "itemDescription", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(APickup, itemDescription), METADATA_PARAMS(Z_Construct_UClass_APickup_Statics::NewProp_itemDescription_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APickup_Statics::NewProp_itemDescription_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APickup_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APickup_Statics::NewProp_pickupThumbnail,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APickup_Statics::NewProp_itemName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APickup_Statics::NewProp_itemAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APickup_Statics::NewProp_itemDescription,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_APickup_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APickup>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_APickup_Statics::ClassParams = {
		&APickup::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_APickup_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_APickup_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_APickup_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APickup_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APickup()
	{
		if (!Z_Registration_Info_UClass_APickup.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APickup.OuterSingleton, Z_Construct_UClass_APickup_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_APickup.OuterSingleton;
	}
	template<> EXPERIMENTAL_API UClass* StaticClass<APickup>()
	{
		return APickup::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(APickup);
	APickup::~APickup() {}
	struct Z_CompiledInDeferFile_FID_Experimental_Source_Experimental_Pickup_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Experimental_Source_Experimental_Pickup_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_APickup, APickup::StaticClass, TEXT("APickup"), &Z_Registration_Info_UClass_APickup, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APickup), 1007801223U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Experimental_Source_Experimental_Pickup_h_1287040574(TEXT("/Script/Experimental"),
		Z_CompiledInDeferFile_FID_Experimental_Source_Experimental_Pickup_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Experimental_Source_Experimental_Pickup_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
