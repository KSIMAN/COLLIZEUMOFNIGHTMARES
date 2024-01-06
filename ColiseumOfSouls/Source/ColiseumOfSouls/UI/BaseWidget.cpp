// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseWidget.h"
#include "Kismet/KismetStringLibrary.h"
#include "Kismet/KismetTextLibrary.h"

UBaseWidget::UBaseWidget(const FObjectInitializer& ObjectInitializer) : UUserWidget(ObjectInitializer)
{
}

void UBaseWidget::NativeConstruct()
{
	UUserWidget::NativeConstruct();


}

void UBaseWidget::SetStamina(float stamina)
{
	StaminaBar->SetPercent(convertToOneF(stamina));
}

void UBaseWidget::SetHealth(float health)
{
	HealthBar->SetPercent(convertToOneF(health));
}

void UBaseWidget::SetMana(float mana)
{
	ManaBar->SetPercent(convertToOneF(mana));
}

void UBaseWidget::SetKills(int32 kills, int32 max_kills)
{

	FString text = FString::Printf(TEXT("%d/%d"), kills, max_kills);
	KillsText->SetText(FText::FromString(text));
}

float UBaseWidget::convertToOneF(float value, float max_value)
{
	return value / max_value;
}
