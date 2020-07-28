// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.


#include "ConsoleVariableActor.h"
#include "HAL/IConsoleManager.h"

static TAutoConsoleVariable<bool> CVarDDShopEnabled(
	TEXT("dd.ShopEnabled"),
	false,
	TEXT("The switch to enable shop or not."),
	ECVF_Default);

static TAutoConsoleVariable<int> CVarDDShopCount(
	TEXT("dd.ShopCount"),
	3,
	TEXT("The count of shop."),
	ECVF_Default);

static TAutoConsoleVariable<FString> CVarDDShopName(
	TEXT("dd.ShopName"),
	TEXT("Jack"),
	TEXT("The name of shop."),
	ECVF_Default);

AConsoleVariableActor::AConsoleVariableActor()
{
	PrimaryActorTick.bCanEverTick=true;
}

void AConsoleVariableActor::BeginPlay()
{
	Super::BeginPlay();
}

void AConsoleVariableActor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	FString str=FString::Printf(TEXT("dd.ShopEnabled: %s"), CVarDDShopEnabled.GetValueOnGameThread()?TEXT("true"):TEXT("false"));
	str += FString::Printf(TEXT("\ndd.ShopCount: %d"), CVarDDShopCount.GetValueOnGameThread());
	str += FString::Printf(TEXT("\ndd.ShopName: %s"), *CVarDDShopName.GetValueOnGameThread());
	
	GEngine->AddOnScreenDebugMessage(0,5.f,FColor::Red, str);

}
