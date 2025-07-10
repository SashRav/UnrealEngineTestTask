// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GAHealthBarWidget.generated.h"

class UProgressBar;

UCLASS()
class GAMEANIMATIONSAMPLE_API UGAHealthBarWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Health")
	void UpdateHealthBar(const float HealthPercent);

protected:
	UPROPERTY(meta = (BindWidget))
	UProgressBar* PB_HealthBar;
};
