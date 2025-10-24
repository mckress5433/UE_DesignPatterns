#pragma once
#include "SwordPartTemplate.h"
#include "PommelTemplate.generated.h"

USTRUCT(BlueprintType)
struct FPommelTemplate : public FSwordPartTemplate
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MaxDamage;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MinDamage;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MaxDefense;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MinDefense;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MaxAttackSpeed;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MinAttackSpeed;
};
