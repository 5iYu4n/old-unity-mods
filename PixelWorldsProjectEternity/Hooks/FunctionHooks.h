#ifndef FUNCTIONHOOKS_H
#define FUNCTIONHOOKS_H

void *(*Component_get_transform)(void *instance);
void *(*Component_get_gameObject)(void *instance);
monoString *(*Object_get_name)(void *instance);

void *(*Transform_GetChild)(void *instance, int index);
int (*Transform_get_childCount)(void *instance);
Vector3 (*Transform_get_position)(void *instance);
void (*Transform_set_position)(void *instance, Vector3 newPos);

void *(*BSONObject_get_Item)(void *instance, monoString *value);
monoString *(*BSONValue_get_stringValue)(void *instance);

void (*Application_set_targetFrameRate)(int value);

void (*TMP_Text_SetText)(void *instance, monoString *string);

int (*Screen_get_height)();
int (*Screen_get_width)();

void (*AIBase_OnDeath)(void *instance);
int (*AIBase_GetCurrentAIBehaviorType)(void *instance);

bool (*AIEnemyMonoBehaviourBase_GetIsActive)(void *instance);

void (*ChatUI_WarpToWorld)(void *instance, monoString *world, int channel);

bool (*ConfigData_IsBlockFamiliar)(int blockType);
bool (*ConfigData_IsBlockPortal)(int blockType);
bool (*ConfigData_DoesBlockHaveCollider)(int blockType);
int (*ConfigData_GetBlockSortingLayerType)(int blockType);
bool (*ConfigData_IsBlockInstakill)(int blockType);
bool (*ConfigData_IsBlockFishingWater)(int blockType);
bool (*ConfigData_IsBlockWater)(int blockType);
bool (*ConfigData_IsFishingLure)(int blockType);
bool (*ConfigData_IsMiningNugget)(int blockType);
bool (*ConfigData_IsFish)(int blockType);
int (*ConfigData_GetFishRecycleValueForFishRecycler)(int blockType);
bool (*ConfigData_IsBlockMiningGemstone)(int blockType);
int (*ConfigData_GetGemstoneRecycleValueForMiningGemstoneRecycler)(int blockType);
bool (*ConfigData_IsConsumableTreasurePouch)(int blockType);
int (*ConfigData_GetTreasurePouchRewardAmount)(int blockType);
bool (*ConfigData_IsBlockButterflyEventItem)(int blocktype);
int (*ConfigData_GetMaxHitPoints)(int enemyType);
int (*ConfigData_GetBlockTypeInventoryItemType)(int blockType);

DateTime (*EventDates_GetMiniEventNextStartTime)(int miniEvent);
DateTime (*EventDates_GetEventStartDateTime)(int evt, bool getNext);
DateTime (*EventDates_GetEventStartDateTimeExtra)(int evt, bool getNext);

void (*FishingGaugeMinigameUI_LandButtonPressed)(void *instance);

void (*FishingResultsPopupUI_HardwareBackButtonPressed)(void *instance);

void (*GameplayUI_OnButtonDownNew)(void *instance, int button);
void (*GameplayUI_SettingsButtonClicked)(void *instance);

InventoryKey (*InventoryControl_GetCurrentSelection)(void *instance);

monoList<ItemPack *> *(*ItemPacks_GetItemPacksList)(monoString *Category);

DateTime (*KukouriTime_Get)();

void (*MainMenuLogic_JoinRandomWorldFromMainMenu)(void *instance);
void (*MainMenuLogic_LogOut)(void *instance);
bool (*MainMenuShopLogic_IsInMainMenu)(void *instance);

