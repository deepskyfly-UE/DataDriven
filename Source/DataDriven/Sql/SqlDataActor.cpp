// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.


#include "SqlDataActor.h"
#include "Engine/DataTable.h"
#include "SQLiteDatabaseConnection.h"

ASqlDataActor::ASqlDataActor()
{
}

void ASqlDataActor::BeginPlay()
{
	Super::BeginPlay();
}

bool ASqlDataActor::LoadSqlAsTable(FString path, TArray<FShopItem>& Items)
{
	FSQLiteDatabaseConnection db;
	if (!db.Open(*path, nullptr, nullptr))
	{
		return false;
	}

	FString query = FString::Printf(TEXT("SELECT Name,Icon,Price FROM ShopItems"));

	FDataBaseRecordSet* outRecords = nullptr;
	if (!db.Execute(*query, outRecords))
	{
		delete outRecords;
		return false;
	}

	int count = outRecords->GetRecordCount();
	if (count == 0)
	{
		delete outRecords;
		return false;
	}

	int result = -1;
	for (FDataBaseRecordSet::TIterator i(outRecords); i; ++i)
	{
		FShopItem& newItem = Items.AddDefaulted_GetRef();
		for (FDatabaseColumnInfo column : i->GetColumnNames())
		{
			if (column.ColumnName == TEXT("Name"))
			{
				newItem.Name = FText::FromString(i->GetString(*column.ColumnName));

			}
			else if (column.ColumnName == TEXT("Icon"))
			{
				newItem.Icon = LoadObject<UTexture2D>(nullptr, *i->GetString(*column.ColumnName));
			}
			else if (column.ColumnName == TEXT("Price"))
			{
				newItem.Price = i->GetFloat(*column.ColumnName);
			}

		}

	}
	delete outRecords;
	db.Close();
	
	return true;
}

