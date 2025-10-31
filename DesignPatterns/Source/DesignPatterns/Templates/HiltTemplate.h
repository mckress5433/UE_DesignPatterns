#pragma once
#include "SwordPartTemplate.h"
#include "HiltTemplate.generated.h"

USTRUCT(BlueprintType)
struct FHiltTemplate : public FSwordPartTemplate
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 MaxAttackSpeed;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 MinAttackSpeed;
};
