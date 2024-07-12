#ifndef CSY_PLAYER_H
#define CSY_PLAYER_H

void (*old_Player_CheckInvertedControls)(void *instance);
void Player_CheckInvertedControls(void *instance)
{
    if(instance != nullptr)
    {
        if(EnableAntiInvertedControls)
        {
            return;
        }
    }
    old_Player_CheckInvertedControls(instance);
}

void (*old_Player_CheckPortals)(void *instance);
void Player_CheckPortals(void *instance)
{
    if(instance != nullptr)
    {
        if(EnableAntiPortal)
        {
            return;
        }
    }
    old_Player_CheckPortals(instance);
}

void (*old_Player_CheckCheckPoints)(void *instance);
void Player_CheckCheckPoints(void *instance)
{
    if(instance != nullptr)
    {
        if(EnableAntiCheckPoint)
        {
            return;
        }
    }
    old_Player_CheckCheckPoints(instance);
}

bool (*Player_IsPlayerInMapPoint)(void *instance, Vector2i mapPoint);

bool IsPlayerInMapPoint(void *instance)
{
    if(instance != nullptr)
    {
        Vector2i currentPlayerMapPoint = *(Vector2i *)((uint64_t)instance + PixelWorlds.Player_currentPlayerMapPoint);
        return Player_IsPlayerInMapPoint(instance, currentPlayerMapPoint);
    }
    return false;
}

bool IsPlayerDead(void *instance)
{
    if(instance != nullptr)
    {
        return *(bool *)((uint64_t)instance + PixelWorlds.Player_isDead);
    }
    return false;
}

struct PlayerList_t {
    void *object;

};

class PlayerListManager {
public:
    std::vector<PlayerList_t *> *enemies;

    PlayerListManager() {
        enemies = new std::vector<PlayerList_t *>();
    }
    bool isEnemyPresent(void *enemyObject) {
        for (std::vector<PlayerList_t *>::iterator it = enemies->begin(); it != enemies->end(); it++) {
            if ((*it)->object == enemyObject) {
                return true;
            }
        }
        return false;
    }
    void removeEnemy(PlayerList_t *enemy) {
        for (int i = 0; i < enemies->size(); i++) {
            if ((*enemies)[i] == enemy) {
                enemies->erase(enemies->begin() + i);
                return;
            }
        }
    }
    void tryAddEnemy(void *enemyObject) {
        if (isEnemyPresent(enemyObject)) {
            return;
        }

        if(IsPlayerDead(enemyObject))
        {
            return;
        }

        if(!IsPlayerInMapPoint(enemyObject))
        {
            return;
        }

        PlayerList_t *newEnemy = new PlayerList_t();

        newEnemy->object = enemyObject;

        enemies->push_back(newEnemy);
    }
    void updateEnemies(void *enemyObject) {
        for (int i = 0; i < enemies->size(); i++) {
            PlayerList_t *current = (*enemies)[i];

            if(IsPlayerDead(current->object))
            {
                enemies->erase(enemies->begin() + i);
            }
            if(!IsPlayerInMapPoint(current->object))
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
PlayerListManager *playerListManager;

void (*old_Player_Update)(void *instance);
void Player_Update(void *instance)
{
    if(instance != nullptr)
    {
        if(!IsPlayerDead(instance) && IsPlayerInMapPoint(instance))
            playerListManager->tryAddEnemy(instance);

        playerListManager->updateEnemies(instance);

        bool isLocal = *(bool *)((uint64_t)instance + PixelWorlds.Player_isLocalPlayer);
        if(isLocal)
        {
            CustomWearable(instance);

            LocalPlayerInstantiate = instance;
            MyMapPoint = *(Vector2i *)((uint64_t)instance + PixelWorlds.Player_currentPlayerMapPoint);

            Vector2 boxSize = *(Vector2 *) ((uint64_t)instance + PixelWorlds.Player_playerBoxColliderSize);
            boxSizeY = boxSize.Y;
            void *myTransform = *(void **)((uint64_t)instance + PixelWorlds.Player_myTransform);
            if(myTransform != nullptr)
            {
                Vector3 MyPos = Transform_get_position(myTransform);
                MyPositionOK = MyPos;
                MyMapPointVec2 = ConvertWorldPointToMapPoint(Vector2{MyPos.X, MyPos.Y});
                MyWorldToScreenVec2 = WorldToScreenVec2(Vector2{MyPos.X , MyPos.Y});
            }

            if(setJumpModeID > 0)
            {
                *(int *)((uint64_t)instance + PixelWorlds.Player_jumpMode) = (int)(setJumpModeID - 1);
            }

            if(setFistCooldown >= 0.7f && setFistCooldown <= 1.0f)
            {
                *(float *)((uint64_t)instance + PixelWorlds.Player_cooldownToUseFistMultiplier) = setFistCooldown;
            }
            else
            {
                *(float *)((uint64_t)instance + PixelWorlds.Player_cooldownToUseFistMultiplier) = 1.0f;
            }


            if(EnableJumpButton)
            {
                EnableJumpButton = false;
                *(bool *)((uint64_t) instance + PixelWorlds.Player_jumpButtonDown) = true;
                *(bool *)((uint64_t) instance + PixelWorlds.Player_jumpButton) = true;
            }

            void *myPlayerData = *(void **)((uint64_t)instance + PixelWorlds.Player_myPlayerData);
            if(myPlayerData != nullptr)
            {
                MyPlayerData = myPlayerData;

                add_item(myPlayerData);

                playerMaxHealth = PlayerData_GetMaxHitPoints(myPlayerData);
                int currentHealth = *(int *)((uint64_t)myPlayerData + PixelWorlds.PlayerData_health);
                autoHealing(playerMaxHealth, currentHealth);
                Auto_Repair_Pickaxe(myPlayerData);
                autoConvertToKey(myPlayerData);
            }

            void *playerNameTextMeshPro = *(void **)((uint64_t)instance + PixelWorlds.Player_playerNameTextMeshPro);
            if(playerNameTextMeshPro != nullptr)
            {
                TMP_Text_SetText(playerNameTextMeshPro, CreateIl2cppString(PlayerName));
            }

            //TPByTouch(instance);
        }
    }
    old_Player_Update(instance);
}

#endif
