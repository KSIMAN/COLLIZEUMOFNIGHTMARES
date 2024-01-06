// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "BaseWidget.generated.h"

/**
 * 
 */
UCLASS()
class COLISEUMOFSOULS_API UBaseWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UBaseWidget(const FObjectInitializer& ObjectInitializer);
	virtual void NativeConstruct() override;

	//Setters

	//Converts and sets stamina value
	void SetStamina(float stamina);

	//Converts and sets health value
	void SetHealth(float health);

	//Converts and sets stamina value
	void SetMana(float mana);
	
	//Converts and sets Kills value
	void SetKills(int32 kills, int32 max_kills);



protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UProgressBar* HealthBar;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UProgressBar* StaminaBar;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UProgressBar* ManaBar;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* KillsText;

	//Converts to nf to 1.0f
	float convertToOneF(float value, float max_value = 1000.f);
	
};
