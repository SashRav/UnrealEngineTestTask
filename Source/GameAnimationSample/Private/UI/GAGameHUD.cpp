// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GAGameHUD.h"
#include "Blueprint/UserWidget.h"

void AGAGameHUD::BeginPlay()
{
	Super::BeginPlay();

	check(GameWidgetClass);

	GameWidget = CreateWidget<UUserWidget>(GetWorld(), GameWidgetClass);
	GameWidget->AddToViewport();
}
