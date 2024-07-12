#ifndef CSY_ESP_H
#define CSY_ESP_H

static bool EnableESPLine = false;
static bool EnableESPBox = false;
static bool EnableESPHealthBar = false;
static bool EnableESPMonster = false;
static ImColor ESPMonster = ColorImGui_Red;
static ImColor ESPBoss = ColorImGui_BlueGreen;
static bool EnableESPPlayer = false;
static ImColor ESPPlayer = ColorImGui_Orange;
static bool EnableESPCollectable = false;
static ImColor ESPCollectable = ColorImGui_Purple;
static bool EnableESPButterfly = false;
static ImColor ESPButterFly = ColorImGui_OrangeRed;
static bool EnableESPSpirit = false;
static ImColor ESPSpirit = ColorImGui_PurpleBlue;

static bool EnableESPMineGemstone = false;
static ImColor ESPMineGemstone = ColorImGui_Green;
static bool EnableESPMineCrate = false;
static ImColor ESPMineCrate = ColorImGui_Blue;
static bool EnableESPMineExit = false;
static ImColor ESPMineExit = ColorImGui_White;

static bool EnableESPNetherGiftBox = false;
static ImColor ESPNetherGiftBox = ColorImGui_Green;
static bool EnableESPNetherTreasureBox = false;
static ImColor ESPNetherTreasureBox = ColorImGui_Yellow;
static bool EnableESPNetherSpecialItem = false;
static ImColor ESPNetherSpecialItem = ColorImGui_Blue;
static bool EnableESPNetherExit = false;
static ImColor ESPNetherExit = ColorImGui_White;

