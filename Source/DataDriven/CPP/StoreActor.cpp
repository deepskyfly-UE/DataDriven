// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "StoreActor.h"
#include "Components/WidgetComponent.h"
#include "Components/TextRenderComponent.h"



AStoreActor::AStoreActor()
{

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	ConstructorHelpers::FObjectFinder<USkeletalMesh> objFinder(TEXT("/Game/Mannequin/Character/Mesh/SK_Mannequin"));
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>("Mesh");
	Mesh->SetupAttachment(RootComponent);
	if (objFinder.Succeeded())
	{
		Mesh->SetSkeletalMesh(objFinder.Object);
	}

	ConstructorHelpers::FClassFinder<UAnimInstance> animClassFinder(TEXT("/Game/Mannequin/Animations/ThirdPerson_AnimBP"));
	if (animClassFinder.Succeeded())
	{
		Mesh->SetAnimClass(animClassFinder.Class);
	}

	Mesh->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));

	ConstructorHelpers::FClassFinder<UUserWidget> classFinder(TEXT("/Game/Blueprint/CPP/UMG_Shop_CPP"));
	Widget= CreateDefaultSubobject<UWidgetComponent>("Widget");
	Widget->SetupAttachment(RootComponent);
	Widget->SetRelativeLocation(FVector(0.f, 0.f, 110.f));
	Widget->SetRelativeScale3D(FVector(0.3f, 0.3f, 0.3f));
	Widget->SetDrawAtDesiredSize(true);
	Widget->SetManuallyRedraw(true);

	if (classFinder.Succeeded())
	{
		Widget->SetWidgetClass(classFinder.Class);
	}

	TextComponent = CreateDefaultSubobject<UTextRenderComponent>("Text");
	TextComponent->SetupAttachment(RootComponent);
	TextComponent->SetRelativeLocation(FVector(0.f,0.f,250.f));
	TextComponent->SetText(TEXT("C++"));
	TextComponent->SetHorizontalAlignment(EHTA_Center);
	
}

void AStoreActor::BeginPlay()
{
	Super::BeginPlay();
}

