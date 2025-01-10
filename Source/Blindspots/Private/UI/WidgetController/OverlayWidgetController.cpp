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
		BSAttributeSet->GetHealthAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnHealthChanged.Broadcast(Data.NewValue);
		}
		);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		BSAttributeSet->GetMaxHealthAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnMaxHealthChanged.Broadcast(Data.NewValue);
		}
		);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		BSAttributeSet->GetManaAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnManaChanged.Broadcast(Data.NewValue);
		}
		);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		BSAttributeSet->GetMaxManaAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnMaxManaChanged.Broadcast(Data.NewValue);
		}
		);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		BSAttributeSet->GetStaminaAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnStaminaChanged.Broadcast(Data.NewValue);
		}
		);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		BSAttributeSet->GetMaxStaminaAttribute()).AddLambda(
		[this](const FOnAttributeChangeData& Data)
		{
			OnMaxStaminaChanged.Broadcast(Data.NewValue);
		}
		);

	Cast<UBSAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda(
		[this](const FGameplayTagContainer& AssetTags)
		{
			for (const FGameplayTag& Tag : AssetTags)
			{
				// For example, say that Tag = Message.HealthPotion
				// "Message.HealthPotion".MatchesTag("Message") will return True, "Message".MatchesTag("Message.HealthPotion") will return False
				FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag(FName("Message"));
				if(Tag.MatchesTag(MessageTag))
				{
					const FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag);
					MessageWidgetRowDelegate.Broadcast(*Row);
				}
			}
		}
	);
}