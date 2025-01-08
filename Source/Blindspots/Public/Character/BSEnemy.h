// Copyright Y.M. Bilge

#pragma once

#include "CoreMinimal.h"
#include "Character/BSCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "BSEnemy.generated.h"

/**
 * 
 */
UCLASS()
class BLINDSPOTS_API ABSEnemy : public ABSCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:
	ABSEnemy();

	//** Begin Enemy Interface */
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	//** End Enemy Interface */


protected:

	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;
	
};
