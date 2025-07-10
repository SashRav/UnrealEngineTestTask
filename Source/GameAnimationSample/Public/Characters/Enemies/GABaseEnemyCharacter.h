// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/GABaseCharacter.h"
#include "GABaseEnemyCharacter.generated.h"

class UGAPlayerAbilitySystemComponent;
class UGAHealthAttributeSet;

UCLASS()
class GAMEANIMATIONSAMPLE_API AGABaseEnemyCharacter : public AGABaseCharacter
{
	GENERATED_BODY()

public:
	AGABaseEnemyCharacter();

protected:
	virtual void BeginPlay() override;
};
