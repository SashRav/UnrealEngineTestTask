// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Enemies/GABaseEnemyCharacter.h"
#include "Components/WidgetComponent.h"
#include "UI/Widgets/GAHealthBarWidget.h"
#include "AbilitySystem/Attributes/GAHealthAttributeSet.h"

AGABaseEnemyCharacter::AGABaseEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	HealthBar = CreateDefaultSubobject<UWidgetComponent>(TEXT("HealthBar"));
	HealthBar->SetupAttachment(RootComponent);
}

void AGABaseEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	if(UGAHealthBarWidget* HealthWidget = Cast<UGAHealthBarWidget>(HealthBar->GetWidget()))
	{
		HealthBarWidget = HealthWidget;
	}

	if (HealthAttributeSet) 
	{
		UpdateHealthWidget(HealthAttributeSet->GetHealth(), HealthAttributeSet->GetMaxHealth());
	}
}

void AGABaseEnemyCharacter::UpdateHealthWidget(float NewHealth, float MaxHealth)
{
	if (HealthBarWidget && MaxHealth != 0)
	{
		float NewHealthPercent = NewHealth / MaxHealth;

		HealthBarWidget->UpdateHealthBar(NewHealthPercent);
	}
}
