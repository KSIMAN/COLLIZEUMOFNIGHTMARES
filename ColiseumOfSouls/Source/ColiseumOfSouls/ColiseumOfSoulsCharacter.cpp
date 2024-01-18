// Copyright Epic Games, Inc. All Rights Reserved.

#include "ColiseumOfSoulsCharacter.h"
#include "UI/PlayerHUD.h"
#include "UI/BaseWidget.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/GameMode.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// AColiseumOfSoulsCharacter

AColiseumOfSoulsCharacter::AColiseumOfSoulsCharacter() :
max_mana(1000.f),
max_stamina(1000.0f),
mana(1000.0f),
stamina(1000.0f),
ABaseMob(1000.f, 1000.f)
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
		
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	

}

//---Interface Functions-------------------------------------------------

void AColiseumOfSoulsCharacter::OnDeath()
{
	Super::OnDeath();
	//Play Die Sound
	GetMesh()->GetAnimInstance()->Montage_Play(getContentHolder()->deathAnimation);
	FTimerHandle timerHandle;
	FTimerDelegate deathDel; // Delegate to bind function with parameters

	UGameplayStatics::PlaySound2D(GetWorld(), getContentHolder()->deathSound, 1.0f, 1.0f, 0.0f);

	GetWorld()->GetTimerManager().SetTimer(timerHandle, FTimerDelegate::CreateLambda([&] {
		if (MainHUDPtr->GameOverWidgetPtr)
			MainHUDPtr->GameOverWidgetPtr->AddToViewport(666); }), 3.0f, false);

	//GetWorld()->GetTimerManager().SetTimer(timerHandle, deathDel, 7.0f, false);


}

void AColiseumOfSoulsCharacter::RecieveDamage(float fDamage)
{
	//Maybe need Damage types
	Super::RecieveDamage(fDamage);
	
	RemoveHealth(fDamage);
	//Play Hit Sound

	GetMesh()->GetAnimInstance()->Montage_Play(getContentHolder()->damagedAnimation);
}


void AColiseumOfSoulsCharacter::MakeHit(ABaseMob* pActorToHit)
{
	Super::MakeHit(pActorToHit);
	//Get Hit Type (Maybe not here, get type upper and return to this function)
}
//------------------------------------------------------------------------


void AColiseumOfSoulsCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	GetMesh()->GetAnimInstance()->OnMontageEnded.AddDynamic(this, &AColiseumOfSoulsCharacter::HandleOnMontageEnded);

	//Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
	
	MainHUDPtr = Cast<APlayerHUD>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD());
	if (!MainHUDPtr)
		return;

	//Full Life And Stamina And Mana
	MainHUDPtr->BaseWidgetPtr->SetHealth(500.f);
	MainHUDPtr->BaseWidgetPtr->SetMana(1000.f);
	MainHUDPtr->BaseWidgetPtr->SetStamina(1000.f);

	RecieveDamage(100.f);
}

void AColiseumOfSoulsCharacter::addHealth(float health_to_add)
{

	float total_health = health_to_add + GetHealth();
	if (total_health >= max_health)
		health = max_health;
	else
		health = total_health;

	MainHUDPtr->BaseWidgetPtr->SetHealth(health);

	//Add Heal Effect Here


}

void AColiseumOfSoulsCharacter::RemoveHealth(float health_to_remove)
{
	float total_health = GetHealth() - health_to_remove;
	if (total_health < 0.f)
		health = 0.f;
	else
		health = total_health;

	MainHUDPtr->BaseWidgetPtr->SetHealth(health);
	
	if (health <= 0.f)
		OnDeath();
}

void AColiseumOfSoulsCharacter::addStamina(float stamina_to_add)
{
	float total_stamina = GetStamina() + stamina_to_add;
	if (total_stamina > max_stamina)
		stamina = max_stamina;
	else
		stamina = total_stamina;

	MainHUDPtr->BaseWidgetPtr->SetStamina(stamina);
}

void AColiseumOfSoulsCharacter::RemoveStamina(float stamina_to_remove)
{
}

void AColiseumOfSoulsCharacter::addMana(float mana_to_add)
{
}

void AColiseumOfSoulsCharacter::RemoveMana(float mana_to_remove)
{
}

//////////////////////////////////////////////////////////////////////////
// Input

void AColiseumOfSoulsCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AColiseumOfSoulsCharacter::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AColiseumOfSoulsCharacter::Look);
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void AColiseumOfSoulsCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AColiseumOfSoulsCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AColiseumOfSoulsCharacter::HandleOnMontageEnded(UAnimMontage* Montage, bool Interrupted)
{
	if (Montage == getContentHolder()->deathAnimation)
	{

		//GetMesh()->GetAnimInstance()->StopSlotAnimation();
		////GetMesh()->GetAnimInstance()->StopAllMontages(0.0f);
		//GetMesh()->SetSimulatePhysics(true);
		//GetWorld()->GetFirstPlayerController()->SetPause(true);
	}
}
