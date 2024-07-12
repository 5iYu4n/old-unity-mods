#ifndef WORLDCONTROLLER
#define WORLDCONTROLLER

void (*old_WorldController_InstantiateGiftBoxPrizeGameObject)(void *instance, InventoryKey inventoryItemKey);
void WorldController_InstantiateGiftBoxPrizeGameObject(void *instance, InventoryKey inventoryItemKey)
{
    if(instance != nullptr)
    {

    }
    old_WorldController_InstantiateGiftBoxPrizeGameObject(instance, inventoryItemKey);
}

void (*old_WorldController_BlockColliderAndLayerHelper)(void *instance, int blockType, void *gameObject, Vector2i mapPoint);
void WorldController_BlockColliderAndLayerHelper(void *instance, int blockType, void *gameObject, Vector2i mapPoint)
{
    if(instance != nullptr && EnableGodMod)
    {
        if(ConfigData_IsBlockInstakill(blockType))
        {
            blockType = 1;
        }
    }
    old_WorldController_BlockColliderAndLayerHelper(instance, blockType, gameObject, mapPoint);
}

void (*old_WorldController_KickPlayerByInactivity)(void *instance, monoString *deltaParameter);
void WorldController_KickPlayerByInactivity(void *instance, monoString *deltaParameter)
{
    if(instance != nullptr)
    {
        if(EnableAntiAFKKick)
        {
            return;
        }
        else if(EnableAutoMine)
        {
            return;
        }
    }
    old_WorldController_KickPlayerByInactivity(instance, deltaParameter);
}

void (*old_WorldController_ChangeLighting)(void *instance ,int lightingType);
void WorldController_ChangeLighting(void *instance ,int lightingType)
{
    if(instance != nullptr)
    {
        if(EnableAlwaysLightOn)
        {
            return;
        }
    }
    old_WorldController_ChangeLighting(instance, lightingType);
}

void (*old_WorldController_InstantiateFogOfWar)(void *instance);
void WorldController_InstantiateFogOfWar(void *instance)
{
    if(instance != nullptr)
    {
        if(EnableAlwaysFogOff)
        {
            return;
        }
    }
    old_WorldController_InstantiateFogOfWar(instance);
}


void (*old_WorldController_LocalPlayerReadyToPlay)(void *instance);
void WorldController_LocalPlayerReadyToPlay(void *instance)
{
    if(instance != nullptr)
    {
        NetherBeforeStart = 15.0f;
        MineBeforeStart = 15.0f;
        refreshEntity = true;
        if(!playerListManager->enemies->empty())
        {
            for (int i = 0; i < aIEnemyManager->enemies->size(); i++) {
                (*aIEnemyManager->enemies)[i]->object = nullptr;
            }
        }
        NetherBossFound = false;
        exitOnce = true;
        repairOnce = true;
        canHeal = true;
        DoOnceConvertNugget = true;
        //DoJoinPortalOnce = true;
    }
    old_WorldController_LocalPlayerReadyToPlay(instance);
}

void (*old_WorldController_Update)(void *instance);
void WorldController_Update(void *instance)
{
    if(instance != nullptr)
    {
        checkIsPlayerInMenu = false;

        WorldControllerInstantiate = instance;

        SetVisualBlock(instance);

        void *world = *(void **)((uint64_t)instance + PixelWorlds.WorldController_world);
        if(world != nullptr)
        {
            WorldInstantiate = world;

            getCurrentWorldSize.x = *(int *)((uint64_t)world + PixelWorlds.World_worldSizeX);
            getCurrentWorldSize.y = *(int *)((uint64_t)world + PixelWorlds.World_worldSizeY);

            if(setGravityModeID > 0)
            {
                *(int *)((uint64_t)world + PixelWorlds.World_gravityMode) = (int)(setGravityModeID - 1);
            }

            worldType = *(int *)((uint64_t)world + PixelWorlds.World_worldType);

            PixelWorldsEntity();

            if(setBackground != 0)
            {
                *(int *)((uint64_t)world + PixelWorlds.World_worldBackground) = (setBackground - 1);
            }

            if(setWeather != 0)
            {
                *(int *)((uint64_t)world + PixelWorlds.World_worldWeatherType) = (setWeather - 1);
            }

            if(setLighting != 0)
            {
                *(int *)((uint64_t)world + PixelWorlds.World_worldLightingType) = (setLighting - 1);
            }

            collectables = *(monoList<void **> **)((uint64_t)world + PixelWorlds.World_collectables);

            AutoSearchNetherBoss(world, worldType);
            Nether_Mod(world);
            AutoMine(instance, world);
            Auto_Spin();
            Super_Hero();
            AutoFishing();
            Auto_Break();
            //TpPortalMod();

            switch (fpsOptions) {
                case 0:
                    break;
                case 1:
                    Application_set_targetFrameRate(30);
                    break;
                case 2:
                    Application_set_targetFrameRate(60);
                    break;
                case 3:
                    Application_set_targetFrameRate(90);
                    break;
                case 4:
                    Application_set_targetFrameRate(120);
                    break;
                case 5:
                    Application_set_targetFrameRate(240);
                    break;
            }
        }

        void *spirit = *(void **)((uint64_t)instance + PixelWorlds.WorldController_spirit);
        SpiritScript(spirit);
    }
    old_WorldController_Update(instance);
}

#endif
