// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Ability/GAHealAbility.h"
#include "AbilitySystemGlobals.h"
#include "AbilitySystemComponent.h"

void UGAHealAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if (UAbilitySystemComponent* TargetAbilitySystemComponent = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(ActorInfo->OwnerActor.Get()))
	{
		FGameplayEffectContextHandle EffectContextHandle = TargetAbilitySystemComponent->MakeEffectContext();
		EffectContextHandle.AddInstigator(ActorInfo->OwnerActor.Get(), ActorInfo->OwnerActor.Get());

		FGameplayEffectSpecHandle SpecHandle = TargetAbilitySystemComponent->MakeOutgoingSpec(EffectClass, 1.f, EffectContextHandle);
		TargetAbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
	}

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
