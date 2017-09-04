package com.example.u003_jni;

import fang.key.CheckKey;
import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.TextView;

public class MainActivity extends Activity {

	private TextView textView;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);  
		 
		textView = (TextView)findViewById(R.id.textId);
		
		
		//ע�� ����JNI so�к���  ��ò�Ҫ�� ui�߳�  �ᱨ��fatal signal 6 ����
		new Thread(new Runnable() {		
			@Override
			public void run() {
				// TODO Auto-generated method stub
				CheckKey checkKey = new CheckKey();    
				int ret = checkKey.checkKeyFile("/mnt/sdcard/tmp2");   //У����Կ  ���� 1
				Log.e("MainActivity>>","end �� "+String.valueOf(ret));
				String  cpuInfo = checkKey.getCpuSerial();           //��ȡcpu���к�
				Log.e("MainActivity>>","cpuInfo : "+cpuInfo);   
				String  APPKeyFile = checkKey.getAPPKeyFile("/mnt/sdcard/tmp2");
				Log.e("MainActivity>>","APPKeyFile : "+APPKeyFile);   //��ȡ������Կ
			}
		}).start(); 

	}
}
