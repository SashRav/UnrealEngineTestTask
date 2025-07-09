// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Ability/GAAttackAbility.h"
#include "AbilitySystem/Components/GAPlayerAbilitySystemComponent.h"

void UGAAttackAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
    Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

    check(AttackAnimation);

    if (GEngine)
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Ability Works from code"));

    GetAbilitySystemComponentFromActorInfo()->AddLooseGameplayTags(ActivationOwnedTags);

    EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
}

void UGAAttackAbility::EndAbilityAnimation()
{
    GetAbilitySystemComponentFromActorInfo()->RemoveLooseGameplayTags(ActivationOwnedTags);
}
