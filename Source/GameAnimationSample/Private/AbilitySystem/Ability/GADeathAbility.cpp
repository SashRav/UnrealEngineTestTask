// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Ability/GADeathAbility.h"
#include "AbilitySystem/Components/GAPlayerAbilitySystemComponent.h"

void UGADeathAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	GetAbilitySystemComponentFromActorInfo()->AddLooseGameplayTags(ActivationOwnedTags);
	GetAbilitySystemComponentFromActorInfo()->PlayMontage(this, ActivationInfo, DeathAnimation, 1.f);

	EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}
