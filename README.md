# app_run_fangkey
android app run makeKey and CheckKey by fang 安卓app运行秘钥生成和校验

本项目为  为android app 本地运行设计软件秘钥

适用平台：android     适用软件：android app

适用方法：可以导入jar包和so    或者   直接运行可执行文件（arm-linux-android）

软件功能：生成秘钥文件  and  校验秘钥文件   （只要系统android机子有秘钥文件，软件运行中调用校验就ok）
  
生成秘钥方式：2种： 1.可以执行make_By_c 下的可执行文件    
或者在app导入fangKey.jar libfang_key_MakeKey.so然后在代码中
写入：MakeKey makeKey = new MakeKey();  
	  int ret = makeKey.makeKeyFile("/mnt/sdcard/tmp");
    成功返回：0  ，失败返回：-1
	注意：先在androidManifest.xml 中添加对文件写入的权限
	
校验秘钥方式：2种 ： 1.linux—c 代码校验 使用demo见make_By_c 
或者在app导入fangKey2.jar libfang_key_CheckKey.so然后在代码
写入：CheckKey checkKey = new CheckKey();    
int ret = checkKey.checkKeyFile("/mnt/sdcard/tmp2");   
//校验密钥  失败返回 -1  完全成功返回 0