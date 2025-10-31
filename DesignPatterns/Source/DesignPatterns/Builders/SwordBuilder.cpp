#include "SwordBuilder.h"
#include "DesignPatterns/Weapons/BaseSword.h"

DEFINE_LOG_CATEGORY(LogBuilder);

void SwordBuilder::Reset()
{
	SwordInfo = FSwordInfo();
}

FSwordInfo SwordBuilder::GetResult()
{
	return SwordInfo;
}
