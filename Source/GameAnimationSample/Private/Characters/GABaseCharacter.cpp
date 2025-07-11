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
	HealthAttributeSet->OnCurrentHealthUpdated.AddDynamic(this, &AGABaseCharacter::UpdateHealthWidget);

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

	AbilitySystemComponent->SetupBaseTags();
}