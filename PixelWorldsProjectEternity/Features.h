#ifndef FEATURES_H
#define FEATURES_H

extern "C" {
    JNIEXPORT jobjectArray JNICALL
    Java_com_csy_modmenu_FloatingModMenuService_getFeatureList(JNIEnv *env, jobject context) {
        jobjectArray ret;

        const char *features[] = {
                OBFUSCATE("Collapse_Setting"),
                OBFUSCATE("-1_CollapseAdd_CheckBox_Enable Save Feature"),
                OBFUSCATE("36_CollapseAdd_Spinner_Set FPS Limit_Default,30 FPS,60 FPS,90 FPS,120 FPS,240 FPS"),

                OBFUSCATE("Collapse_Player"),
                OBFUSCATE("47_CollapseAdd_InputText_Set Custom Name"),
                OBFUSCATE("1_CollapseAdd_CheckBox_Enable God Mod"),
                OBFUSCATE("37_CollapseAdd_SeekBarInt_Set Auto Healing Health %_0_100"),
                OBFUSCATE("16_CollapseAdd_SeekBar_Set Run Speed_18_30"),
                OBFUSCATE("48_CollapseAdd_SeekBar_Set Fist Cooldown_7_10"),
                OBFUSCATE("49_CollapseAdd_Spinner_Set Jump Mode_Default,Normal Jump,Double Jump,Long Jump,Parachute,Jet Pack,Continuous Jumping,Triple Jump,Flying Mount"),
                OBFUSCATE("50_CollapseAdd_Spinner_Set Gravity Mode_Default,Normal,Low,High"),
                OBFUSCATE("17_CollapseAdd_CheckBox_Enable Anti-Lava Bounce"),
                OBFUSCATE("18_CollapseAdd_CheckBox_Enable Anti-Bounce"),
                OBFUSCATE("19_CollapseAdd_CheckBox_Enable Anti-Elastic"),
                OBFUSCATE("20_CollapseAdd_CheckBox_Enable Anti-Pinball"),
                OBFUSCATE("21_CollapseAdd_CheckBox_Enable Anti-Trampoline"),
                OBFUSCATE("22_CollapseAdd_CheckBox_Enable Anti-Wind"),
                OBFUSCATE("23_CollapseAdd_CheckBox_Enable Anti-Deflector"),
                OBFUSCATE("24_CollapseAdd_CheckBox_Enable Anti-Elevator"),
                OBFUSCATE("25_CollapseAdd_CheckBox_Enable Anti-Inverted Controls"),
                OBFUSCATE("26_CollapseAdd_CheckBox_Enable Anti-Portal"),
                OBFUSCATE("27_CollapseAdd_CheckBox_Enable Anti-Check Point"),
                OBFUSCATE("28_CollapseAdd_CheckBox_Enable Anti-Pickup"),

                OBFUSCATE("Collapse_ESP"),
                OBFUSCATE("CollapseAdd_RichTextView_➥ESP Options:"),
                OBFUSCATE("51_CollapseAdd_CheckBox_Enable ESP Line"),
                OBFUSCATE("52_CollapseAdd_CheckBox_Enable ESP Box"),
                //OBFUSCATE("53_CollapseAdd_CheckBox_Enable ESP Health Bar"),
                OBFUSCATE("CollapseAdd_RichTextView_➥Entities:"),
                OBFUSCATE("55_CollapseAdd_CheckBox_Enable ESP Player"),
                OBFUSCATE("61_CollapseAdd_Spinner_Set Player ESP Color_Default,Color Black,Color White,Color Purple,Color Purple Blue,Color Blue,Color Blue Green,Color Green,Color Green Yellow,Color Yellow,Color Yellow Orange,Color Orange,Color Orange Red,Color Red,Color Red Purple"),
                OBFUSCATE("54_CollapseAdd_CheckBox_Enable ESP Monster"), //ESPBoss
                OBFUSCATE("58_CollapseAdd_Spinner_Set Monster ESP Color_Default,Color Black,Color White,Color Purple,Color Purple Blue,Color Blue,Color Blue Green,Color Green,Color Green Yellow,Color Yellow,Color Yellow Orange,Color Orange,Color Orange Red,Color Red,Color Red Purple"),
                OBFUSCATE("70_CollapseAdd_Spinner_Set Boss ESP Color_Default,Color Black,Color White,Color Purple,Color Purple Blue,Color Blue,Color Blue Green,Color Green,Color Green Yellow,Color Yellow,Color Yellow Orange,Color Orange,Color Orange Red,Color Red,Color Red Purple"),
                OBFUSCATE("56_CollapseAdd_CheckBox_Enable ESP Collectable"),
                OBFUSCATE("62_CollapseAdd_Spinner_Set Collectable ESP Color_Default,Color Black,Color White,Color Purple,Color Purple Blue,Color Blue,Color Blue Green,Color Green,Color Green Yellow,Color Yellow,Color Yellow Orange,Color Orange,Color Orange Red,Color Red,Color Red Purple"),
                OBFUSCATE("57_CollapseAdd_CheckBox_Enable ESP Butterfly"),
                OBFUSCATE("63_CollapseAdd_Spinner_Set Butterfly ESP Color_Default,Color Black,Color White,Color Purple,Color Purple Blue,Color Blue,Color Blue Green,Color Green,Color Green Yellow,Color Yellow,Color Yellow Orange,Color Orange,Color Orange Red,Color Red,Color Red Purple"),
                OBFUSCATE("65_CollapseAdd_CheckBox_Enable ESP Spirit"),
                OBFUSCATE("66_CollapseAdd_Spinner_Set Spirit ESP Color_Default,Color Black,Color White,Color Purple,Color Purple Blue,Color Blue,Color Blue Green,Color Green,Color Green Yellow,Color Yellow,Color Yellow Orange,Color Orange,Color Orange Red,Color Red,Color Red Purple"),
                OBFUSCATE("CollapseAdd_RichTextView_➥Nether:"),
                OBFUSCATE("71_CollapseAdd_CheckBox_Enable ESP Gift Box"),
                OBFUSCATE("72_CollapseAdd_Spinner_Set Gift Box ESP Color_Default,Color Black,Color White,Color Purple,Color Purple Blue,Color Blue,Color Blue Green,Color Green,Color Green Yellow,Color Yellow,Color Yellow Orange,Color Orange,Color Orange Red,Color Red,Color Red Purple"),
                OBFUSCATE("73_CollapseAdd_CheckBox_Enable ESP Treasure Box"),
                OBFUSCATE("74_CollapseAdd_Spinner_Set Treasure Box ESP Color_Default,Color Black,Color White,Color Purple,Color Purple Blue,Color Blue,Color Blue Green,Color Green,Color Green Yellow,Color Yellow,Color Yellow Orange,Color Orange,Color Orange Red,Color Red,Color Red Purple"),
                OBFUSCATE("75_CollapseAdd_CheckBox_Enable ESP Special Item"),
                OBFUSCATE("76_CollapseAdd_Spinner_Set Special Item ESP Color_Default,Color Black,Color White,Color Purple,Color Purple Blue,Color Blue,Color Blue Green,Color Green,Color Green Yellow,Color Yellow,Color Yellow Orange,Color Orange,Color Orange Red,Color Red,Color Red Purple"),
                OBFUSCATE("77_CollapseAdd_CheckBox_Enable ESP Exit Door"),
                OBFUSCATE("78_CollapseAdd_Spinner_Set Exit Dor ESP Color_Default,Color Black,Color White,Color Purple,Color Purple Blue,Color Blue,Color Blue Green,Color Green,Color Green Yellow,Color Yellow,Color Yellow Orange,Color Orange,Color Orange Red,Color Red,Color Red Purple"),
                OBFUSCATE("CollapseAdd_RichTextView_➥Mine:"),
                OBFUSCATE("79_CollapseAdd_CheckBox_Enable ESP Gemstone"),
                OBFUSCATE("80_CollapseAdd_Spinner_Set Gemstone ESP Color_Default,Color Black,Color White,Color Purple,Color Purple Blue,Color Blue,Color Blue Green,Color Green,Color Green Yellow,Color Yellow,Color Yellow Orange,Color Orange,Color Orange Red,Color Red,Color Red Purple"),
                OBFUSCATE("81_CollapseAdd_CheckBox_Enable ESP Crate"),
                OBFUSCATE("82_CollapseAdd_Spinner_Set Crate ESP Color_Default,Color Black,Color White,Color Purple,Color Purple Blue,Color Blue,Color Blue Green,Color Green,Color Green Yellow,Color Yellow,Color Yellow Orange,Color Orange,Color Orange Red,Color Red,Color Red Purple"),
                OBFUSCATE("83_CollapseAdd_CheckBox_Enable ESP Exit Door"),
                OBFUSCATE("84_CollapseAdd_Spinner_Set Exit Dor ESP Color_Default,Color Black,Color White,Color Purple,Color Purple Blue,Color Blue,Color Blue Green,Color Green,Color Green Yellow,Color Yellow,Color Yellow Orange,Color Orange,Color Orange Red,Color Red,Color Red Purple"),

                OBFUSCATE("Collapse_Farm"),
                OBFUSCATE("CollapseAdd_RichTextView_➥Auto-Break:"),
                OBFUSCATE("107_CollapseAdd_CheckBox_Enable Auto Farm"),
                OBFUSCATE("109_CollapseAdd_CheckBox_Enable Farm Info Label"),
                OBFUSCATE("113_CollapseAdd_CheckBox_Enable Auto Drop Seed"),
                OBFUSCATE("108_CollapseAdd_Button_Save Seed To Drop"),
                OBFUSCATE("110_CollapseAdd_SeekBarInt_Set Seed Amount Limit In Inventory Before Drop_0_999"),
                OBFUSCATE("111_CollapseAdd_SeekBarInt_Set Collectable Amount Limit % In Map Point_0_100"),
                OBFUSCATE("112_CollapseAdd_SeekBarInt_Set Repeat Process_0_30"),

                OBFUSCATE("Collapse_Fish"),
                OBFUSCATE("92_CollapseAdd_CheckBox_Enable Auto Fish"),
                OBFUSCATE("93_CollapseAdd_CheckBox_Enable Info Label"),
                OBFUSCATE("CollapseAdd_RichTextView_➥Config:"),
                OBFUSCATE("94_CollapseAdd_True_CheckBox_Enable Auto-Set Bait"),
                OBFUSCATE("95_CollapseAdd_True_CheckBox_Enable Auto-Fish Strike"),
                OBFUSCATE("96_CollapseAdd_True_CheckBox_Enable Auto-Play Fish Game"),
                OBFUSCATE("CollapseAdd_RichTextView_➥Extra:"),
                OBFUSCATE("97_CollapseAdd_CheckBox_Enable Ignore Tiny Fish"),
                OBFUSCATE("98_CollapseAdd_CheckBox_Enable Ignore Small Fish"),
                OBFUSCATE("99_CollapseAdd_CheckBox_Enable Ignore Medium Fish"),
                OBFUSCATE("100_CollapseAdd_CheckBox_Enable Ignore Large Fish"),
                OBFUSCATE("101_CollapseAdd_True_CheckBox_Enable Ignore Huge Fish"),
                OBFUSCATE("CollapseAdd_RichTextView_➥Module:"),
                OBFUSCATE("102_CollapseAdd_SeekBarInt_Set Tiny Fish Reduce Chance_0_100"),
                OBFUSCATE("103_CollapseAdd_SeekBarInt_Set Tiny Small Reduce Chance_0_100"),
                OBFUSCATE("104_CollapseAdd_SeekBarInt_Set Tiny Medium Reduce Chance_0_100"),
                OBFUSCATE("105_CollapseAdd_SeekBarInt_Set Tiny Large Reduce Chance_0_100"),
                OBFUSCATE("106_CollapseAdd_SeekBarInt_Set Tiny Huge Reduce Chance_0_100"),

                OBFUSCATE("Collapse_Nether"),
                OBFUSCATE("117_CollapseAdd_Button_Manually Reload Nether World"),
                OBFUSCATE("4_CollapseAdd_CheckBox_Enable Nether Aimbot"),
                OBFUSCATE("5_CollapseAdd_CheckBox_Enable Nether Auto-Claim Near Giftbox"),
                OBFUSCATE("6_CollapseAdd_CheckBox_Enable Nether Auto-Break Near Treasure Box"),
                //OBFUSCATE("7_CollapseAdd_CheckBox_Enable Ez Nether World"),
                OBFUSCATE("0_CollapseAdd_CheckBox_Enable Auto Search Nether Boss"),

                OBFUSCATE("Collapse_Mine"),
                OBFUSCATE("CollapseAdd_RichTextView_➥Auto-Mine:"),
                OBFUSCATE("9_CollapseAdd_CheckBox_Enable Auto-Mine"),
                OBFUSCATE("10_CollapseAdd_CheckBox_Enable Auto-Collect Collectable"),
                OBFUSCATE("11_CollapseAdd_CheckBox_Enable Auto-Break Gemstone"),
                //OBFUSCATE("12_CollapseAdd_CheckBox_Enable Auto-Break Crate"),
                OBFUSCATE("13_CollapseAdd_CheckBox_Enable Auto-Kill Near Monster"),
                OBFUSCATE("CollapseAdd_RichTextView_➥Misc:"),
                OBFUSCATE("14_CollapseAdd_Spinner_Set Auto Repair Pickaxe_None,Crappy Pickaxe,Flimsy Pickaxe,Basic Pickaxe,Sturdy Pickaxe,Heavy Pickaxe,Master Pickaxe,Epic Pickaxe,Dark Pickaxe"),
                OBFUSCATE("88_CollapseAdd_CheckBox_Enable Only Collect Gemstone, Nugget & pWatch"),
                OBFUSCATE("89_CollapseAdd_CheckBox_Enable Auto-Convert Nuggets To Key"),
                OBFUSCATE("CollapseAdd_RichTextView_➥Mine Token:"),
                OBFUSCATE("38_CollapseAdd_InputValue_Set Mine Token To Spin"),
                OBFUSCATE("39_CollapseAdd_Button_Spin Mine Roulette"),

                OBFUSCATE("Collapse_Secret Base"),
                OBFUSCATE("44_CollapseAdd_CheckBox_Enable Aimbot"),
                OBFUSCATE("45_CollapseAdd_CheckBox_Enable Auto-Claim Near Gift Box"),

                OBFUSCATE("Collapse_Jet Race"),
                //OBFUSCATE("CollapseAdd_RichTextView_➥Mod:"),
                //OBFUSCATE("46_CollapseAdd_CheckBox_Enable Ez Jet Race World"),
                OBFUSCATE("CollapseAdd_RichTextView_➥Jet Race Token:"),
                OBFUSCATE("40_CollapseAdd_InputValue_Set Jet Race Token To Spin"),
                OBFUSCATE("41_CollapseAdd_Button_Spin Jet Race Roulette"),

                //OBFUSCATE("Collapse_Halloween"),
                //OBFUSCATE("8_CollapseAdd_CheckBox_Halloween Info Label"),

                OBFUSCATE("Collapse_Event Spirit"),
                OBFUSCATE("67_CollapseAdd_CheckBox_Enable Aimbot"),

                OBFUSCATE("Collapse_Pack"),
                OBFUSCATE("CollapseAdd_ButtonLink_Click To Get Pack Name_https://pastebin.com/3P3j1P18"),
                OBFUSCATE("87_CollapseAdd_InputText_Set Gem Pack Name"),
                OBFUSCATE("85_CollapseAdd_InputValue_Set Buy Time"),
                OBFUSCATE("86_CollapseAdd_Button_Click To Buy Pack"),

                OBFUSCATE("Collapse_World"),
                //OBFUSCATE("116_CollapseAdd_CheckBox_Enable TP By Touch"),
                //OBFUSCATE("127_CollapseAdd_CheckBox_Enable Free Cam"),
                OBFUSCATE("90_CollapseAdd_InputText_Set Warp World"),
                OBFUSCATE("91_CollapseAdd_Button_Click To Warp"),
                OBFUSCATE("69_CollapseAdd_CheckBox_Enable Zoom Hack"),
                OBFUSCATE("64_CollapseAdd_CheckBox_Enable Gems Counter"),
                OBFUSCATE("2_CollapseAdd_CheckBox_Enable Light Always On"),
                OBFUSCATE("3_CollapseAdd_CheckBox_Enable Fog Always Off"),
                OBFUSCATE("118_CollapseAdd_CheckBox_Enable World Full Right (Local)"),
                OBFUSCATE("15_CollapseAdd_CheckBox_Enable Remove All Monster"),
                OBFUSCATE("114_CollapseAdd_CheckBox_Enable Get Item Data By Touch"),
                //OBFUSCATE("115_CollapseAdd_CheckBox_Enable Portal TP By Touch"),

                OBFUSCATE("Collapse_Misc"),
                //OBFUSCATE("999_CollapseAdd_Button_Extract Event Date"),
                //OBFUSCATE("997_CollapseAdd_Spinner_Set Gem Pack Category_Kits,Boosters,Wearables,Seeds,Locks,Fishing,Familiars,Pets,Orbs,Battle Cards,Wiring,Special Items,Blueprints,Community Items,Clan Items"),
                //OBFUSCATE("998_CollapseAdd_Button_Extract Pack Name"),
                OBFUSCATE("29_CollapseAdd_Button_Click To Game Refresh"),
                OBFUSCATE("30_CollapseAdd_Button_Click To Log Out"),
                OBFUSCATE("31_CollapseAdd_CheckBox_Enable Unlock All Recipes"),
                OBFUSCATE("32_CollapseAdd_CheckBox_Enable Anti-AFK Kick"),
                OBFUSCATE("33_CollapseAdd_CheckBox_Enable Anti-Censor"),
                OBFUSCATE("34_CollapseAdd_CheckBox_Enable Can Place Seed On Everywhere"),
                OBFUSCATE("35_CollapseAdd_CheckBox_Enable Instant Drop"),
                //OBFUSCATE("68_CollapseAdd_CheckBox_Enable Bypass World Name Check"),

                OBFUSCATE("Collapse_Visual"),
                OBFUSCATE("CollapseAdd_RichTextView_➥INFO:"),
                OBFUSCATE("CollapseAdd_ButtonLink_Click To Get Block, Wearable ID_https://pastebin.com/1QPQSJSB"),
                OBFUSCATE("CollapseAdd_RichTextView_➥PLAYER:"),
                OBFUSCATE("43_CollapseAdd_CheckBox_Enable Inventory Controller"),
                OBFUSCATE("59_CollapseAdd_InputValue_Set Wearable ID"),
                OBFUSCATE("60_CollapseAdd_Button_Click To Wear"),
                OBFUSCATE("CollapseAdd_RichTextView_➥WORLD:"),
                OBFUSCATE("119_CollapseAdd_Spinner_Set Background_Disable,Forest Background,Night Background,Space Background,Desert Background,Ice Background,Star Background,Candy Background,Halloween Tower Background,Cemetery Background,Nether Background,City Background,Blue Sky Background,Jet Race Background"),
                OBFUSCATE("120_CollapseAdd_Spinner_Set Weather_Disable,None,Heavy Rain,Pixel Trail,Sand Storm,Light Rain,Light Snow,Snow Storm,Deep Nether,Halloween,Halloween Tower,Hearts,Mining,Aurora Borealis,Armageddon"),
                OBFUSCATE("121_CollapseAdd_Spinner_Set Lighting_Disable,None,Dark,Mining,Lesser Dark,Great Dark"),
                OBFUSCATE("CollapseAdd_RichTextView_➥World Visual Item:"),
                OBFUSCATE("122_CollapseAdd_InputValue_Set Visual Block ID"),
                OBFUSCATE("124_CollapseAdd_Spinner_Set Visual Block Type To Remove_Disable,Block & Prop,Background Block,Water Block"),
                OBFUSCATE("123_CollapseAdd_CheckBox_Enable Add Visual Block By 2-Tap"),
        };

        int Total_Feature = (sizeof features / sizeof features[0]);
        ret = (jobjectArray)
                env->NewObjectArray(Total_Feature, env->FindClass(OBFUSCATE("java/lang/String")),
                                    env->NewStringUTF(""));

        for (int i = 0; i < Total_Feature; i++)
            env->SetObjectArrayElement(ret, i, env->NewStringUTF(features[i]));

        pthread_t ptid;
        pthread_create(&ptid, NULL, antiLeech, NULL);

        return (ret);
    }

    JNIEXPORT void JNICALL
    Java_com_csy_modmenu_Preferences_Changes(JNIEnv *env, jclass clazz, jobject obj,
                                             jint featNum, jstring featName, jint value,
                                             jboolean boolean, jstring str) {

        switch (featNum) {
            case 0:
                EnableAutoSearchNetherBoss = boolean;
                break;
            case 1:
                EnableGodMod = boolean;
                break;
            case 2:
                EnableAlwaysLightOn = boolean;
                break;
            case 3:
                EnableAlwaysFogOff = boolean;
                break;
            case 4:
                EnableNetherAimbot = boolean;
                break;
            case 5:
                EnableAutoClaimNetherGiftBox = boolean;
                break;
            case 6:
                EnableAutoBreakNetherTreasureBox = boolean;
                break;
            case 8:
                EnableHalloweenInfoLabel = boolean;
                break;
            case 9:
                EnableAutoMine = boolean;
                break;
            case 10:
                EnableMineAutoCollect = boolean;
                break;
            case 11:
                EnableAutoBreakGemstone = boolean;
                break;
            case 12:
                EnableAutoBreakCrate = boolean;
                break;
            case 13:
                EnableAutoKillMonster = boolean;
                break;
            case 14:
                current_pickaxe = value - 1;
                break;
            case 15:
                EnableDisableAiEnemy = boolean;
                break;
            case 16:
                setRunSpeed = SeekBarToFloat(value);
                break;
            case 17:
                EnableAntiLavaBounce = boolean;
                break;
            case 18:
                EnableAntiBounce = boolean;
                break;
            case 19:
                EnableAntiElastic = boolean;
                break;
            case 20:
                EnableAntiPinball = boolean;
                break;
            case 21:
                EnableAntiTrampolin = boolean;
                break;
            case 22:
                EnableAntiWind = boolean;
                break;
            case 23:
                EnableAntiDeflector = boolean;
                break;
            case 24:
                EnableAntiElevator = boolean;
                break;
            case 25:
                EnableAntiInvertedControls = boolean;
                break;
            case 26:
                EnableAntiPortal = boolean;
                break;
            case 27:
                EnableAntiCheckPoint = boolean;
                break;
            case 28:
                EnableAntiPickup = boolean;
                break;
            case 29:
                SceneLoader_ReloadGame();
                break;
            case 30:
                DoLogOutOnce = true;
                break;
            case 31:
                EnableUnlockAllRecipes = boolean;
                break;
            case 32:
                EnableAntiAFKKick = boolean;
                break;
            case 33:
                EnableAntiWordCensor = boolean;
                break;
            case 34:
                EnableCanPlaceSeedOnTop = boolean;
                break;
            case 35:
                EnableToSelectDrop = boolean;
                break;
            case 36:
                fpsOptions = value;
                break;
            case 37:
                SetHealthPercentForHeal = value;
                break;
            case 38:
                MineTokenToUse = value;
                break;
            case 39:
                EnableMineSpin = true;
                break;
            case 40:
                JetTokenToUse = value;
                break;
            case 41:
                EnableJetSpin = true;
                break;
            case 42:
                break;
            case 43:
                EnableDrawInventoryController = boolean;
                break;
            case 44:
                EnableSuperHeroAimbot = boolean;
                break;
            case 45:
                EnableSuperHeroAutoCollectGiftBox = boolean;
                break;
            case 47:
                PlayerName = env->GetStringUTFChars(str, 0);
                break;
            case 48:
                setFistCooldown = SeekBarToFloat(value);
                break;
            case 49:
                setJumpModeID = value;
                break;
            case 50:
                setGravityModeID = value;
                break;
            case 51:
                EnableESPLine = boolean;
                break;
            case 52:
                EnableESPBox = boolean;
                break;
            case 53:
                EnableESPHealthBar = boolean;
                break;
            case 54:
                EnableESPMonster = boolean;
                break;
            case 55:
                EnableESPPlayer = boolean;
                break;
            case 56:
                EnableESPCollectable = boolean;
                break;
            case 57:
                EnableESPButterfly = boolean;
                break;
            case 58:
                switch (value) {
                    case 0:
                        ESPMonster = ColorImGui_OrangeRed;
                        break;
                    case 1:
                        ESPMonster = ColorImGui_Black;
                        break;
                    case 2:
                        ESPMonster = ColorImGui_White;
                        break;
                    case 3:
                        ESPMonster = ColorImGui_Purple;
                        break;
                    case 4:
                        ESPMonster = ColorImGui_PurpleBlue;
                        break;
                    case 5:
                        ESPMonster = ColorImGui_Blue;
                        break;
                    case 6:
                        ESPMonster = ColorImGui_BlueGreen;
                        break;
                    case 7:
                        ESPMonster = ColorImGui_Green;
                        break;
                    case 8:
                        ESPMonster = ColorImGui_GreenYellow;
                        break;
                    case 9:
                        ESPMonster = ColorImGui_Yellow;
                        break;
                    case 10:
                        ESPMonster = ColorImGui_YellowOrange;
                        break;
                    case 11:
                        ESPMonster = ColorImGui_Orange;
                        break;
                    case 12:
                        ESPMonster = ColorImGui_OrangeRed;
                        break;
                    case 13:
                        ESPMonster = ColorImGui_Red;
                        break;
                    case 14:
                        ESPMonster = ColorImGui_RedPurple;
                        break;
                }
                break;
            case 59:
                currentWearable = value;
                break;
            case 60:
                ApplyWearable = true;
                break;
            case 61:
                switch (value) {
                    case 0:
                        ESPPlayer = ColorImGui_Orange;
                        break;
                    case 1:
                        ESPPlayer = ColorImGui_Black;
                        break;
                    case 2:
                        ESPPlayer = ColorImGui_White;
                        break;
                    case 3:
                        ESPPlayer = ColorImGui_Purple;
                        break;
                    case 4:
                        ESPPlayer = ColorImGui_PurpleBlue;
                        break;
                    case 5:
                        ESPPlayer = ColorImGui_Blue;
                        break;
                    case 6:
                        ESPPlayer = ColorImGui_BlueGreen;
                        break;
                    case 7:
                        ESPPlayer = ColorImGui_Green;
                        break;
                    case 8:
                        ESPPlayer = ColorImGui_GreenYellow;
                        break;
                    case 9:
                        ESPPlayer = ColorImGui_Yellow;
                        break;
                    case 10:
                        ESPPlayer = ColorImGui_YellowOrange;
                        break;
                    case 11:
                        ESPPlayer = ColorImGui_Orange;
                        break;
                    case 12:
                        ESPPlayer = ColorImGui_OrangeRed;
                        break;
                    case 13:
                        ESPPlayer = ColorImGui_Red;
                        break;
                    case 14:
                        ESPPlayer = ColorImGui_RedPurple;
                        break;
                }
                break;
            case 62:
                switch (value) {
                    case 0:
                        ESPCollectable = ColorImGui_Purple;
                        break;
                    case 1:
                        ESPCollectable = ColorImGui_Black;
                        break;
                    case 2:
                        ESPCollectable = ColorImGui_White;
                        break;
                    case 3:
                        ESPCollectable = ColorImGui_Purple;
                        break;
                    case 4:
                        ESPCollectable = ColorImGui_PurpleBlue;
                        break;
                    case 5:
                        ESPCollectable = ColorImGui_Blue;
                        break;
                    case 6:
                        ESPCollectable = ColorImGui_BlueGreen;
                        break;
                    case 7:
                        ESPCollectable = ColorImGui_Green;
                        break;
                    case 8:
                        ESPCollectable = ColorImGui_GreenYellow;
                        break;
                    case 9:
                        ESPCollectable = ColorImGui_Yellow;
                        break;
                    case 10:
                        ESPCollectable = ColorImGui_YellowOrange;
                        break;
                    case 11:
                        ESPCollectable = ColorImGui_Orange;
                        break;
                    case 12:
                        ESPCollectable = ColorImGui_OrangeRed;
                        break;
                    case 13:
                        ESPCollectable = ColorImGui_Red;
                        break;
                    case 14:
                        ESPCollectable = ColorImGui_RedPurple;
                        break;
                }
                break;
            case 63:
                switch (value) {
                    case 0:
                        ESPButterFly = ColorImGui_GreenYellow;
                        break;
                    case 1:
                        ESPButterFly = ColorImGui_Black;
                        break;
                    case 2:
                        ESPButterFly = ColorImGui_White;
                        break;
                    case 3:
                        ESPButterFly = ColorImGui_Purple;
                        break;
                    case 4:
                        ESPButterFly = ColorImGui_PurpleBlue;
                        break;
                    case 5:
                        ESPButterFly = ColorImGui_Blue;
                        break;
                    case 6:
                        ESPButterFly = ColorImGui_BlueGreen;
                        break;
                    case 7:
                        ESPButterFly = ColorImGui_Green;
                        break;
                    case 8:
                        ESPButterFly = ColorImGui_GreenYellow;
                        break;
                    case 9:
                        ESPButterFly = ColorImGui_Yellow;
                        break;
                    case 10:
                        ESPButterFly = ColorImGui_YellowOrange;
                        break;
                    case 11:
                        ESPButterFly = ColorImGui_Orange;
                        break;
                    case 12:
                        ESPButterFly = ColorImGui_OrangeRed;
                        break;
                    case 13:
                        ESPButterFly = ColorImGui_Red;
                        break;
                    case 14:
                        ESPButterFly = ColorImGui_RedPurple;
                        break;
                }
                break;
            case 64:
                EnableGemsCounter = boolean;
                break;
            case 65:
                EnableESPSpirit = boolean;
                break;
            case 66:
                switch (value) {
                    case 0:
                        ESPSpirit = ColorImGui_PurpleBlue;
                        break;
                    case 1:
                        ESPSpirit = ColorImGui_Black;
                        break;
                    case 2:
                        ESPSpirit = ColorImGui_White;
                        break;
                    case 3:
                        ESPSpirit = ColorImGui_Purple;
                        break;
                    case 4:
                        ESPSpirit = ColorImGui_PurpleBlue;
                        break;
                    case 5:
                        ESPSpirit = ColorImGui_Blue;
                        break;
                    case 6:
                        ESPSpirit = ColorImGui_BlueGreen;
                        break;
                    case 7:
                        ESPSpirit = ColorImGui_Green;
                        break;
                    case 8:
                        ESPSpirit = ColorImGui_GreenYellow;
                        break;
                    case 9:
                        ESPSpirit = ColorImGui_Yellow;
                        break;
                    case 10:
                        ESPSpirit = ColorImGui_YellowOrange;
                        break;
                    case 11:
                        ESPSpirit = ColorImGui_Orange;
                        break;
                    case 12:
                        ESPSpirit = ColorImGui_OrangeRed;
                        break;
                    case 13:
                        ESPSpirit = ColorImGui_Red;
                        break;
                    case 14:
                        ESPSpirit = ColorImGui_RedPurple;
                        break;
                }
                break;
            case 67:
                EnableSpiritAimbot = boolean;
                break;
            case 68:
                EnableAlwaysValidateWorldName = true;
                break;
            case 69:
                EnableZoomHack = boolean;
                break;
            case 70:
                switch (value) {
                    case 0:
                        ESPBoss = ColorImGui_BlueGreen;
                        break;
                    case 1:
                        ESPBoss = ColorImGui_Black;
                        break;
                    case 2:
                        ESPBoss = ColorImGui_White;
                        break;
                    case 3:
                        ESPBoss = ColorImGui_Purple;
                        break;
                    case 4:
                        ESPBoss = ColorImGui_PurpleBlue;
                        break;
                    case 5:
                        ESPBoss = ColorImGui_Blue;
                        break;
                    case 6:
                        ESPBoss = ColorImGui_BlueGreen;
                        break;
                    case 7:
                        ESPBoss = ColorImGui_Green;
                        break;
                    case 8:
                        ESPBoss = ColorImGui_GreenYellow;
                        break;
                    case 9:
                        ESPBoss = ColorImGui_Yellow;
                        break;
                    case 10:
                        ESPBoss = ColorImGui_YellowOrange;
                        break;
                    case 11:
                        ESPBoss = ColorImGui_Orange;
                        break;
                    case 12:
                        ESPBoss = ColorImGui_OrangeRed;
                        break;
                    case 13:
                        ESPBoss = ColorImGui_Red;
                        break;
                    case 14:
                        ESPBoss = ColorImGui_RedPurple;
                        break;
                }
                break;
            case 71:
                EnableESPNetherGiftBox = boolean;
                break;
            case 72:
                switch (value) {
                    case 0:
                        ESPNetherGiftBox = ColorImGui_Green;
                        break;
                    case 1:
                        ESPNetherGiftBox = ColorImGui_Black;
                        break;
                    case 2:
                        ESPNetherGiftBox = ColorImGui_White;
                        break;
                    case 3:
                        ESPNetherGiftBox = ColorImGui_Purple;
                        break;
                    case 4:
                        ESPNetherGiftBox = ColorImGui_PurpleBlue;
                        break;
                    case 5:
                        ESPNetherGiftBox = ColorImGui_Blue;
                        break;
                    case 6:
                        ESPNetherGiftBox = ColorImGui_BlueGreen;
                        break;
                    case 7:
                        ESPNetherGiftBox = ColorImGui_Green;
                        break;
                    case 8:
                        ESPNetherGiftBox = ColorImGui_GreenYellow;
                        break;
                    case 9:
                        ESPNetherGiftBox = ColorImGui_Yellow;
                        break;
                    case 10:
                        ESPNetherGiftBox = ColorImGui_YellowOrange;
                        break;
                    case 11:
                        ESPNetherGiftBox = ColorImGui_Orange;
                        break;
                    case 12:
                        ESPNetherGiftBox = ColorImGui_OrangeRed;
                        break;
                    case 13:
                        ESPNetherGiftBox = ColorImGui_Red;
                        break;
                    case 14:
                        ESPNetherGiftBox = ColorImGui_RedPurple;
                        break;
                }
                break;
            case 73:
                EnableESPNetherTreasureBox = boolean;
                break;
            case 74:
                switch (value) {
                    case 0:
                        ESPNetherTreasureBox = ColorImGui_Yellow;
                        break;
                    case 1:
                        ESPNetherTreasureBox = ColorImGui_Black;
                        break;
                    case 2:
                        ESPNetherTreasureBox = ColorImGui_White;
                        break;
                    case 3:
                        ESPNetherTreasureBox = ColorImGui_Purple;
                        break;
                    case 4:
                        ESPNetherTreasureBox = ColorImGui_PurpleBlue;
                        break;
                    case 5:
                        ESPNetherTreasureBox = ColorImGui_Blue;
                        break;
                    case 6:
                        ESPNetherTreasureBox = ColorImGui_BlueGreen;
                        break;
                    case 7:
                        ESPNetherTreasureBox = ColorImGui_Green;
                        break;
                    case 8:
                        ESPNetherTreasureBox = ColorImGui_GreenYellow;
                        break;
                    case 9:
                        ESPNetherTreasureBox = ColorImGui_Yellow;
                        break;
                    case 10:
                        ESPNetherTreasureBox = ColorImGui_YellowOrange;
                        break;
                    case 11:
                        ESPNetherTreasureBox = ColorImGui_Orange;
                        break;
                    case 12:
                        ESPNetherTreasureBox = ColorImGui_OrangeRed;
                        break;
                    case 13:
                        ESPNetherTreasureBox = ColorImGui_Red;
                        break;
                    case 14:
                        ESPNetherTreasureBox = ColorImGui_RedPurple;
                        break;
                }
                break;
            case 75:
                EnableESPNetherSpecialItem = boolean;
                break;
            case 76:
                switch (value) {
                    case 0:
                        ESPNetherSpecialItem = ColorImGui_Blue;
                        break;
                    case 1:
                        ESPNetherSpecialItem = ColorImGui_Black;
                        break;
                    case 2:
                        ESPNetherSpecialItem = ColorImGui_White;
                        break;
                    case 3:
                        ESPNetherSpecialItem = ColorImGui_Purple;
                        break;
                    case 4:
                        ESPNetherSpecialItem = ColorImGui_PurpleBlue;
                        break;
                    case 5:
                        ESPNetherSpecialItem = ColorImGui_Blue;
                        break;
                    case 6:
                        ESPNetherSpecialItem = ColorImGui_BlueGreen;
                        break;
                    case 7:
                        ESPNetherSpecialItem = ColorImGui_Green;
                        break;
                    case 8:
                        ESPNetherSpecialItem = ColorImGui_GreenYellow;
                        break;
                    case 9:
                        ESPNetherSpecialItem = ColorImGui_Yellow;
                        break;
                    case 10:
                        ESPNetherSpecialItem = ColorImGui_YellowOrange;
                        break;
                    case 11:
                        ESPNetherSpecialItem = ColorImGui_Orange;
                        break;
                    case 12:
                        ESPNetherSpecialItem = ColorImGui_OrangeRed;
                        break;
                    case 13:
                        ESPNetherSpecialItem = ColorImGui_Red;
                        break;
                    case 14:
                        ESPNetherSpecialItem = ColorImGui_RedPurple;
                        break;
                }
                break;
            case 77:
                EnableESPNetherExit = boolean;
                break;
            case 78:
                switch (value) {
                    case 0:
                        ESPNetherExit = ColorImGui_White;
                        break;
                    case 1:
                        ESPNetherExit = ColorImGui_Black;
                        break;
                    case 2:
                        ESPNetherExit = ColorImGui_White;
                        break;
                    case 3:
                        ESPNetherExit = ColorImGui_Purple;
                        break;
                    case 4:
                        ESPNetherExit = ColorImGui_PurpleBlue;
                        break;
                    case 5:
                        ESPNetherExit = ColorImGui_Blue;
                        break;
                    case 6:
                        ESPNetherExit = ColorImGui_BlueGreen;
                        break;
                    case 7:
                        ESPNetherExit = ColorImGui_Green;
                        break;
                    case 8:
                        ESPNetherExit = ColorImGui_GreenYellow;
                        break;
                    case 9:
                        ESPNetherExit = ColorImGui_Yellow;
                        break;
                    case 10:
                        ESPNetherExit = ColorImGui_YellowOrange;
                        break;
                    case 11:
                        ESPNetherExit = ColorImGui_Orange;
                        break;
                    case 12:
                        ESPNetherExit = ColorImGui_OrangeRed;
                        break;
                    case 13:
                        ESPNetherExit = ColorImGui_Red;
                        break;
                    case 14:
                        ESPNetherExit = ColorImGui_RedPurple;
                        break;
                }
                break;
            case 79:
                EnableESPMineGemstone = boolean;
                break;
            case 80:
                switch (value) {
                    case 0:
                        ESPMineGemstone = ColorImGui_White;
                        break;
                    case 1:
                        ESPMineGemstone = ColorImGui_Black;
                        break;
                    case 2:
                        ESPMineGemstone = ColorImGui_White;
                        break;
                    case 3:
                        ESPMineGemstone = ColorImGui_Purple;
                        break;
                    case 4:
                        ESPMineGemstone = ColorImGui_PurpleBlue;
                        break;
                    case 5:
                        ESPMineGemstone = ColorImGui_Blue;
                        break;
                    case 6:
                        ESPMineGemstone = ColorImGui_BlueGreen;
                        break;
                    case 7:
                        ESPMineGemstone = ColorImGui_Green;
                        break;
                    case 8:
                        ESPMineGemstone = ColorImGui_GreenYellow;
                        break;
                    case 9:
                        ESPMineGemstone = ColorImGui_Yellow;
                        break;
                    case 10:
                        ESPMineGemstone = ColorImGui_YellowOrange;
                        break;
                    case 11:
                        ESPMineGemstone = ColorImGui_Orange;
                        break;
                    case 12:
                        ESPMineGemstone = ColorImGui_OrangeRed;
                        break;
                    case 13:
                        ESPMineGemstone = ColorImGui_Red;
                        break;
                    case 14:
                        ESPMineGemstone = ColorImGui_RedPurple;
                        break;
                }
                break;
            case 81:
                EnableESPMineCrate = boolean;
                break;
            case 82:
                switch (value) {
                    case 0:
                        ESPMineCrate = ColorImGui_White;
                        break;
                    case 1:
                        ESPMineCrate = ColorImGui_Black;
                        break;
                    case 2:
                        ESPMineCrate = ColorImGui_White;
                        break;
                    case 3:
                        ESPMineCrate = ColorImGui_Purple;
                        break;
                    case 4:
                        ESPMineCrate = ColorImGui_PurpleBlue;
                        break;
                    case 5:
                        ESPMineCrate = ColorImGui_Blue;
                        break;
                    case 6:
                        ESPMineCrate = ColorImGui_BlueGreen;
                        break;
                    case 7:
                        ESPMineCrate = ColorImGui_Green;
                        break;
                    case 8:
                        ESPMineCrate = ColorImGui_GreenYellow;
                        break;
                    case 9:
                        ESPMineCrate = ColorImGui_Yellow;
                        break;
                    case 10:
                        ESPMineCrate = ColorImGui_YellowOrange;
                        break;
                    case 11:
                        ESPMineCrate = ColorImGui_Orange;
                        break;
                    case 12:
                        ESPMineCrate = ColorImGui_OrangeRed;
                        break;
                    case 13:
                        ESPMineCrate = ColorImGui_Red;
                        break;
                    case 14:
                        ESPMineCrate = ColorImGui_RedPurple;
                        break;
                }
                break;
            case 83:
                EnableESPMineExit = boolean;
                break;
            case 84:
                switch (value) {
                    case 0:
                        ESPMineExit = ColorImGui_White;
                        break;
                    case 1:
                        ESPMineExit = ColorImGui_Black;
                        break;
                    case 2:
                        ESPMineExit = ColorImGui_White;
                        break;
                    case 3:
                        ESPMineExit = ColorImGui_Purple;
                        break;
                    case 4:
                        ESPMineExit = ColorImGui_PurpleBlue;
                        break;
                    case 5:
                        ESPMineExit = ColorImGui_Blue;
                        break;
                    case 6:
                        ESPMineExit = ColorImGui_BlueGreen;
                        break;
                    case 7:
                        ESPMineExit = ColorImGui_Green;
                        break;
                    case 8:
                        ESPMineExit = ColorImGui_GreenYellow;
                        break;
                    case 9:
                        ESPMineExit = ColorImGui_Yellow;
                        break;
                    case 10:
                        ESPMineExit = ColorImGui_YellowOrange;
                        break;
                    case 11:
                        ESPMineExit = ColorImGui_Orange;
                        break;
                    case 12:
                        ESPMineExit = ColorImGui_OrangeRed;
                        break;
                    case 13:
                        ESPMineExit = ColorImGui_Red;
                        break;
                    case 14:
                        ESPMineExit = ColorImGui_RedPurple;
                        break;
                }
                break;
            case 85:
                buyPackTimes = value;
                break;
            case 86:
                Auto_PackOpening();
                break;
            case 87:
                GemPackID = env->GetStringUTFChars(str, 0);
                break;
            case 88:
                EnableIgnoreCollectable = boolean;
                break;
            case 89:
                EnableConvertNuggets = boolean;
                break;
            case 90:
                SetWarpName = env->GetStringUTFChars(str, 0);
                break;
            case 91:
                DoClickWarpWorld = true;
                break;
            case 92:
                EnableAutoFish = boolean;
                break;
            case 93:
                EnableFishInfoLabel = boolean;
                break;
            case 94:
                EnableAutoSetBait = boolean;
                break;
            case 95:
                EnableAutoFishStrike = boolean;
                break;
            case 96:
                EnableAutoPlayFishGame = boolean;
                break;
            case 97:
                EnableIgnoreTinyFish = boolean;
                break;
            case 98:
                EnableIgnoreSmallFish = boolean;
                break;
            case 99:
                EnableIgnoreMediumFish = boolean;
                break;
            case 100:
                EnableIgnoreLargeFish = boolean;
                break;
            case 101:
                EnableIgnoreHugeFish = boolean;
                break;
            case 102:
                reduceChanceForTinyFish = value;
                break;
            case 103:
                reduceChanceForSmallFish = value;
                break;
            case 104:
                reduceChanceForMediumFish = value;
                break;
            case 105:
                reduceChanceForLargeFish = value;
                break;
            case 106:
                reduceChanceForHugeFish = value;
                break;
            case 107:
                EnableAutoFarm = boolean;
                break;
            case 108:
                DoSaveSeedToDrop = true;
                break;
            case 109:
                EnableAutoFarmInfoLabel = boolean;
                break;
            case 110:
                SetSeedAmountBeforeDrop = value;
                break;
            case 111:
                SetBlockPercentBeforeStop = value;
                break;
            case 112:
                RepeatPutAndBreak = value;
                break;
            case 113:
                EnableAutoDropSeed = boolean;
                break;
            case 114:
                EnableToolGetItemData = boolean;
                break;
            case 115:
                //EnablePortalTP = boolean;
                break;
            case 116:
                EnableTeleportation = boolean;
                break;
            case 117:
                EnableManuallyReloadNetherWorld = true;
                break;
            case 118:
                EnableVisualRight = boolean;
                break;
            case 119:
                setBackground = value;
                break;
            case 120:
                setWeather = value;
                break;
            case 121:
                setLighting = value;
                break;
            case 122:
                setVisualBlockType = value;
                break;
            case 123:
                EnableDrawVisualBlock = boolean;
                break;
            case 124:
                BlockToRemoveState = value;
                break;
            case 997:
                currentCategory = value;
                break;
            case 998:
                GetPackName();
                break;
            case 999:
                Next_EvenDate();
                break;
        }
    }
}

#endif