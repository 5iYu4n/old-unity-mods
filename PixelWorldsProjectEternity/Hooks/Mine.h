#ifndef CSY_MINE_H
#define CSY_MINE_H

static bool EnableIgnoreCollectable = false;
static bool EnableConvertNuggets = false;
static bool DoOnceConvertNugget = false;

static float MineStuckTimer = 0.f;
static float MineStuckDelay = 2.0f;

Vector2i StuckMapPoint = Vector2i{-1, -1};

void DoCheckIfStuck(Vector2i myMapPoint, Vector2i mapPoint, float ActionTimer)
{
    MineStuckTimer += deltaTime;
    if(MineStuckTimer >= MineStuckDelay)
    {
        if(mapPoint == Vector2i{-1, -1})
        {
            mapPoint = mapPoint;
            MineStuckTimer = 0.f;
        }
        else if(mapPoint == myMapPoint)
        {
            MineStuckTimer = 0.f;
        }
        else
        {
            mapPoint = Vector2i{-1, -1};
            MineStuckTimer = 0.f;
        }
    }
}

bool isSolidBlockInMine(int block)
{
    if(block == 3980 || block == 3981 || block == 3982 || block == 3983 || block == 3984 || block == 3985 || block == 3986 || block == 3987 || block == 3988 || block == 3989 || block == 3990 || block == 3991 || block == 3992 || block == 3993 || block == 3994 || block == 3995 || block == 3996 || block == 3999 || block == 4000 || block == 4002)
    {
        return true;
    }
    return false;
}

bool isIgnoreCollectableBy(int blockType)
{
    if(ConfigData_IsMiningNugget(blockType))
        return true;
    else if(ConfigData_IsBlockMiningGemstone(blockType))
        return true;
    else if(blockType == 4139)//PocketWatch
        return true;
    else
        return false;
}

