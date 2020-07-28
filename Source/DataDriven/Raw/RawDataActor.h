// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Types/DDTypes.h"
#include "RawDataActor.generated.h"

UCLASS(BlueprintType,Blueprintable)
class ARawDataActor :public AActor
{
	GENERATED_BODY()
public:
	ARawDataActor();
public:
	virtual void BeginPlay()override;
public:
	UFUNCTION(BlueprintCallable)
		FString ReadTxtFile(FString path);

	UFUNCTION(BlueprintCallable)
		bool LoadCsvAsTable(FString path,TArray<FShopItem>& Items);

	UFUNCTION(BlueprintCallable)
		bool LoadJsonAsTable(FString path,TArray<FShopItem>& Items);
};