// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseMob.h"
#include "ScuffieMob.generated.h"

/**
 * 
 */
UCLASS()
class COLISEUMOFSOULS_API AScuffieMob : public ABaseMob
{
	GENERATED_BODY()
public:

	AScuffieMob();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnOverlapBegin(AActor* CurrentActor, AActor* OtherActor);


	//---Interface Functions-------------------------------------------------

	virtual void OnHealthChanged(int MaxHealth, int CurrentHealth);


	virtual void MakeHit(TScriptInterface<ICreatureInterface> CreatureToHit);


	virtual void OnDeath() override;									//When Creture Dies		
	
};
