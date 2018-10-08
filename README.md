# LameNdkDemo
Android上一个MP3转换的demo cmake构建 、ubuntu 生成 .o格式的静态库 .
## 简介
1. 在ubuntu上使用ndk-build交叉编译lame 运行脚本在 /LameConfig/lameconfig.sh 中
在交叉编译时遇到了一些小插曲 在NDK版本在R18时去掉了 gcc 导致我怎么都编译失败 ，后面去查询才发现，所以说看官方的资料很重要。
2. 目前网上关于ndk 的资料少之又少、很多书和资料都是eclipse + ndk-build形式的 目前 AS默认的已经开始使用cmake 进行构建了。
3. 构建过程： 在ubuntu上 利用lameconfig.sh 指定好 各种c++的构建工具后（记得修改为自己的ndk路径）进行 make install 生成 .o静态库 ，导入 AS 以Addlibrary方式添加进入 ，其他内容具体看代码。
