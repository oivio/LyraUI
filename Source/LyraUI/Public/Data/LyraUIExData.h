// Copyright Epic Games, Inc. All Rights Reserved.
#pragma once

#include "Engine/DataAsset.h"

#include "UIExtensionSystem.h"
#include "GameplayTagContainer.h"
#include "Blueprint/UserWidget.h"

#include "LyraUIExData.generated.h"

#define UE_API LYRAUI_API

class UObject;

USTRUCT(BlueprintType)
struct FRegisterExtensionAsWidgetEntry
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Extensions)
	FGameplayTag ExtensionPointTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Extensions)
	TSubclassOf<UUserWidget> WidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Extensions)
	int32 Priority = -1;

};

USTRUCT(BlueprintType)
struct FRegisterExtensionAsWidgetForContextEntry
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Extensions)
	FGameplayTag ExtensionPointTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Extensions)
	UObject* ContextObject = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Extensions)
	TSubclassOf<UUserWidget> WidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Extensions)
	int32 Priority = -1;

};

USTRUCT(BlueprintType)
struct FRegisterExtensionPointEntry
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Extensions)
	FGameplayTag ExtensionPointTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Extensions)
	EUIExtensionPointMatch ExtensionPointTagMatchType = EUIExtensionPointMatch::ExactMatch;;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Extensions)
	TArray<TSubclassOf<UObject>> AllowedDataClasses;

	FExtendExtensionPointDelegate ExtensionCallback;

};

USTRUCT(BlueprintType)
struct FRegisterExtensionPointContextEntry
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Extensions)
	FGameplayTag ExtensionPointTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Extensions)
	UObject* ContextObject = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Extensions)
	EUIExtensionPointMatch ExtensionPointTagMatchType = EUIExtensionPointMatch::ExactMatch;;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Extensions)
	TArray<TSubclassOf<UObject>> AllowedDataClasses;

	FExtendExtensionPointDelegate ExtensionCallback;

};

USTRUCT(BlueprintType)
struct FRegisterExtensionAsDataEntry
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Extensions)
	FGameplayTag ExtensionPointTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Extensions)
	UObject* ContextObject = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Extensions)
	UObject* Data = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Extensions)
	int32 Priority = -1;

};

UCLASS(MinimalAPI, BlueprintType)
class ULyraUIExData : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI Extension")
	TArray<FRegisterExtensionAsWidgetEntry> WidgetEntries;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI Extension")
	TArray<FRegisterExtensionAsWidgetForContextEntry> WidgetForContexEntries;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI Extension")
	TArray<FRegisterExtensionPointEntry> PointEntries;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI Extension")
	TArray<FRegisterExtensionPointContextEntry> PointContextEntries;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI Extension")
	TArray<FRegisterExtensionAsDataEntry> DataExtensions;

};

#undef UE_API
