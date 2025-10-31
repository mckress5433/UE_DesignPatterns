// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseSword.h"

#include "DesignPatterns/DesignPatterns.h"
#include "DesignPatterns/Player/BaseCharacter.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABaseSword::ABaseSword()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SM_Hilt = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM_Hilt"));
	RootComponent = SM_Hilt;
	SM_Hilt->SetCollisionResponseToChannel(ECC_Interactable, ECR_Block);
	
	SM_Blade = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM_Blade"));
	SM_Blade->SetCollisionResponseToChannel(ECC_Interactable, ECR_Block);
	SM_Blade->SetupAttachment(SM_Hilt);
	
	SM_Crossguard = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM_Crossguard"));
	SM_Crossguard->SetCollisionResponseToChannel(ECC_Interactable, ECR_Block);
	SM_Crossguard->SetupAttachment(SM_Hilt);
	
	SM_Pommel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM_Pommel"));
	SM_Pommel->SetCollisionResponseToChannel(ECC_Interactable, ECR_Block);
	SM_Pommel->SetupAttachment(SM_Hilt);
	
	InteractableComponent = CreateDefaultSubobject<UInteractableComponent>(TEXT("InteractableComponent"));
	
	StatsWidgetRoot = CreateDefaultSubobject<USceneComponent>(TEXT("StatsWidgetRoot"));
	StatsWidgetRoot->SetupAttachment(SM_Hilt);

	WidgetComp = CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetComp"));
	WidgetComp->SetHiddenInGame(true);
	WidgetComp->SetupAttachment(StatsWidgetRoot);
	
}

void ABaseSword::AssembleSword(const FSwordInfo& swInfo)
{
	SwordInfo = swInfo;
	SM_Blade->SetStaticMesh(swInfo.BladeMesh);
	SM_Crossguard->SetStaticMesh(swInfo.CrossguardMesh);
	SM_Hilt->SetStaticMesh(swInfo.HiltMesh);
	SM_Pommel->SetStaticMesh(swInfo.PommelMesh);
}

// Called when the game starts or when spawned
void ABaseSword::BeginPlay()
{
	Super::BeginPlay();

	if (UWorld* world = GetWorld(); world != nullptr)
	{
		if (APlayerController* controller = UGameplayStatics::GetPlayerController(world, 0); controller != nullptr)
		{
			if (auto baseCharacter = Cast<ABaseCharacter>(controller->GetPawn()); baseCharacter != nullptr)
			{
				CameraComponent = baseCharacter->GetCameraComponent();
			}
		}
	}
	
	InteractableComponent->OnBeginHoverEvent.BindUFunction(this, FName("OnBeginHover"));
	InteractableComponent->OnEndHoverEvent.BindUFunction(this, FName("OnEndHover"));
	InteractableComponent->OnInteractEvent.BindUFunction(this, FName("OnInteract"));
}

void ABaseSword::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	StatsWidgetPositionTimerHandle.Invalidate();
	
	InteractableComponent->OnBeginHoverEvent.Unbind();
	InteractableComponent->OnEndHoverEvent.Unbind();
	InteractableComponent->OnInteractEvent.Unbind();
}

void ABaseSword::OnBeginHover()
{
	//SwordStatsWidget->SetHiddenInGame(false);

	if (UWorld* world = GetWorld(); world != nullptr)
	{
		StatWidgetPositionTickTime = 1/StatWidgetPositionTickSpeed;
		world->GetTimerManager().SetTimer(StatsWidgetPositionTimerHandle, this, &ABaseSword::SetWidgetPositionTick, StatWidgetPositionTickTime, true);
	}
}

void ABaseSword::OnEndHover()
{
	//SwordStatsWidget->SetHiddenInGame(true);
	StatsWidgetPositionTimerHandle.Invalidate();
}

void ABaseSword::OnInteract_Implementation()
{
	
}

void ABaseSword::SetWidgetPositionTick()
{
	FVector CameraLocation = CameraComponent->GetComponentLocation();
	FVector StatsRootLocation = StatsWidgetRoot->GetComponentLocation();

	FVector newWidgetLocation = FMath::Lerp(StatsRootLocation, CameraLocation, 0.75f);
	WidgetComp->SetWorldLocation(newWidgetLocation);
}

