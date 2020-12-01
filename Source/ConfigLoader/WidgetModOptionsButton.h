#pragma once
//#include "FGButtonWidget.h"
#include "UObject/Class.h"
#include "Button.h"
#include "FGWidgetSwitcher.h"
#include "Image.h"
#include "TextBlock.h"
#include "WidgetSwitcher.h"
#include "WidgetModOptionsButton.generated.h"



UCLASS()
class CONFIGLOADER_API UModOptionsButton : public UUserWidget
{
	GENERATED_BODY()
public:

	UModOptionsButton(const FObjectInitializer& ObjectInitializer);

	// Member Properties:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UButton* mFrontEndButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTextBlock* Title;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UImage* PointerImage;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText mDisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UWidgetSwitcher* mSwitcherWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UWidget* mTargetWidget;  //This is the widget that will get displayed when the button is clicked

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UPanelWidget* mParentList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool mUseTransparentBackground;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsFocused;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsSelected;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsBigButton;

	UPROPERTY(EditAnywhere)
		int FontSize;


	// Properties related to the Pause Menu:
	UPROPERTY()
		UUserWidget* PauseMenuWidget;
	
	UPROPERTY()
		UWidget* mFocusWidget;

	UPROPERTY()
		UFGWidgetSwitcher* mSwitcher; // This is a reference to the pause menu's switcher
	


	///Member Functions:
	UFUNCTION()
		void SetPauseMenu(UUserWidget* PauseMenu, UWidget* FocusWidget, UFGWidgetSwitcher* Switcher);
	
	UFUNCTION(BlueprintCallable)
		void OnModButtonClicked();

	UFUNCTION(BlueprintCallable)
		void SetTitle();

	UFUNCTION(BlueprintCallable)
		void SetActiveWidgetInSwitcher();

	UFUNCTION(BlueprintCallable)
		void CLearListOfSelections();

	UFUNCTION(BlueprintCallable)
		FSlateColor GetButtonTextColor();

	UFUNCTION(BlueprintCallable)
		FLinearColor GetButtonColor();

	UFUNCTION(BlueprintCallable)
		void SetFocused();


	UFUNCTION(BlueprintCallable)
		void ShowButton();

	UFUNCTION(BlueprintCallable)
		void HideButton();

	UFUNCTION(BlueprintCallable)
		FText GetButtonText();

	UFUNCTION(BlueprintCallable)
		bool SetSelected(bool b);

	//UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category = "Input")
		//FEventReply OnFocusReceived(FGeometry MyGeometry, FFocusEvent InFocusEvent) override;

	virtual FReply NativeOnFocusReceived(const FGeometry& InGeometry, const FFocusEvent& InFocusEvent) override;

	

protected:
	virtual void NativePreConstruct() override;

	virtual void NativeConstruct() override;

	virtual void NativeDestruct() override;

	void InitializeWidgetComponents();

	//virtual TSharedRef<SWidget> RebuildWidget() override;

	void LogWidgetTree(UPanelWidget* Widget, int R);


public:
	FORCEINLINE ~UModOptionsButton() = default;
};




