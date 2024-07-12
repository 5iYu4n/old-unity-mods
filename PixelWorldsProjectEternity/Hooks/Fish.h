#ifndef CSY_FISH_H
#define CSY_FISH_H

float fishingProgress;
float fishPosition;
float targetAreaPosition;
FishSizeSetting currentFishSetting;
int fishCaught = 0;

InventoryKey currentBaitID;

static bool EnableAutoFish = false;
static bool EnableFishInfoLabel = false;
static bool EnableAutoSetBait = false;
static bool EnableAutoFishStrike = false;
static bool EnableAutoPlayFishGame = false;

static bool EnableIgnoreTinyFish = false;
static bool EnableIgnoreSmallFish = false;
static bool EnableIgnoreMediumFish = false;
static bool EnableIgnoreLargeFish = false;
static bool EnableIgnoreHugeFish = false;

static bool ShouldAutoPlayFishGame = false;
static bool CanSkipFishResult = false;
static bool DoOnceFishChance = false;

static float FishingActionDelay = 0.150f;
static float FishingActionTimer = 0.f;

static int ChanceToFishNextFish = 100;

static int reduceChanceForTinyFish = 0;
static int reduceChanceForSmallFish = 0;
static int reduceChanceForMediumFish = 0;
static int reduceChanceForLargeFish = 0;
static int reduceChanceForHugeFish = 0;

static int currentChanceToFish;

