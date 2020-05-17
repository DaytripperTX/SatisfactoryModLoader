#include "ConfigLoaderActor.h"
#include "util/Logging.h"
#include "../SML/mod/hooking.h"
#include "Kismet/GameplayStatics.h"
#include "Components/InputComponent.h"
//#include "Delegates/DelegateSignatureImpl.inl"
#include "UObject/UObjectGlobals.h"
#include "TimerManager.h"

#include "Engine/World.h"

#include "FGGameMode.h"




AConfigLoaderActor::AConfigLoaderActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this->bAllowTickBeforeBeginPlay = false;

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("StaticMesh'/Game/ChainsawMod/test/Cube.Cube'"));

	if (CubeVisualAsset.Succeeded())
	{
		VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 100.0f));
	}




}




void AConfigLoaderActor::DoStuff() {
	SML::Logging::info("ConfigLoaderActor");
	const FString Str = "Do stuff";

	SML::Logging::info("Do stuff");
}

void AConfigLoaderActor::AddAction(const struct FInputActionKeyMapping & Mapping)
{
	const FName ActionName = FName("Dash");
	Settings->AddActionMapping(Mapping);
	//Settings->AddActionMapping(FInputActionKeyMapping(FName("Charge"), FKey("Left Alt")));

}

// ReSharper disable once CppMemberFunctionMayBeStatic
void AConfigLoaderActor::BindAction(APawn* Player, UObject* TargetObject, const FName ActionName, const EInputEvent KeyEvent, const FName FunctionName)
{
	////use  AddActionBinding(FInputActionBinding Binding)

	UInputComponent* Input = getInputComponent(Player);

	if (!Input)
	{
		SML::Logging::info("Input comp null");
		return;
	}
	else
	{
		SML::Logging::info("Input comp exists: ", TCHAR_TO_ANSI(*UKismetSystemLibrary::GetDisplayName(Input)));
	}

	//int32 n = Input->GetNumActionBindings();
	//const int32 n0 = Input->GetNumActionBindings();

	//if (!n0)
	//{
	//	SML::Logging::info("num action binds null");
	//}

	/*if(Input->HasBegunPlay())
	{
		SML::Logging::info("input comp has begun play");
	}else
	{
		SML::Logging::info("input comp has not begun play");
	}*/

	SML::Logging::debug("Debug 0");

	//SML::Logging::info("Num Action Binds before adding bind: ", TCHAR_TO_ANSI(*FString::FromInt(n0)));


	//SML::Logging::info("------------------0");

	const bool hasBind = Input->HasBindings();




	

	if (!hasBind)
	{
		SML::Logging::info("Input comp has no bindings!");
	}
	{

		SML::Logging::info("Input comp has  bindings:  ");

		SML::Logging::info("------------------Action Bindings:------------------\n\n");

		int32 n = Input->GetNumActionBindings();
		SML::Logging::info("Num Action Binds: ", TCHAR_TO_ANSI(*FString::FromInt(n)));

		if (n > 0)
		{
			for (int32 i = 0; i > n; i++)
			{
				FName bind = Input->GetActionBinding(i).GetActionName();
				FString str = bind.ToString();

				SML::Logging::info("Found Action Bind:   ", TCHAR_TO_ANSI(*str));
			}
		}

		SML::Logging::info("------------------Action Bindings:------------------\n\n");


	}

	SML::Logging::debug("Debug 1");

	//	//Input->AddActionBinding(FInputActionBinding(ActionName, KeyEvent));
	//	//UKismetSystemLibrary::PrintString(World, UKismetSystemLibrary::GetDisplayName(InputComponent));
	//UKismetSystemLibrary::PrintString(World, "----------");
	/*FInputActionHandlerSignature Delegate;
	Delegate.BindUFunction(TargetObject, FunctionName);
	SML::Logging::debug("Debug 2");*/

	////Input->BindAction(ActionName, KeyEvent, TargetObject, );

	//FInputActionBinding NewActionBinding = FInputActionBinding(ActionName, KeyEvent);
	////NewActionBinding.ActionName = ActionName;
	////NewActionBinding.KeyEvent = KeyEvent;
	//NewActionBinding.ActionDelegate = Delegate;
	//SML::Logging::debug("Debug 3");
	////Input->AddActionBinding(NewActionBinding);

	//SML::Logging::info("------------------Action Bindings:------------------\n\n");

	//int32 n = Input->GetNumActionBindings();
	//SML::Logging::info("Num Action Binds: ", TCHAR_TO_ANSI(*FString::FromInt(n)));

	//if (n > 0)
	//{
	//	for (int32 i = 0; i > n; i++)
	//	{
	//		FName bind = Input->GetActionBinding(i).GetActionName();
	//		FString str = bind.ToString();

	//		SML::Logging::info("Found Action Bind:   ", TCHAR_TO_ANSI(*str));
	//	}
	//}

	//SML::Logging::info("------------------Action Bindings:------------------\n\n");

	////return;

}

