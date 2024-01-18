// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UObject/Class.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FHealthChangeObserver, int, MaxHP, int, CurrentHP);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COLISEUMOFSOULS_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();
	// Sets default values for this component's properties
	UHealthComponent(int MaxHp, int CurrentHp);
	
	UFUNCTION(BlueprintCallable)
	int GetMaxHealth() { return MaxHealth; }
	
	UFUNCTION(BlueprintCallable)
	int GetCurrentHealth() { return CurrentHealth; }

	UPROPERTY(BlueprintAssignable)
	FHealthChangeObserver HealthObserver;

	UFUNCTION(BlueprintCallable)
	virtual void HandleHealthChange(int Change); // If Change is damage, must be < 0

	UFUNCTION(BlueprintCallable)
	virtual void HandleHealthReset(int MaxHP, int CurrentHP);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	int MaxHealth;
	int CurrentHealth;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
};
