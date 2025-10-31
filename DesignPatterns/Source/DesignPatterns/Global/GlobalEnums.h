#pragma once

UENUM()
enum ESwordPart : uint8
{
	Blade,
	Crossguard,
	Hilt,
	Pommel,
	SWORD_PART_COUNT
};

UENUM()
enum ERace : uint8
{
	Dwarven,
	Elven,
	Human,
	Orcish,
	RACE_COUNT
};

static FString GetSwordPartName(const ESwordPart SwordPart)
{
	switch (SwordPart)
	{
		case ESwordPart::Blade: return TEXT("Blade");
		case ESwordPart::Crossguard: return TEXT("Crossguard");
		case ESwordPart::Hilt: return TEXT("Hilt");
		case ESwordPart::Pommel: return TEXT("Pommel");
		default: return TEXT("Unknown Part");
	}
}

static FString GetRaceName(const ERace Race)
{
	switch (Race)
	{
		case ERace::Dwarven: return TEXT("Dwarven");
		case ERace::Elven: return TEXT("Elven");
		case ERace::Human: return TEXT("Human");
		case ERace::Orcish: return TEXT("Orcish");
		default: return TEXT("Unknown Race");
	}
}