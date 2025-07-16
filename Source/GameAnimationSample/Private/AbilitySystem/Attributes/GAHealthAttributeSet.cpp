// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Attributes/GAHealthAttributeSet.h"
#include "GameplayEffectExtension.h"

UGAHealthAttributeSet::UGAHealthAttributeSet()
{
	InitHealth(100.f);
	InitMaxHealth(100.f);
}

void UGAHealthAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
    Super::PostGameplayEffectExecute(Data);

    if (Data.EvaluatedData.Attribute == GetHealthAttribute())
    {
        const float ClampedHealth = FMath::Clamp(GetHealth(), 0.0f, GetMaxHealth());
        SetHealth(ClampedHealth);
    }

    OnCurrentHealthUpdated.Broadcast(GetHealth(), GetMaxHealth());
}
