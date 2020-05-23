#pragma once

#include "Button.h"
#include "CoreMinimal.h"
#include "CoreUObject.h"
#include "FGButtonWidget.h"
#include "PanelWidget.h"
#include "GameFramework/Actor.h"
#include "PauseMenuTweaks.generated.h"


UCLASS()
class CONFIGLOADER_API APauseMenuTweaks : public AActor {
	GENERATED_BODY()
public:

	APauseMenuTweaks();

	UPROPERTY(meta = (BindWidget))
		UButton* Button;

	UPROPERTY()
		UFGButtonWidget* ModButton;

	UFUNCTION()
		void OnModButtonClicked();



	UFUNCTION()
		void GRegisterPauseMenuHooks();

	UFUNCTION()
		void InsertChildAt(UPanelWidget* PanelWidget, int32 Index, UWidget* Content);

	UFUNCTION()
		void ShiftChild(UPanelWidget* PanelWidget, int32 Index, UWidget* Child);

	UFUNCTION()
		static TArray<UPanelSlot*> GetSlots(UPanelWidget* PanelWidget);

	UFUNCTION()
		bool ReplaceChildAt(UPanelWidget* PanelWidget, int32 Index, UWidget* Content) const;

	UFUNCTION()
		void DoTimer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};