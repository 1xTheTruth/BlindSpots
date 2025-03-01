// Copyright Y.M. Bilge


#include "Player/BSPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interaction/EnemyInterface.h"

ABSPlayerController::ABSPlayerController()
{
	bReplicates = true;
}

void ABSPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
}

void ABSPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;

	LastActor = ThisActor;
	ThisActor = CursorHit.GetActor();

	/**
* Line trace from cursor. There are several scenarios:
* A. LastActor is null && ThisActor is null
*	- Do Nothing.
* B. LastActor is null && ThisActor is valid
*	- Highlight ThisActor
* C. LastActor is valid && ThisActor is null
*	- UnHighlight LastActor
* D. Both actors are valid, but LastActor != ThisActor
*	- UnHighlight LastActor, and Highlight ThisActor
* E. Both actors are valid, and are the same actor
*	- Do Nothing
*/
	
	if (LastActor == nullptr)
	{
		if (ThisActor != nullptr)
		{
			// Case B
			ThisActor->HighlightActor();
		}
		else
		{
			// Case A - both actors are null, do nothing
		}
	}
	else
	{
		if (ThisActor == nullptr)
		{
			// Case C
			LastActor->UnHighlightActor();
		}
		else
		{
			if (LastActor != ThisActor)
			{
				// Case D
				LastActor->UnHighlightActor();
				ThisActor->HighlightActor();
			}
			else
			{
				// Case E
			}
		}
	}
}

void ABSPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(BSContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem)
	{
		Subsystem->AddMappingContext(BSContext, 0);
	}

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void ABSPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveActionForward, ETriggerEvent::Triggered, this, &ABSPlayerController::Move);
	EnhancedInputComponent->BindAction(MoveActionBackward, ETriggerEvent::Triggered, this, &ABSPlayerController::Move);
	EnhancedInputComponent->BindAction(MoveActionLeft, ETriggerEvent::Triggered, this, &ABSPlayerController::Move);
	EnhancedInputComponent->BindAction(MoveActionRight, ETriggerEvent::Triggered, this, &ABSPlayerController::Move);
}

void ABSPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

