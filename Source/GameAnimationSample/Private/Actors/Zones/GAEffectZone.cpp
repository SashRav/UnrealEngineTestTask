// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Zones/GAEffectZone.h"
#include "AbilitySystemGlobals.h"
#include "AbilitySystemComponent.h"

AGAEffectZone::AGAEffectZone()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AGAEffectZone::BeginPlay()
{
	check(EffectClass);
}

void AGAEffectZone::ApplyEffectToTarget(AActor* InTargetActor)
{
	if (UAbilitySystemComponent* TargetAbilitySystemCompoennt = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(InTargetActor))
	{
		FGameplayEffectContextHandle EffectContextHandle = TargetAbilitySystemCompoennt->MakeEffectContext();
		EffectContextHandle.AddInstigator(InTargetActor, this);

		FGameplayEffectSpecHandle SpecHandle = TargetAbilitySystemCompoennt->MakeOutgoingSpec(EffectClass, 1.f, EffectContextHandle);
		TargetAbilitySystemCompoennt->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
	}
}

