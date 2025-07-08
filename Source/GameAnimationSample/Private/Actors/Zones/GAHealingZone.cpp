// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Zones/GAHealingZone.h"
#include "AbilitySystemGlobals.h"
#include "AbilitySystemComponent.h"

AGAHealingZone::AGAHealingZone()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AGAHealingZone::ApplyEffectToTarget(AActor* InTargetActor)
{
	if (UAbilitySystemComponent* TargetAbilitySystemCompoennt = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(InTargetActor))
	{
		FGameplayEffectContextHandle EffectContextHandle = TargetAbilitySystemCompoennt->MakeEffectContext();
		EffectContextHandle.AddInstigator(this, this);

		FGameplayEffectSpecHandle SpecHandle = TargetAbilitySystemCompoennt->MakeOutgoingSpec(EffectClass, 1.f, EffectContextHandle);
		TargetAbilitySystemCompoennt->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
	}
}

