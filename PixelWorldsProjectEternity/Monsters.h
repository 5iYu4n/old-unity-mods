#ifndef OFFSETS_H
#define OFFSETS_H

struct PixelWorlds
{
    uintptr_t Component_get_transform = 0x12CCCAC;
    uintptr_t Component_get_gameObject = 0x12CCCFC;
    uintptr_t Object_get_name = 0x140CFF0;

    uintptr_t Transform_GetChild = 0x14277D8;
    uintptr_t Transform_get_childCount = 0x1427304;
    uintptr_t Transform_get_position = 0x14253D4;
    uintptr_t Transform_set_position = 0x14254AC;

    uintptr_t BSONObject_get_Item = 0x220C25C;
    uintptr_t BSONValue_get_stringValue = 0x220CA18;

    uintptr_t Application_set_targetFrameRate = 0x12C5D34;

    uintptr_t TMP_Text_SetText = 0x8DEE88;

    uintptr_t Screen_get_height = 0x141E350;
    uintptr_t Screen_get_width = 0x141E308;

    uintptr_t AdminToolsTeleportOverlayUI_ActivateDummy = 0x87C14C;
    uintptr_t AdminToolsTeleportOverlayUI_Update = 0x87C788;

    uintptr_t AIBase_OnDeath = 0x1FD1234;
    uintptr_t AIBase_GetCurrentAIBehaviorType = 0x1FD09DC;
    uintptr_t AIBase_IsAlive = 0x1FD0FE0;
    //Field
    uintptr_t AIBase_enemyType = 0x8;
    uintptr_t AIBase_mapPointX = 0x34;
    uintptr_t AIBase_mapPointY = 0x38;
    uintptr_t AIBase_id = 0xC;
    uintptr_t AIBase_health = 0x50;

    uintptr_t AIEnemyMonoBehaviourBase_GetIsActive = 0x1FE1368;
    uintptr_t AIEnemyMonoBehaviourBase_Update = 0x1FDF1B0;
    //Field
    uintptr_t AIEnemyMonoBehaviourBase_aiBase = 0xBC;

    uintptr_t BaseMenuUI_Update = 0x1F04B70;

    uintptr_t ChatUI_Update = 0x1EC4658;
    uintptr_t ChatUI_WarpToWorld = 0x1EC8724;

    //Field
    uintptr_t CollectableData_mapPoint = 0x20;
    uintptr_t CollectableData_blockType = 0xC;
    uintptr_t CollectableData_amount = 0x28;
    uintptr_t CollectableData_posX = 0x18;
    uintptr_t CollectableData_posY = 0x1C;

    uintptr_t ConfigData_IsBlockFamiliar = 0x1E6E970;
    uintptr_t ConfigData_IsBlockPortal = 0x1E7BCB8;
    uintptr_t ConfigData_DoesBlockHaveCollider = 0x1E6C260;
    uintptr_t ConfigData_GetBlockSortingLayerType = 0x1E6A200;
    uintptr_t ConfigData_IsBlockInstakill = 0x1E6C6BC;
    uintptr_t ConfigData_IsBlockFishingWater = 0x1E7BC54;
    uintptr_t ConfigData_IsFishingLure = 0x1E67984;
    uintptr_t ConfigData_IsBlockWater = 0x1E798CC;
    uintptr_t ConfigData_IsMiningNugget = 0x1E69D84;
    uintptr_t ConfigData_IsFish = 0x1E69CC8;
    uintptr_t ConfigData_GetFishRecycleValueForFishRecycler = 0x1E8B440;
    uintptr_t ConfigData_IsBlockMiningGemstone = 0x1E69D54;
    uintptr_t ConfigData_GetGemstoneRecycleValueForMiningGemstoneRecycler = 0x1E8C128;
    uintptr_t ConfigData_IsConsumableTreasurePouch = 0x1E85678;
    uintptr_t ConfigData_GetTreasurePouchRewardAmount = 0x1E85620;
    uintptr_t ConfigData_IsBlockButterflyEventItem = 0x1E7C8A8;
    uintptr_t ConfigData_GetMaxHitPoints = 0x1FD06E8; //IEnemyConfigData
    uintptr_t ConfigData_GetBlockTypeInventoryItemType = 0x1E6782C;
    uintptr_t ConfigData_CanPlaceSeedTopOf = 0x1E85BB0;
    uintptr_t ConfigData_GetBlockRunSpeed = 0x1E6FBD8;
    uintptr_t ConfigData_IsBlockHot = 0x1E71218;
    uintptr_t ConfigData_IsBlockSpring = 0x1E70FF8;
    uintptr_t ConfigData_IsBlockDeflector = 0x1E81EF0;
    uintptr_t ConfigData_GetDeflectorRange = 0x1E81FF0;
    uintptr_t ConfigData_GetDeflectorForce = 0x1E81F14;
    uintptr_t ConfigData_GetDeflectorForceGrounded = 0x1E81F48;
    uintptr_t ConfigData_IsBlockElastic = 0x1E78214;
    uintptr_t ConfigData_IsBlockElevator = 0x1E8207C;
    uintptr_t ConfigData_IsBlockPinball = 0x1E7143C;
    uintptr_t ConfigData_IsBlockTrampolin = 0x1E70DD4;
    uintptr_t ConfigData_IsBlockWind = 0x1E763B4;

