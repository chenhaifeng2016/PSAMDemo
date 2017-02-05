//
// Created by chenhf on 16-6-30.
//
#include <stdio.h>
#include <stdlib.h>

#include "com_cssweb_psamdemo_jni_psamwrapper.h"
#include "libsam.h"




JNIEXPORT jstring JNICALL Java_com_cssweb_psamdemo_jni_psamwrapper_open(JNIEnv * env, jobject obj)
  {

    int rc = OpenSimMoudle();

    char msg[100] = {0};
    sprintf(msg, "open %d", rc);

    return (*env)->NewStringUTF(env, msg);

//    return env->NewStringUTF("hi");
  }