// Copyright Y.M. Bilge

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BSPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

/**
 * 
 */
UCLASS()
class BLINDSPOTS_API ABSPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	ABSPlayerController();

	virtual void PlayerTick(float DeltaTime) override;

protected:

	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> BSContext;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> MoveActionForward;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> MoveActionBackward;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> MoveActionRight;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> MoveActionLeft;

	void Move(const FInputActionValue& InputActionValue);

};
