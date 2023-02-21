// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Experimental/ExperimentalGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeExperimentalGameMode() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	EXPERIMENTAL_API UClass* Z_Construct_UClass_AExperimentalGameMode();
	EXPERIMENTAL_API UClass* Z_Construct_UClass_AExperimentalGameMode_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
	UPackage* Z_Construct_UPackage__Script_Experimental();
// End Cross Module References
	DEFINE_FUNCTION(AExperimentalGameMode::execChangeHUDState)
	{
		P_GET_PROPERTY(FByteProperty,Z_Param_NewState);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ChangeHUDState(Z_Param_NewState);
		P_NATIVE_END;
	}
	void AExperimentalGameMode::StaticRegisterNativesAExperimentalGameMode()
	{
		UClass* Class = AExperimentalGameMode::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ChangeHUDState", &AExperimentalGameMode::execChangeHUDState },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AExperimentalGameMode_ChangeHUDState_Statics
	{
		struct ExperimentalGameMode_eventChangeHUDState_Parms
		{
			uint8 NewState;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_NewState;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AExperimentalGameMode_ChangeHUDState_Statics::NewProp_NewState = { "NewState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ExperimentalGameMode_eventChangeHUDState_Parms, NewState), nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AExperimentalGameMode_ChangeHUDState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AExperimentalGameMode_ChangeHUDState_Statics::NewProp_NewState,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AExperimentalGameMode_ChangeHUDState_Statics::Function_MetaDataParams[] = {
		{ "Category", "HUD Functions" },
		{ "Comment", "/*Setter function for the hudstate, applies the new state and then calls ApplyHUDChanges*/" },
		{ "ModuleRelativePath", "ExperimentalGameMode.h" },
		{ "ToolTip", "Setter function for the hudstate, applies the new state and then calls ApplyHUDChanges" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AExperimentalGameMode_ChangeHUDState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AExperimentalGameMode, nullptr, "ChangeHUDState", nullptr, nullptr, sizeof(Z_Construct_UFunction_AExperimentalGameMode_ChangeHUDState_Statics::ExperimentalGameMode_eventChangeHUDState_Parms), Z_Construct_UFunction_AExperimentalGameMode_ChangeHUDState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AExperimentalGameMode_ChangeHUDState_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AExperimentalGameMode_ChangeHUDState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AExperimentalGameMode_ChangeHUDState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AExperimentalGameMode_ChangeHUDState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AExperimentalGameMode_ChangeHUDState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AExperimentalGameMode);
	UClass* Z_Construct_UClass_AExperimentalGameMode_NoRegister()
	{
		return AExperimentalGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AExperimentalGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IngameHUDClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_IngameHUDClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InventoryHUDClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_InventoryHUDClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PauseHUDClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_PauseHUDClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CurrentWidget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentWidget;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AExperimentalGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Experimental,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AExperimentalGameMode_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AExperimentalGameMode_ChangeHUDState, "ChangeHUDState" }, // 2982187077
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AExperimentalGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "ExperimentalGameMode.h" },
		{ "ModuleRelativePath", "ExperimentalGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AExperimentalGameMode_Statics::NewProp_IngameHUDClass_MetaData[] = {
		{ "BlueprintProtected", "true" },
		{ "Category", "HUDwidgets" },
		{ "ModuleRelativePath", "ExperimentalGameMode.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AExperimentalGameMode_Statics::NewProp_IngameHUDClass = { "IngameHUDClass", nullptr, (EPropertyFlags)0x0024080000010005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AExperimentalGameMode, IngameHUDClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AExperimentalGameMode_Statics::NewProp_IngameHUDClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AExperimentalGameMode_Statics::NewProp_IngameHUDClass_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AExperimentalGameMode_Statics::NewProp_InventoryHUDClass_MetaData[] = {
		{ "BlueprintProtected", "true" },
		{ "Category", "HUDwidgets" },
		{ "ModuleRelativePath", "ExperimentalGameMode.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AExperimentalGameMode_Statics::NewProp_InventoryHUDClass = { "InventoryHUDClass", nullptr, (EPropertyFlags)0x0024080000010005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AExperimentalGameMode, InventoryHUDClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AExperimentalGameMode_Statics::NewProp_InventoryHUDClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AExperimentalGameMode_Statics::NewProp_InventoryHUDClass_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AExperimentalGameMode_Statics::NewProp_PauseHUDClass_MetaData[] = {
		{ "BlueprintProtected", "true" },
		{ "Category", "HUDwidgets" },
		{ "ModuleRelativePath", "ExperimentalGameMode.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AExperimentalGameMode_Statics::NewProp_PauseHUDClass = { "PauseHUDClass", nullptr, (EPropertyFlags)0x0024080000010005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AExperimentalGameMode, PauseHUDClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AExperimentalGameMode_Statics::NewProp_PauseHUDClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AExperimentalGameMode_Statics::NewProp_PauseHUDClass_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AExperimentalGameMode_Statics::NewProp_CurrentWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ExperimentalGameMode.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AExperimentalGameMode_Statics::NewProp_CurrentWidget = { "CurrentWidget", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AExperimentalGameMode, CurrentWidget), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AExperimentalGameMode_Statics::NewProp_CurrentWidget_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AExperimentalGameMode_Statics::NewProp_CurrentWidget_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AExperimentalGameMode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AExperimentalGameMode_Statics::NewProp_IngameHUDClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AExperimentalGameMode_Statics::NewProp_InventoryHUDClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AExperimentalGameMode_Statics::NewProp_PauseHUDClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AExperimentalGameMode_Statics::NewProp_CurrentWidget,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AExperimentalGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AExperimentalGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AExperimentalGameMode_Statics::ClassParams = {
		&AExperimentalGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AExperimentalGameMode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AExperimentalGameMode_Statics::PropPointers),
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_AExperimentalGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AExperimentalGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AExperimentalGameMode()
	{
		if (!Z_Registration_Info_UClass_AExperimentalGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AExperimentalGameMode.OuterSingleton, Z_Construct_UClass_AExperimentalGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AExperimentalGameMode.OuterSingleton;
	}
	template<> EXPERIMENTAL_API UClass* StaticClass<AExperimentalGameMode>()
	{
		return AExperimentalGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AExperimentalGameMode);
	AExperimentalGameMode::~AExperimentalGameMode() {}
	struct Z_CompiledInDeferFile_FID_Experimental_Source_Experimental_ExperimentalGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Experimental_Source_Experimental_ExperimentalGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AExperimentalGameMode, AExperimentalGameMode::StaticClass, TEXT("AExperimentalGameMode"), &Z_Registration_Info_UClass_AExperimentalGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AExperimentalGameMode), 787110481U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Experimental_Source_Experimental_ExperimentalGameMode_h_2196417098(TEXT("/Script/Experimental"),
		Z_CompiledInDeferFile_FID_Experimental_Source_Experimental_ExperimentalGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Experimental_Source_Experimental_ExperimentalGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