    uintptr_t EventDates_GetMiniEventNextStartTime = 0x1F38AB0;
    uintptr_t EventDates_GetEventStartDateTime = 0x1F34758;
    uintptr_t EventDates_GetEventStartDateTimeExtra = 0x1F34F84;

    uintptr_t FishingGaugeMinigameUI_LandButtonPressed = 0x22FA43C;
    uintptr_t FishingGaugeMinigameUI_Update = 0x22F98F0;
    //Field
    uintptr_t FishingGaugeMinigameUI_progress = 0xAC;
    uintptr_t FishingGaugeMinigameUI_fishPosition = 0xE0;
    uintptr_t FishingGaugeMinigameUI_targetAreaPosition = 0x144;
    uintptr_t FishingGaugeMinigameUI_currentFishSetting = 0xBC;

    uintptr_t FishingResultsPopupUI_HardwareBackButtonPressed = 0x1EA5DCC;

    uintptr_t GameplayUI_OnButtonDownNew = 0x1F63ED4;
    uintptr_t GameplayUI_SettingsButtonClicked = 0x1F61A1C;
    uintptr_t GameplayUI_Update = 0x1F4DB08;
    //Field
    uintptr_t GameplayUI_zoomSlider = 0x1B8;

    uintptr_t InventoryControl_GetCurrentSelection = 0x1D3A740;
    uintptr_t InventoryControl_Update = 0x1D49A08;

    //Field
    uintptr_t InventoryItemBase_blockType = 0x8;

    uintptr_t ItemPacks_GetItemPacksList = 0x22A3944;

    uintptr_t KukouriTime_Get = 0x220ADE4;

    uintptr_t MainMenuLogic_JoinRandomWorldFromMainMenu = 0x21EE920;
    uintptr_t MainMenuLogic_LogOut = 0x21E5FA0;
    uintptr_t MainMenuLogic_Update = 0x21E6238;
    //Field
    uintptr_t MainMenuLogic_mainMenuShopLogic = 0xD8;

    uintptr_t MainMenuShopLogic_IsInMainMenu = 0x1EE2FE4;

    uintptr_t MineWorldNotificationUI_Update = 0x7C0228;
    //Field
    uintptr_t MineWorldNotificationUI_timeLeftInSeconds = 0x30;

    uintptr_t NetherWorldNotificationUI_Update = 0x1A97ED0;
    //Field
    uintptr_t NetherWorldNotificationUI_timeLeftInSeconds = 0x40;

    uintptr_t OptionsMenuUI_Update = 0x20C8A18;
    uintptr_t OptionsMenuUI_ExitWorld = 0x20CBF58;

    uintptr_t OutgoingMessages_SendHitBlockBackgroundMessage = 0x704918;
    uintptr_t OutgoingMessages_SendHitBlockWaterMessage = 0x7046D0;
    uintptr_t OutgoingMessages_SendSetBlockMessage = 0x705A68;
    uintptr_t OutgoingMessages_SendSetBlockBackgroundMessage = 0x705924;
    uintptr_t OutgoingMessages_SendSetBlockWaterMessage = 0x706AAC;
    uintptr_t OutgoingMessages_ConvertItems = 0x719408;
    uintptr_t OutgoingMessages_BuyItemPack = 0x716BD8;
    uintptr_t OutgoingMessages_SendHitAirMessage = 0x704A1C;
    uintptr_t OutgoingMessages_SendHitSpiritMessage = 0x704B20;
    uintptr_t OutgoingMessages_SendSpinMiningRouletteMessage = 0x71A7B0;
    uintptr_t OutgoingMessages_SendSpinJetRaceRouletteMessage = 0x71A978;
    uintptr_t OutgoingMessages_SendUsePotionMessage = 0x703F90;
    uintptr_t OutgoingMessages_SendCollectCollectableMessage = 0x706D34;
    uintptr_t OutgoingMessages_MiningPickaxeRepairing = 0x71A340;
    uintptr_t OutgoingMessages_SendRequestGeneratedMineExitMessage = 0x718470;
    uintptr_t OutgoingMessages_SendRequestItemFromGiftBoxMessage = 0x711460;
    uintptr_t OutgoingMessages_SendHitBlockMessage = 0x7047D4;
    uintptr_t OutgoingMessages_SendHitAIEnemyMessage = 0x705468;

