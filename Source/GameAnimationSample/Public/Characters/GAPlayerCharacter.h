// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "GameplayTagContainer.h"
#include "GAPlayerCharacter.generated.h"

class UInputAction;
class USpringArmComponent;
class UCameraComponent;
class UCharacterTrajectoryComponent;
class UGAPlayerAbilitySystemComponent;
class UGAHealthAttributeSet;
class UGameplayAbility;
struct FInputActionValue;

UCLASS()
class GAMEANIMATIONSAMPLE_API AGAPlayerCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:	
	AGAPlayerCharacter();
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	//Ability System
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	TObjectPtr<UGAHealthAttributeSet> GetHealthAttributeSet() const { return HealthAttributeSet; }

protected:
	// Charater Movement
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	
	// Setup Default Abilities
	void GiveDefaultAbilities();

	//Run Attack Ability
	void AttackEnemy(const FInputActionValue& Value);

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

	// Animation Trajectory
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	TObjectPtr<UCharacterTrajectoryComponent> TrajectoryComponent = nullptr;

	//Ablity System
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	TObjectPtr<UGAPlayerAbilitySystemComponent> AbilitySystemComponent = nullptr;

	UPROPERTY()
	TObjectPtr<UGAHealthAttributeSet> HealthAttributeSet = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	TSubclassOf<UGameplayAbility> AttackAbility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	FGameplayTagContainer GameplayTagsContainer;
};
