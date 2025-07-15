// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/GABaseCharacter.h"
#include "AbilitySystem/Components/GAPlayerAbilitySystemComponent.h"
#include "AbilitySystem/Attributes/GAHealthAttributeSet.h"
#include "CharacterTrajectoryComponent.h"

// Sets default values
AGABaseCharacter::AGABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	AbilitySystemComponent = CreateDefaultSubobject<UGAPlayerAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	HealthAttributeSet = CreateDefaultSubobject<UGAHealthAttributeSet>(TEXT("HealthAttributeSet"));

	//Animations setup
	TrajectoryComponent = CreateDefaultSubobject<UCharacterTrajectoryComponent>(TEXT("TrajectoryComponent"));

	WeaponStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	WeaponStaticMesh->SetupAttachment(GetMesh(), TEXT("weapon_socket"));
}

UAbilitySystemComponent* AGABaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AGABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	check(AttackAbility);
	check(HealAbility);

	if (AbilitySystemComponent) 
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
		AbilitySystemComponent->SetupBaseTags();
	}

	SetDefaultAbilities();

	if (HealthAttributeSet)
	{
		HealthAttributeSet->OnCurrentHealthUpdated.AddDynamic(this, &AGABaseCharacter::UpdateHealthData);
		UpdateHealthData(HealthAttributeSet->GetHealth(), HealthAttributeSet->GetMaxHealth());
	}
}

void AGABaseCharacter::SetDefaultAbilities()
{
	if (!AbilitySystemComponent)
	{
		UE_LOG(LogTemp, Error, TEXT("AbilitySystemComponent is nullptr in GiveDefaultAbilities()"));
		return;
	}
	const FGameplayAbilitySpec AttackAbilitySpec(AttackAbility, 1);
	AbilitySystemComponent->GiveAbility(AttackAbilitySpec);

	const FGameplayAbilitySpec HealAbilitySpec(HealAbility, 1);
	AbilitySystemComponent->GiveAbility(HealAbilitySpec);
}

void AGABaseCharacter::UpdateHealthData(float NewHealth, float MaxHealth)
{
	OnCharacterHealthUpdated.Broadcast(NewHealth, MaxHealth);
}
