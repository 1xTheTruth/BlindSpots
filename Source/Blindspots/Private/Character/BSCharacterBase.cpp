// Copyright Y.M. Bilge


#include "Character/BSCharacterBase.h"

ABSCharacterBase::ABSCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ABSCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}