void DrawESP()
{
    int width = Screen_get_width();
    int height = Screen_get_height();
    ImGui::SetNextWindowSize(ImVec2(width, height));
    ImGui::Begin(OBFUSCATE("ESP"), nullptr,ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_NoBackground |ImGuiWindowFlags_NoDecoration);
    ImDrawList *drawList = ImGui::GetWindowDrawList();
    drawList->PushClipRectFullScreen();
    if(!checkIsPlayerInMenu)
    {
        if(EnableESPPlayer)
        {
            if (playerListManager->enemies->empty())
            {
                return;
            }

            for (int i = 0; i < playerListManager->enemies->size(); i++)
            {
                void *Player = (*playerListManager->enemies)[i]->object;
                if (!IsPlayerDead(Player) && IsPlayerInMapPoint(Player))
                {
                    bool isLocal = *(bool *) ((uint64_t) Player + PixelWorlds.Player_isLocalPlayer);
                    Vector2 boxSize = *(Vector2 *) ((uint64_t) Player + PixelWorlds.Player_playerBoxColliderSize);
                    Vector2 reSizeBox = Vector2{boxSize.X * 1.2f, boxSize.Y * 1.2};
                    auto ScreenBox = ScaleToScreen(reSizeBox);
                    void *myTransform = *(void **) ((uint64_t) Player + PixelWorlds.Player_myTransform);
                    if (myTransform != nullptr && !isLocal)
                    {
                        Vector3 MyPos = Transform_get_position(myTransform);
                        auto worldToScreen = WorldToScreenVec2(Vector2{MyPos.X, MyPos.Y});
                        if (EnableESPLine)
                        {
                            drawList->AddLine(ImVec2(MyWorldToScreenVec2.X, MyWorldToScreenVec2.Y),ImVec2(worldToScreen.X, worldToScreen.Y),ImColor(ESPPlayer));
                        }
                        if (EnableESPBox)
                        {
                            drawList->AddRect(ImVec2(worldToScreen.X - (ScreenBox.X / 2),worldToScreen.Y - ScreenBox.Y),ImVec2(worldToScreen.X + (ScreenBox.X / 2), worldToScreen.Y),ImColor(ESPPlayer), 0.1f, 15);
                        }
                    }
                }
                else
                {
                    playerListManager->removeEnemyGivenObject(Player);
                }
            }
        }

        if(EnableESPMonster && NetherBeforeStart <= .5f)
        {
            if (aIEnemyManager->enemies->empty())
            {
                return;
            }

            if (worldType == 5 || worldType == 9 || worldType == 11 || worldType == 18)
            {
                for (int i = 0; i < aIEnemyManager->enemies->size(); i++)
                {
                    void *AiEnemies = (*aIEnemyManager->enemies)[i]->object;
                    if (IsAiEnemyAlive(AiEnemies) && IsAiEnemyActive(AiEnemies) &&
                        !IsSpellOrBullet(AiEnemies)) {
                        float sizeOffsetMonster = PixelPerfectCamera_cameraZoom * 15.0f;
                        float BossOffsetMonster = PixelPerfectCamera_cameraZoom * 20.0f;
                        auto worldToScreen = GetAiEnemyWorldToScreen(AiEnemies);
                        void *AiBase = *(void **) ((uint64_t) AiEnemies + PixelWorlds.AIEnemyMonoBehaviourBase_aiBase);
                        if (AiBase != nullptr) {
                            int enemyType = *(int *) ((uint64_t) AiBase + PixelWorlds.AIBase_enemyType);
                            //Health
                            int maxHealth = ConfigData_GetMaxHitPoints(enemyType);
                            int currentHealth = *(int *)((uint64_t)AiBase + PixelWorlds.AIBase_health);
                            int healthPercent = (currentHealth / maxHealth) * 100;
                            int redHealth = 250 - healthPercent * 2.55;
                            int greenHealth = healthPercent * 2.55;
                            //
                            if (enemyType == 21) //Laboratory Boss
                            {
                                if (EnableESPLine)
                                {
                                    drawList->AddLine(ImVec2(MyWorldToScreenVec2.X,MyWorldToScreenVec2.Y),ImVec2(worldToScreen.X, worldToScreen.Y + BossOffsetMonster),ImColor(ESPBoss));
                                }
                                if (EnableESPBox)
                                {
                                    drawList->AddRect(ImVec2(worldToScreen.X - BossOffsetMonster,worldToScreen.Y - (BossOffsetMonster * 2.7f)),ImVec2(worldToScreen.X + (BossOffsetMonster * 2.5f),worldToScreen.Y + BossOffsetMonster),ImColor(ESPBoss), 0.1f, 15);
                                }
                            }
                            else if (enemyType == 46) //Nether Boss
                            {
                                if (EnableESPLine)
                                {
                                    drawList->AddLine(ImVec2(MyWorldToScreenVec2.X, MyWorldToScreenVec2.Y),ImVec2(worldToScreen.X, worldToScreen.Y + BossOffsetMonster),ImColor(ESPBoss));
                                }
                                if (EnableESPBox)
                                {
                                    drawList->AddRect(ImVec2(worldToScreen.X - BossOffsetMonster,worldToScreen.Y - (BossOffsetMonster * 2.5f)),ImVec2(worldToScreen.X + BossOffsetMonster,worldToScreen.Y + BossOffsetMonster),ImColor(ESPBoss), 0.1f, 15);
                                }
                            }
                            else if (!IsSpellOrBullet(AiEnemies))
                            {
                                if (EnableESPLine)
                                {
                                    drawList->AddLine(ImVec2(MyWorldToScreenVec2.X,MyWorldToScreenVec2.Y),ImVec2(worldToScreen.X, worldToScreen.Y +sizeOffsetMonster),ImColor(ESPMonster));
                                }
                                if (EnableESPBox)
                                {
                                    drawList->AddRect(ImVec2(worldToScreen.X - sizeOffsetMonster,worldToScreen.Y - sizeOffsetMonster),ImVec2(worldToScreen.X + sizeOffsetMonster,worldToScreen.Y + sizeOffsetMonster),ImColor(ESPMonster), 0.1f, 15);
                                }
                                if(EnableESPHealthBar)
                                {
                                    float healthBarY = worldToScreen.Y + sizeOffsetMonster;
                                    float healthBar = (healthBarY * (float)healthPercent) / 100.f;
                                    int healthBarDelta = healthBarY - healthBar;
                                    drawList->AddRectFilled(ImVec2(worldToScreen.X + sizeOffsetMonster + 2,worldToScreen.Y - sizeOffsetMonster),ImVec2(worldToScreen.X  + sizeOffsetMonster + 4, healthBar),ImColor(redHealth, greenHealth, 0), 0.1f, 15);
                                }
                            }
                        }
                    }
                }
            }
        }

        if(EnableESPCollectable && collectables != nullptr)
        {
            for (int i = 0; i < collectables->getSize(); ++i)
            {
                void *collectable = collectables->getItems()[i];
                if (collectable != nullptr)
                {
                    float sizeOffset = PixelPerfectCamera_cameraZoom * 9.0f;
                    int blockType = *(int *) ((uint64_t) collectable + PixelWorlds.CollectableData_blockType);
                    float PosX = *(float *) ((uint64_t) collectable + PixelWorlds.CollectableData_posX);
                    float PosY = *(float *) ((uint64_t) collectable + PixelWorlds.CollectableData_posY);
                    auto convertMapPointToWorldPoint = ConvertMapPointToWorldPoint(PosX, PosY);
                    auto worldToScreen = WorldToScreenVec2(convertMapPointToWorldPoint);
                    if (blockType != -1)
                    {
                        if(EnableESPLine)
                        {
                            drawList->AddLine(ImVec2(MyWorldToScreenVec2.X, MyWorldToScreenVec2.Y),ImVec2(worldToScreen.X, worldToScreen.Y + sizeOffset),ImColor(ESPCollectable));

                        }
                        if(EnableESPBox)
                        {
                            drawList->AddRect(ImVec2(worldToScreen.X - sizeOffset,worldToScreen.Y - sizeOffset),ImVec2(worldToScreen.X + sizeOffset,worldToScreen.Y + sizeOffset),ImColor(ESPCollectable), 0.1f, 15);
                        }
                    }
                }
            }
        }

        if(EnableESPButterfly)
        {
            if(WorldInstantiate != nullptr)
            {
                for (int x = 0; x < getCurrentWorldSize.x; ++x)
                {
                    for (int y = 0; y < getCurrentWorldSize.y; ++y)
                    {
                        float BlockSizeByZoom = PixelPerfectCamera_cameraZoom * 12.0f;
                        Vector2 BlockPosition = Vector2(x, y);
                        auto convertMapPointToWorldPoint = ConvertMapPointToWorldPoint(BlockPosition.X, BlockPosition.Y);
                        auto worldToScreen = WorldToScreenVec2(convertMapPointToWorldPoint);
                        int getBlockType = World_GetBlockType(WorldInstantiate, x, y);
                        if(ConfigData_IsBlockButterflyEventItem(getBlockType))
                        {
                            if(EnableESPLine)
                            {
                                drawList->AddLine(ImVec2(MyWorldToScreenVec2.X, MyWorldToScreenVec2.Y), ImVec2(worldToScreen.X,worldToScreen.Y + BlockSizeByZoom),ImColor(ESPButterFly));
                            }
                            if(EnableESPBox)
                            {
                                drawList->AddRect(ImVec2(worldToScreen.X - BlockSizeByZoom,worldToScreen.Y - BlockSizeByZoom),ImVec2(worldToScreen.X + BlockSizeByZoom,worldToScreen.Y + BlockSizeByZoom),ImColor(ESPButterFly), 0.1f, 15);
                            }
                        }
                    }
                }
            }
        }

        //Nether
        if(worldType == 5 || worldType == 9)
        {
            if(WorldInstantiate != nullptr) {
                for (int x = 0; x < getCurrentWorldSize.x; ++x)
                {
                    for (int y = 0; y < getCurrentWorldSize.y; ++y)
                    {
                        float BlockSizeByZoom = PixelPerfectCamera_cameraZoom * 16.0f;
                        Vector2 BlockPosition = Vector2(x, y);
                        auto convertMapPointToWorldPoint = ConvertMapPointToWorldPoint(BlockPosition.X, BlockPosition.Y);
                        auto worldToScreen = WorldToScreenVec2(convertMapPointToWorldPoint);
                        int getBlockType = World_GetBlockType(WorldInstantiate, x, y);
                        void *GetWorldItemData = World_GetWorldItemData(WorldInstantiate, x, y);
                        if((getBlockType == 1419 || getBlockType == 1502) && EnableESPNetherExit) //Exit
                        {
                            if(EnableESPLine)
                            {
                                drawList->AddLine(ImVec2(MyWorldToScreenVec2.X, MyWorldToScreenVec2.Y), ImVec2(worldToScreen.X,worldToScreen.Y + BlockSizeByZoom),ImColor(ESPNetherExit));
                            }
                            if(EnableESPBox)
                            {
                                drawList->AddRect(ImVec2(worldToScreen.X - BlockSizeByZoom,worldToScreen.Y - BlockSizeByZoom),ImVec2(worldToScreen.X + BlockSizeByZoom,worldToScreen.Y + BlockSizeByZoom),ImColor(ESPNetherExit), 0.1f, 15);
                            }
                        }
                        else if(getBlockType == 1392 && EnableESPNetherGiftBox) //Gift Box
                        {
                            if(GetWorldItemData != nullptr)
                            {
                                int blockType = *(int *)((uint64_t)GetWorldItemData + PixelWorlds.WorldItemBase_blockType);
                                if(blockType == 1392)
                                {
                                    bool isAnimationOn = *(bool *)((uint64_t)GetWorldItemData + PixelWorlds.WorldItemBase_isAnimationOn);
                                    if(isAnimationOn)
                                    {
                                        if(EnableESPLine)
                                        {
                                            drawList->AddLine(ImVec2(MyWorldToScreenVec2.X, MyWorldToScreenVec2.Y), ImVec2(worldToScreen.X, worldToScreen.Y + BlockSizeByZoom),ImColor(ESPNetherGiftBox));
                                        }
                                        if(EnableESPBox)
                                        {
                                            drawList->AddRect(ImVec2(worldToScreen.X - BlockSizeByZoom,worldToScreen.Y - BlockSizeByZoom),ImVec2(worldToScreen.X + BlockSizeByZoom,worldToScreen.Y + BlockSizeByZoom),ImColor(ESPNetherGiftBox), 0.1f, 15);
                                        }
                                    }
                                }
                            }
                        }
                        else if(getBlockType == 1400 && EnableESPNetherTreasureBox) //Treasure
                        {
                            if(EnableESPLine)
                            {
                                drawList->AddLine(ImVec2(MyWorldToScreenVec2.X, MyWorldToScreenVec2.Y), ImVec2(worldToScreen.X,worldToScreen.Y + BlockSizeByZoom),ImColor(ESPNetherTreasureBox));
                            }
                            if(EnableESPBox)
                            {
                                drawList->AddRect(ImVec2(worldToScreen.X - BlockSizeByZoom,worldToScreen.Y - BlockSizeByZoom),ImVec2(worldToScreen.X + BlockSizeByZoom,worldToScreen.Y + BlockSizeByZoom),ImColor(ESPNetherTreasureBox), 0.1f, 15);
                            }
                        }
                        else if(getBlockType == 2066 && EnableESPNetherSpecialItem) //Special
                        {
                            if(EnableESPLine)
                            {
                                drawList->AddLine(ImVec2(MyWorldToScreenVec2.X, MyWorldToScreenVec2.Y), ImVec2(worldToScreen.X,worldToScreen.Y + BlockSizeByZoom),ImColor(ESPNetherSpecialItem));
                            }
                            if(EnableESPBox)
                            {
                                drawList->AddRect(ImVec2(worldToScreen.X - BlockSizeByZoom,worldToScreen.Y - BlockSizeByZoom),ImVec2(worldToScreen.X + BlockSizeByZoom,worldToScreen.Y + BlockSizeByZoom),ImColor(ESPNetherSpecialItem), 0.1f, 15);
                            }
                        }
                    }
                }
            }
        }

        if(EnableESPSpirit && SpiritVec2i != Vector2i{})
        {
            float sizeOfSpirit = PixelPerfectCamera_cameraZoom * 5.0f;
            if (EnableESPLine)
            {
                drawList->AddLine(ImVec2(MyWorldToScreenVec2.X, MyWorldToScreenVec2.Y), ImVec2(SpiritVec2.X,SpiritVec2.Y + sizeOfSpirit),ImColor(ESPSpirit));
            }
            if (EnableESPBox)
            {
                drawList->AddRect(ImVec2(SpiritVec2.X - sizeOfSpirit, SpiritVec2.Y - sizeOfSpirit),ImVec2(SpiritVec2.X + sizeOfSpirit, SpiritVec2.Y + sizeOfSpirit),ImColor(ESPSpirit), 0.1f, 15);
            }
        }

        //Mine
        if(worldType == 18) {
            if (WorldInstantiate != nullptr) {
                for (int x = 0; x < getCurrentWorldSize.x; ++x)
                {
                    for (int y = 0; y < getCurrentWorldSize.y; ++y)
                    {
                        float BlockSizeByZoom = PixelPerfectCamera_cameraZoom * 16.0f;
                        Vector2 BlockPosition = Vector2(x, y);
                        auto convertMapPointToWorldPoint = ConvertMapPointToWorldPoint(BlockPosition.X, BlockPosition.Y);
                        auto worldToScreen = WorldToScreenVec2(convertMapPointToWorldPoint);
                        int getBlockType = World_GetBlockType(WorldInstantiate, x, y);
                        void *GetWorldItemData = World_GetWorldItemData(WorldInstantiate, x, y);
                        if (getBlockType == 4002 || getBlockType == 3996 || getBlockType == 3999 || getBlockType == 4000 || getBlockType == 3995)
                        {
                            if(EnableESPMineGemstone)
                            {
                                if (EnableESPLine)
                                {
                                    drawList->AddLine(ImVec2(MyWorldToScreenVec2.X, MyWorldToScreenVec2.Y),ImVec2(worldToScreen.X, worldToScreen.Y + BlockSizeByZoom),ImColor(ESPMineGemstone));
                                }
                                if (EnableESPBox)
                                {
                                    drawList->AddRect(ImVec2(worldToScreen.X - BlockSizeByZoom,worldToScreen.Y - BlockSizeByZoom),ImVec2(worldToScreen.X + BlockSizeByZoom,worldToScreen.Y + BlockSizeByZoom),ImColor(ESPMineGemstone), 0.1f, 15);
                                }
                            }
                        }
                        else if (getBlockType == 4130 || getBlockType == 4149 || getBlockType == 4150)
                        {
                            if(EnableESPMineCrate)
                            {
                                if (EnableESPLine)
                                {
                                    drawList->AddLine(ImVec2(MyWorldToScreenVec2.X, MyWorldToScreenVec2.Y),ImVec2(worldToScreen.X, worldToScreen.Y + BlockSizeByZoom),ImColor(ESPMineCrate));
                                }
                                if (EnableESPBox)
                                {
                                    drawList->AddRect(ImVec2(worldToScreen.X - BlockSizeByZoom,worldToScreen.Y - BlockSizeByZoom),ImVec2(worldToScreen.X + BlockSizeByZoom,worldToScreen.Y + BlockSizeByZoom),ImColor(ESPMineCrate), 0.1f, 15);
                                }
                            }
                        }
                        else if(getBlockType == 3966)
                        {
                            if(EnableESPMineExit)
                            {
                                if (EnableESPLine)
                                {
                                    drawList->AddLine(ImVec2(MyWorldToScreenVec2.X, MyWorldToScreenVec2.Y),ImVec2(worldToScreen.X, worldToScreen.Y + BlockSizeByZoom),ImColor(ESPMineExit));
                                }
                                if (EnableESPBox)
                                {
                                    drawList->AddRect(ImVec2(worldToScreen.X - BlockSizeByZoom,worldToScreen.Y - BlockSizeByZoom),ImVec2(worldToScreen.X + BlockSizeByZoom,worldToScreen.Y + BlockSizeByZoom),ImColor(ESPMineExit), 0.1f, 15);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    ImGui::End();
}
#endif
