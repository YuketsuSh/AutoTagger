// Copyright Yuketsu. All Rights Reserved.

#include "AutoTagger.h"

#include "AssetData.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Logging/LogMacros.h"


#define LOCTEXT_NAMESPACE "FAutoTaggerModule"

void FAutoTaggerModule::StartupModule()
{
	UE_LOG(LogTemp, Warning, TEXT("AutoTagger Plugin loaded successfully"));

	TagAssetsByRules();
}

void FAutoTaggerModule::ShutdownModule()
{
	UE_LOG(LogTemp, Warning, TEXT("AutoTagger Plugin Unloaded"));
}


void FAutoTaggerModule::TagAssetsByRules()
{
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	IAssetRegistry& AssetRegistry = AssetRegistryModule.Get();

	TArray<FAssetData> AssetList;
	AssetRegistry.GetAllAssets(AssetList);

	for (const FAssetData& Asset : AssetList) {
		FString AssetName = Asset.AssetName.ToString();
		FString AssetPath = Asset.ObjectPath.ToString();

		if (AssetName.Contains("Wall")) {
			UE_LOG(LogTemp, Warning, TEXT("Asset: %s has been tagged as 'Mur'"), *AssetName);
		}
	}

}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FAutoTaggerModule, AutoTagger)