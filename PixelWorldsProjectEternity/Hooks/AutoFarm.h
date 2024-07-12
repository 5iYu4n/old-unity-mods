#ifndef CSY_AUTOFARM_H
#define CSY_AUTOFARM_H

static bool EnableAutoFarm = false;
static bool EnableAutoFarmInfoLabel = false;
static bool EnableAutoDropSeed = false;
static int SetSeedAmountBeforeDrop = 900;
static int SetBlockPercentBeforeStop = 80;
static float dropActionDelay = 0.3f;
static float dropActionTimer = 0.f;
static bool DoSaveSeedToDrop = false;

InventoryKey currentSelectedBlockType = InventoryKey();
InventoryKey currentSelectedSeedToDrop = InventoryKey();

static bool doOnceCheckIfClear = false;
static bool doClearOnceFarm = false;
static bool doDropOnceInFarm = false;

static float farmActionTimer = 0.f;
static float farmActionDelay = 0.180f;
static float putActionDelay = 0.190f;

static int RepeatPutAndBreak = 7;
static int InitRepeatPutAndBreak = 0;

Vector2i AutoBreakStartPoint = Vector2i{};

int GetBlockCategory(InventoryKey block)
{
    if(ConfigData_GetBlockSortingLayerType(block.blockType) == 35)
    {
        return 1;
    }
    else if(ConfigData_GetBlockSortingLayerType(block.blockType) == 2)
    {
        return 2;
    }
    else if(ConfigData_DoesBlockHaveCollider(block.blockType))
    {
        return 3;
    }
}

int GetMapPointCollectableAmount(Vector2i MapPoint)
{
    if(collectables != nullptr)
    {
        int currentCollectableMapPointCount = 0;
        for (int i = 0; i < collectables->getSize(); ++i) {
            void *collectable = collectables->getItems()[i];
            if(collectable != nullptr)
            {
                Vector2i mapPoint = *(Vector2i *)((uint64_t)collectable + PixelWorlds.CollectableData_mapPoint);
                if(MapPoint == mapPoint)
                {
                    currentCollectableMapPointCount ++;
                }
            }
        }
        return (currentCollectableMapPointCount * 100)/30;
    }
}

bool CheckIfThereIsBlock(int posX, int posY)
{
    if(World_GetBlockType(WorldInstantiate, posX, posY) != 0)
    {
        return true;
    }
    else if(World_GetBlockBackgroundType(WorldInstantiate, posX, posY) != 0)
    {
        return true;
    }
    else if(World_GetBlockWaterType(WorldInstantiate, posX, posY) != 0)
    {
        return true;
    }
    return false;
}

void AutoPutBlock(int posX, int posY, InventoryKey block)
{
    if(GetBlockCategory(block) == 1)
    {
        if(farmActionTimer >= putActionDelay)
        {
            farmActionTimer = 0.f;
            OutgoingMessages_SendSetBlockWaterMessage(Vector2i{posX, posY}, block.blockType);
            PlayerData_RemoveItemsFromInventory(MyPlayerData, block, 1);
        }
    }
    else if(GetBlockCategory(block) == 2)
    {
        if(farmActionTimer >= putActionDelay)
        {
            farmActionTimer = 0.f;
            OutgoingMessages_SendSetBlockBackgroundMessage(Vector2i{posX, posY}, block.blockType);
            PlayerData_RemoveItemsFromInventory(MyPlayerData, block, 1);
        }
    }
    else if(GetBlockCategory(block) == 3)
    {
        if(farmActionTimer >= putActionDelay)
        {
            farmActionTimer = 0.f;
            OutgoingMessages_SendSetBlockMessage(Vector2i{posX, posY}, block.blockType);
            PlayerData_RemoveItemsFromInventory(MyPlayerData, block, 1);
        }
    }
}

