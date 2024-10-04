// Copyright Y.M. Bilge

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BSHUD.generated.h"

class UBSUserWidget;
/**
 * 
 */
UCLASS()
class BLINDSPOTS_API ABSHUD : public AHUD
{
	GENERATED_BODY()

public:

	UPROPERTY()
	TObjectPtr<UBSUserWidget> OverlayWidget;

protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere)
	TSubclassOf<UBSUserWidget> OverlayWidgetClass;
	
};
