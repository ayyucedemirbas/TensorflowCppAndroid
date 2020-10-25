# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

set(JNI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../jni)


add_library(tflite-lib SHARED IMPORTED)

add_library( native-lib

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        native-lib.cpp
        )


set_target_properties(tflite-lib
        PROPERTIES IMPORTED_LOCATION
        ${JNI_DIR}/${ANDROID_ABI}/libtfl.so)


include_directories( ${JNI_DIR} )


target_link_libraries(

        native-lib

        tflite-lib
        ${log-lib}
)