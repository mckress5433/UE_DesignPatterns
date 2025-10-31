// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DesignPatterns/Global/GlobalStructs.h"
#include "DesignPatterns/Player/InteractionSystemComponent/InteractableComponent.h"
#include "GameFramework/Actor.h"
#include "BaseSword.generated.h"

UCLASS()
class DESIGNPATTERNS_API ABaseSword : public AActor
{
	GENERATED_BODY()
	

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* SM_Blade;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* SM_Crossguard;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* SM_Hilt;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* SM_Pommel;

	UPROPERTY(EditDefaultsOnly)
	UInteractableComponent* InteractableComponent;

	UPROPERTY(VisibleAnywhere)
	FSwordInfo SwordInfo;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Sets default values for this actor's properties
	ABaseSword();
	
	void AssembleSword(const FSwordInfo& swInfo);
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
