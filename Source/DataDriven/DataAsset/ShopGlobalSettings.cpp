// Fill out your copyright notice in the Description page of Project Settings.

#include "ShopGlobalSettings.h"

UShopGlobalSettings::UShopGlobalSettings()
{
	
}

UShopGlobalSettings* UShopGlobalSettings::Get()
{
	static UShopGlobalSettings* obj=nullptr;
	if (obj==nullptr)
	{
		obj = LoadObject<UShopGlobalSettings>(nullptr, TEXT("/Game/Blueprint/DataAsset/DA_ShopGlobalSettings"));
		obj->AddToRoot();
	}
	return obj;
}
