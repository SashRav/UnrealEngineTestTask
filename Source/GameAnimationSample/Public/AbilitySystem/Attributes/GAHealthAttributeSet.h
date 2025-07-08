// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Attributes/GABaseAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GAHealthAttributeSet.generated.h"

UCLASS()
class GAMEANIMATIONSAMPLE_API UGAHealthAttributeSet : public UGABaseAttributeSet
{
	GENERATED_BODY()

public:
	UGAHealthAttributeSet();

	ATTRIBUTE_ACCESSORS(ThisClass, Health);
	ATTRIBUTE_ACCESSORS(ThisClass, MaxHealth);

private:
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Health;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MaxHealth;
};
