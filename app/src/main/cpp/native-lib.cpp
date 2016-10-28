#include <jni.h>
#include <string>

extern "C"
jstring
Java_mobi_xiaohong_hellondk_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from 冯红静";
    return env->NewStringUTF(hello.c_str());
}

