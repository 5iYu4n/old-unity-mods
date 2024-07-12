#ifndef HOOKS_H
#define HOOKS_H

int (*Application_get_targetFrameRate)();
void (*Application_set_targetFrameRate)(int value);

float (*Time_get_timeScale)();
void (*Time_set_timeScale)(float value);

bool (*BattleServantData_IsNpMax)(void *instance);
void (*BattleServantData_addNpPer)(void *instance, float value);

void (*old_BattleActorControl_Update)(void *instance);
void BattleActorControl_Update(void *instance)
{
    if(instance != nullptr)
    {
        if(setFrameLvl != 0 && Application_get_targetFrameRate() != setFrameValue && Application_get_targetFrameRate() != 0)
            Application_set_targetFrameRate(setFrameValue);

        if(setTimeScaleLvl != 0 && Time_get_timeScale() != setTimeScaleValue && Time_get_timeScale() != 0)
            Time_set_timeScale(setTimeScaleValue);

        bool isEnemy = *(bool *)((uint64_t)instance + fgo.BattleActorControl_isEnemy);
        if(isEnemy)
        {
            void *battleSvtData = *(void **)((uint64_t)instance + fgo.BattleActorControl_battleSvtData);
            if(battleSvtData != nullptr)
            {
                if(IsEnemyNoob)
                    *(int *)((uint64_t)battleSvtData + fgo.BattleServantData_atk) = 0;

                if(IsWeakEnemy)
                {
                    int currentHP = *(int *)((uint64_t)battleSvtData + fgo.BattleServantData_hp);
                    if(currentHP > 1)
                    {
                        *(int *)((uint64_t)battleSvtData + fgo.BattleServantData_hp) = 1;
                    }
                }
            }
        }
        else
        {
            void *battleSvtData = *(void **)((uint64_t)instance + fgo.BattleActorControl_battleSvtData);
            if(battleSvtData != nullptr)
            {
                if(IsMassiveDamage)
                    *(int *)((uint64_t)battleSvtData + fgo.BattleServantData_atk) = 9999999;

                if(IsGodMod)
                {
                    int maxHP = *(int *)((uint64_t)battleSvtData + fgo.BattleServantData_maxhp);
                    int currentHP = *(int *)((uint64_t)battleSvtData + fgo.BattleServantData_hp);
                    if(currentHP != maxHP)
                    {
                        *(int *)((uint64_t)battleSvtData + fgo.BattleServantData_hp) = *(int *)((uint64_t)battleSvtData + fgo.BattleServantData_maxhp);
                    }
                }

                if(IsNPMax && !BattleServantData_IsNpMax(battleSvtData))
                {
                    BattleServantData_addNpPer(battleSvtData, 100);
                }
            }
        }
    }
    old_BattleActorControl_Update(instance);
}

namespace FGO
{
    void LOAD_HOOKS()
    {
        Application_get_targetFrameRate = (int (*)())
                getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x2DC1AF4")));
        Application_set_targetFrameRate = (void (*)(int))
                getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x2DC1B3C")));

        Time_get_timeScale = (float (*)())
                getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x2AEF528")));
        Time_set_timeScale = (void (*)(float))
                getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x2AEF570")));

        BattleServantData_IsNpMax = (bool (*)(void *))
                getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x1AC6FB8")));
        BattleServantData_addNpPer = (void (*)(void *, float))
                getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x1AC71E4")));

        MSHookFunction((void *)
        getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x23F590C"))), (void *)BattleActorControl_Update, (void **)&old_BattleActorControl_Update);
    }
}

#endif
