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

	UPROPERTY(EditDefaultsOnly)
	float InteractionDist = 100.0f;
	UPROPERTY(EditDefaultsOnly)
	float InteractionRadius = 10.0f;
	
public:	
	// Sets default values for this component's properties
	UInteractionComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void InteractionTick();
	TWeakObjectPtr<UInteractableComponent> CheckForInteractable();

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
		
};
