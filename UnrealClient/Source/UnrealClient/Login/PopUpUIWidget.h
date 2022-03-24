#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PopUpUIWidget.generated.h"

UCLASS()
class UNREALCLIENT_API UPopUpUIWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PopUpUI")
	FString m_PopUpMessageString;

public:
	virtual void NativeConstruct() override;
};
