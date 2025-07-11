// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Ability/GAAttackAbility.h"
#include "AbilitySystem/Components/GAPlayerAbilitySystemComponent.h"
#include "Abilities/Tasks/AbilityTask_PlayMontageAndWait.h"
#include "Characters/GAPlayerCharacter.h"

void UGAAttackAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	LocalHandle = Handle;
	LocalActorInfo = *ActorInfo;
	LocalActivationInfo = ActivationInfo;

	check(AttackAnimation);

	GetAbilitySystemComponentFromActorInfo()->AddLooseGameplayTags(ActivationOwnedTags);

	FTimerHandle AbilityhDurationTime;
	GetWorld()->GetTimerManager().SetTimer(AbilityhDurationTime, this, &UGAAttackAbility::OnEndAbilityAnimation, AttackAnimation->GetPlayLength(), false);
}

void UGAAttackAbility::OnEndAbilityAnimation()
{
	GetAbilitySystemComponentFromActorInfo()->RemoveLooseGameplayTags(ActivationOwnedTags);

	EndAbility(LocalHandle, &LocalActorInfo, LocalActivationInfo, true, false);
}
