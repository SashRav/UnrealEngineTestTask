// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "GAPlayerCharacter.generated.h"

class UInputAction;
class USpringArmComponent;
class UCameraComponent;
class UCharacterTrajectoryComponent;
class UGAPlayerAbilitySystemComponent;
class UGAHealthAttributeSet;
struct FInputActionValue;

UCLASS()
class GAMEANIMATIONSAMPLE_API AGAPlayerCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:

protected:
	virtual void BeginPlay() override;

public:	
	AGAPlayerCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	// Charater Movement
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

	//Ability System
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	TObjectPtr<UGAHealthAttributeSet> GetHealthAttributeSet() const { return HealthAttributeSet; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputAction> MoveAction = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputAction> LookAction = nullptr;

	// Components
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	TObjectPtr<USpringArmComponent> CameraBoom = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	TObjectPtr<UCameraComponent> FollowCamera = nullptr;

	// Animation Trajectory
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	TObjectPtr<UCharacterTrajectoryComponent> TrajectoryComponent = nullptr;

	//Ablity System
	UPROPERTY()
	TObjectPtr<UGAPlayerAbilitySystemComponent> AbilitySystemComponent = nullptr;

	UPROPERTY()
	TObjectPtr<UGAHealthAttributeSet> HealthAttributeSet = nullptr;
};
