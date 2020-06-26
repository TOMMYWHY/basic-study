# cmake

> learning how to use cmake to compile

>https://www.bilibili.com/video/av76127421

~~~vb
set(变量名 值)
messsage(${variable})
~~~

## 1. compile 外部构建
创建 cmakelist.txt 在根目录下
~~~vb
cd build
cmake .. # 编译上层，生成makefile
make
./hello_cv_1 #执行
~~~


## 2. 动态库 与 静态库
> c 编译过程 ： 预编译 -> 编译 -> 汇编 ->连接（*）
### 2.1 静态库 - 静态链接
> 编译期链接完成，运行程序时与函数库已经无关。占内存。
.a/.lib

### 2.2 动态库 
> 运行时加载，增量更新，内存中拷贝一次。依赖性强

.so/.dll