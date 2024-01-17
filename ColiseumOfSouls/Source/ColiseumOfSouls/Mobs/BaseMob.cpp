// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseMob.h"

// Sets default values

ABaseMob::ABaseMob() : ABaseMob(0, 0)
{
}

ABaseMob::ABaseMob(float _health, float _max_health) :
	health(_health), max_health(_max_health)
{
	PrimaryActorTick.bCanEverTick = true;
	
	attackAnimation = CreateDefaultSubobject<UAnimMontage>("Attack Animation");
	deathAnimation = CreateDefaultSubobject<UAnimMontage>("Death Animation");
	damagedAnimation = CreateDefaultSubobject<UAnimMontage>("Take Damage Animation");

	HealthComponent = CreateDefaultSubobject<UHealthComponent>("Health Component");
}

// Called when the game starts or when spawned
void ABaseMob::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseMob::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseMob::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

