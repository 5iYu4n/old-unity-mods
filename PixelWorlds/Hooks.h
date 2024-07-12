#ifndef HOOKS_H
#define HOOKS_H

void (*TMP_Text_SetText)(void *instance, monoString *text);

bool (*ConfigData_IsBlockInstakill)(int blockType);

bool (*old_ConfigData_CanPlaceSeedTopOf)(int blockType);
bool ConfigData_CanPlaceSeedTopOf(int blockType)
{
    if(EnableCanPlaceSeedOnTop)
    {
        return true;
    }
    return old_ConfigData_CanPlaceSeedTopOf(blockType);
}

float (*old_ConfigData_GetBlockRunSpeed)(int blockType);
float ConfigData_GetBlockRunSpeed(int blockType)
{
    if(setRunSpeed >= 1.7f)
    {
        return setRunSpeed;
    }
    return old_ConfigData_GetBlockRunSpeed(blockType);
}

bool (*old_ConfigData_IsBlockHot)(void *instance, int blockType);
bool ConfigData_IsBlockHot(void *instance, int blockType)
{
    if(instance != nullptr)
    {
        if(EnableAntiBounce)
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
    return old_ConfigData_IsBlockElastic(instance, blockType);
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

void (*old_FishingGaugeMinigameUI_SetFishVelocity)(void *instance);
void FishingGaugeMinigameUI_SetFishVelocity(void *instance)
{
    if(instance != nullptr)
    {
        if(EnableFishHack)
        {
            return;
        }
    }
    old_FishingGaugeMinigameUI_SetFishVelocity(instance);
}

void (*old_GameplayUI_Update)(void *instance);
void GameplayUI_Update(void *instance)
{
    if(instance != nullptr)
    {
        void *zoomSlider = *(void **)((uint64_t)instance + PixelWorlds.GameplayUI_zoomSlider);
        if(zoomSlider != nullptr)
        {
            ZoomSlider = zoomSlider;
        }
    }
    old_GameplayUI_Update(instance);
}

void (*MainMenuLogic_LogOut)(void *instance);

void (*old_MainMenuLogic_Update)(void *instance);
void MainMenuLogic_Update(void *instance)
{
    if(instance != nullptr)
    {
        if(DoLogOut)
        {
            DoLogOut = false;
            MainMenuLogic_LogOut(instance);
        }
    }
    old_MainMenuLogic_Update(instance);
}

void (*old_PixelPerfectCamera_LateUpdate)(void *instance);
void PixelPerfectCamera_LateUpdate(void *instance){
    if(instance != nullptr){
        if(EnableZoomHack && ZoomSlider != nullptr)
        {
            *(int *)((uint64_t)instance + PixelWorlds.PixelPerfectCamera_cameraZoom) = (*(int *)((uint64_t)ZoomSlider + 0x1C)) + 1;
        }
    }
    old_PixelPerfectCamera_LateUpdate(instance);
}

void (*old_Player_Update)(void *instance);
void Player_Update(void *instance)
{
    if(instance != nullptr)
    {
        bool isLocal = *(bool *)((uint64_t)instance + PixelWorlds.Player_isLocalPlayer);
        if(isLocal)
        {
            switch (setFistCooldownLevel) {
                case 1:
                    setFistCooldown = 1.0f;
                    break;
                case 2:
                    setFistCooldown = 0.9f;
                    break;
                case 3:
                    setFistCooldown = 0.8f;
                    break;
                case 4:
                    setFistCooldown = 0.7f;
                    break;
            }
            *(float *)((uint64_t)instance + PixelWorlds.Player_cooldownToUseFistMultiplier) = setFistCooldown;
            if(setJumpModeLevel > 1)
            {
                *(int *)((uint64_t)instance + PixelWorlds.Player_jumpMode) = setJumpModeLevel - 1;
            }

            void *playerNameTextMeshPro = *(void **)((uint64_t)instance + PixelWorlds.Player_playerNameTextMeshPro);
            if(playerNameTextMeshPro != nullptr)
            {
                TMP_Text_SetText(playerNameTextMeshPro, CreateIl2cppString(OBFUSCATE("Modded By 0xCsy")));
            }
        }
    }
    old_Player_Update(instance);
}

void (*old_Player_CheckPoisoned)(void *instance);
void Player_CheckPoisoned(void *instance)
{
    if(instance != nullptr)
    {
        if(EnableGodMod)
        {
            return;
        }
    }
    old_Player_CheckPoisoned(instance);
}

void (*old_Player_CausePoisoned0)(void *instance);
void Player_CausePoisoned0(void *instance)
{
    if(instance != nullptr)
    {
        if(EnableGodMod)
        {
            return;
        }
    }
    old_Player_CausePoisoned0(instance);
}

void (*old_Player_CausePoisoned1)(void *instance);
void Player_CausePoisoned1(void *instance)
{
    if(instance != nullptr)
    {
        if(EnableGodMod)
        {
            return;
        }
    }
    old_Player_CausePoisoned1(instance);
}

void (*old_Player_CausePoisoned2)(void *instance);
void Player_CausePoisoned2(void *instance)
{
    if(instance != nullptr)
    {
        if(EnableGodMod)
        {
            return;
        }
    }
    old_Player_CausePoisoned2(instance);
}

void (*old_Player_HitPlayerFromAIEnemy0)(void *instance, void *aiBase, int aiDamageModelType);
void Player_HitPlayerFromAIEnemy0(void *instance, void *aiBase, int aiDamageModelType)
{
    if(instance != nullptr)
    {
        if(EnableGodMod)
        {
            return;
        }
    }
    old_Player_HitPlayerFromAIEnemy0(instance, aiBase, aiDamageModelType);
}

void (*old_Player_HitPlayerFromAIEnemy1)(void *instance, int hitForce, int aiEnemyType);
void Player_HitPlayerFromAIEnemy1(void *instance, int hitForce, int aiEnemyType)
{
    if(instance != nullptr)
    {
        if(EnableGodMod)
        {
            return;
        }
    }
    old_Player_HitPlayerFromAIEnemy1(instance, hitForce, aiEnemyType);
}

void (*old_Player_HitPlayerFromBlock0)(void *instance);
void Player_HitPlayerFromBlock0(void *instance)
{
    if(instance != nullptr)
    {
        if(EnableGodMod)
        {
            return;
        }
    }
    old_Player_HitPlayerFromBlock0(instance);
}

void (*old_Player_HitPlayerFromBlock1)(void *instance);
void Player_HitPlayerFromBlock1(void *instance)
{
    if(instance != nullptr)
    {
        if(EnableGodMod)
        {
            return;
        }
    }
    old_Player_HitPlayerFromBlock1(instance);
}

void (*old_Player_CheckCheckPoints)(void *instance);
void Player_CheckCheckPoints(void *instance)
{
    if(instance != nullptr)
    {
        if(EnableAntiCheckPoint)
        {
            return;
        }
    }
    old_Player_CheckCheckPoints(instance);
}

void (*old_Player_CheckPortals)(void *instance);
void Player_CheckPortals(void *instance)
{
    if(instance != nullptr)
    {
        if(EnableAntiPortal)
        {
            return;
        }
    }
    old_Player_CheckPortals(instance);
}

void (*old_Player_CheckInvertedControls)(void *instance);
void Player_CheckInvertedControls(void *instance)
{
    if(instance != nullptr)
    {
        if(EnableAntiInvertedControls)
        {
            return;
        }
    }
    old_Player_CheckInvertedControls(instance);
}

bool (*old_PlayerData_HasUnlockedRecipe)(void *instance, int blockType);
bool PlayerData_HasUnlockedRecipe(void *instance, int blockType)
{
    if(instance != nullptr)
    {
        if(EnableUnlockAllRecipes)
        {
            return true;
        }
    }
    return old_PlayerData_HasUnlockedRecipe(instance, blockType);
}

void (*old_ProfanityFilter_Censor)(void *instance);
void ProfanityFilter_Censor(void *instance)
{
    if(instance != nullptr)
    {
        if(EnableAntiCensor)
        {
            return;
        }
    }
    old_ProfanityFilter_Censor(instance);
}

void (*old_TrapProjectile_OnTriggerEnter2D)(void *instance, void *other);
void TrapProjectile_OnTriggerEnter2D(void *instance, void *other)
{
    if(instance != nullptr)
    {
        if(EnableGodMod)
        {
            return;
        }
    }
    old_TrapProjectile_OnTriggerEnter2D(instance, other);
}

bool (*old_World_DoesPlayerHaveRightToModifyItemDataByMinorRightsLockWorld)(void *instance, Vector2i mapPoint, void *playerData);
bool World_DoesPlayerHaveRightToModifyItemDataByMinorRightsLockWorld(void *instance, Vector2i mapPoint, void *playerData)
{
    if(instance != nullptr)
    {
        if(EnableLocalFullRight)
        {
            return true;
        }
    }
    return old_World_DoesPlayerHaveRightToModifyItemDataByMinorRightsLockWorld(instance, mapPoint, playerData);
}

void (*old_WorldController_ChangeLighting)(void *instance, int lightingType);
void WorldController_ChangeLighting(void *instance, int lightingType)
{
    if(instance != nullptr)
    {
        if(EnableLightAlwaysOn)
        {
            return;
        }
    }
    old_WorldController_ChangeLighting(instance, lightingType);
}

void (*old_WorldController_InstantiateFogOfWar)(void *instance);
void WorldController_InstantiateFogOfWar(void *instance)
{
    if(instance != nullptr)
    {
        if(EnableAlwaysFogOff)
        {
            return;
        }
    }
    old_WorldController_InstantiateFogOfWar(instance);
}

void (*old_WorldController_BlockColliderAndLayerHelper)(void *instance, int blockType, void *gameObject, Vector2i mapPoint);
void WorldController_BlockColliderAndLayerHelper(void *instance, int blockType, void *gameObject, Vector2i mapPoint)
{
    if(instance != nullptr)
    {
        if(EnableGodMod && ConfigData_IsBlockInstakill(blockType))
        {
            blockType = 1;
        }
    }
    old_WorldController_BlockColliderAndLayerHelper(instance, blockType, gameObject, mapPoint);
}

void (*old_WorldController_KickPlayerByInactivity)(void *instance, monoString *deltaParameter);
void WorldController_KickPlayerByInactivity(void *instance, monoString *deltaParameter)
{
    if(instance != nullptr)
    {
        if(EnableAntiAFKKick)
        {
            return;
        }
    }
    old_WorldController_KickPlayerByInactivity(instance, deltaParameter);
}

namespace PIXELWORLDS
{
    void LOAD_HOOKS()
    {
        TMP_Text_SetText = (void (*)(void *, monoString *)) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x8DEE88")));

        ConfigData_IsBlockInstakill = (bool (*)(int)) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x1E6C6BC")));

        MainMenuLogic_LogOut = (void (*)(void *)) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x21E5FA0")));

        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x1E85BB0"))), (void *)ConfigData_CanPlaceSeedTopOf, (void **)&old_ConfigData_CanPlaceSeedTopOf);
        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x1E71218"))), (void *) ConfigData_IsBlockHot, (void **) &old_ConfigData_IsBlockHot);
        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x1E70FF8"))), (void *) ConfigData_IsBlockSpring, (void **) &old_ConfigData_IsBlockSpring);
        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x1E78214"))), (void *) ConfigData_IsBlockElastic, (void **) &old_ConfigData_IsBlockElastic);
        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x1E81EF0"))), (void *) ConfigData_IsBlockDeflector, (void **) &old_ConfigData_IsBlockDeflector);
        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x1E81FF0"))), (void *) ConfigData_GetDeflectorRange, (void **) &old_ConfigData_GetDeflectorRange);
        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x1E81F14"))), (void *) ConfigData_GetDeflectorForce, (void **) &old_ConfigData_GetDeflectorForce);
        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x1E81F48"))), (void *) ConfigData_GetDeflectorForceGrounded, (void **) &old_ConfigData_GetDeflectorForceGrounded);
        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x1E8207C"))), (void *) ConfigData_IsBlockElevator, (void **) &old_ConfigData_IsBlockElevator);
        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x1E7143C"))), (void *) ConfigData_IsBlockPinball, (void **) &old_ConfigData_IsBlockPinball);
        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x1E70DD4"))), (void *) ConfigData_IsBlockTrampolin, (void **) &old_ConfigData_IsBlockTrampolin);
        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x1E763B4"))), (void *) ConfigData_IsBlockWind, (void **) &old_ConfigData_IsBlockWind);
        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x1E6FBD8"))), (void *)ConfigData_GetBlockRunSpeed, (void **)&old_ConfigData_GetBlockRunSpeed);
        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x22F878C"))), (void *)FishingGaugeMinigameUI_SetFishVelocity, (void **)&old_FishingGaugeMinigameUI_SetFishVelocity);
        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x1F4DB08"))), (void *)GameplayUI_Update, (void **)&old_GameplayUI_Update);
        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x21E6238"))), (void *)MainMenuLogic_Update, (void **)&old_MainMenuLogic_Update);
        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x1BE0E44"))), (void *)PixelPerfectCamera_LateUpdate, (void **)&old_PixelPerfectCamera_LateUpdate);
        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x1BF5160"))), (void *) Player_Update, (void **) &old_Player_Update);
        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x1C113B0"))), (void *) Player_CheckCheckPoints, (void **) &old_Player_CheckCheckPoints);
        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x1C1036C"))), (void *) Player_CheckPortals, (void **) &old_Player_CheckPortals);
        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x1BFB93C"))), (void *) Player_CheckInvertedControls, (void **) &old_Player_CheckInvertedControls);
        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x1C0F164"))), (void *) Player_CheckPoisoned, (void **) &old_Player_CheckPoisoned);
        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x1C24DEC"))), (void *) Player_CausePoisoned0, (void **) &old_Player_CausePoisoned0);
        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x1C26680"))), (void *) Player_CausePoisoned1, (void **) &old_Player_CausePoisoned1);
        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x1C264AC"))), (void *) Player_CausePoisoned2, (void **) &old_Player_CausePoisoned2);
        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x1C25C00"))), (void *) Player_HitPlayerFromAIEnemy0, (void **) &old_Player_HitPlayerFromAIEnemy0);
        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x1C25ECC"))), (void *) Player_HitPlayerFromAIEnemy1, (void **) &old_Player_HitPlayerFromAIEnemy1);
        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x1C137C8"))), (void *) Player_HitPlayerFromBlock0, (void **) &old_Player_HitPlayerFromBlock0);
        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x1C24F18"))), (void *) Player_HitPlayerFromBlock1, (void **) &old_Player_HitPlayerFromBlock1);
        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x2091C1C"))), (void *)PlayerData_HasUnlockedRecipe, (void **)&old_PlayerData_HasUnlockedRecipe);
        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x1FFB2C4"))), (void *)ProfanityFilter_Censor, (void **)&old_ProfanityFilter_Censor);
        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x23E9BC8"))), (void *)TrapProjectile_OnTriggerEnter2D, (void **)&old_TrapProjectile_OnTriggerEnter2D);
        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x1C8C5B0"))), (void *)World_DoesPlayerHaveRightToModifyItemDataByMinorRightsLockWorld, (void **)&old_World_DoesPlayerHaveRightToModifyItemDataByMinorRightsLockWorld);
        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x1BCEA14"))), (void *)WorldController_ChangeLighting, (void **)&old_WorldController_ChangeLighting);
        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x1BBF614"))), (void *)WorldController_InstantiateFogOfWar, (void **)&old_WorldController_InstantiateFogOfWar);
        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x1B6C954"))), (void *)WorldController_BlockColliderAndLayerHelper, (void **)&old_WorldController_BlockColliderAndLayerHelper);
        MSHookFunction((void *) getAbsoluteAddress(targetLibName, string2Offset(ProtectOffset("0x1B50C4C"))), (void *)WorldController_KickPlayerByInactivity, (void **)&old_WorldController_KickPlayerByInactivity);
    }
}

#endif
