#ifndef FEATURES_H
#define FEATURES_H

void Init(JNIEnv *env, jobject thiz, jobject ctx, jobject title, jobject subtitle){
    //Set sub title
    setText(env, title, OBFUSCATE("FGO ENGLISH"));

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
            OBFUSCATE("0_Spinner_Set FPS Limit_Default,30 FPS,60 FPS,90 FPS,120 FPS,240 FPS"),
            OBFUSCATE("1_Spinner_Set Game Speed_Default,0.5x,1x,1.5x,2x,5x,10x"),
            OBFUSCATE("7_CheckBox_Enable God Mod"),
            OBFUSCATE("4_CheckBox_Enable NP Max"),
            OBFUSCATE("2_CheckBox_Enable Massive Damage"),
            OBFUSCATE("3_CheckBox_Enable Enemy Deal 0 Damage"),
            OBFUSCATE("6_CheckBox_Enable Enemy Weak"),
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
            setFrameLvl = value;
            switch (setFrameLvl) {
                case 1:
                    setFrameValue = 30;
                    break;
                case 2:
                    setFrameValue = 60;
                    break;
                case 3:
                    setFrameValue = 90;
                    break;
                case 4:
                    setFrameValue = 120;
                    break;
                case 5:
                    setFrameValue = 240;
                    break;
            }
            break;
        case 1:
            setTimeScaleLvl = value;
            switch (setTimeScaleLvl) {
                case 1:
                    setTimeScaleValue = .5f;
                    break;
                case 2:
                    setTimeScaleValue = 1.f;
                    break;
                case 3:
                    setTimeScaleValue = 1.5f;
                    break;
                case 4:
                    setTimeScaleValue = 2.f;
                    break;
                case 5:
                    setTimeScaleValue = 5.f;
                    break;
                case 6:
                    setTimeScaleValue = 10.f;
                    break;

            }
            break;
        case 2:
            IsMassiveDamage = boolean;
            break;
        case 3:
            IsEnemyNoob = boolean;
            break;
        case 4:
            IsNPMax = boolean;
            break;
        case 5:
            //IsAutoPlay = boolean;
            break;
        case 6:
            IsWeakEnemy = boolean;
            break;
        case 7:
            IsGodMod = boolean;
            break;
    }
}

#endif
