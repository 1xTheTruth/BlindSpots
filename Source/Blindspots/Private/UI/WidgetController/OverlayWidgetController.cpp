// Copyright Y.M. Bilge


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/BSAbilitySystemComponent.h"
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

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		BSAttributeSet->GetStaminaAttribute()).AddUObject(this, &UOverlayWidgetController::StaminaChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		BSAttributeSet->GetMaxStaminaAttribute()).AddUObject(this, &UOverlayWidgetController::MaxStaminaChanged);

	Cast<UBSAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda(
		[](const FGameplayTagContainer& AssetTags)
		{
			for (const FGameplayTag& Tag : AssetTags)
			{
				const FString Msg = FString::Printf(TEXT("GE Tag: %s"), *Tag.ToString());
				GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Blue, Msg);
			}
		}
	);
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

void UOverlayWidgetController::StaminaChanged(const FOnAttributeChangeData& Data) const
{
	OnStaminaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxStaminaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxStaminaChanged.Broadcast(Data.NewValue);
}
