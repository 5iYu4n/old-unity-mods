#ifndef GEMSCOUNTER_H
#define GEMSCOUNTER_H

static bool EnableGemsCounter = false;

void DrawGemCounter()
{
    if(EnableGemsCounter && !checkIsPlayerInMenu)
    {
        ImGui::Begin(OBFUSCATE("Gems Counter"), &EnableGemsCounter,ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
        if(collectables != nullptr)
        {
            int fishGemsCount = 0;
            int mineGemsCount = 0;
            int pouchGemsCount = 0;
            for (int i = 0; i < collectables->getSize(); ++i) {
                void *collectable = collectables->getItems()[i];
                if(collectable != nullptr)
                {
                    int blockType = *(int *)((uint64_t)collectable + PixelWorlds.CollectableData_blockType);
                    short amount = *(short *)((uint64_t)collectable + PixelWorlds.CollectableData_amount);
                    if(ConfigData_IsFish(blockType))
                    {
                        fishGemsCount += ConfigData_GetFishRecycleValueForFishRecycler(blockType) * amount;
                    }
                    else if(ConfigData_IsBlockMiningGemstone(blockType))
                    {
                        mineGemsCount += ConfigData_GetGemstoneRecycleValueForMiningGemstoneRecycler(blockType) * amount;
                    }
                    else if(ConfigData_IsConsumableTreasurePouch(blockType))
                    {
                        pouchGemsCount += ConfigData_GetTreasurePouchRewardAmount(blockType) * amount;
                    }
                }
            }
            ImGui::Text("Total Gems In World: %d", (fishGemsCount + mineGemsCount + pouchGemsCount));
            if(ImGui::TreeNode(OBFUSCATE("Gem(s) Pouch")))
            {
                ImGui::Text("Total Pouch Gems: %d", pouchGemsCount);
                for (int i = 0; i < collectables->getSize(); ++i) {
                    void *collectable = collectables->getItems()[i];
                    if (collectable != nullptr)
                    {
                        int blockType = *(int *) ((uint64_t) collectable + PixelWorlds.CollectableData_blockType);
                        short amount = *(short *) ((uint64_t) collectable + PixelWorlds.CollectableData_amount);
                        if(ConfigData_IsConsumableTreasurePouch(blockType))
                        {
                            ImGui::Text("[x%d] %s: %d Gem(s)", amount, blockTypeToString[blockType], (ConfigData_GetTreasurePouchRewardAmount(blockType) * amount));
                        }
                    }
                }
                ImGui::TreePop();
                ImGui::Separator();
            }
            if(ImGui::TreeNode(OBFUSCATE("Fish(s) Gem")))
            {
                ImGui::Text("Total Fish Gems: %d", fishGemsCount);
                for (int i = 0; i < collectables->getSize(); ++i) {
                    void *collectable = collectables->getItems()[i];
                    if (collectable != nullptr)
                    {
                        int blockType = *(int *) ((uint64_t) collectable + PixelWorlds.CollectableData_blockType);
                        short amount = *(short *) ((uint64_t) collectable + PixelWorlds.CollectableData_amount);
                        if(ConfigData_IsFish(blockType))
                        {
                            ImGui::Text("[x%d] %s: %d Gem(s)", amount, blockTypeToString[blockType], (ConfigData_GetFishRecycleValueForFishRecycler(blockType) * amount));
                        }
                    }
                }
                ImGui::TreePop();
                ImGui::Separator();
            }
            if(ImGui::TreeNode(OBFUSCATE("Gemstone(s) Gem")))
            {
                ImGui::Text("Total Mine Gems: %d", mineGemsCount);
                for (int i = 0; i < collectables->getSize(); ++i) {
                    void *collectable = collectables->getItems()[i];
                    if (collectable != nullptr)
                    {
                        int blockType = *(int *) ((uint64_t) collectable + PixelWorlds.CollectableData_blockType);
                        short amount = *(short *) ((uint64_t) collectable + PixelWorlds.CollectableData_amount);
                        if(ConfigData_IsBlockMiningGemstone(blockType))
                        {
                            ImGui::Text("[x%d] %s: %d Gem(s)", amount, blockTypeToString[blockType], (ConfigData_GetGemstoneRecycleValueForMiningGemstoneRecycler(blockType) * amount));
                        }
                    }
                }
                ImGui::TreePop();
                ImGui::Separator();
            }
        }
        ImGui::End();
    }
}


#endif

