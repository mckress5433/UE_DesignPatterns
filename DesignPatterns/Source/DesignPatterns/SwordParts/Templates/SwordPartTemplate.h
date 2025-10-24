#pragma once
#include "SwordPartTemplate.generated.h"

USTRUCT(BlueprintType)
struct FSwordPartTemplate : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UStaticMesh* PartMesh;
	
};
