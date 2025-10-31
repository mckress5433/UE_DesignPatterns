#include "GlobalUtilityMethods.h"


int32 GlobalUtilityMethods::GetRandomInt32InRange(const int32 Min, const int32 Max)
{
	const int32 range = Max - Min;
	if (range == 0)
	{
		return Min;
	}
	return (FMath::Rand32() % range) + Min;
}
