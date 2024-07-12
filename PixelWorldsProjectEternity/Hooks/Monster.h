#ifndef CSY_MONSTER_H
#define CSY_MONSTER_H

bool (*AIBase_IsAlive)(void *instance);

bool IsAiEnemyAlive(void *instance)
{
    if(instance != nullptr)
    {
        void *AiBAse = *(void **)((uint64_t)instance + PixelWorlds.AIEnemyMonoBehaviourBase_aiBase);
        if(AiBAse != nullptr)
        {
            return AIBase_IsAlive(AiBAse);
        }
    }
    return false;
}

bool IsSpellOrBullet(void *instance)
{
    if(instance != nullptr)
    {
        void *aiBase = *(void **)((uint64_t)instance + PixelWorlds.AIEnemyMonoBehaviourBase_aiBase);
        if(aiBase != nullptr)
        {
            int enemyType = *(int *)((uint64_t)aiBase + PixelWorlds.AIBase_enemyType);
            if(enemyType == 8 || enemyType == 9 || enemyType == 11 || enemyType == 16 || enemyType == 18 || enemyType == 20 || enemyType == 22 || enemyType == 23 || enemyType == 24 || enemyType == 25 || enemyType == 26 || enemyType == 27 || enemyType == 28 || enemyType == 29 || enemyType == 30 || enemyType == 31 || enemyType == 32 || enemyType == 33 || enemyType == 34 || enemyType ==  35 || enemyType == 36 || enemyType == 37 || enemyType == 38 || enemyType == 39 || enemyType == 40 || enemyType == 41 || enemyType == 42 || enemyType == 43 || enemyType == 44 || enemyType == 47  || enemyType == 48  || enemyType == 53  || enemyType == 54)
            {
                return true;
            }
        }
    }
    return false;
}

void MonsterOnDeath(void *instance)
{
    if(instance != nullptr)
    {
        void *AiBAse = *(void **)((uint64_t)instance + PixelWorlds.AIEnemyMonoBehaviourBase_aiBase);
        if(AiBAse != nullptr)
        {
            AIBase_OnDeath(AiBAse);
        }
    }
}

bool IsHideAndSpawn(void *instance)
{
    if(instance != nullptr)
    {
        void *AiBAse = *(void **)((uint64_t)instance + PixelWorlds.AIEnemyMonoBehaviourBase_aiBase);
        if(AiBAse != nullptr)
        {
            if(AIBase_GetCurrentAIBehaviorType(AiBAse) == 28)
            {
                return true;
            }
        }
    }
    return false;
}

bool IsGassyMonster(void *instance)
{
    if(instance != nullptr)
    {
        void *aiBase = *(void **)((uint64_t)instance + PixelWorlds.AIEnemyMonoBehaviourBase_aiBase);
        if(aiBase != nullptr)
        {
            int enemyType = *(int *)((uint64_t)aiBase + PixelWorlds.AIBase_enemyType);
            if(enemyType == 51)
            {
                return true;
            }
        }
    }
    return false;
}

bool IsAiEnemyActive(void *instance)
{
    if(instance != nullptr)
    {
        return AIEnemyMonoBehaviourBase_GetIsActive(instance);
    }
    return false;
}

Vector2 GetAiEnemyLocation(void *instance)
{
    if(instance != nullptr)
    {
        void *AiBAse = *(void **)((uint64_t)instance + PixelWorlds.AIEnemyMonoBehaviourBase_aiBase);
        if(AiBAse != nullptr)
        {
            return Vector2{
                    *(float *)((uint64_t)AiBAse + PixelWorlds.AIBase_mapPointX),
                    *(float *)((uint64_t)AiBAse + PixelWorlds.AIBase_mapPointY)
            };
        }
    }
}

int GetAiEnemyID(void *instance)
{
    if(instance != nullptr)
    {
        void *AiBAse = *(void **)((uint64_t)instance + PixelWorlds.AIEnemyMonoBehaviourBase_aiBase);
        if(AiBAse != nullptr)
        {
            return *(int *)((uint64_t)AiBAse + PixelWorlds.AIBase_id);
        }
    }
    return -1;
}

Vector2 GetAiEnemyWorldToScreen(void *instance)
{
    if(instance != nullptr)
    {
        Vector2 Position = GetAiEnemyLocation(instance);
        auto convertMapPointToWorldPoint = ConvertMapPointToWorldPoint(Position.X, Position.Y);
        return WorldToScreenVec2(convertMapPointToWorldPoint);
    }
}


struct AiEnemy_t {
    void *object;
    int health;
};

class AIEnemyManager {
public:
    std::vector<AiEnemy_t *> *enemies;

    AIEnemyManager() {
        enemies = new std::vector<AiEnemy_t *>();
    }

    bool isEnemyPresent(void *enemyObject) {
        for (std::vector<AiEnemy_t *>::iterator it = enemies->begin(); it != enemies->end(); it++) {
            if ((*it)->object == enemyObject) {
                return true;
            }
        }

        return false;
    }

    void removeEnemy(AiEnemy_t *enemy) {
        for (int i = 0; i < enemies->size(); i++) {
            if ((*enemies)[i] == enemy) {
                enemies->erase(enemies->begin() + i);

                return;
            }
        }
    }

    void tryAddEnemy(void *enemyObject)
    {
        if (isEnemyPresent(enemyObject))
        {
            return;
        }

        if(!IsAiEnemyAlive(enemyObject))
        {
            return;
        }

        if(!IsAiEnemyActive(enemyObject))
        {
            return;
        }

        if(IsGassyMonster(enemyObject))
        {
            return;
        }

        if(IsSpellOrBullet(enemyObject))
        {
            return;
        }

        AiEnemy_t *newEnemy = new AiEnemy_t();

        newEnemy->object = enemyObject;

        enemies->push_back(newEnemy);
    }

