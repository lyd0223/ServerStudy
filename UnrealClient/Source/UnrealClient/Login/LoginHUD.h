#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "LoginHUD.generated.h"

UCLASS()
class UNREALCLIENT_API ALoginHUD : public AHUD
{
	GENERATED_BODY()

public:
	ALoginHUD();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI", meta = (AllowPrivateAccess = "true"))
	class ULoginUI* m_LoginUI;

public:
	ULoginUI* GetLoginUI() const
	{
		return m_LoginUI;
	}
};
