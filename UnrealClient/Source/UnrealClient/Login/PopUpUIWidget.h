#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PopUpUIWidget.generated.h"

UCLASS()
class UNREALCLIENT_API UPopUpUIWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PopUpUI", meta = (AllowPrivateAccess = "true"))
	FString m_PopUpMessageString;

public:
	void SetPopUpMessageString(const FString& _String)
	{
		m_PopUpMessageString = _String;
	}
public:
	virtual void NativeConstruct() override;


	UFUNCTION(BlueprintCallable)
	void PopUpUIOff();
};
