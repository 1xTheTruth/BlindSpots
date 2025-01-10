// Copyright Y.M. Bilge


#include "UI/WidgetController/BSWidgetController.h"

void UBSWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void UBSWidgetController::BroadcastInitialValues()
{
	
}

void UBSWidgetController::BindCallbacksToDependencies()
{
	
}