#include "PauseMenuTweaks.h"
#include "../SML/mod/blueprint_hooking.h"
#include "util/Logging.h"
#include "Components/VerticalBox.h"
#include "Components/Widget.h"
#include "FGButtonWidget.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/PanelWidget.h"





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
		UVerticalBox* MenuOptions = Cast<UVerticalBox>(Cast<UWidget>(Property->GetObjectPropertyValue_InContainer(PauseMenuWidget)));

		// Instantiate Mod Options Button
		//UClass* FButtonClass = LoadObject<UClass>(nullptr, TEXT("/Game/FactoryGame/Interface/UI/Menu/Widget_FrontEnd_Button.Widget_FrontEnd_Button_C"));
		UClass* FButtonClass = LoadObject<UClass>(nullptr, TEXT("/Game/ExoSuitMod/ExoSuit/UI/Mod_Options_btn.Mod_Options_btn_C"));
		UFGButtonWidget* ModButton = CreateWidget<UFGButtonWidget>(MenuOptions, FButtonClass, FName("ModButton"));



		// Insert Mod Options Button into array of pause buttons
		TArray<UWidget*> PauseButtons = MenuOptions->GetAllChildren();



		//TODO: create swap child at fn


		InsertChildAt(MenuOptions, 8, ModButton);



		//MenuOptions->ClearChildren();

		//for (int32 i = 0; i < length; i++)
		//{
		//	//MenuOptions->AddChild(Slots[i]->Content);
		//	Slots[i]->Parent = MenuOptions;
		//	
		//	
		//}

		PauseButtons = MenuOptions->GetAllChildren();

		for (UWidget* child : PauseButtons)
		{
			SML::Logging::info("Child Name: ", TCHAR_TO_ANSI(*UKismetSystemLibrary::GetDisplayName(child)), "  |  Class Name: ", TCHAR_TO_ANSI(*UKismetSystemLibrary::GetDisplayName(child->GetClass())));
		}

	}, EPredefinedHookOffset::Return);
}


void InsertChildAt(UPanelWidget* PanelWidget, int32 Index, UWidget* Content)
{
	UPanelSlot* NewSlot = PanelWidget->AddChild(Content);
	ShiftChild(PanelWidget, Index, Content);


}

void ShiftChild(UPanelWidget* PanelWidget, int32 Index, UWidget* Child)
{
	const int32 CurrentIndex = PanelWidget->GetChildIndex(Child);
	TArray<UPanelSlot*> Slots = GetSlots(PanelWidget);
	//TArray<UPanelSlot*> Slots = PanelWidget->GetSlots();
	Slots.RemoveAt(CurrentIndex);
	Slots.Insert(Child->Slot, FMath::Clamp(Index, 0, Slots.Num()));

}

const TArray<UPanelSlot*>  GetSlots(UPanelWidget* PanelWidget)
{
	TArray<UPanelSlot*> Slots;
	int32 length = PanelWidget->GetChildrenCount();
	for (int32 i = 0; i < length; i++)
	{
		Slots.Add(PanelWidget->GetChildAt(i)->Slot);
	}

	return Slots;
}


