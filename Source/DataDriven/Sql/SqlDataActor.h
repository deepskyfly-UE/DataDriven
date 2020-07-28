// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Types/DDTypes.h"
#include "SqlDataActor.generated.h"

UCLASS(BlueprintType,Blueprintable)
class ASqlDataActor :public AActor
{
	GENERATED_BODY()
public:
	ASqlDataActor();
public:
	virtual void BeginPlay()override;
public:
	UFUNCTION(BlueprintCallable)
		bool LoadSqlAsTable(FString path,TArray<FShopItem>& Items);
};