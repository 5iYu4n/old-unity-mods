#ifndef CSY_AUTOHEALING_H
#define CSY_AUTOHEALING_H

void autoHealing(int maxHealth, int currentHealth)
{
    if(SetHealthPercentForHeal > 0)
    {
        if(canHeal)
        {
            if(((currentHealth * 100) / maxHealth) <= SetHealthPercentForHeal)
            {
                canHeal = false;
                LastAutoHeal = currentHealth;
                OutgoingMessages_SendUsePotionMessage(2303);
            }
        }
        else
        {
            if(LastAutoHeal < currentHealth)
            {
                canHeal = true;
            }
        }
    }
}

#endif