void AutoBreak(int posX, int posY, InventoryKey block)
{
    if(GetBlockCategory(block) == 1)
    {
        if(farmActionTimer >= farmActionDelay)
        {
            farmActionTimer = 0.0f;
            OutgoingMessages_SendHitBlockWaterMessage(Vector2i{posX, posY}, DateTime{0});
        }
    }
    else if(GetBlockCategory(block) == 2)
    {
        if(farmActionTimer >= farmActionDelay)
        {
            farmActionTimer = 0.0f;
            OutgoingMessages_SendHitBlockBackgroundMessage(Vector2i{posX, posY}, DateTime{0});
        }
    }
    else if(GetBlockCategory(block) == 3)
    {
        if(farmActionTimer >= farmActionDelay)
        {
            farmActionTimer = 0.0f;
            OutgoingMessages_SendHitBlockMessage(Vector2i{posX, posY}, DateTime{0}, false);
        }
    }
}

bool FullyAutoFarmClear()
{
    if(CheckIfThereIsBlock(AutoBreakStartPoint.x - 2, AutoBreakStartPoint.y + 2))
    {
        return false;
    }
    else if(CheckIfThereIsBlock(AutoBreakStartPoint.x - 1, AutoBreakStartPoint.y + 2))
    {
        return false;
    }
    else if(CheckIfThereIsBlock(AutoBreakStartPoint.x, AutoBreakStartPoint.y + 2))
    {
        return false;
    }
    else if(CheckIfThereIsBlock(AutoBreakStartPoint.x + 1, AutoBreakStartPoint.y + 2))
    {
        return false;
    }
    else if(CheckIfThereIsBlock(AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y + 2))
    {
        return false;
    }
    //2
    else if(CheckIfThereIsBlock(AutoBreakStartPoint.x - 2, AutoBreakStartPoint.y + 1))
    {
        return false;
    }
    else if(CheckIfThereIsBlock(AutoBreakStartPoint.x - 1, AutoBreakStartPoint.y + 1))
    {
        return false;
    }
    else if(CheckIfThereIsBlock(AutoBreakStartPoint.x, AutoBreakStartPoint.y + 1))
    {
        return false;
    }
    else if(CheckIfThereIsBlock(AutoBreakStartPoint.x + 1, AutoBreakStartPoint.y + 1))
    {
        return false;
    }
    else if(CheckIfThereIsBlock(AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y + 1))
    {
        return false;
    }
    //3
    else if(CheckIfThereIsBlock(AutoBreakStartPoint.x - 2, AutoBreakStartPoint.y))
    {
        return false;
    }
    else if(CheckIfThereIsBlock(AutoBreakStartPoint.x - 1, AutoBreakStartPoint.y))
    {
        return false;
    }
    else if(CheckIfThereIsBlock(AutoBreakStartPoint.x + 1, AutoBreakStartPoint.y))
    {
        return false;
    }
    else if(CheckIfThereIsBlock(AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y))
    {
        return false;
    }
    //4
    else if(CheckIfThereIsBlock(AutoBreakStartPoint.x - 2, AutoBreakStartPoint.y - 1))
    {
        return false;
    }
    else if(CheckIfThereIsBlock(AutoBreakStartPoint.x - 1, AutoBreakStartPoint.y - 1))
    {
        return false;
    }
    else if(CheckIfThereIsBlock(AutoBreakStartPoint.x + 1, AutoBreakStartPoint.y - 1))
    {
        return false;
    }
    else if(CheckIfThereIsBlock(AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y - 1))
    {
        return false;
    }
    //5
    else if(CheckIfThereIsBlock(AutoBreakStartPoint.x - 2, AutoBreakStartPoint.y - 2))
    {
        return false;
    }
    else if(CheckIfThereIsBlock(AutoBreakStartPoint.x - 1, AutoBreakStartPoint.y - 2))
    {
        return false;
    }
    else if(CheckIfThereIsBlock(AutoBreakStartPoint.x + 1, AutoBreakStartPoint.y - 2))
    {
        return false;
    }
    else if(CheckIfThereIsBlock(AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y - 2))
    {
        return false;
    }
    else
    {
        return true;
    }
}

