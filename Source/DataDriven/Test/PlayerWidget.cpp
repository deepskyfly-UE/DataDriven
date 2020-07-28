// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerWidget.h"
#include "Components/TextBlock.h"

#include "Kismet/KismetTextLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "WorldSettings/ShopWorldSettings.h"
#include "GameFramework/GameModeBase.h"


void UPlayerWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	
}

void UPlayerWidget::NativeConstruct()
{
	Super::NativeConstruct();

	AWorldSettings* settings= UGameplayStatics::GetGameMode(this)->GetWorld()->GetWorldSettings();
	AShopWorldSettings* shopSettings=Cast<AShopWorldSettings>(settings);
	if (shopSettings!=nullptr)
	{
		DifficultyTextBlock->SetText(UKismetTextLibrary::Conv_FloatToText(shopSettings->LevelDifficulty, ERoundingMode::HalfToEven));
	}

}