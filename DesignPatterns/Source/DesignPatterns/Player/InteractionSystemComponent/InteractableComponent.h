// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Components/ActorComponent.h"
#include "InteractableComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DESIGNPATTERNS_API UInteractableComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this component's properties
	UInteractableComponent();

	// Triggered when InteractionComponent::InteractableComp is set to this object
	UFUNCTION(BlueprintNativeEvent)
	void BeginHover();

	// Triggered when InteractionComponent::InteractableComp is no longer set to this object
	UFUNCTION(BlueprintNativeEvent)
	void EndHover();
};
