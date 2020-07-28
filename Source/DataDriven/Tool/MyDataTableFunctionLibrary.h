// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved. 

#pragma once
#include "Engine/DataTable.h"
#include "MyDataTableFunctionLibrary.generated.h"

USTRUCT(BlueprintType)
struct FVolumeItem :public FTableRowBase
{
	GENERATED_BODY();
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString Name;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FBoxSphereBounds Bound;
};


UCLASS(Blueprintable, Category = "DataDriven")
class UMyDataTableFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
#if WITH_EDITOR
	UFUNCTION(BlueprintCallable, Category = "Editor Scripting | DataTable", DisplayName = "AddRowToDataTable")
		static void AddVolumeToDataTable(UDataTable* DataTable, FName rowName,const FVolumeItem& row);

	UFUNCTION(BlueprintCallable, Category = "Editor Scripting | DataTable", DisplayName = "ClearDataTable")
		static void ClearDataTable(UDataTable* DataTable);

	UFUNCTION(BlueprintCallable, Category = "Editor Scripting | DataTable", DisplayName = "DataTable_RemoveRow")
		static void DataTable_RemoveRow(UDataTable* DataTable, FName rowName);
#endif
};

