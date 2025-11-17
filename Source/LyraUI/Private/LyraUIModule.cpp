// Copyright Epic Games, Inc. All Rights Reserved.

#include "LyraUIModule.h"

#include "GameplayTagsManager.h"
#include "Misc/Paths.h"
#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "FLyraUIModule"

void FLyraUIModule::StartupModule()
{
	UGameplayTagsManager::Get().AddTagIniSearchPath(FPaths::ProjectPluginsDir() / TEXT("LyraUI/Config/Tags"));
}

void FLyraUIModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FLyraUIModule, LyraUI)