    uintptr_t PixelPerfectCamera_LateUpdate = 0x1BE0E44;
    //Field
    uintptr_t PixelPerfectCamera_cameraZoom = 0x18;
    uintptr_t PixelPerfectCamera_cameraOrigin = 0x34;

    uintptr_t Player_GoFromPortalAnotherWorldHelper = 0x1C27D94;
    uintptr_t Player_ChangeFamiliarRemote = 0x1C3D9F8;
    uintptr_t Player_GoFromPortal = 0x1C229E4;
    uintptr_t Player_IsFishStrikeActive = 0x1C2C8E8;
    uintptr_t Player_ChangeWearableRemote = 0x1C3C158;
    uintptr_t Player_IsPlayerInMapPoint = 0x1C165A0;
    uintptr_t Player_CheckPortals = 0x1C1036C;
    uintptr_t Player_CheckCheckPoints = 0x1C113B0;
    uintptr_t Player_CheckInvertedControls = 0x1BFB93C;
    uintptr_t Player_SetVelocity = 0x1BE39D4;
    uintptr_t Player_CausePoisoned0 = 0x1C24DEC;
    uintptr_t Player_CausePoisoned1 = 0x1C26680;
    uintptr_t Player_CausePoisoned2 = 0x1C264AC;
    uintptr_t Player_HitPlayerFromAIEnemy0 = 0x1C25C00;
    uintptr_t Player_HitPlayerFromAIEnemy1 = 0x1C25ECC;
    uintptr_t Player_HitPlayerFromBlock0 = 0x1C137C8;
    uintptr_t Player_HitPlayerFromBlock1 = 0x1C24F18;
    uintptr_t Player_Update = 0x1BF5160;
    //Field
    uintptr_t Player_isLocalPlayer = 0x34;
    uintptr_t Player_myTransform = 0x10;
    uintptr_t Player_currentPlayerMapPoint = 0x638;
    uintptr_t Player_jumpButtonDown = 0x5E0;
    uintptr_t Player_jumpButton = 0x5E1;
    uintptr_t Player_myPlayerData = 0x2C;
    uintptr_t Player_playerNameTextMeshPro = 0xD3C;
    uintptr_t Player_jumpMode = 0x54;
    uintptr_t Player_cooldownToUseFistMultiplier = 0x1170;
    uintptr_t Player_isDead = 0x36;
    uintptr_t Player_playerBoxColliderSize = 0x604;
    uintptr_t Player_fishingState = 0x5C8;
    uintptr_t Player_fishingLeftButton = 0x5D8;
    uintptr_t Player_fishingRightButton = 0x5D9;

    uintptr_t PlayerData_GetBeltItem = 0x20932E0;
    uintptr_t PlayerData_AddItemToInventory = 0x208FCA8;
    uintptr_t PlayerData_RemoveItemsFromInventory = 0x208C0A8;
    uintptr_t PlayerData_GetInventoryAsOrderedByInventoryItemType = 0x208BE7C;
    uintptr_t PlayerData_GetInventorySize = 0x208EBF0;
    uintptr_t PlayerData_GetInventoryData = 0x208D01C;
    uintptr_t PlayerData_GetCount = 0x208F1A0;
    uintptr_t PlayerData_HasUnlockedRecipe = 0x2091C1C;
    uintptr_t PlayerData_GetMaxHitPoints = 0x208C558;
    uintptr_t PlayerData_GetPlayerWearWerablesAndWeaponInventoryDatas = 0x2094F70;
    //Field
    uintptr_t PlayerData_health = 0x280;

    uintptr_t ProfanityFilter_Censor = 0x1FFB2C4;

    uintptr_t SceneLoader_ReloadGame = 0x2378E74;

    uintptr_t SpeechBubble_Update = 0x206AF60;
    uintptr_t SpeechBubble_player = 0x10;
    uintptr_t SpeechBubble_currentSpeechBubbleVisualLookType = 0x24;

    uintptr_t Spirit_GetCurrentMapPoint = 0x20710B8;
    //Field
    uintptr_t Spirit_myTransform = 0xC;

