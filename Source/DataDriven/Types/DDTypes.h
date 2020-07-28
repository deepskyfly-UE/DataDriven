// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "DDTypes.generated.h"

USTRUCT(BlueprintType)
struct FShopItem:public FTableRowBase
{
	GENERATED_BODY();
public:
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
		FText Name;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UTexture2D* Icon;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float Price;
};