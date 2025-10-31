#pragma once
#include "SwordPartTemplate.h"
#include "CrossguardTemplate.generated.h"

USTRUCT(BlueprintType)
struct FCrossguardTemplate : public FSwordPartTemplate
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 MaxDefense;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 MinDefense;
};