void AutoMine(void *WorldController, void *World)
{
    if(EnableAutoMine && LocalPlayerInstantiate != nullptr && MineBeforeStart <= 3.0f)
    {
        MineActionTimer += deltaTime;

        if(worldType == 18)
        {
            //Movement
            Vector3 VelocityGoLeft = Vector3{-1.9f, 0.36f};
            Vector3 VelocityGoLeftUp = Vector3{-1.9f, 1.1f, 0.0f};
            Vector3 VelocityGoUp = Vector3{0.0f, 1.9f, 0.0f};
            Vector3 VelocityGoRightUp = Vector3{1.9f, 1.1f, 0.0f};
            Vector3 VelocityGoRight = Vector3{1.9f, 0.36f, 0.0f};
            Vector3 VelocityGoDown = Vector3{0.0f, -1.6f, 0.0f};
            Vector3 VelocityGoLeftDown = Vector3{-1.6f, -0.5f, 0.0f};
            Vector3 VelocityGoRightDown = Vector3{1.6f, -0.5f, 0.0f};
            Vector3 VelocityGoLeftWalk = Vector3{-1.9f, -0.1f};
            Vector3 VelocityGoRightWalk = Vector3{1.9f, -0.1f};

            Vector2i MyMapPointInMine = MyMapPoint;
            Vector2 MyVec2InMine = MyMapPointVec2;

            //Collectable
            float closestCollectableDist = INFINITY;
            int HighestCollectableY = 0;
            Vector2i SafestCollectablePoint = Vector2i{};

            //Block
            float closestBlockDist = INFINITY;
            int HighestBlockY = 0;
            Vector2i EntranceDoorPoint = Vector2i{};
            Vector2i ExitDoorPoint = Vector2i{};
            Vector2i SafestBlockPoint = Vector2i{};

            //Monster
            Vector2i SafestMonsterMapPoint = Vector2i{};

            float closestTargetDist = INFINITY;
            int HighestTargetAction = 0;
            SafestTargetActionMapPoint = Vector2i{};

            //Get The Highest And The Closest Collectable
            if(EnableMineAutoCollect)
            {
                if(collectables != nullptr)
                {
                    for (int i = 0; i < collectables->getSize(); ++i)
                    {
                        void *collectable = collectables->getItems()[i];
                        if (collectable != nullptr) {
                            if(SafestAutoMine)
                            {
                                Vector2i currentCollectablePosition = *(Vector2i *)((uint64_t)collectable + PixelWorlds.CollectableData_mapPoint);
                                int blockType = *(int *)((uint64_t)collectable + PixelWorlds.CollectableData_blockType);
                                if(EnableIgnoreCollectable)
                                {
                                    if(isIgnoreCollectableBy(blockType))
                                    {
                                        if(HighestCollectableY < currentCollectablePosition.y)
                                        {
                                            closestCollectableDist = INFINITY;
                                            HighestCollectableY = currentCollectablePosition.y;
                                            SafestCollectablePoint = currentCollectablePosition;
                                            Vector2 Distance = Vector2{MyMapPointInMine.x - currentCollectablePosition.x, MyMapPointInMine.y - currentCollectablePosition.y};
                                            float Pytha = sqrt((Distance.X * Distance.X) + (Distance.Y * Distance.Y));
                                            if(Pytha < closestCollectableDist)
                                            {
                                                closestCollectableDist = Pytha;
                                            }
                                        }
                                        else if(HighestCollectableY == currentCollectablePosition.y)
                                        {
                                            Vector2 Distance = Vector2{MyMapPointInMine.x - currentCollectablePosition.x, MyMapPointInMine.y - currentCollectablePosition.y};
                                            float Pytha = sqrt((Distance.X * Distance.X) + (Distance.Y * Distance.Y));
                                            if(Pytha < closestCollectableDist)
                                            {
                                                closestCollectableDist = Pytha;
                                                SafestCollectablePoint = currentCollectablePosition;
                                            }
                                        }
                                    }
                                }
                                else
                                {
                                    if(HighestCollectableY < currentCollectablePosition.y)
                                    {
                                        closestCollectableDist = INFINITY;
                                        HighestCollectableY = currentCollectablePosition.y;
                                        SafestCollectablePoint = currentCollectablePosition;
                                        Vector2 Distance = Vector2{MyMapPointInMine.x - currentCollectablePosition.x, MyMapPointInMine.y - currentCollectablePosition.y};
                                        float Pytha = sqrt((Distance.X * Distance.X) + (Distance.Y * Distance.Y));
                                        if(Pytha < closestCollectableDist)
                                        {
                                            closestCollectableDist = Pytha;
                                        }
                                    }
                                    else if(HighestCollectableY == currentCollectablePosition.y)
                                    {
                                        Vector2 Distance = Vector2{MyMapPointInMine.x - currentCollectablePosition.x, MyMapPointInMine.y - currentCollectablePosition.y};
                                        float Pytha = sqrt((Distance.X * Distance.X) + (Distance.Y * Distance.Y));
                                        if(Pytha < closestCollectableDist)
                                        {
                                            closestCollectableDist = Pytha;
                                            SafestCollectablePoint = currentCollectablePosition;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

            //Get The Highest And The Closest Gemstone, Crate, Entry Point, Exit Point
            if(WorldInstantiate != nullptr)
            {
                for (int j = getCurrentWorldSize.y; j > 0; --j)
                {
                    for (int i = 0; i < getCurrentWorldSize.x; ++i)
                    {
                        int GetBlock = World_GetBlockType(WorldInstantiate, i, j);
                        if(EnableAutoBreakGemstone || EnableAutoBreakCrate)
                        {
                            if(SafestAutoMine)
                            {
                                //Gemstone
                                if(EnableAutoBreakGemstone && !EnableAutoBreakCrate)
                                {
                                    if(GetBlock == 3995 || GetBlock == 3996 || GetBlock == 3999 || GetBlock == 4000 || GetBlock == 4002)
                                    {
                                        Vector2i currentBlockTarget = Vector2i{i, j};
                                        if(HighestBlockY < currentBlockTarget.y)
                                        {
                                            closestBlockDist = INFINITY;
                                            HighestBlockY = currentBlockTarget.y;
                                            SafestBlockPoint = currentBlockTarget;
                                            Vector2 Distance = Vector2{MyMapPointInMine.x - currentBlockTarget.x, MyMapPointInMine.y - currentBlockTarget.y};
                                            float Pytha = sqrt((Distance.X * Distance.X) + (Distance.Y * Distance.Y));
                                            if(Pytha < closestBlockDist)
                                            {
                                                closestBlockDist = Pytha;
                                            }
                                        }
                                        else if(HighestBlockY == currentBlockTarget.y)
                                        {
                                            Vector2 Distance = Vector2{MyMapPointInMine.x - currentBlockTarget.x, MyMapPointInMine.y - currentBlockTarget.y};
                                            float Pytha = sqrt((Distance.X * Distance.X) + (Distance.Y * Distance.Y));
                                            if(Pytha < closestBlockDist)
                                            {
                                                closestBlockDist = Pytha;
                                                SafestBlockPoint = currentBlockTarget;
                                            }
                                        }
                                    }
                                }
                                    //Crate
                                else if(EnableAutoBreakCrate && !EnableAutoBreakGemstone)
                                {
                                    if(GetBlock == 4130 || GetBlock == 4149 || GetBlock == 4150)
                                    {
                                        Vector2i currentBlockTarget = Vector2i{i, j};
                                        if(HighestBlockY < currentBlockTarget.y)
                                        {
                                            closestBlockDist = INFINITY;
                                            HighestBlockY = currentBlockTarget.y;
                                            SafestBlockPoint = currentBlockTarget;
                                            Vector2 Distance = Vector2{MyMapPointInMine.x - currentBlockTarget.x, MyMapPointInMine.y - currentBlockTarget.y};
                                            float Pytha = sqrt((Distance.X * Distance.X) + (Distance.Y * Distance.Y));
                                            if(Pytha < closestBlockDist)
                                            {
                                                closestBlockDist = Pytha;
                                            }
                                        }
                                        else if(HighestBlockY == currentBlockTarget.y)
                                        {
                                            Vector2 Distance = Vector2{MyMapPointInMine.x - currentBlockTarget.x, MyMapPointInMine.y - currentBlockTarget.y};
                                            float Pytha = sqrt((Distance.X * Distance.X) + (Distance.Y * Distance.Y));
                                            if(Pytha < closestBlockDist)
                                            {
                                                closestBlockDist = Pytha;
                                                SafestBlockPoint = currentBlockTarget;
                                            }
                                        }
                                    }
                                }
                                    //Gemstone || Crate
                                else if(EnableAutoBreakGemstone && EnableAutoBreakCrate)
                                {
                                    if(GetBlock == 3995 || GetBlock == 3996 || GetBlock == 3999 || GetBlock == 4000 || GetBlock == 4002 || GetBlock == 4130 || GetBlock == 4149 || GetBlock == 4150)
                                    {
                                        Vector2i currentBlockTarget = Vector2i{i, j};
                                        if(HighestBlockY < currentBlockTarget.y)
                                        {
                                            closestBlockDist = INFINITY;
                                            HighestBlockY = currentBlockTarget.y;
                                            SafestBlockPoint = currentBlockTarget;
                                            Vector2 Distance = Vector2{MyMapPointInMine.x - currentBlockTarget.x, MyMapPointInMine.y - currentBlockTarget.y};
                                            float Pytha = sqrt((Distance.X * Distance.X) + (Distance.Y * Distance.Y));
                                            if(Pytha < closestBlockDist)
                                            {
                                                closestBlockDist = Pytha;
                                            }
                                        }
                                        else if(HighestBlockY == currentBlockTarget.y)
                                        {
                                            Vector2 Distance = Vector2{MyMapPointInMine.x - currentBlockTarget.x, MyMapPointInMine.y - currentBlockTarget.y};
                                            float Pytha = sqrt((Distance.X * Distance.X) + (Distance.Y * Distance.Y));
                                            if(Pytha < closestBlockDist)
                                            {
                                                closestBlockDist = Pytha;
                                                SafestBlockPoint = currentBlockTarget;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        //"PortalMiningEntry = 4103"
                        if(GetBlock == 4103)
                        {
                            Vector2i currentBlockTarget = Vector2i{i, j};
                            EntranceDoorPoint = currentBlockTarget;
                        }

                        //"PortalMineExit = 3966"
                        if(GetBlock == 3966)
                        {
                            Vector2i currentBlockTarget = Vector2i{i, j};
                            ExitDoorPoint = currentBlockTarget;
                        }
                    }
                }
            }

            //Get The Highest And The Closest Monster
            if(EnableAutoKillMonster)
            {
                if(SafestAutoMine)
                {
                    if(MineClosestMonster != nullptr)
                    {
                        int getAiID = GetAiEnemyID(MineClosestMonster);
                        Vector2 CurrentSafestMonsterPos = GetAiEnemyLocation(MineClosestMonster);
                        Vector2i ClosestMonsterMapPoint = Vector2i{roundf(CurrentSafestMonsterPos.X), roundf(CurrentSafestMonsterPos.Y)};
                        int GetBlockBellow = World_GetBlockType(WorldInstantiate, MyMapPointInMine.x, MyMapPointInMine.y - 1);
                        if((isSolidBlockInMine(GetBlockBellow) ||  GetBlockBellow == 3) && MineActionTimer > MineActionCooldown)
                        {
                            MineActionTimer = 0.0f;
                            OutgoingMessages_SendHitAIEnemyMessage(ClosestMonsterMapPoint, getAiID);
                        }
                    }
                    MineClosestMonster = nullptr;

                    if(MineSafestMonster != nullptr)
                    {
                        int getAiID = GetAiEnemyID(MineSafestMonster);
                        Vector2 CurrentSafestMonsterPos = GetAiEnemyLocation(MineSafestMonster);
                        SafestMonsterMapPoint = Vector2i{roundf(CurrentSafestMonsterPos.X), roundf(CurrentSafestMonsterPos.Y)};
                        Vector2 distance = Vector2{MyMapPoint.x - SafestMonsterMapPoint.x, MyMapPoint.y - SafestMonsterMapPoint.y};
                        int GetBlockBellow = World_GetBlockType(WorldInstantiate, MyMapPointInMine.x, MyMapPointInMine.y - 1);
                        float Pytha = sqrt((distance.X * distance.X) + (distance.Y * distance.Y));
                        if ((isSolidBlockInMine(GetBlockBellow) ||  GetBlockBellow == 3) && Pytha < 2.82f)
                        {
                            if(MineActionTimer > MineActionCooldown)
                            {
                                MineActionTimer = 0.0f;
                                OutgoingMessages_SendHitAIEnemyMessage(SafestMonsterMapPoint, getAiID);
                            }
                        }
                    }
                }
            }

            if(SafestAutoMine)
            {
                if(SafestCollectablePoint != Vector2i{})
                {
                    if(HighestTargetAction <= SafestCollectablePoint.y)
                    {
                        HighestTargetAction = SafestCollectablePoint.y;
                        Vector2 DistanceCollectable = Vector2{MyMapPointInMine.x - SafestCollectablePoint.x, MyMapPointInMine.y - SafestCollectablePoint.y};
                        float PythaCollectable = sqrt((DistanceCollectable.X * DistanceCollectable.X) + (DistanceCollectable.Y * DistanceCollectable.Y));
                        if(PythaCollectable <= closestTargetDist)
                        {
                            closestTargetDist = PythaCollectable;
                            SafestTargetActionMapPoint = SafestCollectablePoint;
                        }
                    }
                }

                if(SafestBlockPoint != Vector2i{})
                {
                    if(HighestTargetAction < SafestBlockPoint.y)
                    {
                        closestTargetDist = INFINITY;
                        HighestTargetAction = SafestBlockPoint.y;
                        Vector2 DistanceBlock = Vector2{MyMapPointInMine.x - SafestBlockPoint.x,MyMapPointInMine.y - SafestBlockPoint.y};
                        float PythaBlock = sqrt((DistanceBlock.X * DistanceBlock.X) +(DistanceBlock.Y * DistanceBlock.Y));
                        if (PythaBlock < closestTargetDist)
                        {
                            closestTargetDist = PythaBlock;
                            SafestTargetActionMapPoint = SafestBlockPoint;
                        }
                    }
                    else if(HighestTargetAction == SafestBlockPoint.y)
                    {
                        Vector2 DistanceBlock = Vector2{MyMapPointInMine.x - SafestBlockPoint.x,MyMapPointInMine.y - SafestBlockPoint.y};
                        float PythaBlock = sqrt((DistanceBlock.X * DistanceBlock.X) +(DistanceBlock.Y * DistanceBlock.Y));
                        if (PythaBlock < closestTargetDist)
                        {
                            closestTargetDist = PythaBlock;
                            SafestTargetActionMapPoint = SafestBlockPoint;
                        }
                    }
                }

                if(SafestMonsterMapPoint != Vector2i{})
                {
                    if(HighestTargetAction < SafestMonsterMapPoint.y)
                    {
                        closestTargetDist = INFINITY;
                        Vector2 DistanceMonster = Vector2{MyMapPointInMine.x - SafestMonsterMapPoint.x,MyMapPointInMine.y - SafestMonsterMapPoint.y};
                        float PythaMonster = sqrt((DistanceMonster.X * DistanceMonster.X) +(DistanceMonster.Y * DistanceMonster.Y));
                        if (PythaMonster < closestTargetDist) {
                            SafestTargetActionMapPoint = SafestMonsterMapPoint;
                        }
                    }
                    else if(HighestTargetAction == SafestMonsterMapPoint.y)
                    {
                        Vector2 DistanceMonster = Vector2{MyMapPointInMine.x - SafestMonsterMapPoint.x,MyMapPointInMine.y - SafestMonsterMapPoint.y};
                        float PythaMonster = sqrt((DistanceMonster.X * DistanceMonster.X) +(DistanceMonster.Y * DistanceMonster.Y));
                        if (PythaMonster < closestTargetDist) {
                            SafestTargetActionMapPoint = SafestMonsterMapPoint;
                        }
                    }
                }

                if(SafestCollectablePoint == Vector2i{} && SafestBlockPoint == Vector2i{} && SafestMonsterMapPoint == Vector2i{})
                {
                    SafestTargetActionMapPoint = ExitDoorPoint;
                }

                if(SafestTargetActionMapPoint.y < EntranceDoorPoint.y && (MyMapPointInMine == Vector2i{EntranceDoorPoint.x , EntranceDoorPoint.y} || MyMapPointInMine == Vector2i{EntranceDoorPoint.x - 1 , EntranceDoorPoint.y} || MyMapPointInMine == Vector2i{EntranceDoorPoint.x + 1 , EntranceDoorPoint.y}))
                {
                    if(SafestTargetActionMapPoint.x - MyVec2InMine.X <= 0)
                    {
                        int GetBlock = World_GetBlockType(WorldInstantiate, EntranceDoorPoint.x - 1, EntranceDoorPoint.y - 1);
                        if(isSolidBlockInMine(GetBlock))
                        {
                            if(MineActionTimer > MineActionCooldown)
                            {
                                MineActionTimer = 0.0f;
                                OutgoingMessages_SendHitBlockMessage(Vector2i{EntranceDoorPoint.x - 1, EntranceDoorPoint.y - 1}, DateTime{0}, false);
                            }
                        }
                        else
                        {
                            Player_SetVelocity(LocalPlayerInstantiate, Vector3{-1.8f, -1.7f});
                        }
                    }
                    else
                    {
                        int GetBlock = World_GetBlockType(WorldInstantiate, EntranceDoorPoint.x + 1, EntranceDoorPoint.y - 1);
                        if(isSolidBlockInMine(GetBlock))
                        {
                            if(MineActionTimer > MineActionCooldown)
                            {
                                MineActionTimer = 0.0f;
                                OutgoingMessages_SendHitBlockMessage(Vector2i{EntranceDoorPoint.x + 1, EntranceDoorPoint.y - 1}, DateTime{0}, false);
                            }
                        }
                        else
                        {
                            Player_SetVelocity(LocalPlayerInstantiate, Vector3{1.8f, -1.7f});
                        }
                    }
                }
                else if(SafestCollectablePoint != Vector2i{} || SafestBlockPoint != Vector2i{} || SafestMonsterMapPoint != Vector2i{})
                {
                    Vector2 DistanceVec = Vector2{SafestTargetActionMapPoint.x - MyVec2InMine.X, SafestTargetActionMapPoint.y - MyVec2InMine.Y};
                    Vector2 DistanceMapPoint = Vector2{SafestTargetActionMapPoint.x - MyMapPointInMine.x, SafestTargetActionMapPoint.y - MyMapPointInMine.y};
                    Vector2 DistanceMapPointCorrection = Vector2{SafestTargetActionMapPoint.x - MyMapPointInMine.x, SafestTargetActionMapPoint.y - (MyMapPointInMine.y + 0.15f)};
                    if(DistanceVec.X < 0 && DistanceMapPoint.Y == 0)
                    {
                        int getBlock = World_GetBlockType(WorldInstantiate, MyMapPointInMine.x - 1, MyMapPointInMine.y);
                        int getShouldWalk = World_GetBlockType(WorldInstantiate, MyMapPointInMine.x, MyMapPointInMine.y - 1);
                        if(isSolidBlockInMine(getShouldWalk) || getShouldWalk == 3)
                        {
                            Player_SetVelocity(LocalPlayerInstantiate, VelocityGoLeftWalk);
                        }
                        else
                        {
                            Player_SetVelocity(LocalPlayerInstantiate, VelocityGoLeft);
                        }
                        if(isSolidBlockInMine(getBlock))
                        {
                            if(MineActionTimer > MineActionCooldown)
                            {
                                MineActionTimer = 0.0f;
                                OutgoingMessages_SendHitBlockMessage(Vector2i{MyMapPointInMine.x - 1, MyMapPointInMine.y}, DateTime{0}, false);
                            }
                        }
                    }
                    else if(DistanceVec.X > 0 && DistanceMapPoint.Y  == 0)
                    {
                        int getBlock = World_GetBlockType(WorldInstantiate, MyMapPointInMine.x + 1, MyMapPointInMine.y);
                        int getShouldWalk = World_GetBlockType(WorldInstantiate, MyMapPointInMine.x, MyMapPointInMine.y - 1);
                        if(isSolidBlockInMine(getShouldWalk) || getShouldWalk == 3)
                        {
                            Player_SetVelocity(LocalPlayerInstantiate, VelocityGoRightWalk);
                        }
                        else
                        {
                            Player_SetVelocity(LocalPlayerInstantiate, VelocityGoRight);
                        }
                        if(isSolidBlockInMine(getBlock))
                        {
                            if(MineActionTimer > MineActionCooldown)
                            {
                                MineActionTimer = 0.0f;
                                OutgoingMessages_SendHitBlockMessage(Vector2i{MyMapPointInMine.x + 1, MyMapPointInMine.y}, DateTime{0}, false);
                            }
                        }
                    }
                    else if(DistanceMapPoint.X == 0 && DistanceVec.Y < 0)
                    {
                        int getBlock = World_GetBlockType(WorldInstantiate, MyMapPointInMine.x, MyMapPointInMine.y - 1);
                        Player_SetVelocity(LocalPlayerInstantiate, VelocityGoDown);
                        if(isSolidBlockInMine(getBlock))
                        {
                            if(MineActionTimer > MineActionCooldown)
                            {
                                MineActionTimer = 0.0f;
                                OutgoingMessages_SendHitBlockMessage(Vector2i{MyMapPointInMine.x, MyMapPointInMine.y - 1}, DateTime{0}, false);
                            }
                        }
                    }
                    else if(DistanceMapPoint.X == 0 && DistanceVec.Y > 0)
                    {
                        int getBlock = World_GetBlockType(WorldInstantiate, MyMapPointInMine.x, MyMapPointInMine.y + 1);
                        int getBlockDown = World_GetBlockType(WorldInstantiate, MyMapPointInMine.x, MyMapPointInMine.y - 1);
                        Player_SetVelocity(LocalPlayerInstantiate, VelocityGoUp);
                        if((isSolidBlockInMine(getBlockDown) || getBlockDown == 3) && !isSolidBlockInMine(getBlock))
                        {
                            EnableJumpButton = true;
                        }
                        if(isSolidBlockInMine(getBlock))
                        {
                            if(MineActionTimer > MineActionCooldown)
                            {
                                MineActionTimer = 0.0f;
                                OutgoingMessages_SendHitBlockMessage(Vector2i{MyMapPointInMine.x, MyMapPointInMine.y + 1}, DateTime{0}, false);
                            }
                        }
                    }
                    else if(DistanceVec.X < 0 && DistanceMapPoint.Y < 0)
                    {
                        int getBlock = World_GetBlockType(WorldInstantiate, MyMapPointInMine.x, MyMapPointInMine.y - 1);
                        Player_SetVelocity(LocalPlayerInstantiate, VelocityGoDown);
                        if(isSolidBlockInMine(getBlock))
                        {
                            if(MineActionTimer > MineActionCooldown)
                            {
                                MineActionTimer = 0.0f;
                                OutgoingMessages_SendHitBlockMessage(Vector2i{MyMapPointInMine.x, MyMapPointInMine.y - 1}, DateTime{0}, false);
                            }
                        }
                    }
                    else if(DistanceVec.X > 0 && DistanceMapPoint.Y < 0)
                    {
                        int getBlock = World_GetBlockType(WorldInstantiate, MyMapPointInMine.x, MyMapPointInMine.y - 1);
                        Player_SetVelocity(LocalPlayerInstantiate, VelocityGoDown);
                        if(isSolidBlockInMine(getBlock))
                        {
                            if(MineActionTimer > MineActionCooldown)
                            {
                                MineActionTimer = 0.0f;
                                OutgoingMessages_SendHitBlockMessage(Vector2i{MyMapPointInMine.x, MyMapPointInMine.y - 1}, DateTime{0}, false);
                            }
                        }
                    }
                    else if(DistanceVec.X < 0 && DistanceMapPoint.Y > 0)
                    {
                        int getBlockLeft = World_GetBlockType(WorldInstantiate, MyMapPointInMine.x - 1, MyMapPointInMine.y);
                        int getBlockUp = World_GetBlockType(WorldInstantiate, MyMapPointInMine.x, MyMapPointInMine.y + 1);
                        int getBlockLeftUp = World_GetBlockType(WorldInstantiate, MyMapPointInMine.x -1, MyMapPointInMine.y + 1);
                        int getBlockDown = World_GetBlockType(WorldInstantiate, MyMapPointInMine.x, MyMapPointInMine.y - 1);
                        if((isSolidBlockInMine(getBlockDown) || getBlockDown == 3) && !isSolidBlockInMine(getBlockUp))
                        {
                            EnableJumpButton = true;
                        }
                        Player_SetVelocity(LocalPlayerInstantiate, VelocityGoLeftUp);
                        if(isSolidBlockInMine(getBlockLeft))
                        {
                            if(isSolidBlockInMine(getBlockUp))
                            {
                                if(MineActionTimer > MineActionCooldown)
                                {
                                    MineActionTimer = 0.0f;
                                    OutgoingMessages_SendHitBlockMessage(Vector2i{MyMapPointInMine.x, MyMapPointInMine.y + 1}, DateTime{0}, false);
                                }
                            }
                            else if(isSolidBlockInMine(getBlockLeftUp))
                            {
                                if(MineActionTimer > MineActionCooldown)
                                {
                                    MineActionTimer = 0.0f;
                                    OutgoingMessages_SendHitBlockMessage(Vector2i{MyMapPointInMine.x - 1, MyMapPointInMine.y + 1}, DateTime{0}, false);
                                }
                            }
                        }
                    }
                    else if(DistanceVec.X > 0 && DistanceMapPoint.Y > 0)
                    {
                        int getBlockRight = World_GetBlockType(WorldInstantiate, MyMapPointInMine.x + 1, MyMapPointInMine.y);
                        int getBlockUp = World_GetBlockType(WorldInstantiate, MyMapPointInMine.x, MyMapPointInMine.y + 1);
                        int getBlockRightUp = World_GetBlockType(WorldInstantiate, MyMapPointInMine.x + 1, MyMapPointInMine.y + 1);
                        int getBlockDown = World_GetBlockType(WorldInstantiate, MyMapPointInMine.x, MyMapPointInMine.y - 1);
                        Player_SetVelocity(LocalPlayerInstantiate, VelocityGoRightUp);
                        if((isSolidBlockInMine(getBlockDown) || getBlockDown == 3) && !isSolidBlockInMine(getBlockUp))
                        {
                            EnableJumpButton = true;
                        }
                        if(isSolidBlockInMine(getBlockRight))
                        {
                            if(isSolidBlockInMine(getBlockUp))
                            {
                                if(MineActionTimer > MineActionCooldown)
                                {
                                    MineActionTimer = 0.0f;
                                    OutgoingMessages_SendHitBlockMessage(Vector2i{MyMapPointInMine.x, MyMapPointInMine.y + 1}, DateTime{0}, false);
                                }
                            }
                            else if(isSolidBlockInMine(getBlockRightUp))
                            {
                                if(MineActionTimer > MineActionCooldown)
                                {
                                    MineActionTimer = 0.0f;
                                    OutgoingMessages_SendHitBlockMessage(Vector2i{MyMapPointInMine.x + 1, MyMapPointInMine.y + 1}, DateTime{0}, false);
                                }
                            }
                        }
                    }
                }
                else
                {
                    Vector2 DistanceVec = Vector2{SafestTargetActionMapPoint.x - MyVec2InMine.X, SafestTargetActionMapPoint.y - MyVec2InMine.Y};
                    Vector2 DistanceMapPoint = Vector2{SafestTargetActionMapPoint.x - MyMapPointInMine.x, SafestTargetActionMapPoint.y - MyMapPointInMine.y};
                    if(DistanceMapPoint.X == 0 && DistanceMapPoint.Y == 0)
                    {
                        if(exitOnce && MineActionTimer > MineActionCooldown)
                        {
                            exitOnce = false;
                            MineActionTimer = 0.0f;
                            OutgoingMessages_SendRequestGeneratedMineExitMessage(ExitDoorPoint);
                        }
                    }
                    else if(DistanceVec.X < 0 && DistanceMapPoint.Y == 0)
                    {
                        int getBlock = World_GetBlockType(WorldInstantiate, MyMapPointInMine.x - 1, MyMapPointInMine.y);
                        int getShouldWalk = World_GetBlockType(WorldInstantiate, MyMapPointInMine.x, MyMapPointInMine.y - 1);
                        if(isSolidBlockInMine(getShouldWalk) || getShouldWalk == 3)
                        {
                            Player_SetVelocity(LocalPlayerInstantiate, VelocityGoLeftWalk);
                        }
                        else
                        {
                            Player_SetVelocity(LocalPlayerInstantiate, VelocityGoLeft);
                        }
                        if(isSolidBlockInMine(getBlock))
                        {
                            if(MineActionTimer > MineActionCooldown)
                            {
                                MineActionTimer = 0.0f;
                                OutgoingMessages_SendHitBlockMessage(Vector2i{MyMapPointInMine.x - 1, MyMapPointInMine.y}, DateTime{0}, false);
                            }
                        }
                    }
                    else if(DistanceVec.X > 0 && DistanceMapPoint.Y  == 0)
                    {
                        int getBlock = World_GetBlockType(WorldInstantiate, MyMapPointInMine.x + 1, MyMapPointInMine.y);
                        int getShouldWalk = World_GetBlockType(WorldInstantiate, MyMapPointInMine.x, MyMapPointInMine.y - 1);
                        if(isSolidBlockInMine(getShouldWalk) || getShouldWalk == 3)
                        {
                            Player_SetVelocity(LocalPlayerInstantiate, VelocityGoRightWalk);
                        }
                        else
                        {
                            Player_SetVelocity(LocalPlayerInstantiate, VelocityGoRight);
                        }
                        if(isSolidBlockInMine(getBlock))
                        {
                            if(MineActionTimer > MineActionCooldown)
                            {
                                MineActionTimer = 0.0f;
                                OutgoingMessages_SendHitBlockMessage(Vector2i{MyMapPointInMine.x + 1, MyMapPointInMine.y}, DateTime{0}, false);
                            }
                        }
                    }
                    else if(DistanceMapPoint.X == 0 && DistanceVec.Y < 0)
                    {
                        int getBlock = World_GetBlockType(WorldInstantiate, MyMapPointInMine.x, MyMapPointInMine.y - 1);
                        Player_SetVelocity(LocalPlayerInstantiate, VelocityGoDown);
                        if(isSolidBlockInMine(getBlock))
                        {
                            if(MineActionTimer > MineActionCooldown)
                            {
                                MineActionTimer = 0.0f;
                                OutgoingMessages_SendHitBlockMessage(Vector2i{MyMapPointInMine.x, MyMapPointInMine.y - 1}, DateTime{0}, false);
                            }
                        }
                    }
                    else if(DistanceMapPoint.X == 0 && DistanceVec.Y > 0)
                    {
                        int getBlock = World_GetBlockType(WorldInstantiate, MyMapPointInMine.x, MyMapPointInMine.y + 1);
                        int getBlockDown = World_GetBlockType(WorldInstantiate, MyMapPointInMine.x, MyMapPointInMine.y - 1);
                        Player_SetVelocity(LocalPlayerInstantiate, VelocityGoUp);
                        if((isSolidBlockInMine(getBlockDown) || getBlockDown == 3) && !isSolidBlockInMine(getBlock))
                        {
                            EnableJumpButton = true;
                        }
                        if(isSolidBlockInMine(getBlock))
                        {
                            if(MineActionTimer > MineActionCooldown)
                            {
                                MineActionTimer = 0.0f;
                                OutgoingMessages_SendHitBlockMessage(Vector2i{MyMapPointInMine.x, MyMapPointInMine.y + 1}, DateTime{0}, false);
                            }
                        }
                    }
                    else if(DistanceVec.X < 0 && DistanceMapPoint.Y < 0)
                    {
                        int getBlock = World_GetBlockType(WorldInstantiate, MyMapPointInMine.x, MyMapPointInMine.y - 1);
                        Player_SetVelocity(LocalPlayerInstantiate, VelocityGoDown);
                        if(isSolidBlockInMine(getBlock))
                        {
                            if(MineActionTimer > MineActionCooldown)
                            {
                                MineActionTimer = 0.0f;
                                OutgoingMessages_SendHitBlockMessage(Vector2i{MyMapPointInMine.x, MyMapPointInMine.y - 1}, DateTime{0}, false);
                            }
                        }
                    }
                    else if(DistanceVec.X > 0 && DistanceMapPoint.Y < 0)
                    {
                        int getBlock = World_GetBlockType(WorldInstantiate, MyMapPointInMine.x, MyMapPointInMine.y - 1);
                        Player_SetVelocity(LocalPlayerInstantiate, VelocityGoDown);
                        if(isSolidBlockInMine(getBlock))
                        {
                            if(MineActionTimer > MineActionCooldown)
                            {
                                MineActionTimer = 0.0f;
                                OutgoingMessages_SendHitBlockMessage(Vector2i{MyMapPointInMine.x, MyMapPointInMine.y - 1}, DateTime{0}, false);
                            }
                        }
                    }
                    else if(DistanceVec.X < 0 && DistanceMapPoint.Y > 0)
                    {
                        int getBlockLeft = World_GetBlockType(WorldInstantiate, MyMapPointInMine.x - 1, MyMapPointInMine.y);
                        int getBlockUp = World_GetBlockType(WorldInstantiate, MyMapPointInMine.x, MyMapPointInMine.y + 1);
                        int getBlockLeftUp = World_GetBlockType(WorldInstantiate, MyMapPointInMine.x -1, MyMapPointInMine.y + 1);
                        int getBlockDown = World_GetBlockType(WorldInstantiate, MyMapPointInMine.x, MyMapPointInMine.y - 1);
                        if((isSolidBlockInMine(getBlockDown) || getBlockDown == 3) && !isSolidBlockInMine(getBlockUp))
                        {
                            EnableJumpButton = true;
                        }
                        Player_SetVelocity(LocalPlayerInstantiate, VelocityGoLeftUp);
                        if(isSolidBlockInMine(getBlockLeft))
                        {
                            if(isSolidBlockInMine(getBlockUp))
                            {
                                if(MineActionTimer > MineActionCooldown)
                                {
                                    MineActionTimer = 0.0f;
                                    OutgoingMessages_SendHitBlockMessage(Vector2i{MyMapPointInMine.x, MyMapPointInMine.y + 1}, DateTime{0}, false);
                                }
                            }
                            else if(isSolidBlockInMine(getBlockLeftUp))
                            {
                                if(MineActionTimer > MineActionCooldown)
                                {
                                    MineActionTimer = 0.0f;
                                    OutgoingMessages_SendHitBlockMessage(Vector2i{MyMapPointInMine.x - 1, MyMapPointInMine.y + 1}, DateTime{0}, false);
                                }
                            }
                        }
                    }
                    else if(DistanceVec.X > 0 && DistanceMapPoint.Y > 0)
                    {
                        int getBlockRight = World_GetBlockType(WorldInstantiate, MyMapPointInMine.x + 1, MyMapPointInMine.y);
                        int getBlockUp = World_GetBlockType(WorldInstantiate, MyMapPointInMine.x, MyMapPointInMine.y + 1);
                        int getBlockRightUp = World_GetBlockType(WorldInstantiate, MyMapPointInMine.x + 1, MyMapPointInMine.y + 1);
                        int getBlockDown = World_GetBlockType(WorldInstantiate, MyMapPointInMine.x, MyMapPointInMine.y - 1);
                        Player_SetVelocity(LocalPlayerInstantiate, VelocityGoRightUp);
                        if((isSolidBlockInMine(getBlockDown) || getBlockDown == 3) && !isSolidBlockInMine(getBlockUp))
                        {
                            EnableJumpButton = true;
                        }
                        if(isSolidBlockInMine(getBlockRight))
                        {
                            if(isSolidBlockInMine(getBlockUp))
                            {
                                if(MineActionTimer > MineActionCooldown)
                                {
                                    MineActionTimer = 0.0f;
                                    OutgoingMessages_SendHitBlockMessage(Vector2i{MyMapPointInMine.x, MyMapPointInMine.y + 1}, DateTime{0}, false);
                                }
                            }
                            else if(isSolidBlockInMine(getBlockRightUp))
                            {
                                if(MineActionTimer > MineActionCooldown)
                                {
                                    MineActionTimer = 0.0f;
                                    OutgoingMessages_SendHitBlockMessage(Vector2i{MyMapPointInMine.x + 1, MyMapPointInMine.y + 1}, DateTime{0}, false);
                                }
                            }
                        }
                    }
                }
            }

            MineSafestMonster = nullptr;
        }
    }
}

void Auto_Repair_Pickaxe(void *myPlayerData)
{
    if(EnableAutoMine)
    {
        switch (current_pickaxe) {
            case 0:
                PickaxeID = 4087;
                break;
            case 1:
                PickaxeID = 4088;
                break;
            case 2:
                PickaxeID = 4089;
                break;
            case 3:
                PickaxeID = 4090;
                break;
            case 4:
                PickaxeID = 4091;
                break;
            case 5:
                PickaxeID = 4092;
                break;
            case 6:
                PickaxeID = 4093;
                break;
            case 7:
                PickaxeID = 4195;
                break;
        }

        monoList<void **> *GetPlayerWearWerablesAndWeaponInventoryDatas = PlayerData_GetPlayerWearWerablesAndWeaponInventoryDatas(myPlayerData);
        for (int i = 0; i < GetPlayerWearWerablesAndWeaponInventoryDatas->getSize(); ++i) {
            void *GetPlayerWearWerablesAndWeaponInventoryData = GetPlayerWearWerablesAndWeaponInventoryDatas->getItems()[i];
            if(GetPlayerWearWerablesAndWeaponInventoryData != nullptr)
            {
                int blockType = *(int *)((uint64_t)GetPlayerWearWerablesAndWeaponInventoryData + PixelWorlds.InventoryItemBase_blockType);
                if(PickaxeID == blockType)
                {
                    if(current_pickaxe == 0)
                    {
                        int durability = WeaponPickaxeCrappyInventoryData_GetDurability(GetPlayerWearWerablesAndWeaponInventoryData);
                        if(durability < 1)
                        {
                            if(repairOnce && worldType == 18)
                            {
                                repairOnce = false;
                                OutgoingMessages_MiningPickaxeRepairing(InventoryKey{PickaxeID, 5});
                            }
                        }
                    }
                    else if(current_pickaxe == 1)
                    {
                        int durability = WeaponPickaxeFlimsyInventoryData_GetDurability(GetPlayerWearWerablesAndWeaponInventoryData);
                        if(durability < 1)
                        {
                            if(repairOnce && worldType == 18)
                            {
                                repairOnce = false;
                                OutgoingMessages_MiningPickaxeRepairing(InventoryKey{PickaxeID, 5});
                            }
                        }
                    }
                    else if(current_pickaxe == 2)
                    {
                        int durability = WeaponPickaxeBasicInventoryData_GetDurability(GetPlayerWearWerablesAndWeaponInventoryData);
                        if(durability < 1)
                        {
                            if(repairOnce && worldType == 18)
                            {
                                repairOnce = false;
                                OutgoingMessages_MiningPickaxeRepairing(InventoryKey{PickaxeID, 5});
                            }
                        }
                    }
                    else if(current_pickaxe == 3)
                    {
                        int durability = WeaponPickaxeSturdyInventoryData_GetDurability(GetPlayerWearWerablesAndWeaponInventoryData);
                        if(durability < 1)
                        {
                            if(repairOnce && worldType == 18)
                            {
                                repairOnce = false;
                                OutgoingMessages_MiningPickaxeRepairing(InventoryKey{PickaxeID, 5});
                            }
                        }
                    }
                    else if(current_pickaxe == 4)
                    {
                        int durability = WeaponPickaxeHeavyInventoryData_GetDurability(GetPlayerWearWerablesAndWeaponInventoryData);
                        if(durability < 1)
                        {
                            if(repairOnce && worldType == 18)
                            {
                                repairOnce = false;
                                OutgoingMessages_MiningPickaxeRepairing(InventoryKey{PickaxeID, 5});
                            }
                        }
                    }
                    else if(current_pickaxe == 5)
                    {
                        int durability = WeaponPickaxeMasterInventoryData_GetDurability(GetPlayerWearWerablesAndWeaponInventoryData);
                        if(durability < 1)
                        {
                            if(repairOnce && worldType == 18)
                            {
                                repairOnce = false;
                                OutgoingMessages_MiningPickaxeRepairing(InventoryKey{PickaxeID, 5});
                            }
                        }
                    }
                    else if(current_pickaxe == 6)
                    {
                        int durability = WeaponPickaxeEpicInventoryData_GetDurability(GetPlayerWearWerablesAndWeaponInventoryData);
                        if(durability < 1)
                        {
                            if(repairOnce && worldType == 18)
                            {
                                repairOnce = false;
                                OutgoingMessages_MiningPickaxeRepairing(InventoryKey{PickaxeID, 5});
                            }
                        }

                    }
                    else if(current_pickaxe == 7)
                    {
                        int durability = WeaponPickaxeDarkInventoryData_GetDurability(GetPlayerWearWerablesAndWeaponInventoryData);
                        if(durability < 1)
                        {
                            if(repairOnce && worldType == 18)
                            {
                                repairOnce = false;
                                OutgoingMessages_MiningPickaxeRepairing(InventoryKey{PickaxeID, 5});
                            }
                        }
                    }
                }
            }
        }
    }
}

void autoConvertToKey(void *myPlayerData)
{
    if(DoOnceConvertNugget && EnableConvertNuggets)
    {
        monoArray<InventoryKey *> *GetInventoryAsOrderedByInventoryItemType = PlayerData_GetInventoryAsOrderedByInventoryItemType(myPlayerData);
        for (int i = 0; i < GetInventoryAsOrderedByInventoryItemType->getLength(); ++i)
        {
            InventoryKey GetInventoryAsOrderedByInventoryItem = GetInventoryAsOrderedByInventoryItemType->getPointer()[i];
            if(ConfigData_IsMiningNugget(GetInventoryAsOrderedByInventoryItem.blockType))
            {
                if(PlayerData_GetCount(myPlayerData, GetInventoryAsOrderedByInventoryItem) >= 100)
                {
                    OutgoingMessages_ConvertItems(GetInventoryAsOrderedByInventoryItem);
                    DoOnceConvertNugget = false;
                }
            }
        }
    }
}

#endif //CSY_MINE_H
