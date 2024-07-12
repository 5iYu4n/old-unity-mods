#ifndef CSY_MAINMENULOGIC_H
#define CSY_MAINMENULOGIC_H

void (*old_MainMenuLogic_Update)(void *instance);
void MainMenuLogic_Update(void *instance)
{
    if(instance != nullptr)
    {
        if(DoLogOutOnce)
        {
            DoLogOutOnce = false;
            MainMenuLogic_LogOut(instance);
        }

        void *mainMenuShopLogic = *(void **)((uint64_t)instance + PixelWorlds.MainMenuLogic_mainMenuShopLogic);
        if(mainMenuShopLogic != nullptr)
        {
            checkIsPlayerInMenu = MainMenuShopLogic_IsInMainMenu(mainMenuShopLogic);
        }
    }
    old_MainMenuLogic_Update(instance);
}

#endif
