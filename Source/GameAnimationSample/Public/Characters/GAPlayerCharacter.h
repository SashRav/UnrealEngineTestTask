// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/GABaseCharacter.h"
#include "GameplayTagContainer.h"
#include "GAPlayerCharacter.generated.h"

class UInputAction;
class USpringArmComponent;
class UCameraComponent;
class UGameplayAbility;
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
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

protected:
	// Charater Movement
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	
	// Setup Default Abilities
	void GiveDefaultAbilities();

	//Run Attack Ability
	void AttackEnemy(const FInputActionValue& Value);

	virtual void UpdateHealthWidget(float NewHealth, float MaxHealth) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputAction> MoveAction = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputAction> LookAction = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputAction> AttackAction = nullptr;

	// Components
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	TObjectPtr<USpringArmComponent> CameraBoom = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	TObjectPtr<UCameraComponent> FollowCamera = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	TObjectPtr<UStaticMeshComponent> WeaponStaticMesh = nullptr;

	//UI
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
	AGAGameHUD* GameHUD;

	//Ability
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	TSubclassOf<UGameplayAbility> AttackAbility;
};
