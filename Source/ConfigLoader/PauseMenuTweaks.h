#pragma once

#include "CoreMinimal.h"
#include "CoreUObject.h"
#include "PanelWidget.h"
#include "GameFramework/Actor.h"
//#include "PauseMenuTweaks.generated.h"


void GRegisterPauseMenuHooks();

void InsertChildAt(UPanelWidget* PanelWidget, int32 Index, UWidget* Content);

void ShiftChild(UPanelWidget* PanelWidget, int32 Index, UWidget* Child);

const TArray<UPanelSlot*> GetSlots(UPanelWidget* PanelWidget);

