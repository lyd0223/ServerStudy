// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LoginUI.generated.h"

UCLASS()
class UNREALCLIENT_API ULoginUI : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConnectInfo")
	FString m_IPString;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConnectInfo")
	FString m_PortString;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConnectInfo")
	FString m_ConnectStatusString;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LoginInfo")
	FString m_IDString;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LoginInfo")
	FString m_PWString;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConnectInfo")
	FLinearColor m_ConnectedIconColor;    	

	class USignInUIWidget* m_SignInUIWidget;

public:
	virtual void NativeConstruct() override;
	
	UFUNCTION(BlueprintCallable, Category = "Login|Connect")
	void SetLocalIP();

	UFUNCTION(BlueprintCallable, Category = "Login|Connect")
	void SetTeacherIP();

	UFUNCTION(BlueprintCallable, Category = "Login|Connect")
	void ServerConnect();

	UFUNCTION(BlueprintCallable, Category = "Login|Login")
	void ServerLogin();
	
	UFUNCTION(BlueprintCallable, Category="SignIn|SignIn")
	void SignInUIWidgetOpen();
};
