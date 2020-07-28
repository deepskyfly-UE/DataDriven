// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "DataDrivenGameMode.h"
#include "DataDrivenHUD.h"
#include "DataDrivenCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADataDrivenGameMode::ADataDrivenGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ADataDrivenHUD::StaticClass();
}
