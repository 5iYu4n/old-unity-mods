#ifndef CSY_MINEWORLDNOTIFICATIONUI_H
#define CSY_MINEWORLDNOTIFICATIONUI_H

void (*old_MineWorldNotificationUI_Update)(void *instance);
void MineWorldNotificationUI_Update(void *instance)
{
    if(instance != nullptr)
    {
        MineBeforeStart = *(float *)((uint64_t)instance + PixelWorlds.MineWorldNotificationUI_timeLeftInSeconds);
    }
    old_MineWorldNotificationUI_Update(instance);
}

#endif
