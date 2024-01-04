// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameObject.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class COLISEUMOFSOULS_API AMyActor : public AActor, public IGameObject
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "MyCategory")
	int GetMaxHP(AActor* TargetActor); virtual int GetMaxHP_Implementation(AActor* TargetActor);
	//UFUNCTION(BlueprintCallable, Category = "MyCategory")
	//virtual int GetCurrentHP() override;
};
