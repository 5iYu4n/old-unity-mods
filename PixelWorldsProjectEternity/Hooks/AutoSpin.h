#ifndef CSY_AUTOSPIN_H
#define CSY_AUTOSPIN_H

static bool EnableMineSpin = false;
int MineTokenToUse = 0;

static bool EnableJetSpin = false;
int JetTokenToUse = 0;

void Auto_Spin()
{
    if(EnableMineSpin)
    {
        EnableMineSpin = false;
        for (int i = 0; i < MineTokenToUse; ++i) {
            OutgoingMessages_SendSpinMiningRouletteMessage();
        }
        SceneLoader_ReloadGame();
    }

    if(EnableJetSpin)
    {
        EnableJetSpin = false;
        for (int i = 0; i < JetTokenToUse; ++i) {
            OutgoingMessages_SendSpinJetRaceRouletteMessage();
        }
        SceneLoader_ReloadGame();
    }
}

#endif
