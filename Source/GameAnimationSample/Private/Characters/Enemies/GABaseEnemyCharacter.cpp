// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Enemies/GABaseEnemyCharacter.h"
#include "AbilitySystem/Components/GAPlayerAbilitySystemComponent.h"
#include "AbilitySystem/Attributes/GAHealthAttributeSet.h"

AGABaseEnemyCharacter::AGABaseEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	AbilitySystemComponent = CreateDefaultSubobject<UGAPlayerAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	HealthAttributeSet = CreateDefaultSubobject<UGAHealthAttributeSet>(TEXT("HealthAttributeSet"));
}

void AGABaseEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
}
