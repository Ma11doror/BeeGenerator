
#pragma once

#include "CoreMinimal.h"
#include "BodyPartTypes.h"
#include "Engine/DataAsset.h"
#include "BodyPartAsset.generated.h"


UCLASS()
class BEEGENERATOR_API UBodyPartAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	USkeletalMesh* BodyPartSkeletalMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EBodyPartType BodyPartType = EBodyPartType::None;

	
	FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("BodyPartAsset", GetFName());
	}
};
