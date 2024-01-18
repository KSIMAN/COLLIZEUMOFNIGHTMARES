// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieMob.h"
#include "../ColiseumOfSoulsCharacter.h"

AZombieMob::AZombieMob()
{
}

void AZombieMob::BeginPlay()
{
	Super::BeginPlay();
	InitCreatureHealth(200, 200);
	OnActorBeginOverlap.AddDynamic(this, &AZombieMob::OnOverlapBegin);
}

void AZombieMob::OnOverlapBegin(AActor* CurrentActor, AActor* OtherActor)
{
	if (Cast<AColiseumOfSoulsCharacter>(OtherActor) != nullptr)
	{
		MakeHit(OtherActor);
	}
}

void AZombieMob::OnDeath()
{
	//Play anim

	//Play Sound

	//Timer N Secs

	GetController()->StopMovement();

	Destroy();
}

void AZombieMob::OnHealthChanged(int MaxHealth, int CurrentHealth)
{
	Super::OnHealthChanged(MaxHealth, CurrentHealth);
	if (CurrentHealth <= 0)
		OnDeath();
}

void AZombieMob::ReceiveDamage(int Damage)
{
	Super::ReceiveDamage(Damage);
	GetHealthComponent()->HandleHealthChange(-Damage);
}

void AZombieMob::MakeHit(TScriptInterface<ICreatureInterface> CreatureToHit)
{
	if (!CreatureToHit)
		return;

	CreatureToHit->ReceiveDamage(10);
}
