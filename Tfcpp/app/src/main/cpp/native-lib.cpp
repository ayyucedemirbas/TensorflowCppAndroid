#include <jni.h>
#include <string>
#include <iostream>
#include "../jni/common.h"
#include "../jni/builtin_ops.h"
#include "../jni/c_api.h"


extern "C" JNIEXPORT jstring JNICALL
Java_com_example_tfcpp_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    const char *path = "/home/ayyuce/Desktop/model.tflite";
    TfLiteInterpreterOptions* options = TfLiteInterpreterOptionsCreate();
    TfLiteModel * model = TfLiteModelCreateFromFile(path);
    TfLiteInterpreter * interpreter = TfLiteInterpreterCreate(model, options);
    //TfLiteInterpreterAllocateTensors(interpreter); //there is a problem with this line, if u uncomment it, the app crashes
    /*TfLiteTensor * input_tensor = TfLiteInterpreterGetInputTensor(interpreter, 0);
    const TfLiteTensor * output_tensor =
            TfLiteInterpreterGetOutputTensor(interpreter, 0);
    TfLiteStatus from_status = TfLiteTensorCopyFromBuffer(
            input_tensor,
            input_data,
            TfLiteTensorByteSize(input_tensor));
    TfLiteStatus interpreter_invoke_status = TfLiteInterpreterInvoke(interpreter);
    TfLiteStatus to_status = TfLiteTensorCopyToBuffer(
            output_tensor,
            output_data,
            TfLiteTensorByteSize(output_tensor));*/
    auto version = TfLiteVersion();
    std::string s(version);
    std::string hello= version;
    //TfLiteModelCreateFromFile()

    //TfLiteVersion();
    //std::string hello = "Hello from C++";

    return env->NewStringUTF(hello.c_str());
}
