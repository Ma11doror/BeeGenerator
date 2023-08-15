#pragma once

//#include "CoreMinimal.h"
#include "BodyPartAsset.h"
#include "BodyPartTypes.h"
#include "Engine/DataTable.h"
#include "BodyTypesRow.generated.h"

UENUM(BlueprintType)
enum class EDataTableLibraryType : uint8
{
	None,
	Bodies,
	Eyes,
	Wings,
	Limbs,
	Antenna,
	Accessories
};

USTRUCT(BlueprintType)
struct FBodyPart : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
	
public:
	FBodyPart():
	BodyAsset()
	{}

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBodyPartAsset* BodyAsset = nullptr;
};

USTRUCT(BlueprintType)
struct FDataTableLibraryRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	EDataTableLibraryType Type = EDataTableLibraryType::None;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	UDataTable* Datatable = nullptr;
};
