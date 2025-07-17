// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Animations/GAttackAnimNotifyState.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/Ability/GAAttackAbility.h"

void UGAttackAnimNotifyState::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);

	AActor* Owner = MeshComp->GetOwner();
	if (!Owner) return;

	IAbilitySystemInterface* AbilityInterface = Cast<IAbilitySystemInterface>(Owner);
	if (!AbilityInterface) return;

	UAbilitySystemComponent* AbilitySystemComponent = AbilityInterface->GetAbilitySystemComponent();
	if (!AbilitySystemComponent) return;

	TArray<FGameplayAbilitySpecHandle> OutAbilityHandles;
	AbilitySystemComponent->GetAllAbilities(OutAbilityHandles);

	for (const FGameplayAbilitySpecHandle& AbilitySpecHandle : OutAbilityHandles)
	{
		const FGameplayAbilitySpec* AbilitySpec = AbilitySystemComponent->FindAbilitySpecFromHandle(AbilitySpecHandle);
		if (!AbilitySpec) continue;

		if (UGAAttackAbility* AttackAbility = Cast<UGAAttackAbility>(AbilitySpec->GetPrimaryInstance()))
		{
			AttackAbility->StartWeaponOverlapCheck();
			break;
		}
	}
}

void UGAttackAnimNotifyState::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);

	AActor* Owner = MeshComp->GetOwner();
	if (!Owner) return;

	IAbilitySystemInterface* AbilityInterface = Cast<IAbilitySystemInterface>(Owner);
	if (!AbilityInterface) return;

	UAbilitySystemComponent* AbilitySystemComponent = AbilityInterface->GetAbilitySystemComponent();
	if (!AbilitySystemComponent) return;

	TArray<FGameplayAbilitySpecHandle> OutAbilityHandles;
	AbilitySystemComponent->GetAllAbilities(OutAbilityHandles);

	for (const FGameplayAbilitySpecHandle& AbilitySpecHandle : OutAbilityHandles)
	{
		const FGameplayAbilitySpec* AbilitySpec = AbilitySystemComponent->FindAbilitySpecFromHandle(AbilitySpecHandle);
		if (!AbilitySpec) continue;

		if (UGAAttackAbility* AttackAbility = Cast<UGAAttackAbility>(AbilitySpec->GetPrimaryInstance()))
		{
			AttackAbility->EndWeaponOverlapCheck();
			break;
		}
	}
}
