// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/GAPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"

void AGAPlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(DefaultMappingContext);
}

void AGAPlayerController::SetupInputComponent()
{
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}
}
