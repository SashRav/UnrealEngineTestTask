// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/GAPlayerCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "AbilitySystem/Components/GAPlayerAbilitySystemComponent.h"
#include "AbilitySystem/Attributes/GAHealthAttributeSet.h"
#include "UI/GAGameHUD.h"

AGAPlayerCharacter::AGAPlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;
}

void AGAPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		GameHUD = Cast<AGAGameHUD>(PlayerController->GetHUD());
	}
}

void AGAPlayerCharacter::UpdateHealthWidget(float NewHealth, float MaxHealth)
{
	if (GameHUD && MaxHealth != 0) 
	{
		const float HealthPercent = NewHealth / MaxHealth;
		GameHUD->UpdateHealthPercent(HealthPercent);
	}
}

//void AGAPlayerCharacter::AttackEnemy(const FInputActionValue& Value)
//{
//	if (!AbilitySystemComponent)
//	{
//		UE_LOG(LogTemp, Error, TEXT("AbilitySystemComponent is nullptr in AttackEnemy()"));
//		return;
//	}
//	AbilitySystemComponent->TryActivateAbilityByClass(AttackAbility);
//	
//}
//
//void AGAPlayerCharacter::HealPlayer(const FInputActionValue& Value)
//{
//	if (!AbilitySystemComponent)
//	{
//		UE_LOG(LogTemp, Error, TEXT("AbilitySystemComponent is nullptr in HealPlayer()"));
//		return;
//	}
//
//	AbilitySystemComponent->TryActivateAbilityByClass(HealAbility);
//}

