// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HealthComponent.h"
#include "UObject/Interface.h"
#include "CreatureInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, NotBlueprintable)
class UCreatureInterface : public UInterface
{
	GENERATED_BODY()



};

/**
 * 
 */
class COLISEUMOFSOULS_API ICreatureInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintCallable)
	virtual UHealthComponent* GetHealthComponent() = 0;

	UFUNCTION(BlueprintCallable)
	virtual void InitCreatureHealth(int MaxHealth, int CurrentHealth) = 0;

	// Обработчик урона от других существ, в будущем должен быть заменён на компонент
	UFUNCTION(BlueprintCallable)
	virtual void ReceiveDamage(int Damage) = 0;
	
	UFUNCTION(BlueprintCallable)
	virtual void OnDeath() = 0;
	UFUNCTION(BlueprintCallable)
	virtual void OnHealthChanged(int MaxHealth, int CurrentHealth) = 0;
	UFUNCTION(BlueprintCallable)
	virtual void MakeHit(TScriptInterface<ICreatureInterface> CreatureToHit) = 0;
};
