#ifndef __COMMON_H
#define __COMMON_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>



#define IN
#define OUT

void authorPrintf(char *arg);  //�����Ϣ��ѯ

int keyEncrpyt(IN char *key, OUT char *effectKey); //��Կ  �����㷨����

int getCpuInfoSerial(OUT char *serialNum);         //��Կ��׼key ��ȡ ����

int check_APPKey(IN char *keyFilePath, IN char *StrfAPP_Key);   //У����Կ


#endif