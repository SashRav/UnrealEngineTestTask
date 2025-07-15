// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GAGameHUD.h"
#include "Blueprint/UserWidget.h"
#include "UI/Widgets/GAHealthBarWidget.h"
#include "Characters/GABaseCharacter.h"

void AGAGameHUD::BeginPlay()
{
	Super::BeginPlay();

	check(GameWidgetClass);
	check(HealthBarWidgetClass);

	GameWidget = CreateWidget<UUserWidget>(GetWorld(), GameWidgetClass);
	GameWidget->AddToViewport();

	HealthBarWidget = CreateWidget<UGAHealthBarWidget>(GetWorld(), HealthBarWidgetClass);
	HealthBarWidget->AddToViewport();

	AGABaseCharacter* OwningPawn = Cast<AGABaseCharacter>(GetOwningPawn());
	if (!OwningPawn) return;

	OwningPawn->OnCharacterHealthUpdated.AddDynamic(this, &AGAGameHUD::UpdateHealthPercent);
}

void AGAGameHUD::UpdateHealthPercent(float NewHealth, float MaxHealth)
{
	if (HealthBarWidget && MaxHealth != 0) 
	{
		const float NewPercent = NewHealth / MaxHealth;
		HealthBarWidget->UpdateHealthBar(NewPercent);
	}
}
