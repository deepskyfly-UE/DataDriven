// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseItemWdget.h"
#include "BaseShopWdget.generated.h"

UCLASS(Abstract)
class UBaseShopWdget : public UUserWidget
{
	GENERATED_BODY()
public:
public:
	virtual void NativePreConstruct()override;
	virtual void NativeConstruct()override;

public:
	UPROPERTY(meta = (BindWidget))
		class UUniformGridPanel* ItemsUniformGridPanel;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		TSubclassOf<UBaseItemWdget> ItemWidgetClass;
};
