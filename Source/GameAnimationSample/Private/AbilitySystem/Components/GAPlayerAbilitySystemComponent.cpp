// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Components/GAPlayerAbilitySystemComponent.h"

void UGAPlayerAbilitySystemComponent::OnCharacterDeath()
{
	RemoveLooseGameplayTag(AliveTag);
}

void UGAPlayerAbilitySystemComponent::SetupBaseTags()
{
	AddLooseGameplayTag(AliveTag);
}