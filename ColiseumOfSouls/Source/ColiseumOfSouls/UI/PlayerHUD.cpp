// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHUD.h"
#include "BaseWidget.h"
#include "Blueprint/UserWidget.h"

APlayerHUD::APlayerHUD() : Super()
{
	// Script / UMGEditor.WidgetBlueprint'/Game/Widgets/WBP_MainWidget.WBP_MainWidget'
	ConstructorHelpers::FClassFinder<UUserWidget> WBPBaseWidget(TEXT("/Game/Widgets/WBP_MainWidget")); 
	
	BaseWidgetRef = WBPBaseWidget.Class;
	
}

void APlayerHUD::BeginPlay()
{
	Super::BeginPlay();
	BaseWidgetPtr = Cast<UBaseWidget>(CreateWidget(GetWorld(), BaseWidgetRef));

	if (BaseWidgetPtr)
		BaseWidgetPtr->AddToViewport();
}
