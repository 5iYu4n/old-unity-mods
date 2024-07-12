#ifndef CSY_WORLDNAMECHECKER_H
#define CSY_WORLDNAMECHECKER_H

static bool EnableAlwaysValidateWorldName = false;

int (*old_WorldNameChecker_Validate)(void *instance, monoString *worldName);
int WorldNameChecker_Validate(void *instance, monoString *worldName)
{
    if(instance != nullptr)
    {
        if(EnableAlwaysValidateWorldName)
        {
            return 0;
        }
    }

    return old_WorldNameChecker_Validate(instance, worldName);
}

#endif //CSY_WORLDNAMECHECKER_H
