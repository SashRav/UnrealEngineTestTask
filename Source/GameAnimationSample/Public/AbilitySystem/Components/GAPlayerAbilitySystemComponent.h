// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GAPlayerAbilitySystemComponent.generated.h"

UCLASS()
class GAMEANIMATIONSAMPLE_API UGAPlayerAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
public:
	void OnCharacterDeath();
	void SetupBaseTags();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tags")
	FGameplayTag AliveTag;
};
