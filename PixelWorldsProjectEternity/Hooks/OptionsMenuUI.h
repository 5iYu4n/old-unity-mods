#ifndef CSY_OPTIONSMENUUI_H
#define CSY_OPTIONSMENUUI_H

void (*OptionsMenuUI_ExitWorld)(void *instance, monoString* world);

void (*old_OptionsMenuUI_Update)(void *instance);
void OptionsMenuUI_Update(void *instance)
{
    if(instance != nullptr)
    {
        if(isReloadOptionsMenuOpen)
        {
            isReloadOptionsMenuOpen = false;
            OptionsMenuUI_ExitWorld(instance, CreateIl2cppString(OBFUSCATE("NETHERWORLD")));
        }
    }
    old_OptionsMenuUI_Update(instance);
}


#endif
