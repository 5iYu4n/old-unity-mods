#ifndef CSY_CHATUI_H
#define CSY_CHATUI_H

const char *SetWarpName = OBFUSCATE("");
static bool DoClickWarpWorld = false;

void (*old_ChatUI_Update)(void *instance);
void ChatUI_Update(void *instance)
{
    if(instance != nullptr)
    {
        if(DoClickWarpWorld)
        {
            DoClickWarpWorld = false;
            ChatUI_WarpToWorld(instance, CreateIl2cppString(SetWarpName), 1);
        }
    }
    old_ChatUI_Update(instance);
}

#endif //CSY_CHATUI_H
