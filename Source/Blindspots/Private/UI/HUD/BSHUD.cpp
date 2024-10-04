// Copyright Y.M. Bilge


#include "UI/HUD/BSHUD.h"
#include "UI/Widget/BSUserWidget.h"

#include "Blueprint/UserWidget.h"

void ABSHUD::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	Widget->AddToViewport();
}
