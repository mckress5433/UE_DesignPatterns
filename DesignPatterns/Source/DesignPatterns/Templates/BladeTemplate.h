#pragma once
#include "SwordPartTemplate.h"
#include "BladeTemplate.generated.h"

USTRUCT(BlueprintType)
struct FBladeTemplate : public FSwordPartTemplate
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int MaxDamage;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int MinDamage;
};
