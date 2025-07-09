// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GABaseEnemyCharacter.generated.h"

class UGAPlayerAbilitySystemComponent;
class UGAHealthAttributeSet;

UCLASS()
class GAMEANIMATIONSAMPLE_API AGABaseEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AGABaseEnemyCharacter();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	TObjectPtr<UGAPlayerAbilitySystemComponent> AbilitySystemComponent = nullptr;

	UPROPERTY()
	TObjectPtr<UGAHealthAttributeSet> HealthAttributeSet = nullptr;
};
