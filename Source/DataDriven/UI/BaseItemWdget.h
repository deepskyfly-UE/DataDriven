// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Types/DDTypes.h"

#include "BaseItemWdget.generated.h"

UCLASS(Abstract)
class UBaseItemWdget : public UUserWidget
{
	GENERATED_BODY()
public:
public:
	virtual void NativePreConstruct()override;
	virtual void NativeConstruct()override;
public:
	UPROPERTY(meta = (BindWidget))
		class UImage* IconImage;

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* NameTextBlock;
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* PriceTextBlock;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, meta = (ExposeOnSpawn))
		FShopItem Item;
};