    uintptr_t TitleScreenLogic_Start = 0x1F8C608;
    uintptr_t TitleScreenLogic_Update = 0x1F8CE4C;
    uintptr_t TitleScreenLogic_tipsText = 0x18;

    uintptr_t TrapProjectile_OnTriggerEnter2D = 0x23E9BC8;

    uintptr_t WeaponPickaxeCrappyInventoryData_GetDurability = 0x1CBA0C0;
    uintptr_t WeaponPickaxeFlimsyInventoryData_GetDurability = 0x1CBADEC;
    uintptr_t WeaponPickaxeBasicInventoryData_GetDurability = 0x1CB9C5C;
    uintptr_t WeaponPickaxeSturdyInventoryData_GetDurability = 0x1CBBB18;
    uintptr_t WeaponPickaxeHeavyInventoryData_GetDurability = 0x1CBB250;
    uintptr_t WeaponPickaxeMasterInventoryData_GetDurability = 0x1CBB6B4;
    uintptr_t WeaponPickaxeEpicInventoryData_GetDurability = 0x1CBA988;
    uintptr_t WeaponPickaxeDarkInventoryData_GetDurability = 0x1CBA524;

    uintptr_t WearableHotSpotsValidity_GetWearableHotSpots = 0x1CC208C;

    uintptr_t WiringWireController_Update = 0x1C5BB30;

    uintptr_t World_DoesPlayerHaveRightToModifyItemData = 0x1C6CD30;
    uintptr_t World_GetBlockBackgroundType = 0x1C72E48;
    uintptr_t World_GetBlockWaterType = 0x1C73390;
    uintptr_t World_GetWorldItemData = 0x1C73620;
    uintptr_t World_GetBlockType = 0x1C66720;
    //Field
    uintptr_t World_worldSizeX = 0x78;
    uintptr_t World_worldSizeY = 0x7C;
    uintptr_t World_worldType = 0xA4;
    uintptr_t World_collectables = 0xE0;
    uintptr_t World_gravityMode = 0x168;
    uintptr_t World_worldBackground = 0x14;
    uintptr_t World_worldWeatherType = 0x18;
    uintptr_t World_worldLightingType = 0x1C;

    uintptr_t WorldController_DestroyBlockSpriteOrQuad = 0x1B74FFC;
    uintptr_t WorldController_DestroyBlockBackgroundSpriteOrQuad = 0x1B6B294;
    uintptr_t WorldController_DestroyBlockWaterSpriteOrQuad = 0x1B836AC;
    uintptr_t WorldController_InstantiateGiftBoxPrizeGameObject = 0x1BA4BB8;
    uintptr_t WorldController_SetBaitWithTool = 0x1BC6020;
    uintptr_t WorldController_BlockColliderAndLayerHelper = 0x1B6C954;
    uintptr_t WorldController_DropStuffFromInventory = 0x1BA1398;
    uintptr_t WorldController_KickPlayerByInactivity = 0x1B50C4C;
    uintptr_t WorldController_SetBlock = 0x1B51348;
    uintptr_t WorldController_SetBlockBackground = 0x1B50F58;
    uintptr_t WorldController_SetBlockWater = 0x1B536B4;
    uintptr_t WorldController_ChangeLighting = 0x1BCEA14;
    uintptr_t WorldController_InstantiateFogOfWar = 0x1BBF614;
    uintptr_t WorldController_LocalPlayerReadyToPlay = 0x1B5A2A0;
    uintptr_t WorldController_Update = 0x1B500E8;
    //Field
    uintptr_t WorldController_world = 0x1C;
    uintptr_t WorldController_spirit = 0x2FC;
    uintptr_t WorldController_fishBlockType = 0x464;

    //Field
    uintptr_t WorldItemBase_blockType = 0xC;
    uintptr_t WorldItemBase_isAnimationOn = 0x14;

    uintptr_t WorldNameChecker_Validate = 0x21613C8;


    //Data Item
        //Portal
    uintptr_t VortexPortalData_GetName = 0x1CAF620;
    uintptr_t VortexPortalData_GetIsLocked = 0x1CAF640;
    uintptr_t VortexPortalData_GetEntryPointID = 0x1CAF630;
    uintptr_t VortexPortalData_GetTargetWorldID = 0x1CAF600;
    uintptr_t VortexPortalData_GetTargetEntryPointID = 0x1CAF610;

    uintptr_t PortalData_GetName = 0x7321E0;
    uintptr_t PortalData_GetIsLocked = 0x732200;
    uintptr_t PortalData_GetEntryPointID = 0x7321F0;
    uintptr_t PortalData_GetTargetWorldID = 0x7321C0;
    uintptr_t PortalData_GetTargetEntryPointID = 0x7321D0;

