package fang.key;


//fang_key_CheckKey.so��������  
public class CheckKey {

	public CheckKey() {
		// TODO Auto-generated constructor stub
	}
	 
	public native int checkKeyFile(String path);
	public native String getCpuSerial();               //��ȡcpu���к�   ��Կ��׼��
	public native String getAPPKeyFile(String path);   //��ȡ    ��Կ�ļ�
	
	static{ 
		System.loadLibrary("fang_key_CheckKey"); 
	}

}
