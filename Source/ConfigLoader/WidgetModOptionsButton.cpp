#include "WidgetModOptionsButton.h"


#include "WidgetBlueprintLibrary.h"
#include "util/Logging.h"






UModOptionsButton::UModOptionsButton(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SML::Logging::info("Mod options button class construct");

	mDisplayName = FText::FromString("Mod Options");
	mUseTransparentBackground = true;
	IsFocused = false;
	IsSelected = false;
	IsBigButton = false;
	FontSize = 15;
	PointerImage = NewObject<UImage>();
	Title = NewObject<UTextBlock>();


	mFrontEndButton = NewObject<UButton>(this, FName("Button"));



	//InitializeWidgetComponents();

	//Init Title
	//FSlateFontInfo mSlateFontInfo0;
	//mSlateFontInfo0.FontObject = 
	//mSlateFontInfo0.FontMaterial = Title->Font.FontMaterial;
	//mSlateFontInfo0.OutlineSettings = Title->Font.OutlineSettings;
	//mSlateFontInfo0.TypefaceFontName = Title->Font.TypefaceFontName;
	//FString path = FPaths::EngineContentDir() + TEXT('/Game/FactoryGame/Interface/Font/DescriptionText.DescriptionText');
	//SML::Logging::info("Font path: ", TCHAR_TO_ANSI(*path));
	//Title->SetFont(FSlateFontInfo(FPaths::EngineContentDir() / TEXT('/Game/FactoryGame/Interface/Font/DescriptionText.DescriptionText'),  15));
	//Title->SetFont(FSlateFontInfo("Arial", 15));
	//FString::ConcatFStrings<FString, FString>(FPaths::EngineContentDir(), TEXT('/Game/FactoryGame/Interface/Font/DescriptionText.DescriptionText'));
}

// Setup all of our components such as overlays etc.
void UModOptionsButton::InitializeWidgetComponents()
{

	//
	//// set up widget tree
	//auto WidgetTree = NewObject<UWidgetTree>(this, UWidgetTree::StaticClass(), TEXT("WidgetTree"));
	//WidgetTree->RootWidget->Visibility = ESlateVisibility::SelfHitTestInvisible;

	UOverlay* RootWidget = Cast<UOverlay>(GetRootWidget());

	//// set up our first overlay
	UOverlay* Overlay_0 = NewObject<UOverlay>(this, UOverlay::StaticClass(), TEXT("Overlay_0"));
	////TArray<UPanelSlot*> OverlaySlots_0 = Overlay_0->GetSlots();
	////OverlaySlots_0.Reserve(2);
	//UOverlay* Overlay_0 = WidgetTree->ConstructWidget<UOverlay>(UOverlay::StaticClass(), TEXT("Overlay_0"));

	//RootWidget->AddChild(Overlay_0);

	//Overlay_0->AddToRoot();

	//
	////UOverlaySlot* ButtonSlot = NewObject<UOverlaySlot>(Overlay_0, UOverlaySlot::StaticClass(), TEXT("ButtonSlot"));
	////ButtonSlot.HorizontalAlignment = EHorizontalAlignment::HAlign_Fill;

	//// Set up button style
	//mFrontEndButton = NewObject<UButton>(WidgetTree, UButton::StaticClass(), TEXT("mFrontEndButton"));
	//mFrontEndButton->WidgetStyle.Normal.ImageSize = FVector2D(8.000000, 8.000000);
	//mFrontEndButton->WidgetStyle.Normal.TintColor = FLinearColor(0.328125, 0.317329, 0.314032, 0.000000);
	//mFrontEndButton->WidgetStyle.Hovered.ImageSize = FVector2D(8.000000, 8.000000);
	//mFrontEndButton->WidgetStyle.Hovered.TintColor = FLinearColor(0.783538, 0.291771, 0.059511, 1.000000);
	//mFrontEndButton->WidgetStyle.Hovered.DrawAs = ESlateBrushDrawType::Type::Image;
	//mFrontEndButton->WidgetStyle.Pressed.ImageSize = FVector2D(8.000000, 8.000000);
	//mFrontEndButton->WidgetStyle.Pressed.TintColor = FLinearColor(0.095307, 0.095307, 0.095307, 1.000000);
	//mFrontEndButton->WidgetStyle.Pressed.DrawAs = ESlateBrushDrawType::Type::Image;
	//mFrontEndButton->WidgetStyle.NormalPadding.Left = 0.000000f;
	//mFrontEndButton->WidgetStyle.NormalPadding.Top = 0.000000f;
	//mFrontEndButton->WidgetStyle.NormalPadding.Right = 0.000000f;
	//mFrontEndButton->WidgetStyle.NormalPadding.Bottom = 0.000000f;
	//mFrontEndButton->WidgetStyle.PressedPadding.Left = 0.000000f;
	//mFrontEndButton->WidgetStyle.PressedPadding.Top = 0.000000f;
	//mFrontEndButton->WidgetStyle.PressedPadding.Right = 0.000000f;
	//mFrontEndButton->WidgetStyle.PressedPadding.Bottom = 0.000000f;
	//Overlay_0->AddChild(mFrontEndButton);


	//// set up title and containing overlay:
	//auto Overlay_1 = NewObject<UOverlay>(WidgetTree, UOverlay::StaticClass(), TEXT("Overlay_1"));

	//Title = NewObject<UTextBlock>(WidgetTree, UTextBlock::StaticClass(), TEXT("Title"));
	//Title->Text = FTextStringHelper::CreateFromBuffer(TEXT("NSLOCTEXT(\"UMG\", \"TextBlockDefaultValue\", \"Text Block\")"));





	// 

	//WidgetTree->RootWidget = Overlay_0;
};

