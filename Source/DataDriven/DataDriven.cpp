// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "DataDriven.h"
#include "Modules/ModuleManager.h"

#include "DataTable/ShopConfig.h"


void FDataDriven::StartupModule()
{
	UShopConfig::Get()->Initialize();
}

void FDataDriven::ShutdownModule()
{
}



IMPLEMENT_PRIMARY_GAME_MODULE(FDataDriven, DataDriven, "DataDriven");