    uintptr_t AnniversaryPortalData_GetName = 0x223D054;
    uintptr_t AnniversaryPortalData_GetIsLocked = 0x223D074;
    uintptr_t AnniversaryPortalData_GetEntryPointID = 0x223D064;
    uintptr_t AnniversaryPortalData_GetTargetWorldID = 0x223D044;
    uintptr_t AnniversaryPortalData_GetTargetEntryPointID = 0x223D034;

    uintptr_t PortalWOTWData_GetName = 0x73C4AC;
    uintptr_t PortalWOTWData_GetIsLocked = 0x73C4CC;
    uintptr_t PortalWOTWData_GetEntryPointID = 0x73C4BC;
    uintptr_t PortalWOTWData_GetTargetWorldID = 0x73C48C;
    uintptr_t PortalWOTWData_GetTargetEntryPointID = 0x73C49C;

    uintptr_t NetherGroupPortalData_GetName = 0x75CE84;
    uintptr_t NetherGroupPortalData_GetIsLocked = 0x75CEA4;
    uintptr_t NetherGroupPortalData_GetEntryPointID = 0x75CE94;
    uintptr_t NetherGroupPortalData_GetTargetWorldID = 0x75CE64;
    uintptr_t NetherGroupPortalData_GetTargetEntryPointID = 0x75CE74;

    uintptr_t LabEnterPortalData_GetName = 0x221AEF0;
    uintptr_t LabEnterPortalData_GetIsLocked = 0x221AF10;
    uintptr_t LabEnterPortalData_GetEntryPointID = 0x221AF00;
    uintptr_t LabEnterPortalData_GetTargetWorldID = 0x221AED0;
    uintptr_t LabEnterPortalData_GetTargetEntryPointID = 0x221AEE0;

    uintptr_t LabExitPortalData_GetName = 0x221B8F4;
    uintptr_t LabExitPortalData_GetIsLocked = 0x221B914;
    uintptr_t LabExitPortalData_GetEntryPointID = 0x221B904;
    uintptr_t LabExitPortalData_GetTargetWorldID = 0x221B8D4;
    uintptr_t LabExitPortalData_GetTargetEntryPointID = 0x221B8E4;

    uintptr_t BluePortalData_GetName = 0x2037514;
    uintptr_t BluePortalData_GetIsLocked = 0x2037534;
    uintptr_t BluePortalData_GetEntryPointID = 0x2037524;
    uintptr_t BluePortalData_GetTargetWorldID = 0x2037504;
    uintptr_t BluePortalData_GetTargetEntryPointID = 0x20374F4;

    uintptr_t TutorialCablePortalData_GetName = 0x7C7D94;
    uintptr_t TutorialCablePortalData_GetIsLocked = 0x7C7DB4;
    uintptr_t TutorialCablePortalData_GetEntryPointID = 0x7C7DA4;
    uintptr_t TutorialCablePortalData_GetTargetWorldID = 0x7C7D74;
    uintptr_t TutorialCablePortalData_GetTargetEntryPointID = 0x7C7D84;

    uintptr_t RiftPortalData_GetName = 0x23CFA74;
    uintptr_t RiftPortalData_GetIsLocked = 0x23CFA94;
    uintptr_t RiftPortalData_GetEntryPointID = 0x23CFA84;
    uintptr_t RiftPortalData_GetTargetWorldID = 0x23CFA54;
    uintptr_t RiftPortalData_GetTargetEntryPointID = 0x23CFA64;

    uintptr_t PortalPasswordData_GetName = 0x73B2EC;
    uintptr_t PortalPasswordData_GetIsLocked = 0x73B30C;
    uintptr_t PortalPasswordData_GetEntryPointID = 0x73B2FC;
    uintptr_t PortalPasswordData_GetTargetWorldID = 0x73B2CC;
    uintptr_t PortalPasswordData_GetTargetEntryPointID = 0x73B2DC;

    uintptr_t PortalFactionDarkData_GetName = 0x732AC0;
    uintptr_t PortalFactionDarkData_GetIsLocked = 0x732AE0;
    uintptr_t PortalFactionDarkData_GetEntryPointID = 0x732AD0;
    uintptr_t PortalFactionDarkData_GetTargetWorldID = 0x732AA0;
    uintptr_t PortalFactionDarkData_GetTargetEntryPointID = 0x732AB0;

    uintptr_t PortalFactionLightData_GetName = 0x7333A0;
    uintptr_t PortalFactionLightData_GetIsLocked = 0x7333C0;
    uintptr_t PortalFactionLightData_GetEntryPointID = 0x7333B0;
    uintptr_t PortalFactionLightData_GetTargetWorldID = 0x733380;
    uintptr_t PortalFactionLightData_GetTargetEntryPointID = 0x733390;

