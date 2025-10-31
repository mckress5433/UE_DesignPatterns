#pragma once
#include "SwordPartTemplate.h"
#include "PommelTemplate.generated.h"

USTRUCT(BlueprintType)
struct FPommelTemplate : public FSwordPartTemplate
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 MaxDamage;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 MinDamage;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 MaxDefense;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 MinDefense;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 MaxAttackSpeed;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 MinAttackSpeed;
};
