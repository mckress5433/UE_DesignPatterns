// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Components/ActorComponent.h"
#include "InteractableComponent.generated.h"


DECLARE_DYNAMIC_DELEGATE(FOnBeginHover);
DECLARE_DYNAMIC_DELEGATE(FOnEndHover);
DECLARE_DYNAMIC_DELEGATE(FOnInteract);

DECLARE_LOG_CATEGORY_EXTERN(LogInteraction, Log, All);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DESIGNPATTERNS_API UInteractableComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this component's properties
	UInteractableComponent();

	// Triggered when InteractionComponent::InteractableComp is set to this object
	void BeginHover() const;

	// Triggered when InteractionComponent::InteractableComp is no longer set to this object
	void EndHover() const;

	void Interact();

	UPROPERTY()
	FOnBeginHover OnBeginHoverEvent;

	UPROPERTY()
	FOnEndHover OnEndHoverEvent;

	UPROPERTY()
	FOnInteract OnInteractEvent;

	bool CanInteract() const { return !bCanIteractOnce || (bCanIteractOnce && !bHasBeenInteracted);};

protected:
	// If true the player can only interact with the object once
	UPROPERTY(EditDefaultsOnly)
	bool bCanIteractOnce = false;
	bool bHasBeenInteracted = false;
};
