// Copyright Epic Games, Inc. All Rights Reserved.

#include "Player/LyraUIPlayerController.h"

#include "LyraLogChannels.h"
#include "Player/LyraLocalPlayer.h"
#include "Settings/LyraSettingsLocal.h"
#include "Settings/LyraSettingsShared.h"
#include "UI/LyraHUD.h"

#include "CommonInputTypeEnum.h"
#include "GameFramework/Pawn.h"
#include "CommonInputSubsystem.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputMappingContext.h"
#include "Engine/LocalPlayer.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(LyraUIPlayerController)

namespace LyraUI
{
	namespace Input
	{
		static int32 ShouldAlwaysPlayForceFeedback = 0;
		static FAutoConsoleVariableRef CVarShouldAlwaysPlayForceFeedback(TEXT("LyraPC.ShouldAlwaysPlayForceFeedback"),
			ShouldAlwaysPlayForceFeedback,
			TEXT("Should force feedback effects be played, even if the last input device was not a gamepad?"));
	}
}

ALyraHUD* ALyraUIPlayerController::GetLyraHUD() const
{
	return CastChecked<ALyraHUD>(GetHUD(), ECastCheckedType::NullAllowed);
}

ALyraUIPlayerController::ALyraUIPlayerController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void ALyraUIPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void ALyraUIPlayerController::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void ALyraUIPlayerController::SetPlayer(UPlayer* InPlayer)
{
	Super::SetPlayer(InPlayer);

	if (const ULyraLocalPlayer* LyraLocalPlayer = Cast<ULyraLocalPlayer>(InPlayer))
	{
		ULyraSettingsShared* UserSettings = LyraLocalPlayer->GetSharedSettings();
		UserSettings->OnSettingChanged.AddUObject(this, &ThisClass::OnSettingsChanged);

		OnSettingsChanged(UserSettings);

		AddInputConfig();
	}
}

void ALyraUIPlayerController::OnSettingsChanged(ULyraSettingsShared* InSettings)
{
	bForceFeedbackEnabled = InSettings->GetForceFeedbackEnabled();
}

void ALyraUIPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

}

void ALyraUIPlayerController::OnUnPossess()
{
	Super::OnUnPossess();

}

void ALyraUIPlayerController::AddInputConfig()
{

	if (DefaultInputMappings.IsEmpty()) return;

	//Get EnhancedInputLocalPlayerSubsystem
	UEnhancedInputLocalPlayerSubsystem* InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (!InputSubsystem) return;

	//Get user settings for registration
	UEnhancedInputUserSettings* UserSettings = InputSubsystem->GetUserSettings();
	if (!UserSettings) return;

	for (const FInputMappingContextAndPriority& Mapping : DefaultInputMappings)
	{
		if (UInputMappingContext* IMC = Mapping.InputMapping.LoadSynchronous())
		{

			FModifyContextOptions Options = {};
			Options.bIgnoreAllPressedKeysUntilRelease = false;

			InputSubsystem->AddMappingContext(IMC, Mapping.Priority, Options);

			if (Mapping.bRegisterWithSettings)
				UserSettings->RegisterInputMappingContext(IMC);
		
		}
	}

}

void ALyraUIPlayerController::UpdateForceFeedback(IInputInterface* InputInterface, const int32 ControllerId)
{
	if (bForceFeedbackEnabled)
	{
		if (const UCommonInputSubsystem* CommonInputSubsystem = UCommonInputSubsystem::Get(GetLocalPlayer()))
		{
			const ECommonInputType CurrentInputType = CommonInputSubsystem->GetCurrentInputType();
			if (LyraUI::Input::ShouldAlwaysPlayForceFeedback || CurrentInputType == ECommonInputType::Gamepad || CurrentInputType == ECommonInputType::Touch)
			{
				InputInterface->SetForceFeedbackChannelValues(ControllerId, ForceFeedbackValues);
				return;
			}
		}
	}

	InputInterface->SetForceFeedbackChannelValues(ControllerId, FForceFeedbackValues());
}