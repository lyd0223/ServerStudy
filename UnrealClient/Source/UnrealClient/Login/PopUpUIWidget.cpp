// Fill out your copyright notice in the Description page of Project Settings.


#include "PopUpUIWidget.h"


void UPopUpUIWidget::NativeConstruct()
{
	
}

void UPopUpUIWidget::PopUpUIOff()
{
	this->SetVisibility(ESlateVisibility::Collapsed);
}