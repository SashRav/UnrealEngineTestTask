// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Attributes/GABaseAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GAHealthAttributeSet.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCurrentHealthUpdated, float, Health);

UCLASS()
class GAMEANIMATIONSAMPLE_API UGAHealthAttributeSet : public UGABaseAttributeSet
{
	GENERATED_BODY()

public:
	UGAHealthAttributeSet();

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;

	ATTRIBUTE_ACCESSORS(ThisClass, Health);
	ATTRIBUTE_ACCESSORS(ThisClass, MaxHealth);

	UPROPERTY(VisibleAnywhere, BlueprintAssignable, Category = "Health")
	FCurrentHealthUpdated OnCurrentHealthUpdated;

private:
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Health;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MaxHealth;
};
