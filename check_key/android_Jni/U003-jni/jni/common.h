#ifndef __COMMON_H
#define __COMMON_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>



#define IN
#define OUT

int master(char *argv);  //�����Ϣ��ѯ

int keyEncrpyt(IN char *key, OUT char *effectKey); //��Կ  �����㷨����

int getCpuInfoSerial(OUT char *serialNum);         //��Կ��׼key ��ȡ ����

int getKeyFile(IN char *keyFilePath, OUT char *contentText);   //��ȡ����Կ�ļ�
int check_APPKey(IN char *keyFilePath, IN char *StrfAPP_Key);   //У����Կ


#endif
