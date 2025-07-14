// Copyright Epic Games, Inc. All Rights Reserved.

#include "UI/LyraHUD.h"

#include "Async/TaskGraphInterfaces.h"
#include "UObject/UObjectIterator.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(LyraHUD)

class AActor;
class UWorld;

//////////////////////////////////////////////////////////////////////
// ALyraHUD

ALyraHUD::ALyraHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryActorTick.bStartWithTickEnabled = false;
}

void ALyraHUD::PreInitializeComponents()
{
	Super::PreInitializeComponents();

}

void ALyraHUD::BeginPlay()
{

	Super::BeginPlay();
}

void ALyraHUD::EndPlay(const EEndPlayReason::Type EndPlayReason)
{

	Super::EndPlay(EndPlayReason);
}

void ALyraHUD::GetDebugActorList(TArray<AActor*>& InOutList)
{
	UWorld* World = GetWorld();

	Super::GetDebugActorList(InOutList);

}

