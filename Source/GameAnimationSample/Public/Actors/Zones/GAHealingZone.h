// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GAHealingZone.generated.h"

class UGameplayEffect;

UCLASS()
class GAMEANIMATIONSAMPLE_API AGAHealingZone : public AActor
{
	GENERATED_BODY()
	
public:	
	AGAHealingZone();

protected:
	//Gameplay Effectes
	UFUNCTION(BlueprintCallable, Category = "Effects")
	void ApplyEffectToTarget(AActor* InTargetActor);

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects", meta = (AllowPrivateAccess = true))
	TSubclassOf<UGameplayEffect> EffectClass;
};
