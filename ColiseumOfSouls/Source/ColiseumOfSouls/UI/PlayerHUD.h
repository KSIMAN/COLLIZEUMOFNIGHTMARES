// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PlayerHUD.generated.h"

/**
 * 
 */

class UUserWidget;

UCLASS()
class COLISEUMOFSOULS_API APlayerHUD : public AHUD
{
	GENERATED_BODY()
public:
	APlayerHUD();

	virtual void BeginPlay() override;


	//-----Widgets------------------------------------------------------

	//Base Player Widget
	TSubclassOf<class UBaseWidget> BaseWidgetRef;
	UBaseWidget* BaseWidgetPtr;


	//Game over widget

	TSubclassOf<UUserWidget> GameOverWidgetRef;
	UUserWidget* GameOverWidgetPtr;

	//Victory Widget
	TSubclassOf<UUserWidget> VictoryWidgetRef;
	UUserWidget* VictoryWidgetPtr;

	//Pause Widget
	TSubclassOf<UUserWidget> PauseWidgetRef;
	UUserWidget* PauseWidgetPtr;

};
