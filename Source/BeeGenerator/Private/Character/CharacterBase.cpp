#include "BeeGenerator/Public/Character/CharacterBase.h"

#include "BeeGenerator/Public/Data/AsyncAssetManager.h"

ACharacterBase::ACharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

	LegsSlot = CreateOptionalDefaultSubobject<USkeletalMeshComponent>("LegsMesh");
	LegsSlot->SetupAttachment(GetMesh());
	
	WingsSlot = CreateOptionalDefaultSubobject<USkeletalMeshComponent>("WingsMesh");
	WingsSlot->SetupAttachment(GetMesh());
	
	AntennaSlot = CreateOptionalDefaultSubobject<USkeletalMeshComponent>("AntennaMesh");
	AntennaSlot->SetupAttachment(GetMesh());
	
	AccessorySlot = CreateOptionalDefaultSubobject<USkeletalMeshComponent>("AccessoryMesh");
	AccessorySlot->SetupAttachment(GetMesh());
	
	EyesSlot = CreateOptionalDefaultSubobject<USkeletalMeshComponent>("AccessoryMesh");
	EyesSlot->SetupAttachment(GetMesh());

}

void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
	AssetManager = UAsyncAssetManager::GetAsyncAssetManager();
}

void ACharacterBase::AsyncLoadBodyPart(const TArray<FPrimaryAssetId> InBodyPartsArray)
{
	if(!AssetManager->IsValid())
	{
		return;
	}

	for( const auto BodyPart : InBodyPartsArray)
	{
		OnBodyPartLoadFinished.BindUObject(this, &ThisClass::OnBodyPartLoaded);
		AssetManager->LoadBodyPartAssetAsync(BodyPart, OnBodyPartLoadFinished);
	}
}

void ACharacterBase::OnBodyPartLoaded(const UBodyPartAsset* BodyPartAsset)
{
	OnBodyPartLoadFinished.Unbind();
	ApplyBodyPart(BodyPartAsset);
}

