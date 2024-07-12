#ifndef OFFSETS_H
#define OFFSETS_H

struct LonelySurvivor
{
    uintptr_t BattleManager_MainHero = 0x24;
    uintptr_t BattleManager_GoldCount = 0xA0;

    uintptr_t BattleControlHero_InstantKillTimes = 0xF4;

    uintptr_t BattleControlUnit_UnitData = 0x40;

    uintptr_t BattleUnitData_Atk = 0x20;
}LonelySurvivor;

#endif
