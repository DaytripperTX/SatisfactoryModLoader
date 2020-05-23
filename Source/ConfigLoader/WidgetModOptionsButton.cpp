#include "WidgetModOptionsButton.h"

#include "util/Logging.h"






UModOptionsButton::UModOptionsButton(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

	mDisplayName = FText::FromString("Mod Options Button");
	mUseTransparentBackground = true;
	IsFocused = false;
	IsSelected = false;
	IsBigButton = false;

	//mFrontEndButton = NewObject<UButton>(this, FName("Button"));

	Title = NewObject<UTextBlock>();

	InitializeWidgetComponents();

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

	//// set up our first overlay
	//auto Overlay_0 = NewObject<UOverlay>(WidgetTree, UOverlay::StaticClass(), TEXT("Overlay_0"));
	////TArray<UPanelSlot*> OverlaySlots_0 = Overlay_0->GetSlots();
	////OverlaySlots_0.Reserve(2);

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

	

	
	//// set button font
	//FSlateFontInfo mSlateFontInfo;
	//if (IsBigButton)
	//{
	//	FontSize = 25;
	//}
	//else
	//{
	//	FontSize = 15;
	//}
	//mSlateFontInfo.FontObject = Title->Font.FontObject;
	//mSlateFontInfo.FontMaterial = Title->Font.FontMaterial;
	//mSlateFontInfo.OutlineSettings = Title->Font.OutlineSettings;
	//mSlateFontInfo.TypefaceFontName = Title->Font.TypefaceFontName;
	//mSlateFontInfo.Size = FontSize;
	//Title->SetFont(mSlateFontInfo);
	//SetTitle();



	//// set button background colors:
	//FLinearColor LColor1 = FLinearColor(0, 0, 0, 0);
	//FLinearColor LColor2 = FLinearColor(0.09530699998140335, 0.09530699998140335, 0.09530699998140335, 1);
	//FLinearColor LColor3;
	//switch (mUseTransparentBackground) {
	//case false: LColor3 = LColor2;
	//case true:LColor3 =  LColor1;
	//};
	//FSlateColor mSlateColor = FSlateColor(LColor3);


	//// set slate brush
	//FSlateBrush mSlateBrush;
	//mSlateBrush.ImageSize = mFrontEndButton->WidgetStyle.Normal.ImageSize;
	//mSlateBrush.Margin = mFrontEndButton->WidgetStyle.Normal.Margin;
	//mSlateBrush.TintColor = mSlateColor;
	//mSlateBrush.SetResourceObject(mFrontEndButton->WidgetStyle.Normal.GetResourceObject());
	//mSlateBrush.DrawAs = mFrontEndButton->WidgetStyle.Normal.DrawAs;
	//mSlateBrush.Tiling = mFrontEndButton->WidgetStyle.Normal.Tiling;
	//mSlateBrush.Mirroring = mFrontEndButton->WidgetStyle.Normal.Mirroring;


	//// set button style
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

void UModOptionsButton::NativeConstruct()
{
	Super::NativeConstruct();
	
	TScriptDelegate <FWeakObjectPtr> Delegate;

	Delegate.BindUFunction(this, FName("OnModButtonClicked"));

	mFrontEndButton->OnClicked.Add(Delegate);

	ShowButton();
}


void UModOptionsButton::NativeDestruct()
{
	Super::NativeDestruct();
}



void UModOptionsButton::OnModButtonClicked()
{
	SML::Logging::info("Button Clicked from c++ !!");
}





void UModOptionsButton::SetTitle()
{
	Title->SetText(mDisplayName);
}

void UModOptionsButton::SetActiveWidgetInSwitcher()
{
}

void UModOptionsButton::CLearListOfSelections()
{
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
}

void UModOptionsButton::OnFocusRecieved()
{
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
	return FText();
}

bool UModOptionsButton::SetSelected()
{
	return false;
}



