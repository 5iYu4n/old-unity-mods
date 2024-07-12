#ifndef CSY_CONFIGDATA_H
#define CSY_CONFIGDATA_H

float (*old_ConfigData_GetBlockRunSpeed)(void *instance, int blockType);
float ConfigData_GetBlockRunSpeed(void *instance, int blockType)
{
    if(instance != nullptr)
    {
        if(worldType == 20) //JetRace
        {
            return old_ConfigData_GetBlockRunSpeed(instance, blockType);
        }
        else if (setRunSpeed >= 1.0f && setRunSpeed <= 3.0f)
        {
            return setRunSpeed;
        }
        else
        {
            return old_ConfigData_GetBlockRunSpeed(instance, blockType);
        }
    }
    return old_ConfigData_GetBlockRunSpeed(instance, blockType);
}

bool (*old_ConfigData_IsBlockHot)(void *instance, int blockType);
bool ConfigData_IsBlockHot(void *instance, int blockType)
{
    if(instance != nullptr)
    {
        if(EnableAutoMine && worldType == 18)
        {
            return false;
        }
        else if(EnableAntiLavaBounce)
        {
            return false;
        }
    }
    return old_ConfigData_IsBlockHot(instance, blockType);
}

bool (*old_ConfigData_IsBlockSpring)(void *instance, int blockType);
bool ConfigData_IsBlockSpring(void *instance, int blockType)
{
    if(instance != nullptr)
    {

        if(EnableAntiBounce)
        {
            return false;
        }
    }
    return old_ConfigData_IsBlockSpring(instance, blockType);
}

bool (*old_ConfigData_IsBlockElastic)(void *instance, int blockType);
bool ConfigData_IsBlockElastic(void *instance, int blockType)
{
    if(instance != nullptr)
    {

        if(EnableAntiElastic)
        {
            return false;
        }
    }
    return ConfigData_IsBlockElastic(instance, blockType);
}

bool (*old_ConfigData_IsBlockPinball)(void *instance, int blockType);
bool ConfigData_IsBlockPinball(void *instance, int blockType)
{
    if(instance != nullptr)
    {
        if(EnableAntiPinball)
        {
            return false;
        }
    }
    return old_ConfigData_IsBlockPinball(instance, blockType);
}

bool (*old_ConfigData_IsBlockTrampolin)(void *instance, int blockType);
bool ConfigData_IsBlockTrampolin(void *instance, int blockType)
{
    if(instance != nullptr)
    {
        if(EnableAntiTrampolin)
        {
            return false;
        }
    }
    return old_ConfigData_IsBlockTrampolin(instance, blockType);
}

bool (*old_ConfigData_IsBlockWind)(void *instance, int blockType);
bool ConfigData_IsBlockWind(void *instance, int blockType)
{
    if(instance != nullptr)
    {
        if(EnableAntiWind)
        {
            return false;
        }
    }
    return old_ConfigData_IsBlockWind(instance, blockType);
}

bool (*old_ConfigData_IsBlockDeflector)(void *instance, int blockType);
bool ConfigData_IsBlockDeflector(void *instance, int blockType)
{
    if(instance != nullptr)
    {
        if(EnableAntiDeflector)
        {
            return false;
        }
    }
    return old_ConfigData_IsBlockDeflector(instance, blockType);
}

float (*old_ConfigData_GetDeflectorRange)(void *instance, int blockType, int fpsSetting);
float ConfigData_GetDeflectorRange(void *instance, int blockType, int fpsSettings)
{
    if(instance != nullptr)
    {

        if(EnableAntiDeflector)
        {
            return 0.0f;
        }
    }
    return old_ConfigData_GetDeflectorRange(instance, blockType, fpsSettings);
}

float (*old_ConfigData_GetDeflectorForce)(void *instance, int blockType, int fpsSetting);
float ConfigData_GetDeflectorForce(void *instance, int blockType, int fpsSettings)
{
    if(instance != nullptr)
    {

       if(EnableAntiDeflector)
        {
            return 0.0f;
        }
    }
    return old_ConfigData_GetDeflectorForce(instance, blockType, fpsSettings);
}

float (*old_ConfigData_GetDeflectorForceGrounded)(void *instance, int blockType, int fpsSetting);
float ConfigData_GetDeflectorForceGrounded(void *instance, int blockType, int fpsSettings)
{
    if(instance != nullptr)
    {
        if(EnableAntiDeflector)
        {
            return 0.0f;
        }
    }
    return old_ConfigData_GetDeflectorForceGrounded(instance, blockType, fpsSettings);
}

bool (*old_ConfigData_IsBlockElevator)(void *instance, int blockType);
bool ConfigData_IsBlockElevator(void *instance, int blockType)
{
    if(instance != nullptr)
    {
        if(EnableAntiElevator)
        {
            return false;
        }
    }
    return old_ConfigData_IsBlockElevator(instance, blockType);
}

bool (*old_ConfigData_CanPlaceSeedTopOf)(int blockType);
bool ConfigData_CanPlaceSeedTopOf(int blockType)
{
    if(EnableCanPlaceSeedOnTop)
    {
        return true;
    }
    return old_ConfigData_CanPlaceSeedTopOf(blockType);
}
#endif
