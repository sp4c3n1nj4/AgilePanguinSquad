// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Experimental/Interactable.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInteractable() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	EXPERIMENTAL_API UClass* Z_Construct_UClass_AInteractable();
	EXPERIMENTAL_API UClass* Z_Construct_UClass_AInteractable_NoRegister();
	UPackage* Z_Construct_UPackage__Script_Experimental();
// End Cross Module References
	DEFINE_FUNCTION(AInteractable::execInteract)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Interact_Implementation();
		P_NATIVE_END;
	}
	static FName NAME_AInteractable_Interact = FName(TEXT("Interact"));
	void AInteractable::Interact()
	{
		ProcessEvent(FindFunctionChecked(NAME_AInteractable_Interact),NULL);
	}
	void AInteractable::StaticRegisterNativesAInteractable()
	{
		UClass* Class = AInteractable::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Interact", &AInteractable::execInteract },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AInteractable_Interact_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AInteractable_Interact_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/*Allows this function to be overriden whilst keeping the implementation*/" },
		{ "ModuleRelativePath", "Interactable.h" },
		{ "ToolTip", "Allows this function to be overriden whilst keeping the implementation" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AInteractable_Interact_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AInteractable, nullptr, "Interact", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AInteractable_Interact_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AInteractable_Interact_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AInteractable_Interact()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AInteractable_Interact_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AInteractable);
	UClass* Z_Construct_UClass_AInteractable_NoRegister()
	{
		return AInteractable::StaticClass();
	}
	struct Z_Construct_UClass_AInteractable_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_interactableHelpText_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_interactableHelpText;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_interactableMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_interactableMesh;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AInteractable_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Experimental,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AInteractable_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AInteractable_Interact, "Interact" }, // 859970014
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AInteractable_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Interactable.h" },
		{ "ModuleRelativePath", "Interactable.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AInteractable_Statics::NewProp_interactableHelpText_MetaData[] = {
		{ "Category", "Interact Properties" },
		{ "Comment", "/*Assuming all interactables have help text*/" },
		{ "ModuleRelativePath", "Interactable.h" },
		{ "ToolTip", "Assuming all interactables have help text" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AInteractable_Statics::NewProp_interactableHelpText = { "interactableHelpText", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AInteractable, interactableHelpText), METADATA_PARAMS(Z_Construct_UClass_AInteractable_Statics::NewProp_interactableHelpText_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AInteractable_Statics::NewProp_interactableHelpText_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AInteractable_Statics::NewProp_interactableMesh_MetaData[] = {
		{ "Category", "Interact Properties" },
		{ "Comment", "/*Assuming all interactables have a mesh*/" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Interactable.h" },
		{ "ToolTip", "Assuming all interactables have a mesh" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AInteractable_Statics::NewProp_interactableMesh = { "interactableMesh", nullptr, (EPropertyFlags)0x0020080000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AInteractable, interactableMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AInteractable_Statics::NewProp_interactableMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AInteractable_Statics::NewProp_interactableMesh_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AInteractable_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AInteractable_Statics::NewProp_interactableHelpText,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AInteractable_Statics::NewProp_interactableMesh,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AInteractable_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AInteractable>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AInteractable_Statics::ClassParams = {
		&AInteractable::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AInteractable_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AInteractable_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AInteractable_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AInteractable_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AInteractable()
	{
		if (!Z_Registration_Info_UClass_AInteractable.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AInteractable.OuterSingleton, Z_Construct_UClass_AInteractable_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AInteractable.OuterSingleton;
	}
	template<> EXPERIMENTAL_API UClass* StaticClass<AInteractable>()
	{
		return AInteractable::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AInteractable);
	AInteractable::~AInteractable() {}
	struct Z_CompiledInDeferFile_FID_Experimental_Source_Experimental_Interactable_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Experimental_Source_Experimental_Interactable_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AInteractable, AInteractable::StaticClass, TEXT("AInteractable"), &Z_Registration_Info_UClass_AInteractable, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AInteractable), 534361075U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Experimental_Source_Experimental_Interactable_h_883588556(TEXT("/Script/Experimental"),
		Z_CompiledInDeferFile_FID_Experimental_Source_Experimental_Interactable_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Experimental_Source_Experimental_Interactable_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