void (*OutgoingMessages_SendHitBlockBackgroundMessage)(Vector2i mapPoint, DateTime hitTime);
void (*OutgoingMessages_SendHitBlockWaterMessage)(Vector2i mapPoint, DateTime hitTime);
void (*OutgoingMessages_SendSetBlockMessage)(Vector2i mapPoint, int blockType);
void (*OutgoingMessages_SendSetBlockBackgroundMessage)(Vector2i mapPoint, int blockType);
void (*OutgoingMessages_SendSetBlockWaterMessage)(Vector2i mapPoint, int blockType);
void (*OutgoingMessages_ConvertItems)(InventoryKey sourceItem);
void (*OutgoingMessages_BuyItemPack)(monoString *itemPackId);
void (*OutgoingMessages_SendHitAirMessage)(Vector2i mapPoint);
void (*OutgoingMessages_SendHitSpiritMessage)(Vector2i mapPoint);
void (*OutgoingMessages_SendSpinMiningRouletteMessage)();
void (*OutgoingMessages_SendSpinJetRaceRouletteMessage)();
void (*OutgoingMessages_SendUsePotionMessage)(int blockType);
void (*OutgoingMessages_MiningPickaxeRepairing)(InventoryKey miningPickaxeRepairingIK);
void (*OutgoingMessages_SendRequestGeneratedMineExitMessage)(Vector2i mapPoint);
void (*OutgoingMessages_SendRequestItemFromGiftBoxMessage)(Vector2i mapPoint);
void (*OutgoingMessages_SendHitBlockMessage)(Vector2i mapPoint, DateTime hitTime, bool doNotDestroy);
void (*OutgoingMessages_SendHitAIEnemyMessage)(Vector2i mapPoint, int aiID);

void (*Player_GoFromPortal)(void *instance, Vector2i mapPoint);
void (*Player_ChangeWearableRemote)(void *instance, int animationHotSpot, int blockType);
void (*Player_SetVelocity)(void *instance, Vector3 newVelocity);
bool (*Player_IsFishStrikeActive)(void *instance);
void (*Player_ChangeFamiliarRemote)(void *instance, int blockType, monoString *name, bool isMax);

InventoryKey (*PlayerData_GetBeltItem)(void *instance);
void (*PlayerData_AddItemToInventory)(void *instance, int blockType, int itemType, short amount);
void (*PlayerData_RemoveItemsFromInventory)(void *instance, InventoryKey inventoryKey, short amount);
monoArray<InventoryKey *> *(*PlayerData_GetInventoryAsOrderedByInventoryItemType)(void *instance);
int (*PlayerData_GetInventorySize)(void *instance);
void *(*PlayerData_GetInventoryData)(void *instance, InventoryKey inventoryKey);
short (*PlayerData_GetCount)(void *instance, InventoryKey inventoryKey);
int (*PlayerData_GetMaxHitPoints)(void *instance);
monoList<void **> *(*PlayerData_GetPlayerWearWerablesAndWeaponInventoryDatas)(void *instance);

void (*SceneLoader_ReloadGame)();

Vector2i (*Spirit_GetCurrentMapPoint)(void *instance);

int (*WeaponPickaxeCrappyInventoryData_GetDurability)(void *instance);
int (*WeaponPickaxeFlimsyInventoryData_GetDurability)(void *instance);
int (*WeaponPickaxeBasicInventoryData_GetDurability)(void *instance);
int (*WeaponPickaxeSturdyInventoryData_GetDurability)(void *instance);
int (*WeaponPickaxeHeavyInventoryData_GetDurability)(void *instance);
int (*WeaponPickaxeMasterInventoryData_GetDurability)(void *instance);
int (*WeaponPickaxeEpicInventoryData_GetDurability)(void *instance);
int (*WeaponPickaxeDarkInventoryData_GetDurability)(void *instance);

monoArray<int *> *(*WearableHotSpotsValidity_GetWearableHotSpots)(int blockType);

void *(*World_GetWorldItemData)(void *instance, int positionX, int positionY);
int (*World_GetBlockType)(void *instance, int positionX, int positionY);
int (*World_GetBlockWaterType)(void *instance, int positionX, int positionY);
int (*World_GetBlockBackgroundType)(void *instance, int positionX, int positionY);

