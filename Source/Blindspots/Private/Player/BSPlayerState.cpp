// Copyright Y.M. Bilge


#include "Player/BSPlayerState.h"
#include "AbilitySystem/BSAbilitySystemComponent.h"
#include "AbilitySystem/BSAttributeSet.h"

ABSPlayerState::ABSPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UBSAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UBSAttributeSet>("AttributeSet");

	NetUpdateFrequency = 100.f;
}

UAbilitySystemComponent* ABSPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
