#ifndef FEATURES_H
#define FEATURES_H

void Init(JNIEnv *env, jobject thiz, jobject ctx, jobject title, jobject subtitle){
    //Set sub title
    setText(env, title, OBFUSCATE("HM Colorful Stage"));

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
            OBFUSCATE("1_Spinner_Set Note Result Always_Disable,Miss,Bad,Good,Great,Perfect"),
            OBFUSCATE("2_CheckBox_Enable Legit Auto Play"),
            OBFUSCATE("Collapse_Legit Settings"),
            OBFUSCATE("3_CollapseAdd_SeekBar_Set Perfect Note Chance_0_100"),
            OBFUSCATE("4_CollapseAdd_SeekBar_Set Great Note Chance_0_100"),
            OBFUSCATE("5_CollapseAdd_SeekBar_Set Good Note Chance_0_100"),
            OBFUSCATE("6_CollapseAdd_SeekBar_Set Bad Note Chance_0_100"),
            OBFUSCATE("7_CollapseAdd_SeekBar_Set Miss Note Chance_0_100"),
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
        case 1:
            SetNoteResult = value;
            switch (SetNoteResult) {
                case 1:
                    CurNotResult = 1;
                    break;
                case 2:
                    CurNotResult = 3;
                    break;
                case 3:
                    CurNotResult = 5;
                    break;
                case 4:
                    CurNotResult = 6;
                    break;
                case 5:
                    CurNotResult = 7;
                    break;
            }
            break;
        case 2:
            EnableLegitAutoPlay = boolean;
            break;
        case 3:
            PerfectNote = value;
            break;
        case 4:
            GreatNote = value;
            break;
        case 5:
            GoodNote = value;
            break;
        case 6:
            BadNote = value;
            break;
        case 7:
            MissNote = value;
            break;
    }
}

#endif
