#include "ConfigLoaderModule.h"
#include <fstream>
#include "ConfigLoaderActor.h"
#include "FactoryGame.h"
#include "FGGameMode.h"
#include "FGPlayerController.h"
#include "../SML/mod/hooking.h"
#include "util/Logging.h"
#include "Engine/World.h"
#include "PauseMenuTweaks.h"



//AConfigLoaderActor* actor;

void FConfigLoaderModule::StartupModule() {
	SUBSCRIBE_METHOD("?InitGameState@AFGGameMode@@UEAAXXZ", AFGGameMode::InitGameState, [](auto& scope, AFGGameMode* gameMode) {
		/*actor = gameMode->GetWorld()->SpawnActor<AConfigLoaderActor>(FVector::ZeroVector, FRotator::ZeroRotator);
		actor->DoStuff();*/

		APauseMenuTweaks* Tweaks = gameMode->GetWorld()->SpawnActor<APauseMenuTweaks>();
		
		
		Tweaks->GRegisterPauseMenuHooks();


	});

	SUBSCRIBE_METHOD("?BeginPlay@AFGPlayerController@@UEAAXXZ", AFGPlayerController::BeginPlay, [](auto&, AFGPlayerController* controller)
	{


		/*FString str = UKismetSystemLibrary::GetDisplayName(controller);
		SML::Logging::info("Player controller began play: ", TCHAR_TO_ANSI(*str));

		APawn* Player = controller->GetPawn();
		SML::Logging::info("hooked player: ", TCHAR_TO_ANSI(*Player->GetName()));
*/


		//UInputComponent* In = actor->getInputComponent(Player);
		//UInputComponent* Input = Player->InputComponent;




		
		//if (!Input)
		//{
		//	SML::Logging::info("Input comp null");
		//	return;
		//}
		//else
		//{
		//	SML::Logging::info("Input comp exists: ", TCHAR_TO_ANSI(*UKismetSystemLibrary::GetDisplayName(Input)));

		//	if (Input->HasBegunPlay())
		//	{
		//		SML::Logging::info("input comp has begun play");
		//	}
		//	else
		//	{
		//		SML::Logging::info("input comp has not begun play");
		//	}
		//}
		
		//actor->BindAction(Player, actor, "Dash", IE_Pressed, "DoStuff");
	});
}

IMPLEMENT_GAME_MODULE(FConfigLoaderModule, ConfigLoader);


