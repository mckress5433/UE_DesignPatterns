// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "DesignPatterns/Player/InteractionSystemComponent/InteractableComponent.h"
#include "GameFramework/Actor.h"
#include "BaseLootChest.generated.h"

UCLASS()
class DESIGNPATTERNS_API ABaseLootChest : public AActor
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UStaticMeshComponent* LootChestMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* LidMesh;
	
	UPROPERTY(EditDefaultsOnly)
	UInteractableComponent* InteractableComp;
	
public:	
	// Sets default values for this actor's properties
	ABaseLootChest();

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

protected:
	UFUNCTION()
	void OnBeginHover() const;
	UFUNCTION()
	void OnEndHover() const;
	UFUNCTION(BlueprintNativeEvent)
	void OnInteract();
};