void UModOptionsButton::NativePreConstruct()
{

	Super::NativePreConstruct();



	SML::Logging::info("Mod options button preconstruct");
	bIsFocusable = true;


	//// set button font

	//if (IsBigButton)
	//{
	//	FontSize = 25;
	//	//PointerImage->SetBrushSize(FVector2D(30, 30));
	//}
	//else
	//{
	//	FontSize = 15;
	//	//PointerImage->SetBrushSize(FVector2D(20, 20));
	//}
	////SetSelected(IsSelected);
	//FSlateFontInfo mSlateFontInfo;
	//mSlateFontInfo.FontObject = Title->Font.FontObject;
	//mSlateFontInfo.FontMaterial = Title->Font.FontMaterial;
	//mSlateFontInfo.OutlineSettings = Title->Font.OutlineSettings;
	//mSlateFontInfo.TypefaceFontName = Title->Font.TypefaceFontName;
	//mSlateFontInfo.Size = FontSize;
	//Title->SetFont(mSlateFontInfo);
	//SetTitle();



	////// set button background colors:
	//FLinearColor LColor1 = FLinearColor(0, 0, 0, 0);
	//FLinearColor LColor2 = FLinearColor(0.09530699998140335, 0.09530699998140335, 0.09530699998140335, 1);
	//FLinearColor LColor3;
	//switch (mUseTransparentBackground) {
	//case false: LColor3 = LColor2;
	//case true:LColor3 = LColor1;
	//};
	//FSlateColor mSlateColor = FSlateColor(LColor3);


	////// set slate brush
	//FSlateBrush mSlateBrush;
	//mSlateBrush.ImageSize = mFrontEndButton->WidgetStyle.Normal.ImageSize;
	//mSlateBrush.Margin = mFrontEndButton->WidgetStyle.Normal.Margin;
	//mSlateBrush.TintColor = mSlateColor;
	//mSlateBrush.SetResourceObject(mFrontEndButton->WidgetStyle.Normal.GetResourceObject());
	//mSlateBrush.DrawAs = mFrontEndButton->WidgetStyle.Normal.DrawAs;
	//mSlateBrush.Tiling = mFrontEndButton->WidgetStyle.Normal.Tiling;
	//mSlateBrush.Mirroring = mFrontEndButton->WidgetStyle.Normal.Mirroring;


	////// set button style
	//FButtonStyle mButtonStyle;
	//mButtonStyle.Normal = mSlateBrush;
	//mButtonStyle.Hovered = mFrontEndButton->WidgetStyle.Hovered;
	//mButtonStyle.Pressed = mFrontEndButton->WidgetStyle.Pressed;
	//mButtonStyle.Disabled = mFrontEndButton->WidgetStyle.Disabled;
	//mButtonStyle.NormalPadding = mFrontEndButton->WidgetStyle.NormalPadding;
	//mButtonStyle.PressedPadding = mFrontEndButton->WidgetStyle.PressedPadding;
	////mButtonStyle.SetPressedSound(mFrontEndButton->WidgetStyle.PressedSlateSound);
	////mButtonStyle.SetHoveredSound(mFrontEndButton->WidgetStyle.HoveredSlateSound);
	//mFrontEndButton->SetStyle(mButtonStyle);


};
//
//TSharedRef<SWidget> UModOptionsButton::RebuildWidget()
//{
//	TSharedRef<SWidget> Widget = Super::RebuildWidget();
//
//	UPanelWidget* RootWidget = Cast<UPanelWidget>(GetRootWidget());
//	//UOverlay* RootWidget = nullptr;
//	//if(WidgetTree)
//	//{
//	//	 RootWidget = WidgetTree->ConstructWidget<UOverlay>(UOverlay::StaticClass(), FName("RootWidget"));
//	//	 WidgetTree->RootWidget = RootWidget;
//
//	//}
//	//SML::Logging::info("Root widget: ", *UKismetSystemLibrary::GetDisplayName(RootWidget));
//
//
//
//	if (WidgetTree && RootWidget)
//	{
//
//
//		SML::Logging::info("Root widget: ", *UKismetSystemLibrary::GetDisplayName(RootWidget));
//
//		UOverlay* Overlay_000 = WidgetTree->ConstructWidget<UOverlay>(UOverlay::StaticClass(), TEXT("Overlay_000"));
//
//
//		//root overlay
//		UOverlay* Overlay_0 = WidgetTree->ConstructWidget<UOverlay>(UOverlay::StaticClass(), TEXT("Overlay_0"));
//
//		mFrontEndButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), FName("Button1"));
//		mFrontEndButton->WidgetStyle.Normal.ImageSize = FVector2D(8.000000, 8.000000);
//		mFrontEndButton->WidgetStyle.Normal.TintColor = FLinearColor(0.328125, 0.317329, 0.314032, 0.000000);
//		mFrontEndButton->WidgetStyle.Hovered.ImageSize = FVector2D(8.000000, 8.000000);
//		mFrontEndButton->WidgetStyle.Hovered.TintColor = FLinearColor(0.783538, 0.291771, 0.059511, 1.000000);
//		mFrontEndButton->WidgetStyle.Hovered.DrawAs = ESlateBrushDrawType::Type::Image;
//		mFrontEndButton->WidgetStyle.Pressed.ImageSize = FVector2D(8.000000, 8.000000);
//		mFrontEndButton->WidgetStyle.Pressed.TintColor = FLinearColor(0.095307, 0.095307, 0.095307, 1.000000);
//		mFrontEndButton->WidgetStyle.Pressed.DrawAs = ESlateBrushDrawType::Type::Image;
//		mFrontEndButton->WidgetStyle.NormalPadding.Left = 0.000000f;
//		mFrontEndButton->WidgetStyle.NormalPadding.Top = 0.000000f;
//		mFrontEndButton->WidgetStyle.NormalPadding.Right = 0.000000f;
//		mFrontEndButton->WidgetStyle.NormalPadding.Bottom = 0.000000f;
//		mFrontEndButton->WidgetStyle.PressedPadding.Left = 0.000000f;
//		mFrontEndButton->WidgetStyle.PressedPadding.Top = 0.000000f;
//		mFrontEndButton->WidgetStyle.PressedPadding.Right = 0.000000f;
//		mFrontEndButton->WidgetStyle.PressedPadding.Bottom = 0.000000f;
//
//
//
//		//container for text and pointer image
//		UOverlay* Overlay_1 = WidgetTree->ConstructWidget<UOverlay>(UOverlay::StaticClass(), TEXT("Overlay_1"));
//
//
//
//
//		// set up title block
//		Title = NewObject<UTextBlock>(WidgetTree, UTextBlock::StaticClass(), TEXT("Title"));
//		Title->Text = FTextStringHelper::CreateFromBuffer(TEXT("NSLOCTEXT(\"UMG\", \"TextBlockDefaultValue\", \"Text Block\")"));
//		Title->Font.FontObject = LoadObject<UObject>(nullptr, TEXT("/Game/FactoryGame/Interface/Font/DescriptionText.DescriptionText"));
//		Title->Font.TypefaceFontName = FName(TEXT("Font"));
//		Title->Font.Size = FontSize;
//
//
//
//
//		// set up pointer image
//		PointerImage = NewObject<UImage>(WidgetTree, UImage::StaticClass(), TEXT("PointerImage"));
//		FSlateBrush brush = FSlateBrush();
//		brush.DrawAs = ESlateBrushDrawType::Image;
//		brush.Tiling = ESlateBrushTileType::NoTile;
//		brush.ImageType = ESlateBrushImageType::NoImage;
//		brush.ImageSize = FVector2D(20.000000, 20.000000);
//		brush.TintColor = FLinearColor{1.0, 1.0, 1.0};
//		brush.Margin = FMargin(0.0);
//		UTexture2D* texture = LoadObject<UTexture2D>(nullptr, TEXT("/Game/FactoryGame/Interface/UI/Assets/Shared/MainMenu_Pointer.MainMenu_Pointer"));
//		brush.SetResourceObject(texture);
//		PointerImage->Brush = brush;
//
//
//		// add all children to widgets
//		//Overlay_0->AddChild(mFrontEndButton);
//		//Overlay_0->AddChild(Overlay_1);
//
//		//Overlay_000->AddChild(Overlay_0);
//		//RootWidget->AddChild(Overlay_000);
//		RootWidget->AddChild(mFrontEndButton);
//		RootWidget->AddChild(Overlay_1);
//		Overlay_1->AddChild(Title);
//		Overlay_1->AddChild(PointerImage);
//
//
//		// setup padding and alignment for all slots
//		if (UOverlaySlot* ButtonSlot = Cast<UOverlaySlot>(mFrontEndButton->Slot)) {
//			ButtonSlot->HorizontalAlignment = EHorizontalAlignment::HAlign_Fill;
//			ButtonSlot->VerticalAlignment = EVerticalAlignment::VAlign_Fill;
//		}
//
//		if (UOverlaySlot* Overlay_1_slot = Cast<UOverlaySlot>(Overlay_1->Slot))
//		{
//			SML::Logging::info("Overlay 2 slot is an overlay slot");
//			Overlay_1_slot->HorizontalAlignment = EHorizontalAlignment::HAlign_Fill;
//			Overlay_1_slot->VerticalAlignment = EVerticalAlignment::VAlign_Fill;
//		}
//
//		if (UOverlaySlot* TitleSlot = Cast<UOverlaySlot>(Title->Slot)) {
//			SML::Logging::info("titleslot is overlayslot");
//			TitleSlot->Padding.Left = 50.000000f;
//			TitleSlot->Padding.Top = 10.000000f;
//			TitleSlot->Padding.Right = 50.000000f;
//			TitleSlot->Padding.Bottom = 10.000000f;
//		}
//		else
//		{
//			SML::Logging::info("titleslot is not overlayslot");
//		}
//
//		if (UOverlaySlot* PointerSlot = Cast<UOverlaySlot>(PointerImage->Slot))
//		{
//			PointerSlot->HorizontalAlignment = EHorizontalAlignment::HAlign_Right;
//			PointerSlot->VerticalAlignment = EVerticalAlignment::VAlign_Center;
//		}
//
//		//if (UOverlaySlot* Overlay_0_slot = Cast<UOverlaySlot>(Overlay_0->Slot))
//		//{
//		//	SML::Logging::info("Overlay 2 slot is an overlay slot");
//		//	Overlay_0_slot->HorizontalAlignment = EHorizontalAlignment::HAlign_Fill;
//		//	Overlay_0_slot->VerticalAlignment = EVerticalAlignment::VAlign_Fill;
//		//}
//
//		//if (UOverlaySlot* Overlay_000_slot = Cast<UOverlaySlot>(Overlay_000->Slot))
//		//{
//		//	SML::Logging::info("Overlay 2 slot is an overlay slot");
//		//	Overlay_000_slot->HorizontalAlignment = EHorizontalAlignment::HAlign_Fill;
//		//	Overlay_000_slot->VerticalAlignment = EVerticalAlignment::VAlign_Fill;
//		//}
//
//
//
//		LogWidgetTree(RootWidget, 0);
//
//
//
//
//		if (IsDesignTime())
//		{
//			WidgetTree->SetFlags(RF_Transactional);
//			//WidgetTree->FindWidget("Button1");
//			WidgetTree->Modify();
//		}
//
//	}
//
//	return Widget;
//}
//

