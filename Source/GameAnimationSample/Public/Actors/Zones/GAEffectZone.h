// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GAEffectZone.generated.h"

class UGameplayEffect;

UCLASS()
class GAMEANIMATIONSAMPLE_API AGAEffectZone : public AActor
{
	GENERATED_BODY()
	
public:	
	AGAEffectZone();

protected:
	virtual void BeginPlay() override;

	//Gameplay Effects
	UFUNCTION(BlueprintCallable, Category = "Effects")
	void ApplyEffectToTarget(AActor* InTargetActor);

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects", meta = (AllowPrivateAccess = true))
	TSubclassOf<UGameplayEffect> EffectClass;
};
