// Copyright Y.M. Bilge

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BSEffectActor.generated.h"

class UGameplayEffect;

UCLASS()
class BLINDSPOTS_API ABSEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	

	ABSEffectActor();

	

protected:

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
	TSubclassOf<UGameplayEffect> DurationGameplayEffectClass;
	
};
