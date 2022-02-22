// Fill out your copyright notice in the Description page of Project Settings.


#include "ClientBlueprintFunctionLibrary.h"


bool UClientBlueprintFunctionLibrary::FStringToUTF8(const FString& _FString, std::string& _UTF8)
{
	FString String = TEXT("Test ~ String~");
	return true;
}

bool UClientBlueprintFunctionLibrary::StringToVectorData(const std::string& _String, std::vector<uint8> _VectorData)
{
	_VectorData.clear();
	
	return true;
}


 bool UClientBlueprintFunctionLibrary::FStringToVectorData(const FString& _FString, std::vector<uint8> _VectorData)
{
	return true;

	
}