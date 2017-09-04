#ifndef __COMMON_H
#define __COMMON_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>



#define IN
#define OUT

void authorPrintf(char *arg);  //软件信息查询

int keyEncrpyt(IN char *key, OUT char *effectKey); //秘钥  加密算法函数

int getCpuInfoSerial(OUT char *serialNum);         //秘钥基准key 获取 函数

int check_APPKey(IN char *keyFilePath, IN char *StrfAPP_Key);   //校验密钥


#endif