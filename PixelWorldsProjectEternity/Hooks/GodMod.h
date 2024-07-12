#ifndef CSY_GODMOD_H
#define CSY_GODMOD_H

static bool EnableGodMod = false;

void (*old_Player_CausePoisoned0)(void *instance, int causeBlockType);
void Player_CausePoisoned0(void *instance, int causeBlockType)
{
    if(instance != nullptr)
    {
        if(EnableGodMod)
        {
            return;
        }
    }
    old_Player_CausePoisoned0(instance, causeBlockType);
}

void (*old_Player_CausePoisoned1)(void *instance, int enemyType);
void Player_CausePoisoned1(void *instance, int enemyType)
{
    if(instance != nullptr)
    {
        if(EnableGodMod)
        {
            return;
        }
    }
    old_Player_CausePoisoned1(instance, enemyType);
}

void (*old_Player_CausePoisoned2)(void *instance, float poisonedCooldown);
void Player_CausePoisoned2(void *instance, float poisonedCooldown)
{
    if(instance != nullptr)
    {
        if(EnableGodMod)
        {
            return;
        }
    }
    old_Player_CausePoisoned2(instance, poisonedCooldown);
}

void (*old_Player_HitPlayerFromAIEnemy0)(void *instance, void *aiEnemy, int aiDamageModelType);
void Player_HitPlayerFromAIEnemy0(void *instance, void *aiEnemy, int aiDamageModelType)
{
    if(instance != nullptr)
    {
        if(EnableGodMod)
        {
            return;
        }
    }
    old_Player_HitPlayerFromAIEnemy0(instance, aiEnemy, aiDamageModelType);
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

void (*old_Player_HitPlayerFromBlock0)(void *instance, int blocktype, Vector2i blockMapPoint);
void Player_HitPlayerFromBlock0(void *instance, int blocktype, Vector2i blockMapPoint)
{
    if(instance != nullptr)
    {
        if(EnableGodMod)
        {
            return;
        }
    }
    old_Player_HitPlayerFromBlock0(instance, blocktype, blockMapPoint);
}

void (*old_Player_HitPlayerFromBlock1)(void *instance, int hitForce, int hitFromBlockType, Vector2i blockMapPoint);
void Player_HitPlayerFromBlock1(void *instance, int hitForce, int hitFromBlockType, Vector2i blockMapPoint)
{
    if(instance != nullptr)
    {
        if(EnableGodMod)
        {
            return;
        }
    }
    old_Player_HitPlayerFromBlock1(instance, hitForce, hitFromBlockType, blockMapPoint);
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

#endif
