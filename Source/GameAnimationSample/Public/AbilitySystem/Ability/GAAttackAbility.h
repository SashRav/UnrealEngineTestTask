// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GAAttackAbility.generated.h"

class UAnimMontage;

UCLASS()
class GAMEANIMATIONSAMPLE_API UGAAttackAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
public:
	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData) override;

protected:
	void OnEndAbilityAnimation();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	TObjectPtr<UAnimMontage> AttackAnimation = nullptr;

private:
	UPROPERTY()
	FGameplayAbilitySpecHandle LocalHandle;

	UPROPERTY()
	FGameplayAbilityActorInfo LocalActorInfo;
	
	UPROPERTY()
	FGameplayAbilityActivationInfo LocalActivationInfo;
};
