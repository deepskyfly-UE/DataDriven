#include "ShopConfig.h"
#include "UObject/ConstructorHelpers.h"
#include "Types/DDTypes.h"

bool UShopConfig::Initialize()
{
	//FString path=TEXT("/Game/Blueprint/DataTable/DT_ShopItems");
	//mItemsDataTable = ConstructorHelpersInternal::FindOrLoadObject<UDataTable>(path);

	mItemsDataTable = LoadObject<UDataTable>(nullptr, TEXT("/Game/Blueprint/DataTable/DT_ShopItems.DT_ShopItems"));

	return mItemsDataTable!=nullptr;
}

UShopConfig* UShopConfig::Get()
{
	return GetMutableDefault<UShopConfig>();
}

void UShopConfig::GetAllItems(TArray<FShopItem*>& outItems)
{
	static const FString ContextString(TEXT("GENERAL"));
	mItemsDataTable->GetAllRows(ContextString,outItems);
}
