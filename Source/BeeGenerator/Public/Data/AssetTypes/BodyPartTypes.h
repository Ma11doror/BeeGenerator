#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"


UENUM(BlueprintType)
enum class EBodyPartType : uint8
{
	None,
	Body,
	Eyes,
	Wings,
	Legs,
	Antenna,
	Accessories
	
};
ENUM_RANGE_BY_FIRST_AND_LAST(EBodyPartType, EBodyPartType::None, EBodyPartType::Accessories)
