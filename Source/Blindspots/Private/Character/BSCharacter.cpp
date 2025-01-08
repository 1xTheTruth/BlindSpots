// Copyright Y.M. Bilge


#include "Character/BSCharacter.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/BSAbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/BSPlayerController.h"
#include "Player/BSPlayerState.h"

ABSCharacter::ABSCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void ABSCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	//Init ability actor info for the server
	InitAbilityActorInfo();
	
}

void ABSCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	//Init ability actor info for the Client
	InitAbilityActorInfo();
	
}

void ABSCharacter::InitAbilityActorInfo()
{
	ABSPlayerState* BSPlayerState = GetPlayerState<ABSPlayerState>();
	check(BSPlayerState);
	BSPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(BSPlayerState, this);
	Cast<UBSAbilitySystemComponent>(BSPlayerState->GetAbilitySystemComponent())->AbilityActorInfoSet();
	AbilitySystemComponent = BSPlayerState->GetAbilitySystemComponent();
	AttributeSet = BSPlayerState->GetAttributeSet();
}





