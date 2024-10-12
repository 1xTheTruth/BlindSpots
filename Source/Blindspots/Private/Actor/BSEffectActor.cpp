// Copyright Y.M. Bilge


#include "Actor/BSEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/BSAttributeSet.h"
#include "Components/SphereComponent.h"

ABSEffectActor::ABSEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);
	
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(GetRootComponent());
}

void ABSEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//TODO: Change this to apply a Gameplay Effect. For now, using const_cast because i'm lazy! 
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UBSAttributeSet* BSAttributeSet = Cast<UBSAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UBSAttributeSet::StaticClass()));
		
		UBSAttributeSet* MutableBSAttributeSet = const_cast<UBSAttributeSet*>(BSAttributeSet);
		MutableBSAttributeSet->SetHealth(BSAttributeSet->GetHealth() + 25.f);
		MutableBSAttributeSet->SetMana(BSAttributeSet->GetMana() - 25.f);
		Destroy();
	}
}

void ABSEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}

void ABSEffectActor::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ABSEffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &ABSEffectActor::EndOverlap);
}


