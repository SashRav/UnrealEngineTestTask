// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GAGameHUD.generated.h"

class UUserWidget;

UCLASS()
class GAMEANIMATIONSAMPLE_API AGAGameHUD : public AHUD
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UUserWidget> GameWidgetClass;

private:
	UPROPERTY()
	TObjectPtr<UUserWidget> GameWidget = nullptr;

};
