// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "GABaseCharacter.generated.h"

class UGAPlayerAbilitySystemComponent;
class UGAHealthAttributeSet;
class UCharacterTrajectoryComponent;

UCLASS()
class GAMEANIMATIONSAMPLE_API AGABaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	AGABaseCharacter();

	//Ability System
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	TObjectPtr<UGAHealthAttributeSet> GetHealthAttributeSet() const { return HealthAttributeSet; }

protected:
	virtual void BeginPlay() override;

	//Ablity System
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	TObjectPtr<UGAPlayerAbilitySystemComponent> AbilitySystemComponent = nullptr;

	UPROPERTY()
	TObjectPtr<UGAHealthAttributeSet> HealthAttributeSet = nullptr;

	// Animation Trajectory
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	TObjectPtr<UCharacterTrajectoryComponent> TrajectoryComponent = nullptr;
};
