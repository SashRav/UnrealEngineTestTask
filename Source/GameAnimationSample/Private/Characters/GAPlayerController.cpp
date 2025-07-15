// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/GAPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputMappingContext.h"

void AGAPlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(DefaultMappingContext);
	check(MoveAction);
	check(LookAction);
	check(AttackAction);
	check(HealAction);
}

void AGAPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}
		
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AGAPlayerController::Look);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AGAPlayerController::Move);
		EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Started, this, &AGAPlayerController::RunAttackAbility);
		EnhancedInputComponent->BindAction(HealAction, ETriggerEvent::Started, this, &AGAPlayerController::RunHealAbility);
	}
}

void AGAPlayerController::Move(const FInputActionValue& Value)
{
	if (APawn* PlayerPawn = GetPawn()) 
	{
		FVector2D MovementVector = Value.Get<FVector2D>();

		const FRotator Rotation = GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		PlayerPawn->AddMovementInput(ForwardDirection, MovementVector.Y);
		PlayerPawn->AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AGAPlayerController::Look(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	AddYawInput(LookAxisVector.X);
	AddPitchInput(LookAxisVector.Y);
}

void AGAPlayerController::RunAttackAbility(const FInputActionValue& Value)
{
	//ToDo: Move Attack logic
	//	if (!AbilitySystemComponent)
//	{
//		UE_LOG(LogTemp, Error, TEXT("AbilitySystemComponent is nullptr in AttackEnemy()"));
//		return;
//	}
//	AbilitySystemComponent->TryActivateAbilityByClass(AttackAbility);
}

void AGAPlayerController::RunHealAbility(const FInputActionValue& Value)
{
	//ToDo: Move Heal logic
	//	if (!AbilitySystemComponent)
//	{
//		UE_LOG(LogTemp, Error, TEXT("AbilitySystemComponent is nullptr in HealPlayer()"));
//		return;
//	}
//
//	AbilitySystemComponent->TryActivateAbilityByClass(HealAbility);
}
