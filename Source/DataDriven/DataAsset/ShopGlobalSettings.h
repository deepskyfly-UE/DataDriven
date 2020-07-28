// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine/DataAsset.h"

#include "ShopGlobalSettings.generated.h"

UCLASS(BlueprintType)
class UShopGlobalSettings : public UDataAsset
{
	GENERATED_BODY()
public:
	UShopGlobalSettings();
public:
	UFUNCTION(BlueprintPure, DisplayName = "ShopGlobalSettings")
		static UShopGlobalSettings* Get();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float PlayerStartMoney = 100.f;	
};
