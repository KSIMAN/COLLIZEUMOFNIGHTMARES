// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseMob.h"
#include "ZombieMob.generated.h"

/**
 * 
 */
UCLASS()
class COLISEUMOFSOULS_API AZombieMob : public ABaseMob
{
	GENERATED_BODY()

public:
	AZombieMob();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnOverlapBegin(AActor* CurrentActor, AActor* OtherActor);


	//---Interface Functions-------------------------------------------------
	
	virtual void ReceiveDamage(int Damage) override;

	virtual void OnDeath() override;
	virtual void OnHealthChanged(int MaxHealth, int CurrentHealth) override;
	virtual void MakeHit(TScriptInterface<ICreatureInterface> CreatureToHit) override;
	
};
