#include <jni.h>
#include <string>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#include "jni/arm/c_api.h"
#include "jni/arm/common.h"
#include "jni/arm/builtin_ops.h"
extern "C" JNIEXPORT jstring JNICALL
Java_com_xvu_f32c_1jni_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    TfLiteModel * model;
    std::string hello="Hello from TensorFlow C library version ";
    //std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
