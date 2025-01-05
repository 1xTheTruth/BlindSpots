// Copyright Y.M. Bilge


#include "Character/BSCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"

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

	
}

void ABSCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	
}





