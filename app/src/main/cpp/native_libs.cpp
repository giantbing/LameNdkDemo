//
// Created by giant on 2018/9/21.
//
#include <jni.h>
#include <string>
#include <android/log.h>
#include "LameHelper.h"

#ifndef LOG_TAG
#define LOG_TAG "giantbing_Jni"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG ,__VA_ARGS__) // 定义LOGD类型
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG ,__VA_ARGS__) // 定义LOGI类型
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,LOG_TAG ,__VA_ARGS__) // 定义LOGW类型
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG ,__VA_ARGS__) // 定义LOGE类型
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,LOG_TAG ,__VA_ARGS__) // 定义LOGF类型
#endif


using namespace std;

LameHelper lame  = LameHelper();

extern "C" JNIEXPORT jstring JNICALL
Java_com_dingceng_giant_myndkdemo_Native_NativeHelper_getAppkey(
        JNIEnv *env,
        jobject /* this */) {
    string hello = "Nice_to_Meet_you_C++";
    return env->NewStringUTF(hello.c_str());
}
//pcmPath:String,mp3Path:String,sampleRate:Int,channel:Int,bitRate:Int
extern "C" JNIEXPORT void JNICALL
Java_com_dingceng_giant_myndkdemo_Native_NativeHelper_initMp3(
        JNIEnv *env,
        jobject  /* this */,
        jstring pcmPath,
        jstring mp3Path,
        jint sampleRate,
        jint channel,
        jint bitRate) {
    jboolean isCopy;
    const char* pamPath =  env->GetStringUTFChars(pcmPath,&isCopy);
    const char* mp3FilePath =  env->GetStringUTFChars(mp3Path,&isCopy);
    lame.Init(pamPath,mp3FilePath,sampleRate,channel,bitRate);
    LOGE(pamPath,"%s");
    env->ReleaseStringUTFChars(pcmPath,pamPath);
    env->ReleaseStringUTFChars(mp3Path,mp3FilePath);
    return;
}

extern "C" JNIEXPORT void JNICALL
Java_com_dingceng_giant_myndkdemo_Native_NativeHelper_decodeMp3(
        JNIEnv *env,
        jobject /* this */) {
    lame.Encode();
    return;
}
extern "C" JNIEXPORT void JNICALL
Java_com_dingceng_giant_myndkdemo_Native_NativeHelper_destryMp3(
        JNIEnv *env,
        jobject /* this */) {
    lame.Destory();
    return;
}