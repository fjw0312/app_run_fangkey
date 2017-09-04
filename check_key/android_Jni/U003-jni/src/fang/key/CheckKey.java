package fang.key;


//fang_key_CheckKey.so函数声明  
public class CheckKey {

	public CheckKey() {
		// TODO Auto-generated constructor stub
	}
	 
	public native int checkKeyFile(String path);
	public native String getCpuSerial();               //获取cpu序列号   密钥基准码
	public native String getAPPKeyFile(String path);   //获取    密钥文件
	
	static{ 
		System.loadLibrary("fang_key_CheckKey"); 
	}

}
