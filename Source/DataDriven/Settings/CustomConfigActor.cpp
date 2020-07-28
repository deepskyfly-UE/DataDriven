// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.


#include "CustomConfigActor.h"

ACustomConfigActor::ACustomConfigActor()
{
}

void ACustomConfigActor::BeginPlay()
{
	Super::BeginPlay();
	LoadConfig();
}

void ACustomConfigActor::AddMaxLifeAndSave(float val)
{
	MaxLife+=val;
	SaveConfig();
}

static TAutoConsoleVariable<FString> CVarSusiPassword(
	TEXT("susi.Password"),
	TEXT("INVALID_DEFAULT"),
	TEXT("The password to log into SUSI with."),
	ECVF_Default);