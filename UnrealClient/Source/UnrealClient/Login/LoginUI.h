// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LoginUI.generated.h"

UCLASS()
class UNREALCLIENT_API ULoginUI : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConnectInfo", meta = (AllowPrivateAccess = "true"))
	FString m_IPString;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConnectInfo", meta = (AllowPrivateAccess = "true"))
	FString m_PortString;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConnectInfo", meta = (AllowPrivateAccess = "true"))
	FString m_ConnectStatusString;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LoginInfo", meta = (AllowPrivateAccess = "true"))
	FString m_IDString;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LoginInfo", meta = (AllowPrivateAccess = "true"))
	FString m_PWString;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ConnectInfo", meta = (AllowPrivateAccess = "true"))
	FLinearColor m_ConnectedIconColor;    	

	class USignInUIWidget* m_SignInUIWidget;
	class UPopUpUIWidget* m_PopUpUIWidget;

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

	void SignInUIOff();

	void SignInFailedPopUpOn();
	void SignInSucceedPopUpOn();
	void LoginFailedPopUpOn();
	
};
