// Copyright Y.M. Bilge


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/BSAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UBSAttributeSet* BSAttributeSet = CastChecked<UBSAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(BSAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(BSAttributeSet->GetMaxHealth());
	OnManaChanged.Broadcast(BSAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(BSAttributeSet->GetMaxMana());
	OnStaminaChanged.Broadcast(BSAttributeSet->GetStamina());
	OnMaxStaminaChanged.Broadcast(BSAttributeSet->GetMaxStamina());
	
}