    uintptr_t PortalCrypticData_GetName = 0x7318A0;
    uintptr_t PortalCrypticData_GetIsLocked = 0x7318C0;
    uintptr_t PortalCrypticData_GetEntryPointID = 0x7318B0;
    uintptr_t PortalCrypticData_GetTargetWorldID = 0x731890;
    uintptr_t PortalCrypticData_GetTargetEntryPointID = 0x731880;

    uintptr_t PortalPixelMinesData_GetName = 0x73BBCC;
    uintptr_t PortalPixelMinesData_GetIsLocked = 0x73BBEC;
    uintptr_t PortalPixelMinesData_GetEntryPointID = 0x73BBDC;
    uintptr_t PortalPixelMinesData_GetTargetWorldID = 0x73BBAC;
    uintptr_t PortalPixelMinesData_GetTargetEntryPointID = 0x73BBBC;

    uintptr_t PortalMineExitData_GetName = 0x73A14C;
    uintptr_t PortalMineExitData_GetIsLocked = 0x73A16C;
    uintptr_t PortalMineExitData_GetEntryPointID = 0x73A15C;
    uintptr_t PortalMineExitData_GetTargetWorldID = 0x73A12C;
    uintptr_t PortalMineExitData_GetTargetEntryPointID = 0x73A13C;

    uintptr_t PortalMiningEntryData_GetName = 0x73AA2C;
    uintptr_t PortalMiningEntryData_GetIsLocked = 0x73AA4C;
    uintptr_t PortalMiningEntryData_GetEntryPointID = 0x73AA3C;
    uintptr_t PortalMiningEntryData_GetTargetWorldID = 0x73AA0C;
    uintptr_t PortalMiningEntryData_GetTargetEntryPointID = 0x73AA1C;

    uintptr_t JetRaceGroupPortalData_GetName = 0x247F368;
    uintptr_t JetRaceGroupPortalData_GetIsLocked = 0x247F388;
    uintptr_t JetRaceGroupPortalData_GetEntryPointID = 0x247F378;
    uintptr_t JetRaceGroupPortalData_GetTargetWorldID = 0x247F348;
    uintptr_t JetRaceGroupPortalData_GetTargetEntryPointID = 0x247F358;

        //Lock
    uintptr_t LockSmallData_GetPlayerWhoOwnsLockId = 0x90E5A0;
    uintptr_t LockSmallData_GetPlayerWhoOwnsLockName = 0x90E5B0;
    uintptr_t LockSmallData_GetIsOpen = 0x90E5C8;
    uintptr_t LockSmallData_GetIgnoreEmptyArea = 0x90E5D8;
    uintptr_t LockSmallData_GetPlayersWhoHaveAccessToLock = 0x90E664;
    uintptr_t LockSmallData_GetPlayersWhoHaveMinorAccessToLock = 0x90E7C8;
    uintptr_t LockSmallData_GetLastActivatedTime = 0x90E944;

    uintptr_t LockMediumData_GetPlayerWhoOwnsLockId = 0x902744;
    uintptr_t LockMediumData_GetPlayerWhoOwnsLockName = 0x902754;
    uintptr_t LockMediumData_GetIsOpen = 0x90276C;
    uintptr_t LockMediumData_GetIgnoreEmptyArea = 0x90277C;
    uintptr_t LockMediumData_GetPlayersWhoHaveAccessToLock = 0x902808;
    uintptr_t LockMediumData_GetPlayersWhoHaveMinorAccessToLock = 0x90296C;
    uintptr_t LockMediumData_GetLastActivatedTime = 0x902AE8;

    uintptr_t LockLargeData_GetPlayerWhoOwnsLockId = 0x901620;
    uintptr_t LockLargeData_GetPlayerWhoOwnsLockName = 0x901630;
    uintptr_t LockLargeData_GetIsOpen = 0x901648;
    uintptr_t LockLargeData_GetIgnoreEmptyArea = 0x901658;
    uintptr_t LockLargeData_GetPlayersWhoHaveAccessToLock = 0x9016E4;
    uintptr_t LockLargeData_GetPlayersWhoHaveMinorAccessToLock = 0x901848;
    uintptr_t LockLargeData_GetLastActivatedTime = 0x9019C4;

