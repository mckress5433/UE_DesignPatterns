#pragma once
#include "SwordBuilder.h"
#include "DesignPatterns/Global/GlobalEnums.h"
#include "DesignPatterns/Templates/SwordPartTemplate.h"

class RandomSwordBuilder : public SwordBuilder
{
public:
	RandomSwordBuilder();

	virtual void BuildBlade() override;
	virtual void BuildCrossguard() override;
	virtual void BuildHilt() override;
	virtual void BuildPommel() override;

private:
	// Returns a Random DataTable based on the sword part
	UDataTable* GetRandomDataTableForPart(ESwordPart SwordPart);
	// Returns a Random DataTable based on the sword part and race
	UDataTable* GetDataTableForPartAndRace(ESwordPart Part, ERace Race);

	// returns a random row from the data tableRans
	template<std::derived_from<FSwordPartTemplate> T>
	T GetRandomRowFromTable(const UDataTable* DataTable);
	
	
};


