// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionComponent.h"

#include "KismetTraceUtils.h"
#include "DesignPatterns/DesignPatterns.h"
#include "DesignPatterns/Global/GlobalConsoleVariables.h"
#include "DesignPatterns/Player/BaseCharacter.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values for this component's properties
UInteractionComponent::UInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}

void UInteractionComponent::TryInteract()
{
	if (InteractableComp != nullptr)
	{
		InteractableComp->Interact();
	}
}


// Called when the game starts
void UInteractionComponent::StartTimer()
{
	if (auto character = static_cast<ABaseCharacter*>(GetOwner()); character != nullptr)
	{
		CameraComp = MakeWeakObjectPtr<UCameraComponent>(character->GetCameraComponent());
		PlayerHud = MakeWeakObjectPtr<UPlayerHud>(character->GetPlayerHud());

		if (UWorld* world = character->GetWorld(); world != nullptr)
		{
			InteractionTickTime = 1/InteractionTickSpeed;
			world->GetTimerManager().SetTimer(InteractionTimerHandle, this, &UInteractionComponent::InteractionTick, InteractionTickTime, true);
		}
	}
}

void UInteractionComponent::InteractionTick()
{
	TWeakObjectPtr<UInteractableComponent> foundInteractable = CheckForInteractable();

	if (foundInteractable.IsValid())
	{
		if (PlayerHud.IsValid())
		{
			PlayerHud->SetInteractionPromptVisibility(true);
		}

		bool bIsInteractableValid = InteractableComp.IsValid();
		if (!bIsInteractableValid || foundInteractable.Get() != InteractableComp.Get())
		{
			if (bIsInteractableValid)
			{
				InteractableComp->EndHover();
			}
			foundInteractable->BeginHover();
			InteractableComp = foundInteractable;
		}
	}
	else if (InteractableComp.IsValid())
	{
		InteractableComp->EndHover();
		InteractableComp.Reset();

		if (PlayerHud.IsValid())
		{
			PlayerHud->SetInteractionPromptVisibility(false);
		}
	}
	
}

TWeakObjectPtr<UInteractableComponent> UInteractionComponent::CheckForInteractable()
{
	TWeakObjectPtr<UInteractableComponent> foundInteractable;

	if (UWorld* world = GetWorld(); world != nullptr && CameraComp.IsValid())
	{
		if (UCameraComponent* cameraPtr = CameraComp.Get(false); cameraPtr != nullptr)
		{
			FVector cameraLocation = cameraPtr->GetComponentLocation();
			FVector CameraForwardVector = cameraPtr->GetForwardVector();
			FVector traceEnd = cameraLocation + (CameraForwardVector * InteractionDist);
			TArray<AActor*> IgnoredActors;
			IgnoredActors.Add(GetOwner());

			EDrawDebugTrace::Type debugFlag = static_cast<EDrawDebugTrace::Type>(GInteractionDebugVariable.GetValueOnAnyThread(false));
			FCollisionQueryParams CollisionQueryParams;
			CollisionQueryParams.AddIgnoredActors(IgnoredActors);
			
			FHitResult lineTraceResult;
			
			world->LineTraceSingleByChannel(
				lineTraceResult,
				cameraLocation,
				traceEnd,
				ECC_Interactable,
				CollisionQueryParams
				);

			if (debugFlag != EDrawDebugTrace::None)
			{
				DrawDebugLineTraceSingle(
					world,
					cameraLocation,
					traceEnd,
					debugFlag,
					lineTraceResult.bBlockingHit,
					lineTraceResult,
					FColor::Green,
					FColor::Orange,
					InteractionTickTime);
			}

			// If we hit an interactable actor with the line trace then we are done here
			if (lineTraceResult.bBlockingHit)
			{
				if (AActor* hitActor = lineTraceResult.GetActor(); hitActor != nullptr)
				{
					if (auto interactableComp =	hitActor->FindComponentByClass<UInteractableComponent>(); interactableComp != nullptr)
					{
						if (interactableComp->CanInteract())
						{
							return MakeWeakObjectPtr<UInteractableComponent>(interactableComp);
						}
					}
				}
			}

			// Otherwise we need consider the surrounding area
			FVector hitLocation = lineTraceResult.bBlockingHit ? lineTraceResult.ImpactPoint : traceEnd;
			float shortestDist = FMath::Sqrt(FMath::Square(InteractionRadius) + FMath::Square(InteractionDist));
			TArray<FHitResult> outHits;

			world->SweepMultiByChannel(
				outHits,
				cameraLocation,
				traceEnd,
				FQuat::Identity,
				ECC_Interactable,
				FCollisionShape::MakeSphere(InteractionRadius),
				CollisionQueryParams
				);

			bool bHit = false;
			
			for (FHitResult& hitResult : outHits)
			{
				if (hitResult.bBlockingHit)
				{
					bHit = true;
				}
				
				if (AActor* hitActor = hitResult.GetActor(); hitActor != nullptr)
				{
					if (auto interactableComp = hitActor->FindComponentByClass<UInteractableComponent>(); interactableComp != nullptr)
					{
						if (interactableComp->CanInteract())
						{
							float distToHit = (hitResult.ImpactPoint - hitLocation).Length();
							if (distToHit < shortestDist)
							{
								foundInteractable = MakeWeakObjectPtr<UInteractableComponent>(interactableComp);
							}
						}
					}
				}
			}

			if (debugFlag != EDrawDebugTrace::None)
			{
				DrawDebugSphereTraceMulti(
					world,
					cameraLocation,
					traceEnd,
					InteractionRadius,
					debugFlag,
					bHit,
					outHits,
					FColor::Cyan,
					FColor::Red,
					InteractionTickTime);
			}
		}
	}
	return foundInteractable;
}

void UInteractionComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	InteractionTimerHandle.Invalidate();
}



