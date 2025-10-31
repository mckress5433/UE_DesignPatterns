// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseLootChest.h"

#include "DesignPatterns/Builders/RandomSwordBuilder.h"
#include "DesignPatterns/Builders/SwordDirector.h"
#include "DesignPatterns/Player/InteractionSystemComponent/InteractionComponent.h"
#include "DesignPatterns/Weapons/BaseSword.h"

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

	ItemSpawnLocation = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemSpawnLocation"));
	ItemSpawnLocation->SetupAttachment(LootChestMesh);
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
	if (UWorld* world =  GetWorld(); world != nullptr)
	{
		if (IsValid(SwordClass))
		{
			// Spawn Sword
			FActorSpawnParameters SpawnParameters;
			SpawnParameters.Owner = this;
			SpawnParameters.Instigator = GetInstigator();
			SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

			FVector SpawnLocation = ItemSpawnLocation->GetComponentLocation();
			FRotator SpawnRotation = ItemSpawnLocation->GetComponentRotation();

			ABaseSword* SwordItem = world->SpawnActor<ABaseSword>(SwordClass, SpawnLocation, SpawnRotation, SpawnParameters);

			// Build Sword
			if (SwordItem != nullptr)
			{
				RandomSwordBuilder* swordBuilder = new RandomSwordBuilder();
				SwordDirector::ConstructSword(swordBuilder);
				FSwordInfo swordInfo = swordBuilder->GetResult();
			
				SwordItem->AssembleSword(swordBuilder->GetResult());
			}
			else
			{
				UE_LOG(LogBuilder, Error, TEXT("Failed to Spawn sword!"))
			}
		}
		else
		{
			UE_LOG(LogBuilder, Error, TEXT("SwordClass is not valid because it was not set!"));
		}
	}
}


