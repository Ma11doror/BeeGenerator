#include "BeeGenerator/Public/Data/AsyncAssetManager.h"

UAsyncAssetManager* UAsyncAssetManager::GetAsyncAssetManager()
{
	UAsyncAssetManager* AssetManager = Cast<UAsyncAssetManager>(GEngine->AssetManager);
	checkf(AssetManager, TEXT("Invalid AssetManager"));
	return AssetManager;
}

void UAsyncAssetManager::LoadBodyPartAssetAsync(FPrimaryAssetId BodyPartId, const FOnBodyPartLoaded OnLoadDelegate)
{
	if(!BodyPartId.IsValid()) { return; }

	UObject* Asset = GetPrimaryAssetObject(BodyPartId);
	if(Asset != nullptr)
	{
		UBodyPartAsset* BodyPartAsset = Cast<UBodyPartAsset>(Asset);
		OnLoadDelegate.ExecuteIfBound(BodyPartAsset);
	}
	else
	{
		const TSharedPtr<FStreamableHandle> LoadHandle = LoadPrimaryAsset(BodyPartId,  TArray<FName>());
		if(LoadHandle.IsValid())
		{
			if(!LoadHandle->HasLoadCompleted())
			{
				LoadHandle->BindCompleteDelegate(FStreamableDelegate::CreateUObject(this, &ThisClass::OnBodyPartAssetLoaded, LoadHandle, OnLoadDelegate));
			}
		}
	}
	
}

void UAsyncAssetManager::OnBodyPartAssetLoaded(TSharedPtr<FStreamableHandle> LoadHandle, FOnBodyPartLoaded DelegateToCall) const
{
	if(!LoadHandle.IsValid()) { return; }

	UBodyPartAsset* BodyPartAsset = Cast<UBodyPartAsset>(LoadHandle->GetLoadedAsset());
	DelegateToCall.ExecuteIfBound(BodyPartAsset);
	LoadHandle.Reset();
}
