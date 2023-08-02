#pragma once

#include "CoreMinimal.h"


UENUM(BlueprintType)
enum class EBodyPartType : uint8
{
	None,
	Body,
	Wings,
	Legs,
	Antenna
	
};
ENUM_RANGE_BY_FIRST_AND_LAST(EBodyPartType, EBodyPartType::None, EBodyPartType::Antenna)