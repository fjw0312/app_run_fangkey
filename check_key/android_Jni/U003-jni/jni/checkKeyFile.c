#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define IN
#define OUT


//瀵嗛挜璺緞   鐢卞嚱鏁板弬鏁颁紶鍏�
//瀵嗛挜鏂囦欢鍚�
#define  KEYFILE  "fAPP_Key"

//***********************************
//*** 鍑芥暟鍔熻兘锛氳幏鍙�fAPP_Key 鏂囦欢
//*** author:fjw0312   fjw0312@163.com
//*** date:2017.3.31
//**********************************
int getKeyFile(IN char *keyFilePath, OUT char *contentText)
{
	if(keyFilePath == NULL)
	{
		printf("keyFilePath is NULL !\n");
		return -1;
	}
	
	//鑾峰彇 key 鏂囦欢鍚�
	char fileName[200];
	int num = strlen(keyFilePath);
	if( keyFilePath[num-1] == '/')
	{
		strcpy(fileName, keyFilePath);
		strcat(fileName, KEYFILE);
	}else{
		strcpy(fileName, keyFilePath);
		strcat(fileName, "/");
		strcat(fileName, KEYFILE);
	}
	
	//鎵撳紑鍒涘缓鏂囦欢
	FILE *file = fopen(fileName, "r");
	if(file == NULL)
	{
		perror("fopen file");
		return -1;
	}
	//鍐欏叆鏂囦欢鍐呭
	char bufLine[500];
	if( fgets(bufLine, sizeof(bufLine), file) == NULL)
	{
		printf("fgets  fAPP_Key error!\n");
		return -1;
	}
	strncpy(contentText, bufLine, strlen(bufLine));
	printf("get fAPP_Key : %s\n", contentText);
	
	fclose(file);
	return 0;
}
//***********************************
//*** 鍑芥暟鍔熻兘锛歝heck fAPP_Key
//*** author:fjw0312   fjw0312@163.com
//*** date:2017.4.5   杩斿洖鏈夊嚑涓。娆★細0 \ 1 \ 2 \ 3~60 \ 10000+0~10
//**********************************
int check_APPKey(IN char *keyFilePath, IN char *StrfAPP_Key)
{
	if(keyFilePath == NULL && StrfAPP_Key == NULL)
	{
		printf("keyFilePath is NULL !\n");
		return -1;
	}
	// 鑾峰彇fAPP_Key鏂囦欢瀵嗛挜
	char getFile_key[500];
	if( getKeyFile(keyFilePath, getFile_key) == -1 )
	{
		printf(" get getKeyFile error!\n");
	}
	//鍒ゆ柇 瀵嗛挜鏄惁姝ｇ‘
	if( strcmp(StrfAPP_Key, getFile_key) == 0 ){     //瀵嗛挜瀹屽叏鏍￠獙鎴愬姛
		printf(" fAPP_Key is right and pass <OK>!\n");
		return 0;
	}
	if( strstr(getFile_key, StrfAPP_Key) ){          //瀵嗛挜閮ㄥ垎鏍￠獙鎴愬姛锛堟湁鍖呭惈瀵嗛挜锛�
		printf("fAPP_Key has get!\n");
		return 1;
	}
	if( strstr(getFile_key, "fjw0312PassAllisNB")){  //瀵嗛挜涓鸿秴绾�寮�彂鑰�
		printf("fAPP_Key is fjw0312PassAll!\n");
		return 2;
	}
	if( strstr(getFile_key, "Time:") ){              //瀵嗛挜涓鸿瘯鐢ㄨ�鏉冮檺 鏈夋晥鏈熸渶澶�0
		printf("has %s Time\n", getFile_key);
		char buf[100];
		strcpy(buf, (char *)(getFile_key+5));
		int time = atoi(buf);
		if( time > 60)  time = 10 + time%10;
		if(time < 3) time = 0;
		return time;
	}
	if( strstr(getFile_key, "Effect:") ){            //瀵嗛挜涓轰紒涓氱敓鏁堣繖鑰呮潈闄�鏈夋晥鏈熸渶澶�0
		printf("has %s effect\n", getFile_key);
		char buf[100];
		strcpy(buf, (char *)(getFile_key+5));
		int time = atoi(buf);
		if( time > 10)  time = time%10;
		time = time + 10000;
		return time;
	}
	
	return -1;
}
