// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent(): UHealthComponent(20, 20)
{
}
// Sets default values for this component's properties
UHealthComponent::UHealthComponent(int MaxHp, int CurrentHp): MaxHealth(MaxHp), CurrentHealth(CurrentHp)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


void UHealthComponent::HandleHealthChange(int Change)
{
	CurrentHealth = std::max(CurrentHealth + Change, 0);
	HealthObserver.Broadcast(MaxHealth, CurrentHealth);
}

void UHealthComponent::HandleHealthReset(int MaxHP, int CurrentHP)
{
	MaxHealth = MaxHP;
	CurrentHealth = CurrentHP;
	HealthObserver.Broadcast(MaxHealth, CurrentHealth);
}

/*void UHealthComponent::AddOnDamageReceiveObserver(AActor* function)
{
	//OnDamageReceiveObservers.AddDynamic(function, Invoke);
}*/

// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

