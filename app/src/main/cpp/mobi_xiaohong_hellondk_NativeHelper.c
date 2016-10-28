//
// Created by XIAOHONG on 2016/10/28.
//
#include "mobi_xiaohong_hellondk_NativeHelper.h"
// 加载 Android 日志库的方法
#include <android/log.h>
#include <stdio.h>

JNIEXPORT jstring JNICALL
Java_mobi_xiaohong_hellondk_NativeHelper_getAppkey(
        JNIEnv *env,
        jclass type) {
    const char *str = "1234567";
    // 生成java中的字符串对象
    // 指针的指针
//        env  等同于 JNINativeInterface **  c
    jstring ret = (*env)->NewStringUTF(env, str); // 创建字符串, 返回JString;
    return ret;

}

JNIEXPORT jstring JNICALL
Java_mobi_xiaohong_hellondk_NativeHelper_getAppSecret(
        JNIEnv *env,
        jclass type) {
    const char *str = "12345671234567890";
    // 生成java中的字符串对象
    // 指针的指针
//        env  等同于 JNINativeInterface **  c
    jstring ret = (*env)->NewStringUTF(env, str); // 创建字符串, 返回JString;
    return ret;

}

JNIEXPORT jint JNICALL
Java_mobi_xiaohong_hellondk_NativeHelper_add(
        JNIEnv *env, jclass type, jint a, jint b) {
    return a + b;
}

JNIEXPORT jint JNICALL
        Java_mobi_xiaohong_hellondk_NativeHelper_sayHello(
        JNIEnv * env, jclass type, jstring name){
    // TODO: 调用Android 的代码, 显示Android 的日志
    // 代码需要调用系统日志库, 这个已经在 CMakeLists.txt, 添加了, 因此可以直接调用

    const  char* TAG = "NativeHelper";
//    jstring  --> const char *
    jboolean b = JNI_TRUE;
    const char* text = (*env)->GetStringUTFChars(*env, name, &b);
    __android_log_write(ANDROID_LOG_DEBUG, TAG, text);
    // 销毁临时生成的字符串
    (*env)->ReleaseStringChars(env, name, text);
}

JNIEXPORT jintArray JNICALL
Java_mobi_xiaohong_hellondk_NativeHelper_convertBitmap(JNIEnv *env, jclass type, jintArray colors_,
                                                       jint w, jint h) {

    jintArray ret = NULL;
    jint *colors = (*env)->GetIntArrayElements(env, colors_, NULL);

    // TODO
    // C 调用 Java 对象的方法 : colors_ 是一个数组对象, 需要获取元素个数
    jsize len = (*env)->GetArrayLength(env, colors_);
    // new 一个新的数组
    ret = (*env)->NewIntArray(env, len);

    // TODO: 转换颜色
    int index = 0;
    for(; index < len; index++) {
        int color = colors[index];
        colors[index] ^= 0x0FFFFFF;
        // 遍历设置每一个新的数组元素
    }
    // 设置数组的元素, 可以直接把转换的内容全部设置
    (*env)->SetIntArrayRegion(env, ret, 0, len, colors);

    (*env)->ReleaseIntArrayElements(env, colors_, colors, 0);
    return ret;
}