// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameImpact.h"
#include "UObject/Interface.h"
#include "GameObject.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, meta=(BlueprintImplementableEvent))
class UGameObject : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class COLISEUMOFSOULS_API IGameObject
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "MyCategory")
	int GetMaxHP(AActor* TargetActor);
	//UFUNCTION(BlueprintCallable, Category = "MyCategory")
	//virtual int GetCurrentHP() = 0;

	/*UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "MyCategory")
	TArray<int> GetImpactResistance();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "MyCategory")
	TArray<int> GetEffectResistance();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "MyCategory")
	TArray<int> GetCurrentEffects();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "MyCategory")
	void HandleImpact(IGameImpact* Impact);
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "MyCategory")
	void HandleEffect();*/
};