void CleanAutoFarm(InventoryKey block)
{
    if(CheckIfThereIsBlock(AutoBreakStartPoint.x - 2, AutoBreakStartPoint.y + 2))
    {
        AutoBreak(AutoBreakStartPoint.x - 2, AutoBreakStartPoint.y + 2, block);
    }
    else if(CheckIfThereIsBlock(AutoBreakStartPoint.x - 1, AutoBreakStartPoint.y + 2))
    {
        AutoBreak(AutoBreakStartPoint.x - 1, AutoBreakStartPoint.y + 2, block);
    }
    else if(CheckIfThereIsBlock(AutoBreakStartPoint.x - 0, AutoBreakStartPoint.y + 2))
    {
        AutoBreak(AutoBreakStartPoint.x - 0, AutoBreakStartPoint.y + 2, block);
    }
    else if(CheckIfThereIsBlock(AutoBreakStartPoint.x + 1, AutoBreakStartPoint.y + 2))
    {
        AutoBreak(AutoBreakStartPoint.x + 1, AutoBreakStartPoint.y + 2, block);
    }
    else if(CheckIfThereIsBlock(AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y + 2))
    {
        AutoBreak(AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y + 2, block);
    }
        //2
    else if(CheckIfThereIsBlock(AutoBreakStartPoint.x - 2, AutoBreakStartPoint.y + 1))
    {
        AutoBreak(AutoBreakStartPoint.x - 2, AutoBreakStartPoint.y + 1, block);
    }
    else if(CheckIfThereIsBlock(AutoBreakStartPoint.x - 1, AutoBreakStartPoint.y + 1))
    {
        AutoBreak(AutoBreakStartPoint.x - 1, AutoBreakStartPoint.y + 1, block);
    }
    else if(CheckIfThereIsBlock(AutoBreakStartPoint.x - 0, AutoBreakStartPoint.y + 1))
    {
        AutoBreak(AutoBreakStartPoint.x - 0, AutoBreakStartPoint.y + 1, block);
    }
    else if(CheckIfThereIsBlock(AutoBreakStartPoint.x + 1, AutoBreakStartPoint.y + 1))
    {
        AutoBreak(AutoBreakStartPoint.x + 1, AutoBreakStartPoint.y + 1, block);
    }
    else if(CheckIfThereIsBlock(AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y + 1))
    {
        AutoBreak(AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y + 1, block);
    }
        //3
    else if(CheckIfThereIsBlock(AutoBreakStartPoint.x - 2, AutoBreakStartPoint.y + 0))
    {
        AutoBreak(AutoBreakStartPoint.x - 2, AutoBreakStartPoint.y + 0, block);
    }
    else if(CheckIfThereIsBlock(AutoBreakStartPoint.x - 1, AutoBreakStartPoint.y + 0))
    {
        AutoBreak(AutoBreakStartPoint.x - 1, AutoBreakStartPoint.y + 0, block);
    }
    else if(CheckIfThereIsBlock(AutoBreakStartPoint.x + 1, AutoBreakStartPoint.y + 0))
    {
        AutoBreak(AutoBreakStartPoint.x + 1, AutoBreakStartPoint.y + 0, block);
    }
    else if(CheckIfThereIsBlock(AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y + 0))
    {
        AutoBreak(AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y + 0, block);
    }
        //4
    else if(CheckIfThereIsBlock(AutoBreakStartPoint.x - 2, AutoBreakStartPoint.y - 1))
    {
        AutoBreak(AutoBreakStartPoint.x - 2, AutoBreakStartPoint.y - 1, block);
    }
    else if(CheckIfThereIsBlock(AutoBreakStartPoint.x - 1, AutoBreakStartPoint.y - 1))
    {
        AutoBreak(AutoBreakStartPoint.x - 1, AutoBreakStartPoint.y - 1, block);
    }
    else if(CheckIfThereIsBlock(AutoBreakStartPoint.x + 1, AutoBreakStartPoint.y - 1))
    {
        AutoBreak(AutoBreakStartPoint.x + 1, AutoBreakStartPoint.y - 1, block);
    }
    else if(CheckIfThereIsBlock(AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y - 1))
    {
        AutoBreak(AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y - 1, block);
    }
        //5
    else if(CheckIfThereIsBlock(AutoBreakStartPoint.x - 2, AutoBreakStartPoint.y - 2))
    {
        AutoBreak(AutoBreakStartPoint.x - 2, AutoBreakStartPoint.y - 2, block);
    }
    else if(CheckIfThereIsBlock(AutoBreakStartPoint.x - 1, AutoBreakStartPoint.y - 2))
    {
        AutoBreak(AutoBreakStartPoint.x - 1, AutoBreakStartPoint.y - 2, block);
    }
    else if(CheckIfThereIsBlock(AutoBreakStartPoint.x + 1, AutoBreakStartPoint.y - 2))
    {
        AutoBreak(AutoBreakStartPoint.x + 1, AutoBreakStartPoint.y - 2, block);
    }
    else if(CheckIfThereIsBlock(AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y - 2))
    {
        AutoBreak(AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y - 2, block);
    }
}

