#ifndef CSY_HERO_H
#define CSY_HERO_H

void Super_Hero()
{
    if(worldType == 11)
    {
        SuperHeroTimer += deltaTime;

        MyMapPointInSB = MyMapPoint;

        float GiftBoxClosestDistance = INFINITY;
        Vector2i CurrentSuperHeroClosestGiftBox = Vector2i{};

        if(WorldInstantiate != nullptr)
        {
            if(EnableSuperHeroAutoCollectGiftBox)
            {
                for (int x = 0; x < getCurrentWorldSize.x; ++x)
                {
                    for (int y = 0; y < getCurrentWorldSize.y; ++y)
                    {
                        int getBlockType = World_GetBlockType(WorldInstantiate, x, y);
                        if (getBlockType == 2066)
                        {
                            Vector2i BlockPosition = Vector2i{x, y};
                            void *GetWorldItemData = World_GetWorldItemData(WorldInstantiate, x, y);
                            if(GetWorldItemData != nullptr)
                            {
                                bool isAnimationOn = *(bool *) ((uint64_t) GetWorldItemData + PixelWorlds.WorldItemBase_isAnimationOn);
                                if (isAnimationOn)
                                {
                                    Vector2i Distance = Vector2i{MyMapPointInSB.x - BlockPosition.x,MyMapPointInSB.y - BlockPosition.y};
                                    float MaxDistanceRange = sqrt(((float)Distance.x * (float)Distance.x) + ((float)Distance.y * (float)Distance.y));
                                    if(MaxDistanceRange < GiftBoxClosestDistance)
                                    {
                                        GiftBoxClosestDistance = MaxDistanceRange;
                                        if(GiftBoxClosestDistance < 1.41f)
                                        {
                                            CurrentSuperHeroClosestGiftBox = Vector2i{x, y};
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        if(EnableSuperHeroAutoCollectGiftBox && CurrentSuperHeroClosestGiftBox != Vector2i{})
        {
            if(SuperHeroTimer >= superHeroActionDelay)
            {
                SuperHeroTimer = 0.0f;
                OutgoingMessages_SendRequestItemFromGiftBoxMessage(CurrentSuperHeroClosestGiftBox);
            }
        }
        else if(EnableSuperHeroAimbot)
        {
            if(CloserMonster != nullptr)
            {
                Vector2 getLocation = GetAiEnemyLocation(CloserMonster);
                void *aiBase = *(void **)((uint64_t)CloserMonster + PixelWorlds.AIEnemyMonoBehaviourBase_aiBase);
                if(aiBase != nullptr)
                {
                    int id = *(int *)((uint64_t)aiBase + PixelWorlds.AIBase_id);
                    Vector2i MonsterMapPoint = Vector2i{roundf(getLocation.X), roundf(getLocation.Y)};
                    if(SuperHeroTimer >= superHeroActionDelay)
                    {
                        SuperHeroTimer = 0.0f;
                        OutgoingMessages_SendHitAIEnemyMessage(MonsterMapPoint, id);
                    }
                }
            }
        }
    }
}

#endif
