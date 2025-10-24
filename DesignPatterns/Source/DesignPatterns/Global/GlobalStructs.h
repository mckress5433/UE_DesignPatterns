#pragma once
#include "GlobalStructs.generated.h"


USTRUCT(BlueprintType)
struct FSwordInfo
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UStaticMesh* BladeMesh;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UStaticMesh* CrossguardMesh;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UStaticMesh* HiltMesh;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UStaticMesh* PommelMesh;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	float Damage;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	float Defense;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	float AttackSpeed;
};
