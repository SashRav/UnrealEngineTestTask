// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Ability/GAAttackAbility.h"
#include "AbilitySystem/Components/GAPlayerAbilitySystemComponent.h"
#include "Characters/GABaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

UGAAttackAbility::UGAAttackAbility()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
}

void UGAAttackAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	check(AttackAnimation);
	check(DamageEffect);

	GetAbilitySystemComponentFromActorInfo()->AddLooseGameplayTags(ActivationOwnedTags);
	GetAbilitySystemComponentFromActorInfo()->PlayMontage(this, ActivationInfo, AttackAnimation, 1.f);

	FTimerHandle AbilityDurationTime;
	GetWorld()->GetTimerManager().SetTimer(AbilityDurationTime, this, &UGAAttackAbility::OnEndAbilityAnimation, AttackAnimation->GetPlayLength(), false);

	// Stop Character Movement while ability is active
	if (AGABaseCharacter* Character = Cast<AGABaseCharacter>(ActorInfo->AvatarActor.Get()))
	{
		if (Character->GetCharacterMovement())
		{
			Character->GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_None);
		}
	}

	//Overlap check is triggered from UGAttackAnimNotifyState
}

void UGAAttackAbility::OnWeaponMeshBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == GetCurrentActorInfo()->OwnerActor.Get()) return;

	IAbilitySystemInterface* AbilityInterface = Cast<IAbilitySystemInterface>(OtherActor);
	if (!AbilityInterface) return;
	
	UAbilitySystemComponent* TargetAbilitySystemComponent = AbilityInterface->GetAbilitySystemComponent();
	if (!TargetAbilitySystemComponent) return;

	FGameplayEffectContextHandle EffectContextHandle = GetAbilitySystemComponentFromActorInfo()->MakeEffectContext();
	EffectContextHandle.AddInstigator(GetCurrentActorInfo()->OwnerActor.Get(), GetCurrentActorInfo()->OwnerActor.Get());
	
	FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponentFromActorInfo()->MakeOutgoingSpec(DamageEffect, 1.f, EffectContextHandle);
	GetAbilitySystemComponentFromActorInfo()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), TargetAbilitySystemComponent);

	//End Check for overlaps because already hit something
	EndWeaponOverlapCheck();
}

void UGAAttackAbility::StartWeaponOverlapCheck()
{
	if (!GetCurrentActorInfo()) return;

	if (AGABaseCharacter* Character = Cast<AGABaseCharacter>(GetCurrentActorInfo()->OwnerActor.Get()))
	{
		if (!Character->GetWeaponMesh()) return;
		if (Character->GetWeaponMesh()->OnComponentBeginOverlap.IsAlreadyBound(this, &UGAAttackAbility::OnWeaponMeshBeginOverlap)) return;
		
		Character->GetWeaponMesh()->OnComponentBeginOverlap.AddDynamic(this, &UGAAttackAbility::OnWeaponMeshBeginOverlap);
	}
}

void UGAAttackAbility::EndWeaponOverlapCheck()
{
	if (AGABaseCharacter* Character = Cast<AGABaseCharacter>(GetCurrentActorInfo()->OwnerActor.Get()))
	{
		if (Character->GetWeaponMesh())
		{
			Character->GetWeaponMesh()->OnComponentBeginOverlap.RemoveDynamic(this, &UGAAttackAbility::OnWeaponMeshBeginOverlap);
		}
	}
}

void UGAAttackAbility::OnEndAbilityAnimation()
{
	GetAbilitySystemComponentFromActorInfo()->RemoveLooseGameplayTags(ActivationOwnedTags);
	EndWeaponOverlapCheck();

	// Enable Walking after the end of ability
	if (AGABaseCharacter* Character = Cast<AGABaseCharacter>(GetCurrentActorInfo()->AvatarActor.Get()))
	{
		if (Character->GetCharacterMovement())
		{
			Character->GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Walking);
		}
	}

	EndAbility(GetCurrentAbilitySpecHandle(), GetCurrentActorInfo(), GetCurrentActivationInfo(), true, false);
}




