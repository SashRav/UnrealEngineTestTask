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


	for (const FGameplayAbilitySpec& AbilitySpec : AbilitySystemComponent->GetActivatableAbilities())
	{
		if (AbilitySpec.IsActive())
		{
			if (UGAAttackAbility* AttackAbility = Cast<UGAAttackAbility>(AbilitySpec.Ability))
			{
				AttackAbility->PrintDebugMessageStart();
				break;
			}
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


	for (const FGameplayAbilitySpec& AbilitySpec : AbilitySystemComponent->GetActivatableAbilities())
	{
		if (AbilitySpec.IsActive())
		{
			if (UGAAttackAbility* AttackAbility = Cast<UGAAttackAbility>(AbilitySpec.Ability))
			{
				AttackAbility->PrintDebugMessageEnd();
				break;
			}
		}
	}
}
