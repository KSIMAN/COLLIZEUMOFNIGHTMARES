// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Mobs/BaseMob.h"
#include "Logging/LogMacros.h"
#include "ColiseumOfSoulsCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class AColiseumOfSoulsCharacter : public ABaseMob
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

public:
	AColiseumOfSoulsCharacter();

	virtual void ReceiveDamage(int Damage) override;
	
	virtual void OnDeath() override;
	virtual void OnHealthChanged(int MaxHealth, int CurrentHealth) override;
	virtual void MakeHit(TScriptInterface<ICreatureInterface> CreatureToHit) override;

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);
	
	/** Delegates */

	UFUNCTION()
	void HandleOnMontageEnded(UAnimMontage* Montage, bool Interrupted);


	/**  Player Variables */

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class APlayerHUD* MainHUDPtr;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Variables)
	float max_stamina; //For Running, not magic
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Variables)
	float stamina; //For Running, not magic

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Variables)
	float max_mana; //For Magic
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Variables)
	float mana; //For Magic

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay();

public:


	//-------------* Getters *----------------/

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	/* Returns Stamina of Character from 0 to 1000*/
	FORCEINLINE float GetStamina() { return stamina; };

	/* Returns Mana of Character from 0 to 1000*/
	FORCEINLINE float GetMana() { return mana; };



	//-------------* Setters *----------------/

	void addStamina(float stamina_to_add);
	void RemoveStamina(float stamina_to_remove);

	void addMana(float mana_to_add);
	void RemoveMana(float mana_to_remove);

};

