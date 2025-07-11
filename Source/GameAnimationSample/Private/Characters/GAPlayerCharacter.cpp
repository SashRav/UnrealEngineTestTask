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

	check(MoveAction);
	check(LookAction);
	check(AttackAction);
	check(HealAction);
	check(AttackAbility);
	check(HealAbility);

	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	
	GiveDefaultAbilities();
	
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		GameHUD = Cast<AGAGameHUD>(PlayerController->GetHUD());
	}

	if (HealthAttributeSet)
	{
		UpdateHealthWidget(HealthAttributeSet->GetHealth(), HealthAttributeSet->GetMaxHealth());
	}
}

void AGAPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) 
	{
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AGAPlayerCharacter::Look);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AGAPlayerCharacter::Move);
		EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Started, this, &AGAPlayerCharacter::AttackEnemy);
		EnhancedInputComponent->BindAction(HealAction, ETriggerEvent::Started, this, &AGAPlayerCharacter::HealPlayer);
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

void AGAPlayerCharacter::Move(const FInputActionValue& Value)
{
	if (GetController())
	{
		FVector2D MovementVector = Value.Get<FVector2D>();

		const FRotator Rotation = GetController()->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AGAPlayerCharacter::Look(const FInputActionValue& Value)
{
	if (GetController())
	{
		FVector2D LookAxisVector = Value.Get<FVector2D>();

		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AGAPlayerCharacter::GiveDefaultAbilities()
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

void AGAPlayerCharacter::AttackEnemy(const FInputActionValue& Value)
{
	if (!AbilitySystemComponent)
	{
		UE_LOG(LogTemp, Error, TEXT("AbilitySystemComponent is nullptr in AttackEnemy()"));
		return;
	}
	AbilitySystemComponent->TryActivateAbilityByClass(AttackAbility);
	
}

void AGAPlayerCharacter::HealPlayer(const FInputActionValue& Value)
{
	if (!AbilitySystemComponent)
	{
		UE_LOG(LogTemp, Error, TEXT("AbilitySystemComponent is nullptr in HealPlayer()"));
		return;
	}

	AbilitySystemComponent->TryActivateAbilityByClass(HealAbility);
}

