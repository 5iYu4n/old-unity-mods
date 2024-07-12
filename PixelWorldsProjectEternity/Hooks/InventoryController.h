#ifndef CSY_INVENTORYCONTROLLER_H
#define CSY_INVENTORYCONTROLLER_H

static bool EnableDrawInventoryController = false;

static bool ApplyAddItem = false;
int InventorySize = 0;
int AddItemRange = 1;
static int currentAddItemRange = 1;
static int leakItem = 4893;

void add_item(void *myPlayerData)
{
    if(myPlayerData != nullptr)
    {
        InventorySize = PlayerData_GetInventorySize(myPlayerData);
        AddItemRange = ceil(4908.f / (float)InventorySize);
        if(ApplyAddItem)
        {
            ApplyAddItem = false;
            int firstItem = (((currentAddItemRange - 1) * InventorySize) + 1);
            int lastItem = currentAddItemRange * InventorySize;

            monoArray<InventoryKey *> *GetInventoryAsOrderedByInventoryItemType = PlayerData_GetInventoryAsOrderedByInventoryItemType(myPlayerData);
            for (int i = 0; i < GetInventoryAsOrderedByInventoryItemType->getLength(); ++i)
            {
                InventoryKey GetInventoryAsOrderedByInventoryItem = GetInventoryAsOrderedByInventoryItemType->getPointer()[i];
                PlayerData_RemoveItemsFromInventory(myPlayerData, GetInventoryAsOrderedByInventoryItem, 999);
            }

            /* Leak
            for (int i = leakItem; i <= 4908; ++i) {
                if(i <= 4908)
                {
                    PlayerData_AddItemToInventory(myPlayerData, i, ConfigData_GetBlockTypeInventoryItemType(i), 1);
                }
            }*/
            for (int i = firstItem; i <= lastItem; ++i) {
                if(i <= 4908)
                {
                    PlayerData_AddItemToInventory(myPlayerData, i, ConfigData_GetBlockTypeInventoryItemType(i), 1);
                }
            }
        }
    }
}

void DrawInventoryControllerMenu()
{
    if (EnableDrawInventoryController)
    {
        ImGui::Begin(OBFUSCATE("Inventory Controller"), &EnableDrawInventoryController,ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
        if(ImGui::Button(OBFUSCATE("-1")))
        {
            if(currentAddItemRange > 1)
            {
                currentAddItemRange --;
            }
        }
        ImGui::SameLine();
        ImGui::Text(OBFUSCATE("Add To Inventory Item Range: %d"), currentAddItemRange);
        ImGui::SameLine();
        if(ImGui::Button(OBFUSCATE("+1")))
        {
            if(currentAddItemRange < AddItemRange)
            {
                currentAddItemRange ++;
            }
        }
        ImGui::SameLine();
        if(ImGui::Button(OBFUSCATE("Apply")))
        {
            ApplyAddItem = true;
        }
        ImGui::End();
    }
}

#endif
