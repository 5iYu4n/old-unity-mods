#ifndef HOOKS_H
#define HOOKS_H

int LegitBot()
{
    if(EnableLegitAutoPlay)
    {
        totalNote = PerfectNote + GreatNote + GoodNote + BadNote + MissNote;
        int curChance = rand() % totalNote + 1;
        if(PerfectNote > 0 && curChance <= PerfectNote)
        {
            return 7;
        }
        else if(GreatNote > 0 && curChance <= (PerfectNote + GreatNote))
        {
            return 6;
        }
        else if(GoodNote > 0 && curChance <= (PerfectNote + GreatNote + GoodNote))
        {
            return 5;
        }
        else if(BadNote > 0 && curChance <= (PerfectNote + GreatNote + GoodNote + BadNote))
        {
            return 3;
        }
        else if(MissNote > 0 && curChance <= (PerfectNote + GreatNote + GoodNote + BadNote + MissNote))
        {
            return 1;
        }
    }
}

void (*old_LiveLogic_OnDamage)(void *instance, void *NoteBase);
void LiveLogic_OnDamage(void *instance, void *NoteBase)
{
    if(instance != nullptr)
    {
        if(NoteBase != nullptr)
        {
            if(SetNoteResult != 0 && !EnableLegitAutoPlay)
                *(int *)((uint64_t)NoteBase + hmcs.NoteBase_Result) = CurNotResult;
            else if(EnableLegitAutoPlay)
                *(int *)((uint64_t)NoteBase + hmcs.NoteBase_Result) = NoteType;
        }
    }
    old_LiveLogic_OnDamage(instance, NoteBase);
}

void (*old_LiveLogic_OnJudgmentNote)(void *instance ,void *NoteBase);
void LiveLogic_OnJudgmentNote(void *instance ,void *NoteBase)
{
    if(instance != nullptr)
    {
        if(NoteBase != nullptr)
        {
            NoteType = LegitBot();

            if(SetNoteResult != 0 && !EnableLegitAutoPlay)
                *(int *)((uint64_t)NoteBase + hmcs.NoteBase_Result) = CurNotResult;
            else if(EnableLegitAutoPlay)
                *(int *)((uint64_t)NoteBase + hmcs.NoteBase_Result) = NoteType;
        }
    }
    old_LiveLogic_OnJudgmentNote(instance, NoteBase);
}

void (*old_LiveLogic_OnUpdateCombo)(void *instance ,void *NoteBase);
void LiveLogic_OnUpdateCombo(void *instance ,void *NoteBase)
{
    if(instance != nullptr)
    {
        if(NoteBase != nullptr)
        {
            if(SetNoteResult != 0 && !EnableLegitAutoPlay)
                *(int *)((uint64_t)NoteBase + hmcs.NoteBase_Result) = CurNotResult;
            else if(EnableLegitAutoPlay)
                *(int *)((uint64_t)NoteBase + hmcs.NoteBase_Result) = NoteType;
        }

    }
    old_LiveLogic_OnUpdateCombo(instance, NoteBase);
}

namespace HMCS
{
    void LOAD_HOOKS()
    {
        A64HookFunction((void *)
        getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x2C6C504"))), (void *)LiveLogic_OnDamage, (void **)&old_LiveLogic_OnDamage);
        A64HookFunction((void *)
        getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x2C6C5CC"))), (void *)LiveLogic_OnJudgmentNote, (void **)&old_LiveLogic_OnJudgmentNote);
        A64HookFunction((void *)
        getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x2C6D448"))), (void *)LiveLogic_OnUpdateCombo, (void **)&old_LiveLogic_OnUpdateCombo);
    }
}

#endif
