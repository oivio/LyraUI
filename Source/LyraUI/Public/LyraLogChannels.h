// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Logging/LogMacros.h"

class UObject;

LYRAUI_API DECLARE_LOG_CATEGORY_EXTERN(LogLyra, Log, All);
LYRAUI_API DECLARE_LOG_CATEGORY_EXTERN(LogLyraExperience, Log, All);
LYRAUI_API DECLARE_LOG_CATEGORY_EXTERN(LogLyraAbilitySystem, Log, All);
LYRAUI_API DECLARE_LOG_CATEGORY_EXTERN(LogLyraTeams, Log, All);

LYRAUI_API FString GetClientServerContextString(UObject* ContextObject = nullptr);
