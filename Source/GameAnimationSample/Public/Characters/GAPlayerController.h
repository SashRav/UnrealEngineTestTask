// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GAPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
class AGABaseCharacter;
struct FInputActionValue;

UCLASS()
class GAMEANIMATIONSAMPLE_API AGAPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	virtual void OnPossess(APawn* aPawn) override;

	// Charater Movement
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

	void RunAttackAbility(const FInputActionValue& Value);
	void RunHealAbility(const FInputActionValue& Value);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputAction> MoveAction = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputAction> LookAction = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputAction> AttackAction = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputAction> HealAction = nullptr;

	UPROPERTY()
	TObjectPtr<AGABaseCharacter> OwningCharacter;
};
