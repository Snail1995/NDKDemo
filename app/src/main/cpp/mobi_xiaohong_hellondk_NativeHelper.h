//
// Created by XIAOHONG on 2016/10/28.
//

#ifndef HELLONDK_MOBI_XIAOHONG_HELLONDK_NATIVEHELPER_H
#define HELLONDK_MOBI_XIAOHONG_HELLONDK_NATIVEHELPER_H

#include <jni.h>

// 获取两个方法, 这些方法需要在 .c 的文件中实现 , 不要忘记 添加include


/**
 *  获取 Appkey
 */
JNIEXPORT jstring JNICALL
Java_mobi_xiaohong_hellondk_NativeHelper_getAppkey(
        JNIEnv *env,
        jclass type);
JNIEXPORT jstring JNICALL
Java_mobi_xiaohong_hellondk_NativeHelper_getAppSecret(
        JNIEnv *env,
        jclass type);


JNIEXPORT jint JNICALL
Java_mobi_xiaohong_hellondk_NativeHelper_add(
        JNIEnv *env, jclass type, jint a, jint b);

// 声明, 传递字符串的方法
JNIEXPORT jint JNICALL
Java_mobi_xiaohong_hellondk_NativeHelper_sayHello(
        JNIEnv * env, jclass type, jstring name);


JNIEXPORT jintArray JNICALL
Java_mobi_xiaohong_hellondk_NativeHelper_convertBitmap(
        JNIEnv *env, jclass type, jintArray colors_,
        jint w, jint h);



#endif //HELLONDK_MOBI_XIAOHONG_HELLONDK_NATIVEHELPER_H