void FarmPattern(InventoryKey block)
{
    if(doDropOnceInFarm && MyMapPoint == Vector2i{AutoBreakStartPoint.x - 4, AutoBreakStartPoint.y})
    {
        WorldController_DropStuffFromInventory(WorldControllerInstantiate, Vector2i{MyMapPoint.x - 1, MyMapPoint.y}, currentSelectedSeedToDrop, PlayerData_GetCount(MyPlayerData, currentSelectedSeedToDrop), PlayerData_GetInventoryData(MyPlayerData, currentSelectedSeedToDrop));
        dropActionTimer = 0.f;
        doDropOnceInFarm = false;
        Player_GoFromPortal(LocalPlayerInstantiate, MyMapPoint);
    }
    if(doOnceCheckIfClear && !CheckIfThereIsBlock(AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y - 2))
    {
        doOnceCheckIfClear = false;
        doClearOnceFarm = true;
        InitRepeatPutAndBreak ++;
    }
    if(EnableAutoDropSeed && PlayerData_GetCount(MyPlayerData, currentSelectedSeedToDrop) >= SetSeedAmountBeforeDrop)
    {
        dropActionTimer += deltaTime;
        if(MyMapPoint == AutoBreakStartPoint)
        {
            if(dropActionTimer >= dropActionDelay * 3)
            {
                dropActionTimer = 0.00f;
                farmActionTimer = (-0.150f * 5.f);
                Player_GoFromPortal(LocalPlayerInstantiate, MyMapPoint);
                doDropOnceInFarm = true;
            }
        }
    }
    else if(InitRepeatPutAndBreak < RepeatPutAndBreak && AutoBreakStartPoint == MyMapPoint)
    {
        if(!CheckIfThereIsBlock(AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y - 2) && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y - 2}) < SetBlockPercentBeforeStop)
        {
            //1
            if(!CheckIfThereIsBlock(AutoBreakStartPoint.x - 2, AutoBreakStartPoint.y + 2) && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x - 2, AutoBreakStartPoint.y + 2}) < SetBlockPercentBeforeStop && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y - 2}) < SetBlockPercentBeforeStop)
            {
                AutoPutBlock(AutoBreakStartPoint.x - 2, AutoBreakStartPoint.y + 2, block);
            }
            else if(!CheckIfThereIsBlock(AutoBreakStartPoint.x - 1, AutoBreakStartPoint.y + 2) && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x - 1, AutoBreakStartPoint.y + 2}) < SetBlockPercentBeforeStop && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y - 2}) < SetBlockPercentBeforeStop)
            {
                AutoPutBlock(AutoBreakStartPoint.x - 1, AutoBreakStartPoint.y + 2, block);
            }
            else if(!CheckIfThereIsBlock(AutoBreakStartPoint.x - 0, AutoBreakStartPoint.y + 2) && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x - 0, AutoBreakStartPoint.y + 2}) < SetBlockPercentBeforeStop && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y - 2}) < SetBlockPercentBeforeStop)
            {
                AutoPutBlock(AutoBreakStartPoint.x - 0, AutoBreakStartPoint.y + 2, block);
            }
            else if(!CheckIfThereIsBlock(AutoBreakStartPoint.x + 1, AutoBreakStartPoint.y + 2) && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x + 1, AutoBreakStartPoint.y + 2}) < SetBlockPercentBeforeStop && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y - 2}) < SetBlockPercentBeforeStop)
            {
                AutoPutBlock(AutoBreakStartPoint.x + 1, AutoBreakStartPoint.y + 2, block);
            }
            else if(!CheckIfThereIsBlock(AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y + 2) && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y + 2}) < SetBlockPercentBeforeStop && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y - 2}) < SetBlockPercentBeforeStop)
            {
                AutoPutBlock(AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y + 2, block);
            }
            //2
            else if(!CheckIfThereIsBlock(AutoBreakStartPoint.x - 2, AutoBreakStartPoint.y + 1) && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x - 2, AutoBreakStartPoint.y + 1}) < SetBlockPercentBeforeStop && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y - 2}) < SetBlockPercentBeforeStop)
            {
                AutoPutBlock(AutoBreakStartPoint.x - 2, AutoBreakStartPoint.y + 1, block);
            }
            else if(!CheckIfThereIsBlock(AutoBreakStartPoint.x - 1, AutoBreakStartPoint.y + 1) && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x - 1, AutoBreakStartPoint.y + 1}) < SetBlockPercentBeforeStop && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y - 2}) < SetBlockPercentBeforeStop)
            {
                AutoPutBlock(AutoBreakStartPoint.x - 1, AutoBreakStartPoint.y + 1, block);
            }
            else if(!CheckIfThereIsBlock(AutoBreakStartPoint.x - 0, AutoBreakStartPoint.y + 1) && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x - 0, AutoBreakStartPoint.y + 1}) < SetBlockPercentBeforeStop && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y - 2}) < SetBlockPercentBeforeStop)
            {
                AutoPutBlock(AutoBreakStartPoint.x - 0, AutoBreakStartPoint.y + 1, block);
            }
            else if(!CheckIfThereIsBlock(AutoBreakStartPoint.x + 1, AutoBreakStartPoint.y + 1) && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x + 1, AutoBreakStartPoint.y + 1}) < SetBlockPercentBeforeStop && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y - 2}) < SetBlockPercentBeforeStop)
            {
                AutoPutBlock(AutoBreakStartPoint.x + 1, AutoBreakStartPoint.y + 1, block);
            }
            else if(!CheckIfThereIsBlock(AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y + 1) && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y + 1}) < SetBlockPercentBeforeStop && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y - 2}) < SetBlockPercentBeforeStop)
            {
                AutoPutBlock(AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y + 1, block);
            }
            //3
            else if(!CheckIfThereIsBlock(AutoBreakStartPoint.x - 2, AutoBreakStartPoint.y + 0) && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x - 2, AutoBreakStartPoint.y + 0}) < SetBlockPercentBeforeStop && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y - 2}) < SetBlockPercentBeforeStop)
            {
                AutoPutBlock(AutoBreakStartPoint.x - 2, AutoBreakStartPoint.y + 0, block);
            }
            else if(!CheckIfThereIsBlock(AutoBreakStartPoint.x - 1, AutoBreakStartPoint.y + 0) && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x - 1, AutoBreakStartPoint.y + 0}) < SetBlockPercentBeforeStop && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y - 2}) < SetBlockPercentBeforeStop)
            {
                AutoPutBlock(AutoBreakStartPoint.x - 1, AutoBreakStartPoint.y + 0, block);
            }
            else if(!CheckIfThereIsBlock(AutoBreakStartPoint.x + 1, AutoBreakStartPoint.y + 0) && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x + 1, AutoBreakStartPoint.y + 0}) < SetBlockPercentBeforeStop && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y - 2}) < SetBlockPercentBeforeStop)
            {
                AutoPutBlock(AutoBreakStartPoint.x + 1, AutoBreakStartPoint.y + 0, block);
            }
            else if(!CheckIfThereIsBlock(AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y + 0) && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y + 0}) < SetBlockPercentBeforeStop && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y - 2}) < SetBlockPercentBeforeStop)
            {
                AutoPutBlock(AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y + 0, block);
            }
            //4
            else if(!CheckIfThereIsBlock(AutoBreakStartPoint.x - 2, AutoBreakStartPoint.y - 1) && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x - 2, AutoBreakStartPoint.y - 1}) < SetBlockPercentBeforeStop && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y - 2}) < SetBlockPercentBeforeStop)
            {
                AutoPutBlock(AutoBreakStartPoint.x - 2, AutoBreakStartPoint.y - 1, block);
            }
            else if(!CheckIfThereIsBlock(AutoBreakStartPoint.x - 1, AutoBreakStartPoint.y - 1) && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x - 1, AutoBreakStartPoint.y - 1}) < SetBlockPercentBeforeStop && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y - 2}) < SetBlockPercentBeforeStop)
            {
                AutoPutBlock(AutoBreakStartPoint.x - 1, AutoBreakStartPoint.y - 1, block);
            }
            else if(!CheckIfThereIsBlock(AutoBreakStartPoint.x + 1, AutoBreakStartPoint.y - 1) && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x + 1, AutoBreakStartPoint.y - 1}) < SetBlockPercentBeforeStop && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y - 2}) < SetBlockPercentBeforeStop)
            {
                AutoPutBlock(AutoBreakStartPoint.x + 1, AutoBreakStartPoint.y - 1, block);
            }
            else if(!CheckIfThereIsBlock(AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y - 1) && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y - 1}) < SetBlockPercentBeforeStop && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y - 2}) < SetBlockPercentBeforeStop)
            {
                AutoPutBlock(AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y - 1, block);
            }
            //5
            else if(!CheckIfThereIsBlock(AutoBreakStartPoint.x - 2, AutoBreakStartPoint.y - 2) && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x - 2, AutoBreakStartPoint.y - 2}) < SetBlockPercentBeforeStop && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y - 2}) < SetBlockPercentBeforeStop)
            {
                AutoPutBlock(AutoBreakStartPoint.x - 2, AutoBreakStartPoint.y - 2, block);
            }
            else if(!CheckIfThereIsBlock(AutoBreakStartPoint.x - 1, AutoBreakStartPoint.y - 2) && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x - 1, AutoBreakStartPoint.y - 2}) < SetBlockPercentBeforeStop && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y - 2}) < SetBlockPercentBeforeStop)
            {
                AutoPutBlock(AutoBreakStartPoint.x - 1, AutoBreakStartPoint.y - 2, block);
            }
            else if(!CheckIfThereIsBlock(AutoBreakStartPoint.x + 1, AutoBreakStartPoint.y - 2) && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x + 1, AutoBreakStartPoint.y - 2}) < SetBlockPercentBeforeStop && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y - 2}) < SetBlockPercentBeforeStop)
            {
                AutoPutBlock(AutoBreakStartPoint.x + 1, AutoBreakStartPoint.y - 2, block);
            }
            else if(!CheckIfThereIsBlock(AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y - 2) && GetMapPointCollectableAmount(Vector2i{AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y - 2}) < SetBlockPercentBeforeStop)
            {
                AutoPutBlock(AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y - 2, block);
            }
        }
        else
        {
            //1
            if(CheckIfThereIsBlock(AutoBreakStartPoint.x - 2, AutoBreakStartPoint.y + 2))
            {
                doOnceCheckIfClear = true;
                AutoBreak(AutoBreakStartPoint.x - 2, AutoBreakStartPoint.y + 2, block);
            }
            else if(CheckIfThereIsBlock(AutoBreakStartPoint.x - 1, AutoBreakStartPoint.y + 2))
            {
                doOnceCheckIfClear = true;
                AutoBreak(AutoBreakStartPoint.x - 1, AutoBreakStartPoint.y + 2, block);
            }
            else if(CheckIfThereIsBlock(AutoBreakStartPoint.x - 0, AutoBreakStartPoint.y + 2))
            {
                doOnceCheckIfClear = true;
                AutoBreak(AutoBreakStartPoint.x - 0, AutoBreakStartPoint.y + 2, block);
            }
            else if(CheckIfThereIsBlock(AutoBreakStartPoint.x + 1, AutoBreakStartPoint.y + 2))
            {
                doOnceCheckIfClear = true;
                AutoBreak(AutoBreakStartPoint.x + 1, AutoBreakStartPoint.y + 2, block);
            }
            else if(CheckIfThereIsBlock(AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y + 2))
            {
                doOnceCheckIfClear = true;
                AutoBreak(AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y + 2, block);
            }
                //2
            else if(CheckIfThereIsBlock(AutoBreakStartPoint.x - 2, AutoBreakStartPoint.y + 1))
            {
                doOnceCheckIfClear = true;
                AutoBreak(AutoBreakStartPoint.x - 2, AutoBreakStartPoint.y + 1, block);
            }
            else if(CheckIfThereIsBlock(AutoBreakStartPoint.x - 1, AutoBreakStartPoint.y + 1))
            {
                doOnceCheckIfClear = true;
                AutoBreak(AutoBreakStartPoint.x - 1, AutoBreakStartPoint.y + 1, block);
            }
            else if(CheckIfThereIsBlock(AutoBreakStartPoint.x - 0, AutoBreakStartPoint.y + 1))
            {
                doOnceCheckIfClear = true;
                AutoBreak(AutoBreakStartPoint.x - 0, AutoBreakStartPoint.y + 1, block);
            }
            else if(CheckIfThereIsBlock(AutoBreakStartPoint.x + 1, AutoBreakStartPoint.y + 1))
            {
                doOnceCheckIfClear = true;
                AutoBreak(AutoBreakStartPoint.x + 1, AutoBreakStartPoint.y + 1, block);
            }
            else if(CheckIfThereIsBlock(AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y + 1))
            {
                doOnceCheckIfClear = true;
                AutoBreak(AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y + 1, block);
            }
                //3
            else if(CheckIfThereIsBlock(AutoBreakStartPoint.x - 2, AutoBreakStartPoint.y + 0))
            {
                doOnceCheckIfClear = true;
                AutoBreak(AutoBreakStartPoint.x - 2, AutoBreakStartPoint.y + 0, block);
            }
            else if(CheckIfThereIsBlock(AutoBreakStartPoint.x - 1, AutoBreakStartPoint.y + 0))
            {
                doOnceCheckIfClear = true;
                AutoBreak(AutoBreakStartPoint.x - 1, AutoBreakStartPoint.y + 0, block);
            }
            else if(CheckIfThereIsBlock(AutoBreakStartPoint.x + 1, AutoBreakStartPoint.y + 0))
            {
                doOnceCheckIfClear = true;
                AutoBreak(AutoBreakStartPoint.x + 1, AutoBreakStartPoint.y + 0, block);
            }
            else if(CheckIfThereIsBlock(AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y + 0))
            {
                doOnceCheckIfClear = true;
                AutoBreak(AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y + 0, block);
            }
                //4
            else if(CheckIfThereIsBlock(AutoBreakStartPoint.x - 2, AutoBreakStartPoint.y - 1))
            {
                doOnceCheckIfClear = true;
                AutoBreak(AutoBreakStartPoint.x - 2, AutoBreakStartPoint.y - 1, block);
            }
            else if(CheckIfThereIsBlock(AutoBreakStartPoint.x - 1, AutoBreakStartPoint.y - 1))
            {
                doOnceCheckIfClear = true;
                AutoBreak(AutoBreakStartPoint.x - 1, AutoBreakStartPoint.y - 1, block);
            }
            else if(CheckIfThereIsBlock(AutoBreakStartPoint.x + 1, AutoBreakStartPoint.y - 1))
            {
                doOnceCheckIfClear = true;
                AutoBreak(AutoBreakStartPoint.x + 1, AutoBreakStartPoint.y - 1, block);
            }
            else if(CheckIfThereIsBlock(AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y - 1))
            {
                doOnceCheckIfClear = true;
                AutoBreak(AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y - 1, block);
            }
                //5
            else if(CheckIfThereIsBlock(AutoBreakStartPoint.x - 2, AutoBreakStartPoint.y - 2))
            {
                doOnceCheckIfClear = true;
                AutoBreak(AutoBreakStartPoint.x - 2, AutoBreakStartPoint.y - 2, block);
            }
            else if(CheckIfThereIsBlock(AutoBreakStartPoint.x - 1, AutoBreakStartPoint.y - 2))
            {
                doOnceCheckIfClear = true;
                AutoBreak(AutoBreakStartPoint.x - 1, AutoBreakStartPoint.y - 2, block);
            }
            else if(CheckIfThereIsBlock(AutoBreakStartPoint.x + 1, AutoBreakStartPoint.y - 2))
            {
                doOnceCheckIfClear = true;
                AutoBreak(AutoBreakStartPoint.x + 1, AutoBreakStartPoint.y - 2, block);
            }
            else if(CheckIfThereIsBlock(AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y - 2))
            {
                doOnceCheckIfClear = true;
                AutoBreak(AutoBreakStartPoint.x + 2, AutoBreakStartPoint.y - 2, block);
            }
            else
            {
                doOnceCheckIfClear = true;
            }
        }
    }
    else
    {
        if(doClearOnceFarm)
        {
            if(FullyAutoFarmClear())
            {
                if(MyMapPoint.y >= AutoBreakStartPoint.y + 3)
                {
                    doClearOnceFarm = false;
                    InitRepeatPutAndBreak = 0;
                }
                EnableJumpButton = true;
                Player_SetVelocity(LocalPlayerInstantiate, Vector3(0.0f, 2.1f));
            }
            else
            {
                CleanAutoFarm(block);
            }
        }
    }
}

