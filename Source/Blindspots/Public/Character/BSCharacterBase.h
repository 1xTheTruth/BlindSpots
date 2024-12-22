// Copyright Y.M. Bilge

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BSCharacterBase.generated.h"

UCLASS(Abstract)
class BLINDSPOTS_API ABSCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ABSCharacterBase();

protected:
	virtual void BeginPlay() override;
	
};
