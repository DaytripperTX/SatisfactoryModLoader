//#include "ConfigLoader/BP_Generated/Mod_Button__pf365157904.h"
#include "PauseMenuTweaks.h"
#include "../SML/mod/blueprint_hooking.h"
#include "util/Logging.h"
#include "Components/VerticalBox.h"
#include "Components/Widget.h"
#include "FGButtonWidget.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/PanelWidget.h"
#include "FGWidgetSwitcher.h"
#include "WidgetModOptionsButton.h"
#include "Components/Button.h"



APauseMenuTweaks::APauseMenuTweaks()
{
	Button = NewObject<UButton>(this, FName("Button"));

	TScriptDelegate <FWeakObjectPtr> Delegate;

	Delegate.BindUFunction(this, FName("OnModButtonClicked"));

	Button->OnClicked.Add(Delegate);

	//Button->OnClicked.AddDynamic(this, &APauseMenuTweaks::OnModButtonClicked());

	if (Delegate.IsBound())
	{
		SML::Logging::info("Delegate is Bound");
		UObject* DelObj = Delegate.GetUObject();
		SML::Logging::info("Object Name: ", TCHAR_TO_ANSI(*UKismetSystemLibrary::GetDisplayName(DelObj)), "  |  Class Name: ", TCHAR_TO_ANSI(*UKismetSystemLibrary::GetDisplayName(DelObj->GetClass())));
		FName DelName = Delegate.GetFunctionName();
		SML::Logging::info(*DelName.ToString(), 1);
	}


	SML::Logging::info("Pause menu tweaks class constructed");

};


void APauseMenuTweaks::GRegisterPauseMenuHooks()
{
	UClass* PauseMenuClass = LoadObject<UClass>(nullptr, TEXT("/Game/FactoryGame/Interface/UI/Menu/PauseMenu/BP_PauseWidget.BP_PauseWidget_C"));
	check(PauseMenuClass);
	UFunction* ConstructFn = PauseMenuClass->FindFunctionByName(TEXT("Construct"));
	check(ConstructFn);
	HookBlueprintFunction(ConstructFn, [&](FBlueprintHookHelper& HookHelper) {
		//Retrieve Menu Options vertical box
		UUserWidget* PauseMenuWidget = Cast<UUserWidget>(HookHelper.GetContext());
		UObjectProperty* Property = Cast<UObjectProperty>(PauseMenuWidget->GetClass()->FindPropertyByName(TEXT("MenuOptions")));
		checkf(Property, TEXT("Menu Options not found"));
		UVerticalBox* MenuOptions = Cast<UVerticalBox>(Cast<UWidget>(Property->GetObjectPropertyValue_InContainer(PauseMenuWidget)));

		// Instantiate Mod Options Button
		//UClass* FButtonClass = LoadObject<UClass>(nullptr, TEXT("/Game/FactoryGame/Interface/UI/Menu/Widget_FrontEnd_Button.Widget_FrontEnd_Button_C"));
		//UClass* FButtonClass = LoadObject<UClass>(nullptr, TEXT("/Game/ExoSuitMod/ExoSuit/UI/Mod_Button.Mod_Button_C"));
		//UModOptionsButton* ModButton = CreateWidget<UModOptionsButton>(MenuOptions, FButtonClass, FName("ModButton"));
		/*SML::Logging::info("IS ModButton constructed: ", ModButton->IsConstructed());*/
		//ModButton->SetButton(Button);

		//test mod button class
		UModOptionsButton* ModButton = CreateWidget<UModOptionsButton>(MenuOptions, UModOptionsButton::StaticClass(), FName("ModButton"));
		//UMod_Button_C* ModButton = CreateWidget<UMod_Button_C>(MenuOptions, UModOptionsButton::StaticClass(), FName("ModButton"));




		// Retrieve mFocusWidget
		UObjectProperty* Prop_mFocus = Cast<UObjectProperty>(PauseMenuWidget->GetClass()->FindPropertyByName(TEXT("mFocusWidget")));
		checkf(Prop_mFocus, TEXT("mFocusWidget not found"));
		UWidget* Pause_mFocusWidget = Cast<UWidget>(Prop_mFocus->GetObjectPropertyValue_InContainer(PauseMenuWidget));

		//SML::Logging::info("Object Name: ", TCHAR_TO_ANSI(*UKismetSystemLibrary::GetDisplayName(Pause_mFocusWidget)), "  |  Class Name: ", TCHAR_TO_ANSI(*UKismetSystemLibrary::GetDisplayName(Pause_mFocusWidget->GetClass())));


		// Retrieve mSwitcher
		UObjectProperty* Prop_mSwitcher = Cast<UObjectProperty>(PauseMenuWidget->GetClass()->FindPropertyByName(TEXT("mSwitcher")));
		checkf(Prop_mSwitcher, TEXT("mSwitcher not found"));
		UFGWidgetSwitcher* mSwitcher = Cast<UFGWidgetSwitcher>(Cast<UWidget>(Prop_mSwitcher->GetObjectPropertyValue_InContainer(PauseMenuWidget)));

		//SML::Logging::info("Object Name: ", TCHAR_TO_ANSI(*UKismetSystemLibrary::GetDisplayName(mSwitcher)), "  |  Class Name: ", TCHAR_TO_ANSI(*UKismetSystemLibrary::GetDisplayName(mSwitcher->GetClass())));


		// Insert Mod Options Button into array of pause buttons

		if (!MenuOptions->HasChild(ModButton)) 
		{
			MenuOptions->AddChild(ModButton);
		}

		ModButton->SetPauseMenu(PauseMenuWidget, Pause_mFocusWidget, mSwitcher);


		ModButton->ShowButton();

		//TArray<UWidget*> SwitcherChildren = mSwitcher->GetAllChildren();

		//for (UWidget* Child : SwitcherChildren)
		//{
		//	FString name = UKismetSystemLibrary::GetDisplayName(Child);
		//	FString childClass = UKismetSystemLibrary::GetDisplayName(Child->GetClass());
		//	FString vis = Child->IsVisible() ? TEXT("true") : TEXT("false");

		//	SML::Logging::info("Switcher child Name: ", TCHAR_TO_ANSI(*name), "  |  Class Name: ", TCHAR_TO_ANSI(*childClass), "  |  Visibility: ", TCHAR_TO_ANSI(*vis));
		//}






		//APlayerController* PlayerController = PauseMenuWidget->GetOwningPlayer();




		//UObjectProperty* Prop_Button_click = Cast<UObjectProperty>(ModButton->GetClass()->FindPropertyByName("mInternalButton"));
		//checkf(Prop_Button_click, TEXT("Button OnClicked not found"));


		//if (Button->OnClicked.IsBound())
		//{
		//	SML::Logging::info("Button is bound");
		//	TArray<UObject*> BoundObjs = Button->OnClicked.GetAllObjects();
		//	for (UObject* Element : BoundObjs)
		//	{
		//		SML::Logging::info("Object Name: ", TCHAR_TO_ANSI(*UKismetSystemLibrary::GetDisplayName(Element)), "  |  Class Name: ", TCHAR_TO_ANSI(*UKismetSystemLibrary::GetDisplayName(Element->GetClass())));
		//		
		//	}
		//}

		//SML::Logging::info("Object Name: ", TCHAR_TO_ANSI(*UKismetSystemLibrary::GetDisplayName(Prop_Button_click)), "  |  Class Name: ", TCHAR_TO_ANSI(*UKismetSystemLibrary::GetDisplayName(Prop_Button_click->GetClass())));




		//TODO: create swap child at fn


		//InsertChildAt(MenuOptions, 8, ModButton);






		TArray<UWidget*> PauseButtons = MenuOptions->GetAllChildren();
		////PauseButtons = MenuOptions->GetAllChildren();

		for (UWidget* child : PauseButtons)
		{
			SML::Logging::info("Menu Child Name: ", TCHAR_TO_ANSI(*UKismetSystemLibrary::GetDisplayName(child)), "  |  Class Name: ", TCHAR_TO_ANSI(*UKismetSystemLibrary::GetDisplayName(child->GetClass())));
		}

	}, EPredefinedHookOffset::Return);


	/*FTimerHandle Timer;
	FTimerDelegate TimerDel;

	TimerDel.BindUFunction(this, FName("DoTimer"));
	SML::Logging::info("Setting timer for 60 sec then will call button event");
	GetWorldTimerManager().SetTimer(Timer, TimerDel, 20.0f, false);*/
};


