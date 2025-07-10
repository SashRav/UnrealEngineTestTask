// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GAGameHUD.h"
#include "Blueprint/UserWidget.h"
#include "UI/Widgets/GAHealthBarWidget.h"

void AGAGameHUD::BeginPlay()
{
	Super::BeginPlay();

	check(GameWidgetClass);
	check(HealthBarWidgetClass);

	GameWidget = CreateWidget<UUserWidget>(GetWorld(), GameWidgetClass);
	GameWidget->AddToViewport();

	HealthBarWidget = CreateWidget<UGAHealthBarWidget>(GetWorld(), HealthBarWidgetClass);
	HealthBarWidget->AddToViewport();
}

void AGAGameHUD::UpdateHealthPercent(const float NewPercent)
{
	if (HealthBarWidget) 
	{
		HealthBarWidget->UpdateHealthBar(NewPercent);
	}
}
