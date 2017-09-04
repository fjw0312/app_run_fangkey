#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define IN
#define OUT


//密钥路径   由函数参数传入
//密钥文件名
#define  KEYFILE  "fAPP_Key"

//***********************************
//*** 函数功能：获取 fAPP_Key 文件
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
	
	//获取 key 文件名
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
	
	//打开创建文件
	FILE *file = fopen(fileName, "r");
	if(file == NULL)
	{
		perror("fopen file");
		return -1;
	}
	//写入文件内容
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
//*** 函数功能：check fAPP_Key 
//*** author:fjw0312   fjw0312@163.com
//*** date:2017.4.5   返回有几个档次：0 \ 1 \ 2 \ 3~60 \ 10000+0~10
//**********************************
int check_APPKey(IN char *keyFilePath, IN char *StrfAPP_Key)
{
	if(keyFilePath == NULL && StrfAPP_Key == NULL)
	{
		printf("keyFilePath is NULL !\n");
		return -1;
	}
	// 获取fAPP_Key文件密钥
	char getFile_key[500];
	if( getKeyFile(keyFilePath, getFile_key) == -1 )
	{
		printf(" get getKeyFile error!\n");
	}
	//判断 密钥是否正确   
	if( strcmp(StrfAPP_Key, getFile_key) == 0 ){     //密钥完全校验成功
		printf(" fAPP_Key is right and pass <OK>!\n");
		return 0;
	}
	if( strstr(getFile_key, StrfAPP_Key) ){          //密钥部分校验成功（有包含密钥）
		printf("fAPP_Key has get!\n");
		return 1;
	}
	if( strstr(getFile_key, "fjw0312PassAllisNB")){  //密钥为超级 开发者
		printf("fAPP_Key is fjw0312PassAll!\n");
		return 2;
	}
	if( strstr(getFile_key, "Time:") ){              //密钥为试用者权限 有效期最多60
		printf("has %s Time\n", getFile_key);
		char buf[100];
		strcpy(buf, (char *)(getFile_key+5));
		int time = atoi(buf);
		if( time > 60)  time = 10 + time%10;
		if(time < 3) time = 0;
		return time;
	}
	if( strstr(getFile_key, "Effect:") ){            //密钥为企业生效这者权限 有效期最多10
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