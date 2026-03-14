# LyraUI-Plugin

Lyra UI Plugin is a conversion of advanced Lyra Interface into a separate Plugin. The goal was to make it reusable with almost any project besides Lyra, while also making it easy to update from future Lyra Sample versions. 
Lyra UI is an advance system that requires some C++ and Blueprint skills. 


## ✨ Installation Introduction 

1. Copy the following plugins from the Lyra Sample Project or from my small demo: https://github.com/oivio/LyraUI-Demo :
```	
- AsyncMixin
- CommonGame
- CommonLoadingScreen
- CommonUser
- GameplayMessageRouter
- GameSettings
- GameSubtitles
- ModularGameplayActors
- UIExtension
```	

2. Inside the **LyraUI/Config/ExtrasToCopy** folder, you will find configuration files that must be placed inside your project's **Config** folder.
```	
If files with the same names already exist in your project, do not overwrite them. Instead, copy only the required configuration entries from these files and paste them into your existing configuration files.
```	
3. It is required to update INI files manually or from Project Settings.

Project settings to change or update :

```	
  - [Project / Maps & Modes] -> Game Instance Class = LyraGameInstance
  
  - [Game / Common Input Settings] -> Input Data = B_CommonInputData
  - [Game / Common Loading Screen] -> W_LoadingScreen_Host
  
  - [Game / Lyra Audio Settings] -> Default Control Bus Mix = CBM_BaseMix
  - [Game / Lyra Audio Settings] -> Loading Screen Control Bus Mix = CBM_LoadingScreenMix
  - [Game / Lyra Audio Settings] -> User Settings Control Bus Mix = CBM_UserMix
  - [Game / Lyra Audio Settings] -> Overall Volume Control Bus = CB_Main
  - [Game / Lyra Audio Settings] -> Music Volume Control Bus = CB_Music
  - [Game / Lyra Audio Settings] -> Sound FXVolume Control Bus = CB_SFX
  - [Game / Lyra Audio Settings] -> Dialogue Volume Control Bus = CB_Dialogue
  - [Game / Lyra Audio Settings] -> Voice Chat Volume Control Bus = CB_VoiceChat
  - [Game / Lyra Audio Settings] -> HDRAudioSubmixEffectChain = MusicSubmix
  - [Game / Lyra Audio Settings] -> HDRAudioSubmixEffectChain -> MusicSubmix -> SubmixEffectChain = DYN_MainDynamics
  - [Game / Lyra Audio Settings] -> LDRAudioSubmixEffectChain = MainSubmix
  - [Game / Lyra Audio Settings] -> LDRAudioSubmixEffectChain -> MainSubmix -> SubmixEffectChain = DYN_LowMultibandDynamics
  - [Game / Lyra Audio Settings] -> LDRAudioSubmixEffectChain -> MainSubmix -> SubmixEffectChain = DYN_LowDynamics
  
  - [Game / Lyra UI Manager] -> Default UI Policy Class = B_LyraUIPolicy
  
  - [Game / Lyra UI Messaging] -> Confirmation Dialog Class -> W_ConfirmationDefault
  - [Game / Lyra UI Messaging] -> Error Dialog Class -> W_ConfirmationError
  
  - [Engine / General Settings] -> Game Viewport Client Class = LyraGameViewportClient
  - [Engine / General Settings] -> Local Player Class = LyraLocalPlayer
  - [Engine / General Settings] -> Advanced -> Game User Settings Class = LyraSettingsLocal
  
  - [Engine / Enhanced Input] -> User Settings -> Enable User Settings = "Checked"
  - [Engine / Enhanced Input] -> User Settings Class = LyraInputUserSettings
  - [Engine / Enhanced Input] -> Default Player Mappable Key Profile Class = LyraPlayerMappableKeyProfile
  
  - [Engine / General Settings] -> Default Player Input Class = LyraGameViewportClient
  - [Engine / General Settings] -> Default Input Component Class = LyraLocalPlayer
  
  - [Plugins / Common UI Editor] -> Template Text Style = TextStyle-Regular
  - [Plugins / Common UI Editor] -> Template Button Style = ButtonStyle-Primary-M
  
  - [Plugins / Common UI Framework] -> Default Throbber Material = M_UI_Throbber_Base
  - [Plugins / Common UI Framework] -> Default Rich Text Data Class = CommonUIRichTextData
```	
 
Updating INI files:

Open DefaultEngine.ini and edit or add:
```
[/Script/EngineSettings.GameMapsSettings]
GameInstanceClass=/Script/LyraUINavigation.LyraUINavGameInstance

[/Script/Engine.Engine]
LocalPlayerClassName=/Script/LyraUI.LyraLocalPlayer
GameViewportClientClassName=/Script/LyraUI.LyraGameViewportClient
GameUserSettingsClassName=/Script/LyraUI.LyraSettingsLocal
```	
	
Open DefaultEditor.ini and edit or add:
```	
[/Script/CommonUI.CommonUIEditorSettings]
TemplateTextStyle=/LyraUI/UI/Foundation/Text/TextStyle-Regular.TextStyle-Regular_C
TemplateButtonStyle=/LyraUI/UI/Foundation/Buttons/ButtonStyle-Primary-M.ButtonStyle-Primary-M_C
```

