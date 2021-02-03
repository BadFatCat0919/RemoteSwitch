# ESP32_FW

> 这里用于存放ESP32固件的源码。

## 开发环境

使用VsCode的Arduino插件开发，兼容Arduino的IDE。

## Arduino踩坑记录

- Arduino的ino文件要与文件夹同名
- Arduino要求源码和ino文件要放在同一个目录下，即不能自己建文件夹来对源码分类存放
- 某些情况下，例如更改了文件名，需要把build目录下的中间文件删掉再重新编译