void AutoFishing()
{
    if(EnableAutoFish)
    {
        if(LocalPlayerInstantiate != nullptr && MyPlayerData != nullptr && WorldInstantiate != nullptr && WorldControllerInstantiate != nullptr)
        {
            FishingActionTimer += deltaTime;
            Vector2i MyMapPointFishMod = MyMapPoint;
            int GetBlockTypeLeft = World_GetBlockWaterType(WorldInstantiate, MyMapPointFishMod.x - 1, MyMapPointFishMod.y - 1);
            int GetBlockTypeRight = World_GetBlockWaterType(WorldInstantiate, MyMapPointFishMod.x + 1, MyMapPointFishMod.y - 1);
            int FishingState = *(int *)((uint64_t)LocalPlayerInstantiate + PixelWorlds.Player_fishingState);
            fishCaught = *(int *)((uint64_t)WorldControllerInstantiate +PixelWorlds.WorldController_fishBlockType);

            if(currentFishSetting.size != 0)
            {
                if(currentFishSetting.size == 1 && !EnableIgnoreTinyFish)
                {
                    if(DoOnceFishChance)
                    {
                        ChanceToFishNextFish -= reduceChanceForTinyFish;
                        DoOnceFishChance = false;
                    }
                    ShouldAutoPlayFishGame = true;
                }
                else if(currentFishSetting.size == 2 && !EnableIgnoreSmallFish)
                {
                    if(DoOnceFishChance)
                    {
                        ChanceToFishNextFish -= reduceChanceForSmallFish;
                        DoOnceFishChance = false;
                    }
                    ShouldAutoPlayFishGame = true;
                }
                else if(currentFishSetting.size == 3 && !EnableIgnoreMediumFish)
                {
                    if(DoOnceFishChance)
                    {
                        ChanceToFishNextFish -= reduceChanceForMediumFish;
                        DoOnceFishChance = false;
                    }
                    ShouldAutoPlayFishGame = true;
                }
                else if(currentFishSetting.size == 4 && !EnableIgnoreLargeFish)
                {
                    if(DoOnceFishChance)
                    {
                        ChanceToFishNextFish -= reduceChanceForLargeFish;
                        DoOnceFishChance = false;
                    }
                    ShouldAutoPlayFishGame = true;
                }
                else if(currentFishSetting.size == 5 && !EnableIgnoreHugeFish)
                {
                    if(DoOnceFishChance)
                    {
                        ChanceToFishNextFish -= reduceChanceForHugeFish;
                        DoOnceFishChance = false;
                    }
                    ShouldAutoPlayFishGame = true;
                }
                else
                    ShouldAutoPlayFishGame = false;
            }

            monoArray<InventoryKey *> *GetInventoryAsOrderedByInventoryItemType = PlayerData_GetInventoryAsOrderedByInventoryItemType(MyPlayerData);
            for (int i = 0; i < GetInventoryAsOrderedByInventoryItemType->getLength(); ++i)
            {
                InventoryKey GetInventoryAsOrderedByInventoryItem = GetInventoryAsOrderedByInventoryItemType->getPointer()[i];
                if(ConfigData_IsFishingLure(GetInventoryAsOrderedByInventoryItem.blockType))
                {
                    currentBaitID = GetInventoryAsOrderedByInventoryItem;
                }
            }
            if(EnableAutoSetBait && FishingState == 0) //No Fishing State
            {
                if(FishingActionTimer >= FishingActionDelay)
                {
                    if(ConfigData_IsBlockFishingWater(GetBlockTypeLeft))
                    {
                        currentChanceToFish = rand() % 100;
                        *(int *)((uint64_t)WorldControllerInstantiate +PixelWorlds.WorldController_fishBlockType) = 0;
                        DoOnceFishChance = true;
                        CanSkipFishResult = true;
                        currentFishSetting = FishSizeSetting();
                        WorldController_SetBaitWithTool(WorldControllerInstantiate, currentBaitID.blockType, Vector2i{MyMapPointFishMod.x - 1, MyMapPointFishMod.y - 1}, 0.0f);
                        FishingActionTimer = 0.f;
                    }
                    else if(ConfigData_IsBlockFishingWater(GetBlockTypeRight))
                    {
                        currentChanceToFish = rand() % 100 + 1;
                        *(int *)((uint64_t)WorldControllerInstantiate +PixelWorlds.WorldController_fishBlockType) = 0;
                        DoOnceFishChance = true;
                        CanSkipFishResult = true;
                        currentFishSetting = FishSizeSetting();
                        WorldController_SetBaitWithTool(WorldControllerInstantiate, currentBaitID.blockType, Vector2i{MyMapPointFishMod.x - 1, MyMapPointFishMod.y - 1}, 0.0f);
                        FishingActionTimer = 0.f;
                    }
                }
            }
            else if(EnableAutoFishStrike && Player_IsFishStrikeActive(LocalPlayerInstantiate))
            {
                if(FishingActionTimer >= FishingActionDelay)
                {
                    GameplayUI_OnButtonDownNew(GameplayUIInstantiate, 4);
                    FishingActionTimer = 0.f;
                }
            }
            else if(EnableAutoPlayFishGame && FishingState == 3 && ShouldAutoPlayFishGame)
            {
                if(currentChanceToFish < ChanceToFishNextFish)
                {
                    if(fishingProgress >= 1.0f && FishingActionTimer >= FishingActionDelay)
                    {
                        FishingGaugeMinigameUI_LandButtonPressed(FishingGaugeMinigameUIInstantiate);
                        FishingActionTimer = 0.f;
                    }
                    else
                    {
                        if(fishPosition < targetAreaPosition)
                        {
                            *(bool *)((uint64_t)LocalPlayerInstantiate + PixelWorlds.Player_fishingLeftButton) = true;
                        }
                        else
                        {
                            *(bool *)((uint64_t)LocalPlayerInstantiate + PixelWorlds.Player_fishingRightButton) = true;
                        }
                    }
                }
                else
                {
                    ChanceToFishNextFish = 100;
                }
            }
        }
    }
    else
    {
        currentBaitID = InventoryKey();
        ChanceToFishNextFish = 100;
    }
}

void DrawFishMenu()
{
    if (EnableFishInfoLabel)
    {
        ImGui::Begin(OBFUSCATE("Fish Info Label"), &EnableFishInfoLabel, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
        ImGui::Text(OBFUSCATE("Current Bait: %s"), blockTypeToString[currentBaitID.blockType]);
        ImGui::Text(OBFUSCATE("Fish Chance: %d"), ChanceToFishNextFish);
        ImGui::Text(OBFUSCATE("Fail To Catch Chance: %d"), currentChanceToFish);
        ImGui::Text(OBFUSCATE("Current Fish: %s"), blockTypeToString[fishCaught]);
        ImGui::Text(OBFUSCATE("Fish Size: %s"), FishSizesToString[currentFishSetting.size]);
        currentBaitID = InventoryKey();
        ImGui::End();
    }
}

#endif
