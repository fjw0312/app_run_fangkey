#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "common.h"

#define VERSION  "FV_0.001"


/**********************************
****main  锛氬瘑閽ユ枃浠舵牎楠� 鎵ц杞欢 鍏ュ彛
****author: fjw0312   fjw0312@163.com
****date: 2017.3.31
***********************************/

//杞欢  mian
int master(char *argv)
{
	
	printf("welcome into key-Checking !\n");
	
	//鑾峰彇 cpu info key
	char cpuInfoSerial[500];
	if( getCpuInfoSerial(cpuInfoSerial) != 0)
	{
		printf("getCpuInfoSerial Error!\n");
		return -1;
	}
	// key瀵嗛挜绠楁硶
	char effectKey[500];
	if( keyEncrpyt(cpuInfoSerial, effectKey) < 6 )
	{
		printf("keyEncrpyt  Error!\n");
		return -1;
	}
	
	//鏍￠獙瀵嗛挜鏂囦欢
	int ret = check_APPKey(argv, effectKey);
	if( ret == -1 )
	{
		printf("check_APPKey Error !\n");
		return -1;
	}		
	
	return ret;
}
