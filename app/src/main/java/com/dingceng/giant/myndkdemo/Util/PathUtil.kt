package com.dingceng.giant.myndkdemo.Util

import android.content.Context
import android.os.Environment
import android.os.Environment.DIRECTORY_PICTURES
import android.os.Environment.MEDIA_MOUNTED


object PathUtil {


    private fun getSystemFilePath(context: Context): String {
        return if (MEDIA_MOUNTED.equals(Environment.getExternalStorageState()) || !Environment.isExternalStorageRemovable()) {
            context.getExternalFilesDir(DIRECTORY_PICTURES)?.absolutePath!!
            //            cachePath = context.getExternalCacheDir().getPath();//也可以这么写，只是返回的路径不一样，具体打log看
        } else {
            context.filesDir.absolutePath
            //            cachePath = context.getCacheDir().getPath();//也可以这么写，只是返回的路径不一样，具体打log看
        }
    }

}


