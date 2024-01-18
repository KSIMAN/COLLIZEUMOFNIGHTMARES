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
	
	UFUNCTION(BlueprintCallable)
	virtual void InitCreatureHealth(int MaxHealth, int CurrentHealth) override;
	
	UFUNCTION(BlueprintCallable)
	virtual void ReceiveDamage(int Damage) override {}

	UFUNCTION(BlueprintCallable)
	virtual void OnDeath() override {}
	UFUNCTION(BlueprintCallable)
	virtual void OnHealthChanged(int MaxHealth, int CurrentHealth) override {}
	UFUNCTION(BlueprintCallable)
	virtual void MakeHit(TScriptInterface<ICreatureInterface> CreatureToHit) override {}
	

	UPROPERTY(BlueprintReadWrite, Category = Variables)
	UHealthComponent* HealthComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Assets)
	UContentHolderComponent* contentHolder;

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
