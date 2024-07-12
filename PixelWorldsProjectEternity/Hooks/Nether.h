#ifndef CSY_NETHER_H
#define CSY_NETHER_H

void AutoSearchNetherBoss(void *World, int WorldType)
{
    if(EnableAutoSearchNetherBoss && !NetherBossFound)
    {
        if(!checkIsPlayerInMenu && WorldType != 5)
        {
            NetherBossFound = true;
            ReloadWorldNetherBoss = true;
        }
        else if(WorldType == 5)
        {
            int getCurrentNetherGiftBox = 0;
            for (int i = 0; i < getCurrentWorldSize.x; ++i) {
                for (int j = 0; j < getCurrentWorldSize.y; ++j) {
                    int getBlockType = World_GetBlockType(World, i, j);
                    if(getBlockType == 1392)
                    {
                        getCurrentNetherGiftBox ++;
                    }
                }
            }
            if(getCurrentNetherGiftBox >= 11)
            {
                NetherBossFound = true;
            }
            else
            {
                NetherBossFound = true;
                ReloadWorldNetherBoss = true;
            }
        }
    }
}

void Nether_Mod(void *World)
{
    if((worldType == 5 || worldType == 9) && (EnableNetherAimbot || EnableAutoClaimNetherGiftBox || EnableAutoBreakNetherTreasureBox) && NetherBeforeStart <= .5f)
    {
        Vector2i MyMapPointInNether = MyMapPoint;

        NetherActionTimer += deltaTime;

        float GiftBoxClosestDistance = INFINITY;
        float TreasureBoxClosestDistance = INFINITY;

        Vector2i CurrentClosestGiftBox = Vector2i{};
        Vector2i CurrentClosestTreasureBox = Vector2i{};

        if(MyMapPointInNether !=  Vector2i{})
        {
            if(World != nullptr)
            {
                for (int x = 0; x < getCurrentWorldSize.x; ++x)
                {
                    for (int y = 0; y < getCurrentWorldSize.y; ++y)
                    {
                        int getBlockType = World_GetBlockType(World, x, y);
                        if(getBlockType == 1392)//Nether Gift Box
                        {
                            Vector2i BlockPosition = Vector2i{x, y};
                            void *GetWorldItemData = World_GetWorldItemData(World, x, y);
                            if(GetWorldItemData != nullptr)
                            {
                                bool isAnimationOn = *(bool *) ((uint64_t) GetWorldItemData + PixelWorlds.WorldItemBase_isAnimationOn);
                                if (isAnimationOn)
                                {
                                    Vector2i Distance = Vector2i{MyMapPointInNether.x - BlockPosition.x,MyMapPointInNether.y - BlockPosition.y};
                                    float MaxDistanceRange = sqrt(((float)Distance.x * (float)Distance.x) + ((float)Distance.y * (float)Distance.y));
                                    if(MaxDistanceRange < GiftBoxClosestDistance)
                                    {
                                        GiftBoxClosestDistance = MaxDistanceRange;
                                        if(GiftBoxClosestDistance < 1.41f)
                                        {
                                            CurrentClosestGiftBox = Vector2i{x, y};
                                        }
                                    }
                                }
                            }
                        }
                        else if(getBlockType == 1400)//Nether Treasure
                        {
                            Vector2i BlockPosition = Vector2i{x, y};
                            Vector2i Distance = Vector2i{MyMapPointInNether.x - BlockPosition.x,MyMapPointInNether.y - BlockPosition.y};
                            float MaxDistanceRange = sqrt(((float)Distance.x * (float)Distance.x) + ((float)Distance.y * (float)Distance.y));
                            if(MaxDistanceRange < TreasureBoxClosestDistance)
                            {
                                TreasureBoxClosestDistance = MaxDistanceRange;
                                if(TreasureBoxClosestDistance < 2.82f)
                                {
                                    CurrentClosestTreasureBox = Vector2i{x, y};
                                }
                            }
                        }
                    }
                }
            }

            if(EnableAutoClaimNetherGiftBox && CurrentClosestGiftBox != Vector2i{})
            {
                if(NetherActionTimer >= NetherActionDelay)
                {
                    NetherActionTimer = 0.0f;
                    OutgoingMessages_SendRequestItemFromGiftBoxMessage(CurrentClosestGiftBox);
                }
            }

            else if(EnableAutoBreakNetherTreasureBox && CurrentClosestTreasureBox != Vector2i{})
            {
                if(NetherActionTimer >= NetherActionDelay)
                {
                    NetherActionTimer = 0.0f;
                    OutgoingMessages_SendHitBlockMessage(CurrentClosestTreasureBox, DateTime{0}, false);
                }
            }

            else if(EnableNetherAimbot)
            {
                if(CloserMonster != nullptr)
                {
                    Vector2 getLocation = GetAiEnemyLocation(CloserMonster);
                    int id = GetAiEnemyID(CloserMonster);
                    Vector2i MonsterMapPoint = Vector2i{roundf(getLocation.X), roundf(getLocation.Y)};
                    if(NetherActionTimer >= NetherActionDelay)
                    {
                        NetherActionTimer = 0.0f;
                        OutgoingMessages_SendHitAIEnemyMessage(MonsterMapPoint, id);
                    }
                }
            }
        }
    }
}

#endif
