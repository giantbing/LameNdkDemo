package com.dingceng.giant.myndkdemo.Native

class NativeHelper {
    companion object {

        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("native-lib")
        }
    }

    external fun getAppkey(): String
    external fun initMp3(pcmPath:String,mp3Path:String,sampleRate:Int,channel:Int,bitRate:Int)
    external fun decodeMp3()
    external fun destryMp3()
}