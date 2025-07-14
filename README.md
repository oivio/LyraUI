# LyraUI-Plugin

LyraUI-Plugin is a converstion of advanced Lyra UI Main Menu in to seperate Plugin. 
The goal was to make reusable with almost any project besides Lyra and also easly updatable from future Lyra Sample versions.
Lyra UI is advance system that do requie some C++ and also blueprint skills.  


> Installation Instruction:

1. It is needed to copy Plugins can be just copied from original Lyra Sample or from my small demo https://github.com/oivio/LyraUI-Demo :
- AsyncMixin
- CommonGame
- CommonLoadingScreen
- CommonUser
- GameplayMessageRouter
- GameSettings
- GameSubtitles
- ModularGameplayActors
- UIExtension

2. Into project Config folder vopy folders from LyraUI/Config including files like DefaultScalability.ini and DefaultDeviceProfiles.ini the rest is optional 

3. It is requied to update ini files manuly or from Project Settings

Instruction from project settings:

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
 
Instruction from ini files:

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

[/Script/InputEditor.EnhancedInputEditorProjectSettings]
DefaultEditorInputClass=/Script/LyraUI.LyraPlayerInput
```

This is just work in progess instructions.
