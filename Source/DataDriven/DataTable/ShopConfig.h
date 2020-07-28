// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved. 

#pragma once
#include "Engine/DataTable.h"
#include "ShopConfig.generated.h"

struct FShopItem;

UCLASS(Blueprintable, Category = "DataDriven")
class UShopConfig : public UObject
{
	GENERATED_BODY()
public:
	virtual bool Initialize();
public:
	UFUNCTION(BlueprintPure, DisplayName = "ShopConfig")
		static UShopConfig* Get();

public:
	void GetAllItems(TArray<FShopItem*>& outItems);
protected:
	UPROPERTY()
		UDataTable* mItemsDataTable;
};

