#pragma once
//#include "FGButtonWidget.h"
#include "UObject/Class.h"

#include "Button.h"
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

	//UPROPERTY()
	//	Fima

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText mDisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UWidgetSwitcher* mSwitcherWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UWidget* mTargetWidget;

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


	///Member Functions:

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
		void OnFocusRecieved();

	UFUNCTION(BlueprintCallable)
		void ShowButton();

	UFUNCTION(BlueprintCallable)
		void HideButton();

	UFUNCTION(BlueprintCallable)
		FText GetButtonText();

	UFUNCTION(BlueprintCallable)
		bool SetSelected();


protected:
	virtual void NativePreConstruct() override;

	virtual void NativeConstruct() override;

	virtual void NativeDestruct() override;

	 void InitializeWidgetComponents();



public:
	FORCEINLINE ~UModOptionsButton() = default;
};




