// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UObject/Class.h"
#include "HealthComponent.generated.h"

DECLARE_DELEGATE_OneParam(FHObs, float)
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

	int MaxHealth;
	int CurrentHealth;

	UPROPERTY(BlueprintAssignable)
	FHealthChangeObserver HealthObserver;
	
	FHObs Obs;

	UFUNCTION(BlueprintCallable)
	virtual void HandleHealthChange(int Change);

	UFUNCTION(BlueprintCallable)
	virtual void HandleHealthReset(int MaxHP, int CurrentHP);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
