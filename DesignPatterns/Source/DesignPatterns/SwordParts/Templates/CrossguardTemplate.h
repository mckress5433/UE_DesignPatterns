#pragma once
#include "SwordPartTemplate.h"
#include "CrossguardTemplate.generated.h"

USTRUCT(BlueprintType)
struct FCrossguardTemplate : public FSwordPartTemplate
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MaxDefense;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MinDefense;
};
