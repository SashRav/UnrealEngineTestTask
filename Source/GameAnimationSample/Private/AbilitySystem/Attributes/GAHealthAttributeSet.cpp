// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Attributes/GAHealthAttributeSet.h"
#include "AbilitySystem/Components/GAPlayerAbilitySystemComponent.h"

UGAHealthAttributeSet::UGAHealthAttributeSet()
{
	InitHealth(100.f);
	InitMaxHealth(100.f);
}

void UGAHealthAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
    Super::PreAttributeChange(Attribute, NewValue);

    //Clamp max Health value to Max Health

    if (Attribute == GetHealthAttribute())
    {
        NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxHealth());
    }
}

void UGAHealthAttributeSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
    // Check if character is dead
    if (GetHealth() <= 0.f) 
    {
        UAbilitySystemComponent* ASC = GetOwningAbilitySystemComponent();

        if (UGAPlayerAbilitySystemComponent* AbilityComponent = Cast<UGAPlayerAbilitySystemComponent>(ASC))
        {
            AbilityComponent->OnCharacterDeath();
        }
    }

    OnCurrentHealthUpdated.Broadcast(GetHealth());
}
