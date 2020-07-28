// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ConsoleVariableActor.generated.h"

UCLASS(BlueprintType,Blueprintable)
class AConsoleVariableActor :public AActor
{
	GENERATED_BODY()
public:
	AConsoleVariableActor();
public:
	virtual void BeginPlay()override;
	virtual void Tick(float DeltaSeconds)override;
};