#ifndef CSY_SPEECHBUBBLE_H
#define CSY_SPEECHBUBBLE_H

void (*old_SpeechBubble_Update)(void *instance);
void SpeechBubble_Update(void *instance)
{
    if(instance != nullptr)
    {
        LOGI("PW -> Speech OK");
        void *player = *(void **)((uint64_t)instance + PixelWorlds.SpeechBubble_player);
        if(player != nullptr)
        {
            LOGI("PW -> Player Non Null");
            bool isLocal = *(bool *)((uint64_t)player + PixelWorlds.Player_isLocalPlayer);
            if(isLocal)
            {
                *(int *)((uint64_t)instance + PixelWorlds.SpeechBubble_currentSpeechBubbleVisualLookType) = 8;
            }
        }
    }
    old_SpeechBubble_Update(instance);
}

#endif //CSY_SPEECHBUBBLE_H
