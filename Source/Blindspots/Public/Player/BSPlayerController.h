// Copyright Y.M. Bilge

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BSPlayerController.generated.h"


class UInputMappingContext;
/**
 * 
 */
UCLASS()
class BLINDSPOTS_API ABSPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	ABSPlayerController();

protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> BSContext;
};