// for debug purposes
void UModOptionsButton::LogWidgetTree(UPanelWidget* Widget, int R = 0)
{
	TArray<UWidget*> children = Widget->GetAllChildren();

	FString tabs = FString("		");
	for(int i = 0; i <= R; i++)
	{
		tabs.Append(*FString("	"));
	}
	
	for (UWidget* child : children)
	{		
		SML::Logging::info(*tabs, "|	widget child: ", *UKismetSystemLibrary::GetDisplayName(child));
		

		if (UOverlaySlot* childPanelslot = Cast<UOverlaySlot>(child->Slot))
		{
			SML::Logging::info(*tabs, "|		Horizontal Alignment: ", *UEnum::GetValueAsString(childPanelslot->HorizontalAlignment.GetValue()));
			SML::Logging::info(*tabs, "|		Vertical Alignment: ", *UEnum::GetValueAsString(childPanelslot->VerticalAlignment.GetValue()));
		}

		if(UImage* image = Cast<UImage>(child))
		{
			SML::Logging::info(*tabs, "|		Color: ", *image->Brush.TintColor.GetSpecifiedColor().ToString());
			SML::Logging::info(*tabs, "|		Image Type: ", *UEnum::GetValueAsString(image->Brush.ImageType.GetValue()));
			
		}

		if(UTextBlock* text = Cast<UTextBlock>(child))
		{
			if(UOverlaySlot* textSlot = Cast<UOverlaySlot>(child->Slot))
			{
				SML::Logging::info(*tabs, "|		Padding: left: ", *FString::SanitizeFloat(textSlot->Padding.Left), "	|	Right: ", *FString::SanitizeFloat(textSlot->Padding.Right), "	|	Top: ", *FString::SanitizeFloat(textSlot->Padding.Top), "	|	Bottom: ", *FString::SanitizeFloat(textSlot->Padding.Bottom));
			}
		}

		
		if (UPanelWidget* childPanel = Cast<UPanelWidget>(child))
		{
			LogWidgetTree(childPanel,R+1);
		}
	}
}


