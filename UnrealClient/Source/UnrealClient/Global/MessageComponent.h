// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MessageComponent.generated.h"


// MessageComponent는 GameMode에 붙여주고, 매 틱마다 GameInstance에 있는 MessageQueue를 비워준다.
class Dispatcher;
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UNREALCLIENT_API UMessageComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	Dispatcher* m_Dispatcher;
	
public:
	// Sets default values for this component's properties
	UMessageComponent();
	virtual ~UMessageComponent() override;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
