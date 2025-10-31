#pragma once
#include "DesignPatterns/Global/GlobalStructs.h"

DECLARE_LOG_CATEGORY_EXTERN(LogBuilder, Log, All);

class SwordBuilder
{

protected:
	FSwordInfo SwordInfo = FSwordInfo();
	
public:
	virtual ~SwordBuilder() = default;
	virtual void Reset();
	virtual void BuildBlade() PURE_VIRTUAL(SwordBuilder::BuildBlade);
	virtual void BuildCrossguard() PURE_VIRTUAL(SwordBuilder::BuildCrossguard);
	virtual void BuildHilt() PURE_VIRTUAL(SwordBuilder::BuildHilt);
	virtual void BuildPommel() PURE_VIRTUAL(SwordBuilder::BuildPommel);

	virtual FSwordInfo GetResult();
};
