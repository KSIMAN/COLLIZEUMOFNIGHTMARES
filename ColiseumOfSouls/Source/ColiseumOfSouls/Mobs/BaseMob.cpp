// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseMob.h"

// Sets default values

ABaseMob::ABaseMob()
{
	PrimaryActorTick.bCanEverTick = true;
	contentHolder = CreateDefaultSubobject<UContentHolderComponent>("Content Holder Component");

	//getContentHolder()->attackAnimation = CreateDefaultSubobject<UAnimMontage>("Attack Animation");
	//getContentHolder()->deathAnimation = CreateDefaultSubobject<UAnimMontage>("Death Animation");
	//getContentHolder()->damagedAnimation = CreateDefaultSubobject<UAnimMontage>("Take Damage Animation");

	HealthComponent = CreateDefaultSubobject<UHealthComponent>("Health Component");
}

void ABaseMob::InitCreatureHealth(int MaxHealth, int CurrentHealth)
{
	HealthComponent->HandleHealthReset(MaxHealth, CurrentHealth);
	HealthComponent->HealthObserver.AddDynamic(this, &ICreatureInterface::OnHealthChanged);
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

