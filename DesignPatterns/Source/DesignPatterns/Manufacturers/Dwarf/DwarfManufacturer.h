#pragma once
#include "DwarfBlade.h"
#include "DwarfCrossguard.h"
#include "DwarfHilt.h"
#include "DwarfPommel.h"
#include "DesignPatterns/Manufacturers/SwordFactory.h"

class DwarfManufacturer : public SwordFactory
{
public:
	DwarfManufacturer();
	virtual ~DwarfManufacturer() override;

	virtual Blade* CreateBlade() override { return new DwarfBlade(); }
	virtual Crossguard* CreateCrossguard() override { return new DwarfCrossguard(); }
	virtual Pommel* CreatePommel() override { return new DwarfPommel(); }
	virtual Hilt* CreateHilt() override  { return new DwarfHilt(); }
};
