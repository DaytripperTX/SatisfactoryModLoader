#pragma once

#include "CoreMinimal.h"
#include "CoreUObject.h"
#include "GameFramework/Actor.h"
#include "FGGameMode.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
//#include "Delegates/DelegateSignatureImpl.inl"
#include "ConfigLoaderActor.generated.h"


struct FInputActionKeyMapping;
UCLASS()
class CONFIGLOADER_API AConfigLoaderActor : public AActor {
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
		static void DoStuff();

	// Sets default values for this actor's properties
	AConfigLoaderActor();

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* VisualMesh;

	UPROPERTY()
		UObject *World;

	UPROPERTY()
		UInputSettings *Settings;

	UFUNCTION(BlueprintCallable, BlueprintPure)
		void AddAction(const struct  FInputActionKeyMapping& Mapping);

	UFUNCTION(BlueprintCallable)
		void BindAction(APawn* Player, UObject* TargetObject, const FName ActionName, const EInputEvent KeyEvent, const FName FunctionName);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Get Player Input Component"))
		UInputComponent* getInputComponent(APawn* Player) const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};