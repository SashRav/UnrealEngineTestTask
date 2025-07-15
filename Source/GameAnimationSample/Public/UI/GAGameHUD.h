// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GAGameHUD.generated.h"

class UUserWidget;
class UGAHealthBarWidget;

UCLASS()
class GAMEANIMATIONSAMPLE_API AGAGameHUD : public AHUD
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void UpdateHealthPercent(float NewHealth, float MaxHealth);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UUserWidget> GameWidgetClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UGAHealthBarWidget> HealthBarWidgetClass;
	
private:
	UPROPERTY()
	TObjectPtr<UUserWidget> GameWidget = nullptr;

	UPROPERTY()
	TObjectPtr<UGAHealthBarWidget> HealthBarWidget = nullptr;

};
