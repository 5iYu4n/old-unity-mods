#ifndef CSY_INVENTORYCONTROL_H
#define CSY_INVENTORYCONTROL_H

void (*old_InventoryControl_Update)(void *instance);
void InventoryControl_Update(void *instance)
{
    if(instance != nullptr)
    {
        if(MyPlayerData != nullptr)
        {
            if(EnableToSelectDrop)
            {
                DropTimer += deltaTime;
                if(WorldControllerInstantiate != nullptr)
                {
                    if(InventoryControl_GetCurrentSelection(instance).blockType != 0 && PlayerData_GetCount(MyPlayerData, InventoryControl_GetCurrentSelection(instance)) != 0)
                    {
                        if(DropTimer >= DropDelay)
                        {
                            WorldController_DropStuffFromInventory(WorldControllerInstantiate, Vector2i{MyMapPoint.x + 1, MyMapPoint.y}, InventoryControl_GetCurrentSelection(instance), PlayerData_GetCount(MyPlayerData, InventoryControl_GetCurrentSelection(instance)), PlayerData_GetInventoryData(MyPlayerData, InventoryControl_GetCurrentSelection(instance)));
                            DropTimer = 0.000f;
                        }
                    }
                }
            }
        }
    }
    old_InventoryControl_Update(instance);
}

#endif
