#ifndef CSY_FISHINGGAUGEMINIGAMEUI_H
#define CSY_FISHINGGAUGEMINIGAMEUI_H

void (*old_FishingGaugeMinigameUI_Update)(void *instance);
void FishingGaugeMinigameUI_Update(void *instance)
{
    if(instance != nullptr)
    {
        FishingGaugeMinigameUIInstantiate = instance;
        fishingProgress = *(float *)((uint64_t)instance + PixelWorlds.FishingGaugeMinigameUI_progress);
        fishPosition = *(float *)((uint64_t)instance + PixelWorlds.FishingGaugeMinigameUI_fishPosition);
        targetAreaPosition = *(float *)((uint64_t)instance + PixelWorlds.FishingGaugeMinigameUI_targetAreaPosition);
        currentFishSetting = *(FishSizeSetting *)((uint64_t)instance + PixelWorlds.FishingGaugeMinigameUI_currentFishSetting);
    }
    old_FishingGaugeMinigameUI_Update(instance);
}

#endif
