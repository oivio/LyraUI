// Copyright Epic Games, Inc. All Rights Reserved.
#include "Player/LyraLocalPlayer.h"
#include "Settings/LyraSettingsLocal.h"
#include "Settings/LyraSettingsShared.h"

#include "CommonUserSubsystem.h"
#include "GameFramework/PlayerController.h"
#include "AudioMixerBlueprintLibrary.h"
#include "Engine/World.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(LyraLocalPlayer)

class UObject;

ULyraLocalPlayer::ULyraLocalPlayer()
{
}

void ULyraLocalPlayer::PostInitProperties()
{
	Super::PostInitProperties();

	if (ULyraSettingsLocal* LocalSettings = GetLocalSettings())
	{
		LocalSettings->OnAudioOutputDeviceChanged.AddUObject(this, &ULyraLocalPlayer::OnAudioOutputDeviceChanged);
	}
}

void ULyraLocalPlayer::SwitchController(class APlayerController* PC)
{
	Super::SwitchController(PC);

	OnPlayerControllerChanged(PlayerController);
}

bool ULyraLocalPlayer::SpawnPlayActor(const FString& URL, FString& OutError, UWorld* InWorld)
{
	const bool bResult = Super::SpawnPlayActor(URL, OutError, InWorld);

	OnPlayerControllerChanged(PlayerController);

	return bResult;
}

void ULyraLocalPlayer::InitOnlineSession()
{
	OnPlayerControllerChanged(PlayerController);

	Super::InitOnlineSession();
}

void ULyraLocalPlayer::OnPlayerControllerChanged(APlayerController* NewController)
{
	// Stop listening for changes from the old controller
}

ULyraSettingsLocal* ULyraLocalPlayer::GetLocalSettings() const
{
	return ULyraSettingsLocal::Get();
}

ULyraSettingsShared* ULyraLocalPlayer::GetSharedSettings() const
{
	if (!SharedSettings)
	{
		// On PC it's okay to use the sync load because it only checks the disk
		// This could use a platform tag to check for proper save support instead
		bool bCanLoadBeforeLogin = PLATFORM_DESKTOP;

		if (bCanLoadBeforeLogin)
		{
			SharedSettings = ULyraSettingsShared::LoadOrCreateSettings(this);
		}
		else
		{
			// We need to wait for user login to get the real settings so return temp ones
			SharedSettings = ULyraSettingsShared::CreateTemporarySettings(this);
		}
	}

	return SharedSettings;
}

void ULyraLocalPlayer::LoadSharedSettingsFromDisk(bool bForceLoad)
{
	FUniqueNetIdRepl CurrentNetId = GetCachedUniqueNetId();
	if (!bForceLoad && SharedSettings && CurrentNetId == NetIdForSharedSettings)
	{
		// Already loaded once, don't reload
		return;
	}

	ensure(ULyraSettingsShared::AsyncLoadOrCreateSettings(this, ULyraSettingsShared::FOnSettingsLoadedEvent::CreateUObject(this, &ULyraLocalPlayer::OnSharedSettingsLoaded)));
}

void ULyraLocalPlayer::OnSharedSettingsLoaded(ULyraSettingsShared* LoadedOrCreatedSettings)
{
	// The settings are applied before it gets here
	if (ensure(LoadedOrCreatedSettings))
	{
		// This will replace the temporary or previously loaded object which will GC out normally
		SharedSettings = LoadedOrCreatedSettings;

		NetIdForSharedSettings = GetCachedUniqueNetId();
	}
}

void ULyraLocalPlayer::OnAudioOutputDeviceChanged(const FString& InAudioOutputDeviceId)
{
	FOnCompletedDeviceSwap DevicesSwappedCallback;
	DevicesSwappedCallback.BindUFunction(this, FName("OnCompletedAudioDeviceSwap"));
	UAudioMixerBlueprintLibrary::SwapAudioOutputDevice(GetWorld(), InAudioOutputDeviceId, DevicesSwappedCallback);
}

void ULyraLocalPlayer::OnCompletedAudioDeviceSwap(const FSwapAudioOutputResult& SwapResult)
{
	if (SwapResult.Result == ESwapAudioOutputDeviceResultState::Failure)
	{
	}
}