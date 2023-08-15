#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Data/AssetTypes/BodyTypesRow.h"
#include "UtilityFunctionLibrary.generated.h"

class UDataTable;

namespace GLOBAL_HARDCODED
{
	inline const FSoftObjectPath DATA_TABLE_LIBRARY = FSoftObjectPath(TEXT("/Game/Data/DataTablesLibrary.DataTablesLibrary"));
}


UCLASS()
class BEEGENERATOR_API UUtilityFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static UDataTable* GetDataTableFromLibrary(EDataTableLibraryType InType);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static FPrimaryAssetId GetRandomFromDataTable(UDataTable* InDataTable);
};
