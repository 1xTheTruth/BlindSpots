// Copyright Y.M. Bilge


#include "Player/BSPlayerController.h"
#include "EnhancedInputSubsystems.h"

ABSPlayerController::ABSPlayerController()
{
	bReplicates = true;
}

void ABSPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(BSContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(BSContext, 0);

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}
