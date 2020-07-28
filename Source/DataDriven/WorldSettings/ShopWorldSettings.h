// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/WorldSettings.h"
#include "ShopWorldSettings.generated.h"

UCLASS(BlueprintType)
class AShopWorldSettings : public AWorldSettings
{
	GENERATED_BODY()
public:
	AShopWorldSettings();

	UPROPERTY(BlueprintReadWrite, EditAnywhere,Category=Shop)
		float LevelDifficulty = 100.f;
};

