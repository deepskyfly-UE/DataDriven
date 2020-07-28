// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseShopWdget.h"
#include "Components/UniformGridPanel.h"
#include "DataTable/ShopConfig.h"

void UBaseShopWdget::NativePreConstruct()
{
	Super::NativePreConstruct();

	if (ItemWidgetClass == nullptr)
	{
		return;
	}

	ItemsUniformGridPanel->ClearChildren();
	TArray<FShopItem*> outItems;
	UShopConfig::Get()->GetAllItems(outItems);

	for (int32 i = 0; i < outItems.Num(); ++i)
	{
		UBaseItemWdget* itemWidget = CreateWidget<UBaseItemWdget>(ItemsUniformGridPanel, ItemWidgetClass);
		itemWidget->Item = *outItems[i];

		ItemsUniformGridPanel->AddChildToUniformGrid(itemWidget, i / 5, i % 5);
	}
}


void UBaseShopWdget::NativeConstruct()
{
	Super::NativeConstruct();

}
