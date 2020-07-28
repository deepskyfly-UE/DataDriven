// Copyright 2018 Jianzhao Fu. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ExcelTypes.h"
#include "ExcelWorksheet.h"
#include "ExcelVariant.h"
#include <vector>
#include "Engine/EngineTypes.h"

#include "ExcelWorkbook.generated.h"

class UExcelWorkbook;

DECLARE_DYNAMIC_DELEGATE_OneParam(FExcelWorkbookChangedDelegate, UExcelWorkbook*, workbook);

/**
*Excel document object
*/
UCLASS(Blueprintable, BlueprintType, Category = "DirectExcel")
class XLNTLIB_API UExcelWorkbook : public UObject
{
	GENERATED_BODY()
public:
	UExcelWorkbook();
	virtual ~UExcelWorkbook();

public:
	UFUNCTION(BlueprintCallable, Category = "DirectExcel|Workbook", meta = (WorldContext = "WorldContextObject"))
		bool StartWatch(const UObject* WorldContextObject, FExcelWorkbookChangedDelegate onChanged, bool autoReload = true, float rate = 1.f);

	UFUNCTION(BlueprintCallable, Category = "DirectExcel|Workbook", meta = (WorldContext = "WorldContextObject"))
		bool StopWatch(const UObject* WorldContextObject);


	FTimerHandle mWatchTimer;
	void* mFindHandle = nullptr;



};
