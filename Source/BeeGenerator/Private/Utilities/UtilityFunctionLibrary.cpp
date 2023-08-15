// Fill out your copyright notice in the Description page of Project Settings.


#include "Utilities/UtilityFunctionLibrary.h"

UDataTable* UUtilityFunctionLibrary::GetDataTableFromLibrary(EDataTableLibraryType InType)
{
	using namespace GLOBAL_HARDCODED;
	
	if (!ensure(DATA_TABLE_LIBRARY.IsValid())) { return nullptr; }
	
	const UDataTable* DataTableLibrary = Cast<UDataTable>(DATA_TABLE_LIBRARY.ResolveObject());
	
	if (!DataTableLibrary)
	{
		DataTableLibrary = Cast<UDataTable>(DATA_TABLE_LIBRARY.TryLoad());
	}
	
	if (!ensure(DataTableLibrary))	{ return nullptr; }

	UDataTable* Result = nullptr;
	DataTableLibrary->ForeachRow<FDataTableLibraryRow>(*FString(__FUNCTION__),[&](const FName& Key, const FDataTableLibraryRow& Row)
	{
		if (Row.Type == InType)
		{
			Result = Row.Datatable;
		}
	});
	return Result;
}

FPrimaryAssetId UUtilityFunctionLibrary::GetRandomFromDataTable(UDataTable* InDataTable)
{
	check(InDataTable);

	UPrimaryDataAsset* Result = nullptr;
	TArray<FBodyPart*> RowNames;

	InDataTable->GetAllRows(StringCast<TCHAR>(__FUNCTION__).Get(), RowNames);
	const auto Asset = RowNames[FMath::RandRange(0, RowNames.Num() - 1)]->BodyAsset;
	return Asset->GetPrimaryAssetId();
}
