// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Components/GAPlayerAbilitySystemComponent.h"

void UGAPlayerAbilitySystemComponent::OnCharacterDeath()
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, TEXT("Character Dead"));

	RemoveLooseGameplayTag(AliveTag);
}

void UGAPlayerAbilitySystemComponent::BeginPlay()
{
	AddLooseGameplayTag(AliveTag);
}