    uintptr_t LockWorldData_GetPlayerWhoOwnsLockId = 0x9124FC;
    uintptr_t LockWorldData_GetPlayerWhoOwnsLockName = 0x91250C;
    uintptr_t LockWorldData_GetIsOpen = 0x912524;
    uintptr_t LockWorldData_GetIsPunchingAllowed = 0x912534;
    uintptr_t LockWorldData_GetPlayersWhoHaveAccessToLock = 0x912544;
    uintptr_t LockWorldData_GetPlayersWhoHaveMinorAccessToLock = 0x9126D8;
    uintptr_t LockWorldData_GetLastActivatedTime = 0x912884;

    uintptr_t LockClanData_GetPlayerWhoOwnsLockId = 0x8FE5B0;
    uintptr_t LockClanData_GetPlayerWhoOwnsLockName = 0x8FE5C0;
    uintptr_t LockClanData_GetIsOpen = 0x8FE5D8;
    uintptr_t LockClanData_GetIsPunchingAllowed = 0x8FE5E8;
    uintptr_t LockClanData_GetPlayersWhoHaveAccessToLock = 0x8FE5F8;
    uintptr_t LockClanData_GetPlayersWhoHaveMinorAccessToLock = 0x8FE78C;
    uintptr_t LockClanData_GetLastActivatedTime = 0x8FE938;

    uintptr_t LockPlatinumData_GetPlayerWhoOwnsLockId = 0x903744;
    uintptr_t LockPlatinumData_GetPlayerWhoOwnsLockName = 0x903754;
    uintptr_t LockPlatinumData_GetIsOpen = 0x90376C;
    uintptr_t LockPlatinumData_GetIsPunchingAllowed = 0x90377C;
    uintptr_t LockPlatinumData_GetPlayersWhoHaveAccessToLock = 0x90378C;
    uintptr_t LockPlatinumData_GetPlayersWhoHaveMinorAccessToLock = 0x903920;
    uintptr_t LockPlatinumData_GetLastActivatedTime = 0x903ACC;

    uintptr_t LockWorldDarkData_GetPlayerWhoOwnsLockId = 0x911538;
    uintptr_t LockWorldDarkData_GetPlayerWhoOwnsLockName = 0x911548;
    uintptr_t LockWorldDarkData_GetIsOpen = 0x911560;
    uintptr_t LockWorldDarkData_GetIsPunchingAllowed = 0x911570;
    uintptr_t LockWorldDarkData_GetPlayersWhoHaveAccessToLock = 0x911580;
    uintptr_t LockWorldDarkData_GetPlayersWhoHaveMinorAccessToLock = 0x911714;
    uintptr_t LockWorldDarkData_GetLastActivatedTime = 0x9118C0;

    uintptr_t LockWorldBattleData_GetPlayerWhoOwnsLockId = 0x90F5A8;
    uintptr_t LockWorldBattleData_GetPlayerWhoOwnsLockName = 0x90F5B8;
    uintptr_t LockWorldBattleData_GetIsOpen = 0x90F5D0;
    uintptr_t LockWorldBattleData_GetIsPunchingAllowed = 0x90F5E0;
    uintptr_t LockWorldBattleData_GetIsBattleOn = 0x90F944;
    uintptr_t LockWorldBattleData_GetPlayersWhoHaveAccessToLock = 0x90F5F0;
    uintptr_t LockWorldBattleData_GetPlayersWhoHaveMinorAccessToLock = 0x90F784;
    uintptr_t LockWorldBattleData_GetLastActivatedTime = 0x90F930;

    uintptr_t LockBattleData_GetPlayerWhoOwnsLockId = 0x8FC48C;
    uintptr_t LockBattleData_GetPlayerWhoOwnsLockName = 0x8FC49C;
    uintptr_t LockBattleData_GetIsOpen = 0x8FC4B4;
    uintptr_t LockBattleData_GetIgnoreEmptyArea = 0x8FC4C4;
    uintptr_t LockBattleData_GetIsBattleOn = 0x8FC844;
    uintptr_t LockBattleData_GetPlayersWhoHaveAccessToLock = 0x8FC550;
    uintptr_t LockBattleData_GetPlayersWhoHaveMinorAccessToLock = 0x8FC6B4;
    uintptr_t LockBattleData_GetLastActivatedTime = 0x8FC830;

    uintptr_t LockWorldNoobData_GetPlayerWhoOwnsLockId = 0x9134C0;
    uintptr_t LockWorldNoobData_GetPlayerWhoOwnsLockName = 0x9134D0;
    uintptr_t LockWorldNoobData_GetIsOpen = 0x9134E8;
    uintptr_t LockWorldNoobData_GetIsPunchingAllowed = 0x9134F8;
    uintptr_t LockWorldNoobData_GetPlayersWhoHaveAccessToLock = 0x913508;
    uintptr_t LockWorldNoobData_GetPlayersWhoHaveMinorAccessToLock = 0x91369C;
    uintptr_t LockWorldNoobData_GetLastActivatedTime = 0x913848;

