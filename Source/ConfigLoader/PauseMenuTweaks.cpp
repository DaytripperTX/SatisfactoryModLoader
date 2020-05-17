#include "PauseMenuTweaks.h"
#include "../SML/mod/blueprint_hooking.h"
#include "util/Logging.h"


void GRegisterPauseMenuHooks()
{
	UClass* PauseMenuClass = LoadObject<UClass>(nullptr, TEXT("/Game/FactoryGame/Interface/UI/Menu/PauseMenu/BP_PauseWidget.BP_PauseWidget_C"));
	check(PauseMenuClass);
	UFunction* ConstructFn = PauseMenuClass->FindFunctionByName(TEXT("Construct"));
	check(ConstructFn);
	HookBlueprintFunction(ConstructFn, [](FBlueprintHookHelper& HookHelper) {
		//Retrieve Menu Options vertical box
		UUserWidget* PauseMenuWidget = Cast<UUserWidget>(HookHelper.GetContext());
		UObjectProperty* Property = Cast<UObjectProperty>(PauseMenuWidget->GetClass()->FindPropertyByName(TEXT("MenuOptions")));
		checkf(Property, TEXT("Menu Options not found"));

		SML::Logging::info("Found Menu Options");


	}, EPredefinedHookOffset::Return);
}
