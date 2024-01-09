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
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


	//---Interface Functions-------------------------------------------------

	virtual void OnDeath() override;									//When Creture Dies		
	virtual void RecieveDamage(float fDamage) override;					//When Creature recieve damage
	virtual void MakeHit(ABaseMob* pActorToHit) override;				//When Creature makes Hit
	
};
