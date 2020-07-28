// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CustomConfigActor.generated.h"

UCLASS(config = CustomConfig)
class ACustomConfigActor :public AActor
{
	GENERATED_BODY()
public:
	ACustomConfigActor();
public:
	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite, Category = MyCustom)
		float MaxLife = 100.f;

	UPROPERTY(transient, EditAnywhere, BlueprintReadWrite, Category = MyCustom)
		float CurrentLife = 50.f;
public:
	virtual void BeginPlay()override;

	UFUNCTION(BlueprintCallable)
	void AddMaxLifeAndSave(float val);


};