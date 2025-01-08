// Copyright Y.M. Bilge


#include "AbilitySystem/BSAbilitySystemComponent.h"

void UBSAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UBSAbilitySystemComponent::EffectApplied);
}

void UBSAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
											  const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);

	EffectAssetTags.Broadcast(TagContainer);
}

