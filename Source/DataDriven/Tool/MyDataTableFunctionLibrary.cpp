#include "MyDataTableFunctionLibrary.h"

void UMyDataTableFunctionLibrary::AddVolumeToDataTable(UDataTable* DataTable, FName rowName, const FVolumeItem& row)
{
	if (DataTable == nullptr)
	{
		return;
	}
	DataTable->AddRow(rowName, row);
	DataTable->GetOutermost()->MarkPackageDirty();
}

void UMyDataTableFunctionLibrary::ClearDataTable(UDataTable* DataTable)
{
	if (DataTable == nullptr)
	{
		return;
	}
	DataTable->EmptyTable();
	DataTable->GetOutermost()->MarkPackageDirty();
}

void UMyDataTableFunctionLibrary::DataTable_RemoveRow(UDataTable* DataTable, FName rowName)
{
	if (DataTable == nullptr)
	{
		return;
	}
	DataTable->RemoveRow(rowName);
	DataTable->GetOutermost()->MarkPackageDirty();
}
