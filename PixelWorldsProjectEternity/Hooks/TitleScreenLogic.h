#ifndef CSY_TITLESCREENLOGIC_H
#define CSY_TITLESCREENLOGIC_H

static float startTips = 0.0f;
static float TimerTips = 1.f;

int randomTips = 1;

void (*old_TitleScreenLogic_Update)(void *instance);
void TitleScreenLogic_Update(void *instance)
{
    if(instance != nullptr)
    {
        startTips += deltaTime;
        if(startTips >= TimerTips)
        {
            startTips = 0.f;
            randomTips = rand() % 3 + 1;
        }

        void *tipsText = *(void **)((uint64_t)instance + PixelWorlds.TitleScreenLogic_tipsText);
        if(tipsText != nullptr)
        {
            switch (randomTips)
            {
                case 1:
                    TMP_Text_SetText(tipsText, CreateIl2cppString(OBFUSCATE("<color=#00FF1A>0xCsy Mods Vert Useful Right?</color>")));
                    break;
                case 2:
                    TMP_Text_SetText(tipsText, CreateIl2cppString(OBFUSCATE("<color=#FF0000>C</color><color=#FF5000>H</color><color=#FFA100>E</color><color=#FFF100>A</color><color=#BBFF00>T</color><color=#6BFF00>I</color><color=#1AFF00>N</color><color=#00FF35>G</color> <color=#00FFD6>I</color><color=#00D6FF>S</color> <color=#0035FF>S</color><color=#1A00FF>O</color> <color=#BB00FF>G</color><color=#FF00F1>A</color><color=#FF00A1>E</color><color=#FF0050>!</color>")));
                    break;
                case 3:
                    TMP_Text_SetText(tipsText, CreateIl2cppString(OBFUSCATE("<color=#FF0000>Y</color><color=#FF1E00>o</color><color=#FF3D00>u</color> <color=#FF7A00>d</color><color=#FF9900>o</color><color=#FFB700>n</color><color=#FFD600>'</color><color=#FFF400>t</color> <color=#CBFF00>u</color><color=#ADFF00>s</color><color=#8EFF00>e</color> <color=#51FF00>0</color><color=#32FF00>x</color><color=#14FF00>C</color><color=#00FF0A>s</color><color=#00FF28>y</color> <color=#00FF66>M</color><color=#00FF84>o</color><color=#00FFA3>d</color><color=#00FFC1>s</color><color=#00FFE0>,</color> <color=#00E0FF>Y</color><color=#00C1FF>O</color><color=#00A3FF>U</color> <color=#0065FF>A</color><color=#0047FF>R</color><color=#0028FF>E</color> <color=#1400FF>S</color><color=#3200FF>O</color> <color=#7000FF>F</color><color=#8E00FF>R</color><color=#AD00FF>I</color><color=#CC00FF>C</color><color=#EA00FF>K</color><color=#FF00F4>I</color><color=#FF00D6>N</color><color=#FF00B7>G</color> <color=#FF007A>G</color><color=#FF005B>A</color><color=#FF003D>E</color><color=#FF001E>!</color>")));
                    break;
            }
        }
    }
    old_TitleScreenLogic_Update(instance);
}

#endif //CSY_TITLESCREENLOGIC_H
