// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/GAHealthBarWidget.h"
#include "Components/ProgressBar.h"

void UGAHealthBarWidget::UpdateHealthBar(const float HealthPercent)
{
	PB_HealthBar->SetPercent(HealthPercent);
}