    void updateEnemies(void *enemyObject) {
        for (int i = 0; i < enemies->size(); i++) {
            AiEnemy_t *current = (*enemies)[i];

            if(!IsAiEnemyAlive(current->object))
            {
                enemies->erase(enemies->begin() + i);
            }

            if(!IsAiEnemyActive(current->object))
            {
                enemies->erase(enemies->begin() + i);
            }

            if(IsGassyMonster(current->object))
            {
                enemies->erase(enemies->begin() + i);
            }

            if(IsSpellOrBullet(current->object))
            {
                enemies->erase(enemies->begin() + i);
            }
        }
    }

    void removeEnemyGivenObject(void *enemyObject) {
        for (int i = 0; i < enemies->size(); i++) {
            if ((*enemies)[i]->object == enemyObject) {
                enemies->erase(enemies->begin() + i);
                return;
            }
        }
    }
};
AIEnemyManager *aIEnemyManager;

void (*old_AIEnemyMonoBehaviourBase_Update)(void *instance);
void AIEnemyMonoBehaviourBase_Update(void *instance)
{
    if(instance != nullptr)
    {
        if(EnableDisableAiEnemy)
        {
            MonsterOnDeath(instance);
        }
        else
        {
            if(NetherBeforeStart <= 5.0f)
            {
                if(refreshEntity)
                {
                    if(!aIEnemyManager->enemies->empty())
                    {
                        for (int i = 0; i < aIEnemyManager->enemies->size(); i++) {
                            (*aIEnemyManager->enemies)[i]->object = nullptr;
                        }
                    }
                    refreshEntity = false;
                }
                if(IsAiEnemyActive(instance) && IsAiEnemyAlive(instance) && !IsGassyMonster(instance) && !IsSpellOrBullet(instance))
                {
                    aIEnemyManager->tryAddEnemy(instance);
                }
                aIEnemyManager->updateEnemies(instance);
            }
        }
    }
    old_AIEnemyMonoBehaviourBase_Update(instance);
}

void PixelWorldsEntity()
{
    if (aIEnemyManager->enemies->empty())
    {
        return;
    }

    if(worldType == 5 || worldType == 9 || worldType == 11 || worldType == 18)
    {
        float ClosestMonster = INFINITY;
        float AutoMineClosestMonster = INFINITY;
        float MineClosestMonsterMoveTo = INFINITY;
        float HighestMonster = 0.f;
        for (int i = 0; i < aIEnemyManager->enemies->size(); i++) {
            void *AiEnemies = (*aIEnemyManager->enemies)[i]->object;
            if (IsAiEnemyAlive(AiEnemies) && IsAiEnemyActive(AiEnemies) && !IsSpellOrBullet(AiEnemies))
            {
                auto AiEnemyLocation = GetAiEnemyLocation(AiEnemies);
                void *AiBase = *(void **)((uint64_t)AiEnemies + PixelWorlds.AIEnemyMonoBehaviourBase_aiBase);
                if(AiBase != nullptr) {
                    int enemyType = *(int *)((uint64_t)AiBase + PixelWorlds.AIBase_enemyType);

                    if (EnableNetherAimbot || EnableSuperHeroAimbot) {
                        if (!IsSpellOrBullet(AiEnemies)) {
                            Vector2 distance = Vector2{MyMapPoint.x - AiEnemyLocation.X, MyMapPoint.y - AiEnemyLocation.Y};
                            float Pytha = sqrt((distance.X * distance.X) + (distance.Y * distance.Y));
                            if (Pytha <= ClosestMonster) {
                                ClosestMonster = Pytha;
                                if (Pytha < 2.82f) {
                                    CloserMonster = AiEnemies;
                                }
                            }
                        }
                    }

                    if(EnableAutoKillMonster && !IsHideAndSpawn(AiEnemies)) //Safest Monster
                    {
                        if(MyMapPoint.y + 1 >= AiEnemyLocation.Y)
                        {
                            Vector2 distance = Vector2{MyMapPoint.x - AiEnemyLocation.X,MyMapPoint.y - AiEnemyLocation.Y};
                            float Pytha = sqrt((distance.X * distance.X) + (distance.Y * distance.Y));
                            if (Pytha < AutoMineClosestMonster) {
                                AutoMineClosestMonster = Pytha;
                                if (Pytha < 2.82f) {
                                    MineClosestMonster = AiEnemies;
                                }
                            }
                        }
                        if(MyMapPoint.y >= AiEnemyLocation.Y && enemyType == 52)
                        {
                            if (HighestMonster < AiEnemyLocation.Y)
                            {
                                MineClosestMonsterMoveTo = INFINITY;
                                HighestMonster = AiEnemyLocation.Y;
                                MineSafestMonster = AiEnemies;
                                Vector2 distance = Vector2{MyMapPoint.x - AiEnemyLocation.X,MyMapPoint.y - AiEnemyLocation.Y};
                                float Pytha = sqrt((distance.X * distance.X) + (distance.Y * distance.Y));
                                if (Pytha <= MineClosestMonsterMoveTo) {
                                    MineClosestMonsterMoveTo = Pytha;
                                }
                            }
                            else if(HighestMonster == AiEnemyLocation.Y)
                            {
                                Vector2 distance = Vector2{MyMapPoint.x - AiEnemyLocation.X,MyMapPoint.y - AiEnemyLocation.Y};
                                float Pytha = sqrt((distance.X * distance.X) + (distance.Y * distance.Y));
                                if (Pytha < MineClosestMonsterMoveTo) {
                                    MineClosestMonsterMoveTo = Pytha;
                                    MineSafestMonster = AiEnemies;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

}

#endif
