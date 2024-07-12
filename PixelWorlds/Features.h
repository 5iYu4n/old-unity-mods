#ifndef FEATURES_H
#define FEATURES_H

void Init(JNIEnv *env, jobject thiz, jobject ctx, jobject title, jobject subtitle){
    //Set sub title
    setText(env, title, OBFUSCATE("Pixel Worlds"));

    //Set sub title
    setText(env, subtitle, OBFUSCATE("<b><marquee><p style=\"font-size:30\" style=\"color:#CE9124;\">"
                                     "Free Mod | "
                                     "Mod Creator: 0xCsy | "
                                     "Discord: https://discord.gg/zzdFKfHhce | "
                                     "Youtube: https://www.youtube.com/channel/UCTdbULomnb5t7GX_Qkf9FKQ</p>"
                                     "</marquee></b>"));

    //Dialog Example
    //setDialog(ctx,env,OBFUSCATE("Title"),OBFUSCATE("Message Example"));

    //Toast Example
    Toast(env,ctx,OBFUSCATE("Modded By 0xCsy"),ToastLength::LENGTH_LONG);

    initValid = true;
}

jobjectArray GetFeatureList(JNIEnv *env, jobject context) {
    jobjectArray ret;

    const char *features[] = {
            OBFUSCATE("ButtonLink_Discord Server_https://discord.gg/u5eFNPJ9FU"),
            OBFUSCATE("ButtonLink_Paypal Donation_https://paypal.me/0xScy"),
            OBFUSCATE("-1_CheckBox_Enable Save Feature"),
            OBFUSCATE("Category_WORLD"),
            OBFUSCATE("1_Button_Log Out"),
            OBFUSCATE("0_CheckBox_Enable Zoom Hack"),
            OBFUSCATE("3_CheckBox_Enable Always Light On"),
            OBFUSCATE("4_CheckBox_Enable Always Fog Off"),
            OBFUSCATE("23_CheckBox_Enable Local Full Right"),

            OBFUSCATE("Category_PLAYER"),
            OBFUSCATE("2_CheckBox_Enable God Mod"),
            OBFUSCATE("10_Spinner_Set Fist Cooldown LVL_Disable,1,2,3,4"),
            OBFUSCATE("11_Spinner_Set Jump Mode_Disable,Normal,Double Jump,Long Jump,Parachute,Jetpack,Continuous Jumping,Triple Jump,Flying Mount"),
            OBFUSCATE("12_FloatSeekBar_Set Run Speed_17_25"),
            OBFUSCATE("13_CheckBox_Enable Anti-Check Point"),
            OBFUSCATE("14_CheckBox_Enable Anti-Portal"),
            OBFUSCATE("15_CheckBox_Enable Anti-Inverted Controls"),
            OBFUSCATE("16_CheckBox_Enable Anti-Bounce"),
            OBFUSCATE("17_CheckBox_Enable Anti-Deflector"),
            OBFUSCATE("18_CheckBox_Enable Anti-Elastic"),
            OBFUSCATE("19_CheckBox_Enable Anti-Elevator"),
            OBFUSCATE("20_CheckBox_Enable Anti-Pinball"),
            OBFUSCATE("21_CheckBox_Enable Anti-Trampolin"),
            OBFUSCATE("22_CheckBox_Enable Anti-Wind"),

            OBFUSCATE("Category_MISC"),
            OBFUSCATE("5_CheckBox_Enable Anti-AFK Kick"),
            OBFUSCATE("6_CheckBox_Enable Can Place Seed In Air"),
            OBFUSCATE("7_CheckBox_Enable Can Use Bad Word"),
            OBFUSCATE("8_CheckBox_Enable Unlock All Recipes"),
            OBFUSCATE("9_CheckBox_Enable Fish Hack"),
    };

    //Now you dont have to manually update the number everytime;
    int Total_Feature = (sizeof features / sizeof features[0]);
    ret = (jobjectArray)
            env->NewObjectArray(Total_Feature, env->FindClass(OBFUSCATE("java/lang/String")),
                                env->NewStringUTF(""));

    for (int i = 0; i < Total_Feature; i++)
        env->SetObjectArrayElement(ret, i, env->NewStringUTF(features[i]));

    return (ret);
}

void Changes(JNIEnv *env, jclass clazz, jobject obj,
             jint featNum, jstring featName, jint value,
             jboolean boolean, jstring str) {

    switch (featNum) {
        case 0:
            EnableZoomHack = boolean;
            break;
        case 1:
            DoLogOut = true;
            break;
        case 2:
            EnableGodMod = boolean;
            break;
        case 3:
            EnableLightAlwaysOn = boolean;
            break;
        case 4:
            EnableAlwaysFogOff = boolean;
            break;
        case 5:
            EnableAntiAFKKick = boolean;
            break;
        case 6:
            EnableCanPlaceSeedOnTop = boolean;
            break;
        case 7:
            EnableAntiCensor = boolean;
            break;
        case 8:
            EnableUnlockAllRecipes = boolean;
            break;
        case 9:
            EnableFishHack = boolean;
            break;
        case 10:
            setFistCooldownLevel = value;
            break;
        case 11:
            setJumpModeLevel = value;
            break;
        case 12:
            setRunSpeed = SeekBarToFloat(value);
            break;
        case 13:
            EnableAntiCheckPoint = boolean;
            break;
        case 14:
            EnableAntiPortal = boolean;
            break;
        case 15:
            EnableAntiInvertedControls = boolean;
            break;
        case 16:
            EnableAntiBounce = boolean;
            break;
        case 17:
            EnableAntiDeflector = boolean;
            break;
        case 18:
            EnableAntiElastic = boolean;
            break;
        case 19:
            EnableAntiElevator = boolean;
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
            EnableLocalFullRight = boolean;
            break;
    }
}

#endif