void (*WorldController_DestroyBlockSpriteOrQuad)(void *instance, int x, int y);
void (*WorldController_DestroyBlockBackgroundSpriteOrQuad)(void *instance, int x, int y);
void (*WorldController_DestroyBlockWaterSpriteOrQuad)(void *instance, int x, int y);
bool (*WorldController_SetBaitWithTool)(void *instance, int currentSelectedBlockType, Vector2i mapPoint, float timeToWait);
void (*WorldController_DropStuffFromInventory)(void *instance, Vector2i mapPoint, InventoryKey inventoryKey, short amount, void *inventoryData);
void (*WorldController_SetBlock)(void *instance, int blockType, int positionX, int positionY);
void (*WorldController_SetBlockBackground)(void *instance, int blockType, int positionX, int positionY);
void (*WorldController_SetBlockWater)(void *instance, int blockType, int positionX, int positionY);

//Item Data
monoString *(*VortexPortalData_GetName)(void *instance);
bool (*VortexPortalData_GetIsLocked)(void *instance);
monoString *(*VortexPortalData_GetEntryPointID)(void *instance);
monoString *(*VortexPortalData_GetTargetWorldID)(void *instance);
monoString *(*VortexPortalData_GetTargetEntryPointID)(void *instance);

monoString *(*PortalData_GetName)(void *instance);
bool (*PortalData_GetIsLocked)(void *instance);
monoString *(*PortalData_GetEntryPointID)(void *instance);
monoString *(*PortalData_GetTargetWorldID)(void *instance);
monoString *(*PortalData_GetTargetEntryPointID)(void *instance);

monoString *(*LockSmallData_GetPlayerWhoOwnsLockId)(void *instance);
monoString *(*LockSmallData_GetPlayerWhoOwnsLockName)(void *instance);
bool (*LockSmallData_GetIsOpen)(void *instance);
bool (*LockSmallData_GetIgnoreEmptyArea)(void *instance);
monoList<monoString **> *(*LockSmallData_GetPlayersWhoHaveAccessToLock)(void *instance);
monoList<monoString **> *(*LockSmallData_GetPlayersWhoHaveMinorAccessToLock)(void *instance);
DateTime (*LockSmallData_GetLastActivatedTime)(void *instance);

monoString *(*LockMediumData_GetPlayerWhoOwnsLockId)(void *instance);
monoString *(*LockMediumData_GetPlayerWhoOwnsLockName)(void *instance);
bool (*LockMediumData_GetIsOpen)(void *instance);
bool (*LockMediumData_GetIgnoreEmptyArea)(void *instance);
monoList<monoString **> *(*LockMediumData_GetPlayersWhoHaveAccessToLock)(void *instance);
monoList<monoString **> *(*LockMediumData_GetPlayersWhoHaveMinorAccessToLock)(void *instance);
DateTime (*LockMediumData_GetLastActivatedTime)(void *instance);

monoString *(*LockLargeData_GetPlayerWhoOwnsLockId)(void *instance);
monoString *(*LockLargeData_GetPlayerWhoOwnsLockName)(void *instance);
bool (*LockLargeData_GetIsOpen)(void *instance);
bool (*LockLargeData_GetIgnoreEmptyArea)(void *instance);
monoList<monoString **> *(*LockLargeData_GetPlayersWhoHaveAccessToLock)(void *instance);
monoList<monoString **> *(*LockLargeData_GetPlayersWhoHaveMinorAccessToLock)(void *instance);
DateTime (*LockLargeData_GetLastActivatedTime)(void *instance);

monoString *(*LockWorldData_GetPlayerWhoOwnsLockId)(void *instance);
monoString *(*LockWorldData_GetPlayerWhoOwnsLockName)(void *instance);
bool (*LockWorldData_GetIsOpen)(void *instance);
bool (*LockWorldData_GetIsPunchingAllowed)(void *instance);
monoList<monoString **> *(*LockWorldData_GetPlayersWhoHaveAccessToLock)(void *instance);
monoList<monoString **> *(*LockWorldData_GetPlayersWhoHaveMinorAccessToLock)(void *instance);
DateTime (*LockWorldData_GetLastActivatedTime)(void *instance);

