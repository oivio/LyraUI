// Fill out your copyright notice in the Description page of Project Settings.

#include "LyraUIEditor.h"

#include "UI/Subsystem/LyraUIManagerSubsystem.h"
#include "UI/Subsystem/LyraUIMessaging.h"
#include "ISettingsModule.h"
#include "ISettingsSection.h"
#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "FLyraUIEditorModule"

void FLyraUIEditorModule::StartupModule()
{

    if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
    {
        ISettingsSectionPtr SettingsMessaging = SettingsModule->RegisterSettings("Project", "Game", "Lyra UI Messaging",
            LOCTEXT("LyraUIMessaging", "Lyra UI Messaging"),
            LOCTEXT("LyraUIMessagingDesc", "Settings for Lyra Messaging System"),
            GetMutableDefault<ULyraUIMessaging>());
        if (SettingsMessaging.IsValid())
            GetMutableDefault<ULyraUIMessaging>()->SaveConfig();

        ISettingsSectionPtr SettingsManager = SettingsModule->RegisterSettings("Project", "Game", "Lyra UI Manager",
            LOCTEXT("LyraUIManager", "Lyra UI Manager"),
            LOCTEXT("LyraUIManagerDesc", "Settings for Lyra UI Manager"),
            GetMutableDefault<ULyraUIManagerSubsystem>());
        if (SettingsManager.IsValid())
            GetMutableDefault<ULyraUIManagerSubsystem>()->SaveConfig();
    }
}

void FLyraUIEditorModule::ShutdownModule()
{
    if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
    {
        SettingsModule->UnregisterSettings("Project", "Plugins", "Lyra UI Messaging");
        SettingsModule->UnregisterSettings("Project", "Plugins", "Lyra UI Manager");
    }
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FLyraUIEditorModule, LyraUIEditor)