// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.


#include "RawDataActor.h"
#include "Engine/DataTable.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

ARawDataActor::ARawDataActor()
{
}

void ARawDataActor::BeginPlay()
{
	Super::BeginPlay();
}


FString ARawDataActor::ReadTxtFile(FString path)
{
	FString realPath = FPaths::ProjectDir() / path;
	FString content;
	FFileHelper::LoadFileToString(content, *realPath);
	
	return content;
}

bool ARawDataActor::LoadCsvAsTable(FString path, TArray<FShopItem>& Items)
{
	UDataTable* DataTable = NewObject<UDataTable>(GetTransientPackage(), FName(TEXT("TempDataTable")));
	DataTable->RowStruct = FShopItem::StaticStruct();

	FString realPath = FPaths::ProjectDir() / path;
	FString content;

	if (!FFileHelper::LoadFileToString(content, *realPath))
	{
		return false;
	}

	DataTable->CreateTableFromCSVString(content);	//CreateTableFromJSONString

	static const FString ContextString(TEXT("GENERAL"));
	DataTable->ForeachRow<FShopItem>(ContextString, [&Items](const FName& key, const FShopItem& value)
		{
			Items.Add(value);
		});

	return true;
}

bool ARawDataActor::LoadJsonAsTable(FString path, TArray<FShopItem>& Items)
{
	FString realPath = FPaths::ProjectDir() / path;
	FString content;
	FFileHelper::LoadFileToString(content, *realPath);

	TSharedPtr<FJsonObject> jsonRoot = MakeShareable(new FJsonObject());
	TSharedRef<FJsonStringReader> jsonReader= FJsonStringReader::Create(content);

	TArray<TSharedPtr<FJsonValue>> OutArray;

	if (FJsonSerializer::Deserialize<TCHAR>(jsonReader, OutArray))
	{
		for (TSharedPtr<FJsonValue> itemJson: OutArray)
		{
			const TSharedPtr<FJsonObject>& obj=itemJson->AsObject();
			FShopItem& newItem= Items.AddDefaulted_GetRef();
			newItem.Name=FText::FromString(obj->GetStringField(TEXT("Name")));
			newItem.Icon=LoadObject<UTexture2D>(nullptr,*obj->GetStringField(TEXT("Icon")));
			newItem.Price = obj->GetNumberField(TEXT("Price"));
		}
		return true;
	}
	return false;
}
