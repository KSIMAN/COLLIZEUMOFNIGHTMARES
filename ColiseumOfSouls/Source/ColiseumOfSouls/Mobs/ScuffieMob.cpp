// Fill out your copyright notice in the Description page of Project Settings.


#include "ScuffieMob.h"
#include "Kismet/GameplayStatics.h"
#include "../ColiseumOfSoulsCharacter.h"

AScuffieMob::AScuffieMob()
{
	//Change to health component


	InitCreatureHealth(1000, 1000);
	
	//

}

void AScuffieMob::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &AScuffieMob::OnOverlapBegin);
}


void AScuffieMob::OnOverlapBegin(AActor* CurrentActor, AActor* OtherActor)
{
	if (Cast<AColiseumOfSoulsCharacter>(OtherActor))
	{
		MakeHit(OtherActor);
	}
}

void AScuffieMob::OnHealthChanged(int MaxHealth, int CurrentHealth)
{
	GetMesh()->GetAnimInstance()->Montage_Play(getContentHolder()->damagedAnimation);
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), getContentHolder()->damagedSound, GetActorLocation());

	//if (CurrentHealth <= 0)
	//	OnDeath();

}

void AScuffieMob::MakeHit(TScriptInterface<ICreatureInterface> CreatureToHit)
{
	GetMesh()->GetAnimInstance()->Montage_Play(getContentHolder()->attackAnimation);
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), getContentHolder()->damageSound, GetActorLocation());
}

void AScuffieMob::OnDeath()
{
	GetMesh()->GetAnimInstance()->Montage_Play(getContentHolder()->deathAnimation);

	GetMesh()->SetSimulatePhysics(true);
}