UUserWidget* ModOptionsMenu;

void UModOptionsButton::NativeConstruct()
{
	Super::NativeConstruct();

	SML::Logging::info("mod options button construct");

	TScriptDelegate <FWeakObjectPtr> Delegate;

	Delegate.BindUFunction(this, FName("OnModButtonClicked"));

	mFrontEndButton->OnClicked.Add(Delegate);


	ShowButton();


	//FString path =  FPaths::ConvertRelativePathToFull(FPaths::ProjectDir().Append(TEXT("../Game/ExoSuitMod/ExoSuit/UI/Mod_Options_Menu.Mod_Options_Menu_C")));
	//SML::Logging::info(*path);

	//UClass* FModOpnsMenuClass = LoadObject<UClass>(nullptr, *path);
	//checkf(FModOpnsMenuClass, "The Mod options menu class could not be found!");
	/*UClass* FModOpnsMenuClass = LoadObject<UClass>(this, TEXT("/Game/ExoSuitMod/ExoSuit/UI/Mod_Options_Menu.Mod_Options_Menu_C"));
	ModOptionsMenu = CreateWidget<UUserWidget>(this, FModOpnsMenuClass, FName("ModOptionsMenu"));*/
}


void UModOptionsButton::NativeDestruct()
{
	Super::NativeDestruct();
}


