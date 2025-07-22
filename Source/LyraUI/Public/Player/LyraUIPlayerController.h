// Copyright Epic Games, Inc. All Rights Reserved.
#pragma once

#include "CommonPlayerController.h"

#include "LyraUIPlayerController.generated.h"

#define UE_API LYRAUI_API

class ALyraHUD;
class APawn;
class IInputInterface;
class ULyraSettingsShared;
class UInputMappingContext;
class UObject;
class UPlayer;

// STRUCT taken from Lyra.Game GameFeatures GameFeatureAction_AddInputContextMapping
USTRUCT(BlueprintType)
struct FInputMappingContextAndPriority
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Input", meta = (AssetBundles = "Client,Server"))
	TSoftObjectPtr<UInputMappingContext> InputMapping;

	// Higher priority input mappings will be prioritized over mappings with a lower priority.
	UPROPERTY(EditAnywhere, Category = "Input")
	int32 Priority = 0;

	/** If true, then this mapping context will be registered with the settings when this game feature action is registered. */
	UPROPERTY(EditAnywhere, Category = "Input")
	bool bRegisterWithSettings = true;
};

/**
 *	ALyraUIPlayerController
 *	The base player controller class used by this project.
 */
UCLASS(MinimalAPI, Config = Game, Meta = (ShortTooltip = "The base LyraUI player controller class used by this project."))
class ALyraUIPlayerController : public ACommonPlayerController
{
	GENERATED_BODY()

public:

	UE_API ALyraUIPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	UFUNCTION(BlueprintCallable, Category = "LyraUI|PlayerController")
	UE_API ALyraHUD* GetLyraHUD() const;

	//~AActor interface
	UE_API virtual void BeginPlay() override;
	UE_API virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	//~End of AActor interface

	//~AController interface
	UE_API virtual void OnPossess(APawn* InPawn) override;
	UE_API virtual void OnUnPossess() override;
	//~End of AController interface

	//~APlayerController interface
	UE_API virtual void SetPlayer(UPlayer* InPlayer) override;
	UE_API virtual void UpdateForceFeedback(IInputInterface* InputInterface, const int32 ControllerId) override;
	//~End of APlayerController interface

protected:

	UE_API void OnSettingsChanged(ULyraSettingsShared* Settings);

	UE_API void AddInputConfig();

	/** Input Mapping Contexts */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	TArray<FInputMappingContextAndPriority> DefaultInputMappings;

};

#undef UE_API
