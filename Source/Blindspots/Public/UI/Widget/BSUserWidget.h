// Copyright Y.M. Bilge

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BSUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class BLINDSPOTS_API UBSUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;

protected:

	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
	
};