void UModOptionsButton::SetPauseMenu(UUserWidget * PauseMenu, UWidget * FocusWidget, UFGWidgetSwitcher * Switcher)
{
	PauseMenuWidget = PauseMenu;
	mFocusWidget = FocusWidget;
	mSwitcher = Switcher;
}


void UModOptionsButton::OnModButtonClicked()
{
	SML::Logging::info("Button Clicked from c++ !!");


	//ModOptionsMenu->AddToViewport();

	//UWidgetBlueprintLibrary::GetAllWidgetsOfClass(GetWorld())



	if (PauseMenuWidget && mFocusWidget && mSwitcher)
	{
		if (!ModOptionsMenu)
		{
			UClass* FModOpnsMenuClass = LoadObject<UClass>(this, TEXT("/Game/ExoSuitMod/ExoSuit/UI/old_Mod_Options_Menu.old_Mod_Options_Menu_C"));
			ModOptionsMenu = CreateWidget<UUserWidget>(this, FModOpnsMenuClass, FName("ModOptionsMenu"));
		}



		SML::Logging::info("Setting mod menu as active widget...");
		if (!mSwitcher->HasChild(mTargetWidget)) {
			mSwitcher->AddChild(ModOptionsMenu);
			//mSwitcherWidget = mSwitcher;
			mTargetWidget = ModOptionsMenu;
			mSwitcher->SetActiveWidget(mTargetWidget);
		}

		SetActiveWidgetInSwitcher();
		CLearListOfSelections();

		mFocusWidget = this;




	}

	ModOptionsMenu->SetVisibility(ESlateVisibility::Visible);


	TArray<UWidget*> SwitcherChildren = mSwitcher->GetAllChildren();

	for (UWidget* Child : SwitcherChildren)
	{
		FString name = UKismetSystemLibrary::GetDisplayName(Child);
		FString childClass = UKismetSystemLibrary::GetDisplayName(Child->GetClass());
		FString vis = Child->IsVisible() ? TEXT("true") : TEXT("false");
		FString isMenu = (Child == ModOptionsMenu) ? TEXT("true") : TEXT("false");

		SML::Logging::info("Switcher child Name: ", TCHAR_TO_ANSI(*name), "  |  Class Name: ", TCHAR_TO_ANSI(*childClass), "  |  Visibility: ", TCHAR_TO_ANSI(*vis), "  |  IsMenu: ", TCHAR_TO_ANSI(*isMenu));
	}

}


