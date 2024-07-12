#ifndef CSY_PLAYERDATA_H
#define CSY_PLAYERDATA_H

bool (*old_PlayerData_HasUnlockedRecipe)(void *instance, int blocktype);
bool PlayerData_HasUnlockedRecipe(void *instance, int blocktype)
{
    if(instance != nullptr)
    {
        if(EnableUnlockAllRecipes)
        {
            return true;
        }
    }
    return old_PlayerData_HasUnlockedRecipe(instance, blocktype);
}

#endif
