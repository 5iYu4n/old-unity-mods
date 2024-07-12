#ifndef FEATURES_H
#define FEATURES_H

void Init(JNIEnv *env, jobject thiz, jobject ctx, jobject title, jobject subtitle){
    //Set sub title
    setText(env, title, OBFUSCATE("Lonely Survivor"));

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
            OBFUSCATE("2_FloatSeekBar_Game Speed_10_300"),
            OBFUSCATE("0_CheckBox_Enable Always Max Gold Reward"),
            OBFUSCATE("10_CheckBox_Enable Add Hero XP"),
            OBFUSCATE("1_CheckBox_Enable God Mod"),
            OBFUSCATE("3_CheckBox_Enable Massive Damage"),
            OBFUSCATE("4_CheckBox_Enable Instant Kill Monster"),
            OBFUSCATE("5_CheckBox_Enable Remove XP ORB"),
            //OBFUSCATE("9_CheckBox_Enable Get Massive Pet Food"),
            /*OBFUSCATE("Collapse_Item Generator"),
            OBFUSCATE("6_CollapseAdd_InputValue_Item Index"),
            OBFUSCATE("7_CollapseAdd_InputValue_Item Value"),
            OBFUSCATE("8_CollapseAdd_Button_Enable Clear XP Item"),*/
    };

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
            EnableAlwaysMaxGoldReward = boolean;
            break;
        case 1:
            EnableGodMod = boolean;
            break;
        case 2:
            SetGameSpeed = SeekBarToFloat(value);
            break;
        case 3:
            EnableInstantKill = boolean;
            break;
        case 4:
            EnableMassiveKill = boolean;
            break;
        case 5:
            EnableClearXpItem = boolean;
            break;
        case 6:
            SetItemIndex = value;
            break;
        case 7:
            SetItemValue = value;
            break;
        case 8:
            DoGenerateItem = true;
            break;
        case 9:
            EnableMassivePetFood = boolean;
            break;
        case 10:
            EnableMassiveHeroXP = boolean;
            break;
    }
}

#endif
