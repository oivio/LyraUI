#include "GameModes/LyraUIGameMode.h"
#include "UI/Subsystem/LyraUIManagerSubsystem.h"

#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "CommonUIExtensions.h"

void ALyraUIGameMode::BeginPlay()
{
    Super::BeginPlay();

    if (ULocalPlayer* LocalPlayer = UGameplayStatics::GetPlayerController(this, 0)->GetLocalPlayer())
    {

        for (const FContentToLayerWidgetEntry& Entry : Layouts)
        {
            UCommonUIExtensions::PushContentToLayer_ForPlayer(LocalPlayer, Entry.LayerID, Entry.WidgetClass);
        }
    }

    if (UUIExtensionSubsystem* UISubsystem = GetWorld()->GetSubsystem<UUIExtensionSubsystem>())
    {
        WidgetsHandles.Empty();

        for (const FRegisterExtensionAsWidgetEntry& Entry : Widgets)
        {
            FUIExtensionHandle Handle = UISubsystem->RegisterExtensionAsWidget(Entry.SlotID, Entry.WidgetClass, Entry.Priority);

            if (Handle.IsValid())
                WidgetsHandles.Add(Handle);

        }
    }

}

void ALyraUIGameMode::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    if (UUIExtensionSubsystem* UISubsystem = GetWorld()->GetSubsystem<UUIExtensionSubsystem>())
    {
        for (const FUIExtensionHandle& Handle : WidgetsHandles)
        {
            UISubsystem->UnregisterExtension(Handle);
        }
    }

    WidgetsHandles.Empty();

    Super::EndPlay(EndPlayReason);
}