monoString *(*LockClanData_GetPlayerWhoOwnsLockId)(void *instance);
monoString *(*LockClanData_GetPlayerWhoOwnsLockName)(void *instance);
bool (*LockClanData_GetIsOpen)(void *instance);
bool (*LockClanData_GetIsPunchingAllowed)(void *instance);
monoList<monoString **> *(*LockClanData_GetPlayersWhoHaveAccessToLock)(void *instance);
monoList<monoString **> *(*LockClanData_GetPlayersWhoHaveMinorAccessToLock)(void *instance);
DateTime (*LockClanData_GetLastActivatedTime)(void *instance);

monoString *(*LockPlatinumData_GetPlayerWhoOwnsLockId)(void *instance);
monoString *(*LockPlatinumData_GetPlayerWhoOwnsLockName)(void *instance);
bool (*LockPlatinumData_GetIsOpen)(void *instance);
bool (*LockPlatinumData_GetIsPunchingAllowed)(void *instance);
monoList<monoString **> *(*LockPlatinumData_GetPlayersWhoHaveAccessToLock)(void *instance);
monoList<monoString **> *(*LockPlatinumData_GetPlayersWhoHaveMinorAccessToLock)(void *instance);
DateTime (*LockPlatinumData_GetLastActivatedTime)(void *instance);

monoString *(*LockWorldDarkData_GetPlayerWhoOwnsLockId)(void *instance);
monoString *(*LockWorldDarkData_GetPlayerWhoOwnsLockName)(void *instance);
bool (*LockWorldDarkData_GetIsOpen)(void *instance);
bool (*LockWorldDarkData_GetIsPunchingAllowed)(void *instance);
monoList<monoString **> *(*LockWorldDarkData_GetPlayersWhoHaveAccessToLock)(void *instance);
monoList<monoString **> *(*LockWorldDarkData_GetPlayersWhoHaveMinorAccessToLock)(void *instance);
DateTime (*LockWorldDarkData_GetLastActivatedTime)(void *instance);

monoString *(*LockWorldBattleData_GetPlayerWhoOwnsLockId)(void *instance);
monoString *(*LockWorldBattleData_GetPlayerWhoOwnsLockName)(void *instance);
bool (*LockWorldBattleData_GetIsOpen)(void *instance);
bool (*LockWorldBattleData_GetIsPunchingAllowed)(void *instance);
bool (*LockWorldBattleData_GetIsBattleOn)(void *instance);
monoList<monoString **> *(*LockWorldBattleData_GetPlayersWhoHaveAccessToLock)(void *instance);
monoList<monoString **> *(*LockWorldBattleData_GetPlayersWhoHaveMinorAccessToLock)(void *instance);
DateTime (*LockWorldBattleData_GetLastActivatedTime)(void *instance);

monoString *(*LockBattleData_GetPlayerWhoOwnsLockId)(void *instance);
monoString *(*LockBattleData_GetPlayerWhoOwnsLockName)(void *instance);
bool (*LockBattleData_GetIsOpen)(void *instance);
bool (*LockBattleData_GetIgnoreEmptyArea)(void *instance);
bool (*LockBattleData_GetIsBattleOn)(void *instance);
monoList<monoString **> *(*LockBattleData_GetPlayersWhoHaveAccessToLock)(void *instance);
monoList<monoString **> *(*LockBattleData_GetPlayersWhoHaveMinorAccessToLock)(void *instance);
DateTime (*LockBattleData_GetLastActivatedTime)(void *instance);

monoString *(*LockWorldNoobData_GetPlayerWhoOwnsLockId)(void *instance);
monoString *(*LockWorldNoobData_GetPlayerWhoOwnsLockName)(void *instance);
bool (*LockWorldNoobData_GetIsOpen)(void *instance);
bool (*LockWorldNoobData_GetIsPunchingAllowed)(void *instance);
monoList<monoString **> *(*LockWorldNoobData_GetPlayersWhoHaveAccessToLock)(void *instance);
monoList<monoString **> *(*LockWorldNoobData_GetPlayersWhoHaveMinorAccessToLock)(void *instance);
DateTime (*LockWorldNoobData_GetLastActivatedTime)(void *instance);

