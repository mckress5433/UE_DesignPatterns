// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Camera/CameraComponent.h"
#include "InteractableComponent.h"
#include "InteractionComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DESIGNPATTERNS_API UInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

	// The camera component attached to the BaseCharacter class
	TWeakObjectPtr<UCameraComponent> CameraComp;
	FTimerHandle InteractionTimerHandle;

	TWeakObjectPtr<UInteractableComponent> InteractableComp;
	TWeakObjectPtr<UPlayerHud> PlayerHud;

	UPROPERTY(EditDefaultsOnly, Category = "InteractionSystem")
	float InteractionDist = 100.0f;
	UPROPERTY(EditDefaultsOnly, Category = "InteractionSystem")
	float InteractionRadius = 10.0f;
	// In terms of fps
	UPROPERTY(EditDefaultsOnly, Category = "InteractionSystem")
	float InteractionTickSpeed = 30.0f;
	float InteractionTickTime = 0.03f;
	
public:
	// Called by the base character
	void StartTimer();
	// Sets default values for this component's properties
	UInteractionComponent();

	void TryInteract();

protected:

	void InteractionTick();
	TWeakObjectPtr<UInteractableComponent> CheckForInteractable();

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
		
};
