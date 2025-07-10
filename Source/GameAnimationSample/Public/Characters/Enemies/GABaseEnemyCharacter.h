// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/GABaseCharacter.h"
#include "GABaseEnemyCharacter.generated.h"

class UWidgetComponent;
class UGAHealthBarWidget;

UCLASS()
class GAMEANIMATIONSAMPLE_API AGABaseEnemyCharacter : public AGABaseCharacter
{
	GENERATED_BODY()

public:
	AGABaseEnemyCharacter();

protected:
	virtual void BeginPlay() override;

	virtual void UpdateHealthWidget(float NewHealth, float MaxHealth);

	// Components
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	TObjectPtr<UWidgetComponent> HealthBar = nullptr;

	UPROPERTY()
	TObjectPtr<UGAHealthBarWidget> HealthBarWidget = nullptr;
};