void UModOptionsButton::SetTitle()
{
	Title->SetText(mDisplayName);
}

void UModOptionsButton::SetActiveWidgetInSwitcher()
{
	if (UKismetSystemLibrary::IsValid(mTargetWidget) && UKismetSystemLibrary::IsValid(mSwitcher))
	{
		UWidget* tempWidget;
		if (IsSelected)
		{
			tempWidget = nullptr;
		}
		else
		{
			tempWidget = mTargetWidget;
		}
		mSwitcher->SetActiveWidget(tempWidget);
		SetSelected(!IsSelected);
	}
}

void UModOptionsButton::CLearListOfSelections()
{
	UPanelWidget* LocalParent = nullptr;
	if (UKismetSystemLibrary::IsValid(mParentList))
	{
		LocalParent = mParentList;
	}
	else
	{
		UPanelWidget* mPanelWidget = GetParent();
		if (UKismetSystemLibrary::IsValid(mPanelWidget))
		{
			LocalParent = mPanelWidget;
		}
	}

	UClass* FButtonClass = LoadObject<UClass>(nullptr, TEXT("/Game/FactoryGame/Interface/UI/Menu/Widget_FrontEnd_Button.Widget_FrontEnd_Button_C"));

	//for (int32 i = 0; i <= LocalParent->GetChildrenCount(); i++)
	//{
	//	UWidget* mWidget = LocalParent->GetChildAt(i);
	//	/*auto mWidget_Button = Cast<FButtonClass->StaticClass()>(mWidget);*/
	//	UProperty* child_isSelected = nullptr;
	//	if (mWidget)
	//		child_isSelected = Cast<UProperty>(mWidget->GetClass()->FindPropertyByName(TEXT("isSelected")));

	//	//UFunction* child_SetSelected = mWidget->FindFunction("SetSelected");
	//	if (child_isSelected) {
	//		UBoolProperty* isSelected = Cast<UBoolProperty>(child_isSelected);

	//		if (this != mWidget)
	//		{
	//			//isSelected = false;
	//			isSelected->SetPropertyValue((void*)mWidget, false);
	//		}
	//		FString sel = isSelected->GetPropertyValue((void*)mWidget) ? TEXT("true") : TEXT("false");
	//		SML::Logging::info("Child of Switcher: ", *UKismetSystemLibrary::GetDisplayName(mWidget), "  |  isSelected: ", *sel);
	//	}
	//}


}