void Auto_Break()
{
    if(DoSaveSeedToDrop && MyPlayerData != nullptr)
    {
        DoSaveSeedToDrop = false;
        currentSelectedSeedToDrop = PlayerData_GetBeltItem(MyPlayerData);
    }
    if(EnableAutoFarm && worldType == 0 && WorldInstantiate != nullptr && LocalPlayerInstantiate != nullptr && collectables != nullptr)
    {
        farmActionTimer += deltaTime;
        if (AutoBreakStartPoint != Vector2i{} && currentSelectedBlockType.blockType != 0)
        {
            FarmPattern(currentSelectedBlockType);
        }
    }
    if(!EnableAutoFarm)
    {
        currentSelectedBlockType = PlayerData_GetBeltItem(MyPlayerData);
        AutoBreakStartPoint = MyMapPoint;
        InitRepeatPutAndBreak = 0;
        farmActionTimer = 0.f;
    }
}

void AutoFarmInfoLabel()
{
    if (EnableAutoFarmInfoLabel && !checkIsPlayerInMenu && worldType == 0 && MyPlayerData != nullptr) {
        ImGui::Begin(OBFUSCATE("Auto Farm Info Label"), &EnableAutoFarmInfoLabel,ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoResize |ImGuiWindowFlags_NoCollapse);
        ImGui::Text(OBFUSCATE("Current Farm Map Point: %d, %d"), AutoBreakStartPoint.x, AutoBreakStartPoint.y);
        ImGui::Text(OBFUSCATE("Current Block To Farm: %s [x%d]"), blockTypeToString[currentSelectedBlockType.blockType], PlayerData_GetCount(MyPlayerData, currentSelectedBlockType));
        ImGui::Text(OBFUSCATE("Current Selected Seed To Drop: %s [x%d]"), blockTypeToString[currentSelectedSeedToDrop.blockType], PlayerData_GetCount(MyPlayerData, currentSelectedSeedToDrop));
        ImGui::Text(OBFUSCATE("Current Repeat Time: %d"), InitRepeatPutAndBreak);
        ImGui::End();
    }
}

#endif
