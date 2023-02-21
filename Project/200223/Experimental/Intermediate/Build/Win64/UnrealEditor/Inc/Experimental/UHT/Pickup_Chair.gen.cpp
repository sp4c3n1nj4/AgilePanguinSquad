// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Experimental/Pickup_Chair.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePickup_Chair() {}
// Cross Module References
	EXPERIMENTAL_API UClass* Z_Construct_UClass_APickup();
	EXPERIMENTAL_API UClass* Z_Construct_UClass_APickup_Chair();
	EXPERIMENTAL_API UClass* Z_Construct_UClass_APickup_Chair_NoRegister();
	UPackage* Z_Construct_UPackage__Script_Experimental();
// End Cross Module References
	void APickup_Chair::StaticRegisterNativesAPickup_Chair()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(APickup_Chair);
	UClass* Z_Construct_UClass_APickup_Chair_NoRegister()
	{
		return APickup_Chair::StaticClass();
	}
	struct Z_Construct_UClass_APickup_Chair_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APickup_Chair_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APickup,
		(UObject* (*)())Z_Construct_UPackage__Script_Experimental,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APickup_Chair_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Pickup_Chair.h" },
		{ "ModuleRelativePath", "Pickup_Chair.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_APickup_Chair_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APickup_Chair>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_APickup_Chair_Statics::ClassParams = {
		&APickup_Chair::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_APickup_Chair_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APickup_Chair_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APickup_Chair()
	{
		if (!Z_Registration_Info_UClass_APickup_Chair.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APickup_Chair.OuterSingleton, Z_Construct_UClass_APickup_Chair_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_APickup_Chair.OuterSingleton;
	}
	template<> EXPERIMENTAL_API UClass* StaticClass<APickup_Chair>()
	{
		return APickup_Chair::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(APickup_Chair);
	APickup_Chair::~APickup_Chair() {}
	struct Z_CompiledInDeferFile_FID_Experimental_Source_Experimental_Pickup_Chair_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Experimental_Source_Experimental_Pickup_Chair_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_APickup_Chair, APickup_Chair::StaticClass, TEXT("APickup_Chair"), &Z_Registration_Info_UClass_APickup_Chair, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APickup_Chair), 1484757742U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Experimental_Source_Experimental_Pickup_Chair_h_3043810538(TEXT("/Script/Experimental"),
		Z_CompiledInDeferFile_FID_Experimental_Source_Experimental_Pickup_Chair_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Experimental_Source_Experimental_Pickup_Chair_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
