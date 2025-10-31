#include "RandomSwordBuilder.h"

#include "DesignPatterns/Global/GlobalUtilityMethods.h"
#include "DesignPatterns/Templates/BladeTemplate.h"
#include "DesignPatterns/Templates/CrossguardTemplate.h"
#include "DesignPatterns/Templates/HiltTemplate.h"
#include "DesignPatterns/Templates/PommelTemplate.h"


RandomSwordBuilder::RandomSwordBuilder()
{
}

void RandomSwordBuilder::BuildBlade()
{
	UDataTable* DataTable = GetRandomDataTableForPart(ESwordPart::Blade);
	FBladeTemplate BladeTemplate = GetRandomRowFromTable<FBladeTemplate>(DataTable);
	SwordInfo.BladeMesh = BladeTemplate.PartMesh;
	SwordInfo.Damage += GlobalUtilityMethods::GetRandomInt32InRange(BladeTemplate.MinDamage, BladeTemplate.MaxDamage);
}

void RandomSwordBuilder::BuildCrossguard()
{
	UDataTable* DataTable = GetRandomDataTableForPart(ESwordPart::Crossguard);
	FCrossguardTemplate CrossguardTemplate = GetRandomRowFromTable<FCrossguardTemplate>(DataTable);
	SwordInfo.CrossguardMesh = CrossguardTemplate.PartMesh;
	SwordInfo.Defense += GlobalUtilityMethods::GetRandomInt32InRange(CrossguardTemplate.MinDefense, CrossguardTemplate.MaxDefense);
}

void RandomSwordBuilder::BuildHilt()
{
	UDataTable* DataTable = GetRandomDataTableForPart(ESwordPart::Hilt);
	FHiltTemplate HiltTemplate = GetRandomRowFromTable<FHiltTemplate>(DataTable);
	SwordInfo.HiltMesh = HiltTemplate.PartMesh;
	SwordInfo.AttackSpeed += GlobalUtilityMethods::GetRandomInt32InRange(HiltTemplate.MinAttackSpeed, HiltTemplate.MaxAttackSpeed);
}

void RandomSwordBuilder::BuildPommel()
{
	UDataTable* DataTable = GetRandomDataTableForPart(ESwordPart::Pommel);
	FPommelTemplate PommelTemplate = GetRandomRowFromTable<FPommelTemplate>(DataTable);
	SwordInfo.PommelMesh = PommelTemplate.PartMesh;
	SwordInfo.Damage += GlobalUtilityMethods::GetRandomInt32InRange(PommelTemplate.MinDamage, PommelTemplate.MaxDamage);
	SwordInfo.Defense += GlobalUtilityMethods::GetRandomInt32InRange(PommelTemplate.MinDefense, PommelTemplate.MaxDefense);
	SwordInfo.AttackSpeed += GlobalUtilityMethods::GetRandomInt32InRange(PommelTemplate.MinAttackSpeed, PommelTemplate.MaxAttackSpeed);
}

UDataTable* RandomSwordBuilder::GetRandomDataTableForPart(ESwordPart SwordPart)
{
	int32 randInt = FMath::Rand32();
	ERace randRace = static_cast<ERace>(randInt % ERace::RACE_COUNT);
	return GetDataTableForPartAndRace(SwordPart, randRace);
}

UDataTable* RandomSwordBuilder::GetDataTableForPartAndRace(ESwordPart Part, ERace Race)
{
	FString SwordPartName = GetSwordPartName(Part);
	FString RaceName = GetRaceName(Race);
	FString Directory = TEXT("/Game/Blueprints/Weapons/DataTables/") + SwordPartName + TEXT("s/");
	FString AssetName = RaceName + SwordPartName + TEXT("Templates");
	FString Path = Directory + AssetName + TEXT(".") + AssetName;

	UDataTable* DataTable = LoadObject<UDataTable>(nullptr, *Path);
	if (DataTable == nullptr)
	{
		UE_LOG(LogBuilder, Fatal, TEXT("Failed to find DataTable using path = %s"), *Path);
	}
	
	return DataTable;
}

template<std::derived_from<FSwordPartTemplate> T>
T RandomSwordBuilder::GetRandomRowFromTable(const UDataTable* DataTable)
{
	TArray<T*> SwordPartTemplate;
	DataTable->GetAllRows<T>(TEXT("RandomSwordPart"), SwordPartTemplate);
	int numRows = SwordPartTemplate.Num();
	int randIndex = 0;
	if (numRows > 0)
	{
		int32 randInt = FMath::Rand32();
		randIndex = randInt % numRows;
	}
	else
	{
		UE_LOG(LogBuilder, Fatal, TEXT("Failed get random row! DataTable is empty: %s"), *DataTable->GetName());
	}
	return *SwordPartTemplate[randIndex];
}