monoString *(*PortalPasswordData_GetName)(void *instance);
bool (*PortalPasswordData_GetIsLocked)(void *instance);
monoString *(*PortalPasswordData_GetEntryPointID)(void *instance);
monoString *(*PortalPasswordData_GetTargetWorldID)(void *instance);
monoString *(*PortalPasswordData_GetTargetEntryPointID)(void *instance);

monoString *(*LockBattleFactionData_GetPlayerWhoOwnsLockId)(void *instance);
monoString *(*LockBattleFactionData_GetPlayerWhoOwnsLockName)(void *instance);
bool (*LockBattleFactionData_GetIsOpen)(void *instance);
bool (*LockBattleFactionData_GetIgnoreEmptyArea)(void *instance);
bool (*LockBattleFactionData_GetIsBattleOn)(void *instance);
monoList<monoString **> *(*LockBattleFactionData_GetPlayersWhoHaveAccessToLock)(void *instance);
monoList<monoString **> *(*LockBattleFactionData_GetPlayersWhoHaveMinorAccessToLock)(void *instance);
DateTime (*LockBattleFactionData_GetLastActivatedTime)(void *instance);

monoString *(*LockWorldBattleFactionData_GetPlayerWhoOwnsLockId)(void *instance);
monoString *(*LockWorldBattleFactionData_GetPlayerWhoOwnsLockName)(void *instance);
bool (*LockWorldBattleFactionData_GetIsOpen)(void *instance);
bool (*LockWorldBattleFactionData_GetIsPunchingAllowed)(void *instance);
bool (*LockWorldBattleFactionData_GetIsBattleOn)(void *instance);
monoList<monoString **> *(*LockWorldBattleFactionData_GetPlayersWhoHaveAccessToLock)(void *instance);
monoList<monoString **> *(*LockWorldBattleFactionData_GetPlayersWhoHaveMinorAccessToLock)(void *instance);
DateTime (*LockWorldBattleFactionData_GetLastActivatedTime)(void *instance);

monoString *(*AnniversaryPortalData_GetName)(void *instance);
bool (*AnniversaryPortalData_GetIsLocked)(void *instance);
monoString *(*AnniversaryPortalData_GetEntryPointID)(void *instance);
monoString *(*AnniversaryPortalData_GetTargetWorldID)(void *instance);
monoString *(*AnniversaryPortalData_GetTargetEntryPointID)(void *instance);

monoString *(*PortalWOTWData_GetName)(void *instance);
bool (*PortalWOTWData_GetIsLocked)(void *instance);
monoString *(*PortalWOTWData_GetEntryPointID)(void *instance);
monoString *(*PortalWOTWData_GetTargetWorldID)(void *instance);
monoString *(*PortalWOTWData_GetTargetEntryPointID)(void *instance);

monoString *(*NetherGroupPortalData_GetName)(void *instance);
bool (*NetherGroupPortalData_GetIsLocked)(void *instance);
monoString *(*NetherGroupPortalData_GetEntryPointID)(void *instance);
monoString *(*NetherGroupPortalData_GetTargetWorldID)(void *instance);
monoString *(*NetherGroupPortalData_GetTargetEntryPointID)(void *instance);

monoString *(*LabEnterPortalData_GetName)(void *instance);
bool (*LabEnterPortalData_GetIsLocked)(void *instance);
monoString *(*LabEnterPortalData_GetEntryPointID)(void *instance);
monoString *(*LabEnterPortalData_GetTargetWorldID)(void *instance);
monoString *(*LabEnterPortalData_GetTargetEntryPointID)(void *instance);

monoString *(*LabExitPortalData_GetName)(void *instance);
bool (*LabExitPortalData_GetIsLocked)(void *instance);
monoString *(*LabExitPortalData_GetEntryPointID)(void *instance);
monoString *(*LabExitPortalData_GetTargetWorldID)(void *instance);
monoString *(*LabExitPortalData_GetTargetEntryPointID)(void *instance);

