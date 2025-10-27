// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableComponent.h"

DEFINE_LOG_CATEGORY(LogInteraction);

// Sets default values for this component's properties
UInteractableComponent::UInteractableComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

}

void UInteractableComponent::BeginHover() const
{
	if (OnBeginHoverEvent.IsBound())
	{
		OnBeginHoverEvent.Execute();
	}
	else
	{
		UE_LOG(LogInteraction, Warning, TEXT("BeginHover is not bound"));
	}
}

void UInteractableComponent::EndHover() const
{
	if (OnEndHoverEvent.IsBound())
	{
		OnEndHoverEvent.Execute();
	}
	else
	{
		UE_LOG(LogInteraction, Warning, TEXT("EndHover is not bound"));
	}
}

void UInteractableComponent::Interact()
{
	bHasBeenInteracted = true;
	
	if (OnInteractEvent.IsBound())
	{
		OnInteractEvent.Execute();
	}
	else
	{
		UE_LOG(LogInteraction, Warning, TEXT("Interact is not bound"));
	}
}


