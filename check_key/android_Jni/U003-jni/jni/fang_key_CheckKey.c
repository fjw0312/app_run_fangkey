/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "common.h"
#include "fang_key_CheckKey.h"



JNIEXPORT jint JNICALL Java_fang_key_CheckKey_checkKeyFile(JNIEnv *env, jobject thiz,  jstring str)
{
	const char *s =  (*env)->GetStringUTFChars(env, str, 0); //��ȡ�ַ���

	int ret = master(s);
	return  ret;
}

JNIEXPORT jstring JNICALL Java_fang_key_CheckKey_getCpuSerial(JNIEnv *env, jobject thiz)
{
	char cpuInfoSerial[500];
	if( getCpuInfoSerial(cpuInfoSerial) != 0)
	{
		 return (*env)->NewStringUTF(env, " ");
	}
	 return (*env)->NewStringUTF(env, cpuInfoSerial);
}

JNIEXPORT jstring JNICALL Java_fang_key_CheckKey_getAPPKeyFile(JNIEnv *env, jobject thiz,  jstring str)
{
	const char *p =  (*env)->GetStringUTFChars(env, str, 0); //��ȡ�ַ���

	char strFile[500];
    memset(strFile, '\0', 500);
	if( getKeyFile(p, strFile) != 0)
	{
		 return (*env)->NewStringUTF(env, "");
	}
	return (*env)->NewStringUTF(env, strFile);
}
