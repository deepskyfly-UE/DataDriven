// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "DataDrivenProjectSettings.generated.h"

UCLASS(config = DataDrivenProjectSettings, defaultconfig)
class UDataDrivenProjectSettings :public UDeveloperSettings
{
	GENERATED_BODY()
public:
	/** Gets the settings container name for the settings, either Project or Editor */
	virtual FName GetContainerName() const override { return TEXT("Project"); }
	/** Gets the category for the settings, some high level grouping like, Editor, Engine, Game...etc. */
	virtual FName GetCategoryName() const override { return TEXT("DataDriven"); }
	/** The unique name for your section of settings, uses the class's FName. */
	virtual FName GetSectionName() const override { return TEXT("DataDriven"); }
public:
	UDataDrivenProjectSettings();

	UFUNCTION(BlueprintPure, DisplayName = "DataDrivenProjectSettings")
		static UDataDrivenProjectSettings* Get() { return GetMutableDefault<UDataDrivenProjectSettings>(); }
public:
	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = Shop)
		float PriceOff = 50.f;

	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = Player)
		float PlayerStartLevel = 10.f;

};