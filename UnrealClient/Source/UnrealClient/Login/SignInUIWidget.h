#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SignInUIWidget.generated.h"


UCLASS()
class UNREALCLIENT_API USignInUIWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SignInInfo")
	FString m_IDString;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SignInInfo")
	FString m_PWString;

public:
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable, Category="SignIn|SignIn")
	void SignIn();
};
