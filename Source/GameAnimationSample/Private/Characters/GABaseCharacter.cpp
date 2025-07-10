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
}

UAbilitySystemComponent* AGABaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AGABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}
