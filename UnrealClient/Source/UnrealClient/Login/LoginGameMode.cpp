// Fill out your copyright notice in the Description page of Project Settings.


#include "LoginGameMode.h"

ALoginGameMode::ALoginGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bTickEvenWhenPaused = true;
	PrimaryActorTick.TickGroup = TG_PrePhysics;

}

void ALoginGameMode::Tick(float _Delta)
{
	
}

