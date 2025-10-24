#pragma once
#include "DesignPatterns/SwordParts/Crossguard.h"
#include "DesignPatterns/SwordParts/Hilt.h"
#include "DesignPatterns/SwordParts/Pommel.h"

class Blade;

class SwordFactory
{
public:
	virtual ~SwordFactory() = default;

	virtual Blade* CreateBlade() = 0;
	virtual Crossguard* CreateCrossguard() = 0;
	virtual Pommel* CreatePommel() = 0;
	virtual Hilt* CreateHilt() = 0;
};