UInputComponent* AConfigLoaderActor::getInputComponent(APawn* Player) const
{
	if (!Player)
	{
		Player = GetWorld()->GetFirstPlayerController()->GetPawn();
	}
	UInputComponent* Input = Player->InputComponent;

	if (!Input)
	{
		SML::Logging::info("Player Input Component null");
		return nullptr;
	}
	else
	{
		return Input;
	}

	//FObjectInitializer fob = new FObjectInitializer();
	//UInputComponent Input = UInputComponent(this);
	//
	//
	//
	//SML::Logging::info("DEBUG 00");
	//auto *Input = NewObject<UInputComponent>();
	//Input->RegisterComponent();
	//Player->AddComponent(FName("Input"), false, FTransform(), Input);
	//
	//
	//SML::Logging::info("Input comp owner: ", TCHAR_TO_ANSI(*UKismetSystemLibrary::GetDisplayName(Input->GetOwner())));
	//SML::Logging::info("DEBUG 01");

	//TArray<UActorComponent*> comp;
	//Player->GetComponents(comp);
	//SML::Logging::info("debug 02");

	//for (UActorComponent* i : comp)
	//{
	//	SML::Logging::info("comp exists: ", TCHAR_TO_ANSI(*UKismetSystemLibrary::GetDisplayName(i)), "  |	", TCHAR_TO_ANSI(*UKismetSystemLibrary::GetClassDisplayName(i->GetClass())));
	//}

	//return Input;

}

// Called when the game starts or when spawned
void AConfigLoaderActor::BeginPlay()
{
	Super::BeginPlay();
	SML::Logging::info("beginPlay");
	////BindAction({}, FName("Dash"), EInputEvent(0));
	//World = GEngine->GetWorldContexts()[0];

	World = this->GetWorld();

	UWorld* wo = this->GetWorld();


	if (SML::IsMenuMapName(wo->GetPathName()))
	{
		SML::Logging::info("This is the main menu");
	}
	else
	{
		SML::Logging::info("This is not the main menu");
		
				APawn* Player = GetWorld()->GetFirstPlayerController()->GetPawn();
				//BindAction(Player, "Dash", IE_Pressed, "DoStuff");
		

		if (!World)
		{
			SML::Logging::info("World Null");
		}

		Settings = const_cast<UInputSettings*>(GetDefault<UInputSettings>());

		AddAction(FInputActionKeyMapping(FName("Dash"), FKey("Left Ctrl")));
		AddAction(FInputActionKeyMapping(FName("Charge"), FKey("Left Alt")));


		SML::Logging::info("------------------Action Mappings:------------------\n");

		TArray<FName> Mappings;
		Settings->GetActionNames(Mappings);

		for (FName Name : Mappings)
		{
			//UKismetSystemLibrary::PrintString(World, Name.ToString());
			SML::Logging::info(*Name.ToString(), 1);
		}
		//UKismetSystemLibrary::PrintString(World, FString("------------------------------------"));

		SML::Logging::info("------------------Action Mappings:------------------\n");



		FTimerHandle Timer;
		FTimerDelegate TimerDel;

		TimerDel.BindUFunction(this, FName("BindAction"), Player, this, FName("Dash"), IE_Pressed, FName("DoStuff"));
		SML::Logging::info("Setting timer for 60 sec then will bind action");
		GetWorldTimerManager().SetTimer(Timer, TimerDel, 10.0f, false);


	

		
	}

}



// Called every frame
void AConfigLoaderActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	FVector NewLocation = GetActorLocation();
	FRotator NewRotation = GetActorRotation();
	float RunningTime = GetGameTimeSinceCreation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Z += DeltaHeight * 20.0f;       //Scale our height by a factor of 20
	float DeltaRotation = DeltaTime * 20.0f;    //Rotate by 20 degrees per second
	NewRotation.Yaw += DeltaRotation;
	SetActorLocationAndRotation(NewLocation, NewRotation);
	//DoStuff();



	//SML::Logging::info("------------------Action Mappings:------------------\n");

	//TArray<FName> Mappings;
	//Settings->GetActionNames(Mappings);

	//for (FName Name : Mappings)
	//{
	//	UKismetSystemLibrary::PrintString(World, Name.ToString());
	//	//SML::Logging::info(*Name.ToString(), 1);
	//}
	//UKismetSystemLibrary::PrintString(World, FString("------------------------------------"));
	//SML::Logging::info("------------------Action Mappings:------------------\n");
	////SML::Logging::info("------------------------------------");



}