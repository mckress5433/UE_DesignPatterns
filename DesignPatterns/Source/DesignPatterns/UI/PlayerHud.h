// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DesignPatterns/Global/GlobalStructs.h"
#include "PlayerHud.generated.h"

/**
 * 
 */
UCLASS()
class DESIGNPATTERNS_API UPlayerHud : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetInteractionPromptVisibility(bool bIsVisible);

	UFUNCTION(BLueprintNativeEvent, BlueprintCallable)
	void SetWeaponInfoVisibility(bool bIsVisible, FSwordInfo swordInfo);
};