monoString *(*BluePortalData_GetName)(void *instance);
bool (*BluePortalData_GetIsLocked)(void *instance);
monoString *(*BluePortalData_GetEntryPointID)(void *instance);
monoString *(*BluePortalData_GetTargetWorldID)(void *instance);
monoString *(*BluePortalData_GetTargetEntryPointID)(void *instance);

monoString *(*TutorialCablePortalData_GetName)(void *instance);
bool (*TutorialCablePortalData_GetIsLocked)(void *instance);
monoString *(*TutorialCablePortalData_GetEntryPointID)(void *instance);
monoString *(*TutorialCablePortalData_GetTargetWorldID)(void *instance);
monoString *(*TutorialCablePortalData_GetTargetEntryPointID)(void *instance);

monoString *(*RiftPortalData_GetName)(void *instance);
bool (*RiftPortalData_GetIsLocked)(void *instance);
monoString *(*RiftPortalData_GetEntryPointID)(void *instance);
monoString *(*RiftPortalData_GetTargetWorldID)(void *instance);
monoString *(*RiftPortalData_GetTargetEntryPointID)(void *instance);

monoString *(*PortalFactionDarkData_GetName)(void *instance);
bool (*PortalFactionDarkData_GetIsLocked)(void *instance);
monoString *(*PortalFactionDarkData_GetEntryPointID)(void *instance);
monoString *(*PortalFactionDarkData_GetTargetWorldID)(void *instance);
monoString *(*PortalFactionDarkData_GetTargetEntryPointID)(void *instance);

monoString *(*PortalFactionLightData_GetName)(void *instance);
bool (*PortalFactionLightData_GetIsLocked)(void *instance);
monoString *(*PortalFactionLightData_GetEntryPointID)(void *instance);
monoString *(*PortalFactionLightData_GetTargetWorldID)(void *instance);
monoString *(*PortalFactionLightData_GetTargetEntryPointID)(void *instance);

monoString *(*PortalCrypticData_GetName)(void *instance);
bool (*PortalCrypticData_GetIsLocked)(void *instance);
monoString *(*PortalCrypticData_GetEntryPointID)(void *instance);
monoString *(*PortalCrypticData_GetTargetWorldID)(void *instance);
monoString *(*PortalCrypticData_GetTargetEntryPointID)(void *instance);

monoString *(*PortalPixelMinesData_GetName)(void *instance);
bool (*PortalPixelMinesData_GetIsLocked)(void *instance);
monoString *(*PortalPixelMinesData_GetEntryPointID)(void *instance);
monoString *(*PortalPixelMinesData_GetTargetWorldID)(void *instance);
monoString *(*PortalPixelMinesData_GetTargetEntryPointID)(void *instance);

monoString *(*PortalMineExitData_GetName)(void *instance);
bool (*PortalMineExitData_GetIsLocked)(void *instance);
monoString *(*PortalMineExitData_GetEntryPointID)(void *instance);
monoString *(*PortalMineExitData_GetTargetWorldID)(void *instance);
monoString *(*PortalMineExitData_GetTargetEntryPointID)(void *instance);

monoString *(*PortalMiningEntryData_GetName)(void *instance);
bool (*PortalMiningEntryData_GetIsLocked)(void *instance);
monoString *(*PortalMiningEntryData_GetEntryPointID)(void *instance);
monoString *(*PortalMiningEntryData_GetTargetWorldID)(void *instance);
monoString *(*PortalMiningEntryData_GetTargetEntryPointID)(void *instance);

monoString *(*JetRaceGroupPortalData_GetName)(void *instance);
bool (*JetRaceGroupPortalData_GetIsLocked)(void *instance);
monoString *(*JetRaceGroupPortalData_GetEntryPointID)(void *instance);
monoString *(*JetRaceGroupPortalData_GetTargetWorldID)(void *instance);
monoString *(*JetRaceGroupPortalData_GetTargetEntryPointID)(void *instance);