void APauseMenuTweaks::BeginPlay()
{
	//APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

	//UClass* FButtonClass = LoadObject<UClass>(nullptr, TEXT("/Game/ExoSuitMod/ExoSuit/UI/Mod_Options_btn.Mod_Options_btn_C"));
	//ModButton = CreateWidget<UFGButtonWidget>(PlayerController, FButtonClass, FName("ModButton"));
	//ModButton->SetButton(Button);
};


void APauseMenuTweaks::InsertChildAt(UPanelWidget* PanelWidget, int32 Index, UWidget* Content)
{
	UPanelSlot* NewSlot = PanelWidget->AddChild(Content);
	ShiftChild(PanelWidget, Index, Content);


};

void APauseMenuTweaks::ShiftChild(UPanelWidget* PanelWidget, int32 Index, UWidget* Child)
{
	const int32 CurrentIndex = PanelWidget->GetChildIndex(Child);
	TArray<UPanelSlot*> Slots = GetSlots(PanelWidget);
	//TArray<UPanelSlot*> Slots = PanelWidget->GetSlots();
	Slots.RemoveAt(CurrentIndex);
	Slots.Insert(Child->Slot, FMath::Clamp(Index, 0, Slots.Num()));
	Slots[Index]->SynchronizeProperties();

};

TArray<UPanelSlot*> APauseMenuTweaks::GetSlots(UPanelWidget* PanelWidget)
{
	TArray<UPanelSlot*> Slots;
	int32 length = PanelWidget->GetChildrenCount();
	for (int32 i = 0; i < length; i++)
	{
		Slots.Add(PanelWidget->GetChildAt(i)->Slot);
	}

	return Slots;
};

bool APauseMenuTweaks::ReplaceChildAt(UPanelWidget* PanelWidget, int32 Index, UWidget* Content) const
{
	//TArray<UPanelSlot*> Slots = GetSlots(PanelWidget);
	//if(Index < 0 || Index >= Slots.Num())
	//{
	//	return false;
	//}

	UPanelSlot* PanelSlot = PanelWidget->GetChildAt(Index)->Slot;
	if (PanelSlot)
		PanelSlot->Content = Content;

	if (Content)
	{
		Content->Slot = PanelSlot;
	}
	SML::Logging::info("", TCHAR_TO_ANSI(*UKismetSystemLibrary::GetDisplayName(PanelSlot->Content)));
	PanelSlot->SynchronizeProperties();

	return true;

};

void APauseMenuTweaks::OnModButtonClicked()
{
	//SML::Logging::info("Button Clicked from c++ !!");
}

void APauseMenuTweaks::DoTimer()
{
	Button->OnClicked.Broadcast();

};


