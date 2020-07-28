// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseItemWdget.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"

#include "Kismet/KismetTextLibrary.h"

void UBaseItemWdget::NativePreConstruct()
{
	Super::NativePreConstruct();

	NameTextBlock->SetText(Item.Name);
	PriceTextBlock->SetText(UKismetTextLibrary::Conv_FloatToText(Item.Price, ERoundingMode::HalfToEven));
	IconImage->SetBrushFromTexture(Item.Icon);
	IconImage->SetBrushSize(FVector2D(128.f,128.f));
}

void UBaseItemWdget::NativeConstruct()
{
	Super::NativeConstruct();

}