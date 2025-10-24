// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseSword.h"

// Sets default values
ABaseSword::ABaseSword()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

ABaseSword::ABaseSword(const FSwordInfo& swInfo)
{
	SM_Blade->SetStaticMesh(swInfo.BladeMesh);
	SM_Crossguard->SetStaticMesh(swInfo.CrossguardMesh);
	SM_Hilt->SetStaticMesh(swInfo.HiltMesh);
	SM_Pommel->SetStaticMesh(swInfo.PommelMesh);
}

// Called when the game starts or when spawned
void ABaseSword::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseSword::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

