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
		
		
		//注意 调用JNI so中函数  最好不要在 ui线程  会报：fatal signal 6 错误！
		new Thread(new Runnable() {		
			@Override
			public void run() {
				// TODO Auto-generated method stub
				CheckKey checkKey = new CheckKey();    
				int ret = checkKey.checkKeyFile("/mnt/sdcard/tmp2");   //校验密钥  返回 1
				Log.e("MainActivity>>","end ！ "+String.valueOf(ret));
				String  cpuInfo = checkKey.getCpuSerial();           //获取cpu序列号
				Log.e("MainActivity>>","cpuInfo : "+cpuInfo);   
				String  APPKeyFile = checkKey.getAPPKeyFile("/mnt/sdcard/tmp2");
				Log.e("MainActivity>>","APPKeyFile : "+APPKeyFile);   //获取机子密钥
			}
		}).start(); 

	}
}
