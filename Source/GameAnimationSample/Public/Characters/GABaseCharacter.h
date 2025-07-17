// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "GABaseCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCharacterHealthUpdated, float, NewHealth, float, MaxHealth);

class UGAPlayerAbilitySystemComponent;
class UGAHealthAttributeSet;
class UCharacterTrajectoryComponent;
class UGameplayAbility;

UCLASS()
class GAMEANIMATIONSAMPLE_API AGABaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	AGABaseCharacter();

	//Ability System
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	TObjectPtr<UGAHealthAttributeSet> GetHealthAttributeSet() const { return HealthAttributeSet; }

	UPROPERTY(VisibleAnywhere, BlueprintAssignable, Category = "Health")
	FCharacterHealthUpdated OnCharacterHealthUpdated;

	void ActivateAttackAbility();
	void ActivateHealAbility();

	UStaticMeshComponent* GetWeaponMesh() { return WeaponStaticMesh; }

protected:
	virtual void BeginPlay() override;

	// Setup Default Abilities
	void SetDefaultAbilities();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "UI")
	void UpdateHealthData(float NewHealth, float MaxHealth);
	void UpdateHealthData_Implementation(float NewHealth, float MaxHealth);

	//Ablity System
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	TObjectPtr<UGAPlayerAbilitySystemComponent> AbilitySystemComponent = nullptr;

	UPROPERTY()
	TObjectPtr<UGAHealthAttributeSet> HealthAttributeSet = nullptr;

	// Animation Trajectory
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	TObjectPtr<UCharacterTrajectoryComponent> TrajectoryComponent = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	TObjectPtr<UStaticMeshComponent> WeaponStaticMesh = nullptr;

	//Ability
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	TSubclassOf<UGameplayAbility> AttackAbility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	TSubclassOf<UGameplayAbility> HealAbility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	TSubclassOf<UGameplayAbility> DeathAbility;
};
