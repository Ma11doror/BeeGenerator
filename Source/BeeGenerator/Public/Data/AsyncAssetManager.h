#pragma once

#include "CoreMinimal.h"
#include "AssetTypes/BodyPartAsset.h"
#include "Engine/AssetManager.h"
#include "AsyncAssetManager.generated.h"

UCLASS()
class BEEGENERATOR_API UAsyncAssetManager : public UAssetManager
{
	GENERATED_BODY()

public:

	DECLARE_DELEGATE_OneParam(FOnBodyPartLoaded, const UBodyPartAsset*)

	static  UAsyncAssetManager* GetAsyncAssetManager();
	
	void LoadBodyPartAssetAsync(FPrimaryAssetId BodyPartId, FOnBodyPartLoaded OnLoadDelegate);

	void OnBodyPartAssetLoaded(TSharedPtr<FStreamableHandle> LoadHandle, FOnBodyPartLoaded DelegateToCall) const;
};
