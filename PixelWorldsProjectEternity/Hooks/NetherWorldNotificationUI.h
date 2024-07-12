#ifndef CSY_NETHERWORLDNOTIFICATIONUI_H
#define CSY_NETHERWORLDNOTIFICATIONUI_H

void (*old_NetherWorldNotificationUI_Update)(void *instance);
void NetherWorldNotificationUI_Update(void *instance)
{
    if(instance != nullptr)
    {
        NetherBeforeStart = *(float *)((uint64_t)instance + PixelWorlds.NetherWorldNotificationUI_timeLeftInSeconds);
    }
    old_NetherWorldNotificationUI_Update(instance);
}

#endif //CSY_NETHERWORLDNOTIFICATIONUI_H
