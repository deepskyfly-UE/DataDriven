// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Types/DDTypes.h"

#include "PlayerWidget.generated.h"

UCLASS(Abstract)
class UPlayerWidget : public UUserWidget
{
	GENERATED_BODY()
public:
public:
	virtual void NativePreConstruct()override;
	virtual void NativeConstruct()override;
public:
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* DifficultyTextBlock;
};