    uintptr_t LockBattleFactionData_GetPlayerWhoOwnsLockId = 0x8FD5B0;
    uintptr_t LockBattleFactionData_GetPlayerWhoOwnsLockName = 0x8FD5C0;
    uintptr_t LockBattleFactionData_GetIsOpen = 0x8FD5D8;
    uintptr_t LockBattleFactionData_GetIgnoreEmptyArea = 0x8FD5E8;
    uintptr_t LockBattleFactionData_GetIsBattleOn = 0x8FD968;
    uintptr_t LockBattleFactionData_GetPlayersWhoHaveAccessToLock = 0x8FD674;
    uintptr_t LockBattleFactionData_GetPlayersWhoHaveMinorAccessToLock = 0x8FD7D8;
    uintptr_t LockBattleFactionData_GetLastActivatedTime = 0x8FD954;

    uintptr_t LockWorldBattleFactionData_GetPlayerWhoOwnsLockId = 0x910574;
    uintptr_t LockWorldBattleFactionData_GetPlayerWhoOwnsLockName = 0x910584;
    uintptr_t LockWorldBattleFactionData_GetIsOpen = 0x91059C;
    uintptr_t LockWorldBattleFactionData_GetIsPunchingAllowed = 0x9105AC;
    uintptr_t LockWorldBattleFactionData_GetIsBattleOn = 0x910910;
    uintptr_t LockWorldBattleFactionData_GetPlayersWhoHaveAccessToLock = 0x9105BC;
    uintptr_t LockWorldBattleFactionData_GetPlayersWhoHaveMinorAccessToLock = 0x910750;
    uintptr_t LockWorldBattleFactionData_GetLastActivatedTime = 0x9108FC;

    //Chest
    uintptr_t QuantumSafeData_GetIsSomethingIn = 0x20064E0;
    uintptr_t QuantumSafeData_GetNumberOfItems = 0x20065DC;
    uintptr_t QuantumSafeData_GetInventoryKeyOfSlot = 0x2006634;
    uintptr_t QuantumSafeData_GetInventoryAmountOfSlot = 0x20066BC;

    uintptr_t SafeData_GetIsSomethingIn = 0x23719F4;
    uintptr_t SafeData_GetNumberOfItems = 0x2371AF0;
    uintptr_t SafeData_GetInventoryKeyOfSlot = 0x2371B48;
    uintptr_t SafeData_GetInventoryAmountOfSlot = 0x2371BD0;

    uintptr_t SmallChestBlackGoldData_GetIsSomethingIn = 0x205F8B8;
    uintptr_t SmallChestBlackGoldData_GetNumberOfItems = 0x205F9B4;
    uintptr_t SmallChestBlackGoldData_GetInventoryKeyOfSlot = 0x205FA0C;
    uintptr_t SmallChestBlackGoldData_GetInventoryAmountOfSlot = 0x205FA94;

    uintptr_t SmallChestData_GetIsSomethingIn = 0x205F8B8;
    uintptr_t SmallChestData_GetNumberOfItems = 0x205F9B4;
    uintptr_t SmallChestData_GetInventoryKeyOfSlot = 0x205FA0C;
    uintptr_t SmallChestData_GetInventoryAmountOfSlot = 0x205FA94;

    uintptr_t TinyChestData_GetIsSomethingIn = 0x1F8B7FC;
    uintptr_t TinyChestData_GetNumberOfItems = 0x1F8B8F8;
    uintptr_t TinyChestData_GetInventoryKeyOfSlot = 0x1F8B950;
    uintptr_t TinyChestData_GetInventoryAmountOfSlot = 0x1F8B9D8;

    uintptr_t BloodyChestData_GetIsSomethingIn = 0x2447B44;
    uintptr_t BloodyChestData_GetNumberOfItems = 0x2447C40;
    uintptr_t BloodyChestData_GetInventoryKeyOfSlot = 0x2447C98;
    uintptr_t BloodyChestData_GetInventoryAmountOfSlot = 0x2447D20;

    uintptr_t AlienChestData_GetIsSomethingIn = 0x88C55C;
    uintptr_t AlienChestData_GetNumberOfItems = 0x88C658;
    uintptr_t AlienChestData_GetInventoryKeyOfSlot = 0x88C6B0;
    uintptr_t AlienChestData_GetInventoryAmountOfSlot = 0x88C738;
}PixelWorlds;

#endif
