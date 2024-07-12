#ifndef HOOKS_H
#define HOOKS_H

void (*old_AdsManagerADMob_Update)(void *instance);
void AdsManagerADMob_Update(void *instance)
{
    if(instance != nullptr)
    {
        if(EnableRemoveAds)
        {
            *(bool *)((uint64_t)instance + Guidus.AdsManagerADMob_removeADs) = true;
        }
    }
    old_AdsManagerADMob_Update(instance);
}

void (*Character_set_IsImmotal)(void *instance, bool value);

void (*Enemy_ItemDrop)(void *instance, int item, int mini, int max);

Vector3 (*Transform_get_position)(void *instance);
void (*Transform_set_position)(void *instance, Vector3 position);

void (*old_Character_Update)(void *instance);
void Character_Update(void *instance)
{
    if(instance != nullptr)
    {
        void *thisPlayer = *(void **)((uint64_t)instance + Guidus.Character_thisPlayer);
        if(thisPlayer != nullptr)
        {
            if(EnableGodMod)
            {
                Character_set_IsImmotal(instance, true);
            }
            else if(!EnableGodMod)
            {
                Character_set_IsImmotal(instance, false);
            }

            void *transform = *(void **)((uint64_t)instance + Guidus.Character_transform);
            if(transform != nullptr)
            {
                PlayerDropPos = Transform_get_position(transform);
            }
        }

        void *thisEnemy = *(void **)((uint64_t)instance + Guidus.Character_thisEnemy);
        if(thisEnemy != nullptr)
        {
            if(SetEnemyDrop != 0)
                Enemy_ItemDrop(thisEnemy, SetEnemyDrop - 1, 999, 999);
        }
    }
    old_Character_Update(instance);
}

void (*old_Item_Update)(void *instance);
void Item_Update(void *instance)
{
    if(instance != nullptr)
    {
        if(SetEnemyDrop != 0)
        {
            void *transform = *(void **)((uint64_t)instance + Guidus.Item_transform);
            if(transform != nullptr)
            {
                Transform_set_position(transform, PlayerDropPos);
            }
        }
    }
    old_Item_Update(instance);
}

namespace GUIDUS
{
    void LOAD_HOOKS()
    {
        Transform_get_position = (Vector3 (*)(void *)) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x81EEF4")));
        Transform_set_position = (void (*)(void *, Vector3)) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x81EFCC")));

        Character_set_IsImmotal = (void (*)(void *, bool)) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x175CA60")));

        Enemy_ItemDrop = (void (*)(void *, int, int , int)) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x17E7024")));

        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x182649C"))), (void *)AdsManagerADMob_Update, (void **)&old_AdsManagerADMob_Update);
        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x175D738"))), (void *)Character_Update, (void **)&old_Character_Update);
        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x1641538"))), (void *)Item_Update, (void **)&old_Item_Update);
    }
}

#endif
