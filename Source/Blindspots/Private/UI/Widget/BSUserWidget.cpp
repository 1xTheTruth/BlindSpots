// Copyright Y.M. Bilge


#include "UI/Widget/BSUserWidget.h"

void UBSUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
