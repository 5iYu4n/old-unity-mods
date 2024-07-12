#ifndef FEATURES_H
#define FEATURES_H

void Init(JNIEnv *env, jobject thiz, jobject ctx, jobject title, jobject subtitle){
    //Set sub title
    setText(env, title, OBFUSCATE("Guidus"));

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
            OBFUSCATE("0_True_CheckBox_Enable Remove Ads"),
            OBFUSCATE("3_CheckBox_Enable God Mod"),
            OBFUSCATE("4_Spinner_Set Spawn Item_Disable,Gold,Heart,Heart Slot,Alter,Bronze Key,Silver Key,Golden Key,Artifact 1 Piece,Artifact 2 Piece,Artifact 3 Piece,Artifact 4 Piece,Shoes,Monster Essence 1,Monster Essence 2,Monster Essence 3,Monster Essence 4,Monster Essence 5,Monster Essence 6,Stone Level 1,Stone Level 2,Stone Level 3,Stone Level 4,Stone Level 5,Royal Key,Skin Token,Abyss Essence,Chaosshard,Event Token,Wave Shard,Photon Core,Abyss Eye"),
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
            EnableRemoveAds = boolean;
            break;
        case 3:
            EnableGodMod = boolean;
            break;
        case 4:
            SetEnemyDrop = value;
            break;
    }
}

#endif
