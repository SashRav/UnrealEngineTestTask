// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/Enemies/GABaseEnemyCharacter.h"
#include "AbilitySystem/Components/GAPlayerAbilitySystemComponent.h"
#include "AbilitySystem/Attributes/GAHealthAttributeSet.h"

AGABaseEnemyCharacter::AGABaseEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AGABaseEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
}
