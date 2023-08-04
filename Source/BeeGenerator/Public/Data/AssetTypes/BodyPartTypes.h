#pragma once

#include "CoreMinimal.h"


UENUM(BlueprintType)
enum class EBodyPartType : uint8
{
	None,
	Eyes,
	Wings,
	Legs,
	Antenna,
	Accessories
	
};
ENUM_RANGE_BY_FIRST_AND_LAST(EBodyPartType, EBodyPartType::None, EBodyPartType::Accessories)