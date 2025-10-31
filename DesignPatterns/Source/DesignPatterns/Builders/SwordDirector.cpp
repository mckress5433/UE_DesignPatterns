#include "SwordDirector.h"

void SwordDirector::ConstructSword(SwordBuilder* Builder)
{
	Builder->Reset();
	Builder->BuildBlade();
	Builder->BuildCrossguard();
	Builder->BuildHilt();
	Builder->BuildPommel();
}
