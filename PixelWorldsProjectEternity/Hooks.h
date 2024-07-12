#ifndef HOOKS_H
#define HOOKS_H

namespace PIXELWORLDS
{
    void LOAD_HOOK()
    {
        aIEnemyManager = new AIEnemyManager();
        playerListManager = new PlayerListManager();

        Component_get_transform = (void *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.Component_get_transform);
        Component_get_gameObject = (void *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.Component_get_gameObject);
        Object_get_name = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.Object_get_name);
        Application_set_targetFrameRate = (void (*)(int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.Application_set_targetFrameRate);
        TMP_Text_SetText = (void (*)(void *, monoString *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.TMP_Text_SetText);
        Screen_get_height = (int (*)()) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.Screen_get_height);
        Screen_get_width = (int (*)()) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.Screen_get_width);
        Transform_get_position = (Vector3 (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.Transform_get_position);
        Transform_set_position = (void (*)(void *, Vector3)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.Transform_set_position);
        Transform_get_childCount = (int (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.Transform_get_childCount);
        Transform_GetChild = (void *(*)(void *, int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.Transform_GetChild);
        BSONObject_get_Item = (void *(*)(void *, monoString *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.BSONObject_get_Item);
        BSONValue_get_stringValue = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.BSONValue_get_stringValue);

        //AdminToolsTeleportOverlayUI_ActivateDummy = (void (*)(void *, bool)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.AdminToolsTeleportOverlayUI_ActivateDummy);
        AIBase_GetCurrentAIBehaviorType = (int (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.AIBase_GetCurrentAIBehaviorType);
        AIBase_OnDeath = (void (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.AIBase_OnDeath);
        AIBase_IsAlive = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.AIBase_IsAlive);
        AIEnemyMonoBehaviourBase_GetIsActive = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.AIEnemyMonoBehaviourBase_GetIsActive);
        ChatUI_WarpToWorld = (void (*)(void *, monoString *, int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.ChatUI_WarpToWorld);
        ConfigData_IsBlockFamiliar = (bool (*)(int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.ConfigData_IsBlockFamiliar);
        ConfigData_IsBlockPortal = (bool (*)(int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.ConfigData_IsBlockPortal);
        ConfigData_DoesBlockHaveCollider = (bool (*)(int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.ConfigData_DoesBlockHaveCollider);
        ConfigData_IsBlockFamiliar = (bool (*)(int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.ConfigData_IsBlockFamiliar);
        ConfigData_GetBlockSortingLayerType = (int (*)(int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.ConfigData_GetBlockSortingLayerType);
        ConfigData_IsBlockInstakill = (bool (*)(int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.ConfigData_IsBlockInstakill);
        ConfigData_IsBlockFishingWater = (bool (*)(int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.ConfigData_IsBlockFishingWater);
        ConfigData_IsBlockWater = (bool (*)(int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.ConfigData_IsBlockWater);
        ConfigData_IsFishingLure = (bool (*)(int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.ConfigData_IsFishingLure);
        ConfigData_IsMiningNugget = (bool (*)(int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.ConfigData_IsMiningNugget);
        ConfigData_IsFish = (bool (*)(int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.ConfigData_IsFish);
        ConfigData_IsBlockMiningGemstone = (bool (*)(int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.ConfigData_IsBlockMiningGemstone);
        ConfigData_IsConsumableTreasurePouch = (bool (*)(int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.ConfigData_IsConsumableTreasurePouch);
        ConfigData_GetFishRecycleValueForFishRecycler = (int (*)(int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.ConfigData_GetFishRecycleValueForFishRecycler);
        ConfigData_GetGemstoneRecycleValueForMiningGemstoneRecycler = (int (*)(int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.ConfigData_GetGemstoneRecycleValueForMiningGemstoneRecycler);
        ConfigData_GetTreasurePouchRewardAmount = (int (*)(int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.ConfigData_GetTreasurePouchRewardAmount);
        ConfigData_IsBlockButterflyEventItem = (bool (*)(int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.ConfigData_IsBlockButterflyEventItem);
        ConfigData_GetMaxHitPoints = (int (*)(int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.ConfigData_GetMaxHitPoints);
        ConfigData_GetBlockTypeInventoryItemType = (int (*)(int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.ConfigData_GetBlockTypeInventoryItemType);
        EventDates_GetMiniEventNextStartTime = (DateTime (*)(int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.EventDates_GetMiniEventNextStartTime);
        EventDates_GetEventStartDateTime = (DateTime (*)(int, bool)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.EventDates_GetEventStartDateTime);
        EventDates_GetEventStartDateTimeExtra = (DateTime (*)(int, bool)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.EventDates_GetEventStartDateTimeExtra);
        FishingGaugeMinigameUI_LandButtonPressed = (void (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.FishingGaugeMinigameUI_LandButtonPressed);
        FishingResultsPopupUI_HardwareBackButtonPressed = (void (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.FishingResultsPopupUI_HardwareBackButtonPressed);
        GameplayUI_OnButtonDownNew = (void (*)(void *, int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.GameplayUI_OnButtonDownNew);
        GameplayUI_SettingsButtonClicked = (void (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.GameplayUI_SettingsButtonClicked);
        InventoryControl_GetCurrentSelection = (InventoryKey (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.InventoryControl_GetCurrentSelection);
        ItemPacks_GetItemPacksList = (monoList<ItemPack *> *(*)(monoString *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.ItemPacks_GetItemPacksList);
        KukouriTime_Get = (DateTime (*)()) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.KukouriTime_Get);
        MainMenuLogic_JoinRandomWorldFromMainMenu = (void (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.MainMenuLogic_JoinRandomWorldFromMainMenu);
        MainMenuLogic_LogOut = (void (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.MainMenuLogic_LogOut);
        MainMenuShopLogic_IsInMainMenu = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.MainMenuShopLogic_IsInMainMenu);
        OptionsMenuUI_ExitWorld = (void (*)(void *, monoString *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.OptionsMenuUI_ExitWorld);
        OutgoingMessages_SendHitBlockBackgroundMessage = (void (*)(Vector2i, DateTime)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.OutgoingMessages_SendHitBlockBackgroundMessage);
        OutgoingMessages_SendHitBlockWaterMessage = (void (*)(Vector2i, DateTime)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.OutgoingMessages_SendHitBlockWaterMessage);
        OutgoingMessages_SendSetBlockMessage = (void (*)(Vector2i, int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.OutgoingMessages_SendSetBlockMessage);
        OutgoingMessages_SendSetBlockBackgroundMessage = (void (*)(Vector2i, int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.OutgoingMessages_SendSetBlockBackgroundMessage);
        OutgoingMessages_SendSetBlockWaterMessage = (void (*)(Vector2i, int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.OutgoingMessages_SendSetBlockWaterMessage);
        OutgoingMessages_ConvertItems = (void (*)(InventoryKey)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.OutgoingMessages_ConvertItems);
        OutgoingMessages_BuyItemPack = (void (*)(monoString *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.OutgoingMessages_BuyItemPack);
        OutgoingMessages_SendHitAirMessage = (void (*)(Vector2i)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.OutgoingMessages_SendHitAirMessage);
        OutgoingMessages_SendHitSpiritMessage = (void (*)(Vector2i)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.OutgoingMessages_SendHitSpiritMessage);
        OutgoingMessages_SendSpinJetRaceRouletteMessage = (void (*)()) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.OutgoingMessages_SendSpinJetRaceRouletteMessage);
        OutgoingMessages_SendSpinMiningRouletteMessage = (void (*)()) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.OutgoingMessages_SendSpinMiningRouletteMessage);
        OutgoingMessages_SendUsePotionMessage = (void (*)(int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.OutgoingMessages_SendUsePotionMessage);
        OutgoingMessages_MiningPickaxeRepairing = (void (*)(InventoryKey)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.OutgoingMessages_MiningPickaxeRepairing);
        OutgoingMessages_SendRequestGeneratedMineExitMessage = (void (*)(Vector2i)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.OutgoingMessages_SendRequestGeneratedMineExitMessage);
        OutgoingMessages_SendRequestItemFromGiftBoxMessage = (void (*)(Vector2i)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.OutgoingMessages_SendRequestItemFromGiftBoxMessage);
        OutgoingMessages_SendHitBlockMessage = (void (*)(Vector2i, DateTime, bool)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.OutgoingMessages_SendHitBlockMessage);
        OutgoingMessages_SendHitAIEnemyMessage = (void (*)(Vector2i, int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.OutgoingMessages_SendHitAIEnemyMessage);
        Player_GoFromPortal = (void (*)(void *, Vector2i)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.Player_GoFromPortal);
        Player_ChangeWearableRemote = (void (*)(void *, int, int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.Player_ChangeWearableRemote);
        Player_IsPlayerInMapPoint = (bool (*)(void *, Vector2i)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.Player_IsPlayerInMapPoint);
        Player_IsFishStrikeActive = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.Player_IsFishStrikeActive);
        Player_SetVelocity = (void (*)(void *, Vector3)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.Player_SetVelocity);
        Player_ChangeFamiliarRemote = (void (*)(void *, int, monoString *, bool)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.Player_ChangeFamiliarRemote);
        PlayerData_AddItemToInventory = (void (*)(void *, int, int ,short)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PlayerData_AddItemToInventory);
        PlayerData_RemoveItemsFromInventory = (void (*)(void *, InventoryKey, short)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PlayerData_RemoveItemsFromInventory);
        PlayerData_GetInventoryAsOrderedByInventoryItemType = (monoArray<InventoryKey *> *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PlayerData_GetInventoryAsOrderedByInventoryItemType);
        PlayerData_GetBeltItem = (InventoryKey (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PlayerData_GetBeltItem);
        PlayerData_GetInventoryData = (void *(*)(void *, InventoryKey)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PlayerData_GetInventoryData);
        PlayerData_GetInventorySize = (int (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PlayerData_GetInventorySize);
        PlayerData_GetCount = (short (*)(void *, InventoryKey)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PlayerData_GetCount);
        PlayerData_GetMaxHitPoints = (int (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PlayerData_GetMaxHitPoints);
        PlayerData_GetPlayerWearWerablesAndWeaponInventoryDatas = (monoList<void **> *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PlayerData_GetPlayerWearWerablesAndWeaponInventoryDatas);
        SceneLoader_ReloadGame = (void (*)()) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.SceneLoader_ReloadGame);
        Spirit_GetCurrentMapPoint = (Vector2i (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.Spirit_GetCurrentMapPoint);
        WeaponPickaxeCrappyInventoryData_GetDurability = (int (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.WeaponPickaxeCrappyInventoryData_GetDurability);
        WeaponPickaxeFlimsyInventoryData_GetDurability = (int (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.WeaponPickaxeFlimsyInventoryData_GetDurability);
        WeaponPickaxeBasicInventoryData_GetDurability = (int (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.WeaponPickaxeBasicInventoryData_GetDurability);
        WeaponPickaxeSturdyInventoryData_GetDurability = (int (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.WeaponPickaxeSturdyInventoryData_GetDurability);
        WeaponPickaxeHeavyInventoryData_GetDurability = (int (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.WeaponPickaxeHeavyInventoryData_GetDurability);
        WeaponPickaxeMasterInventoryData_GetDurability = (int (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.WeaponPickaxeMasterInventoryData_GetDurability);
        WeaponPickaxeEpicInventoryData_GetDurability = (int (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.WeaponPickaxeEpicInventoryData_GetDurability);
        WeaponPickaxeDarkInventoryData_GetDurability = (int (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.WeaponPickaxeDarkInventoryData_GetDurability);
        WearableHotSpotsValidity_GetWearableHotSpots = (monoArray<int *> *(*)(int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.WearableHotSpotsValidity_GetWearableHotSpots);
        World_GetWorldItemData = (void *(*)(void *, int, int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.World_GetWorldItemData);
        World_GetBlockType = (int (*)(void *, int, int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.World_GetBlockType);
        World_GetBlockWaterType = (int (*)(void *, int, int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.World_GetBlockWaterType);
        World_GetBlockBackgroundType = (int (*)(void *, int, int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.World_GetBlockBackgroundType);
        WorldController_SetBaitWithTool = (bool (*)(void *, int , Vector2i, float)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.WorldController_SetBaitWithTool);
        WorldController_DropStuffFromInventory = (void (*)(void *, Vector2i, InventoryKey, short, void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.WorldController_DropStuffFromInventory);
        WorldController_SetBlock = (void (*)(void *, int, int, int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.WorldController_SetBlock);
        WorldController_SetBlockBackground = (void (*)(void *, int, int, int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.WorldController_SetBlockBackground);
        WorldController_SetBlockWater = (void (*)(void *, int, int, int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.WorldController_SetBlockWater);
        WorldController_DestroyBlockSpriteOrQuad = (void (*)(void *,int ,int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.WorldController_DestroyBlockSpriteOrQuad);
        WorldController_DestroyBlockBackgroundSpriteOrQuad = (void (*)(void *,int ,int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.WorldController_DestroyBlockBackgroundSpriteOrQuad);
        WorldController_DestroyBlockWaterSpriteOrQuad = (void (*)(void *,int ,int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.WorldController_DestroyBlockWaterSpriteOrQuad);

        //Data
        {
            VortexPortalData_GetName = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.VortexPortalData_GetName);
            VortexPortalData_GetIsLocked = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.VortexPortalData_GetIsLocked);
            VortexPortalData_GetEntryPointID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.VortexPortalData_GetEntryPointID);
            VortexPortalData_GetTargetWorldID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.VortexPortalData_GetTargetWorldID);
            VortexPortalData_GetTargetEntryPointID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.VortexPortalData_GetTargetEntryPointID);

            PortalData_GetName = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalData_GetName);
            PortalData_GetIsLocked = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalData_GetIsLocked);
            PortalData_GetEntryPointID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalData_GetEntryPointID);
            PortalData_GetTargetWorldID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalData_GetTargetWorldID);
            PortalData_GetTargetEntryPointID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalData_GetTargetEntryPointID);

            LockSmallData_GetPlayerWhoOwnsLockId = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockSmallData_GetPlayerWhoOwnsLockId);
            LockSmallData_GetPlayerWhoOwnsLockName = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockSmallData_GetPlayerWhoOwnsLockName);
            LockSmallData_GetIsOpen = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockSmallData_GetIsOpen);
            LockSmallData_GetIgnoreEmptyArea = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockSmallData_GetIgnoreEmptyArea);
            LockSmallData_GetPlayersWhoHaveAccessToLock = (monoList<monoString **> *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockSmallData_GetPlayersWhoHaveAccessToLock);
            LockSmallData_GetPlayersWhoHaveMinorAccessToLock = (monoList<monoString **> *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockSmallData_GetPlayersWhoHaveMinorAccessToLock);
            LockSmallData_GetLastActivatedTime = (DateTime (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockSmallData_GetLastActivatedTime);

            LockMediumData_GetPlayerWhoOwnsLockId = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockMediumData_GetPlayerWhoOwnsLockId);
            LockMediumData_GetPlayerWhoOwnsLockName = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockMediumData_GetPlayerWhoOwnsLockName);
            LockMediumData_GetIsOpen = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockMediumData_GetIsOpen);
            LockMediumData_GetIgnoreEmptyArea = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockMediumData_GetIgnoreEmptyArea);
            LockMediumData_GetPlayersWhoHaveAccessToLock = (monoList<monoString **> *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockMediumData_GetPlayersWhoHaveAccessToLock);
            LockMediumData_GetPlayersWhoHaveMinorAccessToLock = (monoList<monoString **> *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockMediumData_GetPlayersWhoHaveMinorAccessToLock);
            LockMediumData_GetLastActivatedTime = (DateTime (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockMediumData_GetLastActivatedTime);

            LockLargeData_GetPlayerWhoOwnsLockId = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockLargeData_GetPlayerWhoOwnsLockId);
            LockLargeData_GetPlayerWhoOwnsLockName = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockLargeData_GetPlayerWhoOwnsLockName);
            LockLargeData_GetIsOpen = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockLargeData_GetIsOpen);
            LockLargeData_GetIgnoreEmptyArea = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockLargeData_GetIgnoreEmptyArea);
            LockLargeData_GetPlayersWhoHaveAccessToLock = (monoList<monoString **> *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockLargeData_GetPlayersWhoHaveAccessToLock);
            LockLargeData_GetPlayersWhoHaveMinorAccessToLock = (monoList<monoString **> *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockLargeData_GetPlayersWhoHaveMinorAccessToLock);
            LockLargeData_GetLastActivatedTime = (DateTime (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockLargeData_GetLastActivatedTime);

            LockWorldData_GetPlayerWhoOwnsLockId = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockWorldData_GetPlayerWhoOwnsLockId);
            LockWorldData_GetPlayerWhoOwnsLockName = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockWorldData_GetPlayerWhoOwnsLockName);
            LockWorldData_GetIsOpen = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockWorldData_GetIsOpen);
            LockWorldData_GetIsPunchingAllowed = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockWorldData_GetIsPunchingAllowed);
            LockWorldData_GetPlayersWhoHaveAccessToLock = (monoList<monoString **> *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockWorldData_GetPlayersWhoHaveAccessToLock);
            LockWorldData_GetPlayersWhoHaveMinorAccessToLock = (monoList<monoString **> *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockWorldData_GetPlayersWhoHaveMinorAccessToLock);
            LockWorldData_GetLastActivatedTime = (DateTime (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockWorldData_GetLastActivatedTime);

            LockClanData_GetPlayerWhoOwnsLockId = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockClanData_GetPlayerWhoOwnsLockId);
            LockClanData_GetPlayerWhoOwnsLockName = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockClanData_GetPlayerWhoOwnsLockName);
            LockClanData_GetIsOpen = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockClanData_GetIsOpen);
            LockClanData_GetIsPunchingAllowed = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockClanData_GetIsPunchingAllowed);
            LockClanData_GetPlayersWhoHaveAccessToLock = (monoList<monoString **> *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockClanData_GetPlayersWhoHaveAccessToLock);
            LockClanData_GetPlayersWhoHaveMinorAccessToLock = (monoList<monoString **> *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockClanData_GetPlayersWhoHaveMinorAccessToLock);
            LockClanData_GetLastActivatedTime = (DateTime (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockClanData_GetLastActivatedTime);

            LockPlatinumData_GetPlayerWhoOwnsLockId = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockPlatinumData_GetPlayerWhoOwnsLockId);
            LockPlatinumData_GetPlayerWhoOwnsLockName = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockPlatinumData_GetPlayerWhoOwnsLockName);
            LockPlatinumData_GetIsOpen = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockPlatinumData_GetIsOpen);
            LockPlatinumData_GetIsPunchingAllowed = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockPlatinumData_GetIsPunchingAllowed);
            LockPlatinumData_GetPlayersWhoHaveAccessToLock = (monoList<monoString **> *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockPlatinumData_GetPlayersWhoHaveAccessToLock);
            LockPlatinumData_GetPlayersWhoHaveMinorAccessToLock = (monoList<monoString **> *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockPlatinumData_GetPlayersWhoHaveMinorAccessToLock);
            LockPlatinumData_GetLastActivatedTime = (DateTime (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockPlatinumData_GetLastActivatedTime);

            LockWorldDarkData_GetPlayerWhoOwnsLockId = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockWorldDarkData_GetPlayerWhoOwnsLockId);
            LockWorldDarkData_GetPlayerWhoOwnsLockName = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockWorldDarkData_GetPlayerWhoOwnsLockName);
            LockWorldDarkData_GetIsOpen = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockWorldDarkData_GetIsOpen);
            LockWorldDarkData_GetIsPunchingAllowed = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockWorldDarkData_GetIsPunchingAllowed);
            LockWorldDarkData_GetPlayersWhoHaveAccessToLock = (monoList<monoString **> *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockWorldDarkData_GetPlayersWhoHaveAccessToLock);
            LockWorldDarkData_GetPlayersWhoHaveMinorAccessToLock = (monoList<monoString **> *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockWorldDarkData_GetPlayersWhoHaveMinorAccessToLock);
            LockWorldDarkData_GetLastActivatedTime = (DateTime (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockWorldDarkData_GetLastActivatedTime);

            LockWorldBattleData_GetPlayerWhoOwnsLockId = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockWorldBattleData_GetPlayerWhoOwnsLockId);
            LockWorldBattleData_GetPlayerWhoOwnsLockName = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockWorldBattleData_GetPlayerWhoOwnsLockName);
            LockWorldBattleData_GetIsOpen = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockWorldBattleData_GetIsOpen);
            LockWorldBattleData_GetIsPunchingAllowed = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockWorldBattleData_GetIsPunchingAllowed);
            LockWorldBattleData_GetIsBattleOn = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockWorldBattleData_GetIsBattleOn);
            LockWorldBattleData_GetPlayersWhoHaveAccessToLock = (monoList<monoString **> *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockWorldBattleData_GetPlayersWhoHaveAccessToLock);
            LockWorldBattleData_GetPlayersWhoHaveMinorAccessToLock = (monoList<monoString **> *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockWorldBattleData_GetPlayersWhoHaveMinorAccessToLock);
            LockWorldBattleData_GetLastActivatedTime = (DateTime (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockWorldBattleData_GetLastActivatedTime);

            LockBattleData_GetPlayerWhoOwnsLockId = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockBattleData_GetPlayerWhoOwnsLockId);
            LockBattleData_GetPlayerWhoOwnsLockName = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockBattleData_GetPlayerWhoOwnsLockName);
            LockBattleData_GetIsOpen = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockBattleData_GetIsOpen);
            LockBattleData_GetIgnoreEmptyArea = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockBattleData_GetIgnoreEmptyArea);
            LockBattleData_GetIsBattleOn = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockBattleData_GetIsBattleOn);
            LockBattleData_GetPlayersWhoHaveAccessToLock = (monoList<monoString **> *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockBattleData_GetPlayersWhoHaveAccessToLock);
            LockBattleData_GetPlayersWhoHaveMinorAccessToLock = (monoList<monoString **> *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockBattleData_GetPlayersWhoHaveMinorAccessToLock);
            LockBattleData_GetLastActivatedTime = (DateTime (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockBattleData_GetLastActivatedTime);

            LockWorldNoobData_GetPlayerWhoOwnsLockId = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockWorldNoobData_GetPlayerWhoOwnsLockId);
            LockWorldNoobData_GetPlayerWhoOwnsLockName = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockWorldNoobData_GetPlayerWhoOwnsLockName);
            LockWorldNoobData_GetIsOpen = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockWorldNoobData_GetIsOpen);
            LockWorldNoobData_GetIsPunchingAllowed = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockWorldNoobData_GetIsPunchingAllowed);
            LockWorldNoobData_GetPlayersWhoHaveAccessToLock = (monoList<monoString **> *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockWorldNoobData_GetPlayersWhoHaveAccessToLock);
            LockWorldNoobData_GetPlayersWhoHaveMinorAccessToLock = (monoList<monoString **> *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockWorldNoobData_GetPlayersWhoHaveMinorAccessToLock);
            LockWorldNoobData_GetLastActivatedTime = (DateTime (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockWorldNoobData_GetLastActivatedTime);

            PortalPasswordData_GetName = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalPasswordData_GetName);
            PortalPasswordData_GetIsLocked = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalPasswordData_GetIsLocked);
            PortalPasswordData_GetEntryPointID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalPasswordData_GetEntryPointID);
            PortalPasswordData_GetTargetWorldID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalPasswordData_GetTargetWorldID);
            PortalPasswordData_GetTargetEntryPointID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalPasswordData_GetTargetEntryPointID);

            LockBattleFactionData_GetPlayerWhoOwnsLockId = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockBattleFactionData_GetPlayerWhoOwnsLockId);
            LockBattleFactionData_GetPlayerWhoOwnsLockName = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockBattleFactionData_GetPlayerWhoOwnsLockName);
            LockBattleFactionData_GetIsOpen = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockBattleFactionData_GetIsOpen);
            LockBattleFactionData_GetIgnoreEmptyArea = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockBattleFactionData_GetIgnoreEmptyArea);
            LockBattleFactionData_GetIsBattleOn = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockBattleFactionData_GetIsBattleOn);
            LockBattleFactionData_GetPlayersWhoHaveAccessToLock = (monoList<monoString **> *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockBattleFactionData_GetPlayersWhoHaveAccessToLock);
            LockBattleFactionData_GetPlayersWhoHaveMinorAccessToLock = (monoList<monoString **> *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockBattleFactionData_GetPlayersWhoHaveMinorAccessToLock);
            LockBattleFactionData_GetLastActivatedTime = (DateTime (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockBattleFactionData_GetLastActivatedTime);

            LockWorldBattleFactionData_GetPlayerWhoOwnsLockId = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockWorldBattleFactionData_GetPlayerWhoOwnsLockId);
            LockWorldBattleFactionData_GetPlayerWhoOwnsLockName = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockWorldBattleFactionData_GetPlayerWhoOwnsLockName);
            LockWorldBattleFactionData_GetIsOpen = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockWorldBattleFactionData_GetIsOpen);
            LockWorldBattleFactionData_GetIsPunchingAllowed = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockWorldBattleFactionData_GetIsPunchingAllowed);
            LockWorldBattleFactionData_GetIsBattleOn = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockWorldBattleFactionData_GetIsBattleOn);
            LockWorldBattleFactionData_GetPlayersWhoHaveAccessToLock = (monoList<monoString **> *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockWorldBattleFactionData_GetPlayersWhoHaveAccessToLock);
            LockWorldBattleFactionData_GetPlayersWhoHaveMinorAccessToLock = (monoList<monoString **> *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockWorldBattleFactionData_GetPlayersWhoHaveMinorAccessToLock);
            LockWorldBattleFactionData_GetLastActivatedTime = (DateTime (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LockWorldBattleFactionData_GetLastActivatedTime);

            AnniversaryPortalData_GetName = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.AnniversaryPortalData_GetName);
            AnniversaryPortalData_GetIsLocked = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.AnniversaryPortalData_GetIsLocked);
            AnniversaryPortalData_GetEntryPointID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.AnniversaryPortalData_GetEntryPointID);
            AnniversaryPortalData_GetTargetWorldID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.AnniversaryPortalData_GetTargetWorldID);
            AnniversaryPortalData_GetTargetEntryPointID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.AnniversaryPortalData_GetTargetEntryPointID);

            PortalWOTWData_GetName = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalWOTWData_GetName);
            PortalWOTWData_GetIsLocked = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalWOTWData_GetIsLocked);
            PortalWOTWData_GetEntryPointID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalWOTWData_GetEntryPointID);
            PortalWOTWData_GetTargetWorldID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalWOTWData_GetTargetWorldID);
            PortalWOTWData_GetTargetEntryPointID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalWOTWData_GetTargetEntryPointID);

            NetherGroupPortalData_GetName = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.NetherGroupPortalData_GetName);
            NetherGroupPortalData_GetIsLocked = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.NetherGroupPortalData_GetIsLocked);
            NetherGroupPortalData_GetEntryPointID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.NetherGroupPortalData_GetEntryPointID);
            NetherGroupPortalData_GetTargetWorldID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.NetherGroupPortalData_GetTargetWorldID);
            NetherGroupPortalData_GetTargetEntryPointID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.NetherGroupPortalData_GetTargetEntryPointID);

            LabEnterPortalData_GetName = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LabEnterPortalData_GetName);
            LabEnterPortalData_GetIsLocked = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LabEnterPortalData_GetIsLocked);
            LabEnterPortalData_GetEntryPointID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LabEnterPortalData_GetEntryPointID);
            LabEnterPortalData_GetTargetWorldID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LabEnterPortalData_GetTargetWorldID);
            LabEnterPortalData_GetTargetEntryPointID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LabEnterPortalData_GetTargetEntryPointID);

            LabExitPortalData_GetName = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LabExitPortalData_GetName);
            LabExitPortalData_GetIsLocked = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LabExitPortalData_GetIsLocked);
            LabExitPortalData_GetEntryPointID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LabExitPortalData_GetEntryPointID);
            LabExitPortalData_GetTargetWorldID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LabExitPortalData_GetTargetWorldID);
            LabExitPortalData_GetTargetEntryPointID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.LabExitPortalData_GetTargetEntryPointID);

            BluePortalData_GetName = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.BluePortalData_GetName);
            BluePortalData_GetIsLocked = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.BluePortalData_GetIsLocked);
            BluePortalData_GetEntryPointID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.BluePortalData_GetEntryPointID);
            BluePortalData_GetTargetWorldID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.BluePortalData_GetTargetWorldID);
            BluePortalData_GetTargetEntryPointID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.BluePortalData_GetTargetEntryPointID);

            TutorialCablePortalData_GetName = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.TutorialCablePortalData_GetName);
            TutorialCablePortalData_GetIsLocked = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.TutorialCablePortalData_GetIsLocked);
            TutorialCablePortalData_GetEntryPointID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.TutorialCablePortalData_GetEntryPointID);
            TutorialCablePortalData_GetTargetWorldID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.TutorialCablePortalData_GetTargetWorldID);
            TutorialCablePortalData_GetTargetEntryPointID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.TutorialCablePortalData_GetTargetEntryPointID);

            RiftPortalData_GetName = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.RiftPortalData_GetName);
            RiftPortalData_GetIsLocked = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.RiftPortalData_GetIsLocked);
            RiftPortalData_GetEntryPointID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.RiftPortalData_GetEntryPointID);
            RiftPortalData_GetTargetWorldID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.RiftPortalData_GetTargetWorldID);
            RiftPortalData_GetTargetEntryPointID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.RiftPortalData_GetTargetEntryPointID);

            PortalFactionDarkData_GetName = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalFactionDarkData_GetName);
            PortalFactionDarkData_GetIsLocked = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalFactionDarkData_GetIsLocked);
            PortalFactionDarkData_GetEntryPointID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalFactionDarkData_GetEntryPointID);
            PortalFactionDarkData_GetTargetWorldID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalFactionDarkData_GetTargetWorldID);
            PortalFactionDarkData_GetTargetEntryPointID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalFactionDarkData_GetTargetEntryPointID);

            PortalFactionLightData_GetName = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalFactionLightData_GetName);
            PortalFactionLightData_GetIsLocked = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalFactionLightData_GetIsLocked);
            PortalFactionLightData_GetEntryPointID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalFactionLightData_GetEntryPointID);
            PortalFactionLightData_GetTargetWorldID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalFactionLightData_GetTargetWorldID);
            PortalFactionLightData_GetTargetEntryPointID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalFactionLightData_GetTargetEntryPointID);

            PortalCrypticData_GetName = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalCrypticData_GetName);
            PortalCrypticData_GetIsLocked = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalCrypticData_GetIsLocked);
            PortalCrypticData_GetEntryPointID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalCrypticData_GetEntryPointID);
            PortalCrypticData_GetTargetWorldID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalCrypticData_GetTargetWorldID);
            PortalCrypticData_GetTargetEntryPointID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalCrypticData_GetTargetEntryPointID);

            PortalPixelMinesData_GetName = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalPixelMinesData_GetName);
            PortalPixelMinesData_GetIsLocked = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalPixelMinesData_GetIsLocked);
            PortalPixelMinesData_GetEntryPointID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalPixelMinesData_GetEntryPointID);
            PortalPixelMinesData_GetTargetWorldID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalPixelMinesData_GetTargetWorldID);
            PortalPixelMinesData_GetTargetEntryPointID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalPixelMinesData_GetTargetEntryPointID);

            PortalMineExitData_GetName = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalMineExitData_GetName);
            PortalMineExitData_GetIsLocked = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalMineExitData_GetIsLocked);
            PortalMineExitData_GetEntryPointID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalMineExitData_GetEntryPointID);
            PortalMineExitData_GetTargetWorldID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalMineExitData_GetTargetWorldID);
            PortalMineExitData_GetTargetEntryPointID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalMineExitData_GetTargetEntryPointID);

            PortalMiningEntryData_GetName = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalMiningEntryData_GetName);
            PortalMiningEntryData_GetIsLocked = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalMiningEntryData_GetIsLocked);
            PortalMiningEntryData_GetEntryPointID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalMiningEntryData_GetEntryPointID);
            PortalMiningEntryData_GetTargetWorldID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalMiningEntryData_GetTargetWorldID);
            PortalMiningEntryData_GetTargetEntryPointID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PortalMiningEntryData_GetTargetEntryPointID);

            JetRaceGroupPortalData_GetName = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.JetRaceGroupPortalData_GetName);
            JetRaceGroupPortalData_GetIsLocked = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.JetRaceGroupPortalData_GetIsLocked);
            JetRaceGroupPortalData_GetEntryPointID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.JetRaceGroupPortalData_GetEntryPointID);
            JetRaceGroupPortalData_GetTargetWorldID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.JetRaceGroupPortalData_GetTargetWorldID);
            JetRaceGroupPortalData_GetTargetEntryPointID = (monoString *(*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.JetRaceGroupPortalData_GetTargetEntryPointID);

            QuantumSafeData_GetIsSomethingIn = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.QuantumSafeData_GetIsSomethingIn);
            QuantumSafeData_GetNumberOfItems = (int (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.QuantumSafeData_GetNumberOfItems);
            QuantumSafeData_GetInventoryKeyOfSlot = (InventoryKey (*)(void *, int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.QuantumSafeData_GetInventoryKeyOfSlot);
            QuantumSafeData_GetInventoryAmountOfSlot = (short (*)(void *, int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.QuantumSafeData_GetInventoryAmountOfSlot);

            SafeData_GetIsSomethingIn = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.SafeData_GetIsSomethingIn);
            SafeData_GetNumberOfItems = (int (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.SafeData_GetNumberOfItems);
            SafeData_GetInventoryKeyOfSlot = (InventoryKey (*)(void *, int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.SafeData_GetInventoryKeyOfSlot);
            SafeData_GetInventoryAmountOfSlot = (short (*)(void *, int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.SafeData_GetInventoryAmountOfSlot);

            SmallChestBlackGoldData_GetIsSomethingIn = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.SmallChestBlackGoldData_GetIsSomethingIn);
            SmallChestBlackGoldData_GetNumberOfItems = (int (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.SmallChestBlackGoldData_GetNumberOfItems);
            SmallChestBlackGoldData_GetInventoryKeyOfSlot = (InventoryKey (*)(void *, int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.SmallChestBlackGoldData_GetInventoryKeyOfSlot);
            SmallChestBlackGoldData_GetInventoryAmountOfSlot = (short (*)(void *, int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.SmallChestBlackGoldData_GetInventoryAmountOfSlot);

            SmallChestData_GetIsSomethingIn = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.SmallChestData_GetIsSomethingIn);
            SmallChestData_GetNumberOfItems = (int (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.SmallChestData_GetNumberOfItems);
            SmallChestData_GetInventoryKeyOfSlot = (InventoryKey (*)(void *, int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.SmallChestData_GetInventoryKeyOfSlot);
            SmallChestData_GetInventoryAmountOfSlot = (short (*)(void *, int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.SmallChestData_GetInventoryAmountOfSlot);

            TinyChestData_GetIsSomethingIn = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.TinyChestData_GetIsSomethingIn);
            TinyChestData_GetNumberOfItems = (int (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.TinyChestData_GetNumberOfItems);
            TinyChestData_GetInventoryKeyOfSlot = (InventoryKey (*)(void *, int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.TinyChestData_GetInventoryKeyOfSlot);
            TinyChestData_GetInventoryAmountOfSlot = (short (*)(void *, int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.TinyChestData_GetInventoryAmountOfSlot);

            BloodyChestData_GetIsSomethingIn = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.BloodyChestData_GetIsSomethingIn);
            BloodyChestData_GetNumberOfItems = (int (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.BloodyChestData_GetNumberOfItems);
            BloodyChestData_GetInventoryKeyOfSlot = (InventoryKey (*)(void *, int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.BloodyChestData_GetInventoryKeyOfSlot);
            BloodyChestData_GetInventoryAmountOfSlot = (short (*)(void *, int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.BloodyChestData_GetInventoryAmountOfSlot);

            AlienChestData_GetIsSomethingIn = (bool (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.AlienChestData_GetIsSomethingIn);
            AlienChestData_GetNumberOfItems = (int (*)(void *)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.AlienChestData_GetNumberOfItems);
            AlienChestData_GetInventoryKeyOfSlot = (InventoryKey (*)(void *, int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.AlienChestData_GetInventoryKeyOfSlot);
            AlienChestData_GetInventoryAmountOfSlot = (short (*)(void *, int)) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.AlienChestData_GetInventoryAmountOfSlot);
        }

        //hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.AdminToolsTeleportOverlayUI_Update), (void *)AdminToolsTeleportOverlayUI_Update, (void **)&old_AdminToolsTeleportOverlayUI_Update);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.AIEnemyMonoBehaviourBase_Update), (void *)AIEnemyMonoBehaviourBase_Update, (void **)&old_AIEnemyMonoBehaviourBase_Update);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.BaseMenuUI_Update), (void *)BaseMenuUI_Update, (void **)&old_BaseMenuUI_Update);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.ChatUI_Update), (void *)ChatUI_Update, (void **)&old_ChatUI_Update);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.ConfigData_CanPlaceSeedTopOf), (void *)ConfigData_CanPlaceSeedTopOf, (void **)&old_ConfigData_CanPlaceSeedTopOf);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.ConfigData_GetBlockRunSpeed), (void *)ConfigData_GetBlockRunSpeed, (void **)&old_ConfigData_GetBlockRunSpeed);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.ConfigData_IsBlockHot), (void *)ConfigData_IsBlockHot, (void **)&old_ConfigData_IsBlockHot);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.ConfigData_IsBlockSpring), (void *)ConfigData_IsBlockSpring, (void **)&old_ConfigData_IsBlockSpring);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.ConfigData_IsBlockElastic), (void *)ConfigData_IsBlockElastic, (void **)&old_ConfigData_IsBlockElastic);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.ConfigData_IsBlockPinball), (void *)ConfigData_IsBlockPinball, (void **)&old_ConfigData_IsBlockPinball);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.ConfigData_IsBlockTrampolin), (void *)ConfigData_IsBlockTrampolin, (void **)&old_ConfigData_IsBlockTrampolin);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.ConfigData_IsBlockElevator), (void *)ConfigData_IsBlockElevator, (void **)&old_ConfigData_IsBlockElevator);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.ConfigData_IsBlockWind), (void *)ConfigData_IsBlockWind, (void **)&old_ConfigData_IsBlockWind);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.ConfigData_IsBlockDeflector), (void *)ConfigData_IsBlockDeflector, (void **)&old_ConfigData_IsBlockDeflector);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.ConfigData_GetDeflectorRange), (void *)ConfigData_GetDeflectorRange, (void **)&old_ConfigData_GetDeflectorRange);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.ConfigData_GetDeflectorForce), (void *)ConfigData_GetDeflectorForce, (void **)&old_ConfigData_GetDeflectorForce);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.ConfigData_GetDeflectorForceGrounded), (void *)ConfigData_GetDeflectorForceGrounded, (void **)&old_ConfigData_GetDeflectorForceGrounded);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.FishingGaugeMinigameUI_Update), (void *)FishingGaugeMinigameUI_Update, (void **)&old_FishingGaugeMinigameUI_Update);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.GameplayUI_Update), (void *)GameplayUI_Update, (void **)&old_GameplayUI_Update);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.InventoryControl_Update), (void *)InventoryControl_Update, (void **)&old_InventoryControl_Update);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.MainMenuLogic_Update), (void *)MainMenuLogic_Update, (void **)&old_MainMenuLogic_Update);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.MineWorldNotificationUI_Update), (void *)MineWorldNotificationUI_Update, (void **)&old_MineWorldNotificationUI_Update);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.NetherWorldNotificationUI_Update), (void *)NetherWorldNotificationUI_Update, (void **)&old_NetherWorldNotificationUI_Update);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.OptionsMenuUI_Update), (void *)OptionsMenuUI_Update, (void **)&old_OptionsMenuUI_Update);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.OutgoingMessages_SendCollectCollectableMessage), (void *)OutgoingMessages_SendCollectCollectableMessage, (void **)&old_OutgoingMessages_SendCollectCollectableMessage);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PixelPerfectCamera_LateUpdate), (void *)PixelPerfectCamera_LateUpdate, (void **)&old_PixelPerfectCamera_LateUpdate);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.Player_CheckInvertedControls), (void *)Player_CheckInvertedControls, (void **)&old_Player_CheckInvertedControls);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.Player_CheckPortals), (void *)Player_CheckPortals, (void **)&old_Player_CheckPortals);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.Player_CheckCheckPoints), (void *)Player_CheckCheckPoints, (void **)&old_Player_CheckCheckPoints);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.Player_CausePoisoned0), (void *)Player_CausePoisoned0, (void **)&old_Player_CausePoisoned0);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.Player_CausePoisoned1), (void *)Player_CausePoisoned1, (void **)&old_Player_CausePoisoned1);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.Player_CausePoisoned2), (void *)Player_CausePoisoned2, (void **)&old_Player_CausePoisoned2);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.Player_HitPlayerFromAIEnemy0), (void *)Player_HitPlayerFromAIEnemy0, (void **)&old_Player_HitPlayerFromAIEnemy0);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.Player_HitPlayerFromAIEnemy1), (void *)Player_HitPlayerFromAIEnemy1, (void **)&old_Player_HitPlayerFromAIEnemy1);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.Player_HitPlayerFromBlock0), (void *)Player_HitPlayerFromBlock0, (void **)&old_Player_HitPlayerFromBlock0);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.Player_HitPlayerFromBlock1), (void *)Player_HitPlayerFromBlock1, (void **)&old_Player_HitPlayerFromBlock1);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.Player_Update), (void *)Player_Update, (void **)&old_Player_Update);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.PlayerData_HasUnlockedRecipe), (void *)PlayerData_HasUnlockedRecipe, (void **)&old_PlayerData_HasUnlockedRecipe);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.ProfanityFilter_Censor), (void *)ProfanityFilter_Censor, (void **)&old_ProfanityFilter_Censor);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.SpeechBubble_Update), (void *)SpeechBubble_Update, (void **)&old_SpeechBubble_Update);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.TitleScreenLogic_Update), (void *)TitleScreenLogic_Update, (void **)&old_TitleScreenLogic_Update);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.TrapProjectile_OnTriggerEnter2D), (void *)TrapProjectile_OnTriggerEnter2D, (void **)&old_TrapProjectile_OnTriggerEnter2D);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.WiringWireController_Update), (void *)WiringWireController_Update, (void **)&old_WiringWireController_Update);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.World_DoesPlayerHaveRightToModifyItemData), (void *)World_DoesPlayerHaveRightToModifyItemData, (void **)&old_World_DoesPlayerHaveRightToModifyItemData);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.WorldController_InstantiateGiftBoxPrizeGameObject), (void *)WorldController_InstantiateGiftBoxPrizeGameObject, (void **)&old_WorldController_InstantiateGiftBoxPrizeGameObject);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.WorldController_KickPlayerByInactivity), (void *)WorldController_KickPlayerByInactivity, (void **)&old_WorldController_KickPlayerByInactivity);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.WorldController_ChangeLighting), (void *)WorldController_ChangeLighting, (void **)&old_WorldController_ChangeLighting);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.WorldController_InstantiateFogOfWar), (void *)WorldController_InstantiateFogOfWar, (void **)&old_WorldController_InstantiateFogOfWar);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.WorldController_LocalPlayerReadyToPlay), (void *)WorldController_LocalPlayerReadyToPlay, (void **)&old_WorldController_LocalPlayerReadyToPlay);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.WorldController_Update), (void *)WorldController_Update, (void **)&old_WorldController_Update);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.WorldController_BlockColliderAndLayerHelper), (void *)WorldController_BlockColliderAndLayerHelper, (void **)&old_WorldController_BlockColliderAndLayerHelper);
        hook((void *) getAbsoluteAddress(UnityIl2cppLib, PixelWorlds.WorldNameChecker_Validate), (void *)WorldNameChecker_Validate, (void **)&old_WorldNameChecker_Validate);
    }
}

#endif
