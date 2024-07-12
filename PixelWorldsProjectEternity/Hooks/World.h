#ifndef CSY_WORLD_H
#define CSY_WORLD_H

bool (*old_World_DoesPlayerHaveRightToModifyItemData)(void *instance);
bool World_DoesPlayerHaveRightToModifyItemData(void *instance)
{
    if(instance != nullptr)
    {
        if(EnableVisualRight)
        {
            return true;
        }
    }
    return old_World_DoesPlayerHaveRightToModifyItemData(instance);
}

#endif //CSY_WORLD_H
