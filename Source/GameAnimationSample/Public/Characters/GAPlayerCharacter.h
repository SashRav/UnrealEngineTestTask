// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/GABaseCharacter.h"
#include "GameplayTagContainer.h"
#include "GAPlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class AGAGameHUD;
struct FInputActionValue;

UCLASS()
class GAMEANIMATIONSAMPLE_API AGAPlayerCharacter : public AGABaseCharacter
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:	
	AGAPlayerCharacter();

protected:
	virtual void UpdateHealthWidget(float NewHealth, float MaxHealth) override;

	// Components
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	TObjectPtr<USpringArmComponent> CameraBoom = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	TObjectPtr<UCameraComponent> FollowCamera = nullptr;

	//UI
	UPROPERTY()
	TObjectPtr<AGAGameHUD> GameHUD = nullptr;
};
