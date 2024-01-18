// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "../Interfaces/CreatureInterface.h"
#include "../Components/ContentHolderComponent.h"
#include "BaseMob.generated.h"


UCLASS()
class COLISEUMOFSOULS_API ABaseMob : public ACharacter, public ICreatureInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseMob();

	ABaseMob(float _health, float _max_health);

	UFUNCTION(BlueprintCallable)
	virtual void OnDeath() {};										//When Creture Dies		
	UFUNCTION(BlueprintCallable)
	virtual void RecieveDamage(float fDamage) {};					//When Creature recieve damage
	UFUNCTION(BlueprintCallable)
	virtual void MakeHit(ABaseMob* pActorToHit) {};				//When Creature makes Hit
	

	UPROPERTY(BlueprintReadWrite, Category = Variables)
	UHealthComponent* HealthComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Assets)
	UContentHolderComponent* contentHolder;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
	float health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
	float max_health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
	int attackResetTime;


	//----Getters------------------------------------------

	UFUNCTION(BlueprintCallable)
	virtual UHealthComponent* GetHealthComponent() override
	{
		return HealthComponent;
	}

	UFUNCTION(BlueprintCallable)
	UContentHolderComponent* getContentHolder() { return contentHolder; }


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
};
