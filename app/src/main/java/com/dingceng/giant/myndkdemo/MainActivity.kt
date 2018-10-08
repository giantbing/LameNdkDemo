package com.dingceng.giant.myndkdemo

import android.Manifest
import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.os.Environment
import com.blankj.utilcode.constant.PermissionConstants.STORAGE
import com.blankj.utilcode.util.LogUtils
import com.blankj.utilcode.util.PermissionUtils
import com.blankj.utilcode.util.ResourceUtils
import com.dingceng.giant.myndkdemo.Native.NativeHelper
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {

    val cachePaht = Environment.getExternalStorageDirectory().toString()
    val nativeHelper by lazy {  NativeHelper() }
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        // Example of a call to a native method
        sample_text.text = NativeHelper().getAppkey()
        PermissionUtils.permission( STORAGE).callback(object :PermissionUtils.SimpleCallback{
            override fun onGranted() {
                LogUtils.e(cachePaht)
                ResourceUtils.copyFileFromAssets("test.pcm","$cachePaht/audio/test.pcm" )
                nativeHelper.initMp3("$cachePaht/audio/test.pcm","$cachePaht/audio/test.mp3",44100,2,320*1000)
                nativeHelper.decodeMp3()
            }

            override fun onDenied() {
            }
        }).request()

    }

}
