// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameplayTagContainer.h"

#include "LyraUIGameMode.generated.h"

#define UE_API LYRAUI_API

class UObject;
class UCommonActivatableWidget;

UCLASS(MinimalAPI, Config = Game)
class ALyraUIGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:

    UE_API virtual void BeginPlay() override;

    UE_API virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI")
    TArray<FContentToLayerWidgetEntry> Layouts;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI")
    TArray<FRegisterExtensionAsWidgetEntry> Widgets;

private:

    TArray<FUIExtensionHandle> WidgetsHandles;
	
};

#undef UE_API
