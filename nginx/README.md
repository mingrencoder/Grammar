# Nginx介绍

## 中间件架构

### 作用
    在网站后台，应用与应用，应用与操作系统交互需要中间件进行分发处理

    WEB请求 ———— 中间件          
                 ↓              ↑
                应用    ————   中间件
                 ↓
            操作系统/硬件     操作系统/硬件

### 简述
    Nginx是一个开源且高性能、可靠的HTTP中间件、代理服务器

### 优点

#### 1、IO多路复用epool

##### 多路复用
    多个描述符的I/O操作都能在一个线程内并发交替地顺序完成，这里的复用指的是复用同一个线程

##### epool模型
    是一个多路复用模型，采用系统的回调函数之间将fd放入，效率更高，最大连接无限制

#### 2、轻量级
    1.功能模块少
    2.代码模块化

#### 3、CPU亲和(affinity)
    一种把CPU核心和Nginx工作进程绑定方式，把每个worker进程固定在一个CPU上执行,减少切换CPU的cache miss，获得更好的性能

#### 4、sendfile
    文件的传输只需要通过内核空间就可以完成，而不需要经过用户空间，实现零拷贝

### 目录
    - 对sql的注入防攻击
    - 对请求的访问控制
    - 对请求的频率控制
    - 对防爬虫

## 对Nginx中间件性能优化

    - http性能压测
    - 性能瓶颈分析
    - 系统性能优化
    - 基于Nginx的性能配置优化

# 环境调试确认

    1、确认系统网络
    2、确认yum可用
    3、确认关闭iptables规则
    4、确认停用selinux

# 基于Nginx的中间件架构

## 环境调试确认

### 两项安装
    yum -y install gcc gcc-c++ autoconf pcre pcre-devel make automake
    yum -y install wget httpd-tools vim

### 一次初始化
    cd /opt;
    mkdir app(代码) download(源码包) logs(自定义日志文件) work(shell脚本) backup




