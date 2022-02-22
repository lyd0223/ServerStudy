// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealClient/Login/LoginUI.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLoginUI() {}
// Cross Module References
	UNREALCLIENT_API UClass* Z_Construct_UClass_ULoginUI_NoRegister();
	UNREALCLIENT_API UClass* Z_Construct_UClass_ULoginUI();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_UnrealClient();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
// End Cross Module References
	DEFINE_FUNCTION(ULoginUI::execServerLogin)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ServerLogin();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ULoginUI::execServerConnect)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ServerConnect();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ULoginUI::execSetTeacherIP)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetTeacherIP();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ULoginUI::execSetLocalIP)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetLocalIP();
		P_NATIVE_END;
	}
	void ULoginUI::StaticRegisterNativesULoginUI()
	{
		UClass* Class = ULoginUI::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ServerConnect", &ULoginUI::execServerConnect },
			{ "ServerLogin", &ULoginUI::execServerLogin },
			{ "SetLocalIP", &ULoginUI::execSetLocalIP },
			{ "SetTeacherIP", &ULoginUI::execSetTeacherIP },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ULoginUI_ServerConnect_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULoginUI_ServerConnect_Statics::Function_MetaDataParams[] = {
		{ "Category", "Login|Connect" },
		{ "ModuleRelativePath", "Login/LoginUI.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULoginUI_ServerConnect_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULoginUI, nullptr, "ServerConnect", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULoginUI_ServerConnect_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ULoginUI_ServerConnect_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULoginUI_ServerConnect()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULoginUI_ServerConnect_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULoginUI_ServerLogin_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULoginUI_ServerLogin_Statics::Function_MetaDataParams[] = {
		{ "Category", "Login|Login" },
		{ "ModuleRelativePath", "Login/LoginUI.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULoginUI_ServerLogin_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULoginUI, nullptr, "ServerLogin", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULoginUI_ServerLogin_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ULoginUI_ServerLogin_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULoginUI_ServerLogin()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULoginUI_ServerLogin_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULoginUI_SetLocalIP_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULoginUI_SetLocalIP_Statics::Function_MetaDataParams[] = {
		{ "Category", "Login|Connect" },
		{ "ModuleRelativePath", "Login/LoginUI.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULoginUI_SetLocalIP_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULoginUI, nullptr, "SetLocalIP", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULoginUI_SetLocalIP_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ULoginUI_SetLocalIP_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULoginUI_SetLocalIP()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULoginUI_SetLocalIP_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULoginUI_SetTeacherIP_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULoginUI_SetTeacherIP_Statics::Function_MetaDataParams[] = {
		{ "Category", "Login|Connect" },
		{ "ModuleRelativePath", "Login/LoginUI.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ULoginUI_SetTeacherIP_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULoginUI, nullptr, "SetTeacherIP", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ULoginUI_SetTeacherIP_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ULoginUI_SetTeacherIP_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ULoginUI_SetTeacherIP()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ULoginUI_SetTeacherIP_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ULoginUI_NoRegister()
	{
		return ULoginUI::StaticClass();
	}
	struct Z_Construct_UClass_ULoginUI_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_IPString_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_m_IPString;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_PortString_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_m_PortString;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_ConnectStatusString_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_m_ConnectStatusString;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_IDString_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_m_IDString;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_PWString_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_m_PWString;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_ConnectedIconColor_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_m_ConnectedIconColor;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ULoginUI_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealClient,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ULoginUI_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ULoginUI_ServerConnect, "ServerConnect" }, // 2510593805
		{ &Z_Construct_UFunction_ULoginUI_ServerLogin, "ServerLogin" }, // 1919845901
		{ &Z_Construct_UFunction_ULoginUI_SetLocalIP, "SetLocalIP" }, // 2769585242
		{ &Z_Construct_UFunction_ULoginUI_SetTeacherIP, "SetTeacherIP" }, // 1626039047
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULoginUI_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Login/LoginUI.h" },
		{ "ModuleRelativePath", "Login/LoginUI.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULoginUI_Statics::NewProp_m_IPString_MetaData[] = {
		{ "Category", "ConnectInfo" },
		{ "ModuleRelativePath", "Login/LoginUI.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_ULoginUI_Statics::NewProp_m_IPString = { "m_IPString", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ULoginUI, m_IPString), METADATA_PARAMS(Z_Construct_UClass_ULoginUI_Statics::NewProp_m_IPString_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULoginUI_Statics::NewProp_m_IPString_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULoginUI_Statics::NewProp_m_PortString_MetaData[] = {
		{ "Category", "ConnectInfo" },
		{ "ModuleRelativePath", "Login/LoginUI.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_ULoginUI_Statics::NewProp_m_PortString = { "m_PortString", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ULoginUI, m_PortString), METADATA_PARAMS(Z_Construct_UClass_ULoginUI_Statics::NewProp_m_PortString_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULoginUI_Statics::NewProp_m_PortString_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULoginUI_Statics::NewProp_m_ConnectStatusString_MetaData[] = {
		{ "Category", "ConnectInfo" },
		{ "ModuleRelativePath", "Login/LoginUI.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_ULoginUI_Statics::NewProp_m_ConnectStatusString = { "m_ConnectStatusString", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ULoginUI, m_ConnectStatusString), METADATA_PARAMS(Z_Construct_UClass_ULoginUI_Statics::NewProp_m_ConnectStatusString_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULoginUI_Statics::NewProp_m_ConnectStatusString_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULoginUI_Statics::NewProp_m_IDString_MetaData[] = {
		{ "Category", "LoginInfo" },
		{ "ModuleRelativePath", "Login/LoginUI.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_ULoginUI_Statics::NewProp_m_IDString = { "m_IDString", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ULoginUI, m_IDString), METADATA_PARAMS(Z_Construct_UClass_ULoginUI_Statics::NewProp_m_IDString_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULoginUI_Statics::NewProp_m_IDString_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULoginUI_Statics::NewProp_m_PWString_MetaData[] = {
		{ "Category", "LoginInfo" },
		{ "ModuleRelativePath", "Login/LoginUI.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_ULoginUI_Statics::NewProp_m_PWString = { "m_PWString", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ULoginUI, m_PWString), METADATA_PARAMS(Z_Construct_UClass_ULoginUI_Statics::NewProp_m_PWString_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULoginUI_Statics::NewProp_m_PWString_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULoginUI_Statics::NewProp_m_ConnectedIconColor_MetaData[] = {
		{ "Category", "ConnectInfo" },
		{ "ModuleRelativePath", "Login/LoginUI.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_ULoginUI_Statics::NewProp_m_ConnectedIconColor = { "m_ConnectedIconColor", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ULoginUI, m_ConnectedIconColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(Z_Construct_UClass_ULoginUI_Statics::NewProp_m_ConnectedIconColor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULoginUI_Statics::NewProp_m_ConnectedIconColor_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULoginUI_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoginUI_Statics::NewProp_m_IPString,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoginUI_Statics::NewProp_m_PortString,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoginUI_Statics::NewProp_m_ConnectStatusString,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoginUI_Statics::NewProp_m_IDString,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoginUI_Statics::NewProp_m_PWString,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoginUI_Statics::NewProp_m_ConnectedIconColor,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ULoginUI_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULoginUI>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ULoginUI_Statics::ClassParams = {
		&ULoginUI::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ULoginUI_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ULoginUI_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_ULoginUI_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ULoginUI_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ULoginUI()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ULoginUI_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ULoginUI, 1215255460);
	template<> UNREALCLIENT_API UClass* StaticClass<ULoginUI>()
	{
		return ULoginUI::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ULoginUI(Z_Construct_UClass_ULoginUI, &ULoginUI::StaticClass, TEXT("/Script/UnrealClient"), TEXT("ULoginUI"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ULoginUI);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
