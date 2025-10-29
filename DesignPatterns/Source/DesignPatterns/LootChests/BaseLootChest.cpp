// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseLootChest.h"

#include "Components/WidgetComponent.h"
#include "DesignPatterns/Player/InteractionSystemComponent/InteractionComponent.h"

// Sets default values
ABaseLootChest::ABaseLootChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	LootChestMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LootChestMesh"));
	RootComponent = LootChestMesh;

	LidMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LidMesh"));
	LidMesh->SetupAttachment(LootChestMesh);
	
	InteractableComp = CreateDefaultSubobject<UInteractableComponent>(TEXT("InteractionComponent"));
}

void ABaseLootChest::BeginPlay()
{
	Super::BeginPlay();

	InteractableComp->OnBeginHoverEvent.BindUFunction(this, FName("OnBeginHover"));
	InteractableComp->OnEndHoverEvent.BindUFunction(this, FName("OnEndHover"));
	InteractableComp->OnInteractEvent.BindUFunction(this, FName("OnInteract"));
}

void ABaseLootChest::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	InteractableComp->OnBeginHoverEvent.Unbind();
	InteractableComp->OnEndHoverEvent.Unbind();
	InteractableComp->OnInteractEvent.Unbind();
}

void ABaseLootChest::OnBeginHover() const
{
}

void ABaseLootChest::OnEndHover() const
{
}

void ABaseLootChest::OnInteract_Implementation()
{
	
}


