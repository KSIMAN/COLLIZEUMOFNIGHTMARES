// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieMob.h"
#include "../ColiseumOfSoulsCharacter.h"
#include "Components/CapsuleComponent.h"

AZombieMob::AZombieMob() : ABaseMob(200.f, 200.f)
{
	
}

void AZombieMob::BeginPlay()
{
	Super::BeginPlay();
	GetMesh()->OnComponentBeginOverlap.AddDynamic(this, &AZombieMob::OnOverlapBegin);
}

void AZombieMob::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<AColiseumOfSoulsCharacter>(OtherActor) != nullptr)
	{
		MakeHit(Cast<AColiseumOfSoulsCharacter>(OtherActor));
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

void AZombieMob::RecieveDamage(float fDamage)
{
	Super::RecieveDamage(fDamage);
	
	float total_health = health - fDamage;
	if (total_health < 0.f)
		health = 0.f;
	else
		health = total_health;
	
	if (health <= 0.f)
		OnDeath();
}

void AZombieMob::MakeHit(ABaseMob* pActorToHit)
{
	if (!pActorToHit)
		return;

	pActorToHit->RecieveDamage(10.f); 
}
