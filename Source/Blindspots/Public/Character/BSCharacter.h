// Copyright Y.M. Bilge

#pragma once

#include "CoreMinimal.h"
#include "Character/BSCharacterBase.h"
#include "BSCharacter.generated.h"

/**
 * 
 */
UCLASS()
class BLINDSPOTS_API ABSCharacter : public ABSCharacterBase
{
	GENERATED_BODY()

public:

	ABSCharacter();

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

private:

	virtual void InitAbilityActorInfo() override;
	
};
