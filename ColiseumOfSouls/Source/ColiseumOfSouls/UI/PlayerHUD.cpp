// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHUD.h"
#include "BaseWidget.h"
#include "Blueprint/UserWidget.h"

APlayerHUD::APlayerHUD() : Super()
{
	// Script / UMGEditor.WidgetBlueprint'/Game/Widgets/WBP_MainWidget.WBP_MainWidget'
	ConstructorHelpers::FClassFinder<UUserWidget> WBPBaseWidget(TEXT("/Game/Widgets/WBP_MainWidget")); 
	ConstructorHelpers::FClassFinder<UUserWidget> WBPGameOverWidgetRef(TEXT("/Game/Widgets/WBP_GameOver"));
	///ConstructorHelpers::FClassFinder<UUserWidget> WBPGameOverWidgetRef(TEXT("/Game/Widgets/WBP_Victory"));
	//ConstructorHelpers::FClassFinder<UUserWidget> WBPGameOverWidgetRef(TEXT("/Game/Widgets/WBP_ChooseLevel"));
	//ConstructorHelpers::FClassFinder<UUserWidget> WBPGameOverWidgetRef(TEXT("/Game/Widgets/WBP_GameOver"));
	VictoryWidgetRef = ConstructorHelpers::FClassFinder<UUserWidget>(TEXT("/Game/Widgets/WBP_Victory")).Class;

	GameOverWidgetRef = WBPGameOverWidgetRef.Class;
	BaseWidgetRef = WBPBaseWidget.Class;
	
}

void APlayerHUD::BeginPlay()
{
	Super::BeginPlay();
	BaseWidgetPtr = Cast<UBaseWidget>(CreateWidget(GetWorld(), BaseWidgetRef));

	GameOverWidgetPtr = CreateWidget(GetWorld(), GameOverWidgetRef);
	VictoryWidgetPtr = CreateWidget(GetWorld(), VictoryWidgetRef);

	//if (VictoryWidgetPtr)
	//	VictoryWidgetPtr->AddToViewport(666);

	if (BaseWidgetPtr)
		BaseWidgetPtr->AddToViewport();
}
