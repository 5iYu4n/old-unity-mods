#ifndef HOOKS_H
#define HOOKS_H

void (*Time_set_timeScale)(float value);

void (*BattleManager_AddGold)(void *instance, int value);
void (*BattleManager_AddHeroCultivateItem)(void *instance);


void (*BattleControlHero_SetInvincibleTime)(void *instance, float value);
void (*BattleControlHero_AddInstantKill)(void *instance, int value);

void *(*BattleControlHero_GetRealUnit)(void *instance);

void (*BattleControlMonster_OnDead)(void *instance, bool notDropExp);

void (*old_BattleManager_Update)(void *instance);
void BattleManager_Update(void *instance)
{
    if(instance != nullptr)
    {
        if(SetGameSpeed != 1.f)
        {
            Time_set_timeScale(SetGameSpeed);
        }
        else
        {
            Time_set_timeScale(1.0f);
        }

        if(EnableMassiveHeroXP)
        {
            BattleManager_AddHeroCultivateItem(instance);
        }

        long goldCount = *(long *)((uint64_t)instance + LonelySurvivor.BattleManager_GoldCount);
        if(EnableAlwaysMaxGoldReward && goldCount < 7400)
        {
            BattleManager_AddGold(instance, 1000000);
        }

        void *HeroMain = *(void **)((uint64_t)instance + LonelySurvivor.BattleManager_MainHero);
        if(HeroMain != nullptr)
        {
            if(EnableGodMod)
            {
                BattleControlHero_SetInvincibleTime(HeroMain, 999.f);
            }
            else
            {
                BattleControlHero_SetInvincibleTime(HeroMain, 0.f);
            }

            int instantKillTime = *(int *)((uint64_t)HeroMain + LonelySurvivor.BattleControlHero_InstantKillTimes);
            if(EnableInstantKill && instantKillTime < 2)
            {
                BattleControlHero_AddInstantKill(HeroMain, 2);
            }
            else if(!EnableInstantKill)
            {
                BattleControlHero_AddInstantKill(HeroMain, -1);
            }

            void *GetRealUnit = BattleControlHero_GetRealUnit(HeroMain);
            if(GetRealUnit != nullptr)
            {
                void *UnitData = *(void **)((uint64_t)GetRealUnit + LonelySurvivor.BattleControlUnit_UnitData);
                if(UnitData != nullptr)
                {
                    if(SaveOnceDamage)
                        SaveOnceDamage = *(int *)((uint64_t)UnitData + LonelySurvivor.BattleUnitData_Atk);

                    if(EnableInstantKill)
                        *(int *)((uint64_t)UnitData + LonelySurvivor.BattleUnitData_Atk) = 999999999;
                    else
                        *(int *)((uint64_t)UnitData + LonelySurvivor.BattleUnitData_Atk) = SaveOnceDamage;
                }
            }
        }
    }
    old_BattleManager_Update(instance);
}

bool (*BattleControlMonster_GetIsNormalMonster)(void *instance);

void (*old_BattleControlMonster_Update)(void *instance);
void BattleControlMonster_Update(void *instance)
{
    if(instance != nullptr)
    {
        bool IsMonster = BattleControlMonster_GetIsNormalMonster(instance);

        if(EnableMassiveKill && IsMonster)
        {
            BattleControlMonster_OnDead(instance, false);
        }
    }
    old_BattleControlMonster_Update(instance);
}

bool (*BattleControlItem_GetIsExpItem)(void *instance);
void (*BattleControlItem_Recycle)(void *instance);

void (*BattleControlItem_InitItem)(void *instance, Vector3 pos, int ItemIndex, int ItemValue);

void (*old_BattleControlItem_Update)(void *instance);
void BattleControlItem_Update(void *instance)
{
    if(instance != nullptr)
    {
        bool IsExpItem = BattleControlItem_GetIsExpItem(instance);

        if(EnableClearXpItem && IsExpItem)
        {
            BattleControlItem_Recycle(instance);
        }

        if(EnableMassivePetFood)
        {
            BattleControlItem_InitItem(instance, ItemStaticPos, 13, 30);
        }

        if(DoGenerateItem)
        {
            DoGenerateItem = false;
            BattleControlItem_InitItem(instance, ItemStaticPos, SetItemIndex, SetItemValue);
        }
    }
    old_BattleControlItem_Update(instance);
}

namespace LONELYSURVIVOR
{
    void LOAD_HOOKS()
    {
        Time_set_timeScale = (void (*)(float)) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x1CC04A0")));

        /* BF.BattleManager */
        BattleManager_AddGold = (void (*)(void *, int)) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x11E73B4")));
        BattleManager_AddHeroCultivateItem = (void (*)(void *)) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x11E7484")));

        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x11E2900"))), (void *)BattleManager_Update, (void **)&old_BattleManager_Update);

        /* BattleControlHero */
        BattleControlHero_SetInvincibleTime = (void (*)(void *, float))  getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x2D92D28")));
        BattleControlHero_AddInstantKill = (void (*)(void *, int))  getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x2D92CDC")));
        BattleControlHero_GetRealUnit = (void *(*)(void *)) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x2D92B44")));

        /* BattleControlMonster */
        BattleControlMonster_GetIsNormalMonster = (bool (*)(void *)) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x2D9ED2C")));
        BattleControlMonster_OnDead = (void (*)(void *, bool)) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x2D9D450")));

        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x2D9FE40"))), (void *)BattleControlMonster_Update, (void **)&old_BattleControlMonster_Update);

        /* BattleControlItem */
        BattleControlItem_GetIsExpItem = (bool (*)(void *)) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x2D96DD8")));
        BattleControlItem_Recycle = (void (*)(void *)) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x2D98130")));
        BattleControlItem_InitItem = (void (*)(void *, Vector3, int, int)) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x2D968D8")));

        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x2D98320"))), (void *)BattleControlItem_Update, (void **)&old_BattleControlItem_Update);
    }
}

#endif
