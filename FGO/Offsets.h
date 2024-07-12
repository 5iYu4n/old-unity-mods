#ifndef OFFSETS_H
#define OFFSETS_H

struct fgo
{
    uintptr_t BattleActorControl_isEnemy = 0xF4;
    uintptr_t BattleActorControl_battleSvtData = 0xE8;

    uintptr_t BattleServantData_hp = 0x108; //<hp>k__BackingField
    uintptr_t BattleServantData_atk = 0xFC;
    uintptr_t BattleServantData_maxhp = 0x10C;
}fgo;

#endif
