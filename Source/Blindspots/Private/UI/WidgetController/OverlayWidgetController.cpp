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

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UBSAttributeSet* BSAttributeSet = CastChecked<UBSAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		BSAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		BSAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		BSAttributeSet->GetManaAttribute()).AddUObject(this, &UOverlayWidgetController::ManaChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		BSAttributeSet->GetMaxManaAttribute()).AddUObject(this, &UOverlayWidgetController::MaxManaChanged);
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}
