// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "ColiseumOfSoulsCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class AColiseumOfSoulsCharacter : public ACharacter
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
	


protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);
			


	/**  Player Variables */

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class APlayerHUD* MainHUDPtr;


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Variables)
	float health; //Player Health 
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Variables)
	float stamina; //For Running, not magic

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Variables)
	float mana; //For Magic



	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Variables)
	float max_health; //Player Health 

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Variables)
	float max_stamina; //For Running, not magic

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Variables)
	float max_mana; //For Magic



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

	/* Returns Health of Character from 0 to 1000*/
	FORCEINLINE float GetHealth() { return health; };

	/* Returns Stamina of Character from 0 to 1000*/
	FORCEINLINE float GetStamina() { return stamina; };

	/* Returns Mana of Character from 0 to 1000*/
	FORCEINLINE float GetMana() { return mana; };



	//-------------* Setters *----------------/

	void addHealth(float health_to_add);
	void RemoveHealth(float health_to_remove);

	void addStamina(float stamina_to_add);
	void RemoveStamina(float stamina_to_remove);

	void addMana(float mana_to_add);
	void RemoveMana(float mana_to_remove);

};

