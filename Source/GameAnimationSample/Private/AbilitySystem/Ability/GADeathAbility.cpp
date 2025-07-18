// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Ability/GADeathAbility.h"
#include "AbilitySystem/Components/GAPlayerAbilitySystemComponent.h"
#include "Characters/GABaseCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

void UGADeathAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	AGABaseCharacter* Character = Cast<AGABaseCharacter>(ActorInfo->AvatarActor.Get());
	if (!Character) return;

	Character->GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Character->GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Character->GetCharacterMovement()->DisableMovement();
	Character->bUseControllerRotationYaw = false;
	Character->OnCharacterDeath();

	GetAbilitySystemComponentFromActorInfo()->AddLooseGameplayTags(ActivationOwnedTags);
	GetAbilitySystemComponentFromActorInfo()->PlayMontage(this, ActivationInfo, DeathAnimation,1.f);

	FTimerHandle AbilityDurationTime;
	GetWorld()->GetTimerManager().SetTimer(AbilityDurationTime, this, &UGADeathAbility::OnEndAbilityAnimation, DeathAnimation->GetPlayLength()-0.3f, false);
}

void UGADeathAbility::OnEndAbilityAnimation()
{
	AGABaseCharacter* Character = Cast<AGABaseCharacter>(GetCurrentActorInfo()->AvatarActor.Get());
	if (!Character) return;

	Character->GetMesh()->bPauseAnims = true;

	EndAbility(GetCurrentAbilitySpecHandle(), GetCurrentActorInfo(), GetCurrentActivationInfo(), true, false);
}
