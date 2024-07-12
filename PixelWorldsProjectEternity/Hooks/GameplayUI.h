#ifndef CSY_GAMEPLAYUI_H
#define CSY_GAMEPLAYUI_H

void (*old_GameplayUI_Update)(void *instance);
void GameplayUI_Update(void *instance)
{
    if(instance != nullptr)
    {
        GameplayUIInstantiate = instance;

        if(((ReloadWorldNetherBoss && !isReloadOptionsMenuOpen) || EnableManuallyReloadNetherWorld))
        {
            EnableManuallyReloadNetherWorld = false;
            ReloadWorldNetherBoss = false;
            GameplayUI_SettingsButtonClicked(instance);
            isReloadOptionsMenuOpen = true;
        }

        void *zoomSlider = *(void **)((uint64_t)instance + PixelWorlds.GameplayUI_zoomSlider);
        if(zoomSlider != nullptr)
        {
            ZoomSlider = zoomSlider;
        }
    }
    old_GameplayUI_Update(instance);
}

#endif
