
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

class UAsyncAssetManager;
class UBodyPartAsset;

UCLASS()
class BEEGENERATOR_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ACharacterBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Customisible Meshes", Transient)
	USkeletalMeshComponent* BodySlot;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Customisible Meshes", Transient)
	USkeletalMeshComponent* WingsSlot;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Customisible Meshes", Transient)
	USkeletalMeshComponent* LegsSlot;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Customisible Meshes", Transient)
	USkeletalMeshComponent* AntennaSlot;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Customisible Meshes", Transient)
	USkeletalMeshComponent* AccessorySlot;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Customisible Meshes", Transient)
	USkeletalMeshComponent* EyesSlot;
	
	

	DECLARE_DELEGATE_OneParam(FBodyPartLoaded, const UBodyPartAsset* /* */)
	FBodyPartLoaded OnBodyPartLoadFinished;

	UFUNCTION(BlueprintImplementableEvent)
	void ApplyBodyPart(const UBodyPartAsset* InBodyPartAsset);

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void AsyncLoadBodyPart(const TArray<FPrimaryAssetId> InBodyPartsArray);

	void OnBodyPartLoaded(const UBodyPartAsset* BodyPartAsset);

private:
	UPROPERTY()
	TWeakObjectPtr<UAsyncAssetManager> AssetManager = nullptr;
};