FSlateColor UModOptionsButton::GetButtonTextColor()
{
	return FSlateColor();
}

FLinearColor UModOptionsButton::GetButtonColor()
{
	return FLinearColor();
}

void UModOptionsButton::SetFocused()
{
	APlayerController* mPlayerController = GetOwningPlayer();
	mFrontEndButton->SetUserFocus(mPlayerController);
	mFrontEndButton->SetKeyboardFocus();
	IsFocused = true;
}

//FEventReply UModOptionsButton::OnFocusReceived(FGeometry MyGeometry, FFocusEvent InFocusEvent)
//{
//	Super::OnFocusReceived(MyGeometry, InFocusEvent);
//	SML::Logging::info("recieved focus");
//	APlayerController* mPlayerController = GetOwningPlayer();
//	mFrontEndButton->SetUserFocus(mPlayerController);
//	return  FEventReply(true);
//}

FReply UModOptionsButton::NativeOnFocusReceived(const FGeometry& InGeometry, const FFocusEvent& InFocusEvent)
{
	SML::Logging::info("received focus");
	APlayerController* mPlayerController = GetOwningPlayer();
	mFrontEndButton->SetUserFocus(mPlayerController);
	return OnFocusReceived(InGeometry, InFocusEvent).NativeReply;
}


void UModOptionsButton::ShowButton()
{
	mFrontEndButton->SetVisibility(ESlateVisibility(0));
}

void UModOptionsButton::HideButton()
{
	mFrontEndButton->SetVisibility(ESlateVisibility(1));
}

FText UModOptionsButton::GetButtonText()
{
	return mDisplayName;
}

bool UModOptionsButton::SetSelected(bool b)
{
	IsSelected = b;

	if (IsSelected)
	{
		PointerImage->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		PointerImage->SetVisibility(ESlateVisibility::Collapsed);
	}

	return b;
}