Open DefaultGame.ini and edit or add:
```	
[/Script/LyraUI.LyraAudioSettings]
DefaultControlBusMix=/LyraUI/Audio/Modulation/ControlBusMixes/CBM_BaseMix.CBM_BaseMix
LoadingScreenControlBusMix=/LyraUI/Audio/Modulation/ControlBusMixes/CBM_LoadingScreenMix.CBM_LoadingScreenMix
UserSettingsControlBusMix=/LyraUI/Audio/Modulation/ControlBusMixes/CBM_UserMix.CBM_UserMix
OverallVolumeControlBus=/LyraUI/Audio/Modulation/ControlBuses/CB_Main.CB_Main
MusicVolumeControlBus=/LyraUI/Audio/Modulation/ControlBuses/CB_Music.CB_Music
SoundFXVolumeControlBus=/LyraUI/Audio/Modulation/ControlBuses/CB_SFX.CB_SFX
DialogueVolumeControlBus=/LyraUI/Audio/Modulation/ControlBuses/CB_Dialogue.CB_Dialogue
VoiceChatVolumeControlBus=/LyraUI/Audio/Modulation/ControlBuses/CB_VoiceChat.CB_VoiceChat
+HDRAudioSubmixEffectChain=(Submix="/LyraUI/Audio/Submixes/MusicSubmix.MusicSubmix",SubmixEffectChain=("/LyraUI/Audio/Effects/SubmixEffects/DYN_MainDynamics.DYN_MainDynamics"))
+LDRAudioSubmixEffectChain=(Submix="/LyraUI/Audio/Submixes/MainSubmix.MainSubmix",SubmixEffectChain=("/LyraUI/Audio/DYN_LowMultibandDynamics.DYN_LowMultibandDynamics","/LyraUI/Audio/Effects/SubmixEffects/DYN_LowDynamics.DYN_LowDynamics"))

[/Script/CommonUI.CommonUISettings]
CommonButtonAcceptKeyHandling=Ignore
DefaultRichTextDataClass=/LyraUI/UI/Foundation/RichTextData/CommonUIRichTextData.CommonUIRichTextData_C
DefaultThrobberMaterial=/LyraUI/UI/Foundation/Materials/M_UI_Throbber_Base.M_UI_Throbber_Base

[/Script/CommonInput.CommonInputSettings]
InputData=/LyraUI/UI/B_CommonInputData.B_CommonInputData_C

[/Script/CommonLoadingScreen.CommonLoadingScreenSettings]
LoadingScreenWidget=/LyraUI/UI/Foundation/LoadingScreen/W_LoadingScreen_Host.W_LoadingScreen_Host_C

[/Script/LyraUI.LyraUIMessaging]
ConfirmationDialogClass=/LyraUI/UI/Foundation/Dialogs/W_ConfirmationDialog.W_ConfirmationDialog_C
ErrorDialogClass=/LyraUI/UI/Foundation/Dialogs/W_ConfirmationError.W_ConfirmationError_C

[/Script/LyraUI.LyraUIManagerSubsystem]
DefaultUIPolicyClass=/LyraUI/UI/B_LyraUIPolicy.B_LyraUIPolicy_C
```

Open DefaultInput.ini and edit or add:
```	
[/Script/Engine.InputSettings]
DefaultPlayerInputClass=/Script/LyraUI.LyraPlayerInput
DefaultInputComponentClass=/Script/LyraUI.LyraInputComponent

[/Script/CommonUI.CommonUIInputSettings]
+InputActions=(ActionTag=UI.Action.Escape,DefaultDisplayName=NSLOCTEXT("[/Script/CommonUI]", "DDDC55F044A6D009AE3FC89634A4FBE3", "Back"),KeyMappings=((Key=Escape),(Key=Gamepad_Special_Right)))
AnalogCursorSettings=(PreprocessorPriority=2,PreprocessorRegistrationInfo=(Type=Game,Priority=2),bEnableCursorAcceleration=True,CursorAcceleration=1500.000000,CursorMaxSpeed=2200.000000,CursorDeadZone=0.250000,HoverSlowdownFactor=0.400000,ScrollDeadZone=0.200000,ScrollUpdatePeriod=0.100000,ScrollMultiplier=2.500000)

[/Script/EnhancedInput.EnhancedInputDeveloperSettings]
bEnableUserSettings=True
UserSettingsClass=/Script/LyraUI.LyraInputUserSettings
DefaultPlayerMappableKeyProfileClass=/Script/LyraUI.LyraPlayerMappableKeyProfile
```

## 🔒 License
* Licensed for Use Only with Unreal Engine-based Products
* The majority of this project is released under the MIT license as found in the [LICENSE](https://github.com/oivio/LyraUI/blob/main/LICENSE) file.

## ⭐ Acknowledgements
- 🎬 [NanceDevDiaries](https://www.youtube.com/@nancedevdiaries) 
- 🧠 [Xist](https://x157.github.io) 
