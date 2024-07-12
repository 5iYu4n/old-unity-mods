#ifndef CSY_BASEMENUUI_H
#define CSY_BASEMENUUI_H

void (*old_BaseMenuUI_Update)(void *instance);
void BaseMenuUI_Update(void *instance)
{
    if(instance != nullptr)
    {
        if(CanSkipFishResult)
        {
            CanSkipFishResult = false;
            FishingResultsPopupUI_HardwareBackButtonPressed(instance);
        }
    }
    old_BaseMenuUI_Update(instance);
}

#endif //CSY_BASEMENUUI_H