bool (*QuantumSafeData_GetIsSomethingIn)(void *instance);
int (*QuantumSafeData_GetNumberOfItems)(void *instance);
InventoryKey (*QuantumSafeData_GetInventoryKeyOfSlot)(void *instance, int zeroBasedSlotNumber);
short (*QuantumSafeData_GetInventoryAmountOfSlot)(void *instance, int zeroBasedSlotNumber);

bool (*SafeData_GetIsSomethingIn)(void *instance);
int (*SafeData_GetNumberOfItems)(void *instance);
InventoryKey (*SafeData_GetInventoryKeyOfSlot)(void *instance, int zeroBasedSlotNumber);
short (*SafeData_GetInventoryAmountOfSlot)(void *instance, int zeroBasedSlotNumber);

bool (*SmallChestBlackGoldData_GetIsSomethingIn)(void *instance);
int (*SmallChestBlackGoldData_GetNumberOfItems)(void *instance);
InventoryKey (*SmallChestBlackGoldData_GetInventoryKeyOfSlot)(void *instance, int zeroBasedSlotNumber);
short (*SmallChestBlackGoldData_GetInventoryAmountOfSlot)(void *instance, int zeroBasedSlotNumber);

bool (*SmallChestData_GetIsSomethingIn)(void *instance);
int (*SmallChestData_GetNumberOfItems)(void *instance);
InventoryKey (*SmallChestData_GetInventoryKeyOfSlot)(void *instance, int zeroBasedSlotNumber);
short (*SmallChestData_GetInventoryAmountOfSlot)(void *instance, int zeroBasedSlotNumber);

bool (*TinyChestData_GetIsSomethingIn)(void *instance);
int (*TinyChestData_GetNumberOfItems)(void *instance);
InventoryKey (*TinyChestData_GetInventoryKeyOfSlot)(void *instance, int zeroBasedSlotNumber);
short (*TinyChestData_GetInventoryAmountOfSlot)(void *instance, int zeroBasedSlotNumber);

bool (*BloodyChestData_GetIsSomethingIn)(void *instance);
int (*BloodyChestData_GetNumberOfItems)(void *instance);
InventoryKey (*BloodyChestData_GetInventoryKeyOfSlot)(void *instance, int zeroBasedSlotNumber);
short (*BloodyChestData_GetInventoryAmountOfSlot)(void *instance, int zeroBasedSlotNumber);

bool (*AlienChestData_GetIsSomethingIn)(void *instance);
int (*AlienChestData_GetNumberOfItems)(void *instance);
InventoryKey (*AlienChestData_GetInventoryKeyOfSlot)(void *instance, int zeroBasedSlotNumber);
short (*AlienChestData_GetInventoryAmountOfSlot)(void *instance, int zeroBasedSlotNumber);

#include "GodMod.h"
#include "Monster.h"
#include "Nether.h"
#include "Halloween.h"
#include "Mine.h"
#include "AutoHealing.h"
#include "AutoSpin.h"
#include "InventoryController.h"
#include "Hero.h"
#include "JetRace.h"
#include "VisualWearable.h"
#include "GemCounter.h"
//#include "Teleportation.h"
#include "PackOpening.h"
#include "Fish.h"
#include "AutoFarm.h"
#include "ItemData.h"
//#include "PortalTP.h"
#include "VisualWorld.h"

#include "BaseMenuUI.h"
#include "ChatUI.h"
#include "ConfigData.h"
#include "EventDates.h"
#include "FishingGaugeMinigameUI.h"
#include "GameplayUI.h"
#include "InventoryControl.h"
#include "MainMenuLogic.h"
#include "OptionsMenuUI.h"
#include "OutgoingMessages.h"
#include "MineWorldNotificationUI.h"
#include "NetherWorldNotificationUI.h"
#include "PixelPerfectCamera.h"
#include "Player.h"
#include "PlayerData.h"
#include "ProfanityFilter.h"
#include "Spirit.h"
#include "SpeechBubble.h"
#include "TitleScreenLogic.h"
#include "WiringWireController.h"
#include "World.h"
#include "WorldController.h"
#include "WorldNameChecker.h"

#include "ESP.h"

#endif
